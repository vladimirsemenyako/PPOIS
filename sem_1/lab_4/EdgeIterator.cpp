#include "EdgeIterator.h"

template<typename T>
std::pair<T, T> EdgeIterator<T>::operator*() const {
    return *current->second.begin();
}

template<typename T>
EdgeIterator<T> &EdgeIterator<T>::operator++() {
    ++current;
    return *this;
}

template<typename T>
EdgeIterator<T> &EdgeIterator<T>::operator--() {
    --current;
    return *this;
}

template<typename T>
bool EdgeIterator<T>::operator==(const EdgeIterator &other) const {
    return current == other.current;
}

template<typename T>
bool EdgeIterator<T>::operator!=(const EdgeIterator &other) const {
    return current != other.current;
}




