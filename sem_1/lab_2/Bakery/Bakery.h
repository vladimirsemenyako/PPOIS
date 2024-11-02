#ifndef BAKERY_H
#define BAKERY_H
#include "../Grocery/Grocery.h"

class Bakery : public Grocery {
public:
    Bakery(const std::string& name, float price, int quantity, const std::string& expiration_date,
           const std::string& bakery_type, bool is_gluten_free);

    void setBakeryType(const std::string& type);
    std::string getBakeryType() const;

    void setGlutenFree(bool gluten_free);
    bool isGlutenFree() const;

    void displayBakeryInfo() const;

private:
    std::string bakery_type_;
    bool is_gluten_free_;
};

#endif //BAKERY_H
