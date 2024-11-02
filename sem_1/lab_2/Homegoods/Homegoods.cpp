#include "Homegoods.h"

Homegoods::Homegoods(const std::string& name, float price, int quantity, const std::string& material)
    : Product(name, price, quantity, "Homegoods"), material_(material) {}

void Homegoods::setMaterial(const std::string& material) {
    material_ = material;
}

std::string Homegoods::getMaterial() const {
    return material_;
}

void Homegoods::displayHomegoodInfo() const {
    std::cout << "Homegoods Material: " << material_ << "\n";
}