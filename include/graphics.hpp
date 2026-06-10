#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <optional>
#include <utility>

namespace Yak {
    std::optional<std::pair<SDL_FRect, SDL_Texture*>>
    drawSprite(const std::string&                                    filename,
               std::optional<std::pair<SDL_Window*, SDL_Renderer*>>& windowRenderer);
}

#endif
