#pragma once
#include "IStatistics.h"

class Max : public IStatistics{
public:
    Max();
    void update(double next) override;
    const char * name() const override;
    double result() const override;

private:
    double number;
}; // Максимальное число