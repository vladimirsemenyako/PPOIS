#ifndef KITCHENWARE_H
#define KITCHENWARE_H
#include "../Homegoods/Homegoods.h"

class Kitchenware : public Homegoods {
public:
    Kitchenware(const std::string& name, float price, int quantity, const std::string& material, bool dishwasher_safe);

    void setMaterial(const std::string& material);
    std::string getMaterial() const;

    void setDishwasherSafe(bool dishwasher_safe);
    bool isDishwasherSafe() const;

    void displayKitchenwareInfo() const;

private:
    std::string material_;
    bool dishwasher_safe_;
};

#endif //KITCHENWARE_H
