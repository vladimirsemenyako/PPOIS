#include "ATM.h"

void ATM::chargeCommission() {
    if (atm_amount_ >= commission_) {
        atm_amount_ -= commission_;
        std::cout << "Commission of " << commission_ << " charged. Remaining balance: " << atm_amount_ << std::endl;
    } else {
        std::cout << "Not enough funds to charge commission. Current balance: " << atm_amount_ << std::endl;
    }
}