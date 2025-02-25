#ifndef MANAGER_H
#define MANAGER_H

#include "../Employee/Employee.h"
#include <string>
#include <vector>

class Manager final : public Employee {
public:
    Manager(int branchId, const std::string& branchLocation, int id, const std::string& name, float salary)
        : Employee(branchId, branchLocation, id, name, "Manager", salary) {}

    void addEmployee(int employeeId);
    bool removeEmployee(int employeeId);
    std::string generateBranchReport();
    void setMonthlyGoal(const std::string& goal);
    std::string getMonthlyGoal() const;
    std::vector<int> managed_employees;
private:
    std::string monthly_goal_;
};

#endif //MANAGER_H