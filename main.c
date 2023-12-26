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

void init_palette(paint_state *paint_state)
{
    // Initialize palette background
    paint_state->p.background = (SDL_Rect){480, 0, 160, 480};

    // Initialize colours
    paint_state->p.colours[0] = (colours){490, 90, 60, 60, 255, 0, 0, 255};
    paint_state->p.colours[1] = (colours){570, 90, 60, 60, 0, 255, 0, 255};

    paint_state->p.colours[2] = (colours){490, 170, 60, 60, 0, 0, 255, 255};
    paint_state->p.colours[3] = (colours){570, 170, 60, 60, 255, 255, 0, 255};

    paint_state->p.colours[4] = (colours){490, 250, 60, 60, 255, 0, 255, 255};
    paint_state->p.colours[5] = (colours){570, 250, 60, 60, 0, 255, 255, 255};

    paint_state->p.colours[6] = (colours){490, 330, 60, 60, 0, 0, 0, 255};
    paint_state->p.colours[7] = (colours){570, 330, 60, 60, 255, 255, 255, 255};

    // Initialize save button
    paint_state->p.save_btn = (SDL_Rect){490, 10, 140, 60};
}

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
    // Render the palette rectangle
    SDL_SetRenderDrawColor(renderer, 228, 228, 228, 255);
    SDL_RenderFillRect(renderer, &palette->background);

    // Render save button. Will use pink for now as a replacement for text
    SDL_SetRenderDrawColor(renderer, 255, 50, 255, 255);
    SDL_RenderFillRect(renderer, &palette->save_btn);

    // Render colour boxes
    for (int i  = 0; i < 8; i++)
    {
        SDL_Rect current_colour = {palette->colours[i].x, palette->colours[i].y,
                                   palette->colours[i].width, palette->colours[i].height};
        SDL_SetRenderDrawColor(renderer, palette->colours[i].r, palette->colours[i].g,
                               palette->colours[i].b, palette->colours[i].a);
        SDL_RenderFillRect(renderer, &current_colour);
    }
}

void draw_grid(SDL_Renderer *renderer, int x, int y, int w, int h, int size)
{
    SDL_SetRenderDrawColor(renderer, 61, 61, 61, 255);

    for (int i = x + size; i < x + w; i += size)
    {
        SDL_RenderDrawLine(renderer, i, y, i, y + h);
    }

    for (int i = y + size; i < y + h; i += size)
    {
        SDL_RenderDrawLine(renderer, x, i, x + w, i);
    }
}

void render_screen(SDL_Renderer *renderer, paint_state *paint_state)
{
    // Render a white screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderClear(renderer);

    // Draw palette on right side of screen
    draw_palette(renderer, &paint_state->p);

    // Draw grid on left side of screen
    draw_grid(renderer, 0, 0, 480, 480, 20);

    SDL_RenderPresent(renderer);
}



int main(int argc, char *argv[])
{
    paint_state paint_state;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);
    init_palette(&paint_state);

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

        render_screen(renderer, &paint_state);

       // SDL_Delay(20);
    }
    return 0;
}
