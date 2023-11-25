#pragma once

class SinglyLinkedList{
public:
    SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList &other);
    ~SinglyLinkedList();

    int size() const;
    void push_back(int data);
    void insert(int position,int data);
    void erase(int position);
    // Перегрузка операторов
    int& operator[](int element);
    SinglyLinkedList& operator=(const SinglyLinkedList &rhs);

private:

    class Node{
    public:
        Node *pNext;
        int data;

        Node(int data, Node *pNext = nullptr){
            this->data = data;
            this->pNext = pNext;
        };

    };

    int s_size;
    Node *head;
};

// Реализация методов
SinglyLinkedList::SinglyLinkedList(): s_size{0}, head{nullptr} {}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &other) : SinglyLinkedList() {
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

SinglyLinkedList::~SinglyLinkedList(){
    while(s_size){
        Node *temp = head;
        head = head->pNext;
        delete temp;
        s_size--;
    }
}

int SinglyLinkedList::size() const {return s_size;}

void SinglyLinkedList::push_back(int data) {
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

void SinglyLinkedList::insert(int position, int data) {
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

void SinglyLinkedList::erase(int position) {
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

int& SinglyLinkedList::operator[](int element){
    Node *current = this->head;

    while(element){
        current = current->pNext;
        element--;
    }
    return current->data;
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList &rhs) {
    SinglyLinkedList temp{rhs};
    Node *temp_data = head;
    int temp_size = s_size;

    head = temp.head;
    s_size = temp.s_size;

    temp.head = temp_data;
    temp.s_size = temp_size;

    return *this;
}
