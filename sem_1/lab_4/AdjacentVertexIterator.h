#ifndef ADJACENTVERTEXITERATOR_H
#define ADJACENTVERTEXITERATOR_H
#include <unordered_set>
template <typename T>
class AdjacentVertexIterator {
public:
    AdjacentVertexIterator(typename std::unordered_set<T>::iterator it,
                           typename std::unordered_set<T>::iterator end, const T& vertex)
                    : current(it), end(end), vertex(vertex) {}
    explicit AdjacentVertexIterator(typename std::unordered_set<T>::iterator it) : current(it) {}
    AdjacentVertexIterator& operator++();
    AdjacentVertexIterator& operator--();
    T operator*() const;
    bool operator==(const AdjacentVertexIterator& other) const;
    bool operator!=(const AdjacentVertexIterator& other) const;
private:
    typename std::unordered_set<T>::iterator current;
    typename std::unordered_set<T>::iterator end;
    T vertex;

};

#endif //ADJACENTVERTEXITERATOR_H
