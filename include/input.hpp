#pragma once

#include "SDL3/SDL_stdinc.h"
#include "alias.hpp"

namespace Yak {
    bool  getNextEvent(bool done);
    float getDeltaTime(Uint64 lastTime);
    void moveSprite(const bool* keyState, spritePair& sprite, const float spriteSpeed, float deltaTime);
} 
