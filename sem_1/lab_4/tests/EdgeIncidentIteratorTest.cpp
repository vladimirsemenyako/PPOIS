#include <gtest/gtest.h>
#include <unordered_set>
#include "../EdgeIncidentIterator.h"

class EdgeIncidentIteratorTest : public ::testing::Test {
protected:
    int vertex = 1;
    std::unordered_set<int> adjacency_set = {2, 3};
    EdgeIncidentIterator<int> iterator_begin = EdgeIncidentIterator<int>(adjacency_set.begin(), vertex);
    EdgeIncidentIterator<int> iterator_end = EdgeIncidentIterator<int>(adjacency_set.end(), vertex);
};

// Тест на оператор разыменования
TEST_F(EdgeIncidentIteratorTest, DereferenceOperator) {
    auto edge = *iterator_begin;
    EXPECT_EQ(edge.first, 1);  // Начальная вершина
    EXPECT_EQ(edge.second, 2); // Связана с первой смежной вершиной
}

// Тест на префиксный инкрементный оператор
TEST_F(EdgeIncidentIteratorTest, PrefixIncrementOperator) {
    ++iterator_begin;
    auto edge = *iterator_begin;
    EXPECT_EQ(edge.first, 1);
    EXPECT_EQ(edge.second, 3); // Теперь связана с другой смежной вершиной
}

// Тест на префиксный декрементный оператор
TEST_F(EdgeIncidentIteratorTest, PrefixDecrementOperator) {
    ++iterator_begin;  // Перемещаемся ко второй вершине для теста
    --iterator_begin;  // Возвращаемся обратно
    auto edge = *iterator_begin;
    EXPECT_EQ(edge.first, 1);
    EXPECT_EQ(edge.second, 2);
}

// Тест на оператор равенства
TEST_F(EdgeIncidentIteratorTest, EqualityOperator) {
    EdgeIncidentIterator<int> iterator_copy = iterator_begin;
    EXPECT_TRUE(iterator_begin == iterator_copy);
    ++iterator_begin;
    EXPECT_FALSE(iterator_begin == iterator_copy);
}

// Тест на оператор неравенства
TEST_F(EdgeIncidentIteratorTest, InequalityOperator) {
    EdgeIncidentIterator<int> iterator_copy = iterator_begin;
    EXPECT_FALSE(iterator_begin != iterator_copy);
    ++iterator_begin;
    EXPECT_TRUE(iterator_begin != iterator_copy);
}