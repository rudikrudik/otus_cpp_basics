#pragma once

template<typename T>
class Iterator {
public:
    Iterator(T *node);
    ~Iterator() = default;

    bool operator!=(const Iterator<T> &other) const;
    Iterator<T> operator++();
    T& operator*();

    T *current;

};

template<typename T>
Iterator<T>::Iterator(T *node) {
    current = node;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &other) const {
    return current != other.current;
}

template<typename T>
typename Iterator<T> Iterator<T>::operator++() {
    current = current->pNext;
    return *this;
}

template<typename T>
T& Iterator<T>::operator*() {
    return current->data;
}