#define SDL_MAIN_HANDLED

#include "Object.h"
#include "Circle.h"
#include "Renderer.h"

#include <iostream>
#include <chrono>

using namespace std;    

int main(int argc, char* argv[]) 
{ 
    SDL_SetMainReady(); // Ensure SDL doesn't override main

    cout<<"//---------------------------------------------------//"<<endl;
    cout<<"//--------------PHYSICS ENGINE START-----------------//"<<endl;
    cout<<"//---------------------------------------------------//"<<endl;
    
    int radius1 = 10;
    Object circleObject(std::make_unique<Circle>(radius1), Vector2(300, 300));
    circleObject.setVelocity(100.0f);
    circleObject.setDirection(Vector2(-1,1));
    
    int radius2 = 20;
    Object circleObject2(std::make_unique<Circle>(radius2), Vector2(400, 300));
    circleObject2.setVelocity(100.0f);
    circleObject2.setDirection(Vector2(2,1));


    bool running = true;
    SDL_Event event;
    Renderer renderer( 800, 600);

    cout<<"//---------------------------------------------------//"<<endl;
    cout<<"//--------------Entering main loop-------------------//"<<endl;
    cout<<"//---------------------------------------------------//"<<endl;
    auto lastTime = chrono::high_resolution_clock::now();
    int dist = ((radius1+radius2)/2);

    while (running) {
        auto currentTime = chrono::high_resolution_clock::now();
        chrono::duration<float> elapsedTime = currentTime - lastTime;
        float deltaTime = elapsedTime.count(); // Time step in seconds
        lastTime = currentTime; // Update lastTime
    
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        renderer.clear();
        
        //Calculate Position
        circleObject.CalculateNextPosGravity(deltaTime);
        
        //Calculate Position
        circleObject2.CalculateNextPosGravity(deltaTime);
        Vector2 pos1 = circleObject.getPosition();
        Vector2 pos2 = circleObject2.getPosition();
        if((abs(pos1.x-pos2.x)<=dist)&&(abs(pos1.y-pos2.y)<=dist))//Collision detected
        {
            float vel1   = circleObject.getVelocity();
            Vector2 Dir1 = circleObject.getDirection();
            float vel2   = circleObject2.getVelocity();
            Vector2 Dir2 = circleObject2.getDirection();
            
            circleObject.setDirection(Dir2);
            circleObject.setVelocity(vel2);
            circleObject2.setDirection(Dir1);
            circleObject2.setVelocity(vel1);
        }
        
        //Draw the objects
        renderer.drawObject(circleObject,SDL_Color(255,0,0,255));
        renderer.drawObject(circleObject2,SDL_Color(255,255,0,255));
        
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

