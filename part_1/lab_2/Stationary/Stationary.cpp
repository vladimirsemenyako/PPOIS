#include "Stationary.h"

Stationary::Stationary(const std::string& name, float price, int quantity, const std::string& brand)
    : Product(name, price, quantity, "Stationary"), brand_(brand) {}

void Stationary::setBrand(const std::string& brand) {
    brand_ = brand;
}

std::string Stationary::getBrand() const {
    return brand_;
}

void Stationary::displayStationaryInfo() const {
    std::cout << "Stationary Brand: " << brand_ << "\n";
}