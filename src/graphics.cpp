#include "../include/graphics.hpp"
#include "../include/window.hpp"
#include "SDL3/SDL_error.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_surface.h"
#include "SDL3_image/SDL_image.h"
#include <optional>

std::optional<std::pair<SDL_FRect, SDL_Texture*>>
Yak::drawSprite(const std::string&                                    filename,
                std::optional<std::pair<SDL_Window*, SDL_Renderer*>>& windowRenderer) {
    // create surface
    SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
    if (!loadedSurface) {
        SDL_Log("Failed to load sprite %s", SDL_GetError());
        Yak::destroyWindowAndRenderer(windowRenderer);
        return std::nullopt;
    }

    // create texture
    SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(windowRenderer->second, loadedSurface);
    if (!spriteTexture) {
        SDL_Log("Failed to create texture %s", SDL_GetError());
        SDL_DestroySurface(loadedSurface);
        Yak::destroyWindowAndRenderer(windowRenderer);
        return std::nullopt;
    }

    // create sprite and set sprite speed
    SDL_FRect spriteRect = {100.0f, 100.0f, static_cast<float>(loadedSurface->w),
                            static_cast<float>(loadedSurface->h)};
    SDL_DestroySurface(loadedSurface);

    return std::make_pair(spriteRect, spriteTexture);
}
