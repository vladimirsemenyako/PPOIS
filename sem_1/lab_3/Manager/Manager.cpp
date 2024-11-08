#include "Manager.h"

void Manager::addEmployee(int employee_id) {
    managed_employees.push_back(employee_id);
}

std::string Manager::generateBranchReport() {
    std::string report = "Branch Report:\n";
    report += "Total Managed Employees: " + std::to_string(managed_employees.size()) + "\n";
    report += "Monthly Goal: " + monthly_goal_ + "\n";
    return report;
}

bool Manager::removeEmployee(int employeeId) {
    auto it = std::find(managed_employees.begin(), managed_employees.end(), employeeId);
    if (it != managed_employees.end()) {
        managed_employees.erase(it);
        std::cout << "Employee " << employeeId << " removed from management.\n";
        return true;
    }
    std::cout << "Employee " << employeeId << " not found under management.\n";
    return false;
}

std::string Manager::getMonthlyGoal() const {
    return monthly_goal_;
}

void Manager::setMonthlyGoal(const std::string &goal) {
    monthly_goal_ = goal;
}




