#include "AdjacentVertexIterator.h"

template <typename T>
AdjacentVertexIterator<T>& AdjacentVertexIterator<T>::operator++() {
    ++current;
    return *this;
}

template <typename T>
AdjacentVertexIterator<T>& AdjacentVertexIterator<T>::operator--() {
    --current;
    return *this;
}

template <typename T>
T AdjacentVertexIterator<T>::operator*() const {
    return *current;
}

template <typename T>
bool AdjacentVertexIterator<T>::operator==(const AdjacentVertexIterator<T>& other) const {
    return current == other.current;
}

template <typename T>
bool AdjacentVertexIterator<T>::operator!=(const AdjacentVertexIterator<T>& other) const {
    return current != other.current;
}

