#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <string>
#include "Object.h"  // Include your Object class

class Renderer {
private:
    SDL_Window* window;
    SDL_Renderer* _renderer;
    int _width, _height;
    std::string _title;
public:
    Renderer(int w, int h);
    Renderer(std::string string,int w, int h);
    ~Renderer();
    void clear();
    void drawObject(const Object& obj);
    void present();
};

#endif
