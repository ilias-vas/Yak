#include "../include/game.hpp"
#include "../include/input.hpp"
#include "SDL3/SDL_video.h"
#include <iostream>

void Yak::gameLoop(SDL_Window* window) {
    bool done = false;
    while (!done) {
        done = Yak::getNextEvent(done);
    }
}
