#ifndef EDGEITERATOR_H
#define EDGEITERATOR_H
#include <unordered_map>
#include <unordered_set>
template <typename T>
class EdgeIterator {
public:
    EdgeIterator(typename std::unordered_map<T, std::unordered_set<T>>::iterator it,
                 typename std::unordered_map<T, std::unordered_set<T>>::iterator end)
    : current(it), end(end) {}

    using MapIterator = typename std::unordered_map<T, std::unordered_set<T>>::iterator;
    using SetIterator = typename std::unordered_set<T>::iterator;

    explicit EdgeIterator(MapIterator current) : current(current) {}

    EdgeIterator& operator++();
    EdgeIterator& operator--();

    std::pair<T, T> operator*() const;

    bool operator==(const EdgeIterator& other) const;

    bool operator!=(const EdgeIterator& other) const;

private:
    typename std::unordered_map<T, std::unordered_set<T>>::iterator current;
    typename std::unordered_map<T, std::unordered_set<T>>::iterator end;
};

#endif //EDGEITERATOR_H
