#include "../Customer/Customer.h"
#include <gtest/gtest.h>

// Тестируем открытие счёта
TEST(CustomerTest, OpenAccount) {
    Customer customer(1, "Main Street", 101, "Alice");

    customer.openAccount("Savings");
    EXPECT_EQ(customer.accounts_balances().size(), 1);
    EXPECT_EQ(customer.accounts_balances()[0], 0);
    EXPECT_EQ(customer.getCustomerInfo().find("Savings") != std::string::npos, true);
}

// Тестируем подачу заявки на кредит
TEST(CustomerTest, ApplyForLoan) {
    Customer customer(1, "Main Street", 101, "Alice");

    testing::internal::CaptureStdout();
    customer.applyForLoan(5000.0f);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Заявка на кредит в размере 5000") != std::string::npos);
}

// Тестируем получение общего баланса
TEST(CustomerTest, CheckBalance) {
    Customer customer(1, "Main Street", 101, "Alice");

    customer.set_total_balance(1000);
    EXPECT_EQ(customer.checkBalance(), 1000);
}

// Тестируем получение информации о клиенте
TEST(CustomerTest, GetCustomerInfo) {
    Customer customer(1, "Main Street", 101, "Alice");
    customer.set_total_balance(1500);
    customer.openAccount("Savings");
    customer.set_accounts_balances({500, 1000});

    std::string info = customer.getCustomerInfo();
    EXPECT_TRUE(info.find("ID клиента: 101") != std::string::npos);
    EXPECT_TRUE(info.find("Имя: Alice") != std::string::npos);
    EXPECT_TRUE(info.find("Общий баланс: 1500") != std::string::npos);
    EXPECT_TRUE(info.find("Типы счетов: Savings") != std::string::npos);
    EXPECT_TRUE(info.find("Баланс по счетам: 500 1000") != std::string::npos);
}