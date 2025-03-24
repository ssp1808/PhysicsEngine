#ifndef OBJECT_H
#define OBJECT_H

#include "Vector2.h"
#include "Shape2.h"
#include <memory>
#include <iostream>

class Object {
private:
    std::unique_ptr<Shape2> shapeTyp;
    Vector2 _position;    
    Vector2 _direction;
    int _mass;
    // int _radius;
    float _angle;
    float _velocity;
    float _acceleration;
    bool _bgravity;

public:
    // Constructor
    Object(std::unique_ptr<Shape2> s, Vector2 position);

    // Deleted copy constructor and copy assignment to prevent shallow copies
    Object(const Object&) = delete;
    Object& operator=(const Object&) = delete;

    // Move Constructor (Transfers Ownership)
    Object(Object&& other) noexcept;
    Object& operator=(Object&& other) noexcept;

    // Destructor (No need to explicitly delete shapeTyp, unique_ptr handles it)
    ~Object() = default;
    
    //Calculate the position
    void CalculateNextPos(float deltaTime); //without gravity
    void CalculateNextPosGravity(float deltaTime); //with gravity

    //Gravity options
    void enableGravity();
    void disableGravity();
    
    // Setters
    void setPosition(const Vector2& position);
    void setDirection(const Vector2& direction);
    void setVelocity(const float& velocity);
    void setMass(int mass);
    void setAcceleration(const float& acceleration);
    void setAngle(const float& angle);
    // void setRadius(const int& iradius);
    
    // Getters
    Vector2 getPosition() const;
    Vector2 getDirection() const;
    int getMass() const;
    int getRadius() const;
    float getAcceleration() const;
    float getVelocity() const;
    float getAngle() const;
    bool hasGravity() const;
    Shape2* getShape() const { 
        if (!shapeTyp) {
            std::cerr << "Warning: Attempting to access a null shape!" << std::endl;
        }
        return shapeTyp.get(); 
    }
    
};

#endif
