import unittest
from datetime import datetime, timedelta
from models.bank_card import BankCard
from models.credit_card import CreditCard
from models.bank import Bank


class TestBankCard(unittest.TestCase):
    def setUp(self):
        """Set up test cases."""
        self.card = BankCard()
        self.card.set_data()
        self.bank = Bank()

    def test_card_initialization(self):
        self.assertIsNotNone(self.card.card_number)
        self.assertEqual(len(self.card.card_number), 16)
        self.assertTrue(self.card.card_number.isdigit())
        self.assertIsNotNone(self.card.cvv_number)
        self.assertTrue(100 <= self.card.cvv_number <= 999)
        self.assertEqual(self.card.balance, 0.0)
        self.assertFalse(self.card.is_locked)

    def test_card_validity(self):
        self.assertTrue(self.card.is_valid())
        self.card.exp_date = (datetime.today() - timedelta(days=1)).strftime("%Y-%m-%d")
        self.assertFalse(self.card.is_valid())
        self.card.exp_date = None
        self.assertFalse(self.card.is_valid())

    def test_card_locking(self):
        self.bank.process_deposit(self.card, 100.0)
        self.card.lock()
        self.assertTrue(self.card.is_locked)
        self.assertIsNone(self.card.check_balance())
        self.card.unlock()
        self.assertFalse(self.card.is_locked)
        self.assertEqual(self.card.check_balance(), 100.0)

    def test_str_representation(self):
        self.card.balance = 100.0
        str_repr = str(self.card)
        self.assertIn(self.card.card_number, str_repr)
        self.assertIn(str(self.card.cvv_number), str_repr)
        self.assertIn(self.card.exp_date, str_repr)
        self.assertIn("100.00", str_repr)
        self.assertIn("Active", str_repr)


class TestCreditCard(unittest.TestCase):

    def setUp(self):
        self.card = CreditCard(credit_limit=1000.0)
        self.card.set_data()
        self.bank = Bank()

    def test_credit_card_initialization(self):
        self.assertEqual(self.card.credit_limit, 1000.0)
        self.assertEqual(self.card.balance, 1000.0)
        self.assertEqual(self.card.available_credit, 1000.0)

    def test_str_representation(self):
        str_repr = str(self.card)
        self.assertIn("Credit Card", str_repr)
        self.assertIn(self.card.card_number, str_repr)
        self.assertIn(str(self.card.cvv_number), str_repr)
        self.assertIn(self.card.exp_date, str_repr)
        self.assertIn("1000.00", str_repr)
        self.assertIn("Active", str_repr)

if __name__ == '__main__':
    unittest.main() 