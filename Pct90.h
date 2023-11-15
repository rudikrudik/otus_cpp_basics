#pragma once
#include "IStatistics.h"
#include "vector"

class Pct90 : public IStatistics{
public:
    void update(double next) override;
    const char * name() const override;
    double result() const override;

private:
    std::vector<double> massive;
}; // 90й процентиль