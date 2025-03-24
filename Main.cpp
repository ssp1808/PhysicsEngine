#define SDL_MAIN_HANDLED

#include "Object.h"
#include "Circle.h"
#include "Renderer.h"
#include "CollisionDetector.h"  // Include collision detector

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]) 
{ 
    SDL_SetMainReady(); // Ensure SDL doesn't override main

    cout<<"//---------------------------------------------------//"<<endl;
    cout<<"//--------------PHYSICS ENGINE START-----------------//"<<endl;
    cout<<"//---------------------------------------------------//"<<endl;
    
    // Create objects
    vector<Object> objects;  // Store objects in a vector
    
    int Max_Objs = 3;
    // for(int j=0;j<Max_Objs;j++)
    // {
    //     Object circleObject(std::make_unique<Circle>(10), Vector2(20+j*30, 300));
    //     circleObject.setVelocity(100.0f);
    //     circleObject.setDirection(Vector2(1,1));
    //     objects.emplace_back(std::move(circleObject));  // Moves object (GOOD)
    // }
 
    bool running = true;
    SDL_Event event;
    Renderer renderer(800, 600);
    CollisionDetector colDetector; // Create collision detector

    cout<<"//---------------------------------------------------//"<<endl;
    cout<<"//--------------Entering main loop-------------------//"<<endl;
    cout<<"//---------------------------------------------------//"<<endl;
    
    auto lastTime = chrono::high_resolution_clock::now();
    auto currentTime = chrono::high_resolution_clock::now();
    chrono::duration<float> elapsedTime = currentTime - lastTime;
    float deltaTime = elapsedTime.count(); // Time step in seconds

    Object circleObject(std::make_unique<Circle>(10), Vector2(20, 300));
    circleObject.setVelocity(100.0f);
    circleObject.setDirection(Vector2(1, 1));
    objects.emplace_back(std::move(circleObject));  // Moves object (GOOD)

    float spawnTimer = 0.0f;  // Track time for spawning objects

    while (running) {
        
        currentTime = chrono::high_resolution_clock::now();
        elapsedTime = currentTime - lastTime;
        deltaTime = elapsedTime.count(); // Time step in seconds
        lastTime = currentTime; // Update lastTime
    
        spawnTimer += deltaTime;  // Accumulate time
    
        // Spawn object only every 0.3 seconds
        if(objects.size()<=100)
        {
            if (spawnTimer >= 0.3f) {
                spawnTimer = 0.0f;  // Reset timer
        
                Object circleObject2(std::make_unique<Circle>(10), Vector2(10, 300));
                circleObject2.setVelocity(100.0f);
                circleObject2.setDirection(Vector2(1, 1));
                objects.emplace_back(std::move(circleObject2));  // Moves object (GOOD)
            }
        }
    
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    
        renderer.clear();
    
        // 🔹 Call Collision Detection
        colDetector.CheckCollisions(objects);
    
        // 🔹 Update all objects
        for (auto& obj : objects) {
            obj.CalculateNextPosGravity(deltaTime);
        }
    
        // 🔹 Draw all objects with safe coloring
        for (size_t i = 0; i < objects.size(); i++) {
            int red = std::min(255, static_cast<int>(i * 10));
            int green = std::min(255, static_cast<int>(i * 5));
            int blue = std::min(255, static_cast<int>(i * 2));
            renderer.drawObject(objects[i], SDL_Color(red, green, blue, 255));
        }
    
        renderer.present();
    }
    

    cout<<"//---------------------------------------------------//"<<endl;
    cout<<"//--------------Exiting main loop--------------------//"<<endl;
    cout<<"//---------------------------------------------------//"<<endl;

    cout<<"//---------------------------------------------------//"<<endl;
    cout<<"//--------------PHYSICS ENGINE END-------------------//"<<endl;
    cout<<"//---------------------------------------------------//"<<endl;
    
    return 0;
}
