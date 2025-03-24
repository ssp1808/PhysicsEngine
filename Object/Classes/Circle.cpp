#include "Shape2.h"
#include "Circle.h"

Circle::Circle() : _radius(0) {shapeTyp=SHAPETYPE::CIRCLE;}
Circle::Circle(int r) : _radius(r) 
{
    shapeTyp=SHAPETYPE::CIRCLE;
}

void Circle::setShapeType(const SHAPETYPE& iType)
{
    shapeTyp = iType;
}

SHAPETYPE Circle::getShapeType() const 
{
    return shapeTyp;
}

int Circle::getArea() 
{
    area = 3.14159 * _radius * _radius;
    return area;
}

int Circle::getRadius()
{
    return _radius;
}
