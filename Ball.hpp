#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"


class Ball {
public:
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    void setRadius(double radius);
    double getRadius() const;
    double getMass() const;
    void setColor(const Color& color);
    Color getColor() const;
    void setCollided(bool status);
    bool isCollided() const;

private:
    Color c_color;
    Point v_velocity;
    Point c_center;
    double r_radius;
    bool f_flag;
};