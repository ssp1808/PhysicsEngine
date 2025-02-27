#include <iostream>
#include "../Headers/Vector2.h"

Vector2::Vector2(/* args */)
{
}

Vector2::Vector2(const int& ix,const int& iy):x(ix),y(iy)
{
    
}

Vector2::~Vector2()
{
}

void Vector2::setVector2(const int& ix,const int& iy)
{
    x = ix;
    y = iy;
}

void Vector2::getVector2(int &ox,int &oy)
{
    ox=x;
    oy=y;
}

Vector2 Vector2::operator+(const Vector2& other)
{
    return Vector2(x + other.x, y + other.y); 
}

void Vector2::dump()
{
    std::cout<<std::endl;
    std::cout<<"Vector2 :: ";
    std::cout<<x;
    std::cout<<";";
    std::cout<<y;
    std::cout<<std::endl;
} 