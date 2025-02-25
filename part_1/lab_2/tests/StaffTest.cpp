#include <gtest/gtest.h>
#include "../Staff/Staff.h"

// Тест конструктора
TEST(StaffTest, ConstructorTest) {
    Staff staff("John Doe", 30, 75.0, "Cashier");

    EXPECT_EQ(staff.getName(), "John Doe");
    EXPECT_EQ(staff.getAge(), 30);
    EXPECT_FLOAT_EQ(staff.getWeight(), 75.0);
    EXPECT_EQ(staff.getPosition(), "Cashier");
}

// Тест получения информации о сотруднике
TEST(StaffTest, GetInformation) {
    Staff staff("Jane Smith", 28, 65.0,"Manager");
    testing::internal::CaptureStdout();
    staff.getInformation();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Jane Smith"), std::string::npos);
    EXPECT_NE(output.find("Position: Manager"), std::string::npos);
}

// Тест сообщения о проблеме
TEST(StaffTest, ReportIssue) {
    Staff staff("Alice", 32, 70.0, "Sales Associate");
    testing::internal::CaptureStdout();
    staff.reportIssue("Register is malfunctioning.");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Alice reported an issue: Register is malfunctioning."), std::string::npos);
}

// Тест помощи клиенту
TEST(StaffTest, AssistCustomer) {
    Staff staff("Bob", 25, 80.0, "Customer Service");
    testing::internal::CaptureStdout();
    staff.assistCustomer("Need help finding a product.");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Bob is assisting a customer with request: Need help finding a product."), std::string::npos);
}

// Тест обновления расписания смен
TEST(StaffTest, UpdateShiftSchedule) {
    Staff staff("Eve", 29, 65.0, "Stock Clerk");
    testing::internal::CaptureStdout();
    staff.updateShiftSchedule("Monday 9 AM - 5 PM");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Updated shift schedule for Eve: Monday 9 AM - 5 PM"), std::string::npos);
}

// Тест получения позиции
TEST(StaffTest, GetPosition) {
    Staff staff("Charlie", 35, 90.0, "Supervisor");
    EXPECT_EQ(staff.getPosition(), "Supervisor");
}