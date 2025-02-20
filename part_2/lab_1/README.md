# Banking System

A simple banking system implementation with support for debit and credit cards.

## Features

- User registration and authentication
- PIN code management
- Debit and credit cards support
- Card operations (deposit, withdrawal)
- Card blocking/unblocking
- Basic and premium account status
- Account limits based on status

## Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd banking-system
```

2. Create and activate virtual environment (optional but recommended):
```bash
python -m venv venv
source venv/bin/activate  # On Windows: venv\Scripts\activate
```

3. Install dependencies:
```bash
pip install -r requirements.txt
```

## Usage

Run the program:
```bash
python main.py
```

## Project Structure

- `cli/` - Command-line interface implementation
- `models/` - Core business logic and data models
- `storage/` - Data storage (JSON files)
- `main.py` - Application entry point

## License

MIT License 