#include <gtest/gtest.h>
#include "../Canned/Canned.h"

// Тесты конструктора
TEST(CannedTest, ConstructorTest) {
    Canned canned("Tomato Soup", 1.99, 30, "2025-05-15", "Heat-treated", true);

    EXPECT_EQ(canned.getName(), "Tomato Soup");
    EXPECT_FLOAT_EQ(canned.getPrice(), 1.99);
    EXPECT_EQ(canned.getQuantity(), 30);
    EXPECT_EQ(canned.getExpirationDate(), "2025-05-15");
    EXPECT_EQ(canned.getPreservationType(), "Heat-treated");
    EXPECT_TRUE(canned.isRecyclable());
}

// Тесты для установки и получения типа консервирования
TEST(CannedTest, SetAndGetPreservationType) {
    Canned canned("Peas", 1.5, 50, "2025-02-01", "Pickled", false);

    canned.setPreservationType("Canned");
    EXPECT_EQ(canned.getPreservationType(), "Canned");
}

// Тесты для установки и получения статуса перерабатываемости
TEST(CannedTest, SetAndGetRecyclableStatus) {
    Canned canned("Corn", 2.0, 40, "2025-03-20", "Vacuum-sealed", false);

    canned.setRecyclable(true);
    EXPECT_TRUE(canned.isRecyclable());

    canned.setRecyclable(false);
    EXPECT_FALSE(canned.isRecyclable());
}

// Тесты для вывода информации о продукте
TEST(CannedTest, DisplayCannedInfoTest) {
    Canned canned("Beans", 1.75, 20, "2025-04-10", "Boiled", true);

    testing::internal::CaptureStdout();
    canned.displayCannedInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Preservation Type: Boiled"), std::string::npos);
    EXPECT_NE(output.find("Recyclable Packaging: Yes"), std::string::npos);
}
