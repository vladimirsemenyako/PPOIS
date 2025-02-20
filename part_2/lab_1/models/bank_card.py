"""Module for handling bank card operations."""

import random
from datetime import datetime, timedelta
from typing import Optional


class BankCard:
    """Base class for bank cards.
    
    This class implements basic card functionality like balance tracking
    and card status management.
    """

    def __init__(
        self,
        card_number: str | None = None,
        cvv_number: int | None = None,
        exp_date: str | None = None,
        balance: float = 0
    ) -> None:
        """Initialize a bank card.
        
        Args:
            card_number: Card number (16 digits)
            cvv_number: CVV security code (3 digits)
            exp_date: Expiration date (YYYY-MM-DD)
            balance: Initial balance
        """
        self.card_number = card_number
        self.cvv_number = cvv_number
        self.exp_date = exp_date
        self.balance = float(balance)
        self.is_locked: bool = False

    def set_data(self) -> None:
        """Set up initial card data with random values."""
        self.card_number = "".join(str(random.randint(0, 9)) for _ in range(16))
        self.cvv_number = random.randint(100, 999)
        self.exp_date = (
            datetime.today() + timedelta(days=365)
        ).strftime("%Y-%m-%d")

    def is_valid(self) -> bool:
        """Check if the card is still valid.
        
        Returns:
            bool: True if card hasn't expired
        """
        if not self.exp_date:
            return False
        return datetime.strptime(self.exp_date, "%Y-%m-%d").date() > datetime.today().date()

    def check_balance(self) -> Optional[float]:
        """Check card balance.
        
        Returns:
            float: Current balance if card is not locked, None otherwise
        """
        return None if self.is_locked else self.balance

    def lock(self) -> None:
        """Lock the card, preventing any operations."""
        self.is_locked = True

    def unlock(self) -> None:
        """Unlock the card, allowing operations."""
        self.is_locked = False

    def __str__(self) -> str:
        """Return string representation of the card."""
        return (
            f'Card Number: {self.card_number}\n'
            f'CVV: {self.cvv_number}\n'
            f'Expire Date: {self.exp_date}\n'
            f'Balance: {self.balance:.2f}\n'
            f'Status: {"Locked" if self.is_locked else "Active"}'
        )



