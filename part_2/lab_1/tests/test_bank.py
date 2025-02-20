"""Tests for bank operations."""

import unittest
from datetime import datetime
from models.bank import Bank
from models.bank_card import BankCard
from models.credit_card import CreditCard


class TestBank(unittest.TestCase):
    """Test cases for Bank class."""

    def setUp(self):
        """Set up test cases."""
        self.bank = Bank()
        self.debit_card = BankCard()
        self.debit_card.set_data()
        self.credit_card = CreditCard(credit_limit=1000)
        self.credit_card.set_data()

    def test_verify_pin(self):
        """Test PIN verification."""
        # В тестовой среде всегда возвращает True
        self.assertTrue(self.bank.verify_pin(self.debit_card.card_number, "1234"))
        
    def test_process_withdrawal_debit(self):
        """Test withdrawal from debit card."""
        # Deposit first
        self.bank.process_deposit(self.debit_card, 1000)
        
        # Test successful withdrawal
        self.assertTrue(self.bank.process_withdrawal(self.debit_card, 500, "1234"))
        self.assertEqual(self.debit_card.balance, 500)
        
        # Test insufficient funds
        with self.assertRaises(ValueError):
            self.bank.process_withdrawal(self.debit_card, 1000, "1234")
            
        # Test negative amount
        with self.assertRaises(ValueError):
            self.bank.process_withdrawal(self.debit_card, -100, "1234")
            
        # Test locked card
        self.debit_card.lock()
        self.assertFalse(self.bank.process_withdrawal(self.debit_card, 100, "1234"))
        
    def test_process_withdrawal_credit(self):
        """Test withdrawal from credit card."""
        # Test successful withdrawal
        self.assertTrue(self.bank.process_withdrawal(self.credit_card, 500, "1234"))
        self.assertEqual(self.credit_card.balance, 500)
        
        # Test exceeding credit limit
        with self.assertRaises(ValueError):
            self.bank.process_withdrawal(self.credit_card, 1000, "1234")
            
    def test_process_deposit_debit(self):
        """Test deposit to debit card."""
        # Test successful deposit
        self.assertTrue(self.bank.process_deposit(self.debit_card, 1000))
        self.assertEqual(self.debit_card.balance, 1000)
        
        # Test negative amount
        with self.assertRaises(ValueError):
            self.bank.process_deposit(self.debit_card, -100)
            
        # Test locked card
        self.debit_card.lock()
        self.assertFalse(self.bank.process_deposit(self.debit_card, 100))
        
    def test_process_deposit_credit(self):
        """Test deposit to credit card."""
        # Test successful deposit
        self.assertTrue(self.bank.process_deposit(self.credit_card, 500))
        self.assertEqual(self.credit_card.balance, 1500)
        
        # Test exceeding credit limit
        with self.assertRaises(ValueError):
            self.bank.process_deposit(self.credit_card, 1000)
            
    def test_process_payment(self):
        """Test payment processing."""
        # Deposit first
        self.bank.process_deposit(self.debit_card, 1000)
        
        # Test successful payment
        self.assertTrue(self.bank.process_payment(
            self.debit_card, 500, "1234", "Test payment"
        ))
        self.assertEqual(self.debit_card.balance, 500)
        
        # Verify transaction was recorded
        transactions = self.bank.get_card_transactions(self.debit_card.card_number)
        self.assertEqual(len(transactions), 2)  # deposit + payment
        last_transaction = transactions[-1]
        self.assertEqual(last_transaction['type'], "payment")
        self.assertEqual(last_transaction['amount'], 500)
        self.assertEqual(last_transaction['description'], "Test payment")
        
    def test_get_card_transactions(self):
        """Test getting card transactions."""
        # No transactions initially
        self.assertEqual(len(self.bank.get_card_transactions(self.debit_card.card_number)), 0)
        
        # Add some transactions
        self.bank.process_deposit(self.debit_card, 1000)
        self.bank.process_withdrawal(self.debit_card, 300, "1234")
        self.bank.process_payment(self.debit_card, 200, "1234", "Test")
        
        # Verify transactions
        transactions = self.bank.get_card_transactions(self.debit_card.card_number)
        self.assertEqual(len(transactions), 3)
        self.assertEqual(transactions[0]['type'], "deposit")
        self.assertEqual(transactions[1]['type'], "withdrawal")
        self.assertEqual(transactions[2]['type'], "payment")


if __name__ == '__main__':
    unittest.main() 