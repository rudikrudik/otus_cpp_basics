#include "Max.h"
#include "limits"

Max::Max() : number{std::numeric_limits<double>::lowest()}{} // Инициализируем number минимальным числом

void Max::update(double next){
    if(next > number){
        number = next;
    }
}

const char * Max::name() const{
    return "Maximum";
}

double Max::result() const{
    return number;
}