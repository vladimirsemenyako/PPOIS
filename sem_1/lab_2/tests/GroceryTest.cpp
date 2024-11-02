#include <gtest/gtest.h>
#include "../Grocery/Grocery.h"

// Тест конструктора
TEST(GroceryTest, ConstructorTest) {
    Grocery grocery("Apples", 1.2, 50, "2024-11-05");

    EXPECT_EQ(grocery.getName(), "Apples");
    EXPECT_FLOAT_EQ(grocery.getPrice(), 1.2);
    EXPECT_EQ(grocery.getQuantity(), 50);
    EXPECT_EQ(grocery.getExpirationDate(), "2024-11-05");
}

// Тесты для установки и получения даты истечения срока годности
TEST(GroceryTest, SetAndGetExpirationDate) {
    Grocery grocery("Oranges", 2.3, 30, "2024-11-15");

    grocery.setExpirationDate("2024-12-01");
    EXPECT_EQ(grocery.getExpirationDate(), "2024-12-01");
}

// Тест для проверки срока годности
TEST(GroceryTest, CheckExpirationTest) {
    Grocery grocery("Bananas", 0.8, 25, "2024-11-10");

    testing::internal::CaptureStdout();
    grocery.checkExpiration();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Expiration Date of Bananas: 2024-11-10"), std::string::npos);
}