#pragma once
#include "ostream"

template<typename T>
class IteratorList {
public:
    IteratorList(T *node);
    ~IteratorList() = default;

    bool operator!=(const IteratorList<T> &other) const;
    IteratorList<T> operator++();
    int& operator*();

    T *current;

};

template<typename T>
IteratorList<T>::IteratorList(T *node) {
    current = node;
}

template<typename T>
bool IteratorList<T>::operator!=(const IteratorList<T> &other) const {
    return current != other.current;
}

template<typename T>
IteratorList<T> IteratorList<T>::operator++() {
    current = current->pNext;
    return *this;
}

template<typename T>
int& IteratorList<T>::operator*() {
    return current->data;
}