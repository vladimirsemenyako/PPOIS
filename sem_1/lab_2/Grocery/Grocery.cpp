#include "Grocery.h"

Grocery::Grocery(const std::string& name, float price, int quantity, const std::string& expiration_date)
    : Product(name, price, quantity, "Grocery"), expiration_date_(expiration_date) {}

void Grocery::setExpirationDate(const std::string& date) {
    expiration_date_ = date;
}

std::string Grocery::getExpirationDate() const {
    return expiration_date_;
}

void Grocery::checkExpiration() const {
    std::cout << "Expiration Date of " << getName() << ": " << expiration_date_ << "\n";
}