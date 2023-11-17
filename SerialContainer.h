#pragma once

class SerialContainer {
public:
    SerialContainer();
    ~SerialContainer() = default;
    SerialContainer(const SerialContainer &other); // Конструктор копирования
    SerialContainer(SerialContainer &&other) noexcept; // Конструктор перемещения

    // Методы работы с объектом
    void push_back(int data);
    void insert(int position, int data);
    void erase(int position);
    int size() const;

    // Перегрузки операторов
    int operator[](int element_number);
    SerialContainer& operator=(const SerialContainer& rhs); // оператор копирования

private:
    int *m_data;
    int m_size;
};