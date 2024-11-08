#include <gtest/gtest.h>
#include <unordered_set>
#include "../AdjacentVertexIterator.h"

// Класс для тестирования итератора смежных вершин
class AdjacentVertexIteratorTest : public ::testing::Test {
protected:
    std::unordered_set<int> adjacency_set = {1, 2, 3};
    AdjacentVertexIterator<int> iterator_begin = AdjacentVertexIterator<int>(adjacency_set.begin());
    AdjacentVertexIterator<int> iterator_end = AdjacentVertexIterator<int>(adjacency_set.end());
};

// Тест на оператор разыменования
TEST_F(AdjacentVertexIteratorTest, DereferenceOperator) {
    EXPECT_EQ(*iterator_begin, 1);
}

// Тест на префиксный инкрементный оператор
TEST_F(AdjacentVertexIteratorTest, PrefixIncrementOperator) {
    ++iterator_begin;
    EXPECT_EQ(*iterator_begin, 2);
}

// Тест на префиксный декрементный оператор
TEST_F(AdjacentVertexIteratorTest, PrefixDecrementOperator) {
    ++iterator_begin;  // Убедимся, что находимся на втором элементе
    --iterator_begin;
    EXPECT_EQ(*iterator_begin, 1);
}

// Тест на оператор равенства
TEST_F(AdjacentVertexIteratorTest, EqualityOperator) {
    AdjacentVertexIterator<int> iterator_copy = iterator_begin;
    EXPECT_TRUE(iterator_begin == iterator_copy);
    ++iterator_begin;
    EXPECT_FALSE(iterator_begin == iterator_copy);
}

// Тест на оператор неравенства
TEST_F(AdjacentVertexIteratorTest, InequalityOperator) {
    AdjacentVertexIterator<int> iterator_copy = iterator_begin;
    EXPECT_FALSE(iterator_begin != iterator_copy);
    ++iterator_begin;
    EXPECT_TRUE(iterator_begin != iterator_copy);
}