#ifndef VECTOR2_H 
#define VECTOR2_H

class Vector2
{
private:
    /* data */
    double x;
    double y;
public:
    void setVector2(const double& ix,const double& iy);
    void getVector2(double &ox,double &oy);
    void dump();
    void normalize();

    //Operators
    Vector2 operator+(const Vector2& other);
    Vector2& operator+=(const Vector2 &other);
    Vector2 operator*(float scalar) const;

    Vector2(const double& ix,const double& iy);
    Vector2(/* args */);
    ~Vector2();
};
#endif