#include <gtest/gtest.h>
#include "../Manager/Manager.h"

TEST(ManagerTest, Initialization) {
    Manager manager(1, "New York", 101, "Alice", 70000.0f);

    EXPECT_EQ(manager.getEmpName(), "Alice");
    EXPECT_EQ(manager.getSalary(), 70000.0f);
}

TEST(ManagerTest, AddEmployee) {
    Manager manager(1, "New York", 101, "Alice", 70000.0f);
    manager.addEmployee(102);

    const auto& employees = manager.managed_employees;
    EXPECT_EQ(employees.size(), 1);
    EXPECT_EQ(employees[0], 102);
}

TEST(ManagerTest, RemoveEmployee) {
    Manager manager(1, "New York", 101, "Alice", 70000.0f);
    manager.addEmployee(102);

    bool result = manager.removeEmployee(102);
    EXPECT_TRUE(result);
    EXPECT_EQ(manager.managed_employees.size(), 0);
}

TEST(ManagerTest, RemoveNonExistentEmployee) {
    Manager manager(1, "New York", 101, "Alice", 70000.0f);
    manager.addEmployee(102);

    bool result = manager.removeEmployee(999);
    EXPECT_FALSE(result);
}

TEST(ManagerTest, GenerateBranchReport) {
    Manager manager(1, "New York", 101, "Alice", 70000.0f);
    manager.addEmployee(102);
    manager.setMonthlyGoal("Increase sales by 10%");

    std::string report = manager.generateBranchReport();
    EXPECT_NE(report.find("Branch Report:"), std::string::npos);
    EXPECT_NE(report.find("Total Managed Employees: 1"), std::string::npos);
    EXPECT_NE(report.find("Monthly Goal: Increase sales by 10%"), std::string::npos);
}

TEST(ManagerTest, SetMonthlyGoal) {
    Manager manager(1, "New York", 101, "Alice", 70000.0f);
    manager.setMonthlyGoal("Increase customer satisfaction by 15%");

    EXPECT_EQ(manager.getMonthlyGoal(), "Increase customer satisfaction by 15%");
}