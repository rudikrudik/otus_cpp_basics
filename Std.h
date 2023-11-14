#pragma once
#include "IStatistics.h"
#include "vector"

class Std : public IStatistics{
public:
    void update(double next) override;
    const char * name() const override;
    double result() const override;

private:
    std::vector<double> massive;
}; // Среднеквадратическое отклонение
