"""Tests for customer functionality."""

import unittest
import os
from pathlib import Path
from models.customer import Customer


class TestCustomer(unittest.TestCase):
    """Test cases for Customer class."""

    def setUp(self):
        """Set up test cases."""
        self.test_storage = Path("test_storage/users.json")
        Customer.STORAGE_FILE = self.test_storage
        self.customer = Customer(
            first_name="John",
            last_name="Doe",
            email="john@example.com",
            password="password123"
        )

    def tearDown(self):
        """Clean up after tests."""
        if self.test_storage.exists():
            os.remove(self.test_storage)
        if self.test_storage.parent.exists():
            os.rmdir(self.test_storage.parent)

    def test_customer_initialization(self):
        """Test customer initialization."""
        self.assertEqual(self.customer.first_name, "John")
        self.assertEqual(self.customer.last_name, "Doe")
        self.assertEqual(self.customer.email, "john@example.com")
        self.assertEqual(self.customer.password, "password123")
        self.assertEqual(self.customer.status, "basic")
        self.assertEqual(len(self.customer.debit_cards), 0)
        self.assertEqual(len(self.customer.credit_cards), 0)

    def test_customer_serialization(self):
        """Test customer serialization."""
        data = self.customer.to_dict()
        self.assertEqual(data['first_name'], "John")
        self.assertEqual(data['last_name'], "Doe")
        self.assertEqual(data['email'], "john@example.com")
        self.assertEqual(data['password'], "password123")
        self.assertEqual(data['status'], "basic")

    def test_customer_save_and_load(self):
        """Test saving and loading customer data."""
        self.customer.save()
        loaded_customer = Customer.load("john@example.com")
        self.assertEqual(loaded_customer.first_name, "John")
        self.assertEqual(loaded_customer.last_name, "Doe")
        self.assertEqual(loaded_customer.email, "john@example.com")
        self.assertEqual(loaded_customer.password, "password123")

    def test_customer_status_change(self):
        """Test customer status change."""
        self.assertEqual(self.customer.status, "basic")
        self.customer.change_status()
        self.assertEqual(self.customer.status, "premium")
        self.customer.change_status()
        self.assertEqual(self.customer.status, "basic")

    def test_card_limits(self):
        """Test card issuance limits."""
        # Test basic status limits
        self.customer.get_debit_card()
        self.customer.get_debit_card()
        with self.assertRaises(ValueError):
            self.customer.get_debit_card()  # Exceeds basic limit

        self.customer.get_credit_card()
        with self.assertRaises(ValueError):
            self.customer.get_credit_card()  # Exceeds basic limit

        # Test premium status limits
        self.customer.change_status()  # Change to premium
        self.customer.get_credit_card()  # Should work now
        with self.assertRaises(ValueError):
            self.customer.get_credit_card()  # Exceeds premium limit

    def test_password_verification(self):
        """Test password verification."""
        self.assertTrue(self.customer.verify_password("password123"))
        self.assertFalse(self.customer.verify_password("wrongpassword"))

    def test_email_exists(self):
        """Test email existence check."""
        self.customer.save()
        self.assertTrue(Customer.email_exists("john@example.com"))
        self.assertFalse(Customer.email_exists("nonexistent@example.com"))

    def test_customer_deletion(self):
        """Test customer deletion."""
        self.customer.save()
        self.assertTrue(Customer.email_exists("john@example.com"))
        self.customer.delete()
        self.assertFalse(Customer.email_exists("john@example.com"))

    def test_payment_operations(self):
        """Test payment operations."""
        self.customer.pin.set_pin_code("1234")
        debit_card = self.customer.get_debit_card()
        
        # Initial deposit
        self.customer.deposit(0, 1000)
        
        # Test successful payment
        self.assertTrue(self.customer.make_payment(0, 500, "1234", "Test payment"))
        self.assertEqual(debit_card.balance, 500)
        
        # Verify transaction was recorded
        self.assertEqual(len(self.customer.transactions), 2)  # deposit + payment
        last_transaction = self.customer.transactions[-1]
        self.assertEqual(last_transaction['type'], "payment")
        self.assertEqual(last_transaction['amount'], 500)
        self.assertEqual(last_transaction['description'], "Test payment")
        
        # Test payment with wrong PIN
        with self.assertRaises(ValueError) as context:
            self.customer.make_payment(0, 100, "4321", "Failed payment")
        self.assertEqual(str(context.exception), "Invalid PIN code")
        
        # Test payment with negative amount
        with self.assertRaises(ValueError) as context:
            self.customer.make_payment(0, -100, "1234", "Negative payment")
        self.assertEqual(str(context.exception), "Payment amount must be positive")
        
        # Test payment with insufficient funds
        with self.assertRaises(ValueError) as context:
            self.customer.make_payment(0, 1000, "1234", "Too large payment")
        self.assertEqual(str(context.exception), "Insufficient funds")

    def test_status_change_with_cards(self):
        """Test status change with existing cards."""
        self.customer.change_status()  # Change to premium
        
        # Get maximum allowed cards for premium
        debit_card1 = self.customer.get_debit_card()
        debit_card2 = self.customer.get_debit_card()
        debit_card3 = self.customer.get_debit_card()
        credit_card1 = self.customer.get_credit_card()
        credit_card2 = self.customer.get_credit_card()
        
        # All cards should be active
        self.assertFalse(debit_card1.is_locked)
        self.assertFalse(debit_card2.is_locked)
        self.assertFalse(debit_card3.is_locked)
        self.assertFalse(credit_card1.is_locked)
        self.assertFalse(credit_card2.is_locked)
        
        # Change back to basic
        self.customer.change_status()
        
        # Check that excess cards are blocked
        self.assertFalse(debit_card1.is_locked)  # Within basic limit
        self.assertFalse(debit_card2.is_locked)  # Within basic limit
        self.assertTrue(debit_card3.is_locked)   # Exceeds basic limit
        self.assertFalse(credit_card1.is_locked) # Within basic limit
        self.assertTrue(credit_card2.is_locked)  # Exceeds basic limit


if __name__ == '__main__':
    unittest.main() 