#include <gtest/gtest.h>
#include "../StockInvestment/StockInvestment.h"

TEST(StockInvestmentTest, Initialization) {
    StockInvestment stockInvestment(1, "New York", 101, "John", 1001, "Stock", 5000.0f, 0.05f, "2024-01-01", 100);

    EXPECT_EQ(stockInvestment.customer_name(), "John");
    EXPECT_EQ(stockInvestment.initial_amount(), 5000.0f);
    EXPECT_EQ(stockInvestment.get_stock_price(), 100);
}

TEST(StockInvestmentTest, SetStockPrice) {
    StockInvestment stockInvestment(1, "New York", 101, "John", 1001, "Stock", 5000.0f, 0.05f, "2024-01-01", 100);

    stockInvestment.set_stock_price(120);
    EXPECT_EQ(stockInvestment.get_stock_price(), 120);
}

TEST(StockInvestmentTest, GetStockPrice) {
    StockInvestment stockInvestment(1, "New York", 101, "John", 1001, "Stock", 5000.0f, 0.05f, "2024-01-01", 100);

    EXPECT_EQ(stockInvestment.get_stock_price(), 100);
}