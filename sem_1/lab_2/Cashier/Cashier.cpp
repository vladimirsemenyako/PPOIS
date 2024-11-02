#include "Cashier.h"

Cashier::Cashier(const std::string& person_name, int age, float weight, int register_number, int shift_hours)
         : Staff(person_name, age, weight, "Cashier"),
           register_number_(register_number), shift_hours_(shift_hours), total_sales_(0.0f) {}

void Cashier::processSale(float sale_amount) {
    total_sales_ += sale_amount;
    std::cout << "Processed sale: $" << sale_amount << ". Total sales: $" << total_sales_ << "\n";
}

void Cashier::checkInventory(const std::string& item) {
    std::cout << "Checking inventory for " << item << ".\n";
}

void Cashier::startShift() {
    total_sales_ = 0.0f;
    std::cout << "Shift started at register #" << register_number_ << ".\n";
}


void Cashier::endShift() const {
    std::cout << "Shift ended. Total sales for the shift: $" << total_sales_ << "\n";
}

void Cashier::getInformation() {
    Staff::getInformation();
    std::cout << "Register Number: " << register_number_ << "\n";
    std::cout << "Shift Hours: " << shift_hours_ << " hours\n";
    std::cout << "Total Sales: $" << total_sales_ << "\n";
}


