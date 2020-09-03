#pragma once
/**
 * @file Файл с описанием графических примитивов и их интерфейсов
 */

#include <iostream>
/**
 * @brief enum с цветами примитива
 */
enum class Color
{
    RED,
    GREEN,
    BLUE
};

/**
 * @brief Интерфейс фигуры
 */
class AbstractPrimitive
{
public:
    virtual void draw() = 0;
    int getX() const;
    int getY() const;
    Color getColor() const;
    [[nodiscard]] int getId() const;
    AbstractPrimitive();
    AbstractPrimitive(int x, int y);
    virtual ~AbstractPrimitive() = default;

protected:
    int x, y, id;
    Color color;
    void setId() const;
    void setX(int newX);
    void setY(int newY);
    void setColor(Color newColor);
};

/**
 * @brief Прямоугольник
 */
class Rectangle : public AbstractPrimitive
{
public:
    Rectangle();
    Rectangle(int x, int y, int w, int h);
    void draw() override;
    int getW() const;
    int getH() const;

private:
    int w, h;
};

/**
 * @brief Круг
 */
class Circle : public AbstractPrimitive
{
public:
    Circle();
    Circle(int x, int y, int radius);
    void draw() override;
    int getRadius() const;

private:
    int radius;
};