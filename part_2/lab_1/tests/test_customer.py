import unittest
import os
from pathlib import Path
from models.customer import Customer


class TestCustomer(unittest.TestCase):

    def setUp(self):
        self.test_storage = Path("test_storage/users.json")
        Customer.STORAGE_FILE = self.test_storage
        self.customer = Customer(
            first_name="John",
            last_name="Doe",
            email="john@example.com",
            password="password123"
        )

    def tearDown(self):
        if self.test_storage.exists():
            os.remove(self.test_storage)
        if self.test_storage.parent.exists():
            os.rmdir(self.test_storage.parent)

    def test_customer_initialization(self):
        self.assertEqual(self.customer.first_name, "John")
        self.assertEqual(self.customer.last_name, "Doe")
        self.assertEqual(self.customer.email, "john@example.com")
        self.assertEqual(self.customer.password, "password123")
        self.assertEqual(self.customer.status, "basic")
        self.assertEqual(len(self.customer.debit_cards), 0)
        self.assertEqual(len(self.customer.credit_cards), 0)

    def test_customer_serialization(self):
        data = self.customer.to_dict()
        self.assertEqual(data['first_name'], "John")
        self.assertEqual(data['last_name'], "Doe")
        self.assertEqual(data['email'], "john@example.com")
        self.assertEqual(data['password'], "password123")
        self.assertEqual(data['status'], "basic")

    def test_customer_save_and_load(self):
        self.customer.save()
        loaded_customer = Customer.load("john@example.com")
        self.assertEqual(loaded_customer.first_name, "John")
        self.assertEqual(loaded_customer.last_name, "Doe")
        self.assertEqual(loaded_customer.email, "john@example.com")
        self.assertEqual(loaded_customer.password, "password123")

    def test_customer_status_change(self):
        self.assertEqual(self.customer.status, "basic")
        self.customer.change_status()
        self.assertEqual(self.customer.status, "premium")
        self.customer.change_status()
        self.assertEqual(self.customer.status, "basic")

    def test_password_verification(self):
        self.assertTrue(self.customer.verify_password("password123"))
        self.assertFalse(self.customer.verify_password("wrongpassword"))

    def test_email_exists(self):
        self.customer.save()
        self.assertTrue(Customer.email_exists("john@example.com"))
        self.assertFalse(Customer.email_exists("nonexistent@example.com"))

    def test_customer_deletion(self):
        self.customer.save()
        self.assertTrue(Customer.email_exists("john@example.com"))
        self.customer.delete()
        self.assertFalse(Customer.email_exists("john@example.com"))

    def test_payment_operations(self):
        self.customer.pin.set_pin_code("1234")
        debit_card = self.customer.get_debit_card()
        self.customer.deposit(0, 1000)
        self.assertTrue(self.customer.make_payment(0, 500, "1234", "Test payment"))
        self.assertEqual(debit_card.balance, 500)
        self.assertEqual(len(self.customer.transactions), 2)  # deposit + payment
        last_transaction = self.customer.transactions[-1]
        self.assertEqual(last_transaction['type'], "payment")
        self.assertEqual(last_transaction['amount'], 500)
        self.assertEqual(last_transaction['description'], "Test payment")
        with self.assertRaises(ValueError) as context:
            self.customer.make_payment(0, 100, "4321", "Failed payment")
        self.assertEqual(str(context.exception), "Invalid PIN code")

        with self.assertRaises(ValueError) as context:
            self.customer.make_payment(0, -100, "1234", "Negative payment")
        self.assertEqual(str(context.exception), "Payment amount must be positive")

        with self.assertRaises(ValueError) as context:
            self.customer.make_payment(0, 1000, "1234", "Too large payment")
        self.assertEqual(str(context.exception), "Insufficient funds")



if __name__ == '__main__':
    unittest.main() 