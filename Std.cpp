#include "Std.h"
#include "numeric"

void Std::update(double next){
    massive.push_back(next);
}

const char* Std::name() const{
    return "Standard deviation";
}

double Std::result() const{
    double sumPowElem = 0;
    // Среднее арифметическое
    double sumElement = std::accumulate(massive.begin(), massive.end(), 0.0) / massive.size();
    // Считаем квадраты отклонений
    for (unsigned int i = 0; i < massive.size(); i++) {
        sumPowElem += pow(massive[i] - sumElement, 2);
    }
    // Среднеквадратичное отклонение
    return sqrt(sumPowElem / massive.size());
}

