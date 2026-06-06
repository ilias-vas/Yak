#include "../include/window.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_Window* engine::createWindow(std::string title, int w, int h) {
    SDL_Window* window;        // Declare a pointer
    SDL_Init(SDL_INIT_VIDEO);  // Initialize SDL3

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    }

    // Create an application window with the following settings:
    window = SDL_CreateWindow(title.c_str(),     // window title
                              w,                 // width, in pixels
                              h,                 // height, in pixels
                              SDL_WINDOW_OPENGL  // flags - see below
    );

    return nullptr;
}
