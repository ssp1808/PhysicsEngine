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
    Object circleObject(std::make_unique<Circle>(20), Vector2(400, 300));
    circleObject.setVelocity(50.0f);
    circleObject.setDirection(Vector2(-1,1));

    Object circleObject2(std::make_unique<Circle>(20), Vector2(400, 300));
    circleObject2.setVelocity(50.0f);
    circleObject2.setDirection(Vector2(1,1));


    bool running = true;
    SDL_Event event;
    Renderer renderer( 800, 600);

    cout<<"//---------------------------------------------------//"<<endl;
    cout<<"//--------------Entering main loop-------------------//"<<endl;
    cout<<"//---------------------------------------------------//"<<endl;
    auto lastTime = chrono::high_resolution_clock::now();

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
        circleObject.CalculateNextPos(deltaTime);
        renderer.drawObject(circleObject);
        //Calculate Position
        circleObject2.CalculateNextPosGravity(deltaTime);
        renderer.drawObject(circleObject2);


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

