#include <stdio.h>
#include <SDL2/SDL.h>

#define GAME_WINDOW_WIDTH  640
#define GAME_WINDOW_HEIGHT 480
#define GAME_WINDOW_FLAGS 0
#define GAME_WINDOW_BACKGROUND_RGBA 90, 90, 90, 255 


int main(void) {
    SDL_Window *window;
    SDL_Renderer *renderer;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
    // create window
    window = SDL_CreateWindow("Shoot'em down!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT, GAME_WINDOW_FLAGS);
    if(!window)
    {
      printf("Couldn't create SDL window: %s\n", SDL_GetError());
      exit(1);
    }

    // create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer)
    {
      printf("Couldn't create SDL renderer: %s\n", SDL_GetError());
      exit(1);
    }

    // render background
    SDL_SetRenderDrawColor(renderer, GAME_WINDOW_BACKGROUND_RGBA);
    SDL_RenderClear(renderer);

    
    // present the renderer
    SDL_RenderPresent(renderer);

    // keep the window displayed until the user closes it
    SDL_Event e;
    ushort quit = 0;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = 1;
            }
            if (e.type == SDL_KEYDOWN){
                quit = 1;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = 1;
            }
        }
    }

    // close and destroy the window and renderer
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // clean up
    SDL_Quit();
    return 0;
}
