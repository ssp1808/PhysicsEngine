#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include <Object.h>
#include <vector>

class CollisionDetector
{

    public:
    void CheckCollisions(std::vector<Object> &ioVecObjects);
};
#endif