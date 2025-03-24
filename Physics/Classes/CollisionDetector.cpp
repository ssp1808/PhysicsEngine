#include "CollisionDetector.h"
#include <vector>
#include <iostream>

void CollisionDetector::CheckCollisions(std::vector<Object>& ioVecObjects) {
    int vectSize = ioVecObjects.size();
    for (size_t i = 0; i < vectSize - 1; i++) {
        for (size_t j = i + 1; j < vectSize; j++) {
            Object& obj1 = ioVecObjects[i];
            Object& obj2 = ioVecObjects[j];

            // Get Positions and Radii
            Vector2 pos1 = obj1.getPosition();
            Vector2 pos2 = obj2.getPosition();
            float radius1 = obj1.getRadius();
            float radius2 = obj2.getRadius();

            // Check for valid radius
            if (radius1 < 0 || radius2 < 0) continue;

            // Compute Distance Vector
            Vector2 diff = pos2 - pos1;
            float distance = diff.length();

            // **Check Collision**
            if (distance <= (radius1 + radius2)) {
                //std::cout << "Collision detected! Exchanging velocities.\n";

                // Swap Velocities
                float tempVelocity = obj1.getVelocity();
                obj1.setVelocity(obj2.getVelocity());
                obj2.setVelocity(tempVelocity);

                // Swap Directions
                Vector2 tempDirection = obj1.getDirection();
                obj1.setDirection(obj2.getDirection());
                obj2.setDirection(tempDirection);
            }
        }
    }
}
