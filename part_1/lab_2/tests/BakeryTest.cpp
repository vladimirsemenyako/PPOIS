#include <gtest/gtest.h>
#include "../Bakery/Bakery.h"
// Тесты конструктора
TEST(BakeryTest, ConstructorTest) {
    Bakery bakery("Bread", 3.5, 10, "2024-12-31", "Loaf", true);

    EXPECT_EQ(bakery.getName(), "Bread");
    EXPECT_FLOAT_EQ(bakery.getPrice(), 3.5);
    EXPECT_EQ(bakery.getQuantity(), 10);
    EXPECT_EQ(bakery.getExpirationDate(), "2024-12-31");
    EXPECT_EQ(bakery.getBakeryType(), "Loaf");
    EXPECT_TRUE(bakery.isGlutenFree());
}

// Тесты для установки и получения типа выпечки
TEST(BakeryTest, SetAndGetBakeryType) {
    Bakery bakery("Croissant", 2.0, 5, "2024-11-01", "Pastry", false);

    bakery.setBakeryType("Bagel");
    EXPECT_EQ(bakery.getBakeryType(), "Bagel");
}

// Тесты для установки и получения статуса безглютеновости
TEST(BakeryTest, SetAndGetGlutenFreeStatus) {
    Bakery bakery("Cookie", 1.5, 20, "2024-12-10", "Sweet", false);

    bakery.setGlutenFree(true);
    EXPECT_TRUE(bakery.isGlutenFree());

    bakery.setGlutenFree(false);
    EXPECT_FALSE(bakery.isGlutenFree());
}

// Тесты для вывода информации о продукте
TEST(BakeryTest, DisplayBakeryInfoTest) {
    Bakery bakery("Muffin", 2.5, 15, "2024-11-25", "Cake", false);

    testing::internal::CaptureStdout();
    bakery.displayBakeryInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Bakery Type: Cake"), std::string::npos);
    EXPECT_NE(output.find("Contains Gluten: Yes"), std::string::npos);
}