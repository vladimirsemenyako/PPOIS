#include "Bank.h"


Bank::Bank(const std::string& name) : bank_name_(name) {}

std::string Bank::get_bank_name() {
    return bank_name_;
}

void Bank::addBranch(const std::string& branchName) {
    branches_.push_back(branchName);
}

std::vector<std::string> Bank::get_branches() {
    return branches_;
}