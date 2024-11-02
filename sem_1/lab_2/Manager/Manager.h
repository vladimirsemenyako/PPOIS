#ifndef MANAGER_H
#define MANAGER_H
#include "../Staff/Staff.h"

class Manager final : public Staff {
public:
    Manager(std::string person_name, int age, float weight, std::string position, float budget);
    void scheduleShift(const std::string& employee_name, const std::string& shift_time);
    static void reviewPerformance(const std::string& employee_name, int rating);

    float getBudget();
    void approveBudget(float amount);
    void generateReport();
    static void handleComplaint(const std::string& complaint);

private:
    float budget_; // бюджет, которым управляет менеджер
    std::vector<std::string> employee_list_; // список сотрудников
    std::vector<std::string> reports_; // отчетность
};

#endif //MANAGER_H
