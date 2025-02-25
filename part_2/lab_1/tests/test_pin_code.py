"""Tests for PIN code functionality."""

import unittest
from models.pin_code import PinCode


class TestPinCode(unittest.TestCase):
    """Test cases for PinCode class."""

    def setUp(self):
        """Set up test cases."""
        self.pin = PinCode()

    def test_set_pin_code(self):
        """Test setting PIN code."""
        self.assertTrue(self.pin.set_pin_code("1234"))
        self.assertEqual(self.pin.get_pin_code(), "1234")

    def test_set_invalid_pin_code(self):
        """Test setting invalid PIN code."""
        self.assertFalse(self.pin.set_pin_code("123"))  # Too short
        self.assertFalse(self.pin.set_pin_code("12345"))  # Too long
        self.assertFalse(self.pin.set_pin_code("abcd"))  # Non-numeric
        self.assertFalse(self.pin.set_pin_code(""))  # Empty

    def test_generate_pin_code(self):
        """Test generating PIN code."""
        pin = self.pin.generate_pin_code()
        self.assertEqual(len(pin), 4)
        self.assertTrue(pin.isdigit())
        self.assertEqual(self.pin.get_pin_code(), pin)

    def test_has_pin_code(self):
        """Test checking if PIN code exists."""
        self.assertFalse(self.pin.has_pin_code())
        self.pin.set_pin_code("1234")
        self.assertTrue(self.pin.has_pin_code())

    def test_verify_pin_code(self):
        """Test PIN code verification."""
        self.pin.set_pin_code("1234")
        self.assertTrue(self.pin.verify_pin_code("1234"))
        self.assertFalse(self.pin.verify_pin_code("4321"))

    def test_change_pin_code(self):
        """Test changing PIN code."""
        self.pin.set_pin_code("1234")
        self.assertTrue(self.pin.change_pin_code("1234", "5678"))
        self.assertEqual(self.pin.get_pin_code(), "5678")
        self.assertFalse(self.pin.change_pin_code("1234", "9012"))  # Wrong old PIN


if __name__ == '__main__':
    unittest.main() 