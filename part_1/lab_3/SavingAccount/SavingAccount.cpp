#include "SavingAccount.h"

void SavingAccount::deposit(float amount) {
    if (amount > 0) {
        balance_ += amount;
        std::cout << "The account has been replenished with the amount:" << std::fixed << std::setprecision(2) << amount << "\n";
        if (balance_ < min_balance_) {
            std::cout << "Alert: Balance is lower than his minimum value.\n";
        }
    } else {
        std::cout << "The deposit amount must be positive.\n";
    }
}

bool SavingAccount::withdraw(float amount) {
    if (amount > 0 && balance_ - amount >= min_balance_) {
        balance_ -= amount;
        std::cout << "From account was taken amount: " << std::fixed << std::setprecision(2) << amount << "\n";
        return true;
    } else {
        std::cout << "Impossible to withdraw money: balance can't be lower than minimum one.\n";
        return false;
    }
}

