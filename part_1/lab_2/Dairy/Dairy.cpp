#include "Dairy.h"

Dairy::Dairy(const std::string& name, float price, int quantity, const std::string& expiration_date,
             float fat_content, bool needs_refrigeration)
    : Grocery(name, price, quantity, expiration_date), fat_content_(fat_content), needs_refrigeration_(needs_refrigeration) {}

void Dairy::setFatContent(float fat_content) {
    fat_content_ = fat_content;
}

float Dairy::getFatContent() const {
    return fat_content_;
}

void Dairy::setRefrigerationRequired(bool needs_refrigeration) {
    needs_refrigeration_ = needs_refrigeration;
}

bool Dairy::isRefrigerationRequired() const {
    return needs_refrigeration_;
}

void Dairy::displayDairyInfo() const {
    std::cout << "Fat Content: " << fat_content_ << "%\n";
    std::cout << "Refrigeration Required: " << (needs_refrigeration_ ? "Yes" : "No") << "\n";
}
