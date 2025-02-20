"""Tests for CLI states."""

import unittest
from unittest.mock import Mock, patch
from cli.states import State, InitialState, AuthenticatedState, AdminState
from models.customer import Customer


class TestStates(unittest.TestCase):
    """Test cases for CLI states."""

    def setUp(self):
        """Set up test cases."""
        self.mock_cli = Mock()
        self.mock_cli.ADMIN_PASSWORD = "1111"
        self.mock_cli.customer = None

    def test_initial_state_menu(self):
        """Test initial state menu display."""
        state = InitialState(self.mock_cli)
        with patch('builtins.print') as mock_print:
            state.show_menu()
            self.mock_cli.clear_screen.assert_called_once()
            mock_print.assert_any_call("\n=== Banking System ===")
            mock_print.assert_any_call("1. Login")
            mock_print.assert_any_call("2. Register")

    def test_initial_state_login(self):
        """Test initial state login handling."""
        state = InitialState(self.mock_cli)
        
        # Simulate successful login
        self.mock_cli.login = Mock(side_effect=lambda: setattr(self.mock_cli, 'customer', Mock()))
        state.handle_input("1")
        self.mock_cli.login.assert_called_once()
        self.mock_cli.change_state.assert_called_once()
        
        # Simulate failed login
        self.mock_cli.login = Mock()
        state.handle_input("1")
        self.mock_cli.login.assert_called_once()
        self.assertEqual(self.mock_cli.change_state.call_count, 1)  # Не должно измениться

    def test_initial_state_register(self):
        """Test initial state registration handling."""
        state = InitialState(self.mock_cli)
        
        # Simulate successful registration
        self.mock_cli.register = Mock(side_effect=lambda: setattr(self.mock_cli, 'customer', Mock()))
        state.handle_input("2")
        self.mock_cli.register.assert_called_once()
        self.mock_cli.change_state.assert_called_once()
        
        # Simulate failed registration
        self.mock_cli.register = Mock()
        state.handle_input("2")
        self.mock_cli.register.assert_called_once()
        self.assertEqual(self.mock_cli.change_state.call_count, 1)  # Не должно измениться

    def test_initial_state_admin(self):
        """Test initial state admin access."""
        state = InitialState(self.mock_cli)
        
        with patch('builtins.input', return_value="1111"):
            state.handle_input("3")
            self.mock_cli.clear_screen.assert_called()
            self.mock_cli.change_state.assert_called_once()
        
        with patch('builtins.input', return_value="wrong"):
            state.handle_input("3")
            self.assertEqual(self.mock_cli.change_state.call_count, 1)  # Не должно измениться

    def test_authenticated_state_menu(self):
        """Test authenticated state menu display."""
        self.mock_cli.customer = Mock()
        self.mock_cli.customer.email = "test@test.com"
        self.mock_cli.customer.status = "basic"
        
        state = AuthenticatedState(self.mock_cli)
        with patch('builtins.print') as mock_print:
            state.show_menu()
            self.mock_cli.clear_screen.assert_called_once()
            mock_print.assert_any_call("\n=== Main Menu (User: test@test.com) ===")
            mock_print.assert_any_call("Status: basic")

    def test_authenticated_state_logout(self):
        """Test authenticated state logout."""
        state = AuthenticatedState(self.mock_cli)
        state.handle_input("14")
        self.assertIsNone(self.mock_cli.customer)
        self.mock_cli.change_state.assert_called_once()

    def test_authenticated_state_actions(self):
        """Test authenticated state menu actions."""
        state = AuthenticatedState(self.mock_cli)
        
        # Test various menu options
        for choice in range(1, 14):
            state.handle_input(str(choice))
            self.mock_cli.clear_screen.assert_called()
            self.mock_cli.process_main_menu_choice.assert_called_with(str(choice))

    def test_admin_state_menu(self):
        """Test admin state menu display."""
        state = AdminState(self.mock_cli)
        with patch('builtins.print') as mock_print:
            state.show_menu()
            self.mock_cli.clear_screen.assert_called_once()
            mock_print.assert_any_call("\n=== Administrator Panel ===")
            mock_print.assert_any_call("1. View all users")
            mock_print.assert_any_call("2. Delete user")

    @patch('models.customer.Customer.get_all_users')
    def test_admin_state_view_users(self, mock_get_users):
        """Test admin state user listing."""
        mock_user = Mock()
        mock_user.customer_id = 1
        mock_user.first_name = "Test"
        mock_user.last_name = "User"
        mock_user.email = "test@test.com"
        mock_user.status = "basic"
        mock_user.password = "password"
        mock_user.debit_cards = []
        mock_user.credit_cards = []
        
        mock_get_users.return_value = [mock_user]
        
        state = AdminState(self.mock_cli)
        with patch('builtins.print') as mock_print:
            state.handle_input("1")
            mock_print.assert_any_call("\nList of all users:")
            mock_print.assert_any_call("ID: 1")
            mock_print.assert_any_call("Name: Test User")

    @patch('models.customer.Customer.email_exists')
    @patch('models.customer.Customer.load')
    def test_admin_state_delete_user(self, mock_load, mock_exists):
        """Test admin state user deletion."""
        mock_exists.return_value = True
        mock_user = Mock()
        mock_load.return_value = mock_user
        
        state = AdminState(self.mock_cli)
        
        # Test successful deletion
        with patch('builtins.input', side_effect=["test@test.com", "yes"]):
            state.handle_input("2")
            mock_exists.assert_called_with("test@test.com")
            mock_load.assert_called_with("test@test.com")
            mock_user.delete.assert_called_once()
        
        # Test cancelled deletion
        with patch('builtins.input', side_effect=["test@test.com", "no"]):
            state.handle_input("2")
            self.assertEqual(mock_user.delete.call_count, 1)  # Не должно измениться

    def test_admin_state_return(self):
        """Test admin state return to main menu."""
        state = AdminState(self.mock_cli)
        state.handle_input("3")
        self.mock_cli.change_state.assert_called_once()


if __name__ == '__main__':
    unittest.main() 