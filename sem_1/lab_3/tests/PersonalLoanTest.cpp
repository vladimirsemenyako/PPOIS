#include <gtest/gtest.h>
#include "../PersonalLoan/PersonalLoan.h"

TEST(PersonalLoanTest, Initialization) {
    PersonalLoan personalLoan(1, "New York", 101, "John", 1001, 250000.0, 5.0, 36);

    EXPECT_EQ(personalLoan.customer_name(), "John");
    EXPECT_EQ(personalLoan.calculate_total_repayment(), 1500000.0);
    EXPECT_EQ(personalLoan.get_duration_months(), 36);
}

TEST(PersonalLoanTest, SetAndGetDurationMonths) {
    PersonalLoan personalLoan(1, "New York", 101, "John", 1001, 150000.0f, 7.0f, 36);
    personalLoan.set_duration_months(48);

    EXPECT_EQ(personalLoan.get_duration_months(), 48);
}

TEST(PersonalLoanTest, CalculateTotalRepayment) {
    PersonalLoan personalLoan(1, "New York", 101, "John", 1001, 250000.0, 5.0, 36);
    EXPECT_EQ(personalLoan.calculate_total_repayment(), 1500000.0);
}