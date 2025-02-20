"""Module for CLI state management."""

from abc import ABC, abstractmethod
from ..models.customer import Customer


class State(ABC):
    """Abstract base class for CLI states."""
    
    def __init__(self, cli) -> None:
        """Initialize state with CLI reference."""
        self.cli = cli
    
    @abstractmethod
    def show_menu(self) -> None:
        """Display menu for current state."""
        pass
    
    @abstractmethod
    def handle_input(self, choice: str) -> None:
        """Handle user input for current state."""
        pass


class InitialState(State):
    """State for non-authenticated users."""
    
    def show_menu(self) -> None:
        """Display initial menu."""
        self.cli.clear_screen()
        print("\n=== Banking System ===")
        print("1. Login")
        print("2. Register")
        print("3. Administrator")
        print("4. Exit")

    def handle_input(self, choice: str) -> None:
        """Handle initial menu choices."""
        if choice == "1":
            self.cli.login()
            if self.cli.customer:
                self.cli.change_state(AuthenticatedState(self.cli))
        elif choice == "2":
            self.cli.register()
            if self.cli.customer:
                self.cli.change_state(AuthenticatedState(self.cli))
        elif choice == "3":
            self.cli.clear_screen()
            admin_password = input("Enter administrator password: ")
            if admin_password == self.cli.ADMIN_PASSWORD:
                self.cli.change_state(AdminState(self.cli))
            else:
                print("\nIncorrect administrator password!")
                input("\nPress Enter to continue...")
        elif choice == "4":
            self.cli.clear_screen()
            exit()


class AuthenticatedState(State):
    """State for authenticated users."""
    
    def show_menu(self) -> None:
        """Display main menu."""
        self.cli.clear_screen()
        print(f"\n=== Main Menu (User: {self.cli.customer.email}) ===")
        print(f"Status: {self.cli.customer.status}")
        print("\n1. Create PIN-code")
        print("2. Generate PIN-code")
        print("3. Check balance")
        print("4. Issue debit card")
        print("5. Issue credit card")
        print("6. Change status")
        print("7. Block card")
        print("8. Unblock card")
        print("9. Deposit")
        print("10. Withdraw")
        print("11. Make payment")
        print("12. View transactions")
        print("13. Change PIN-code")
        print("14. Logout")

    def handle_input(self, choice: str) -> None:
        """Handle authenticated user menu choices."""
        self.cli.clear_screen()
        
        if choice == "14":
            self.cli.customer = None
            self.cli.change_state(InitialState(self.cli))
            return
            
        # Обрабатываем выбор пользователя
        self.cli.process_main_menu_choice(choice)


class AdminState(State):
    """State for administrator interface."""
    
    def show_menu(self) -> None:
        """Display admin menu."""
        self.cli.clear_screen()
        print("\n=== Administrator Panel ===")
        print("1. View all users")
        print("2. Delete user")
        print("3. Return to main menu")

    def handle_input(self, choice: str) -> None:
        """Handle admin menu choices."""
        if choice == "1":
            self.cli.clear_screen()
            users = Customer.get_all_users()
            if not users:
                print("No registered users")
            else:
                print("\nList of all users:")
                for user in users:
                    print(f"\nID: {user.customer_id}")
                    print(f"Name: {user.first_name} {user.last_name}")
                    print(f"Email: {user.email}")
                    print(f"Status: {user.status}")
                    print(f"Password set: {'Yes' if user.password else 'No'}")
                    print(f"Debit cards: {len(user.debit_cards)}")
                    print(f"Credit cards: {len(user.credit_cards)}")
                    print("-" * 40)
            input("\nPress Enter to continue...")
        elif choice == "2":
            self.cli.clear_screen()
            email = input("Enter user email to delete: ")
            if not Customer.email_exists(email):
                print("\nUser not found!")
            else:
                confirm = input(f"\nAre you sure you want to delete user {email}? (yes/no): ")
                if confirm.lower() == 'yes':
                    user = Customer.load(email)
                    user.delete()
                    print("\nUser successfully deleted!")
                else:
                    print("\nDeletion cancelled.")
            input("\nPress Enter to continue...")
        elif choice == "3":
            self.cli.change_state(InitialState(self.cli)) 