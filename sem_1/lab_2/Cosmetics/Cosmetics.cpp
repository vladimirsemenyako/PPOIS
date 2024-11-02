#include "Cosmetics.h"


Cosmetics::Cosmetics(const std::string& name, float price, int quantity, const std::string& skin_type)
    : Product(name, price, quantity, "Cosmetics"), skin_type_(skin_type) {}

void Cosmetics::setSkinType(const std::string& type) {
    skin_type_ = type;
}

std::string Cosmetics::getSkinType() const {
    return skin_type_;
}

void Cosmetics::displayCosmeticInfo() const {
    std::cout << "Cosmetic Product for Skin Type: " << skin_type_ << "\n";
}
