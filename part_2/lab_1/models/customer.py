import random
import re
import json
import os
from pathlib import Path
from datetime import datetime
from typing import List, Dict, Optional, Union, Any

from .credit_card import CreditCard
from .bank_card import BankCard
from .limits import Limits
from .pin_code import PinCode
from .bank import Bank

class Customer:

    STORAGE_FILE = Path("storage/users.json")

    def __init__(
        self,
        first_name: str | None = None,
        last_name: str | None = None,
        email: str | None = None,
        password: str | None = None
    ) -> None:
        self.customer_id = random.randint(10, 100)
        self.first_name = first_name
        self.last_name = last_name
        self.email = email
        self.password = password
        self.credit_cards: List[BankCard] = []
        self.debit_cards: List[BankCard] = []
        self.status = 'basic'
        self.limits = Limits()
        self.pin = PinCode()
        self.transactions: List[Dict[str, Any]] = []
        self._bank = Bank()

    def to_dict(self) -> Dict[str, Any]:
        return {
            'customer_id': self.customer_id,
            'first_name': self.first_name,
            'last_name': self.last_name,
            'email': self.email,
            'password': self.password,
            'credit_cards': [
                {
                    'card_number': card.card_number,
                    'cvv_number': card.cvv_number,
                    'exp_date': card.exp_date,
                    'balance': card.balance,
                    'is_locked': card.is_locked,
                    'credit_limit': card.credit_limit
                } for card in self.credit_cards
            ],
            'debit_cards': [
                {
                    'card_number': card.card_number,
                    'cvv_number': card.cvv_number,
                    'exp_date': card.exp_date,
                    'balance': card.balance,
                    'is_locked': card.is_locked
                } for card in self.debit_cards
            ],
            'status': self.status,
            'pin_code': self.pin.get_pin_code(),
            'transactions': self.transactions
        }

    @classmethod
    def from_dict(cls, data: Dict[str, Any]) -> 'Customer':
        customer = cls()
        customer.customer_id = data['customer_id']
        customer.first_name = data['first_name']
        customer.last_name = data['last_name']
        customer.email = data['email']
        customer.password = data.get('password', '')
        customer.status = data['status']
        customer.transactions = data.get('transactions', [])
        
        if 'pin_code' in data and data['pin_code']:
            customer.pin.set_pin_code(str(data['pin_code']))
        
        for card_data in data['credit_cards']:
            card = CreditCard()
            card.card_number = card_data['card_number']
            card.cvv_number = card_data['cvv_number']
            card.exp_date = card_data['exp_date']
            card.balance = float(card_data['balance'])
            card.is_locked = card_data['is_locked']
            card.credit_limit = float(card_data['credit_limit'])
            customer.credit_cards.append(card)
        
        for card_data in data['debit_cards']:
            card = BankCard()
            card.card_number = card_data['card_number']
            card.cvv_number = card_data['cvv_number']
            card.exp_date = card_data['exp_date']
            card.balance = float(card_data['balance'])
            card.is_locked = card_data['is_locked']
            customer.debit_cards.append(card)
        
        return customer

    @classmethod
    def _load_all_users(cls) -> Dict[str, Dict[str, Any]]:
        if not cls.STORAGE_FILE.exists():
            return {}
        try:
            with open(cls.STORAGE_FILE, 'r', encoding='utf-8') as file:
                return json.load(file)
        except json.JSONDecodeError:
            return {}

    @classmethod
    def _save_all_users(cls, users_data: Dict[str, Dict[str, Any]]) -> None:
        os.makedirs(os.path.dirname(cls.STORAGE_FILE), exist_ok=True)
        with open(cls.STORAGE_FILE, 'w', encoding='utf-8') as file:
            json.dump(users_data, file, indent=4, ensure_ascii=False)

    def save(self) -> None:
        users_data = self._load_all_users()
        users_data[self.email] = self.to_dict()
        self._save_all_users(users_data)

    @classmethod
    def load(cls, email: str) -> Optional['Customer']:
        users_data = cls._load_all_users()
        if email not in users_data:
            return None
        return cls.from_dict(users_data[email])

    @classmethod
    def get_all_users(cls) -> List['Customer']:
        users_data = cls._load_all_users()
        return [cls.from_dict(data) for data in users_data.values()]

    def delete(self) -> None:
        users_data = self._load_all_users()
        if self.email in users_data:
            del users_data[self.email]
            self._save_all_users(users_data)

    def change_status(self) -> None:
        new_status = 'premium' if self.status == 'basic' else 'basic'
        
        if new_status == 'basic':
            debit_limit = self.limits.get_debit_card_limit('basic')
            if len(self.debit_cards) > debit_limit:
                for card in self.debit_cards[debit_limit:]:
                    card.lock()
            credit_limit = self.limits.get_credit_card_limit('basic')
            if len(self.credit_cards) > credit_limit:
                for card in self.credit_cards[credit_limit:]:
                    card.lock()
        
        self.status = new_status
        self.save()

    def set_info(self) -> None:
        self.first_name = self._input_name("Enter first name: ")
        self.last_name = self._input_name("Enter last name: ")
        self.email = self._input_email("Enter email: ")
        self.password = self._input_password("Enter password: ")
        self.status = 'basic'
        self.save()

    def _input_name(self, prompt: str) -> str:
        while True:
            try:
                name = input(prompt).strip()
                if not all(c.isalpha() or c.isspace() for c in name):
                    print("Error: Please enter a valid name (letters only).")
                    continue
                if not name:  # Проверка на пустую строку
                    print("Error: Name cannot be empty.")
                    continue
                return name
            except UnicodeDecodeError:
                print("Error: Please use valid characters.")
                continue

    @classmethod
    def email_exists(cls, email: str) -> bool:
        users_data = cls._load_all_users()
        return email in users_data

    def _input_email(self, prompt: str) -> str:
        while True:
            try:
                email = input(prompt).strip()
                # Более гибкая проверка email
                if '@' not in email or '.' not in email:
                    print("Error: Please enter a valid email address.")
                    continue
                if self.email_exists(email):
                    print("Error: Email already exists!")
                    continue
                return email
            except UnicodeDecodeError:
                print("Error: Please use valid characters in email.")
                continue

    def _input_password(self, prompt: str) -> str:
        while True:
            try:
                password = input(prompt).strip()
                if len(password) < 6:
                    print("Error: Password must be at least 6 characters long.")
                    continue
                confirm = input("Confirm password: ").strip()
                if password != confirm:
                    print("Error: Passwords do not match.")
                    continue
                return password
            except UnicodeDecodeError:
                print("Error: Please use valid characters in password.")
                continue

    def get_credit_card(self) -> CreditCard:
        if not self.pin.has_pin_code():
            raise ValueError("PIN code must be set before issuing cards")
        
        if len(self.credit_cards) >= self.limits.get_credit_card_limit(self.status):
            raise ValueError(f'Credit card limit reached for {self.status} status.')
        
        credit_limit = 2000 if self.status == 'premium' else 1000
        new_credit_card = CreditCard(credit_limit=credit_limit)
        new_credit_card.set_data()
        self.credit_cards.append(new_credit_card)
        return new_credit_card

    def get_debit_card(self) -> BankCard:
        if not self.pin.has_pin_code():
            raise ValueError("PIN code must be set before issuing cards")
        
        if len(self.debit_cards) >= self.limits.get_debit_card_limit(self.status):
            raise ValueError(f'Debit card limit reached for {self.status} status.')
        
        new_debit_card = BankCard()
        new_debit_card.set_data()
        self.debit_cards.append(new_debit_card)
        return new_debit_card

    def deposit(self, card_index: int, amount: float) -> bool:
        if amount <= 0:
            raise ValueError("Deposit amount must be positive")

        try:
            if card_index < len(self.debit_cards):
                card = self.debit_cards[card_index]
            else:
                credit_index = card_index - len(self.debit_cards)
                card = self.credit_cards[credit_index]
        except IndexError:
            return False

        if self._bank.process_deposit(card, amount):
            self.add_transaction("deposit", amount, card.card_number)
            self.save()
            return True
        return False

    def withdraw(self, card_index: int, amount: float, pin: str) -> bool:
        if not self.pin.verify_pin_code(pin):
            raise ValueError("Invalid PIN code")

        withdrawal_limit = self.limits.get_withdrawal_limit(self.status)
        if amount > withdrawal_limit:
            raise ValueError(f"Amount exceeds withdrawal limit ({withdrawal_limit:.2f})")

        try:
            if card_index < len(self.debit_cards):
                card = self.debit_cards[card_index]
            else:
                credit_index = card_index - len(self.debit_cards)
                card = self.credit_cards[credit_index]
        except IndexError:
            return False

        if self._bank.process_withdrawal(card, amount, pin):
            self.add_transaction("withdrawal", amount, card.card_number)
            self.save()
            return True
        return False

    def verify_password(self, password: str) -> bool:
        return self.password == password

    def make_payment(self, card_index: int, amount: float, pin: str, description: str) -> bool:
        if not self.pin.verify_pin_code(pin):
            raise ValueError("Invalid PIN code")

        if amount <= 0:
            raise ValueError("Payment amount must be positive")

        try:
            if card_index < len(self.debit_cards):
                card = self.debit_cards[card_index]
            else:
                credit_index = card_index - len(self.debit_cards)
                card = self.credit_cards[credit_index]
        except IndexError:
            return False

        if self._bank.process_payment(card, amount, pin, description):
            self.add_transaction("payment", amount, card.card_number, description)
            self.save()
            return True
        return False

    def add_transaction(self, transaction_type: str, amount: float, card_number: str, description: str = "") -> None:
        if not hasattr(self, 'transactions'):
            self.transactions = []
        self.transactions.append({
            'type': transaction_type,
            'amount': amount,
            'card_number': card_number,
            'description': description,
            'date': datetime.now().strftime("%m/%d/%Y %I:%M")
        })


