#include "Customer.h"

void Customer::openAccount(const std::string& accountType) {
    account_types_.push_back(accountType);
    accounts_balances_.push_back(0);  // Изначально баланс нового счёта равен 0
    std::cout << "Счёт типа '" << accountType << "' открыт для клиента " << customer_name_ << ".\n";
}

void Customer::applyForLoan(float amount) {
    std::cout << "Заявка на кредит в размере " << amount << " подана для клиента " << customer_name_ << ".\n";
    // Здесь можно добавить логику для обработки кредита
}

float Customer::checkBalance() {
    return total_balance_;
}

std::string Customer::getCustomerInfo() {
    std::string info = "ID клиента: " + std::to_string(customer_id) + "\n";
    info += "Имя: " + customer_name_ + "\n";
    info += "Общий баланс: " + std::to_string(total_balance_) + "\n";
    info += "Типы счетов: ";
    for (const auto& account : account_types_) {
        info += account + " ";
    }
    info += "\nБаланс по счетам: ";
    for (const auto& balance : accounts_balances_) {
        info += std::to_string(balance) + " ";
    }
    return info;
}