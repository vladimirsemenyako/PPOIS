#include "Canned.h"

Canned::Canned(const std::string& name, float price, int quantity, const std::string& expiration_date,
               const std::string& preservation_type, bool is_recyclable)
    : Grocery(name, price, quantity, expiration_date), preservation_type_(preservation_type), is_recyclable_(is_recyclable) {}

void Canned::setPreservationType(const std::string& type) {
    preservation_type_ = type;
}

std::string Canned::getPreservationType() const{
    return preservation_type_;
}

void Canned::setRecyclable(bool recyclable) {
    is_recyclable_ = recyclable;
}

bool Canned::isRecyclable() const {
    return is_recyclable_;
}

void Canned::displayCannedInfo() const {
    std::cout << "Preservation Type: " << preservation_type_ << "\n";
    std::cout << "Recyclable Packaging: " << (is_recyclable_ ? "Yes" : "No") << "\n";
}
