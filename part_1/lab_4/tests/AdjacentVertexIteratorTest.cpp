#include <gtest/gtest.h>
#include "../AdjacentVertexIterator.h"
#include <set>

class AdjacentVertexIteratorTest : public ::testing::Test {
protected:
    std::set<int> adjacent_vertices;
    const int test_vertex = 1;

    void SetUp() override {
        adjacent_vertices = {2, 3, 4};
    }
};

TEST_F(AdjacentVertexIteratorTest, ConstructorTest) {
    AdjacentVertexIterator<int> iterator(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    EXPECT_EQ(*iterator, 2);
}

TEST_F(AdjacentVertexIteratorTest, IncrementOperatorTest) {
    AdjacentVertexIterator<int> iterator(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    EXPECT_EQ(*iterator, 2);
    ++iterator;
    EXPECT_EQ(*iterator, 3);
    ++iterator;
    EXPECT_EQ(*iterator, 4);
}

TEST_F(AdjacentVertexIteratorTest, DecrementOperatorTest) {
    auto it = adjacent_vertices.find(4);
    AdjacentVertexIterator<int> iterator(it, adjacent_vertices.end(), test_vertex);
    EXPECT_EQ(*iterator, 4);
    --iterator;
    EXPECT_EQ(*iterator, 3);
    --iterator;
    EXPECT_EQ(*iterator, 2);
}

TEST_F(AdjacentVertexIteratorTest, EqualityOperatorTest) {
    AdjacentVertexIterator<int> it1(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    AdjacentVertexIterator<int> it2(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    AdjacentVertexIterator<int> it3(++adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);

    EXPECT_TRUE(it1 == it2);
    EXPECT_FALSE(it1 == it3);
}

TEST_F(AdjacentVertexIteratorTest, InequalityOperatorTest) {
    AdjacentVertexIterator<int> it1(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    AdjacentVertexIterator<int> it2(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    AdjacentVertexIterator<int> it3(++adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);

    EXPECT_FALSE(it1 != it2);
    EXPECT_TRUE(it1 != it3);
}

TEST_F(AdjacentVertexIteratorTest, EmptySetTest) {
    std::set<int> empty_set;
    AdjacentVertexIterator<int> begin(empty_set.begin(), empty_set.end(), test_vertex);
    AdjacentVertexIterator<int> end(empty_set.end(), empty_set.end(), test_vertex);

    EXPECT_TRUE(begin == end);
}

TEST_F(AdjacentVertexIteratorTest, CompleteIterationTest) {
    AdjacentVertexIterator<int> begin(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    AdjacentVertexIterator<int> end(adjacent_vertices.end(), adjacent_vertices.end(), test_vertex);

    std::vector<int> expected = {2, 3, 4};
    std::vector<int> result;

    for (auto it = begin; it != end; ++it) {
        result.push_back(*it);
    }

    EXPECT_EQ(result, expected);
}

TEST_F(AdjacentVertexIteratorTest, BoundaryTest) {
    AdjacentVertexIterator<int> it(adjacent_vertices.end(), adjacent_vertices.end(), test_vertex);
    --it;
    EXPECT_NE(*it, 1);
}