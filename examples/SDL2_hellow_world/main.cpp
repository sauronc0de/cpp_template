// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <string>

SDL_Texture *playerTex;
SDL_Rect playerRect = {8, 8, 64, 64};
SDL_Rect playerRect2 = {128, 128, 64, 64};

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#ifndef ASSETS_PATH
#define ASSETS_PATH "/assets/path/"
#endif

int main(int argc, char *args[])
{
  std::string assetPath = ASSETS_PATH;
  std::string imagePath = assetPath + "/img/surrender.png";

  SDL_Window *window = NULL;
  SDL_Surface *screenSurface = NULL;

  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    return 1;
  }
  window = SDL_CreateWindow("hello_sdl2", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if(window == NULL)
  {
    fprintf(stderr, "could not create window: %s\n", SDL_GetError());
    return 1;
  }

  // Add render here
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_Surface *tmpSurface = IMG_Load(imagePath.c_str());
  playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, playerTex, NULL, &playerRect);
  SDL_RenderCopy(renderer, playerTex, NULL, &playerRect2);
  SDL_RenderPresent(renderer);

  SDL_Delay(2000);
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  return 0;
}
