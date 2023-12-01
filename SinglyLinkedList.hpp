#pragma once

template <typename T>
class SinglyLinkedList{
public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList<T> &other);
    ~SinglyLinkedList();

    int size() const;
    void push_back(T data);
    void insert(int position, T data);
    void erase(int position);
    // Перегрузка операторов
    T& operator[](int element);
    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T> &rhs);

private:

    class Node{
    public:
        Node *pNext;
        T data;

        Node(T data, Node *pNext = nullptr){
            this->data = data;
            this->pNext = pNext;
        };

    };

    int s_size;
    Node *head;

public:
    class Iterator {
    public:
        Iterator(Node *node);
        ~Iterator() = default;

        bool operator!=(const Iterator &other) const;
        Iterator operator++();
        T& operator*();
    private:
        Node *current;

    };

public:
    Iterator begin() const;
    Iterator end() const;
};


// Реализация методов
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(): s_size{0}, head{nullptr} {}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T> &other) : SinglyLinkedList<T>() {
    this->s_size = other.s_size;
    Node *temp = nullptr;
    for(Node *p = other.head;  p!= nullptr; p = p->pNext){
        Node *new_item = new Node(p->data);
        if(!head){
            head = new_item;
        }
        else{
            temp->pNext = new_item;
        }
        temp = new_item;
    }
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList<T>(){
    while(s_size){
        Node *temp = head;
        head = head->pNext;
        delete temp;
        s_size--;
    }
}

template <typename T>
int SinglyLinkedList<T>::size() const {return s_size;}

template <typename T>
void SinglyLinkedList<T>::push_back(T data) {
    if(head == nullptr){
        head = new Node(data);
    }
    else{
        Node *current = this->head;
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    s_size++;
}

template <typename T>
void SinglyLinkedList<T>::insert(int position, T data) {
    if(position > s_size -1){
        push_back(data);
        return;
    }

    Node *current = this->head;
    Node *newData = new Node(data);

    if(position == 0){
        head = newData;
        head->pNext = current;
    }
    else{
        while(position - 1){
            current = current->pNext;
            position--;
        }
        newData->pNext = current->pNext;
        current->pNext = newData;
    }
    s_size++;
}

template <typename T>
void SinglyLinkedList<T>::erase(int position) {
    Node *prev = this->head;

    if(position == 0){
        head = prev->pNext;
    }
    else {
        for (int i = 0; i < position - 1; i++) {
            prev = prev->pNext;
        }

        Node *temp = prev->pNext;
        prev->pNext = temp->pNext;
        delete temp;
    }
    s_size--;
}

template <typename T>
T& SinglyLinkedList<T>::operator[](int element){
    Node *current = this->head;

    while(element){
        current = current->pNext;
        element--;
    }
    return current->data;
}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T> &rhs) {
    SinglyLinkedList<T> temp{rhs};
    Node *temp_data = head;
    int temp_size = s_size;

    head = temp.head;
    s_size = temp.s_size;

    temp.head = temp_data;
    temp.s_size = temp_size;

    return *this;
}

// Реализация методов итератора

template<typename T>
SinglyLinkedList<T>::Iterator::Iterator(Node *node) {
    current = node;
}

template<typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::begin() const {
    return Iterator(this->head);
}

template<typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::end() const {
    return Iterator(nullptr);
}


template<typename T>
bool SinglyLinkedList<T>::Iterator::operator!=(const Iterator &other) const {
    return current != other.current;
}

template<typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator::operator++() {
    current = current->pNext;
    return *this;
}

template<typename T>
T& SinglyLinkedList<T>::Iterator::operator*() {
    return current->data;
}