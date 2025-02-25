#include <gtest/gtest.h>
#include "../Investment/Investment.h"

// Тест для конструктора и методов класса Investment
TEST(InvestmentTest, Initialization) {
    Investment inv(1, "New York", 101, "John Doe", 1001, "Deposit", 1000.0f, 5.0f, "2024-01-01");

    // Проверка начальной суммы инвестиции
    EXPECT_EQ(inv.initial_amount(), 1000.0f);

    // Проверка типа инвестиции
    EXPECT_EQ(inv.investment_type(), "Deposit");

    // Проверка ставки доходности
    EXPECT_EQ(inv.return_rate(), 5.0f);

    // Проверка даты начала
    EXPECT_EQ(inv.start_date(), "2024-01-01");
}

TEST(InvestmentTest, AddInvestment) {
    Investment inv(1, "New York", 101, "John Doe", 1001, "Deposit", 1000.0f, 5.0f, "2024-01-01");

    // Добавление инвестиции
    inv.addInvestment(500.0f);

    // Проверка новой суммы
    EXPECT_EQ(inv.initial_amount(), 1500.0f);
}


TEST(InvestmentTest, CalculateReturn) {
    Investment inv(1, "New York", 101, "John Doe", 1001, "Deposit", 1000.0f, 5.0f, "2024-01-01");

    // Проверка расчета дохода
    EXPECT_EQ(inv.calculate_return(), 50.0f);  // 5% от 1000 = 50
}

TEST(InvestmentTest, DisplayInvestmentInfo) {
    Investment inv(1, "New York", 101, "John Doe", 1001, "Deposit", 1000.0, 5.0, "2024-01-01");

    // Проверка вывода информации о инвестиции
    std::stringstream output;
    std::streambuf* old_buf = std::cout.rdbuf(output.rdbuf()); // Перехват вывода в строковый поток

    inv.displayInvestmentInfo();

    std::cout.rdbuf(old_buf); // Возвращаем стандартный вывод

    std::string expected_output = "Investment ID: 1001\nType: Deposit\nInitial Amount: 1000\nReturn Rate: 5%\nStart Date: 2024-01-01\n";
    EXPECT_EQ(output.str(), expected_output);
}
