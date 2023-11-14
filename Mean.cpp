#include "Mean.h"


Mean::Mean() : number{0}, count{0}{}

void Mean::update(double next){
    number += next;
    count++;
}

const char* Mean::name() const{
    return "Arithmetic mean";
}

double Mean::result() const{
    return number / count;
}