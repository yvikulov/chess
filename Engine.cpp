#include "Engine.hpp"

Engine::Engine()
{
    this->setEngineState(true);
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Error: " << SDL_GetError() << std::endl;
        this->setEngineState(false);
    }
    else
    {
        this->window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (this->window == nullptr)
        {
            std::cout << "Error: " << SDL_GetError() << std::endl;
            this->setEngineState(false);
        }
    }
}

Engine::~Engine()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Engine::start()
{
    if (this->getEngineState())
    {
        SDL_Event event;

        int mouse_x = 0;
        int mouse_y = 0;

        bool quit = false;
        while (!quit)
        {
            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        SDL_GetMouseState(&mouse_x, &mouse_y);
                        std::cout << "Index board position: " << mouse_x / (SCREEN_WIDTH / 8) << " " << mouse_y / (SCREEN_HEIGHT / 8) << std::endl;
                        break;
                }
            }
        }
    }
}

void Engine::setEngineState(bool state)
{
    this->_engine_state = state;
}

bool Engine::getEngineState(void)
{
    return this->_engine_state;
}
