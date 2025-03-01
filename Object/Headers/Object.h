#ifndef OBJECT_H
#define OBJECT_H

#include "Vector2.h"
#include "Shape2.h"
#include <memory>

class Object {
private:
    std::unique_ptr<Shape2> shapeTyp;
    Vector2 _position;    
    Vector2 _direction;
    Vector2 _velocity;
    int _mass;
    Vector2 _acceleration;
    float _angle;

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

    // Setters
    void setPosition(const Vector2& position);
    void setDirection(const Vector2& direction);
    void setVelocity(const Vector2& velocity);
    void setMass(int mass);
    void setAcceleration(const Vector2& acceleration);
    void setAngle(float angle);

    // Getters
    Vector2 getPosition() const;
    Vector2 getDirection() const;
    Vector2 getVelocity() const;
    int getMass() const;
    Vector2 getAcceleration() const;
    float getAngle() const;
    Shape2* getShape() const { return shapeTyp.get(); }  // Fixed: Returns a raw pointer
};

#endif
