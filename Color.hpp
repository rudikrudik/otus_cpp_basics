#pragma once
#include <iostream>

class Color {
  public:
    Color();
    Color(double red, double green, double blue);
    double red() const;
    double green() const;
    double blue() const;

friend std::ifstream& operator>>(std::ifstream& stream, Color& color);

  private:
    double r{};
    double g{};
    double b{};

};
