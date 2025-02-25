"""Module for handling PIN code operations."""

import random


class PinCode:

    def __init__(self, pin_code: str | None = None) -> None:
        self._pin_code = pin_code

    def set_pin_code(self, new_pin: str) -> bool:
        if not isinstance(new_pin, str):
            return False
        
        if not new_pin.isdigit() or len(new_pin) != 4:
            return False
        
        self._pin_code = new_pin
        return True

    def change_pin_code(self, old_pin: str, new_pin: str) -> bool:
        if not self.verify_pin_code(old_pin):
            return False
            
        return self.set_pin_code(new_pin)

    def generate_pin_code(self) -> str:
        self._pin_code = str(random.randint(1000, 9999))
        return self._pin_code

    def get_pin_code(self) -> str | None:
        return self._pin_code

    def has_pin_code(self) -> bool:
        return self._pin_code is not None

    def verify_pin_code(self, pin: str) -> bool:
        if not self.has_pin_code():
            return False
        return pin == self._pin_code