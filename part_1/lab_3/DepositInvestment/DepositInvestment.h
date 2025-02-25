#ifndef DEPOSITINVESTMENT_H
#define DEPOSITINVESTMENT_H
#include "../Investment/Investment.h"

class DepositInvestment : public Investment{
public:
    DepositInvestment(int branch_id, std::string location, int cust_id, std::string name, int investment_id, std::string investment_type, float initial_amount,
               float return_rate, std::string start_date, float initial_deposit, float interest_rate)
                   : Investment(branch_id, location, cust_id, name, investment_id, investment_type, initial_amount, return_rate, start_date), initial_deposit_(initial_deposit), interest_rate_(interest_rate){};

    float get_initial_deposit();

    void set_initial_deposit(float initial_deposit);

    float get_interest_rate();

    void set_interest_rate(float interest_rate);
private:
    float initial_deposit_;
    float interest_rate_;
};

#endif //DEPOSITINVESTMENT_H
