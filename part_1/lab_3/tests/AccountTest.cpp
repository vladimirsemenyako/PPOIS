#include <gtest/gtest.h>
#include "../Account/Account.h"

TEST(AccountTest, DepositTest) {
    Account account(1, "New York", 101, "John Doe", 12345, "Saving", 0.0f);
    account.deposit(100.0);
    EXPECT_EQ(account.displayAccountInfo(), "Account Number: 12345\nAccount Type: Saving\nBalance: 100.00\n");
}

TEST(AccountTest, DepositNegativeTest) {
    Account account(1, "New York", 101, "John Doe", 12345, "Saving", 0.0f);
    account.deposit(-50.0);
    EXPECT_EQ(account.displayAccountInfo(), "Account Number: 12345\nAccount Type: Saving\nBalance: 0.00\n");
}

TEST(AccountTest, WithdrawTest) {
    Account account(1, "New York", 101, "John Doe", 12345, "Checking", 200.0f);
    account.withdraw(100.0);
    EXPECT_EQ(account.displayAccountInfo(), "Account Number: 12345\nAccount Type: Checking\nBalance: 100.00\n");
}

TEST(AccountTest, WithdrawInsufficientFundsTest) {
    Account account(1, "New York", 101, "John Doe", 12345, "Checking", 100.0f);
    EXPECT_FALSE(account.withdraw(150.0));
    EXPECT_EQ(account.displayAccountInfo(), "Account Number: 12345\nAccount Type: Checking\nBalance: 100.00\n");
}

TEST(AccountTest, WithdrawExactBalanceTest) {
    Account account(1, "New York", 101, "John Doe", 12345, "Checking", 100.0f);
    EXPECT_TRUE(account.withdraw(100.0));
    EXPECT_EQ(account.displayAccountInfo(), "Account Number: 12345\nAccount Type: Checking\nBalance: 0.00\n");
}