#include "Bakery.h"

Bakery::Bakery(const std::string& name, float price, int quantity, const std::string& expiration_date,
               const std::string& bakery_type, bool is_gluten_free)
    : Grocery(name, price, quantity, expiration_date), bakery_type_(bakery_type), is_gluten_free_(is_gluten_free) {}

void Bakery::setBakeryType(const std::string& type) {
    bakery_type_ = type;
}

std::string Bakery::getBakeryType() const {
    return bakery_type_;
}

void Bakery::setGlutenFree(bool gluten_free) {
    is_gluten_free_ = gluten_free;
}

bool Bakery::isGlutenFree() const {
    return is_gluten_free_;
}

void Bakery::displayBakeryInfo() const {
    std::cout << "Bakery Type: " << bakery_type_ << "\n";
    std::cout << "Contains Gluten: " << (is_gluten_free_ ? "No" : "Yes") << "\n";
}
