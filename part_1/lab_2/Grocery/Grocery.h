#ifndef GROCERY_H
#define GROCERY_H
#include "../Product/Product.h"

class Grocery : public Product {
public:
    Grocery() = default;
    Grocery(const std::string& name, float price, int quantity, const std::string& expiration_date);

    void setExpirationDate(const std::string& date);
    std::string getExpirationDate() const;
    void checkExpiration() const;
private:
    std::string expiration_date_;
};

#endif //GROCERY_H
