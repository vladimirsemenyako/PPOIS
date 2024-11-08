#ifndef NON_ORIENTED_GRAPH_H
#define NON_ORIENTED_GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <string>

#include "AdjacentVertexIterator.h"
#include "EdgeIncidentIterator.h"
#include "EdgeIterator.h"
#include "VertexIterator.h"

struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Объединяем два хеша
        return h1 ^ (h2 << 1);  // или используйте другой метод комбинирования хешей
    }
};

template <typename T>
class NonOrientedGraph {
public:
    std::string checkVertex(const T& vertex);
    std::string checkEdge(const T& vertex1, const T& vertex2) const;
    size_t vertexCount();
    size_t edgeCount();
    int vertexDegree(const T& vertex);
    int edgeDegree(const T& vertex1, const T& vertex2);

    void addVertex(const T& vertex);
    void addEdge(const T& vertex1, const T& vertex2);
    void removeVertex(const T& vertex);
    void removeVertexByIter(typename std::unordered_map<T, std::unordered_set<T>>::iterator it);
    void removeEdge(const T& vertex1, const T& vertex2);
    void removeEdgeByIter(typename std::unordered_map<std::pair<T, T>, bool>::iterator it);

    VertexIterator<T> vertexBegin();
    VertexIterator<T> vertexEnd();
    EdgeIterator<T> edgeBegin();
    EdgeIterator<T> edgeEnd();
    EdgeIncidentIterator<T> edgeIncidentBegin(const T& vertex);
    EdgeIncidentIterator<T> edgeIncidentEnd(const T& vertex);
    AdjacentVertexIterator<T> adjacentBegin(const T& vertex);
    AdjacentVertexIterator<T> adjacentEnd(const T& vertex);

private:
    std::unordered_map<T, std::unordered_set<T>> adj_list_;
    std::unordered_map<std::pair<T, T>, bool, pair_hash> edges;
};

#endif // NON_ORIENTED_GRAPH_H