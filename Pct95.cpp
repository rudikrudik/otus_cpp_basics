#include <iostream>
#include <algorithm>
#include "Pct95.h"

void Pct95::update(double next){
    massive.push_back(next);
}

const char* Pct95::name() const{
    return "95 Percentile";
}

double Pct95::result() const {
    std::vector<double> temp{massive};
    std::sort(temp.rbegin(), temp.rend());
    std::reverse(temp.rbegin(), temp.rend());

    int result = static_cast<int>(0.95 * temp.size());

    return temp[result];
}