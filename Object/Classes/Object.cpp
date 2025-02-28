#include "Object.h"

Object::Object(std::unique_ptr<Shape2> s, Vector2 pos)
    : shape(std::move(s)), _position(pos), _velocity(0, 0), _acceleration(0, 0), direction(0) 
{}

void Object::setPosition(const Vector2& position) {
    _position = position;
}

Vector2 Object::getPosition() const {
    return _position;
}

void Object::setDirection(const Vector2& direction) {
    _direction = direction;
}

Vector2 Object::getDirection() const {
    return _direction;
}

void Object::setVelocity(const Vector2& velocity) {
    _velocity = velocity;
}

Vector2 Object::getVelocity() const {
    return _velocity;
}

void Object::setMass(int mass) {
    _mass = mass;
}

int Object::getMass() const {
    return _mass;
}

void Object::setAcceleration(const Vector2& acceleration) {
    _acceleration = acceleration;
}

Vector2 Object::getAcceleration() const {
    return _acceleration;
}

void Object::setAngle(float angle) {
    direction = angle;
}

float Object::getAngle() const {
    return direction;
}
