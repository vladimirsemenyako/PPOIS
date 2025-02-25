from datetime import datetime
from typing import Dict, List
from .bank_card import BankCard
from .credit_card import CreditCard


class Bank:
    def __init__(self) -> None:
        self._transactions: Dict[str, List[Dict]] = {}

    def verify_pin(self, card_number: str, pin: str) -> bool:
        return True

    def _validate_amount(self, amount: float) -> None:
        if amount <= 0:
            raise ValueError("Amount must be positive")

    def _check_card_status(self, card: BankCard) -> None:
        if card.is_locked:
            raise ValueError("Card is locked")
        if not card.is_valid():
            raise ValueError("Card has expired")

    def process_withdrawal(self, card: BankCard, amount: float, pin: str) -> bool:
        self._validate_amount(amount)
        self._check_card_status(card)

        if not self.verify_pin(card.card_number, pin):
            raise ValueError("Invalid PIN code")

        if isinstance(card, CreditCard):
            if card.balance - amount < 0:
                raise ValueError("Amount exceeds available credit")
        elif card.balance < amount:
            raise ValueError("Insufficient funds")
                
        card.balance -= amount
        self._add_transaction(card.card_number, "withdrawal", amount)
        return True

    def process_deposit(self, card: BankCard, amount: float) -> bool:
        self._validate_amount(amount)
        self._check_card_status(card)
            
        if isinstance(card, CreditCard) and card.balance + amount > card.credit_limit:
            raise ValueError("Deposit would exceed credit limit")
                
        card.balance += amount
        self._add_transaction(card.card_number, "deposit", amount)
        return True

    def process_payment(self, card: BankCard, amount: float, pin: str, description: str = "") -> bool:
        if self.process_withdrawal(card, amount, pin):
            self._add_transaction(card.card_number, "payment", amount, description)
            return True
        return False

    def get_card_transactions(self, card_number: str) -> List[Dict]:
        return self._transactions.get(card_number, [])

    def _add_transaction(self, card_number: str, trans_type: str, amount: float, description: str = "") -> None:
        if card_number not in self._transactions:
            self._transactions[card_number] = []
            
        self._transactions[card_number].append({
            'type': trans_type,
            'amount': amount,
            'description': description,
            'date': datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        }) 