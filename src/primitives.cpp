#include "primitives.h"

AbstractPrimitive::AbstractPrimitive()
{
    _x = 0;
    _y = 0;
}

AbstractPrimitive::AbstractPrimitive(int x, int y)
{
    _x = x;
    _y = y;
}

void AbstractPrimitive::setId() const
{
    std::cout << "ID was set for shape with x: " << getX() << " and y: " << getY() << std::endl;
}

int AbstractPrimitive::getId() const
{
    return _id;
}

void AbstractPrimitive::setX(int newX)
{
    _x = newX;
}

int AbstractPrimitive::getX() const
{
    return _x;
}

void AbstractPrimitive::setY(int newY)
{
    _y = newY;
}

int AbstractPrimitive::getY() const
{
    return _y;
}

void AbstractPrimitive::setColor(Color newColor)
{
    _color = newColor;
}

Color AbstractPrimitive::getColor() const
{
    return _color;
}

Circle::Circle() :
    AbstractPrimitive()
{
    _radius = 0;
    setId();
}

Circle::Circle(int x, int y, int radius) :
    AbstractPrimitive(x, y)
{
    _radius = radius;
    setId();
}

int Circle::getRadius() const
{
    return _radius;
}

void Circle::draw()
{
    std::cout << "Circle with radius " << getRadius() << " was spawned in x: " << getX() << " y: " << getY() << "!" << std::endl;
}

Rectangle::Rectangle() :
    AbstractPrimitive()
{
    _w = 0;
    _h = 0;
    setId();
}

Rectangle::Rectangle(int x, int y, int w, int h) :
    AbstractPrimitive(x, y)
{
    _h = h;
    _w = w;
    setId();
}

void Rectangle::draw()
{
    std::cout << "Rectangle with width " << getW() << " and height " << getH() << " was spawned in x: " << getX() << " y: " << getY() << "!" << std::endl;
}

int Rectangle::getW() const
{
    return _w;
}

int Rectangle::getH() const
{
    return _h;
}