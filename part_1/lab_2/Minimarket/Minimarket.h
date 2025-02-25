#ifndef MINIMARKET_H
#define MINIMARKET_H
#include <iostream>
#include <string>
#include <vector>

class Minimarket {
public:
    explicit Minimarket(const std::string& name) : name_(name) {}
    void addWorker(const std::string& worker_name);
    void removeWorker(const std::string& worker_name);
    void listWorkers() const;
    std::vector<std::string> getWorkers() const;
    std::string getName() const;
    void setName(const std::string& new_name);
    void openMarket();
    void closeMarket();
protected:
    std::vector<std::string> workers_;
private:
    std::string name_;

};

#endif //MINIMARKET_H
