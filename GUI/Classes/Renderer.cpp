#include "Renderer.h"
#include "RendererParm.h"
#include "Circle.h"

#include <iostream>

//Creating SDL2 window in constructor
Renderer::Renderer(int w, int h) : _width(w), _height(h) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Init Error: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow("Physics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL Window Error: " << SDL_GetError() << std::endl;
    }

    _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer) {
        std::cerr << "SDL Renderer Error: " << SDL_GetError() << std::endl;
    }

    _title=WINDOWTITLE;
}

Renderer::Renderer(std::string istring, int w, int h): _title(istring), _width(w), _height(h)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Init Error: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow("Physics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL Window Error: " << SDL_GetError() << std::endl;
    }

    _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!_renderer) {
        std::cerr << "SDL Renderer Error: " << SDL_GetError() << std::endl;
    }
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void DrawCircle(SDL_Renderer* ipRenderer, int iRadius, Vector2 iCentre)
{
    double centreX = 0, centreY = 0;
    iCentre.getVector2(centreX, centreY);

    for (int i = 0; i < iRadius * 2; i++)
    {
        for (int j = 0; j < iRadius * 2; j++)
        {
            int dx = iRadius - i;
            int dy = iRadius - j;
            if ((dx * dx + dy * dy) <= (iRadius * iRadius)) {
                SDL_RenderDrawPoint(ipRenderer, centreX + dx, centreY + dy);
            }
        }
    }
}

void  Renderer::drawObject(const Object& obj)
{
    //Object type
    Shape2* Shape       = obj.getShape();
    SHAPETYPE shapeType = Shape->getShapeType();
    Vector2 pos         = obj.getPosition();
    Circle* circle = nullptr;
    Vector2 centre;
    int radii = 0;
    SDL_SetRenderDrawColor(_renderer, 255, 255,255, 255);

    switch (shapeType)
    {
    case CIRCLE:
        circle = dynamic_cast<Circle*>(obj.getShape()); // Safe cast
        centre = pos;
        radii = circle->getRadius();
        DrawCircle(_renderer,radii,centre);
        break;
    case RECTANGLE:
        break;
    
    case TRIANGLE:
        break;
    
    case SQUARE:
        break;
    
    default:
        break;
    }
    
}

void Renderer::present()
{
    SDL_RenderPresent(_renderer);
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255); // Black background
    SDL_RenderClear(_renderer);
}
