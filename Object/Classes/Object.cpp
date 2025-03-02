#include "Object.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

Object::Object(std::unique_ptr<Shape2> s, Vector2 pos)
    : shapeTyp(std::move(s)), _position(pos), _velocity(0.0), _acceleration(0.0), _direction(0,0) 
{}

/*
Object::Object()
{
}

Object::~Object()
{
}
*/

void Object::setPosition(const Vector2& position) {
    _position = position;
}

Vector2 Object::getPosition() const
{
    return _position;
}

void Object::setDirection(const Vector2& direction) {
    _direction = direction;
}

Vector2 Object::getDirection() const {
    return _direction;
}

void Object::setVelocity(const float& velocity) {
    _velocity = velocity;
}

float Object::getVelocity() const {
    return _velocity;
}

void Object::setMass(int mass) {
    _mass = mass;
}

int Object::getMass() const {
    return _mass;
}

void Object::setAcceleration(const float& acceleration) {
    _acceleration = acceleration;
}

float Object::getAcceleration() const {
    return _acceleration;
}

void Object::setAngle(float angle) {
    _angle = angle;  // Store the angle separately
    float radians = angle * (M_PI / 180.0f);  // Convert degrees to radians
    _direction.setVector2(cos(radians),sin(radians));
}

float Object::getAngle() const {
    return _angle;  // Return the stored angle
}

void Object::CalculateNextPos()
{
    //Get previous pos
    Vector2 position(_position);  // Initial position
    //get veliocity
    float velocity = _velocity; //50.0f;      // Speed (units per second)
    //get direction
    Vector2 direction = _direction;//(1, 1);     // Movement direction (diagonal)
    //calculate and return the final position
    float deltaTime = 0.016f;    // Time step (assuming 60 FPS → 1/60 = 0.016s)

    // Compute displacement: velocity * direction * deltaTime
    Vector2 displacement = direction * velocity * deltaTime;

    // Update position
    _position = position + displacement;
}