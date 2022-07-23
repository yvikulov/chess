#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#define GAME_NAME "Chess"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

class Engine
{
public:
    Engine();
    ~Engine();

    void start();

    void setEngineState(bool state);
    bool getEngineState(void);

private:

    bool _engine_state;
    
    SDL_Window* window;
    SDL_Surface* screenSurface;
};