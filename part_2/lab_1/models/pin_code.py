"""Module for handling PIN code operations."""

import random


class PinCode:
    """PIN code manager for cards."""

    def __init__(self, pin_code: str | None = None) -> None:
        """Initialize PIN code.
        
        Args:
            pin_code: Initial PIN code
        """
        self._pin_code = pin_code

    def set_pin_code(self, new_pin: str) -> bool:
        """Set a new PIN code.
        
        Args:
            new_pin: New 4-digit PIN code
            
        Returns:
            bool: True if PIN code was set successfully
        """
        if not isinstance(new_pin, str):
            return False
        
        if not new_pin.isdigit() or len(new_pin) != 4:
            return False
        
        self._pin_code = new_pin
        return True

    def change_pin_code(self, old_pin: str, new_pin: str) -> bool:
        """Change existing PIN code.
        
        Args:
            old_pin: Current PIN code for verification
            new_pin: New 4-digit PIN code
            
        Returns:
            bool: True if PIN code was changed successfully
        """
        if not self.verify_pin_code(old_pin):
            return False
            
        return self.set_pin_code(new_pin)

    def generate_pin_code(self) -> str:
        """Generate a random PIN code.
        
        Returns:
            str: New 4-digit PIN code
        """
        self._pin_code = str(random.randint(1000, 9999))
        return self._pin_code

    def get_pin_code(self) -> str | None:
        """Get current PIN code.
        
        Returns:
            str: Current PIN code or None if not set
        """
        return self._pin_code

    def has_pin_code(self) -> bool:
        """Check if PIN code is set.
        
        Returns:
            bool: True if PIN code is set
        """
        return self._pin_code is not None

    def verify_pin_code(self, pin: str) -> bool:
        """Verify if provided PIN code matches.
        
        Args:
            pin: PIN code to verify
            
        Returns:
            bool: True if PIN code matches
        """
        if not self.has_pin_code():
            return False
        return pin == self._pin_code