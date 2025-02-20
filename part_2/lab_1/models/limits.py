"""Module for managing account limits based on status."""

from typing import Dict


class Limits:
    """Account limits manager."""

    def __init__(self) -> None:
        """Initialize limits for different account statuses."""
        self.limits: Dict[str, Dict[str, int]] = {
            'basic': {
                'credit_card_limit': 1,
                'debit_card_limit': 2,
                'withdrawal_limit': 500,
            },
            'premium': {
                'credit_card_limit': 2,
                'debit_card_limit': 3,
                'withdrawal_limit': 1000,
            }
        }

    def get_credit_card_limit(self, status: str) -> int:
        """Get maximum number of credit cards allowed.
        
        Args:
            status: Account status (basic/premium)
            
        Returns:
            int: Maximum number of credit cards
        """
        return self.limits[status]['credit_card_limit']

    def get_debit_card_limit(self, status: str) -> int:
        """Get maximum number of debit cards allowed.
        
        Args:
            status: Account status (basic/premium)
            
        Returns:
            int: Maximum number of debit cards
        """
        return self.limits[status]['debit_card_limit']

    def get_withdrawal_limit(self, status: str) -> int:
        """Get maximum withdrawal amount allowed.
        
        Args:
            status: Account status (basic/premium)
            
        Returns:
            int: Maximum withdrawal amount
        """
        return self.limits[status]['withdrawal_limit']