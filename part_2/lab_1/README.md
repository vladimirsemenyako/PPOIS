# Banking System

A comprehensive banking system implementation with support for debit and credit cards.

## Features

### Account Management
- User registration and authentication
- Basic and premium account statuses
- Status-based limits and privileges
- PIN code management (create, generate, change)

### Card Operations
- Issue debit and credit cards
- View card balances
- Block/unblock cards
- Transaction history
- Card limits based on account status

### Transaction Types
- Deposits
- Withdrawals (with status-based limits)
- Payments (with descriptions)

### Security Features
- PIN code verification for operations
- Card expiration checks
- Card status validation
- Transaction limits

### Account Status Benefits

#### Basic Status
- Up to 2 debit cards
- 1 credit card
- 500 withdrawal limit
- 1000 credit limit

#### Premium Status
- Up to 3 debit cards
- 2 credit cards
- 1000 withdrawal limit
- 2000 credit limit

## Technical Details

### Models

#### Customer
- Manages user account information
- Handles card issuance
- Processes transactions
- Manages account status

#### Bank
- Processes banking operations
- Validates transactions
- Maintains transaction history
- Verifies PIN codes

#### BankCard
- Base card functionality
- Balance tracking
- Card status management
- Expiration validation

#### CreditCard
- Extends BankCard
- Credit limit management
- Available credit tracking

#### PinCode
- PIN management
- PIN verification
- PIN generation

#### Limits
- Status-based restrictions
- Card quantity limits
- Transaction amount limits

### Data Storage
- JSON-based persistence
- User data encryption
- Transaction history

### Security Rules
1. PIN code must be set before issuing any cards
2. All transactions require PIN verification
3. Cards can be locked/unlocked
4. Expired cards cannot perform transactions
5. Transactions are validated against account limits

### Bank Class Methods

#### Transaction Processing
- `verify_pin(card_number, pin)`: Verifies PIN code (always returns True in test environment)
- `process_withdrawal(card, amount, pin)`: Processes withdrawal with validation
- `process_deposit(card, amount)`: Processes deposit with validation
- `process_payment(card, amount, pin, description)`: Processes payment as special withdrawal
- `get_card_transactions(card_number)`: Returns transaction history for card

#### Validation Methods
- `_validate_amount(amount)`: Ensures amount is positive
- `_check_card_status(card)`: Validates card is not locked/expired
- `_add_transaction(card_number, type, amount, description)`: Records transaction

#### Transaction Validation Rules
- Amount must be positive
- Card must not be locked
- Card must not be expired
- PIN must be valid
- Sufficient funds/credit must be available
- Credit limit must not be exceeded for deposits

## API Documentation

### Models

#### Bank Class
- Manages all banking operations and transaction processing
- Methods:
  - `verify_pin(card_number, pin)`: Validates PIN code
  - `process_withdrawal(card, amount, pin)`: Handles withdrawals
  - `process_deposit(card, amount)`: Handles deposits
  - `process_payment(card, amount, pin, description)`: Processes payments
  - `get_card_transactions(card_number)`: Returns transaction history

#### BankCard Class
- Base class for all card types
- Properties:
  - `card_number`: 16-digit unique identifier
  - `cvv_number`: 3-digit security code
  - `exp_date`: Expiration date
  - `balance`: Current balance
  - `is_locked`: Card lock status
- Methods:
  - `set_data()`: Initializes card with random data
  - `is_valid()`: Checks expiration
  - `lock()/unlock()`: Controls card status

#### CreditCard Class
- Extends BankCard with credit functionality
- Additional Properties:
  - `credit_limit`: Maximum credit amount
  - `available_credit`: Current available credit

#### Customer Class
- Manages customer accounts and operations
- Methods:
  - Account Management:
    - `set_info()`: Sets up customer profile
    - `change_status()`: Toggles between basic/premium
    - `verify_password(password)`: Authenticates user
  - Card Operations:
    - `get_credit_card()`: Issues credit card
    - `get_debit_card()`: Issues debit card
  - Transactions:
    - `deposit(card_index, amount)`
    - `withdraw(card_index, amount, pin)`
    - `make_payment(card_index, amount, pin, description)`

#### PinCode Class
- Handles PIN code operations
- Methods:
  - `set_pin_code(new_pin)`: Sets new PIN
  - `change_pin_code(old_pin, new_pin)`: Changes PIN
  - `generate_pin_code()`: Creates random PIN
  - `verify_pin_code(pin)`: Validates PIN

#### Limits Class
- Manages account limits based on status
- Methods:
  - `get_credit_card_limit(status)`
  - `get_debit_card_limit(status)`
  - `get_withdrawal_limit(status)`

### CLI Components

#### CLI Class
- Main interface controller
- States:
  - Initial: Login/Register/Admin
  - Authenticated: Main operations
  - Admin: User management

#### CardOperationsHandler
- Handles all card-related UI operations
- Features:
  - Card listing
  - Balance checking
  - Card issuance
  - Transaction processing

#### PinHandler
- Manages PIN-related UI operations
- Features:
  - PIN creation
  - PIN generation
  - PIN changing

#### States
- Implements state pattern for UI
- States:
  - `InitialState`: Pre-login interface
  - `AuthenticatedState`: Main menu
  - `AdminState`: Administration panel

## Usage

### Running the Application
```bash
python main.py
```

### Running Tests
```bash
python -m unittest discover tests
```

## Project Structure
```
banking-system/
├── cli/
│   ├── __init__.py
│   ├── cli.py
│   ├── card_operations.py
│   ├── pin_handler.py
│   └── states.py
├── models/
│   ├── __init__.py
│   ├── bank.py
│   ├── bank_card.py
│   ├── credit_card.py
│   ├── customer.py
│   ├── limits.py
│   └── pin_code.py
├── tests/
│   ├── __init__.py
│   ├── test_bank.py
│   ├── test_bank_card.py
│   ├── test_customer.py
│   ├── test_limits.py
│   └── test_pin_code.py
├── storage/
│   └── users.json
├── main.py
└── README.md
```

## Error Handling
- Invalid PIN codes
- Insufficient funds
- Card limits exceeded
- Invalid transaction amounts
- Expired cards
- Locked cards
- Non-Latin character support

## Development Guidelines
- All operations must be validated
- Transactions must be atomic
- Changes must be persisted
- Error messages must be user-friendly
- Input validation must be thorough

