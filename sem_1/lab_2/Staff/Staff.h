#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include "../Person/Person.h"

class Staff : public Person {
public:
    Staff(const std::string& person_name, int age, float weight, std::string position)
    : Person(person_name, age, weight), position_(position) {}
    void getInformation() override;
    std::string getPosition();
    void reportIssue(const std::string& issue);
    void assistCustomer(const std::string& customerRequest);
    void updateShiftSchedule(const std::string& newSchedule);
private:
    std::string position_;
    std::string shift_schedule_;
};

#endif //STAFF_H
