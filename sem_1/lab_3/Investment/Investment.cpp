#include "Investment.h"

float Investment::calculate_return() const {
    return initial_amount_ * (return_rate_ / 100);
}

void Investment::addInvestment(float amount) {
    initial_amount_ += amount;
    std::cout << "Initial amount is " << initial_amount_ << std::endl;
}


void Investment::displayInvestmentInfo() const {
    std::cout << "Investment ID: " << investment_id_ << "\n"
                 << "Type: " << investment_type_ << "\n"
                 << "Initial Amount: " << initial_amount_ << "\n"
                 << "Return Rate: " << return_rate_ << "%\n"
                 << "Start Date: " << start_date_ << std::endl;
}



