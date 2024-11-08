#include <gtest/gtest.h>
#include <unordered_map>
#include <unordered_set>
#include "../VertexIterator.h"  // Предполагаем, что этот файл содержит ваш итератор

// Тестируем класс VertexIterator
class VertexIteratorTest : public ::testing::Test {
protected:
    // Инициализация данных для тестов
    std::unordered_map<int, std::unordered_set<int>> adj_list;

    void SetUp() override {
        adj_list[1] = {2, 3};
        adj_list[2] = {1, 3};
        adj_list[3] = {1, 2};
    }
};

// Проверка разыменования итератора
TEST_F(VertexIteratorTest, DereferenceIterator) {
    VertexIterator<int> it(adj_list.begin());
    EXPECT_EQ(*it, 1);  // Проверяем, что первый элемент итератора - это вершина 1

    ++it;
    EXPECT_EQ(*it, 2);  // Проверяем, что следующий элемент - вершина 2
}

// Проверка инкремента итератора
TEST_F(VertexIteratorTest, IncrementIterator) {
    VertexIterator<int> it(adj_list.begin());
    EXPECT_EQ(*it, 1);  // Начинаем с вершины 1

    ++it;  // Инкрементируем
    EXPECT_EQ(*it, 2);  // Переход к вершине 2

    ++it;  // Инкрементируем
    EXPECT_EQ(*it, 3);  // Переход к вершине 3
}

// Проверка декремента итератора
TEST_F(VertexIteratorTest, DecrementIterator) {
    VertexIterator<int> it(adj_list.end());
    --it;  // Переходим к последней вершине
    EXPECT_EQ(*it, 3);  // Проверяем, что мы на вершине 3

    --it;  // Декрементируем
    EXPECT_EQ(*it, 2);  // Проверяем, что мы на вершине 2

    --it;  // Декрементируем
    EXPECT_EQ(*it, 1);  // Проверяем, что мы на вершине 1
}

// Проверка на равенство итераторов
TEST_F(VertexIteratorTest, EqualityOperator) {
    VertexIterator<int> it1(adj_list.begin());
    VertexIterator<int> it2(adj_list.begin());
    VertexIterator<int> it3(adj_list.end());

    EXPECT_TRUE(it1 == it2);  // Два итератора должны быть равны, так как они указывают на одно и то же место
    EXPECT_FALSE(it1 == it3); // Итератор на начало и на конец не равны
}

// Проверка на неравенство итераторов
TEST_F(VertexIteratorTest, InequalityOperator) {
    VertexIterator<int> it1(adj_list.begin());
    VertexIterator<int> it2(adj_list.begin());
    VertexIterator<int> it3(adj_list.end());

    EXPECT_FALSE(it1 != it2); // Итераторы, указывающие на одно и то же место, не должны быть неравны
    EXPECT_TRUE(it1 != it3);  // Итераторы на начало и на конец должны быть неравны
}

// Проверка перехода через все элементы
TEST_F(VertexIteratorTest, IterateAllVertices) {
    VertexIterator<int> it(adj_list.begin());
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}

// Проверка на выход за пределы
TEST_F(VertexIteratorTest, OutOfBounds) {
    VertexIterator<int> it(adj_list.end());

    // Проверка того, что не будем разыменовывать пустой итератор
    EXPECT_THROW(*it, std::out_of_range);  // Будет выброшено исключение при попытке разыменовать конец
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}