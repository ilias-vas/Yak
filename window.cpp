#include "window.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_Window* engine::createWindow(std::string title, int w, int h) {
    SDL_Window* window;        // Declare a pointer
    SDL_Init(SDL_INIT_VIDEO);  // Initialize SDL3

    // Create an application window with the following settings:
    window = SDL_CreateWindow(title.c_str(),     // window title
                              w,                 // width, in pixels
                              h,                 // height, in pixels
                              SDL_WINDOW_OPENGL  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return nullptr;
    }

    return nullptr;
}
