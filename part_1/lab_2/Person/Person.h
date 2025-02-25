#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
public:
    virtual ~Person() = default;
    Person(const std::string& person_name, int age, float weight) {
        person_name_ = person_name;
        age_ = age;
        weight_ = weight;
    };
    std::string getName();
    int getAge();
    float getWeight() const;
    void setAge(int age) {age_ = age;}
    virtual void getInformation();
private:
    std::string person_name_;
    int age_;
    float weight_;
};

#endif //PERSON_H
