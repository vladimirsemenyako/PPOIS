#ifndef EDGE_ITERATOR_H
#define EDGE_ITERATOR_H

#include <map>
#include <set>
#include <utility>

template<typename T>
class EdgeIterator {
private:
    using EdgeSet = std::set<T>;
    using GraphMap = std::map<T, EdgeSet>;
    using MapIterator = typename GraphMap::iterator;
    MapIterator current;
    MapIterator end;

public:
    // Конструктор
    EdgeIterator(MapIterator it, MapIterator end_it)
        : current(it), end(end_it) {}

    // Операторы доступа и сравнения
    std::pair<T, T> operator*() const {
        if (current != end) {
            return std::make_pair(current->first, *(current->second.begin()));
        }
        return std::make_pair(T(), T());
    }

    EdgeIterator& operator++() {
        if (current != end) {
            ++current;
        }
        return *this;
    }

    EdgeIterator& operator--() {
        if (current != end) {
            --current;
        }
        return *this;
    }

    bool operator==(const EdgeIterator &other) const {
        return current == other.current;
    }

    bool operator!=(const EdgeIterator &other) const {
        return current != other.current;
    }
};

#endif // EDGE_ITERATOR_H