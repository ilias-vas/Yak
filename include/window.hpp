#pragma once

#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <memory>
#include <string>

namespace engine {
    SDL_Window* createWindow(std::string title, int w, int h);
}  // namespace engine
