#include <iostream>
#include "SerialContainer.h"

SerialContainer::SerialContainer() : m_data{nullptr}, m_size{0} {}

void SerialContainer::push_back(int data) {
    int *new_memory = new int[m_size + 1];
    for(int i = 0; i < m_size; i++){
        new_memory[i] = m_data[i];
    }
    new_memory[m_size] = data;
    delete [] m_data;
    m_data = new_memory;
    m_size++;
}

void SerialContainer::insert(int position, int data) {
    if(position > m_size)
        return;

    int *new_memory = new int[m_size + 1];
    m_size++;

    for(int i = 0, *ptr = m_data; i < m_size; i++, ptr++){
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

void SerialContainer::erase(int position){
    if(position > m_size)
        return;

    int *new_memory = new int[m_size - 1];

    for(int i = 0, *ptr = m_data; i < m_size; i++, ptr++){
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

int SerialContainer::size() const {
    return m_size;
}

int SerialContainer::operator[](int element_number){
    return *(m_data + element_number);
} // Перегрузка оператора [] для доступа к элементу по индексу
