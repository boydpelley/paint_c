#include <stdio.h>
#include <SDL2/SDL.h>

typedef struct
{
    int x, y, width, height;
    Uint8 r, g, b, a;
} colours;

typedef struct
{
    SDL_Rect background;
    colours colours[8];
    SDL_Rect save_btn;
} palette;

typedef struct
{
    // Define the right side of the screen

    palette p;

} paint_state;

short process_events(SDL_Window *window)
{
    SDL_Event event;

    short done = 0;

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
    return done;
}

void draw_palette(SDL_Renderer *renderer, palette *palette)
{
    SDL_SetRenderDrawColor(renderer, )
}

void render_screen(SDL_Renderer *renderer)
{
    // Render a white screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void init_palette(paint_state *paint_state)
{
    // Initialize palette background
    paint_state->p.background = (SDL_Rect){480, 0, 160, 480};

    // Initialize colours
    paint_state->p.colours[0] =
}

int main(int argc, char *argv[])
{
    paint_state paint_state;
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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //paint_state.renderer = renderer;

    short done = 0;
    SDL_Event event;

    while (!done)
    {
        done = process_events(window);

        render_screen(renderer);

       // SDL_Delay(20);
    }
    return 0;
}
