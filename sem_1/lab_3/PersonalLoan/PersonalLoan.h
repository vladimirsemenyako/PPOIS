#ifndef PERSONALLOAN_H
#define PERSONALLOAN_H
#include "../Loan/Loan.h"

class PersonalLoan : public Loan{
public:
    PersonalLoan(int branch_id, std::string location, int cust_id, std::string name, int loan_id, float loan_amount, float interest_rate, int duration_months)
        : Loan(branch_id, location, cust_id, name, loan_id, loan_amount, interest_rate), duration_months_(duration_months) {}

    int get_duration_months() const { return duration_months_; }
    void set_duration_months(int new_duration_months) { duration_months_ = new_duration_months; }
    float calculate_total_repayment() const override;

private:
    int duration_months_;
};

#endif //PERSONALLOAN_H
