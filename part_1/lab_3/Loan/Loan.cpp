#include "Loan.h"

float Loan::calculate_total_repayment() const {
    return loan_amount_ * (1 + interest_rate_);
}

void Loan::apply_for_loan(float amount) {
    loan_amount_ = amount;
    remaining_balance_ = amount;
    std::cout << "Loan of amount " << amount << " approved for customer " << customer_name() << ".\n";
}

void Loan::repay_loan(float amount) {
    if (remaining_balance_ >= amount) {
        remaining_balance_ -= amount;
        std::cout << "Repaid: " << amount << " | Remaining balance: " << remaining_balance_ << "\n";
    } else {
        std::cout << "Repayment amount exceeds the remaining loan balance.\n";
    }
}