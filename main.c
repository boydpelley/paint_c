#include <stdio.h>
#include "SDL2/SDL.h"

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Paint Window",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              640,
                              480,
                              0
                              );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    short done = 0;
    SDL_Event event;

    while (!done)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_WINDOWEVENT_CLOSE:
                {
                    if (window)
                    {
                        SDL_DestroyWindow(window);
                        window = NULL;
                        done = 1;
                    }
                }
                break;
                case SDL_KEYDOWN:
                {
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        {
                            done = 1;
                            break;
                        }
                    }
                }
                break;
                case SDL_QUIT:
                {
                    done = 1;
                }
                break;
            }
        }
    }
    return 0;
}
