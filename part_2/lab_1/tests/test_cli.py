"""Tests for CLI functionality."""

import unittest
from unittest.mock import Mock, patch
from cli.cli import CLI
from cli.states import InitialState, AuthenticatedState, AdminState


class TestCLI(unittest.TestCase):
    """Test cases for CLI class."""

    def setUp(self):
        """Set up test cases."""
        self.cli = CLI()

    def test_initialization(self):
        """Test CLI initialization."""
        self.assertIsNone(self.cli.customer)
        self.assertIsInstance(self.cli._state, InitialState)

    def test_change_state(self):
        """Test state changing."""
        mock_state = Mock()
        self.cli.change_state(mock_state)
        self.assertEqual(self.cli._state, mock_state)

    @patch('os.system')
    def test_clear_screen(self, mock_system):
        """Test screen clearing."""
        self.cli.clear_screen()
        mock_system.assert_called_once_with('clear')

    def test_start(self):
        """Test CLI start method."""
        mock_state = Mock()
        self.cli._state = mock_state
        
        # Симулируем один цикл и выход
        with patch('builtins.input', side_effect=["4"]):
            with self.assertRaises(SystemExit):
                self.cli.start()
            
            mock_state.show_menu.assert_called_once()
            mock_state.handle_input.assert_called_once_with("4")

    def test_login_process(self):
        """Test login process."""
        with patch('models.customer.Customer.email_exists', return_value=True):
            with patch('models.customer.Customer.load') as mock_load:
                mock_customer = Mock()
                mock_customer.verify_password.return_value = True
                mock_load.return_value = mock_customer
                
                with patch('builtins.input', side_effect=["test@test.com", "password"]):
                    self.cli.login()
                    self.assertEqual(self.cli.customer, mock_customer)

    def test_register_process(self):
        """Test registration process."""
        mock_customer = Mock()
        with patch('models.customer.Customer', return_value=mock_customer):
            self.cli.register()
            mock_customer.set_info.assert_called_once()
            self.assertEqual(self.cli.customer, mock_customer)

    def test_process_main_menu_choice(self):
        """Test main menu choice processing."""
        self.cli.customer = Mock()
        self.cli.customer.pin = Mock()
        
        # Test PIN code creation
        self.cli.customer.pin.has_pin_code.return_value = False
        with patch('builtins.input', return_value="1234"):
            self.cli.process_main_menu_choice("1")
            self.cli.customer.pin.set_pin_code.assert_called_once_with("1234")

        # Test PIN code generation
        self.cli.process_main_menu_choice("2")
        self.cli.customer.pin.generate_pin_code.assert_called_once()

        # Test balance check
        self.cli.customer.debit_cards = [Mock()]
        self.cli.customer.credit_cards = [Mock()]
        self.cli.process_main_menu_choice("3")
        self.cli.customer.debit_cards[0].check_balance.assert_called_once()
        self.cli.customer.credit_cards[0].check_balance.assert_called_once()


if __name__ == '__main__':
    unittest.main() 