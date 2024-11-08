#include "NonOrientedGraph.h"

#include <iostream>

template <typename T>
std::string NonOrientedGraph<T>::checkVertex(const T& vertex) {
    return adj_list_.find(vertex) != adj_list_.end() ? "true" : "false";
}

template <typename T>
std::string NonOrientedGraph<T>::checkEdge(const T& vertex1, const T& vertex2) const {
    if (adj_list_.find(vertex1) != adj_list_.end()) {
        return adj_list_.at(vertex1).find(vertex2) != adj_list_.at(vertex1).end() ? "true" : "false";
    }
    return "false";
}

template <typename T>
size_t NonOrientedGraph<T>::vertexCount() {
    return adj_list_.size();
}

template <typename T>
size_t NonOrientedGraph<T>::edgeCount() {
    size_t count = 0;
    for (const auto& pair : adj_list_) {
        count += pair.second.size();
    }
    return count / 2;
}

template <typename T>
int NonOrientedGraph<T>::vertexDegree(const T& vertex) {
    if (adj_list_.find(vertex) != adj_list_.end()) {
        return adj_list_.at(vertex).size();
    }
    return 0;
}

template <typename T>
int NonOrientedGraph<T>::edgeDegree(const T& vertex1, const T& vertex2) {
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

template <typename T>
void NonOrientedGraph<T>::addVertex(const T& vertex) {
    if (adj_list_.find(vertex) == adj_list_.end()) {
        adj_list_[vertex] = {};
    } else {
        std::cout << "There is already a vertex " << vertex << std::endl;
    }
}

template <typename T>
void NonOrientedGraph<T>::addEdge(const T& vertex1, const T& vertex2) {
    if (adj_list_.find(vertex1) != adj_list_.end() && adj_list_.find(vertex2) != adj_list_.end()) {
        adj_list_[vertex1].insert(vertex2);
        adj_list_[vertex2].insert(vertex1);
    }
}

template <typename T>
void NonOrientedGraph<T>::removeVertex(const T& vertex) {
    if (adj_list_.find(vertex) != adj_list_.end()) {
        for (const auto& adjacent : adj_list_[vertex]) {
            adj_list_[adjacent].erase(vertex);
        }
        adj_list_.erase(vertex);
    }
}

template <typename T>
void NonOrientedGraph<T>::removeVertexByIter(typename std::unordered_map<T, std::unordered_set<T>>::iterator it) {
    for (auto& neighbor : it->second) {
        auto neighborIt = adj_list_.find(neighbor);
        if (neighborIt != adj_list_.end()) {
            neighborIt->second.erase(it->first);
        }
    }
    adj_list_.erase(it);
}

template <typename T>
void NonOrientedGraph<T>::removeEdge(const T& vertex1, const T& vertex2) {
    if (adj_list_.find(vertex1) != adj_list_.end() && adj_list_[vertex1].find(vertex2) != adj_list_[vertex1].end()) {
        adj_list_[vertex1].erase(vertex2);
        adj_list_[vertex2].erase(vertex1);
    }
}

template <typename T>
void NonOrientedGraph<T>::removeEdgeByIter(typename std::unordered_map<std::pair<T, T>, bool>::iterator it) {
    T vertex1 = it->first.first;
    T vertex2 = it->first.second;

    adj_list_[vertex1].erase(vertex2);
    adj_list_[vertex2].erase(vertex1);

    edges.erase(it);
}

// Итераторы
template <typename T>
VertexIterator<T> NonOrientedGraph<T>::vertexBegin() { return VertexIterator<T>(adj_list_.begin(), adj_list_.end()); }

template <typename T>
VertexIterator<T> NonOrientedGraph<T>::vertexEnd() { return VertexIterator<T>(adj_list_.end(), adj_list_.end()); }

template <typename T>
EdgeIterator<T> NonOrientedGraph<T>::edgeBegin() { return EdgeIterator<T>(adj_list_.begin(), adj_list_.end()); }

template <typename T>
EdgeIterator<T> NonOrientedGraph<T>::edgeEnd() { return EdgeIterator<T>(adj_list_.end(), adj_list_.end()); }

template <typename T>
EdgeIncidentIterator<T> NonOrientedGraph<T>::edgeIncidentBegin(const T& vertex) {
    auto it = adj_list_.find(vertex);
    if (it != adj_list_.end()) {
        return EdgeIncidentIterator<T>(it->second.begin(), it->second.end(), vertex);
    }
    return EdgeIncidentIterator<T>(adj_list_.end(), adj_list_.end(), vertex);
}

template <typename T>
EdgeIncidentIterator<T> NonOrientedGraph<T>::edgeIncidentEnd(const T& vertex) {
    auto it = adj_list_.find(vertex);
    if (it != adj_list_.end()) {
        return EdgeIncidentIterator<T>(it->second.end(), it->second.end(), vertex);
    }
    return EdgeIncidentIterator<T>(adj_list_.end(), adj_list_.end(), vertex);
}

template <typename T>
AdjacentVertexIterator<T> NonOrientedGraph<T>::adjacentBegin(const T& vertex) {
    auto it = adj_list_.find(vertex);
    if (it != adj_list_.end()) {
        return AdjacentVertexIterator<T>(it->second.begin(), it->second.end(), vertex);
    }
    return AdjacentVertexIterator<T>(adj_list_.end(), adj_list_.end(), vertex);
}

template <typename T>
AdjacentVertexIterator<T> NonOrientedGraph<T>::adjacentEnd(const T& vertex) {
    auto it = adj_list_.find(vertex);
    if (it != adj_list_.end()) {
        return AdjacentVertexIterator<T>(it->second.end(), it->second.end(), vertex);
    }
    return AdjacentVertexIterator<T>(adj_list_.end(), adj_list_.end(), vertex);
}

