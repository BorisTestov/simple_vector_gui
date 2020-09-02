#include "primitives.h"

IShape::IShape(int x, int y)
{
    this->x = x;
    this->y = y;
}

void IShape::setId()
{
    std::cout << "ID was set for shape with x: " << x << " and y: " << y << std::endl;
}

Circle::Circle(int x, int y, int radius) :
    IShape(x, y)
{
    this->radius = radius;
    setId();
}

void Circle::draw()
{
    std::cout << "Circle with radius " << radius << " was spawned in x: " << x << " y: " << y << "!" << std::endl;
}

Square::Square(int x, int y, int w, int h) :
    IShape(x, y)
{
    this->h = h;
    this->w = w;
    setId();
}

void Square::draw()
{
    std::cout << "Square with width " << w << " and height " << h << " was spawned in x: " << x << " y: " << y << "!" << std::endl;
}