#include "../include/input.hpp"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_timer.h"
#include "../include/alias.hpp"
#include <cstdint>
#include <iostream>

bool Yak::getNextEvent(bool done) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            done = true;
            return done;
        }
    }
    return done;
}

float Yak::getDeltaTime(Uint64 lastTime) {
    Uint64 currentTime = SDL_GetPerformanceCounter();
    float  deltaTime = (currentTime - lastTime) / static_cast<float>(SDL_GetPerformanceFrequency());
    return deltaTime;
}

void Yak::moveSprite(const bool* keyState, spritePair& sprite, const float spriteSpeed, float deltaTime) {
    if (keyState[SDL_SCANCODE_W]) {
        sprite.value().first.y -= spriteSpeed * deltaTime;
    }
    if (keyState[SDL_SCANCODE_S]) {
        sprite.value().first.y += spriteSpeed * deltaTime;
    }
    if (keyState[SDL_SCANCODE_A]) {
        sprite.value().first.x -= spriteSpeed * deltaTime;
    }
    if (keyState[SDL_SCANCODE_D]) {
        sprite.value().first.x += spriteSpeed * deltaTime;
    }
}
