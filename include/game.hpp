#ifndef GAME_H
#define GAME_H

#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <optional>
#include <utility>

namespace Yak {
    void gameLoop(std::optional<std::pair<SDL_Window*, SDL_Renderer*>>& windowRenderer);
}

#endif
