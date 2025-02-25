#include <gtest/gtest.h>
#include "../Stationary/Stationary.h"

// Тест конструктора
TEST(StationaryTest, ConstructorTest) {
    Stationary stationary("Notebook", 3.50, 100, "BrandA");

    EXPECT_EQ(stationary.getName(), "Notebook");
    EXPECT_FLOAT_EQ(stationary.getPrice(), 3.50);
    EXPECT_EQ(stationary.getQuantity(), 100);
    EXPECT_EQ(stationary.getCategory(), "Stationary");
    EXPECT_EQ(stationary.getBrand(), "BrandA");
}

// Тест установки и получения бренда
TEST(StationaryTest, SetAndGetBrand) {
    Stationary stationary("Pen", 1.00, 200, "BrandB");

    stationary.setBrand("BrandC");
    EXPECT_EQ(stationary.getBrand(), "BrandC");
}

// Тест отображения информации о канцелярских товарах
TEST(StationaryTest, DisplayStationaryInfo) {
    Stationary stationary("Eraser", 0.75, 50, "BrandD");
    testing::internal::CaptureStdout();
    stationary.displayStationaryInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Stationary Brand: BrandD"), std::string::npos);
}

// Тест отображения информации о продукте
TEST(StationaryTest, DisplayProductInfo) {
    Stationary stationary("Highlighter", 1.50, 150, "BrandE");
    testing::internal::CaptureStdout();
    stationary.displayInfo(); // Предполагается, что метод displayInfo() унаследован от Product
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Product Name: Highlighter"), std::string::npos);
    EXPECT_NE(output.find("Price: $1.5"), std::string::npos);
    EXPECT_NE(output.find("Available Quantity: 150"), std::string::npos);
}