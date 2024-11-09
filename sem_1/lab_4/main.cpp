#include <iostream>
#include "NonOrientedGraph.h"

// In Main.cpp there is example of working this program as a some sort of framework.

int main () {
    // // Создаём объект графа
    // NonOrientedGraph<int> graph;
    //
    // // Добавляем вершины
    // std::cout << "Добавляем вершины 1, 2, 3, 4\n";
    // graph.addVertex(1);
    // graph.addVertex(2);
    // graph.addVertex(3);
    // graph.addVertex(4);
    //
    // // Добавляем рёбра
    // std::cout << "Добавляем рёбра (1, 2), (2, 3), (3, 4), (4, 1)\n";
    // graph.addEdge(1, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 4);
    // graph.addEdge(4, 1);
    //
    // // Проверка наличия вершин и рёбер
    // std::cout << "Проверка наличия вершины 2: " << graph.checkVertex(2) << "\n";
    // std::cout << "Проверка наличия вершины 5: " << graph.checkVertex(5) << "\n";
    // std::cout << "Проверка наличия ребра (1, 2): " << graph.checkEdge(1, 2) << "\n";
    // std::cout << "Проверка наличия ребра (2, 4): " << graph.checkEdge(2, 4) << "\n";
    //
    // // Подсчет вершин и рёбер
    // std::cout << "Количество вершин в графе: " << graph.vertexCount() << "\n";
    // std::cout << "Количество рёбер в графе: " << graph.edgeCount() << "\n";
    //
    // // Степень вершины
    // std::cout << "Степень вершины 2: " << graph.vertexDegree(2) << "\n";
    //
    // // Итератор вершин
    // std::cout << "\nИтерация по вершинам:\n";
    // for (auto it = graph.vertexBegin(); it != graph.vertexEnd(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n";
    //
    // // Итератор рёбер
    // std::cout << "\nИтерация по рёбрам:\n";
    // for (auto it = graph.edgeBegin(); it != graph.edgeEnd(); ++it) {
    //     auto edge = *it;
    //     std::cout << "(" << edge.first << ", " << edge.second << ") ";
    // }
    // std::cout << "\n";
    //
    // // Инцидентные рёбра для вершины 2
    // std::cout << "\nИнцидентные рёбра для вершины 2:\n";
    // for (auto it = graph.edgeIncidentBegin(2); it != graph.edgeIncidentEnd(2); ++it) {
    //     auto edge = *it;
    //     std::cout << "(" << edge.first << ", " << edge.second << ") ";
    // }
    // std::cout << "\n";
    //
    // // Смежные вершины для вершины 2
    // std::cout << "\nСмежные вершины для вершины 2:\n";
    // for (auto it = graph.adjacentBegin(2); it != graph.adjacentEnd(2); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n";
    //
    // // Удаление вершины и ребра
    // std::cout << "\nУдаляем вершину 3 и ребро (1, 2)\n";
    // graph.removeVertex(3);
    // graph.removeEdge(1, 2);
    //
    // // Итерация по вершинам и рёбрам после удаления
    // std::cout << "Вершины после удаления:\n";
    // for (auto it = graph.vertexBegin(); it != graph.vertexEnd(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n";
    //
    // std::cout << "Рёбра после удаления:\n";
    // for (auto it = graph.edgeBegin(); it != graph.edgeEnd(); ++it) {
    //     auto edge = *it;
    //     std::cout << "(" << edge.first << ", " << edge.second << ") ";
    // }
    // std::cout << "\n";
    //
    return 0;
}
