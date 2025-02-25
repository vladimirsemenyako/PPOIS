#ifndef EDGEINCIDENTITERATOR_H
#define EDGEINCIDENTITERATOR_H
#include <set>

template <typename T>
class EdgeIncidentIterator {
public:
    using SetIterator = typename std::set<T>::iterator;

    EdgeIncidentIterator(SetIterator it, SetIterator end_it, const T& v)
        : current(it), end(end_it), vertex(v) {}

    EdgeIncidentIterator& operator++() {
        if (current != end) {
            ++current;
        }
        return *this;
    }

    EdgeIncidentIterator& operator--() {
        if (current != end) {
            --current;
        }
        return *this;
    }

    std::pair<T, T> operator*() const {
        return std::make_pair(vertex, *current);
    }

    bool operator==(const EdgeIncidentIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const EdgeIncidentIterator& other) const {
        return current != other.current;
    }

private:
    SetIterator current;
    SetIterator end;
    T vertex;
};

#endif //EDGEINCIDENTITERATOR_H