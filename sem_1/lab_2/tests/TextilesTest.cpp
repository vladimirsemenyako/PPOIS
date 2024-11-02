#include <gtest/gtest.h>
#include "../Textiles/Textiles.h"

// Тест конструктора
TEST(TextilesTest, ConstructorTest) {
    Textiles textile("Towel", 15.00, 50, "Cotton", "Medium", true);

    EXPECT_EQ(textile.getName(), "Towel");
    EXPECT_FLOAT_EQ(textile.getPrice(), 15.00);
    EXPECT_EQ(textile.getQuantity(), 50);
    EXPECT_EQ(textile.getMaterial(), "Cotton");
    EXPECT_EQ(textile.getSize(), "Medium");
    EXPECT_TRUE(textile.isMachineWashable());
}

// Тест установки и получения материала
TEST(TextilesTest, SetAndGetMaterial) {
    Textiles textile("Sheet", 30.00, 20, "Linen", "Queen", false);

    textile.setMaterial("Cotton");
    EXPECT_EQ(textile.getMaterial(), "Cotton");
}

// Тест установки и получения размера
TEST(TextilesTest, SetAndGetSize) {
    Textiles textile("Curtain", 25.00, 15, "Polyester", "Long", true);

    textile.setSize("Short");
    EXPECT_EQ(textile.getSize(), "Short");
}

// Тест установки и проверки возможности машинной стирки
TEST(TextilesTest, SetAndIsMachineWashable) {
    Textiles textile("Blanket", 40.00, 10, "Wool", "Large", false);

    textile.setMachineWashable(true);
    EXPECT_TRUE(textile.isMachineWashable());
}

// Тест для отображения информации о текстиле
TEST(TextilesTest, DisplayTextileInfo) {
    Textiles textile("Pillow", 20.00, 25, "Memory Foam", "Standard", true);
    testing::internal::CaptureStdout();
    textile.displayTextileInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Material: Memory Foam"), std::string::npos);
    EXPECT_NE(output.find("Size: Standard"), std::string::npos);
    EXPECT_NE(output.find("Machine Washable: Yes"), std::string::npos);
}