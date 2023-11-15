#include "Ball.hpp"
#include <cmath>

const double PI = 3.1415926;

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
    // TODO: место для доработки
    v_velocity = velocity.vector();
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    // TODO: место для доработки
    return v_velocity;
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    // TODO: место для доработки
    painter.draw(Ball::getCenter(), Ball::getRadius(), getColor());
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    // TODO: место для доработки
    c_center = center;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    // TODO: место для доработки
    return c_center;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    // TODO: место для доработки
    return r_radius;
}

void Ball::setRadius(double radius) {
    // TODO: место для доработки
    r_radius = radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {
    // TODO: место для доработки
    return ((PI * pow(getRadius(), 3) * 4) / 3);
}

void Ball::setColor(const Color& color) {
    // TODO: место для доработки
    c_color = color;
}

Color Ball::getColor() const {
    // TODO: место для доработки
    return c_color;
}

void Ball::setCollided(bool status) {
    f_flag = status;
}

bool Ball::isCollided() const {
    return f_flag;
}
