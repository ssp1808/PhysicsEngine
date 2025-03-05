#include <iostream>
#include "Vector2.h"

Vector2::Vector2(/* args */)
{
}

Vector2::Vector2(const double& ix,const double& iy):x(ix),y(iy)
{
    
}

Vector2::~Vector2()
{
}

void Vector2::setVector2(const double& ix,const double& iy)
{
    x = ix;
    y = iy;
}

void Vector2::getVector2(double &ox,double &oy)
{
    ox=x;
    oy=y;
}

Vector2 Vector2::operator+(const Vector2& other)
{
    return Vector2(x + other.x, y + other.y); 
}

Vector2& Vector2::operator+=(const Vector2 &other) {
    x += other.x;
    y += other.y;
    return *this; // Return the modified object
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

// Normalize the vector (make it a unit vector)
void Vector2::normalize() 
{
    float length = std::sqrt(x * x + y * y);
    if (length > 0) {
        x /= length;
        y /= length;
    }
}

// Normalize the vector and return a new unit vector
Vector2 Vector2::normalized() const  
{
    float length = std::sqrt(x * x + y * y);
    if (length > 0) {
        return Vector2(x / length, y / length);
    }
    return Vector2(0, 0);  // Return zero vector if length is zero
}

// Scalar multiplication
Vector2 Vector2::operator*(float scalar) const 
{
    return Vector2(x * scalar, y * scalar);
}

// Compute the length (magnitude) of the vector
float Vector2::length() const 
{
    return std::sqrt(x * x + y * y);
}
