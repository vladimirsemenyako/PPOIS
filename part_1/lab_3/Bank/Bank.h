#ifndef BANK_H
#define BANK_H
#include <string>
#include <vector>

class Bank {
public:

    Bank(const std::string& name);

    std::string get_bank_name();

    void addBranch(const std::string& branchName);

    std::vector<std::string> get_branches();

private:
    std::string bank_name_;
    std::vector<std::string> branches_;

};

#endif //BANK_H
