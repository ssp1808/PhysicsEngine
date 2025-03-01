#ifndef SHAPE2_H
#define SHAPE2_H

#include "Vector2.h"

enum SHAPETYPE{
    CIRCLE,
    RECTANGLE,
    SQUARE,
    TRIANGLE
};

class Shape2
{
    public:
    virtual void setShapeType(const SHAPETYPE& iType)=0;
    virtual SHAPETYPE getShapeType() const =0;
    virtual int  getArea() =0;

    protected:
    int area;
    SHAPETYPE shapeTyp;    
};

#endif