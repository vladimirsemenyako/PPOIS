#include "Product.h"

Product::Product(const std::string& name, float price, int quantity, const std::string& category)
    : Minimarket(name), price_(price), quantity_(quantity), category_(category) {}

void Product::setPrice(float new_price) {
    price_ = new_price;
}

float Product::getPrice() const {
    return price_;
}

void Product::setQuantity(int new_quantity) {
    quantity_ = new_quantity;
}

int Product::getQuantity() const {
    return quantity_;
}

void Product::setCategory(const std::string &new_category) {
    category_ = new_category;
}

std::string Product::getCategory() const {
    return category_;
}

void Product::displayInfo() const {
    std::cout << "Product Name: " << getName() << "\n";
    std::cout << "Category: " << category_ << "\n";
    std::cout << "Price: $" << price_ << "\n";
    std::cout << "Available Quantity: " << quantity_ << "\n";
}

void Product::purchase(int amount) {
    if (amount <= quantity_) {
        quantity_ -= amount;
        std::cout << amount << " units of " << getName() << " purchased.\n";
    } else {
        std::cout << "Not enough stock for " << getName() << ". Available: " << quantity_ << "\n";
    }
}


void Product::addGrocery(Grocery* item) {
    groceries_.push_back(item);
}

void Product::addCosmetics(Cosmetics* item) {
    cosmetics_.push_back(item);
}

void Product::addHomegoods(Homegoods* item) {
    homegoods_.push_back(item);
}

void Product::addStationary(Stationary* item) {
    stationaries_.push_back(item);
}
