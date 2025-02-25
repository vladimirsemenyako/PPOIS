"""Module for handling bank card operations."""

import random
from datetime import datetime, timedelta


class BankCard:

    def __init__(self, balance: float = 0) -> None:
        self.card_number = None
        self.cvv_number = None
        self.exp_date = None
        self.balance = float(balance)
        self.is_locked = False

    def set_data(self) -> None:
        self.card_number = "".join(str(random.randint(0, 9)) for _ in range(16))
        self.cvv_number = random.randint(100, 999)
        self.exp_date = (
            datetime.today() + timedelta(days=365)
        ).strftime("%Y-%m-%d")

    def is_valid(self) -> bool:
        if not self.exp_date:
            return False
        return datetime.strptime(self.exp_date, "%Y-%m-%d").date() > datetime.today().date()

    def check_balance(self) -> float | None:
        return None if self.is_locked else self.balance

    def lock(self) -> None:
        self.is_locked = True

    def unlock(self) -> None:
        self.is_locked = False

    def __str__(self) -> str:
        return (
            f'Card Number: {self.card_number}\n'
            f'CVV: {self.cvv_number}\n'
            f'Expire Date: {self.exp_date}\n'
            f'Balance: {self.balance:.2f}\n'
            f'Status: {"Locked" if self.is_locked else "Active"}'
        )



