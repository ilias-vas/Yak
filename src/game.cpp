#include "../include/game.hpp"
#include "SDL3/SDL_video.h"
void engine::loop(SDL_Window* window) {
    bool done = false;
    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }

        // Do game logic, present a frame, etc.
        // Close and destroy the window
        SDL_DestroyWindow(window);

        // Clean up
        SDL_Quit();
    }
}
