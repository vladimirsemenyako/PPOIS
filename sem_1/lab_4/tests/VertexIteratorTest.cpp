#include <gtest/gtest.h>
#include "../VertexIterator.h"
#include <map>
#include <set>

class VertexIteratorTest : public ::testing::Test {
protected:
    std::map<int, std::set<int>> test_map;

    void SetUp() override {
        // Заполняем тестовый map
        test_map[1] = std::set<int>{2, 3};
        test_map[2] = std::set<int>{1, 3};
        test_map[3] = std::set<int>{1, 2};
    }
};

TEST_F(VertexIteratorTest, ConstructorTest) {
    VertexIterator<int> iterator(test_map.begin(), test_map.end());
    EXPECT_EQ(*iterator, 1);
}

TEST_F(VertexIteratorTest, IncrementOperatorTest) {
    VertexIterator<int> iterator(test_map.begin(), test_map.end());
    EXPECT_EQ(*iterator, 1);
    ++iterator;
    EXPECT_EQ(*iterator, 2);
    ++iterator;
    EXPECT_EQ(*iterator, 3);
}

TEST_F(VertexIteratorTest, DecrementOperatorTest) {
    VertexIterator<int> iterator(test_map.find(3), test_map.end());
    EXPECT_EQ(*iterator, 3);
    --iterator;
    EXPECT_EQ(*iterator, 2);
    --iterator;
    EXPECT_EQ(*iterator, 1);
}

TEST_F(VertexIteratorTest, EqualityOperatorTest) {
    VertexIterator<int> it1(test_map.begin(), test_map.end());
    VertexIterator<int> it2(test_map.begin(), test_map.end());
    VertexIterator<int> it3(test_map.find(2), test_map.end());

    EXPECT_TRUE(it1 == it2);
    EXPECT_FALSE(it1 == it3);
}

TEST_F(VertexIteratorTest, InequalityOperatorTest) {
    VertexIterator<int> it1(test_map.begin(), test_map.end());
    VertexIterator<int> it2(test_map.begin(), test_map.end());
    VertexIterator<int> it3(test_map.find(2), test_map.end());

    EXPECT_FALSE(it1 != it2);
    EXPECT_TRUE(it1 != it3);
}

TEST_F(VertexIteratorTest, EndIteratorTest) {
    VertexIterator<int> begin(test_map.begin(), test_map.end());
    VertexIterator<int> end(test_map.end(), test_map.end());

    auto it = begin;
    int count = 0;
    while (it != end) {
        ++count;
        ++it;
    }
    EXPECT_EQ(count, 3);
}

TEST_F(VertexIteratorTest, EmptyMapTest) {
    std::map<int, std::set<int>> empty_map;
    VertexIterator<int> begin(empty_map.begin(), empty_map.end());
    VertexIterator<int> end(empty_map.end(), empty_map.end());

    EXPECT_TRUE(begin == end);
}

TEST_F(VertexIteratorTest, BoundaryTest) {
    VertexIterator<int> it(test_map.end(), test_map.end());
    --it;
    EXPECT_NE(*it, 3);
}