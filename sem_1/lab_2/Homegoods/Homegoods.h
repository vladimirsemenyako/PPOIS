#ifndef HOMEGOODS_H
#define HOMEGOODS_H
#include "../Product/Product.h"

class Homegoods : public Product {
public:
    Homegoods(const std::string& name, float price, int quantity, const std::string& material);

    void setMaterial(const std::string& material);
    std::string getMaterial() const;

    void displayHomegoodInfo() const;

private:
    std::string material_;
};

#endif //HOMEGOODS_H
