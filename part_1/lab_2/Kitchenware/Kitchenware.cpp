#include "Kitchenware.h"


Kitchenware::Kitchenware(const std::string& name, float price, int quantity, const std::string& material, bool dishwasher_safe)
    : Homegoods(name, price, quantity, material), material_(material), dishwasher_safe_(dishwasher_safe) {}

void Kitchenware::setMaterial(const std::string& material) {
    material_ = material;
}

std::string Kitchenware::getMaterial() const {
    return material_;
}

void Kitchenware::setDishwasherSafe(bool dishwasher_safe) {
    dishwasher_safe_ = dishwasher_safe;
}

bool Kitchenware::isDishwasherSafe() const {
    return dishwasher_safe_;
}

void Kitchenware::displayKitchenwareInfo() const {
    std::cout << "Material: " << material_ << "\n";
    std::cout << "Dishwasher Safe: " << (dishwasher_safe_ ? "Yes" : "No") << "\n";
}
