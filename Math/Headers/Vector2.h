#ifndef VECTOR2_H 
#define VECTOR2_H

class Vector2
{
private:
    /* data */
    public:
    double x;
    double y;

    void setVector2(const double& ix,const double& iy);
    void getVector2(double &ox,double &oy);
    void dump();
    void normalize();

    Vector2 normalized() const;

    //Operators
    Vector2 operator+(const Vector2& other);
    Vector2& operator+=(const Vector2 &other);
    Vector2 operator*(float scalar) const;

    float length() const;

    Vector2(const double& ix,const double& iy);
    Vector2(/* args */);
    ~Vector2();
};
#endif