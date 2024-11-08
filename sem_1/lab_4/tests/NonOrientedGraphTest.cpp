#include <gtest/gtest.h>
#include "../NonOrientedGraph.h"

class NonOrientedGraphTest : public ::testing::Test {
protected:
    NonOrientedGraph<int> graph;

    void SetUp() override {
        // Инициализируем граф для тестов
        graph.addVertex(1);
        graph.addVertex(2);
        graph.addVertex(3);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
    }
};

// Проверка на добавление вершин
TEST_F(NonOrientedGraphTest, AddVertex) {
    EXPECT_EQ(graph.vertexCount(), 3);
    graph.addVertex(4);
    EXPECT_EQ(graph.vertexCount(), 4);
    EXPECT_EQ(graph.checkVertex(4), "true");
}

// Проверка на добавление рёбер
TEST_F(NonOrientedGraphTest, AddEdge) {
    EXPECT_EQ(graph.edgeCount(), 2);
    graph.addEdge(1, 3);
    EXPECT_EQ(graph.edgeCount(), 3);
    EXPECT_EQ(graph.checkEdge(1, 3), "true");
}

// Проверка на удаление вершины
TEST_F(NonOrientedGraphTest, RemoveVertex) {
    graph.removeVertex(2);
    EXPECT_EQ(graph.vertexCount(), 2);
    EXPECT_EQ(graph.checkVertex(2), "false");
    EXPECT_EQ(graph.edgeCount(), 0); // Все рёбра, связанные с вершиной 2, должны быть удалены
}

// Проверка на удаление рёбер
TEST_F(NonOrientedGraphTest, RemoveEdge) {
    graph.removeEdge(1, 2);
    EXPECT_EQ(graph.edgeCount(), 1);
    EXPECT_EQ(graph.checkEdge(1, 2), "false");
}

// // Проверка на удаление вершины по итератору
// TEST_F(NonOrientedGraphTest, RemoveVertexByIterator) {
//     auto it = graph.vertexBegin();
//     graph.removeVertexByIter(it);
//     EXPECT_EQ(graph.vertexCount(), 2);
// }

// // Проверка на удаление ребра по итератору
// TEST_F(NonOrientedGraphTest, RemoveEdgeByIterator) {
//     auto it = graph.edgeBegin();
//     graph.removeEdgeByIter(it);
//     EXPECT_EQ(graph.edgeCount(), 1);
// }

// Проверка количества вершин и рёбер
TEST_F(NonOrientedGraphTest, VertexAndEdgeCount) {
    EXPECT_EQ(graph.vertexCount(), 3);
    EXPECT_EQ(graph.edgeCount(), 2);
}

// Проверка на степень вершины
TEST_F(NonOrientedGraphTest, VertexDegree) {
    EXPECT_EQ(graph.vertexDegree(2), 2);
    EXPECT_EQ(graph.vertexDegree(1), 1);
}

// Проверка степени ребра
TEST_F(NonOrientedGraphTest, EdgeDegree) {
    EXPECT_EQ(graph.edgeDegree(1, 2), 2);
}

// Проверка итератора вершин
TEST_F(NonOrientedGraphTest, VertexIterator) {
    auto it = graph.vertexBegin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}

// Проверка итератора рёбер
TEST_F(NonOrientedGraphTest, EdgeIterator) {
    auto it = graph.edgeBegin();
    auto edge = *it;
    EXPECT_EQ(edge.first, 1);
    EXPECT_EQ(edge.second, 2);
    ++it;
    edge = *it;
    EXPECT_EQ(edge.first, 2);
    EXPECT_EQ(edge.second, 3);
}

// Проверка итератора смежных вершин
TEST_F(NonOrientedGraphTest, AdjacentVertexIterator) {
    auto it = graph.adjacentBegin(2);
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 3);
}

// Проверка инцидентных рёбер
TEST_F(NonOrientedGraphTest, EdgeIncidentIterator) {
    auto it = graph.edgeIncidentBegin(2);
    auto edge = *it;
    EXPECT_EQ(edge.first, 2);
    EXPECT_EQ(edge.second, 1);
    ++it;
    edge = *it;
    EXPECT_EQ(edge.first, 2);
    EXPECT_EQ(edge.second, 3);
}

// Проверка на отсутствие существующей вершины
TEST_F(NonOrientedGraphTest, CheckVertex) {
    EXPECT_EQ(graph.checkVertex(4), "false");
    graph.addVertex(4);
    EXPECT_EQ(graph.checkVertex(4), "true");
}

// Проверка на отсутствие существующего ребра
TEST_F(NonOrientedGraphTest, CheckEdge) {
    EXPECT_EQ(graph.checkEdge(1, 3), "false");
    graph.addEdge(1, 3);
    EXPECT_EQ(graph.checkEdge(1, 3), "true");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}