import os
from typing import Optional, List, Tuple, Union

from models.customer import Customer
from .states import State, InitialState
from .card_operations import CardOperationsHandler
from .pin_handler import PinHandler


class CLI:
    ADMIN_PASSWORD = "1111"

    def __init__(self) -> None:
        self.customer: Optional[Customer] = None
        self._state: Optional[State] = None
        self.change_state(InitialState(self))
        self.card_ops = CardOperationsHandler()
        self.pin_handler = PinHandler()

    def change_state(self, state: State) -> None:
        self._state = state

    def clear_screen(self) -> None:
        os.system('clear')

    def start(self) -> None:
        while True:
            self._state.show_menu()
            choice = input("\nSelect action: ")
            self._state.handle_input(choice)

    def show_initial_menu(self) -> None:
        self.clear_screen()
        print("\n=== Banking System ===")
        print("1. Login")
        print("2. Register")
        print("3. Administrator")
        print("4. Exit")

        choice = input("\nSelect action: ")

        if choice == "1":
            self.login()
        elif choice == "2":
            self.register()
        elif choice == "3":
            self.clear_screen()
            admin_password = input("Enter administrator password: ")
            if admin_password == self.ADMIN_PASSWORD:
                self.show_admin_menu()
            else:
                print("\nIncorrect administrator password!")
                input("\nPress Enter to continue...")
        elif choice == "4":
            self.clear_screen()
            exit()

    def show_admin_menu(self) -> None:
        self.clear_screen()
        print("\n=== Administrator Panel ===")
        print("1. View all users")
        print("2. Delete user")
        print("3. Return to main menu")

        choice = input("\nSelect action: ")

        if choice == "1":
            self.clear_screen()
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
            self.clear_screen()
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

    def _input_admin_password(self) -> Optional[str]:
        print("\nEnter new password (minimum 6 characters)")
        print("Leave empty to cancel")

        while True:
            password = input("New password: ").strip()
            if not password:
                return None

            if len(password) < 6:
                print("Error: Password must be at least 6 characters long.")
                continue

            confirm = input("Confirm password: ").strip()
            if password != confirm:
                print("Error: Passwords do not match.")
                continue

            return password

    def login(self):
        self.clear_screen()
        while True:
            email = input("Enter email: ")
            if not Customer.email_exists(email):
                print("\nUser not found! Do you want to register? (yes/no)")
                if input().lower() == 'yes':
                    self.register()
                    return
                else:
                    return

            customer = Customer.load(email)
            password = input("Enter password: ")

            if not customer.verify_password(password):
                print("\nIncorrect password!")
                input("\nPress Enter to continue...")
                return

            self.customer = customer
            print("\nLogin successful!")
            input("\nPress Enter to continue...")
            return

    def register(self):
        self.clear_screen()
        try:
            self.customer = Customer()
            self.customer.set_info()
            print("\nRegistration successful!")
            input("\nPress Enter to continue...")
        except KeyboardInterrupt:
            print("\nRegistration canceled.")
            self.customer = None

    def show_main_menu(self):
        self.clear_screen()
        print(f"\n=== Main Menu (User: {self.customer.email}) ===")
        print(f"Status: {self.customer.status}")
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
        print("14. Exit")

        choice = input("\nSelect action: ")
        self.process_main_menu_choice(choice)

    def process_main_menu_choice(self, choice: str) -> None:
        self.clear_screen()

        if choice == "1":
            self.pin_handler.handle_pin_creation(self.customer)
        elif choice == "2":
            self.pin_handler.handle_pin_generation(self.customer)
        elif choice == "3":
            self.card_ops.handle_balance_check(self.customer)
        elif choice == "4":
            self.card_ops.handle_card_issuance(self.customer, is_credit=False)
        elif choice == "5":
            self.card_ops.handle_card_issuance(self.customer, is_credit=True)
        elif choice == "6":
            self.handle_status_change()
        elif choice == "7":
            self.card_ops.handle_card_blocking(self.customer, block=True)
        elif choice == "8":
            self.card_ops.handle_card_blocking(self.customer, block=False)
        elif choice == "9":
            self.card_ops.handle_transaction(self.customer, "deposit")
        elif choice == "10":
            self.card_ops.handle_transaction(self.customer, "withdrawal")
        elif choice == "11":
            self.card_ops.handle_transaction(self.customer, "payment")
        elif choice == "12":
            self.show_transactions()
        elif choice == "13":
            self.pin_handler.handle_pin_change(self.customer)
        elif choice == "14":
            self.customer = None
            return

        if choice != "14":
            input("\nPress Enter to continue...")

    def handle_status_change(self):
        self.customer.change_status()
        print(f"\nNew status: {self.customer.status}")
        self.customer.save()

    def show_transactions(self):
        if not self.customer.transactions:
            print("\nNo transactions found!")
        else:
            print("\nTransaction history:")
            for trans in self.customer.transactions:
                print(f"\nType: {trans['type'].capitalize()}")
                print(f"Amount: {trans['amount']:.2f}")
                print(f"Card: {trans['card_number']}")
                if trans['description']:
                    print(f"Description: {trans['description']}")
                print(f"Date: {trans['date']}")
                print("-" * 40)
