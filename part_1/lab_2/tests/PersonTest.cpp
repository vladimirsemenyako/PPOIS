#include <gtest/gtest.h>
#include "../Person/Person.h"

// Тест конструктора
TEST(PersonTest, ConstructorTest) {
    Person person("Alice", 30, 65.0);

    EXPECT_EQ(person.getName(), "Alice");
    EXPECT_EQ(person.getAge(), 30);
    EXPECT_FLOAT_EQ(person.getWeight(), 65.0);
}

// Тест получения информации
TEST(PersonTest, GetInformation) {
    Person person("Bob", 25, 70.0);

    testing::internal::CaptureStdout();
    person.getInformation();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Bob is 25 years old."), std::string::npos);
}


// Тест получения веса
TEST(PersonTest, GetWeight) {
    Person person("Diana", 35, 55.0); // 0 - Male

    EXPECT_FLOAT_EQ(person.getWeight(), 55.0);
}

TEST(PersonTest, SetAge) {
    Person person("Eva", 28, 60.0);
    person.setAge(30);

    EXPECT_EQ(person.getAge(), 30);
}