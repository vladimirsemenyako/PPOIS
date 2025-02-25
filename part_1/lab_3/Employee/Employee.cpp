#include "Employee.h"

float Employee::getSalary() const {
    return salary_;
}

void Employee::setSalary(float new_salary) {
    salary_ = new_salary;
    std::cout << "Your new salary is " << salary_;
}

float Employee::calcYearlyIncome() {
    return salary_ * 12;
}

std::string Employee::getEmployeeInfo() {
    return "Employee ID: " + std::to_string(employee_id) + ", Name: " + employee_name_ + ", Position: " + position_;
}

std::string Employee::getEmpName() {
    return employee_name_;
}



