#include "Textiles.h"

Textiles::Textiles(const std::string& name, float price, int quantity, const std::string& material, const std::string& size, bool is_machine_washable)
    : Homegoods(name, price, quantity, material), material_(material), size_(size), is_machine_washable_(is_machine_washable) {}

void Textiles::setMaterial(const std::string& material) {
    material_ = material;
}

std::string Textiles::getMaterial() const {
    return material_;
}

void Textiles::setSize(const std::string& size) {
    size_ = size;
}

std::string Textiles::getSize() const {
    return size_;
}

void Textiles::setMachineWashable(bool machine_washable) {
    is_machine_washable_ = machine_washable;
}

bool Textiles::isMachineWashable() const {
    return is_machine_washable_;
}

void Textiles::displayTextileInfo() const {
    std::cout << "Material: " << material_ << "\n";
    std::cout << "Size: " << size_ << "\n";
    std::cout << "Machine Washable: " << (is_machine_washable_ ? "Yes" : "No") << "\n";
}
