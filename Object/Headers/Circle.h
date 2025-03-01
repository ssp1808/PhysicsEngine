#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape2.h"

class Circle : public Shape2 {
private:
    int _radius;

public:
    Circle();
    Circle(int r);
    void setShapeType(const SHAPETYPE& iType) override;
    SHAPETYPE getShapeType() const override;
    int getArea() override;
    int getRadius();
};

#endif // CIRCLE_H
