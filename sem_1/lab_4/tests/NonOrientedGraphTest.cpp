#include <gtest/gtest.h>
#include "../NonOrientedGraph.h"

class NonOrientedGraphTest : public ::testing::Test {
protected:
    NonOrientedGraph<int> graph;

    void SetUp() override {
        // Создаем базовый граф для тестов
        graph.addVertex(1);
        graph.addVertex(2);
        graph.addVertex(3);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);
    }
};

TEST_F(NonOrientedGraphTest, AddVertexTest) {
    EXPECT_EQ(graph.checkVertex(1), "true");
    EXPECT_EQ(graph.checkVertex(4), "false");

    graph.addVertex(4);
    EXPECT_EQ(graph.checkVertex(4), "true");
}

TEST_F(NonOrientedGraphTest, AddEdgeTest) {
    EXPECT_EQ(graph.checkEdge(1, 2), "true");
    EXPECT_EQ(graph.checkEdge(1, 3), "false");

    graph.addEdge(1, 3);
    EXPECT_EQ(graph.checkEdge(1, 3), "true");
    EXPECT_EQ(graph.checkEdge(3, 1), "true"); // Проверка неориентированности
}

TEST_F(NonOrientedGraphTest, RemoveVertexTest) {
    graph.removeVertex(2);
    EXPECT_EQ(graph.checkVertex(2), "false");
    EXPECT_EQ(graph.checkEdge(1, 2), "false");
    EXPECT_EQ(graph.checkEdge(2, 3), "false");
}

TEST_F(NonOrientedGraphTest, RemoveEdgeTest) {
    graph.removeEdge(1, 2);
    EXPECT_EQ(graph.checkEdge(1, 2), "false");
    EXPECT_EQ(graph.checkEdge(2, 1), "false");
}

TEST_F(NonOrientedGraphTest, VertexCountTest) {
    EXPECT_EQ(graph.vertexCount(), 3);
    graph.addVertex(4);
    EXPECT_EQ(graph.vertexCount(), 4);
    graph.removeVertex(1);
    EXPECT_EQ(graph.vertexCount(), 3);
}

TEST_F(NonOrientedGraphTest, EdgeCountTest) {
    EXPECT_EQ(graph.edgeCount(), 2);
    graph.addEdge(1, 3);
    EXPECT_EQ(graph.edgeCount(), 3);
    graph.removeEdge(1, 2);
    EXPECT_EQ(graph.edgeCount(), 2);
}

TEST_F(NonOrientedGraphTest, VertexDegreeTest) {
    EXPECT_EQ(graph.vertexDegree(2), 2);
    EXPECT_EQ(graph.vertexDegree(1), 1);
    EXPECT_EQ(graph.vertexDegree(4), 0); // Несуществующая вершина
}

TEST_F(NonOrientedGraphTest, IteratorTest) {
    std::vector<int> vertices;
    for (auto it = graph.vertexBegin(); it != graph.vertexEnd(); ++it) {
        vertices.push_back(*it);
    }
    EXPECT_EQ(vertices.size(), 3);

    std::vector<std::pair<int, int>> edges;
    for (auto it = graph.edgeBegin(); it != graph.edgeEnd(); ++it) {
        edges.push_back(*it);
    }
    EXPECT_EQ(edges.size(), 3);
}

TEST_F(NonOrientedGraphTest, AdjacentVertexIteratorTest) {
    std::vector<int> adjacent;
    for (auto it = graph.adjacentBegin(2); it != graph.adjacentEnd(2); ++it) {
        adjacent.push_back(*it);
    }
    EXPECT_EQ(adjacent.size(), 2);
}

TEST_F(NonOrientedGraphTest, EdgeIncidentIteratorTest) {
    std::vector<std::pair<int, int>> incident;
    for (auto it = graph.edgeIncidentBegin(2); it != graph.edgeIncidentEnd(2); ++it) {
        incident.push_back(*it);
    }
    EXPECT_EQ(incident.size(), 2);
}