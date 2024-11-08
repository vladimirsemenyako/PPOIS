#ifndef ATM_H
#define ATM_H
#include <iostream>
#include "../Branch/Branch.h"
#include <utility>

class ATM : public Branch {
public:
    ATM(int branch_id, std::string location, int atm_amount, int commission)
        : Branch(branch_id, location), atm_amount_(atm_amount), commission_(commission) {}

    int atm_amount() const { return atm_amount_; }
    void set_atm_amount(int atm_amount) { atm_amount_ = atm_amount; }

    int commission() const { return commission_; }
    void set_commission(int commission) { commission_ = commission; }

    void chargeCommission();

    int atm_id;

private:
    int atm_amount_;
    int commission_;
};

#endif //ATM_H
