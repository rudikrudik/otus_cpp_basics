#pragma once
#include "IStatistics.h"

class Min : public IStatistics {
public:
    Min();
    void update(double next) override;
    const char * name() const override;
    double result() const override;
private:
    double number;
}; // Минимальное число