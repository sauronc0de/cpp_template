#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <stdexcept>

class RenderingSystemAO
{
private:
  static constexpr size_t screen_width = 640;
  static constexpr size_t screen_height = 480;
  SDL_Window *window = nullptr;
  SDL_Surface *screenSurface = nullptr;
  SDL_Renderer *renderer = nullptr;
  SDL_Texture *playerTex;
  SDL_Rect playerRect = {8, 8, 64, 64};
  SDL_Texture *CreateCircleTexture(SDL_Renderer *renderer, int radius)
  {
    int diameter = radius * 2;
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, diameter, diameter);
    if(!texture)
      return nullptr;

    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // Transparent background
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White circle

    for(int y = -radius; y <= radius; y++)
    {
      for(int x = -radius; x <= radius; x++)
      {
        if(x * x + y * y <= radius * radius)
        {
          SDL_RenderDrawPoint(renderer, x + radius, y + radius);
        }
      }
    }

    SDL_SetRenderTarget(renderer, nullptr);
    return texture;
  }

public:
  RenderingSystemAO()
  {
    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      throw std::runtime_error(std::string("Could not initialize SDL2: ") + SDL_GetError());
    }

    // Init window
    window = SDL_CreateWindow("DnT4", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, screen_width,
                              screen_height, SDL_WINDOW_SHOWN);
    if(!window)
    {
      throw std::runtime_error(std::string("could not create window: ") + SDL_GetError());
    }

    // Init renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    {
      throw std::runtime_error(std::string("could not create renderer: ") + SDL_GetError());
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_Delay(2000);
  }

  ~RenderingSystemAO()
  {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
  }

  void update()
  {
    playerTex = CreateCircleTexture(renderer, 50);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTex, NULL, &playerRect);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
  }
};