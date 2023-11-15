#include <iostream>
#include <cmath>
#include "Min.h"
#include "Max.h"
#include "Mean.h"
#include "Std.h"
#include "Pct90.h"
#include "Pct95.h"


int main() {
    const int size = 6;
    IStatistics *statistics[size];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new Mean{};
    statistics[3] = new Std{};
    statistics[4] = new Pct90{};
    statistics[5] = new Pct95{};

    double value = 0;
    std::cout << "Enter a sequence of numbers:" << std::endl;

    while(std::cin >> value){
        for(int i = 0; i < size; i++){
            statistics[i]->update(value);
        }
    } // Заполняем экземпляры классов числами с консоли

    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    } // Выдаем ошибку если пользователь ввел не число

    for(int i = 0; i < size; i++){
        std::cout << statistics[i]->name() << ": " <<  statistics[i]->result() << std::endl;
    } // Выводим результат и имя

    for(int i = 0; i < size; i++){
        delete statistics[i];
    } // Вызываем деструкторы

    return 0;
}