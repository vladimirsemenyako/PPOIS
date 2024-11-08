#ifndef INVESTMENT_H
#define INVESTMENT_H
#include "../Customer/Customer.h"

class Investment : public Customer {
public:
    Investment(int branch_id, std::string location, int cust_id, std::string name, int investment_id, std::string investment_type, float initial_amount,
               float return_rate, std::string start_date)
                   : Customer(branch_id, location, cust_id, name), investment_id_(investment_id),
                              investment_type_(investment_type), initial_amount_(initial_amount), return_rate_(return_rate), start_date_(start_date) {}

    int investment_id() const { return investment_id_; }
    void set_investment_id(int investment_id) { investment_id_ = investment_id; }

    std::string investment_type() const { return investment_type_; }
    void set_investment_type(const std::string &type) { investment_type_ = type; }

    float initial_amount() const { return initial_amount_; }
    void set_initial_amount(float amount) { initial_amount_ = amount; }

    float return_rate() const { return return_rate_; }
    void set_return_rate(float rate) { return_rate_ = rate; }

    std::string start_date() const { return start_date_; }
    void set_start_date(const std::string &date) { start_date_ = date; }

    void addInvestment(float amount);
    virtual float calculate_return() const;
    void displayInvestmentInfo() const;

private:
    int investment_id_;
    std::string investment_type_;
    float initial_amount_;
    float return_rate_;
    std::string start_date_;
};

#endif //INVESTMENT_H
