#include <gtest/gtest.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "../EdgeIterator.h" // Путь к файлу с EdgeIterator

// Класс для тестирования итератора рёбер
class EdgeIteratorTest : public ::testing::Test {
protected:
    std::unordered_map<int, std::unordered_set<int>> adj_list;  // Список смежности

    // Инициализация графа
    void SetUp() override {
        adj_list[1] = {2, 3};
        adj_list[2] = {1, 3};
        adj_list[3] = {1, 2};
    }

    // Функция для получения итератора рёбер
    EdgeIterator<int> getEdgeIterator() {
        return EdgeIterator<int>(adj_list.begin());
    }
};

// Тест на оператор разыменования
TEST_F(EdgeIteratorTest, DereferenceOperator) {
    EdgeIterator<int> it = getEdgeIterator();
    auto edge = *it;
    EXPECT_EQ(edge.first, 1); // Первая вершина
    EXPECT_EQ(edge.second, 2); // Вершина, смежная с 1
}

// Тест на префиксный инкрементный оператор
TEST_F(EdgeIteratorTest, PrefixIncrementOperator) {
    EdgeIterator<int> it = getEdgeIterator();
    ++it;
    auto edge = *it;
    EXPECT_EQ(edge.first, 2); // Перемещаемся к вершине 2
    EXPECT_EQ(edge.second, 1); // И проверяем, что смежная вершина 1
}

// Тест на префиксный декрементный оператор
TEST_F(EdgeIteratorTest, PrefixDecrementOperator) {
    EdgeIterator<int> it = getEdgeIterator();
    ++it;  // Перемещаемся ко второй вершине
    --it;  // Возвращаемся обратно
    auto edge = *it;
    EXPECT_EQ(edge.first, 1); // Мы вернулись к первой вершине
    EXPECT_EQ(edge.second, 2); // Смежная вершина 2
}

// Тест на оператор равенства
TEST_F(EdgeIteratorTest, EqualityOperator) {
    EdgeIterator<int> it1 = getEdgeIterator();
    EdgeIterator<int> it2 = getEdgeIterator();
    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_FALSE(it1 == it2);
}

// Тест на оператор неравенства
TEST_F(EdgeIteratorTest, InequalityOperator) {
    EdgeIterator<int> it1 = getEdgeIterator();
    EdgeIterator<int> it2 = getEdgeIterator();
    EXPECT_FALSE(it1 != it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);
}

// Тест на итерацию по всем рёбрам
TEST_F(EdgeIteratorTest, IterationThroughEdges) {
    EdgeIterator<int> it = getEdgeIterator();
    
    // Проверяем первое ребро
    auto edge = *it;
    EXPECT_EQ(edge.first, 1);
    EXPECT_EQ(edge.second, 2);
    
    ++it;  // Переходим ко второму ребру
    edge = *it;
    EXPECT_EQ(edge.first, 2);
    EXPECT_EQ(edge.second, 1);
    
    ++it;  // Переходим к последнему ребру
    edge = *it;
    EXPECT_EQ(edge.first, 3);
    EXPECT_EQ(edge.second, 1);
}