#include "LoanOfficer.h"

void LoanOfficer::addClient(const std::string &client) {
    clients_.push_back(client);
}

std::string LoanOfficer::generateReport() {
    std::string report = "Loan Officer Report:\n";
    report += "Pending Loans: " + std::to_string(pendingLoans_.size()) + "\n";
    report += "Approved Loans: " + std::to_string(approvedLoans_.size()) + "\n";
    report += "Rejected Loans: " + std::to_string(rejectedLoans_.size()) + "\n";
    return report;
}

int LoanOfficer::getPendingLoansCount() const {
    return pendingLoans_.size();
}

const std::vector<std::string> &LoanOfficer::getClients() const {
    return clients_;
}

bool LoanOfficer::checkLoanStatus(int loanID) {
    auto it = std::find(pendingLoans_.begin(), pendingLoans_.end(), loanID);
    if (it != pendingLoans_.end()) {
        rejectedLoans_.push_back(loanID);
        pendingLoans_.erase(it);
        return true;
    }
    return false;
}





