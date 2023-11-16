#include <iostream>
#include "SerialContainer.h"

int main() {
    SerialContainer serial = SerialContainer();
    serial.push_back(10);
    serial.push_back(20);
    serial.push_back(30);
    serial.push_back(40);
    std::cout << "Length SerialContainer: " << serial.size() << std::endl;

    serial.erase(2);

    for(int i = 0; i < serial.size(); i++){
        std::cout << serial[i] << ' ';
    }

    std::cout << std::endl << "Length SerialContainer: " << serial.size() << std::endl;

    //std::cout << serial[1] << std::endl;

    return 0;
}
