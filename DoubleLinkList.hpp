#pragma once

template <typename T>
class DoubleLinkedList{
public:
    DoubleLinkedList();
    DoubleLinkedList(const DoubleLinkedList &other);
    ~DoubleLinkedList();
    void push_back(T data);
    void push_front(T data);
    void insert(int position, T data);
    T pop_back();
    T pop_front();
    T erase(int position);
    int size() const;
    T& operator[](int index);
    DoubleLinkedList<T>& operator=(const DoubleLinkedList<T> &rhs);

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

    int s_size{};
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
    Iterator end() const;
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : s_size{0}, head{nullptr}, tail{nullptr} {}


template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> &other) : DoubleLinkedList<T>() {
    this->s_size = other.s_size;
    D_node *temp = nullptr;
    D_node *temp_prev = nullptr;

    for(D_node *ptr = other.head; ptr != nullptr; ptr = ptr->next){
        D_node *new_item = new D_node(ptr->data);
        if(head == nullptr){
            head = new_item;
            temp = head;
        }
        else{
            temp->next = new_item;
            new_item->prev = temp_prev;
            temp = new_item;
        }
        temp_prev = new_item;
    }
    tail = temp;
}

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
    if(head == nullptr){
        push_back(data);
    }
    else {
        head->prev = new_data;
        new_data->next = head;
        head = new_data;
        s_size++;
    }

}

template <typename T>
void DoubleLinkedList<T>::insert(int position, T data) {
    if(position < 0 || position >= s_size){
        return;
    }

    if(position == 0){
        return push_front(data);
    }
    if(position >= s_size - 1){
        return push_back(data);
    }

    D_node *current = head;

    while(position){
        current = current->next;
        position--;
    }

    D_node *temp = new D_node(data);

    temp->next = current;
    temp->prev = current->prev;
    current->prev->next = temp;
    s_size++;
}

template <typename T>
T DoubleLinkedList<T>::pop_back() {
    if (s_size == 1) {
        return pop_front();
    }
    else {
        D_node *temp = tail;
        T data = tail->data;
        tail = temp->prev;
        tail->next = nullptr;
        s_size--;
        delete temp;
        return data;
    }
}

template <typename T>
T DoubleLinkedList<T>::pop_front() {
    D_node *temp = head;
    T data = head->data;
    head = temp->next;
    s_size--;
    delete temp;
    return data;
}

template <typename T>
T DoubleLinkedList<T>::erase(int position) {
    if(position < 0 || position >= s_size){
        return 0;
    }

    if(position == 0){
        return pop_front();
    }
    if(position >= s_size -1){
        return pop_back();
    }

    D_node *current = head;
    while(position){
        current = current->next;
        position--;
    }

    D_node *temp = current;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    s_size--;
    return temp->data;
}

template <typename T>
int DoubleLinkedList<T>::size() const {return s_size;}

template <typename T>
T& DoubleLinkedList<T>::operator[](int index) {
    if(index < 0){
        return head->data;
    }
    if(index >= s_size -1){
        return tail->data;
    }
    D_node *current = this->head;
    while(index){
        current = current->next;
        index--;
    }
    return current->data;
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> &rhs) {
    DoubleLinkedList<T> temp{rhs};
    D_node *temp_head = head;
    D_node *temp_tail = tail;
    int temp_size = s_size;

    head = temp.head;
    tail = temp.tail;
    s_size = temp.s_size;

    temp.head = temp_head;
    temp.tail = temp_tail;
    temp.s_size = temp_size;

    return *this;
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
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::end() const {
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