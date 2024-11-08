#include "MortgageLoan.h"


float MortgageLoan::calculate_total_repayment() const {
    return loan_amount_ * (1 + interest_rate_);
}