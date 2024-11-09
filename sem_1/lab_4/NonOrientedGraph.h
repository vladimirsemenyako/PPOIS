#ifndef NON_ORIENTED_GRAPH_H
#define NON_ORIENTED_GRAPH_H

#include <map>
#include <set>
#include <string>
#include <iostream>

#include "AdjacentVertexIterator.h"
#include "EdgeIncidentIterator.h"
#include "EdgeIterator.h"
#include "VertexIterator.h"

template <typename T>
class NonOrientedGraph {
public:
    std::string checkVertex(const T& vertex) {
        return adj_list_.find(vertex) != adj_list_.end() ? "true" : "false";
    }

    std::string checkEdge(const T& vertex1, const T& vertex2) const {
        if (adj_list_.find(vertex1) != adj_list_.end()) {
            return adj_list_.at(vertex1).find(vertex2) != adj_list_.at(vertex1).end() ? "true" : "false";
        }
        return "false";
    }

    size_t vertexCount() {
        return adj_list_.size();
    }

    size_t edgeCount() {
        size_t count = 0;
        for (const auto& pair : adj_list_) {
            count += pair.second.size();
        }
        return count / 2;
    }

    int vertexDegree(const T& vertex) {
        if (adj_list_.find(vertex) != adj_list_.end()) {
            return adj_list_.at(vertex).size();
        }
        return 0;
    }

    int edgeDegree(const T& vertex1, const T& vertex2) {
        if (adj_list_.find(vertex1) != adj_list_.end() || adj_list_.find(vertex2) != adj_list_.end()) {
            return 0;
        }

        size_t vertex_degree1 = vertexDegree(vertex1);
        size_t vertex_degree2 = vertexDegree(vertex2);

        size_t total_degree = vertex_degree1 + vertex_degree2;

        if (adj_list_.at(vertex1).count(vertex2) > 0) {
            total_degree -= 1;
        }

        return total_degree;
    }

    void addVertex(const T& vertex) {
        if (adj_list_.find(vertex) == adj_list_.end()) {
            adj_list_[vertex] = std::set<T>();
        } else {
            std::cout << "There is already a vertex " << vertex << std::endl;
        }
    }

    void addEdge(const T& vertex1, const T& vertex2) {
        if (adj_list_.find(vertex1) != adj_list_.end() && adj_list_.find(vertex2) != adj_list_.end()) {
            adj_list_[vertex1].insert(vertex2);
            adj_list_[vertex2].insert(vertex1);
        }
    }

    void removeVertex(const T& vertex) {
        if (adj_list_.find(vertex) != adj_list_.end()) {
            for (const auto& adjacent : adj_list_[vertex]) {
                adj_list_[adjacent].erase(vertex);
            }
            adj_list_.erase(vertex);
        }
    }

    void removeVertexByIter(typename std::map<T, std::set<T>>::iterator it) {
        for (auto& neighbor : it->second) {
            auto neighborIt = adj_list_.find(neighbor);
            if (neighborIt != adj_list_.end()) {
                neighborIt->second.erase(it->first);
            }
        }
        adj_list_.erase(it);
    }

    void removeEdge(const T& vertex1, const T& vertex2) {
        if (adj_list_.find(vertex1) != adj_list_.end() && adj_list_[vertex1].find(vertex2) != adj_list_[vertex1].end()) {
            adj_list_[vertex1].erase(vertex2);
            adj_list_[vertex2].erase(vertex1);
        }
    }

    void removeEdgeByIter(typename std::map<std::pair<T, T>, bool>::iterator it) {
        T vertex1 = it->first.first;
        T vertex2 = it->first.second;

        adj_list_[vertex1].erase(vertex2);
        adj_list_[vertex2].erase(vertex1);

        edges.erase(it);
    }

    VertexIterator<T> vertexBegin() {
        return VertexIterator<T>(adj_list_.begin(), adj_list_.end());
    }

    VertexIterator<T> vertexEnd() {
        return VertexIterator<T>(adj_list_.end(), adj_list_.end());
    }

    EdgeIterator<T> edgeBegin() {
        return EdgeIterator<T>(adj_list_.begin(), adj_list_.end());
    }

    EdgeIterator<T> edgeEnd() {
        return EdgeIterator<T>(adj_list_.end(), adj_list_.end());
    }

    EdgeIncidentIterator<T> edgeIncidentBegin(const T& vertex) {
        auto it = adj_list_.find(vertex);
        if (it != adj_list_.end()) {
            return EdgeIncidentIterator<T>(it->second.begin(), it->second.end(), vertex);
        }
        return EdgeIncidentIterator<T>(std::set<T>().end(), std::set<T>().end(), vertex);
    }

    EdgeIncidentIterator<T> edgeIncidentEnd(const T& vertex) {
        auto it = adj_list_.find(vertex);
        if (it != adj_list_.end()) {
            return EdgeIncidentIterator<T>(it->second.end(), it->second.end(), vertex);
        }
        return EdgeIncidentIterator<T>(std::set<T>().end(), std::set<T>().end(), vertex);
    }

    AdjacentVertexIterator<T> adjacentBegin(const T& vertex) {
        auto it = adj_list_.find(vertex);
        if (it != adj_list_.end()) {
            return AdjacentVertexIterator<T>(it->second.begin(), it->second.end(), vertex);
        }
        return AdjacentVertexIterator<T>(std::set<T>().end(), std::set<T>().end(), vertex);
    }

    AdjacentVertexIterator<T> adjacentEnd(const T& vertex) {
        auto it = adj_list_.find(vertex);
        if (it != adj_list_.end()) {
            return AdjacentVertexIterator<T>(it->second.end(), it->second.end(), vertex);
        }
        return AdjacentVertexIterator<T>(std::set<T>().end(), std::set<T>().end(), vertex);
    }

private:
    std::map<T, std::set<T>> adj_list_;
    std::map<std::pair<T, T>, bool> edges;
};

#endif // NON_ORIENTED_GRAPH_H