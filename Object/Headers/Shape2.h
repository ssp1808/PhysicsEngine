#ifndef SHAPE2_H
#define SHAPE2_H

#include "Vector2.cpp"

enum SHAPETYPE{
    circle,
    rectangle,
    square,
    triangle
};

class Shape2
{
    public:
    virtual void setShape(const SHAPETYPE& iType)=0;
    virtual SHAPETYPE getShape() const =0;
    virtual int  getArea() =0;
    virtual Vector2  getCentre() =0;

    protected:
    int area;
    SHAPETYPE shape;    
};

#endif