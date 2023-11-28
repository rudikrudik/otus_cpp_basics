#pragma once
#include <ostream>

template <typename T>
class IteratorMassive{
public:
    IteratorMassive(T *container);
    ~IteratorMassive() = default;

    IteratorMassive operator++();
    IteratorMassive operator++(int);
    T& operator*();
    bool operator!=(const IteratorMassive<T> &rhs) const;

private:
    T *ptr;
};

template<typename T>
IteratorMassive<T>::IteratorMassive(T *container) : ptr{container} {}

template<typename T>
IteratorMassive<T> IteratorMassive<T>::operator++() {
    ptr++;
    return *this;
}

template<typename T>
IteratorMassive<T> IteratorMassive<T>::operator++(int) {
    IteratorMassive<T> temp = *this;
    ptr++;
    return temp;
}

template<typename T>
T& IteratorMassive<T>::operator*() {
    return *ptr;
}

template<typename T>
bool IteratorMassive<T>::operator!=(const IteratorMassive<T> &rhs) const{
    return ptr != (rhs.ptr + 1);
}

