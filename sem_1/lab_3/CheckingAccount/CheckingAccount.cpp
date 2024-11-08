#include "CheckingAccount.h"

bool CheckingAccount::withdraw(float amount) {
    if (balance_ + overdraft_limit_ >= amount) {
        balance_ -= amount;
        std::cout << "Withdrawn: " << amount << " | New balance: " << balance_ << "\n";
        return true;
    }
    std::cout << "Insufficient funds. Max withdrawable amount: " << balance_ + overdraft_limit_ << "\n";
    return false;
}

