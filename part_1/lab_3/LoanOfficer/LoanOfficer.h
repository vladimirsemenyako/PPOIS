#ifndef LOANOFFICER_H
#define LOANOFFICER_H
#include "../Employee/Employee.h"

class LoanOfficer final : public Employee {
public:
    LoanOfficer(int branchId, const std::string& branchLocation, int id, const std::string& name, float salary)
        : Employee(branchId, branchLocation, id, name, "Loan Officer", salary) {}

    bool checkLoanStatus(int loanID);
    void addClient(const std::string& client);
    std::string generateReport();
    int getPendingLoansCount() const;
    const std::vector<std::string>& getClients() const;

private:
    std::vector<std::string> clients_;
    std::vector<int> pendingLoans_;
    std::vector<int> approvedLoans_;
    std::vector<int> rejectedLoans_;
};

#endif //LOANOFFICER_H
