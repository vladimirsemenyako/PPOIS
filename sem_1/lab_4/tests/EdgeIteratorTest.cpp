#include <gtest/gtest.h>
#include "../EdgeIterator.h"
#include <map>
#include <set>

class EdgeIteratorTest : public ::testing::Test {
protected:
    std::map<int, std::set<int>> test_map;

    void SetUp() override {
        // Создаем тестовый граф
        test_map[1] = std::set<int>{2, 3};
        test_map[2] = std::set<int>{1, 3};
        test_map[3] = std::set<int>{1, 2};
    }
};

TEST_F(EdgeIteratorTest, ConstructorTest) {
    EdgeIterator<int> iterator(test_map.begin(), test_map.end());
    auto edge = *iterator;
    EXPECT_EQ(edge.first, 1);
    EXPECT_EQ(edge.second, 2);
}

TEST_F(EdgeIteratorTest, IncrementOperatorTest) {
    EdgeIterator<int> iterator(test_map.begin(), test_map.end());

    auto edge1 = *iterator;
    EXPECT_EQ(edge1.first, 1);
    EXPECT_EQ(edge1.second, 2);

    ++iterator;
    auto edge2 = *iterator;
    EXPECT_EQ(edge2.first, 2);
    EXPECT_EQ(edge2.second, 1);
}

TEST_F(EdgeIteratorTest, DecrementOperatorTest) {
    EdgeIterator<int> iterator(test_map.find(2), test_map.end());

    auto edge1 = *iterator;
    EXPECT_EQ(edge1.first, 2);
    EXPECT_EQ(edge1.second, 1);

    --iterator;
    auto edge2 = *iterator;
    EXPECT_EQ(edge2.first, 1);
    EXPECT_EQ(edge2.second, 2);
}

TEST_F(EdgeIteratorTest, EqualityOperatorTest) {
    EdgeIterator<int> it1(test_map.begin(), test_map.end());
    EdgeIterator<int> it2(test_map.begin(), test_map.end());
    EdgeIterator<int> it3(test_map.find(2), test_map.end());

    EXPECT_TRUE(it1 == it2);
    EXPECT_FALSE(it1 == it3);
}

TEST_F(EdgeIteratorTest, InequalityOperatorTest) {
    EdgeIterator<int> it1(test_map.begin(), test_map.end());
    EdgeIterator<int> it2(test_map.begin(), test_map.end());
    EdgeIterator<int> it3(test_map.find(2), test_map.end());

    EXPECT_FALSE(it1 != it2);
    EXPECT_TRUE(it1 != it3);
}

TEST_F(EdgeIteratorTest, EmptyGraphTest) {
    std::map<int, std::set<int>> empty_map;
    EdgeIterator<int> begin(empty_map.begin(), empty_map.end());
    EdgeIterator<int> end(empty_map.end(), empty_map.end());

    EXPECT_TRUE(begin == end);
}

TEST_F(EdgeIteratorTest, CompleteIterationTest) {
    EdgeIterator<int> begin(test_map.begin(), test_map.end());
    EdgeIterator<int> end(test_map.end(), test_map.end());

    int edge_count = 0;
    for (auto it = begin; it != end; ++it) {
        ++edge_count;
    }
    EXPECT_NE(edge_count, 6);
}

TEST_F(EdgeIteratorTest, SingleVertexTest) {
    std::map<int, std::set<int>> single_vertex_map;
    single_vertex_map[1] = std::set<int>();

    EdgeIterator<int> begin(single_vertex_map.begin(), single_vertex_map.end());
    EdgeIterator<int> end(single_vertex_map.end(), single_vertex_map.end());

    EXPECT_FALSE(begin == end);
}

TEST_F(EdgeIteratorTest, BoundaryTest) {
    EdgeIterator<int> it(test_map.end(), test_map.end());
    --it;
    auto edge = *it;
    EXPECT_NE(edge.first, 3);
}