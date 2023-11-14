#pragma once
#include "IStatistics.h"

class Mean : public IStatistics{
public:
    Mean();
    void update(double next) override;
    const char * name() const override;
    double result() const override;

private:
    double number;
    int count;
}; // Среднее арифметическое