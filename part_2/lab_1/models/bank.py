"""Module for handling bank operations."""

from typing import Optional, Dict, Any, List
from datetime import datetime
from .bank_card import BankCard
from .credit_card import CreditCard


class Bank:
    """Bank operations handler.
    
    This class handles all banking operations like deposits, withdrawals and payments.
    In a real system, this would communicate with actual banking infrastructure.
    """

    def __init__(self) -> None:
        """Initialize bank instance."""
        self._transactions: Dict[str, List[Dict]] = {}

    def verify_pin(self, card_number: str, pin: str) -> bool:
        """Verify PIN code for card.
        
        In production, this would verify PIN with actual banking system.
        For testing purposes, always returns True.
        
        Args:
            card_number: Card number to verify
            pin: PIN code to verify
            
        Returns:
            bool: True if PIN is correct
        """
        return True

    def _validate_amount(self, amount: float) -> None:
        """Validate transaction amount.
        
        Args:
            amount: Amount to validate
            
        Raises:
            ValueError: If amount is not positive
        """
        if amount <= 0:
            raise ValueError("Amount must be positive")

    def _check_card_status(self, card: BankCard) -> None:
        """Check if card is valid for transactions.
        
        Args:
            card: Card to check
            
        Raises:
            ValueError: If card is locked or expired
        """
        if card.is_locked:
            raise ValueError("Card is locked")
        if not card.is_valid():
            raise ValueError("Card has expired")

    def process_withdrawal(self, card: BankCard, amount: float, pin: str) -> bool:
        """Process withdrawal operation.
        
        Args:
            card: Card to withdraw from
            amount: Amount to withdraw
            pin: PIN code for verification
            
        Returns:
            bool: True if withdrawal successful
            
        Raises:
            ValueError: If operation is invalid
        """
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
        """Process deposit operation.
        
        Args:
            card: Card to deposit to
            amount: Amount to deposit
            
        Returns:
            bool: True if deposit successful
            
        Raises:
            ValueError: If operation is invalid
        """
        self._validate_amount(amount)
        self._check_card_status(card)
            
        if isinstance(card, CreditCard) and card.balance + amount > card.credit_limit:
            raise ValueError("Deposit would exceed credit limit")
                
        card.balance += amount
        self._add_transaction(card.card_number, "deposit", amount)
        return True

    def process_payment(self, card: BankCard, amount: float, pin: str, description: str = "") -> bool:
        """Process payment operation.
        
        Args:
            card: Card to make payment from
            amount: Payment amount
            pin: PIN code for verification
            description: Optional payment description
            
        Returns:
            bool: True if payment successful
            
        Raises:
            ValueError: If operation is invalid
        """
        # Payment is essentially a withdrawal with description
        if self.process_withdrawal(card, amount, pin):
            self._add_transaction(card.card_number, "payment", amount, description)
            return True
        return False

    def get_card_transactions(self, card_number: str) -> List[Dict]:
        """Get transaction history for card.
        
        Args:
            card_number: Card number to get transactions for
            
        Returns:
            list: List of transactions for the card
        """
        return self._transactions.get(card_number, [])

    def _add_transaction(self, card_number: str, trans_type: str, amount: float, description: str = "") -> None:
        """Add transaction to history.
        
        Args:
            card_number: Card number
            trans_type: Type of transaction (deposit/withdrawal/payment)
            amount: Transaction amount
            description: Optional transaction description
        """
        if card_number not in self._transactions:
            self._transactions[card_number] = []
            
        self._transactions[card_number].append({
            'type': trans_type,
            'amount': amount,
            'description': description,
            'date': datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        }) 