#pragma once
#include "primitives.h"

#include <QtTest/QtTest>

class TestPrimitives : public QObject
{
    Q_OBJECT
private slots:
    void TestRectangle_data();
    void TestRectangle();
    void TestCircle_data();
    void TestCircle();
};