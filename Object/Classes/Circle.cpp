#include "Shape2.h"
#include "Circle.h"

Circle::Circle() : radius(0) {}
Circle::Circle(int r) : radius(r) {}

void Circle::setShape(const SHAPETYPE& iType)
{
    shape = iType;
}

SHAPETYPE Circle::getShape() const 
{
    return shape;
}

int Circle::getArea() 
{
    area = 3.14159 * radius * radius;
    return area;
}

Vector2 Circle::getCentre() 
{
    return Vector2(1,3);
}
