#ifndef WINDOW_H
#define WINDOW_H

#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <optional>
#include <string>
#include "alias.hpp"


namespace Yak {
    SDL_Window* createWindow(const std::string& title, int w, int h);
    std::optional<std::pair<SDL_Window*, SDL_Renderer*>> createWindowAndRenderer(const std::string& title,int w, int h);
    void destroyWindow(SDL_Window* window);
    void destroyWindowAndRenderer(const std::optional<std::pair<SDL_Window*, SDL_Renderer*>>& windowRenderer);
    void cleanupAfterSprite(winRen windowRenderer, spritePair sprite);
}  // namespace Yak

#endif
