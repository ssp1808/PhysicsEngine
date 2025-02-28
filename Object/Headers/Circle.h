#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape2.h"

class Circle : public Shape2 {
private:
    int radius;

public:
    Circle();
    Circle(int r);
    void setShape(const SHAPETYPE& iType) override;
    SHAPETYPE getShape() const override;
    int getArea() override;
    Vector2 getCentre() override;

};

#endif // CIRCLE_H
