#include <gtest/gtest.h>
#include "../Minimarket/Minimarket.h"

// Тест конструктора
TEST(MinimarketTest, ConstructorTest) {
    Minimarket market("Local Minimarket");

    EXPECT_EQ(market.getName(), "Local Minimarket");
}

// Тест добавления работника
TEST(MinimarketTest, AddWorker) {
    Minimarket market("Local Minimarket");

    testing::internal::CaptureStdout();
    market.addWorker("Alice");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Worker Alice added."), std::string::npos);
    EXPECT_EQ(market.getWorkers().size(), 1);
    EXPECT_EQ(market.getWorkers()[0], "Alice");
}

// Тест списка работников
TEST(MinimarketTest, ListWorkers) {
    Minimarket market("Local Minimarket");
    market.addWorker("Bob");
    market.addWorker("Charlie");

    testing::internal::CaptureStdout();
    market.listWorkers();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Current workers:"), std::string::npos);
    EXPECT_NE(output.find("- Bob"), std::string::npos);
    EXPECT_NE(output.find("- Charlie"), std::string::npos);
}

// Тест удаления работника
TEST(MinimarketTest, RemoveWorker) {
    Minimarket market("Local Minimarket");
    market.addWorker("David");

    testing::internal::CaptureStdout();
    market.removeWorker("David");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Worker David removed."), std::string::npos);
    EXPECT_EQ(market.getWorkers().size(), 0);

    // Тест на удаление несуществующего работника
    testing::internal::CaptureStdout();
    market.removeWorker("Eve");
    std::string output2 = testing::internal::GetCapturedStdout();

    EXPECT_NE(output2.find("Worker Eve not found."), std::string::npos);
}

// Тест открытия рынка
TEST(MinimarketTest, OpenMarket) {
    Minimarket market("Local Minimarket");

    testing::internal::CaptureStdout();
    market.openMarket();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("The market at Local Minimarket is now open."), std::string::npos);
}

// Тест закрытия рынка
TEST(MinimarketTest, CloseMarket) {
    Minimarket market("Local Minimarket");

    testing::internal::CaptureStdout();
    market.closeMarket();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("The market at Local Minimarket is now closed."), std::string::npos);
}

// Тест установки имени рынка
TEST(MinimarketTest, SetName) {
    Minimarket market("Local Minimarket");
    market.setName("New Minimarket");

    EXPECT_EQ(market.getName(), "New Minimarket");
}