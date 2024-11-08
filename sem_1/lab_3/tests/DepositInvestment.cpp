#include "../DepositInvestment/DepositInvestment.h"
#include <gtest/gtest.h>

TEST(DepositInvestmentTest, InitialDeposit) {
    DepositInvestment investment(1, "Main Street", 101, "Alice", 1001, "Deposit", 5000.0f, 0.05f, "2024-01-01", 1000.0f, 0.03f);

    EXPECT_EQ(investment.get_initial_deposit(), 1000.0f);

    investment.set_initial_deposit(2000.0f);
    EXPECT_EQ(investment.get_initial_deposit(), 2000.0f);
}

TEST(DepositInvestmentTest, InterestRate) {
    DepositInvestment investment(1, "Main Street", 101, "Alice", 1001, "Deposit", 5000.0f, 0.05f, "2024-01-01", 1000.0f, 0.03f);

    EXPECT_EQ(investment.get_interest_rate(), 0.03f);

    investment.set_interest_rate(0.04f);
    EXPECT_EQ(investment.get_interest_rate(), 0.04f);
}//
// Created by Владимир on 07.11.2024.
//
