#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#define GAME_NAME "Chess"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

class Engine
{
public:
    Engine()
    {
        this->setEngineState(true);
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            printf("[err]: SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
            this->setEngineState(false);
        }
        else
            this->initWindow();
    }

    void initWindow(void)
    {
        this->window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (this->window == nullptr)
        {
            printf("[err]: Window could not be created! SDL_Error: %s\n", SDL_GetError());
            this->setEngineState(false);
        }
    }

    void setEngineState(bool state)
    {
        this->_engine_state = state;
    }

    bool getEngineState(void)
    {
        return this->_engine_state;
    }

    void start()
    {
        if (this->getEngineState())
        {
            this->screenSurface = SDL_GetWindowSurface( window );

            SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB( this->screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            SDL_UpdateWindowSurface( this->window );

            SDL_Event e;
            bool quit = false;
            while (!quit){
                while (SDL_PollEvent(&e)){
                    if (e.type == SDL_QUIT){
                        quit = true;
                    }
                    if (e.type == SDL_KEYDOWN){
                        quit = true;
                    }
                    if (e.type == SDL_MOUSEBUTTONDOWN){
                        quit = true;
                    }
                }
            }

            SDL_DestroyWindow(this->window);
            SDL_Quit();
        }
    }

private:

    bool _engine_state;
    
    SDL_Window* window;
    SDL_Surface* screenSurface;
};