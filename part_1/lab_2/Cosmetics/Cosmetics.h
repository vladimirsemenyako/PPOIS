#ifndef COSMETICS_H
#define COSMETICS_H
#include "../Product/Product.h"

class Cosmetics : public Product {
public:
    Cosmetics(const std::string& name, float price, int quantity, const std::string& skin_type);

    void setSkinType(const std::string& type);
    std::string getSkinType() const;

    void displayCosmeticInfo() const;

private:
    std::string skin_type_;
};

#endif //COSMETICS_H
