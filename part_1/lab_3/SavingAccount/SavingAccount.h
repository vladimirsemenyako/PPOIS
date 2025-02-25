#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include "../Account/Account.h"



class SavingAccount final : public Account {
public:
    SavingAccount(int branch_id, std::string location, int cust_id, std::string name,
                   int acc_number, std::string account_type, float balance, float min_balance) :
    Account(branch_id, location, cust_id, name, acc_number, "Saving", balance),
      min_balance_(min_balance) {}

    void deposit(float amount) override;
    bool withdraw(float amount) override;
    float minimumBalance() const { return min_balance_; }
    void setMinimumBalance(float min_balance) { min_balance_ = min_balance; }
private:
    float min_balance_;
};

#endif //SAVINGACCOUNT_H
