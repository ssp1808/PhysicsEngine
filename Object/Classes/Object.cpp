#include "Object.h"
#include "Circle.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

Object::Object(std::unique_ptr<Shape2> s, Vector2 pos)
    : shapeTyp(std::move(s)), _position(pos), _velocity(0.0), _acceleration(0.0), _direction(0,0) 
{}

Object::Object(Object&& other) noexcept
    : shapeTyp(std::move(other.shapeTyp)),  
      _position(other._position),
      _direction(other._direction),
      _mass(other._mass),
      _angle(other._angle),
      _velocity(other._velocity),
      _acceleration(other._acceleration),
      _bgravity(other._bgravity)
{
    std::cout << "[Move Constructor] Moving object..." << std::endl;
    if (shapeTyp) {
        std::cout << "[Move Constructor] Shape type after move: " << shapeTyp->getShapeType() << std::endl;
    } else {
        std::cout << "[Move Constructor] Warning: shapeTyp is NULL!" << std::endl;
    }
    other.shapeTyp = nullptr;  // Ensure safety
}

Object& Object::operator=(Object&& other) noexcept {
    if (this != &other) {
        std::cout << "[Move Assignment] Assigning moved object..." << std::endl;

        shapeTyp = std::move(other.shapeTyp);
        _position = other._position;
        _direction = other._direction;
        _mass = other._mass;
        _angle = other._angle;
        _velocity = other._velocity;
        _acceleration = other._acceleration;
        _bgravity = other._bgravity;

        if (shapeTyp) {
            std::cout << "[Move Assignment] Shape type after move: " << shapeTyp->getShapeType() << std::endl;
        } else {
            std::cout << "[Move Assignment] Warning: shapeTyp is NULL!" << std::endl;
        }

        other.shapeTyp = nullptr;  // Prevent double deletion
    }
    return *this;
}


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

void Object::setAngle(const float &angle)
{
    _angle = angle;  // Store the angle separately
    float radians = angle * (M_PI / 180.0f);  // Convert degrees to radians
    _direction.setVector2(cos(radians),sin(radians));
}

float Object::getAngle() const {
    return _angle;  // Return the stored angle
}

bool Object::hasGravity() const
{
    return _bgravity;
}

void Object::enableGravity()
{
    _bgravity=true;
}

void Object::disableGravity()
{
    _bgravity=false;
}

// Reflects the object's direction upon hitting boundaries and optionally reduces velocity.
void checkBoundaryCollision(Vector2& pos, Vector2& direction, float& velocity)
{
    bool collided = false;
    
    // Check horizontal boundaries
    if (pos.x < 0) {
        pos.x = 0;              // Optional: reposition exactly at the boundary
        direction.x = -direction.x;  // Reflect the horizontal direction
        collided = true;
    } else if (pos.x > 800) {
        pos.x = 800;
        direction.x = -direction.x;
        collided = true;
    }
    
    // Check vertical boundaries
    if (pos.y < 0) {
        pos.y = 0;
        direction.y = -direction.y;  // Reflect the vertical direction
        collided = true;
    } else if (pos.y > 600) {
        pos.y = 600;
        direction.y = -direction.y;
        collided = true;
    }
    
    // // If a collision occurred, optionally reduce the speed to simulate energy loss.
    if (collided) {
        velocity *= 0.98f; // Reduce Y velocity by 2%
    }
    
}


void Object::CalculateNextPos(float deltaTime)
{
    _bgravity=false; //If this function is called that means gravity is not applied to obj

    //check if hitting boundary
    checkBoundaryCollision(_position,_direction,_velocity);

    //get veliocity
    float velocity = _velocity; //50.0f;      // Speed (units per second)
    //get direction
    Vector2 direction = _direction;//(1, 1);     // Movement direction (diagonal)
    //calculate and return the final position

    // Compute displacement: velocity * direction * deltaTime
    Vector2 displacement = direction * velocity * deltaTime;

    // Update position
    _position +=  displacement;
}

void Object::CalculateNextPosGravity(float deltaTime)
{
    _bgravity = true;

    //check if hitting boundary
    checkBoundaryCollision(_position,_direction,_velocity);
    
    //check collision with other objects
    //checkObjectCollision();

    // Use local variables for speed and direction (or use const references if you don't change them)
    float vel = _velocity;
    const Vector2& dir = _direction;  

    // Gravity (assumed constant downward acceleration)
    const Vector2 gravity(0, 9.8f*SCALINGFACTOR);

    // Precompute the term: velocity * deltaTime
    float velDelta = vel * deltaTime;
    
    // Compute new velocity by adding the effect of gravity (only affects y component)
    // Vector2 newVelocity = dir * vel + gravity * deltaTime;
    Vector2 newVelocity = Vector2(_velocity * _direction.x, _velocity * _direction.y) + gravity * deltaTime;

    // Compute displacement using Euler integration:
    // displacement = (current velocity vector + gravity effect) * deltaTime
    // Here we split the effect: horizontal part from velocity and vertical from gravity.
    Vector2 displacement = (dir * velDelta) + (gravity * deltaTime);

    // Update position
    _position += displacement;

    // Update velocity and direction for next frame
    _velocity = newVelocity.length();
    _direction = newVelocity.normalized();
}


int Object::getRadius() const {
    if (!shapeTyp) {
        std::cerr << "Error: Shape is nullptr in Object!" << std::endl;
        return -1;
    }

    Circle* circle = dynamic_cast<Circle*>(shapeTyp.get()); // Use `.get()` for unique_ptr
    if (circle) {
        return circle->getRadius();
    }

    std::cerr << "Error: Shape is not a Circle!" << std::endl;
    return -1;
}
