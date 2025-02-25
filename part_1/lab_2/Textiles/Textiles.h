#ifndef TEXTILES_H
#define TEXTILES_H
#include "../Homegoods/Homegoods.h"

class Textiles : public Homegoods {
public:
    Textiles(const std::string& name, float price, int quantity, const std::string& material, const std::string& size, bool is_machine_washable);

    // Уникальные методы для Textiles
    void setMaterial(const std::string& material);
    std::string getMaterial() const;

    void setSize(const std::string& size);
    std::string getSize() const;

    void setMachineWashable(bool machine_washable);
    bool isMachineWashable() const;

    void displayTextileInfo() const;

private:
    std::string material_;
    std::string size_;
    bool is_machine_washable_;
};

#endif //TEXTILES_H
