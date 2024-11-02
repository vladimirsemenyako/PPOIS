#include <gtest/gtest.h>
#include "../Kitchenware/Kitchenware.h"

// Тест конструктора
TEST(KitchenwareTest, ConstructorTest) {
    Kitchenware kitchenware("Frying Pan", 25.0, 20, "Aluminum", true);

    EXPECT_EQ(kitchenware.getName(), "Frying Pan");
    EXPECT_FLOAT_EQ(kitchenware.getPrice(), 25.0);
    EXPECT_EQ(kitchenware.getQuantity(), 20);
    EXPECT_EQ(kitchenware.getMaterial(), "Aluminum");
    EXPECT_TRUE(kitchenware.isDishwasherSafe());
}

// Тест для установки и получения материала
TEST(KitchenwareTest, SetAndGetMaterial) {
    Kitchenware kitchenware("Saucepan", 30.0, 15, "Stainless Steel", false);

    kitchenware.setMaterial("Ceramic");
    EXPECT_EQ(kitchenware.getMaterial(), "Ceramic");
}

// Тест для установки и проверки пригодности для посудомоечной машины
TEST(KitchenwareTest, SetAndIsDishwasherSafe) {
    Kitchenware kitchenware("Knife Set", 50.0, 10, "Carbon Steel", false);

    kitchenware.setDishwasherSafe(true);
    EXPECT_TRUE(kitchenware.isDishwasherSafe());
}

// Тест для отображения информации о кухонной посуде
TEST(KitchenwareTest, DisplayKitchenwareInfoTest) {
    Kitchenware kitchenware("Cutting Board", 15.0, 30, "Bamboo", false);

    testing::internal::CaptureStdout();
    kitchenware.displayKitchenwareInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Material: Bamboo"), std::string::npos);
    EXPECT_NE(output.find("Dishwasher Safe: No"), std::string::npos);
}