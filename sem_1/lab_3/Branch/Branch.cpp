#include "Branch.h"
void Branch::addEmployee(Employee* employee) {
    employees_.push_back(employee);
}

void Branch::addCustomer(Customer* customer) {
    customers_.push_back(customer);
}

void Branch::addAccount(Account* account) {
    accounts_.push_back(account);
}

void Branch::addLoan(Loan* loan) {
    loan_portfolio_.push_back(loan);
}


void Branch::addATM(ATM* atm) {
    atm_list_.push_back(atm);
}

void Branch::displayBranchInfo() const {
    std::cout << "Branch ID: " << branch_id << ", Location: " << location << std::endl;
}

int Branch::calculateTotalCashOnHand() {
    return totalCashOnHand * 12;
}

