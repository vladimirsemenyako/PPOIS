#include "Staff.h"

void Staff::getInformation() {
    Person::getInformation();
    std::cout << "Position: " << position_ << "\n";
    if (!shift_schedule_.empty()) {
        std::cout << "Shift Schedule: " << shift_schedule_ << "\n";
    }
}

void Staff::reportIssue(const std::string& issue) {
    std::cout << "Staff " << getName() << " reported an issue: " << issue << "\n";
}

void Staff::assistCustomer(const std::string& customerRequest) {
    std::cout << "Staff " << getName() << " is assisting a customer with request: " << customerRequest << "\n";
}

void Staff::updateShiftSchedule(const std::string& newSchedule) {
    shift_schedule_ = newSchedule;
    std::cout << "Updated shift schedule for " << getName() << ": " << shift_schedule_ << "\n";
}

std::string Staff::getPosition() {
    return position_;
}




