#pragma once
#include "SerialContaineriterator.hpp"

template <typename T>
class SerialContainerMR{
public:
    SerialContainerMR();
    SerialContainerMR(const SerialContainerMR &other);
    ~SerialContainerMR();

    int size();
    int capacity();
    void push_back(T data);
    void insert(int position, T data);
    void erase(int position);
    T& operator[](int element_number);
    SerialContainerMR<T>& operator=(const SerialContainerMR &rhs);

    // Методы итератора
    IteratorMassive<T> begin() const;
    IteratorMassive<T> end() const;

private:
    void add_mem();

    T *m_data;
    int m_size;
    int m_mem;

};

// Реализация методов
template <typename T>
SerialContainerMR<T>::SerialContainerMR() : m_data{nullptr}, m_size{0} {
    m_data = new T[1];
    m_mem = 1;
}

template <typename T>
SerialContainerMR<T>::SerialContainerMR(const SerialContainerMR<T> &other) : SerialContainerMR(){
    int capacity = 2;
    while(capacity < other.m_size){
        capacity *= 2;
    }

    this->m_size = other.m_size;
    this->m_data = new T[capacity];
    this->m_mem = capacity;

    for(int i = 0; i < m_size; i++){

        this->m_data[i] = other.m_data[i];
        this->m_mem--;
    }
}

template <typename T>
SerialContainerMR<T>::~SerialContainerMR() {
    delete m_data;
    m_data = nullptr;
}

template <typename T>
int SerialContainerMR<T>::size() {
    return m_size;
}

template <typename T>
int SerialContainerMR<T>::capacity() {
    return m_mem;
}

template <typename T>
void SerialContainerMR<T>::add_mem() {
    T *temp = new T[m_size * 2];

    for(int i = 0; i < m_size; i++){
        temp[i] = m_data[i];
    }
    delete m_data;
    m_data = nullptr;
    m_mem = m_size;
    m_data = temp;
}

template <typename T>
void SerialContainerMR<T>::push_back(T data) {
    if(!m_mem){
        add_mem();
    }
    m_data[m_size] = data;
    m_mem--;
    m_size++;
}

template <typename T>
void SerialContainerMR<T>::insert(int position, T data) {
    if(position < 0 || position > m_size){ return; }

    if(!m_mem){
        add_mem();
    }

    for(int i = m_size; i > position; i--){
        m_data[i] = m_data[i -1];
    }
    m_data[position] = data;
    m_size++;
    m_mem--;
}

template <typename T>
void SerialContainerMR<T>::erase(int position) {
    if(position < 0 || position > m_size){ return; }

    for(int i = position; i < m_size; i++){
        m_data[i] = m_data[i + 1];
    }

    m_size--;
    m_mem++;
}

template <typename T>
T& SerialContainerMR<T>::operator[](int element_number) {
    if(element_number < 0){
        return m_data[0];
    }
    if(element_number > m_size -1){
        return m_data[m_size -1];
    }

    return m_data[element_number];
}

template <typename T>
SerialContainerMR<T>& SerialContainerMR<T>::operator=(const SerialContainerMR<T> &rhs) {
    SerialContainerMR<T> temp{rhs};

    T *ptr_data = m_data;
    m_data = temp.m_data;
    temp.m_data = ptr_data;

    int temp_size = m_size;
    m_size = temp.m_size;
    temp.m_size = temp_size;

    int temp_cap = m_mem;
    m_mem = temp.m_mem;
    temp.m_mem = temp_cap;

    return *this;
}

// Реализация методов итератора
template <typename T>
IteratorMassive<T> SerialContainerMR<T>::begin() const {
    return m_data;
}

template <typename T>
IteratorMassive<T> SerialContainerMR<T>::end() const {
    return m_data + (m_size -1);
}