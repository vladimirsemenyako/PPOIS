#ifndef MORTGAGELOAN_H
#define MORTGAGELOAN_H
#include "../Loan/Loan.h"

class MortgageLoan : public Loan {
public:
    MortgageLoan(int branch_id, std::string location, int cust_id, std::string name, int loan_id, float loan_amount, float interest_rate, std::string property_address)
        : Loan(branch_id, location, cust_id, name, loan_id, loan_amount, interest_rate), property_address_(property_address) {}

    float calculate_total_repayment() const override;
    std::string get_property_address() { return property_address_; };
    void set_property_address(std::string property_address) { property_address_ = property_address; };
private:
    std::string property_address_;
};

#endif //MORTGAGELOAN_H
