#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
#include <utility>
#include "../Branch/Branch.h"

class Employee : public Branch {
public:
    Employee (int id, std::string location, int emp_id, std::string name, std::string emp_position, float salary) :
    Branch(id, location), employee_id(emp_id), employee_name_(name), position_(emp_position), salary_(salary) {
    }
    std::string getEmployeeInfo();
    float calcYearlyIncome();
    std::string getEmpName();
    float getSalary() const;
    void setSalary(float new_salary);
    int getEmpID() const { return employee_id; };
    int employee_id;
private:

    std::string employee_name_;
    std::string position_;
    float salary_;
};

#endif //EMPLOYEE_H
