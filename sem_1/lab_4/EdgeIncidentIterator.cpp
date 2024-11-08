#include "EdgeIncidentIterator.h"

template <typename T>
EdgeIncidentIterator<T>& EdgeIncidentIterator<T>::operator++() {
    ++current;
    return *this;
}

template <typename T>
EdgeIncidentIterator<T>& EdgeIncidentIterator<T>::operator--() {
    --current;
    return *this;
}

template <typename T>
std::pair<T, T> EdgeIncidentIterator<T>::operator*() const {
    return {vertex, *current};
}

template <typename T>
bool EdgeIncidentIterator<T>::operator==(const EdgeIncidentIterator<T>& other) const {
    return current == other.current;
}

template <typename T>
bool EdgeIncidentIterator<T>::operator!=(const EdgeIncidentIterator<T>& other) const {
    return current != other.current;
}

