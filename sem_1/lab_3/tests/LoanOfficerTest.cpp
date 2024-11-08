#include <gtest/gtest.h>
#include "../LoanOfficer/LoanOfficer.h"

TEST(LoanOfficerTest, Initialization) {
    LoanOfficer officer(1, "New York", 101, "Alice", 60000.0f);

    EXPECT_EQ(officer.getEmpName(), "Alice");
    EXPECT_EQ(officer.getSalary(), 60000.0f);
}

TEST(LoanOfficerTest, AddClient) {
    LoanOfficer officer(1, "New York", 101, "Alice", 60000.0f);
    officer.addClient("John Doe");

    const auto& clients = officer.getClients();
    EXPECT_EQ(clients.size(), 1);
    EXPECT_EQ(clients[0], "John Doe");
}

TEST(LoanOfficerTest, GenerateReport) {
    LoanOfficer officer(1, "New York", 101, "Alice", 60000.0f);
    officer.addClient("John Doe");

    std::string report = officer.generateReport();
    EXPECT_NE(report.find("Loan Officer Report:"), std::string::npos);
    EXPECT_NE(report.find("Pending Loans: 0"), std::string::npos);
    EXPECT_NE(report.find("Approved Loans: 0"), std::string::npos);
    EXPECT_NE(report.find("Rejected Loans: 0"), std::string::npos);
}

TEST(LoanOfficerTest, CheckLoanStatus) {
    LoanOfficer officer(1, "New York", 101, "Alice", 60000.0f);
    officer.addClient("John Doe");

    officer.checkLoanStatus(1001);
    EXPECT_EQ(officer.getPendingLoansCount(), 0);
}

TEST(LoanOfficerTest, CheckLoanStatusWithNoPendingLoans) {
    LoanOfficer officer(1, "New York", 101, "Alice", 60000.0f);

    bool result = officer.checkLoanStatus(1001);
    EXPECT_FALSE(result);
}