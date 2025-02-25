from .bank_card import BankCard


class CreditCard(BankCard):
    """Credit card with a credit limit.
    
    This class extends BankCard to add credit limit functionality.
    The balance represents available credit rather than actual money.
    """

    def __init__(self, credit_limit: float = 1000) -> None:
        """Initialize a credit card.
        
        Args:
            credit_limit: Maximum credit amount available
        """
        super().__init__(balance=credit_limit)
        self.credit_limit = float(credit_limit)

    @property
    def available_credit(self) -> float:
        """Get available credit amount.
        
        Returns:
            float: Amount of credit still available
        """
        return self.balance

    def __str__(self) -> str:
        """Return string representation of the credit card."""
        return (
            'Credit Card\n'
            f'Card Number: {self.card_number}\n'
            f'CVV: {self.cvv_number}\n'
            f'Expiry Date: {self.exp_date}\n'
            f'Available Credit: {self.balance:.2f}\n'
            f'Credit Limit: {self.credit_limit:.2f}\n'
            f'Status: {"Locked" if self.is_locked else "Active"}'
        )

