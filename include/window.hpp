#ifndef WINDOW_H
#define WINDOW_H

#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

namespace Yak {
    SDL_Window* createWindow(std::string title, int w, int h);
    void        destroyWindow(SDL_Window* window);
}  // namespace Yak

#endif
