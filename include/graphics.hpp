#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <optional>
#include <utility>
#include "alias.hpp"


namespace Yak {
    spritePair drawSprite(const std::string& filename, winRen windowRenderer, float x, float y);
    void renderSprite(winRen windowRenderer, spritePair sprite);
    void bindSpriteToWindow(spritePair& sprite, float width, float height);
}

#endif
