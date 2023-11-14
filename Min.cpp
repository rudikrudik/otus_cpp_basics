#include <limits>
#include "Min.h"

Min::Min() : number{std::numeric_limits<double>::max()}{
} // Инициализируем number максимальным числом

void Min::update(double next){
    if(next < number){
        number = next;
    }
}

const char* Min::name() const{
    return "Minimum";
}

double Min::result() const{
    return number;
}