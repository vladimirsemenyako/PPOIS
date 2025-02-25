#ifndef DAIRY_H
#define DAIRY_H
#include "../Grocery/Grocery.h"

class Dairy : public Grocery {
public:
    Dairy(const std::string& name, float price, int quantity, const std::string& expiration_date,
          float fat_content, bool needs_refrigeration);

    void setFatContent(float fat_content);
    float getFatContent() const;

    void setRefrigerationRequired(bool needs_refrigeration);
    bool isRefrigerationRequired() const;

    void displayDairyInfo() const;

private:
    float fat_content_;        // Процент жирности
    bool needs_refrigeration_; // Требуется ли хранение в холодильнике
};

#endif //DAIRY_H
