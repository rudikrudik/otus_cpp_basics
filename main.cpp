#include <iostream>
#include "SerialContainer.hpp"

void SerialContainerExample();

int main() {
    SerialContainerExample(); // Вызов функции с примером работы последовательного контейнера
    //SerialContainer<int> temp;
    //temp.push_back(10);
    return 0;
}

template <typename T>
void SerialContainerPrint(T& serial){
    for(int i = 0; i < serial.size(); i++){
        std::cout << serial[i] << ' ';
    }
} // Вспомогательная функция вывода содержимого контейнера

void SerialContainerExample(){
    std::cout << "Serial Container Example" << std::endl << std::endl;

    SerialContainer serialOne = SerialContainer<float>(); // Создаем объект последовательного контейнера

    for(int i = 0; i < 10; i++){
        serialOne.push_back(i + 0.1f);
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
    //serialTwo.push_back(40);
    SerialContainerPrint(serialTwo);
    std::cout << std::endl << "serialTwo size: " << serialTwo.size() << std::endl << std::endl;

    std::cout << "Copy assignment" << std::endl;
    std::cout << "Expected: obj serialTree == obj serialOne after copy" << std::endl;
    SerialContainer serialTree = SerialContainer<float>();
    serialTree.push_back(20); serialTree.push_back(8); serialTree.push_back(12);
    std::cout << "serialTree before copy: ";
    SerialContainerPrint(serialTree);
    std::cout << std::endl;
    serialTree = serialOne;
    std::cout << "serialTree after copy: ";
    SerialContainerPrint(serialTree);
    std::cout << std::endl;

} // Возможности последовательного контейнера

