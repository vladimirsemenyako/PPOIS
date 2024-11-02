#include "Minimarket.h"

void Minimarket::addWorker(const std::string &worker_name) {
    workers_.push_back(worker_name);
    std::cout << "Worker " << worker_name << " added.\n";
}

void Minimarket::listWorkers() const {
    std::cout << "Current workers:\n";
    for (const auto& worker : workers_) {
        std::cout << "- " << worker << "\n";
    }
}
void Minimarket::removeWorker(const std::string &worker_name) {
    auto it = std::find(workers_.begin(), workers_.end(), worker_name);
    if (it != workers_.end()) {
        workers_.erase(it);
        std::cout << "Worker " << worker_name << " removed.\n";
    } else {
        std::cout << "Worker " << worker_name << " not found.\n";
    }
}

std::vector<std::string> Minimarket::getWorkers() const {
    return workers_;
}

void Minimarket::openMarket() {
    std::cout << "The market at " << name_ << " is now open.\n";
}


void Minimarket::closeMarket() {
    std::cout << "The market at " << name_ << " is now closed.\n";
}

std::string Minimarket::getName() const {
    return name_;
}

void Minimarket::setName(const std::string &new_name) {
    name_ = new_name;
}
