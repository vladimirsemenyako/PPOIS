"""Module for handling PIN operations in CLI."""

from models.customer import Customer


class PinHandler:
    """Handler for PIN-related operations."""

    @staticmethod
    def handle_pin_creation(customer: Customer) -> None:
        """Handle PIN code creation."""
        if customer.pin.has_pin_code():
            print("\nPIN-code already exists!")
            return
            
        pin = input("\nEnter new PIN-code (4 digits): ")
        if customer.pin.set_pin_code(pin):
            print("\nPIN-code successfully set!")
            customer.save()
        else:
            print("\nFailed to set PIN-code. Please make sure it's 4 digits.")

    @staticmethod
    def handle_pin_generation(customer: Customer) -> None:
        """Handle PIN code generation."""
        if customer.pin.has_pin_code():
            print("\nPIN-code already exists!")
            return
            
        pin = customer.pin.generate_pin_code()
        print(f"\nGenerated PIN-code: {pin}")
        customer.save()

    @staticmethod
    def handle_pin_change(customer: Customer) -> None:
        """Handle PIN code change."""
        if not customer.pin.has_pin_code():
            print("\nNo PIN-code set!")
            return
            
        old_pin = input("\nEnter current PIN-code: ")
        new_pin = input("Enter new PIN-code (4 digits): ")
        
        if customer.pin.change_pin_code(old_pin, new_pin):
            print("\nPIN-code successfully changed!")
            customer.save()
        else:
            print("\nFailed to change PIN-code. Please check your current PIN-code and make sure the new one is 4 digits.") 