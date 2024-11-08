#include <gtest/gtest.h>
#include "../ATM/ATM.h"
#include <sstream>
#include <iostream>


TEST(ATMTest, ChargeCommission_SufficientFunds) {
    std::string location = "Main Branch";
    ATM atm(1, location, 1000, 200);

    std::ostringstream output;
    std::streambuf* old_buf = std::cout.rdbuf(output.rdbuf());

    atm.chargeCommission();

    EXPECT_EQ(output.str(), "Commission of 200 charged. Remaining balance: 800\n");

    std::cout.rdbuf(old_buf);
}

TEST(ATMTest, ChargeCommission_InsufficientFunds) {
    std::string location = "Main Branch";
    ATM atm(1, location, 100, 200);

    std::ostringstream output;
    std::streambuf* old_buf = std::cout.rdbuf(output.rdbuf());

    atm.chargeCommission();

    EXPECT_EQ(output.str(), "Not enough funds to charge commission. Current balance: 100\n");

    std::cout.rdbuf(old_buf);
}