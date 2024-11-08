#include <gtest/gtest.h>
#include "../MortgageLoan/MortgageLoan.h"

TEST(MortgageLoanTest, Initialization) {
    MortgageLoan mortgageLoan(1, "New York", 101, "Alice", 1001, 250000.0, 5.0, "123 Main St");

    EXPECT_EQ(mortgageLoan.customer_name(), "Alice");
    EXPECT_EQ(mortgageLoan.calculate_total_repayment(), 1500000.0);
    EXPECT_EQ(mortgageLoan.get_property_address(), "123 Main St");
}

TEST(MortgageLoanTest, SetAndGetPropertyAddress) {
    MortgageLoan mortgageLoan(1, "New York", 101, "Alice", 1001, 250000.0f, 5.0f, "123 Main St");
    mortgageLoan.set_property_address("456 Elm St");

    EXPECT_EQ(mortgageLoan.get_property_address(), "456 Elm St");
}

TEST(MortgageLoanTest, CalculateTotalRepayment) {
    MortgageLoan mortgageLoan(1, "New York", 101, "Alice", 1001, 250000.0, 5.0, "123 Main St");
    EXPECT_EQ(mortgageLoan.calculate_total_repayment(), 1500000.0);
}