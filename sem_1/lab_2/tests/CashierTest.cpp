#include <gtest/gtest.h>
#include "../Cashier/Cashier.h"

// Тест конструктора
TEST(CashierTest, ConstructorTest) {
    Cashier cashier("Alice", 28, 65.0f, 3, 8);

    EXPECT_EQ(cashier.getName(), "Alice");
    EXPECT_EQ(cashier.getAge(), 28);
    EXPECT_FLOAT_EQ(cashier.getWeight(), 65.0f);
}

// Тесты для метода processSale
TEST(CashierTest, ProcessSaleTest) {
    Cashier cashier("Bob", 30, 70.0f, 1, 8);

    cashier.processSale(50.0f);
    cashier.processSale(30.0f);
    testing::internal::CaptureStdout();
    cashier.endShift();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Total sales for the shift: $80"), std::string::npos);
}

// Тест для метода startShift
TEST(CashierTest, StartShiftTest) {
    Cashier cashier("Carol", 32, 60.0f, 2, 8);

    cashier.processSale(45.0f);
    cashier.startShift();  // Обнуляем total_sales_

    testing::internal::CaptureStdout();
    cashier.endShift();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Total sales for the shift: $0"), std::string::npos);
}

// Тест для метода checkInventory
TEST(CashierTest, CheckInventoryTest) {
    Cashier cashier("Dave", 29, 68.0f, 4, 8);

    testing::internal::CaptureStdout();
    cashier.checkInventory("Apples");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Checking inventory for Apples"), std::string::npos);
}

// Тест для метода getInformation
TEST(CashierTest, GetInformationTest) {
    Cashier cashier("Eve", 25, 55.0f, 5, 6);

    testing::internal::CaptureStdout();
    cashier.getInformation();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Register Number: 5"), std::string::npos);
    EXPECT_NE(output.find("Shift Hours: 6 hours"), std::string::npos);
    EXPECT_NE(output.find("Total Sales: $0"), std::string::npos);
}