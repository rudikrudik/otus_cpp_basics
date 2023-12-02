#pragma once

template <typename T>
class DoubleLinkedList{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    //~DoubleLinkedList();
    void push_back(T data);
    void push_front(T data);
    T pop_back();
    T pop_front();
    int size() const;
    T& operator[](int index);

private:
    class D_node{
    public:
        D_node *prev;
        D_node *next;
        T data;

        D_node(T data, D_node *prev = nullptr, D_node *next = nullptr){
            this->prev = prev;
            this->next = next;
            this->data = data;
        }
    };

    int s_size;
    D_node *head;
    D_node *tail;

public:
    class Iterator{
    public:
        Iterator(D_node *d_node);
        bool operator!=(const Iterator &other) const;
        Iterator operator++();
        Iterator operator++(int);
        T& operator*();
    private:
        D_node *current;
    };

    // Объявление методов итератора
    Iterator begin() const;
    Iterator rbegin() const;
    Iterator end() const;
    Iterator rend() const;

};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : s_size{0}, head{nullptr}, tail{nullptr} {}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    while(s_size){
        pop_front();
    }
}

template <typename T>
void DoubleLinkedList<T>::push_back(T data) {
    if(head == nullptr){
        head = new D_node(data);
    }
    else{
        if(tail == nullptr){
            tail = new D_node(data);
            tail->prev = head;
            head->next = tail;
        }
        else {
            D_node *new_node = new D_node(data);
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    s_size++;
}

template <typename T>
void DoubleLinkedList<T>::push_front(T data) {
    D_node *new_data = new D_node(data);
    head->prev = new_data;
    new_data->next = head;
    head = new_data;
    s_size++;
}

template <typename T>
T DoubleLinkedList<T>::pop_back() {
    D_node *temp = tail;
    tail = temp->prev;
    tail->next = nullptr;
    s_size--;
    return temp->data;
}

template <typename T>
T DoubleLinkedList<T>::pop_front() {
    D_node *temp = head;
    head = temp->next;
    head->prev = nullptr;
    s_size--;
    return temp->data;
}

template <typename T>
int DoubleLinkedList<T>::size() const {return s_size;}

template <typename T>
T& DoubleLinkedList<T>::operator[](int index) {
    D_node *current = this->head;
    while(index){
        current = current->next;
        index--;
    }
    return current->data;
}

//Методы итератора
template <typename T>
DoubleLinkedList<T>::Iterator::Iterator(D_node *d_node) {
    current = d_node;
}

template <typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::begin() const {
    return Iterator(this->head);
}

template <typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::rbegin() const{
    return Iterator(this->tail);
}

template <typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::end() const {
    return Iterator(nullptr);
}

template <typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::rend() const {
    return Iterator(nullptr);
}

template <typename T>
bool DoubleLinkedList<T>::Iterator::operator!=(const DoubleLinkedList<T>::Iterator &other) const {
    return current != other.current;
}

template <typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::Iterator::operator++() {
    current = current->next;
    return current;
}

template <typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::Iterator::operator++(int) {
    D_node *temp = current;
    current = current->next;
    return temp;
}

template <typename T>
T& DoubleLinkedList<T>::Iterator::operator*() {
    return current->data;
}