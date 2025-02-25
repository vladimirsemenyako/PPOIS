#ifndef BRANCH_H
#define BRANCH_H
#include <string>
#include <vector>
#include <iostream>

class Employee;
class Customer;
class Account;
class Loan;
class ATM;


class Branch {
public:
    Branch(int branch_id, std::string location)
        : branch_id(branch_id), location(location), totalCashOnHand(0.0f) {}

    // Add methods
    void addEmployee(Employee* employee);
    void addCustomer(Customer* customer);
    void addAccount(Account* account);
    void addLoan(Loan* loan);
    void addATM(ATM* atm);
    int calculateTotalCashOnHand();
    void displayBranchInfo() const;

    // Getters
    std::vector<Employee*> getEmployees() { return employees_; }
    std::vector<Customer*> getCustomers() { return customers_; }
    std::vector<Account*> getAccounts() { return accounts_; }
    std::vector<Loan*> getLoans() { return loan_portfolio_; }
    std::vector<ATM*> getATMs() { return atm_list_; }

protected:
    int branch_id;
    std::string location;
    float totalCashOnHand;

private:
    std::vector<Employee*> employees_;
    std::vector<Customer*> customers_;
    std::vector<Account*> accounts_;
    std::vector<Loan*> loan_portfolio_;
    std::vector<ATM*> atm_list_;
};

#endif //BRANCH_H