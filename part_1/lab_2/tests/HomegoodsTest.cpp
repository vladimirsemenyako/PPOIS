#include <gtest/gtest.h>
#include "../Homegoods/Homegoods.h"

// Тест конструктора
TEST(HomegoodsTest, ConstructorTest) {
    Homegoods homegoods("Chair", 45.0, 10, "Wood");

    EXPECT_EQ(homegoods.getName(), "Chair");
    EXPECT_FLOAT_EQ(homegoods.getPrice(), 45.0);
    EXPECT_EQ(homegoods.getQuantity(), 10);
    EXPECT_EQ(homegoods.getMaterial(), "Wood");
}

// Тесты для установки и получения материала
TEST(HomegoodsTest, SetAndGetMaterial) {
    Homegoods homegoods("Table", 80.0, 5, "Metal");

    homegoods.setMaterial("Plastic");
    EXPECT_EQ(homegoods.getMaterial(), "Plastic");
}

// Тест для отображения информации о товаре
TEST(HomegoodsTest, DisplayHomegoodInfoTest) {
    Homegoods homegoods("Lamp", 20.0, 15, "Glass");

    testing::internal::CaptureStdout();
    homegoods.displayHomegoodInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Homegoods Material: Glass"), std::string::npos);
}