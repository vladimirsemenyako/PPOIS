
#include "Account.h"

void Account::deposit(float amount) {
    if (amount < 0.0) {
        std::cout << "Deposit must be positive." << std::endl;
    }
    else {
        balance_ += amount;
        std::cout << "Deposit " << amount << std::endl;
    }
}

bool Account::withdraw(float amount) {
    if (amount > 0 && amount <= balance_) {
        balance_ -= amount;
        std::cout << "Withdraw " << amount << std::endl;
        std::cout << "Your new balance is " << balance_ << std::endl;
        return true;
    }
    else {
        std::cout << "Your amount is so big. Please check your balance" << std::endl;
        return false;
    }
}

std::string Account::displayAccountInfo() const {
    std::ostringstream info;
    info << "Account Number: " << account_number << "\n"
         << "Account Type: " << account_type_ << "\n"
         << "Balance: " << std::fixed << std::setprecision(2) << balance_ << "\n";
    return info.str();
}



