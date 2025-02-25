#ifndef STOCKINVESTMENT_H
#define STOCKINVESTMENT_H
#include "../Investment/Investment.h"

class StockInvestment : public Investment {
public:
    StockInvestment(int branch_id, std::string location, int cust_id, std::string name, int investment_id, std::string investment_type, float initial_amount,
                   float return_rate, std::string start_date, int stock_price)
                       : Investment(branch_id, location, cust_id, name, investment_id, investment_type, initial_amount, return_rate, start_date), stock_price_(stock_price) {}

    int get_stock_price();
    void set_stock_price(int stock_price);
private:
    int stock_price_;
};

#endif //STOCKINVESTMENT_H
