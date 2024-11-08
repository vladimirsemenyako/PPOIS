#include "VertexIterator.h"

template <typename T>
T VertexIterator<T>::operator*() const {
    return current->first;
}

template <typename T>
VertexIterator<T> &VertexIterator<T>::operator++() {
    ++current;
    return *this;
}

template<typename T>
VertexIterator<T> &VertexIterator<T>::operator--() {
    --current;
    return *this;
}

template<typename T>
bool VertexIterator<T>::operator==(const VertexIterator &other) const {
    return current == other.current;
}

template<typename T>
bool VertexIterator<T>::operator!=(const VertexIterator &other) const {
    return current != other.current;
}


