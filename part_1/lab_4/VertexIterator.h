#ifndef VERTEXITERATOR_H
#define VERTEXITERATOR_H
#include <map>
#include <set>

template <typename T>
class VertexIterator {
public:
    using MapIterator = typename std::map<T, std::set<T>>::iterator;

    VertexIterator(MapIterator it, MapIterator end_it)
        : current(it), end(end_it) {}

    VertexIterator& operator++() {
        if (current != end) {
            ++current;
        }
        return *this;
    }

    VertexIterator& operator--() {
        if (current != end) {
            --current;
        }
        return *this;
    }

    T operator*() const {
        return current->first;
    }

    bool operator==(const VertexIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const VertexIterator& other) const {
        return current != other.current;
    }

private:
    MapIterator current;
    MapIterator end;
};

#endif //VERTEXITERATOR_H