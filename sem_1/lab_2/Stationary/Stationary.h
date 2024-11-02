#ifndef STATIONARY_H
#define STATIONARY_H
#include "../Product/Product.h"

class Stationary : public Product {
public:
    Stationary(const std::string& name, float price, int quantity, const std::string& brand);

    void setBrand(const std::string& brand);
    std::string getBrand() const;

    void displayStationaryInfo() const;

private:
    std::string brand_;
};

#endif //STATIONARY_H
