#ifndef EDGEINCIDENTITERATOR_H
#define EDGEINCIDENTITERATOR_H
#include <unordered_set>

template <typename T>
class EdgeIncidentIterator {
public:
    EdgeIncidentIterator(typename std::unordered_set<T>::iterator it,
                         typename std::unordered_set<T>::iterator end, const T& vertex)
                             : current(it), end(end), vertex(vertex) {}
    explicit EdgeIncidentIterator(typename std::unordered_set<T>::iterator it, T vertex)
        : current(it), vertex(vertex) {}
    EdgeIncidentIterator& operator++();
    EdgeIncidentIterator& operator--();
    std::pair<T, T> operator*() const;
    bool operator==(const EdgeIncidentIterator& other) const;
    bool operator!=(const EdgeIncidentIterator& other) const;
private:
    typename std::unordered_set<T>::iterator current;
    typename std::unordered_set<T>::iterator end;
    T vertex;
};

#endif //EDGEINCIDENTITERATOR_H
