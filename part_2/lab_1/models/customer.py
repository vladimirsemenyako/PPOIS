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
    """Customer account manager."""

    STORAGE_FILE = Path("storage/users.json")

    def __init__(
        self,
        first_name: str | None = None,
        last_name: str | None = None,
        email: str | None = None,
        password: str | None = None
    ) -> None:
        """Initialize customer account.
        
        Args:
            first_name: Customer's first name
            last_name: Customer's last name
            email: Customer's email address
            password: Customer's password
        """
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
        """Convert customer data to dictionary for serialization.
        
        Returns:
            dict: Customer data
        """
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
        """Create customer object from dictionary.
        
        Args:
            data: Dictionary with customer data
            
        Returns:
            Customer: New customer instance
        """
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
        """Load all users from storage file.
        
        Returns:
            dict: Dictionary with all users' data
        """
        if not cls.STORAGE_FILE.exists():
            return {}
        try:
            with open(cls.STORAGE_FILE, 'r', encoding='utf-8') as file:
                return json.load(file)
        except json.JSONDecodeError:
            return {}

    @classmethod
    def _save_all_users(cls, users_data: Dict[str, Dict[str, Any]]) -> None:
        """Save all users to storage file.
        
        Args:
            users_data: Dictionary with all users' data
        """
        os.makedirs(os.path.dirname(cls.STORAGE_FILE), exist_ok=True)
        with open(cls.STORAGE_FILE, 'w', encoding='utf-8') as file:
            json.dump(users_data, file, indent=4, ensure_ascii=False)

    def save(self) -> None:
        """Save current customer to storage."""
        users_data = self._load_all_users()
        users_data[self.email] = self.to_dict()
        self._save_all_users(users_data)

    @classmethod
    def load(cls, email: str) -> Optional['Customer']:
        """Load customer by email.
        
        Args:
            email: Customer's email address
            
        Returns:
            Customer: Customer instance or None if not found
        """
        users_data = cls._load_all_users()
        if email not in users_data:
            return None
        return cls.from_dict(users_data[email])

    @classmethod
    def get_all_users(cls) -> List['Customer']:
        """Get list of all customers.
        
        Returns:
            list: List of all customer instances
        """
        users_data = cls._load_all_users()
        return [cls.from_dict(data) for data in users_data.values()]

    def delete(self) -> None:
        """Delete current customer from storage."""
        users_data = self._load_all_users()
        if self.email in users_data:
            del users_data[self.email]
            self._save_all_users(users_data)

    def change_status(self) -> None:
        """Toggle customer status between basic and premium.
        
        If changing from premium to basic, excess cards will be blocked.
        """
        new_status = 'premium' if self.status == 'basic' else 'basic'
        
        if new_status == 'basic':
            # Check and block excess debit cards
            debit_limit = self.limits.get_debit_card_limit('basic')
            if len(self.debit_cards) > debit_limit:
                for card in self.debit_cards[debit_limit:]:
                    card.lock()
            
            # Check and block excess credit cards
            credit_limit = self.limits.get_credit_card_limit('basic')
            if len(self.credit_cards) > credit_limit:
                for card in self.credit_cards[credit_limit:]:
                    card.lock()
        
        self.status = new_status
        self.save()

    def set_info(self) -> None:
        """Set customer information through user input."""
        self.first_name = self._input_name("Enter first name: ")
        self.last_name = self._input_name("Enter last name: ")
        self.email = self._input_email("Enter email: ")
        self.password = self._input_password("Enter password: ")
        self.status = 'basic'
        self.save()

    def _input_name(self, prompt: str) -> str:
        """Get valid name input from user.
        
        Args:
            prompt: Input prompt message
            
        Returns:
            str: Valid name
        """
        while True:
            name = input(prompt).strip()
            if not name.isalpha():
                print("Error: Please enter a valid name (letters only).")
                continue
            return name

    @classmethod
    def email_exists(cls, email: str) -> bool:
        """Check if email is already registered.
        
        Args:
            email: Email to check
            
        Returns:
            bool: True if email exists
        """
        users_data = cls._load_all_users()
        return email in users_data

    def _input_email(self, prompt: str) -> str:
        """Get valid email input from user.
        
        Args:
            prompt: Input prompt message
            
        Returns:
            str: Valid email address
        """
        while True:
            email = input(prompt).strip()
            if not re.match(r"^[\w\.-]+@[\w\.-]+\.\w+$", email):
                print("Error: Please enter a valid email address.")
                continue
            if self.email_exists(email):
                print("Error: Email already exists!")
                continue
            return email

    def _input_password(self, prompt: str) -> str:
        """Get valid password input from user.
        
        Args:
            prompt: Input prompt message
            
        Returns:
            str: Valid password
        """
        while True:
            password = input(prompt).strip()
            if len(password) < 6:
                print("Error: Password must be at least 6 characters long.")
                continue
            confirm = input("Confirm password: ").strip()
            if password != confirm:
                print("Error: Passwords do not match.")
                continue
            return password

    def get_credit_card(self) -> CreditCard:
        """Issue new credit card.
        
        Returns:
            CreditCard: New credit card instance
            
        Raises:
            ValueError: If credit card limit reached
        """
        if len(self.credit_cards) >= self.limits.get_credit_card_limit(self.status):
            raise ValueError(f'Credit card limit reached for {self.status} status.')
        
        # Определяем лимит в зависимости от статуса
        credit_limit = 2000 if self.status == 'premium' else 1000
        new_credit_card = CreditCard(credit_limit=credit_limit)
        new_credit_card.set_data()
        self.credit_cards.append(new_credit_card)
        return new_credit_card

    def get_debit_card(self) -> BankCard:
        """Issue new debit card.
        
        Returns:
            BankCard: New debit card instance
            
        Raises:
            ValueError: If debit card limit reached
        """
        if len(self.debit_cards) >= self.limits.get_debit_card_limit(self.status):
            raise ValueError(f'Debit card limit reached for {self.status} status.')
        
        new_debit_card = BankCard()
        new_debit_card.set_data()
        self.debit_cards.append(new_debit_card)
        return new_debit_card

    def deposit(self, card_index: int, amount: float) -> bool:
        """Add money to the card."""
        if amount <= 0:
            raise ValueError("Deposit amount must be positive")

        if card_index == 0 and self.debit_cards:
            card = self.debit_cards[0]
        elif card_index == 1 and self.credit_cards:
            card = self.credit_cards[0]
        else:
            return False

        if self._bank.process_deposit(card, amount):
            self.add_transaction("deposit", amount, card.card_number)
            self.save()
            return True
        return False

    def withdraw(self, card_index: int, amount: float, pin: str) -> bool:
        """Withdraw money from the card."""

        if amount <= 0:
            raise ValueError("Withdrawal amount must be positive")
        
        # Проверяем лимит снятия
        withdrawal_limit = self.limits.get_withdrawal_limit(self.status)
        if amount > withdrawal_limit:
            raise ValueError(f"Amount exceeds withdrawal limit ({withdrawal_limit:.2f}) for {self.status} status")

        if not self.pin.verify_pin_code(pin):
            raise ValueError("Invalid PIN code")

        if card_index == 0 and self.debit_cards:
            card = self.debit_cards[0]
        elif card_index == 1 and self.credit_cards:
            card = self.credit_cards[0]
        else:
            return False

        if self._bank.process_withdrawal(card, amount, pin):
            self.add_transaction("withdrawal", amount, card.card_number)
            self.save()
            return True
        return False

    def verify_password(self, password: str) -> bool:
        """Verify if provided password matches.
        
        Args:
            password: Password to verify
            
        Returns:
            bool: True if password matches
        """
        return self.password == password

    def make_payment(self, card_index: int, amount: float, pin: str, description: str) -> bool:
        """Make a payment using selected card."""
        if not self.pin.verify_pin_code(pin):
            raise ValueError("Invalid PIN code")

        if amount <= 0:
            raise ValueError("Payment amount must be positive")

        if card_index == 0 and self.debit_cards:
            card = self.debit_cards[0]
        elif card_index == 1 and self.credit_cards:
            card = self.credit_cards[0]
        else:
            return False

        if self._bank.process_payment(card, amount, pin, description):
            self.add_transaction("payment", amount, card.card_number, description)
            self.save()
            return True
        return False

    def add_transaction(self, transaction_type: str, amount: float, card_number: str, description: str = "") -> None:
        """Add a new transaction to history.
        
        Args:
            transaction_type: Type of transaction (deposit/withdrawal/payment)
            amount: Transaction amount
            card_number: Card number used for transaction
            description: Optional transaction description
        """
        if not hasattr(self, 'transactions'):
            self.transactions = []
        self.transactions.append({
            'type': transaction_type,
            'amount': amount,
            'card_number': card_number,
            'description': description,
            'date': datetime.now().strftime("%m/%d/%Y %I:%M")
        })


