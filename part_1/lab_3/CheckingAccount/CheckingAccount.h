#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "../Account/Account.h"


class CheckingAccount final : public Account{
public:
    CheckingAccount(int branch_id, std::string location, int cust_id, std::string name,
                   int acc_number, std::string account_type, float balance, float overdraft_limit) :
    Account(branch_id, location, cust_id, name, acc_number, "Checking", balance),
      overdraft_limit_(overdraft_limit) {}

    bool withdraw(float amount) override;
    float get_overdraft_limit() { return overdraft_limit_; }
    void set_overdraft_limit(float overdraft_limit) { overdraft_limit_ = overdraft_limit; }
private:
    float overdraft_limit_;
};
#endif //CHECKINGACCOUNT_H
