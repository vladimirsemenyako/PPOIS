#include "../CheckingAccount/CheckingAccount.h"
#include <gtest/gtest.h>

// Тестируем успешное снятие средств в пределах баланса и лимита овердрафта
TEST(CheckingAccountTest, WithdrawWithinLimit) {
    CheckingAccount account(1, "Main Street", 201, "John Doe", 1001, "Checking", 500.0f, 200.0f);

    ASSERT_TRUE(account.withdraw(600.0f));
    EXPECT_FLOAT_EQ(account.balance(), -100.0f);
}

// Тестируем отказ в снятии средств, превышающем баланс и лимит овердрафта
TEST(CheckingAccountTest, WithdrawExceedingLimit) {
    CheckingAccount account(1, "Main Street", 201, "John Doe", 1001, "Checking", 500.0f, 200.0f);

    ASSERT_FALSE(account.withdraw(800.0f));
    EXPECT_FLOAT_EQ(account.balance(), 500.0f);
}

// Тестируем установку и получение лимита овердрафта
TEST(CheckingAccountTest, SetAndGetOverdraftLimit) {
    CheckingAccount account(1, "Main Street", 201, "John Doe", 1001, "Checking", 500.0f, 200.0f);

    account.set_overdraft_limit(300.0f);
    EXPECT_FLOAT_EQ(account.get_overdraft_limit(), 300.0f);
}

// Тестируем снятие точно до лимита овердрафта
TEST(CheckingAccountTest, WithdrawToExactOverdraftLimit) {
    CheckingAccount account(1, "Main Street", 201, "John Doe", 1001, "Checking", 500.0f, 200.0f);

    ASSERT_TRUE(account.withdraw(700.0f));
    EXPECT_FLOAT_EQ(account.balance(), -200.0f);
}