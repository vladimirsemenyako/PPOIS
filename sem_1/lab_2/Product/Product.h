#ifndef PRODUCT_H
#define PRODUCT_H
#include "../Minimarket/Minimarket.h"

class Homegoods;
class Grocery;
class Cosmetics;
class Stationary;

class Product : public Minimarket {
public:

    Product(const std::string& name, float price, int quantity, const std::string& category);
    void setPrice(float new_price);
    float getPrice() const;

    void setQuantity(int new_quantity);
    int getQuantity() const;

    void setCategory(const std::string& new_category);
    std::string getCategory() const;

    void displayInfo() const;
    void purchase(int amount);

    void addGrocery(Grocery* item);
    void addCosmetics(Cosmetics* item);
    void addHomegoods(Homegoods* item);
    void addStationary(Stationary* item);
    std::vector<Grocery*> groceries_;
    std::vector<Cosmetics*> cosmetics_;
    std::vector<Homegoods*> homegoods_;
    std::vector<Stationary*> stationaries_;
private:
    float price_;
    int quantity_;           // Количество на складе
    std::string category_;
};

#endif //PRODUCT_H
