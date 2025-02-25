#include <gtest/gtest.h>
#include "../Employee/Employee.h"

// Тест для конструктора и методов класса Employee
TEST(EmployeeTest, Initialization) {
    Employee emp(1, "New York", 101, "John Doe", "Manager", 5000.0f);

    // Проверяем корректность имени сотрудника
    EXPECT_EQ(emp.getEmpName(), "John Doe");

    // Проверяем, что информация о сотруднике включает правильную позицию
    EXPECT_TRUE(emp.getEmployeeInfo().find("Manager") != std::string::npos);

    // Проверяем, что расчёт годового дохода верный
    EXPECT_EQ(emp.calcYearlyIncome(), 5000.0f * 12);

    // Проверяем, что зарплата установлена правильно
    EXPECT_EQ(emp.getSalary(), 5000.0f);
}

TEST(EmployeeTest, SetSalary) {
    Employee emp(1, "New York", 101, "John Doe", "Manager", 5000.0f);

    // Устанавливаем новую зарплату и проверяем, что она изменилась
    emp.setSalary(6000.0f);
    EXPECT_EQ(emp.getSalary(), 6000.0f);
}

TEST(EmployeeTest, SalaryCalculation) {
    Employee emp(1, "New York", 101, "John Doe", "Manager", 5000.0f);

    // Проверяем правильность расчёта годового дохода
    EXPECT_EQ(emp.calcYearlyIncome(), 5000.0f * 12);
}

TEST(EmployeeTest, EmployeeInfo) {
    Employee emp(1, "New York", 101, "John Doe", "Manager", 5000.0f);

    // Проверяем, что информация о сотруднике корректно отображает имя и должность
    EXPECT_TRUE(emp.getEmployeeInfo().find("John Doe") != std::string::npos);
    EXPECT_TRUE(emp.getEmployeeInfo().find("Manager") != std::string::npos);
}

// Тест для пустого конструктора
TEST(EmployeeTest, DefaultConstructor) {
    Employee emp(1, "London", 102, "Jane Smith", "Developer", 4000.0f);

    EXPECT_EQ(emp.getSalary(), 4000.0f);
    EXPECT_EQ(emp.getEmpName(), "Jane Smith");
    EXPECT_TRUE(emp.getEmployeeInfo().find("Developer") != std::string::npos);
}

TEST(EmployeeTest, CheckEmployeeInfo) {
    Employee emp(1, "New York", 101, "John Doe", "Manager", 5000.0f);
    std::string correct_output = "Employee ID: 101, Name: John Doe, Position: Manager";
    EXPECT_EQ(emp.getEmployeeInfo(), correct_output);
}

