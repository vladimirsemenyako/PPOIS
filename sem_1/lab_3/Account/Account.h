#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <sstream>
#include <iomanip>

#include "../Customer/Customer.h"

class Account : public Customer{
public:
    Account(int branch_id, std::string location, int cust_id, std::string name, int account_number, std::string type, float balance) :
    Customer(branch_id, location, cust_id, name), account_number(account_number), account_type_(type), balance_(balance) {} ;

    virtual void deposit(float amount);
    virtual bool withdraw(float amount);
    std::string displayAccountInfo() const;

    int accountNumber() const { return account_number; }
    std::string accountType() const { return account_type_; }
    float balance() const { return balance_; }
    void setBalance(float balance) { balance_ = balance; }
    int account_number;
protected:
    float balance_;
private:

    std::string account_type_;
};

#endif //ACCOUNT_H
