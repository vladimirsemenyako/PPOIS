#include <gtest/gtest.h>
#include "../EdgeIncidentIterator.h"
#include <set>

class EdgeIncidentIteratorTest : public ::testing::Test {
protected:
    std::set<int> adjacent_vertices;
    const int test_vertex = 1;

    void SetUp() override {
        adjacent_vertices = {2, 3, 4};
    }
};

TEST_F(EdgeIncidentIteratorTest, ConstructorTest) {
    EdgeIncidentIterator<int> iterator(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    auto edge = *iterator;
    EXPECT_EQ(edge.first, test_vertex);
    EXPECT_EQ(edge.second, 2);
}

TEST_F(EdgeIncidentIteratorTest, IncrementOperatorTest) {
    EdgeIncidentIterator<int> iterator(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);

    auto edge1 = *iterator;
    EXPECT_EQ(edge1.first, test_vertex);
    EXPECT_EQ(edge1.second, 2);

    ++iterator;
    auto edge2 = *iterator;
    EXPECT_EQ(edge2.first, test_vertex);
    EXPECT_EQ(edge2.second, 3);
}

TEST_F(EdgeIncidentIteratorTest, DecrementOperatorTest) {
    auto it = adjacent_vertices.find(3);
    EdgeIncidentIterator<int> iterator(it, adjacent_vertices.end(), test_vertex);

    auto edge1 = *iterator;
    EXPECT_EQ(edge1.first, test_vertex);
    EXPECT_EQ(edge1.second, 3);

    --iterator;
    auto edge2 = *iterator;
    EXPECT_EQ(edge2.first, test_vertex);
    EXPECT_EQ(edge2.second, 2);
}

TEST_F(EdgeIncidentIteratorTest, EqualityOperatorTest) {
    EdgeIncidentIterator<int> it1(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    EdgeIncidentIterator<int> it2(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    EdgeIncidentIterator<int> it3(++adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);

    EXPECT_TRUE(it1 == it2);
    EXPECT_FALSE(it1 == it3);
}

TEST_F(EdgeIncidentIteratorTest, EmptySetTest) {
    std::set<int> empty_set;
    EdgeIncidentIterator<int> begin(empty_set.begin(), empty_set.end(), test_vertex);
    EdgeIncidentIterator<int> end(empty_set.end(), empty_set.end(), test_vertex);

    EXPECT_TRUE(begin == end);
}

TEST_F(EdgeIncidentIteratorTest, CompleteIterationTest) {
    EdgeIncidentIterator<int> begin(adjacent_vertices.begin(), adjacent_vertices.end(), test_vertex);
    EdgeIncidentIterator<int> end(adjacent_vertices.end(), adjacent_vertices.end(), test_vertex);

    int edge_count = 0;
    for (auto it = begin; it != end; ++it) {
        auto edge = *it;
        EXPECT_EQ(edge.first, test_vertex);
        ++edge_count;
    }
    EXPECT_EQ(edge_count, 3);
}