#include "primitives.h"

AbstractPrimitive::AbstractPrimitive(int x, int y)
{
    this->x = x;
    this->y = y;
}

void AbstractPrimitive::setId() const
{
    std::cout << "ID was set for shape with x: " << x << " and y: " << y << std::endl;
}

int AbstractPrimitive::getId() const
{
    return id;
}

void AbstractPrimitive::setX(int newX)
{
    this->x = newX;
}

int AbstractPrimitive::getX() const
{
    return x;
}

void AbstractPrimitive::setY(int newY)
{
    this->y = newY;
}

int AbstractPrimitive::getY() const
{
    return y;
}

void AbstractPrimitive::setColor(Color newColor)
{
    this->color = newColor;
}

Color AbstractPrimitive::getColor() const
{
    return color;
}

Circle::Circle(int x, int y, int radius) :
    AbstractPrimitive(x, y)
{
    this->radius = radius;
    setId();
}

void Circle::draw()
{
    std::cout << "Circle with radius " << radius << " was spawned in x: " << x << " y: " << y << "!" << std::endl;
}

Rectangle::Rectangle(int x, int y, int w, int h) :
    AbstractPrimitive(x, y)
{
    this->h = h;
    this->w = w;
    setId();
}

void Rectangle::draw()
{
    std::cout << "Rectangle with width " << w << " and height " << h << " was spawned in x: " << x << " y: " << y << "!" << std::endl;
}