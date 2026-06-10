#include "../include/window.hpp"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_surface.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <optional>
#include <utility>

SDL_Window* Yak::createWindow(const std::string& title, int w, int h) {
    SDL_Window* window = nullptr;
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Failed to initialise SDL %s", SDL_GetError());
    }

    window = SDL_CreateWindow(title.c_str(),     // window title
                              w,                 // width, in pixels
                              h,                 // height, in pixels
                              SDL_WINDOW_OPENGL  // flags - see below
    );

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return nullptr;
    }

    return window;
}

std::optional<std::pair<SDL_Window*, SDL_Renderer*>> Yak::createWindowAndRenderer(const std::string& title,
                                                                                  int w, int h) {
    SDL_Window*   window = nullptr;
    SDL_Renderer* renderer = nullptr;
    if (!SDL_CreateWindowAndRenderer(title.c_str(), w, h, SDL_WINDOW_OPENGL, &window, &renderer)) {
        SDL_Log("Failed to create window and renderer %s", SDL_GetError());
        SDL_Quit();
        return std::nullopt;
    }
    return std::make_pair(window, renderer);
}

void Yak::destroyWindow(SDL_Window* window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
    return;
}

void Yak::destroyWindowAndRenderer(
        const std::optional<std::pair<SDL_Window*, SDL_Renderer*>>& windowRenderer) {
    SDL_DestroyRenderer(windowRenderer->second);
    SDL_DestroyWindow(windowRenderer->first);
    SDL_Quit();
    return;
}
