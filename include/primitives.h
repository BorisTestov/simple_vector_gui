#pragma once
/**
 * @file Файл с описание графических примитивов и их интерфейсов
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
class IShape
{
public:
    virtual void draw() = 0;
    virtual int getX() = 0;
    virtual void setX(int x) = 0;
    virtual int getY() = 0;
    virtual void setY(int y) = 0;
    virtual Color getColor() = 0;
    virtual bool setColor(Color color) = 0;
    virtual bool getId() = 0;
    IShape(int x, int y);
    virtual ~IShape() = default;
    //    virtual void setId() = 0;

protected:
    int x, y, id;
    Color color;
    void setId();
};

/**
 * @brief Прямоугольник
 */
class Square : public IShape
{
public:
    Square(int x, int y, int w, int h);
    void draw();
    //    void setId();

private:
    int w, h;
};

/**
 * @brief Круг
 */
class Circle : public IShape
{
public:
    Circle(int x, int y, int radius);
    void draw();
    //    void setId();

private:
    int radius;
};