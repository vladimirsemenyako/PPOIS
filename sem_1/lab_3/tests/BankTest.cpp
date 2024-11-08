#include <gtest/gtest.h>
#include "../Bank/Bank.h"

class BankTest : public ::testing::Test {
protected:
    Bank bank;

    BankTest() : bank("MyBank") {}
};

TEST_F(BankTest, TestBankName) {
    EXPECT_EQ(bank.get_bank_name(), "MyBank");
}

TEST_F(BankTest, TestAddBranch) {
    bank.addBranch("Branch 1");
    bank.addBranch("Branch 2");

    std::vector<std::string> expectedBranches = {"Branch 1", "Branch 2"};
    EXPECT_EQ(bank.get_branches(), expectedBranches);
}

TEST_F(BankTest, TestGetBranches) {
    bank.addBranch("Branch 1");
    bank.addBranch("Branch 2");

    std::vector<std::string> branches = bank.get_branches();
    EXPECT_EQ(branches.size(), 2);
    EXPECT_EQ(branches[0], "Branch 1");
    EXPECT_EQ(branches[1], "Branch 2");
}