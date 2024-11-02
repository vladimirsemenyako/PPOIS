#include <gtest/gtest.h>
#include "../Manager/Manager.h"

// Тест конструктора
TEST(ManagerTest, ConstructorTest) {
    Manager manager("Alice", 30, 70.0, "General Manager", 10000.0);
    
    EXPECT_EQ(manager.getName(), "Alice");
    EXPECT_EQ(manager.getAge(), 30);
    EXPECT_FLOAT_EQ(manager.getWeight(), 70.0);
    EXPECT_EQ(manager.getPosition(), "General Manager");
    EXPECT_FLOAT_EQ(manager.getBudget(), 10000.0);
}

// Тест планирования смены
TEST(ManagerTest, ScheduleShift) {
    Manager manager("Bob", 40, 80.0, "Shift Manager", 5000.0);
    
    testing::internal::CaptureStdout();
    manager.scheduleShift("Charlie", "9 AM - 5 PM");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Scheduling shift for Charlie at 9 AM - 5 PM."), std::string::npos);
}

// Тест обзора производительности
TEST(ManagerTest, ReviewPerformance) {
    Manager manager("David", 35, 75.0, "Team Leader", 3000.0);
    
    testing::internal::CaptureStdout();
    manager.reviewPerformance("Eve", 4);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Reviewing performance for Eve. Rating: 4/5."), std::string::npos);
}

// Тест одобрения бюджета
TEST(ManagerTest, ApproveBudget) {
    Manager manager("Fiona", 45, 65.0, "Finance Manager", 1000.0);
    
    testing::internal::CaptureStdout();
    manager.approveBudget(500.0);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Budget approved: $500. Remaining budget: $500."), std::string::npos);

    // Тест на недостаток бюджета
    testing::internal::CaptureStdout();
    manager.approveBudget(600.0);
    std::string output2 = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output2.find("Insufficient budget to approve $600. Current budget: $500."), std::string::npos);
}

// Тест генерации отчета
TEST(ManagerTest, GenerateReport) {
    Manager manager("George", 50, 90.0, "Project Manager", 2000.0);
    
    testing::internal::CaptureStdout();
    manager.generateReport();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Generating report..."), std::string::npos);
    EXPECT_NE(output.find("Report generated by George"), std::string::npos);
}

// Тест обработки жалобы
TEST(ManagerTest, HandleComplaint) {
    Manager manager("Hannah", 28, 55.0, "HR Manager", 1500.0);
    
    testing::internal::CaptureStdout();
    manager.handleComplaint("Employee is late.");
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Handling complaint: Employee is late."), std::string::npos);
}