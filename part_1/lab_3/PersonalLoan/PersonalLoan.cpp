#include "PersonalLoan.h"

float PersonalLoan::calculate_total_repayment() const {
    return loan_amount_ * (1 + interest_rate_);
}
