#pragma once
#include "SerialContaineriterator.hpp"

template<typename T>
class SerialContainer {
public:
    //friend class IteratorMassive<T>;

    SerialContainer();
    SerialContainer(const SerialContainer &other); // Конструктор копирования
    SerialContainer(SerialContainer &&other) noexcept; // Конструктор перемещения
    ~SerialContainer();

    // Методы работы с объектом
    void push_back(T data);
    void insert(int position, T data);
    void erase(int position);
    int size() const;

    // Перегрузки операторов
    T& operator[](int element_number);
    SerialContainer<T>& operator=(const SerialContainer &rhs); // оператор копирования

    // Методы итератора
    IteratorMassive<T> begin() const;
    IteratorMassive<T> end() const;

private:
    T *m_data;
    int m_size;
};


// Реализация методов
template<typename T>
SerialContainer<T>::SerialContainer() : m_data{nullptr}, m_size{0} {}

template<typename T>
SerialContainer<T>::~SerialContainer() {delete [] m_data;}

template<typename T>
SerialContainer<T>::SerialContainer(const SerialContainer &other) : SerialContainer(){
    this->m_size = other.m_size;
    this->m_data = new T[other.m_size];

    for(int i = 0; i < other.m_size; i++){
        this->m_data[i] = other.m_data[i];
    }
} // Конструктор копирования

template<typename T>
SerialContainer<T>::SerialContainer(SerialContainer &&other)  noexcept{
    m_data = other.m_data;
    other.m_data = nullptr;
    m_size = other.m_size;
    other.m_size = 0;
} // Конструктор перемещения

template<typename T>
void SerialContainer<T>::push_back(T data) {
    T *new_memory = new T[m_size + 1];
    for(int i = 0; i < m_size; i++){
        new_memory[i] = m_data[i];
    }
    new_memory[m_size] = data;
    delete [] m_data;
    m_data = new_memory;
    m_size++;
}

template<typename T>
void SerialContainer<T>::insert(int position, T data) {
    if(position > m_size)
        return;

    T *new_memory = new T[m_size + 1];
    m_size++;
    T *ptr = m_data;

    for(int i = 0; i < m_size; i++, ptr++){
        if(i == position){
            new_memory[i] = data;
            ptr--;
        }
        else{
            new_memory[i] = *ptr;
        }
    }
    delete [] m_data;
    m_data = new_memory;
}

template<typename T>
void SerialContainer<T>::erase(int position){
    if(position > m_size)
        return;

    T *new_memory = new T[m_size - 1];
    T *ptr = m_data;

    for(int i = 0; i < m_size; i++, ptr++){
        if(i == position){
            ptr++;
            new_memory[i] = *ptr;
        }
        else{
            new_memory[i] = *ptr;
        }
    }
    delete [] m_data;
    m_data = new_memory;
    m_size--;
}

template<typename T>
int SerialContainer<T>::size() const {
    return m_size;
}

template<typename T>
T& SerialContainer<T>::operator[](int element_number){
    return m_data[element_number];
} // Перегрузка оператора [] для доступа к элементу по индексу

template<typename T>
SerialContainer<T>& SerialContainer<T>::operator=(const SerialContainer &rhs){
    SerialContainer<T> temp{rhs};

    T *ptr = m_data;
    m_data = temp.m_data;
    temp.m_data = ptr;

    int size = m_size;
    m_size = temp.m_size;
    temp.m_size = size;

    return *this;
}// Перегрузка оператора копирования


// Методы итератора
template<typename T>
IteratorMassive<T> SerialContainer<T>::begin() const
{
    return IteratorMassive(this->m_data);
}

template<typename T>
IteratorMassive<T> SerialContainer<T>::end() const
{
    return IteratorMassive(this->m_data + (this->m_size - 1));
}