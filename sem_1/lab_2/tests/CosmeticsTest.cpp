#include <gtest/gtest.h>
#include "../Cosmetics/Cosmetics.h"

// Тест конструктора
TEST(CosmeticsTest, ConstructorTest) {
    Cosmetics cosmetic("Moisturizer", 20.99, 10, "Dry");

    EXPECT_EQ(cosmetic.getName(), "Moisturizer");
    EXPECT_FLOAT_EQ(cosmetic.getPrice(), 20.99);
    EXPECT_EQ(cosmetic.getQuantity(), 10);
    EXPECT_EQ(cosmetic.getSkinType(), "Dry");
}

// Тесты для установки и получения типа кожи
TEST(CosmeticsTest, SetAndGetSkinType) {
    Cosmetics cosmetic("Face Wash", 15.5, 5, "Oily");

    cosmetic.setSkinType("Sensitive");
    EXPECT_EQ(cosmetic.getSkinType(), "Sensitive");
}

// Тест для отображения информации о косметике
TEST(CosmeticsTest, DisplayCosmeticInfoTest) {
    Cosmetics cosmetic("Sunscreen", 12.75, 15, "All");

    testing::internal::CaptureStdout();
    cosmetic.displayCosmeticInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Cosmetic Product for Skin Type: All"), std::string::npos);
}