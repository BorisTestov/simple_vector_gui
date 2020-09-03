#include "test_primitives.h"

Q_DECLARE_METATYPE(Rectangle)
Q_DECLARE_METATYPE(Circle)

void TestPrimitives::TestRectangle_data()
{
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<int>("w");
    QTest::addColumn<int>("h");
    QTest::addColumn<Rectangle>("expectedPrimitive");
    QTest::addRow("x=0, y=0, w=100, h=100") << 0 << 0 << 100 << 100 << Rectangle(0, 0, 100, 100);
    QTest::addRow("x=-100, y=-100, w=1, h=1") << -100 << -100 << 1 << 1 << Rectangle(-100, -100, 1, 1);
}

void TestPrimitives::TestRectangle()
{
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(int, w);
    QFETCH(int, h);
    QFETCH(Rectangle, expectedPrimitive);
    Rectangle actualPrimitive(x, y, w, h);
    QCOMPARE(actualPrimitive.getX(), expectedPrimitive.getX());
    QCOMPARE(actualPrimitive.getY(), expectedPrimitive.getY());
    QCOMPARE(actualPrimitive.getW(), expectedPrimitive.getW());
    QCOMPARE(actualPrimitive.getH(), expectedPrimitive.getH());
}

void TestPrimitives::TestCircle_data()
{
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");
    QTest::addColumn<int>("radius");
    QTest::addColumn<Circle>("expectedPrimitive");
    QTest::addRow("x=12, y=12, radius=10") << 12 << 12 << 10 << Circle(12, 12, 10);
    QTest::addRow("x=-65, y=-18, radius=42") << -65 << -18 << 42 << Circle(-65, -18, 42);
}

void TestPrimitives::TestCircle()
{
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(int, radius);
    QFETCH(Circle, expectedPrimitive);
    Circle actualPrimitive(x, y, radius);
    QCOMPARE(actualPrimitive.getX(), expectedPrimitive.getX());
    QCOMPARE(actualPrimitive.getY(), expectedPrimitive.getY());
    QCOMPARE(actualPrimitive.getRadius(), expectedPrimitive.getRadius());
}