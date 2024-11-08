#include "DepositInvestment.h"

float DepositInvestment::get_initial_deposit() {
    return initial_deposit_;
}

void DepositInvestment::set_initial_deposit(float initial_deposit) {
    initial_deposit_ = initial_deposit;
}

float DepositInvestment::get_interest_rate() {
    return interest_rate_;
}

void DepositInvestment::set_interest_rate(float interest_rate) {
    interest_rate_ = interest_rate;
}

