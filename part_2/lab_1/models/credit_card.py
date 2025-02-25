from .bank_card import BankCard


class CreditCard(BankCard):
    def __init__(self, credit_limit: float = 1000) -> None:
        super().__init__(balance=credit_limit)
        self.credit_limit = float(credit_limit)

    @property
    def available_credit(self) -> float:
        return self.balance

    def __str__(self) -> str:
        return (
            'Credit Card\n'
            f'Card Number: {self.card_number}\n'
            f'CVV: {self.cvv_number}\n'
            f'Expiry Date: {self.exp_date}\n'
            f'Available Credit: {self.balance:.2f}\n'
            f'Credit Limit: {self.credit_limit:.2f}\n'
            f'Status: {"Locked" if self.is_locked else "Active"}'
        )

