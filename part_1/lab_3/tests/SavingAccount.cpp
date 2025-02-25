#include <gtest/gtest.h>
#include "../SavingAccount/SavingAccount.h"

TEST(SavingAccountTest, Initialization) {
    SavingAccount savingAccount(1, "New York", 101, "John", 1001, "Saving", 5000.0f, 1000.0f);

    EXPECT_EQ(savingAccount.customer_name(), "John");
    EXPECT_EQ(savingAccount.balance(), 5000.0f);
    EXPECT_EQ(savingAccount.minimumBalance(), 1000.0f);
}

TEST(SavingAccountTest, DepositValidAmount) {
    SavingAccount savingAccount(1, "New York", 101, "John", 1001, "Saving", 5000.0f, 1000.0f);

    savingAccount.deposit(500.0f);
    EXPECT_EQ(savingAccount.balance(), 5500.0f);
}

TEST(SavingAccountTest, DepositInvalidAmount) {
    SavingAccount savingAccount(1, "New York", 101, "John", 1001, "Saving", 5000.0f, 1000.0f);

    savingAccount.deposit(-100.0f);
    EXPECT_EQ(savingAccount.balance(), 5000.0f); // Balance should remain unchanged
}

TEST(SavingAccountTest, WithdrawValidAmount) {
    SavingAccount savingAccount(1, "New York", 101, "John", 1001, "Saving", 5000.0f, 1000.0f);

    EXPECT_TRUE(savingAccount.withdraw(1000.0f));
    EXPECT_EQ(savingAccount.balance(), 4000.0f);
}

TEST(SavingAccountTest, WithdrawExceedsBalance) {
    SavingAccount savingAccount(1, "New York", 101, "John", 1001, "Saving", 5000.0f, 1000.0f);

    EXPECT_FALSE(savingAccount.withdraw(4500.0f));
    EXPECT_EQ(savingAccount.balance(), 5000.0f); // Balance should remain unchanged
}

TEST(SavingAccountTest, WithdrawBelowMinimumBalance) {
    SavingAccount savingAccount(1, "New York", 101, "John", 1001, "Saving", 2000.0f, 1000.0f);

    EXPECT_FALSE(savingAccount.withdraw(1500.0f));
    EXPECT_EQ(savingAccount.balance(), 2000.0f); // Balance should remain unchanged
}