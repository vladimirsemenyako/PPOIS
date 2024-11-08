#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <utility>
#include <vector>
#include <iostream>
class Branch;
#include "../Branch/Branch.h"


class Customer : public Branch {
public:
    Customer(int branch_id, std::string location, int cust_id, std::string name)
    : Branch(branch_id, location), customer_id(cust_id), customer_name_(name) {}

    int get_costumer_id(){return customer_id;}
    void set_customer_id(int customer_id) {customer_id = customer_id;}
    std::string customer_name() const {return customer_name_;}
    void set_customer_name(const std::string &customer_name) {customer_name_ = customer_name;}
    std::vector<int> accounts_balances() const {return accounts_balances_;}
    void set_accounts_balances(const std::vector<int> &accounts_balances) {accounts_balances_ = accounts_balances;}
    int total_balance() const {return total_balance_;}
    void set_total_balance(int total_balance) {total_balance_ = total_balance;}

    void openAccount(const std::string& accountType);
    void applyForLoan(float amount);
    float checkBalance();
    std::string getCustomerInfo();
    int customer_id;
protected:
    std::string customer_name_;
private:
    std::vector<std::string> account_types_;
    std::vector<int> accounts_balances_;
    int total_balance_;
};

#endif //CUSTOMER_H
