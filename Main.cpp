#include "Object.h"
#include "Circle.h"
#include "Renderer.h"

#include <iostream>
#include <chrono>

using namespace std;    

int main(int argc, char* argv[]) {

    cout<<"//---------------------------------------------------//"<<endl;
    cout<<"//--------------PHYSICS ENGINE START-----------------//"<<endl;
    cout<<"//---------------------------------------------------//"<<endl;
    Object circleObject(std::make_unique<Circle>(50), Vector2(400, 300));
    circleObject.setVelocity(50.0f);
    circleObject.setDirection(Vector2(-1,1));

    bool running = true;
    SDL_Event event;
    Renderer renderer( 800, 600);
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        renderer.clear();
        
        //Get Position
        circleObject.CalculateNextPos();

        renderer.drawObject(circleObject);
        renderer.present();

        //SDL_Delay(16); // 60 FPS
    }

    cout<<"//---------------------------------------------------//"<<endl;
    cout<<"//--------------PHYSICS ENGINE END-------------------//"<<endl;
    cout<<"//---------------------------------------------------//"<<endl;
    return 0;
}

