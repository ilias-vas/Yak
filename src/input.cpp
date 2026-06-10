#include "../include/input.hpp"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_timer.h"
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
