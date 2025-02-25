    #ifndef ADJACENTVERTEXITERATOR_H
#define ADJACENTVERTEXITERATOR_H
#include <set>

template <typename T>
class AdjacentVertexIterator {
public:
    using SetIterator = typename std::set<T>::iterator;

    AdjacentVertexIterator(SetIterator it, SetIterator end_it, const T& v)
        : current(it), end(end_it), vertex(v) {}

    AdjacentVertexIterator& operator++() {
        if (current != end) {
            ++current;
        }
        return *this;
    }

    AdjacentVertexIterator& operator--() {
        if (current != end) {
            --current;
        }
        return *this;
    }

    T operator*() const {
        return *current;
    }

    bool operator==(const AdjacentVertexIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const AdjacentVertexIterator& other) const {
        return current != other.current;
    }

private:
    SetIterator current;
    SetIterator end;
    T vertex;
};

#endif //ADJACENTVERTEXITERATOR_H