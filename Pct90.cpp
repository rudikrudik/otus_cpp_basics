#include <iostream>
#include <algorithm>
#include "Pct90.h"

void Pct90::update(double next){
    massive.push_back(next);
}

const char* Pct90::name() const{
    return "90 Percentile";
}

double Pct90::result() const {
    std::vector<double> temp{massive};
    std::sort(temp.rbegin(), temp.rend());
    std::reverse(temp.rbegin(), temp.rend());

    int result = static_cast<int>(0.9 * temp.size());

    return temp[result];
}


