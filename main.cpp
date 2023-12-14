#include <iostream>
#include "SerialContainer.hpp"
#include "SerialContainerMemReserve.hpp"
#include "SinglyLinkedList.hpp"
#include "DoubleLinkList.hpp"


void SerialContainerExample();
void SerialContainerMemReserveExample();
void SinglyLinkedListExample();
void DoubleLinkListExample();

int main() {
    SerialContainerExample(); // Вызов функции с примером работы последовательного контейнера
    SerialContainerMemReserveExample();
    SinglyLinkedListExample();
    DoubleLinkListExample();

    return 0;
}

template <typename T>
void SerialContainerPrint(T& serial){
    for(auto iter = serial.begin(); iter != serial.end(); ++iter){
        std::cout << *iter << ' ';
    }
} // Вспомогательная функция вывода содержимого контейнера

void SerialContainerExample(){
    std::cout << "Serial Container Example" << std::endl << std::endl;

    SerialContainer serialOne = SerialContainer<int>(); // Создаем объект последовательного контейнера

    for(int i = 0; i < 10; i++){
        serialOne.push_back(i);
    } // Заполняем контейнер числами от 0 до 9

    std::cout << "Add numbers" << std::endl;
    std::cout << "Expected: 0 1 2 3 4 5 6 7 8 9" << std::endl;
    std::cout << "Result: ";
    SerialContainerPrint(serialOne);
    std::cout << std::endl << std::endl;

    std::cout << "Object serialOne size"<< std::endl;
    std::cout << "Expected: 10" << std::endl;
    std::cout << "Result: ";
    std::cout << serialOne.size() << std::endl << std::endl; // Размер контейнера

    std::cout << "Delete some numbers" << std::endl;
    std::cout << "Expected: 0 1 3 5 7 8 9" << std::endl;
    serialOne.erase(2); serialOne.erase(3); serialOne.erase(4); // Удаление 3, 5, 7, элемента
    std::cout << "Result: ";
    SerialContainerPrint(serialOne);
    std::cout << std::endl << std::endl;

    std::cout << "Add number 10 to start container" << std::endl;
    std::cout << "Expected: 10 0 1 3 5 7 8 9" << std::endl;
    serialOne.insert(0, 10);
    std::cout << "Result: ";
    SerialContainerPrint(serialOne);
    std::cout << std::endl << std::endl;

    std::cout << "Add number 20 to middle container" << std::endl;
    std::cout << "Expected: 10 0 1 3 20 5 7 8 9" << std::endl;
    serialOne.insert(4, 20);
    std::cout << "Result: ";
    SerialContainerPrint(serialOne);
    std::cout << std::endl << std::endl;

    std::cout << "Add number 30 to end container" << std::endl;
    std::cout << "Expected: 10 0 1 3 20 5 7 8 9 30" << std::endl;
    serialOne.push_back(30);
    std::cout << "Result: ";
    SerialContainerPrint(serialOne);
    std::cout << std::endl << std::endl;

    std::cout << "Copy constructor" << std::endl;
    std::cout << "Expected: obj serialTwo == obj serialOne" << std::endl;
    SerialContainer serialTwo(serialOne); // Создаем второй объект контейнера
    std::cout << "Result serialOne data: ";
    SerialContainerPrint(serialOne);
    std::cout << std::endl << "serialOne size: " << serialOne.size() << std::endl;
    std::cout << "Result serialTwo data: ";
    SerialContainerPrint(serialTwo);
    std::cout << std::endl << "serialTwo size: " << serialTwo.size() << std::endl << std::endl;

    std::cout << "Copy assignment" << std::endl;
    std::cout << "Expected: obj serialTree == obj serialOne after copy" << std::endl;
    SerialContainer serialTree = SerialContainer<int>();
    serialTree.push_back(20); serialTree.push_back(8); serialTree.push_back(12);
    std::cout << "serialTree before copy: ";
    SerialContainerPrint(serialTree);
    serialTree = serialOne;
    std::cout << std::endl;
    serialTree = serialOne;
    std::cout << "serialTree after copy: ";
    SerialContainerPrint(serialTree);
    std::cout << std::endl << std::endl;

    std::cout << "Assigning a value by index" << std::endl;
    std::cout << "Num in index [2]" << std::endl;
    std::cout << "Before in index [2]: ";
    std::cout << serialTree[2] << std::endl;
    serialTree[2] = 100;
    std::cout << "After list[2] = 100:  ";
    std::cout << serialTree[2] << std::endl << std::endl;
} // Возможности последовательного контейнера
void SerialContainerMemReserveExample(){
    std::cout << "Serial container with memory reserved Container Example" << std::endl << std::endl;
    SerialContainerMR<int> serialMR;

    for(int i = 0; i < 10; i++){
        serialMR.push_back(i);
    } // Заполняем list числами от 0 до 10

    std::cout << "Add numbers to MR Container" << std::endl;
    std::cout << "Expected: 0 1 2 3 4 5 6 7 8 9" << std::endl;
    std::cout << "Result: ";
    SerialContainerPrint(serialMR);
    std::cout << std::endl << std::endl;

    std::cout << "Object serialMR size"<< std::endl;
    std::cout << "Expected: 10" << std::endl;
    std::cout << "Result: ";
    std::cout << serialMR.size() << std::endl << std::endl; // Размер контейнера

    std::cout << "Delete some numbers" << std::endl;
    std::cout << "Expected: 0 1 3 5 7 8 9" << std::endl;
    serialMR.erase(2); serialMR.erase(3); serialMR.erase(4); // Удаление 3, 5, 7, элемента
    std::cout << "Result: ";
    SerialContainerPrint(serialMR);
    std::cout << std::endl << std::endl;


    std::cout << "Add number 10 to start MR container" << std::endl;
    std::cout << "Expected: 10 0 1 3 5 7 8 9" << std::endl;
    serialMR.insert(0, 10);
    std::cout << "Result: ";
    SerialContainerPrint(serialMR);
    std::cout << std::endl << std::endl;

    std::cout << "Add number 20 to middle MR container" << std::endl;
    std::cout << "Expected: 10 0 1 3 20 5 7 8 9" << std::endl;
    serialMR.insert(4, 20);
    std::cout << "Result: ";
    SerialContainerPrint(serialMR);
    std::cout << std::endl << std::endl;

    std::cout << "Add number 30 to end MR container" << std::endl;
    std::cout << "Expected: 10 0 1 3 20 5 7 8 9 30" << std::endl;
    serialMR.insert(90, 30);
    std::cout << "Result: ";
    SerialContainerPrint(serialMR);
    std::cout << std::endl << std::endl;

    std::cout << "Copy constructor MR container" << std::endl;
    std::cout << "Expected: obj serialMRTwo == obj serialMR" << std::endl;
    SerialContainerMR serialMRTwo(serialMR); // Создаем второй объект контейнера
    std::cout << "Result serialMR data: ";
    SerialContainerPrint(serialMR);
    std::cout << std::endl << "serialMR size: " << serialMR.size() << std::endl;
    std::cout << "Result serialTwo data: ";
    SerialContainerPrint(serialMRTwo);
    std::cout << std::endl << "serialMRTwo size: " << serialMRTwo.size() << std::endl << std::endl;

    std::cout << "Copy assignment MR container" << std::endl;
    std::cout << "Expected: obj listTree == obj listOne after copy" << std::endl;
    SerialContainerMR serialMRTree = SerialContainerMR<int>();
    serialMRTree.push_back(20); serialMRTree.push_back(8); serialMRTree.push_back(12);
    std::cout << "serialMRTree before copy: ";
    SerialContainerPrint(serialMRTree);
    serialMRTree = serialMR;
    std::cout << std::endl;
    std::cout << "serialMRTree after copy: ";
    SerialContainerPrint(serialMRTree);
    std::cout << std::endl << std::endl;

    std::cout << "Edit element in index 2" << std::endl;
    serialMR[2] = 100;
    std::cout << "Result: ";
    std::cout << serialMR[2] << std::endl;
} // Возможности последовательного контейнера с резервированием памяти
void SinglyLinkedListExample(){
    std::cout << "Singly List Container Example" << std::endl << std::endl;
    SinglyLinkedList<int> listOne;

    for(int i = 0; i < 10; i++){
        listOne.push_back(i);
    } // Заполняем list числами от 0 до 10

    std::cout << "Add numbers to Singly List" << std::endl;
    std::cout << "Expected: 0 1 2 3 4 5 6 7 8 9" << std::endl;
    std::cout << "Result: ";
    SerialContainerPrint(listOne);
    std::cout << std::endl << std::endl;


    std::cout << "Object serialOne size"<< std::endl;
    std::cout << "Expected: 10" << std::endl;
    std::cout << "Result: ";
    std::cout << listOne.size() << std::endl << std::endl; // Размер контейнера

    std::cout << "Delete some numbers" << std::endl;
    std::cout << "Expected: 0 1 3 5 7 8 9" << std::endl;
    listOne.erase(2); listOne.erase(3); listOne.erase(4); // Удаление 3, 5, 7, элемента
    std::cout << "Result: ";
    SerialContainerPrint(listOne);
    std::cout << std::endl << std::endl;


    std::cout << "Add number 10 to start list container" << std::endl;
    std::cout << "Expected: 10 0 1 3 5 7 8 9" << std::endl;
    listOne.insert(0, 10);
    std::cout << "Result: ";
    SerialContainerPrint(listOne);
    std::cout << std::endl << std::endl;

    std::cout << "Add number 20 to middle list container" << std::endl;
    std::cout << "Expected: 10 0 1 3 20 5 7 8 9" << std::endl;
    listOne.insert(4, 20);
    std::cout << "Result: ";
    SerialContainerPrint(listOne);
    std::cout << std::endl << std::endl;

    std::cout << "Add number 30 to end list container" << std::endl;
    std::cout << "Expected: 10 0 1 3 20 5 7 8 9 30" << std::endl;
    listOne.insert(90, 30);
    std::cout << "Result: ";
    SerialContainerPrint(listOne);
    std::cout << std::endl << std::endl;

    std::cout << "Copy constructor list container" << std::endl;
    std::cout << "Expected: obj listTwo == obj listOne" << std::endl;
    SinglyLinkedList listTwo(listOne); // Создаем второй объект контейнера
    std::cout << "Result serialOne data: ";
    SerialContainerPrint(listOne);
    std::cout << std::endl << "serialOne size: " << listOne.size() << std::endl;
    std::cout << "Result serialTwo data: ";
    SerialContainerPrint(listTwo);
    std::cout << std::endl << "serialTwo size: " << listTwo.size() << std::endl << std::endl;

    std::cout << "Copy assignment list" << std::endl;
    std::cout << "Expected: obj listTree == obj listOne after copy" << std::endl;
    SinglyLinkedList listTree = SinglyLinkedList<int>();
    listTree.push_back(20); listTree.push_back(8); listTree.push_back(12);
    std::cout << "listTree before copy: ";
    SerialContainerPrint(listTree);
    listTree = listOne;
    std::cout << std::endl;
    std::cout << "listTree after copy: ";
    SerialContainerPrint(listTree);
    std::cout << std::endl << std::endl;

    std::cout << "Edit element in index 2" << std::endl;
    listOne[2] = 100;
    std::cout << "Result: ";
    std::cout << listOne[2] << std::endl;

} // Возможности односвязного списка
void DoubleLinkListExample(){
    std::cout << "Double List Container Example" << std::endl << std::endl;
    DoubleLinkedList<int> d_listOne;

    for(int i = 0; i < 10; i++){
        d_listOne.push_back(i);
    } // Заполняем list числами от 0 до 10

    std::cout << "Add numbers to Double List" << std::endl;
    std::cout << "Expected: 0 1 2 3 4 5 6 7 8 9" << std::endl;
    std::cout << "Result: ";
    SerialContainerPrint(d_listOne);
    std::cout << std::endl << std::endl;

    std::cout << "Object serialOne size"<< std::endl;
    std::cout << "Expected: 10" << std::endl;
    std::cout << "Result: ";
    std::cout << d_listOne.size() << std::endl << std::endl; // Размер контейнера

    std::cout << "Delete some numbers" << std::endl;
    std::cout << "Expected: 0 1 3 5 7 8 9" << std::endl;
    d_listOne.erase(2); d_listOne.erase(3); d_listOne.erase(4); // Удаление 3, 5, 7, элемента
    std::cout << "Result: ";
    SerialContainerPrint(d_listOne);
    std::cout << std::endl << std::endl;


    std::cout << "Add number 10 to start double list container" << std::endl;
    std::cout << "Expected: 10 0 1 3 5 7 8 9" << std::endl;
    d_listOne.insert(0, 10);
    std::cout << "Result: ";
    SerialContainerPrint(d_listOne);
    std::cout << std::endl << std::endl;

    std::cout << "Add number 20 to middle double list container" << std::endl;
    std::cout << "Expected: 10 0 1 3 20 5 7 8 9" << std::endl;
    d_listOne.insert(4, 20);
    std::cout << "Result: ";
    SerialContainerPrint(d_listOne);
    std::cout << std::endl << std::endl;

    std::cout << "Add number 30 to end double list container" << std::endl;
    std::cout << "Expected: 10 0 1 3 20 5 7 8 9 30" << std::endl;
    d_listOne.insert(90, 30);
    std::cout << "Result: ";
    SerialContainerPrint(d_listOne);
    std::cout << std::endl << std::endl;

    std::cout << "Copy constructor double link list container" << std::endl;
    std::cout << "Expected: obj listTwo == obj listOne" << std::endl;
    DoubleLinkedList d_listTwo(d_listOne); // Создаем второй объект контейнера
    std::cout << "Result serialOne data: ";
    SerialContainerPrint(d_listOne);
    std::cout << std::endl << "serialOne size: " << d_listOne.size() << std::endl;
    std::cout << "Result serialTwo data: ";
    SerialContainerPrint(d_listTwo);
    std::cout << std::endl << "serialTwo size: " << d_listTwo.size() << std::endl << std::endl;

    std::cout << "Copy assignment double link list" << std::endl;
    std::cout << "Expected: obj listTree == obj listOne after copy" << std::endl;
    DoubleLinkedList d_listTree = DoubleLinkedList<int>();
    d_listTree.push_back(20); d_listTree.push_back(8); d_listTree.push_back(12);
    std::cout << "listTree before copy: ";
    SerialContainerPrint(d_listTree);
    d_listTree = d_listOne;
    std::cout << std::endl;
    std::cout << "listTree after copy: ";
    SerialContainerPrint(d_listTree);
    std::cout << std::endl << std::endl;

    std::cout << "Edit element in index 2" << std::endl;
    d_listOne[2] = 100;
    std::cout << "Result: ";
    std::cout << d_listOne[2] << std::endl;
} // Возможности двух связного списка