#include "../include/input.hpp"
#include "SDL3/SDL_events.h"
#include <iostream>

bool Yak::getNextEvent(bool done) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            done = true;
            return done;
        }
    }
    // Do game logic, present a frame, etc.
    return done;
}
