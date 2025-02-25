#include <gtest/gtest.h>
#include "../Loan/Loan.h"

TEST(LoanTest, Initialization) {
    Loan loan(1, "New York", 101, "John Doe", 1001, 5000, 0.05f);

    EXPECT_EQ(loan.get_loan_amount(), 5000);
    EXPECT_EQ(loan.loan_id, 1001);
    EXPECT_EQ(loan.calculate_total_repayment(), 5250);
}

TEST(LoanTest, ApplyForLoan) {
    Loan loan(1, "New York", 101, "John Doe", 1001, 5000, 0.05f);

    loan.apply_for_loan(10000);
    EXPECT_EQ(loan.get_loan_amount(), 10000);
}

TEST(LoanTest, RepayLoan) {
    Loan loan(1, "New York", 101, "John Doe", 1001, 5000, 0.05f);
    loan.apply_for_loan(10000);

    loan.repay_loan(2000);
    EXPECT_EQ(loan.get_loan_amount(), 10000);
}

TEST(LoanTest, RepayLoanExceedsBalance) {
    Loan loan(1, "New York", 101, "John Doe", 1001, 5000, 0.05f);
    loan.apply_for_loan(10000);

    loan.repay_loan(11000);
    EXPECT_EQ(loan.get_loan_amount(), 10000);
}