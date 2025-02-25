"""Module for handling card operations in CLI."""

from typing import Optional, List, Tuple, Union
from models.customer import Customer
from models.bank_card import BankCard
from models.credit_card import CreditCard


class CardOperationsHandler:

    @staticmethod
    def _show_cards_list(customer: Customer) -> List[Tuple[str, Union[BankCard, CreditCard]]]:
        available_cards = []
        for card in customer.debit_cards:
            available_cards.append(("Debit", card))
        for card in customer.credit_cards:
            available_cards.append(("Credit", card))
        for i, (card_type, card) in enumerate(available_cards, 1):
            balance_text = "Available" if isinstance(card, CreditCard) else "Balance"
            print(f"{i}) {card_type} Card: {card.card_number} ({balance_text}: {card.balance:.2f}, Status: {'Locked' if card.is_locked else 'Active'})")
            
        return available_cards

    @staticmethod
    def handle_balance_check(customer: Customer) -> None:
        print("\n=== Balance Check ===")
        
        if not (customer.debit_cards or customer.credit_cards):
            print("\nNo cards available.")
            return
            
        CardOperationsHandler._show_cards_list(customer)

    @staticmethod
    def handle_card_issuance(customer: Customer, is_credit: bool = False) -> None:
        try:
            if not customer.pin.has_pin_code():
                print("\nError: You must set a PIN code before issuing any cards.")
                print("Please use the 'Create PIN-code' or 'Generate PIN-code' option first.")
                return
            
            if is_credit:
                card = customer.get_credit_card()
                print("\nCredit card successfully issued!")
            else:
                card = customer.get_debit_card()
                print("\nDebit card successfully issued!")
                
            print(f"\nNew card: {card.card_number} (CVV: {card.cvv_number}, Expires: {card.exp_date})")
            customer.save()
        except ValueError as e:
            print(f"\nFailed to issue card: {e}")

    @staticmethod
    def handle_card_blocking(customer: Customer, block: bool = True) -> None:
        if not (customer.debit_cards or customer.credit_cards):
            print("\nNo cards available.")
            return

        print(f"\n=== {'Block' if block else 'Unblock'} Card ===")
        
        available_cards = CardOperationsHandler._show_cards_list(customer)
        
        try:
            choice = int(input("\nSelect card number: "))
            if choice < 1 or choice > len(available_cards):
                print("\nInvalid card choice.")
                return

            card_type, card = available_cards[choice - 1]
            if not block:
                if card_type == "Credit" and len(customer.credit_cards) > customer.limits.get_credit_card_limit(customer.status):
                    print("\nCannot unblock: Credit card limit exceeded for current status.")
                    return
                if card_type == "Debit" and len(customer.debit_cards) > customer.limits.get_debit_card_limit(customer.status):
                    print("\nCannot unblock: Debit card limit exceeded for current status.")
                    return

            if block:
                card.lock()
                print("\nCard successfully blocked.")
            else:
                card.unlock()
                print("\nCard successfully unblocked.")
            customer.save()
            
            print(f"\nUpdated status: {card.card_number} - {'Locked' if card.is_locked else 'Active'}")
        except ValueError:
            print("\nInvalid input.")

    @staticmethod
    def handle_transaction(customer: Customer, transaction_type: str) -> None:
        if not (customer.debit_cards or customer.credit_cards):
            print("\nNo cards available.")
            return

        print(f"\n=== {transaction_type.capitalize()} ===")
        if transaction_type == "withdrawal":
            withdrawal_limit = customer.limits.get_withdrawal_limit(customer.status)
            print(f"Withdrawal limit for {customer.status} status: {withdrawal_limit:.2f}")
        
        available_cards = CardOperationsHandler._show_cards_list(customer)
        
        try:
            choice = int(input("\nSelect card number: "))
            if choice < 1 or choice > len(available_cards):
                print("\nInvalid card choice.")
                return

            card_type, card = available_cards[choice - 1]
            card_index = choice - 1

            amount = float(input(f"\nEnter {transaction_type} amount: "))
            
            if transaction_type == "payment":
                description = input("Enter payment description: ")
                pin = input("Enter PIN-code: ")
                if customer.make_payment(card_index, amount, pin, description):
                    print(f"\n{transaction_type.capitalize()} successful!")
                    print(f"\nUpdated balance: {card.balance:.2f}")
                else:
                    print(f"\nFailed to process {transaction_type}.")
            elif transaction_type == "withdrawal":
                pin = input("Enter PIN-code: ")
                if customer.withdraw(card_index, amount, pin):
                    print(f"\n{transaction_type.capitalize()} successful!")
                    print(f"\nUpdated balance: {card.balance:.2f}")
                else:
                    print(f"\nFailed to process {transaction_type}.")
            else:  # deposit
                if customer.deposit(card_index, amount):
                    print(f"\n{transaction_type.capitalize()} successful!")
                    print(f"\nUpdated balance: {card.balance:.2f}")
                else:
                    print(f"\nFailed to process {transaction_type}.")
                    
        except ValueError as e:
            print(f"\nError: {e}")
        except IndexError:
            print("\nInvalid card choice.") 