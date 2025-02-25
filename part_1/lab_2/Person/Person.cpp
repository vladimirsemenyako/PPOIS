#include "Person.h"
#include <iostream>

std::string Person::getName() {
    return person_name_;
}

int Person::getAge() {
    return age_;
}

float Person::getWeight() const {
    return weight_;
}

void Person::getInformation() {
    std::cout << person_name_ << " is " << age_ << " years old.";
}





