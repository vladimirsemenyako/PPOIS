#ifndef LOAN_H
#define LOAN_H
#include "../Customer/Customer.h"

class Loan : public Customer{
public:
    Loan(int branch_id, std::string location, int cust_id, std::string name, int loan_id, float loan_amount, float interest_rate)
        : Customer(branch_id, location, cust_id, name), loan_id(loan_id), loan_amount_(loan_amount), interest_rate_(interest_rate) {}

    virtual float calculate_total_repayment() const;
    void apply_for_loan(float amount);
    void repay_loan(float amount);
    int get_loan_id() const { return loan_id; }
    int get_loan_amount() const { return loan_amount_; }
    void set_loan_id(int loan_id) { loan_id = loan_id; }
    void set_loan_amount(int loan_amount) { loan_amount_ = loan_amount; }
    int loan_id;
protected:
    int loan_amount_;
    float interest_rate_;
private:

    float remaining_balance_;
};

#endif //LOAN_H
