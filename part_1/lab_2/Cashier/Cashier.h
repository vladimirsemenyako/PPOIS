#ifndef CASHIER_H
#define CASHIER_H
#include "../Staff/Staff.h"


class Cashier final : public Staff {
public:
    Cashier(const std::string& person_name, int age, float weight, int register_number, int shift_hours);
    void processSale(float sale_amount);
    void startShift();
    void endShift() const;
    static void checkInventory(const std::string& item);
    void getInformation() override;
private:
    int register_number_;
    int shift_hours_;
    float total_sales_;
};


#endif //CASHIER_H
