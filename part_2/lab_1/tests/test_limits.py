"""Tests for account limits functionality."""

import unittest
from models import Limits


class TestLimits(unittest.TestCase):
    """Test cases for Limits class."""

    def setUp(self):
        """Set up test cases."""
        self.limits = Limits()

    def test_basic_limits(self):
        """Test limits for basic status."""
        self.assertEqual(self.limits.get_credit_card_limit("basic"), 1)
        self.assertEqual(self.limits.get_debit_card_limit("basic"), 2)
        self.assertEqual(self.limits.get_withdrawal_limit("basic"), 500)

    def test_premium_limits(self):
        """Test limits for premium status."""
        self.assertEqual(self.limits.get_credit_card_limit("premium"), 2)
        self.assertEqual(self.limits.get_debit_card_limit("premium"), 3)
        self.assertEqual(self.limits.get_withdrawal_limit("premium"), 1000)

    def test_limits_comparison(self):
        """Test comparison between basic and premium limits."""
        self.assertLess(
            self.limits.get_credit_card_limit("basic"),
            self.limits.get_credit_card_limit("premium")
        )
        self.assertLess(
            self.limits.get_debit_card_limit("basic"),
            self.limits.get_debit_card_limit("premium")
        )
        self.assertLess(
            self.limits.get_withdrawal_limit("basic"),
            self.limits.get_withdrawal_limit("premium")
        )


if __name__ == '__main__':
    unittest.main() 