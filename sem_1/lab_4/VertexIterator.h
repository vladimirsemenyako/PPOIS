#ifndef VERTEXITERATOR_H
#define VERTEXITERATOR_H

#include <unordered_map>
#include <unordered_set>

template <typename T>
class VertexIterator {
public:
    VertexIterator(typename std::unordered_map<T, std::unordered_set<T>>::iterator it,
                   typename std::unordered_map<T, std::unordered_set<T>>::iterator end)
                    : current(it), end(end) {}
    explicit VertexIterator(typename std::unordered_map<T, std::unordered_set<T>>::iterator it) : current(it) {}
    VertexIterator& operator++();
    VertexIterator& operator--();
    T operator*() const;
    bool operator==(const VertexIterator& other) const;
    bool operator!=(const VertexIterator& other) const;
private:
    typename std::unordered_map<T, std::unordered_set<T>>::iterator current;
    typename std::unordered_map<T, std::unordered_set<T>>::iterator end;
};

#endif //VERTEXITERATOR_H
