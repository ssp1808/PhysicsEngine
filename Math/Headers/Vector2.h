#ifndef VECTOR2_H 
#define VECTOR2_H

class Vector2
{
private:
    /* data */
    int x;
    int y;
public:
    void setVector2(const int& ix,const int& iy);
    void getVector2(int &ox,int &oy);
    void dump();

    Vector2 operator+(const Vector2& other);
    Vector2(const int& ix,const int& iy);
    Vector2(/* args */);
    ~Vector2();
};
#endif