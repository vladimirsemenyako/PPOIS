#include <gtest/gtest.h>
#include "../Dairy/Dairy.h"

// Тест конструктора
TEST(DairyTest, ConstructorTest) {
    Dairy dairy("Milk", 3.5, 20, "2024-11-10", 3.2f, true);

    EXPECT_EQ(dairy.getName(), "Milk");
    EXPECT_FLOAT_EQ(dairy.getPrice(), 3.5);
    EXPECT_EQ(dairy.getQuantity(), 20);
    EXPECT_EQ(dairy.getExpirationDate(), "2024-11-10");
    EXPECT_FLOAT_EQ(dairy.getFatContent(), 3.2f);
    EXPECT_TRUE(dairy.isRefrigerationRequired());
}

// Тесты для установки и получения содержания жира
TEST(DairyTest, SetAndGetFatContent) {
    Dairy dairy("Cheese", 5.0, 15, "2024-12-01", 10.5f, true);

    dairy.setFatContent(15.0f);
    EXPECT_FLOAT_EQ(dairy.getFatContent(), 15.0f);
}

// Тест для установки и получения необходимости охлаждения
TEST(DairyTest, SetAndGetRefrigerationRequired) {
    Dairy dairy("Butter", 4.0, 10, "2024-12-15", 80.0f, false);

    dairy.setRefrigerationRequired(true);
    EXPECT_TRUE(dairy.isRefrigerationRequired());
}

// Тест для отображения информации о молочном продукте
TEST(DairyTest, DisplayDairyInfoTest) {
    Dairy dairy("Yogurt", 2.5, 25, "2024-11-20", 2.0f, true);

    testing::internal::CaptureStdout();
    dairy.displayDairyInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Fat Content: 2"), std::string::npos);
    EXPECT_NE(output.find("Refrigeration Required: Yes"), std::string::npos);
}