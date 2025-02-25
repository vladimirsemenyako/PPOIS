import unittest
from models.bank import Bank
from models.bank_card import BankCard
from models.credit_card import CreditCard


class TestBank(unittest.TestCase):

    def setUp(self):
        self.bank = Bank()
        self.debit_card = BankCard()
        self.debit_card.set_data()
        self.credit_card = CreditCard(credit_limit=1000)
        self.credit_card.set_data()

    def test_verify_pin(self):
        self.assertTrue(self.bank.verify_pin(self.debit_card.card_number, "1234"))
        
    def test_process_withdrawal_credit(self):
        self.assertTrue(self.bank.process_withdrawal(self.credit_card, 500, "1234"))
        self.assertEqual(self.credit_card.balance, 500)
        with self.assertRaises(ValueError):
            self.bank.process_withdrawal(self.credit_card, 1000, "1234")

if __name__ == '__main__':
    unittest.main() 