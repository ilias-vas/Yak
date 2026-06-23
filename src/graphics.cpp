#include "../include/graphics.hpp"
#include "../include/window.hpp"
#include "SDL3/SDL_error.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_surface.h"
#include "SDL3_image/SDL_image.h"
#include <optional>

spritePair Yak::drawSprite(const std::string& filename, winRen windowRenderer, float x, float y) {
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

    // create sprite and set sprite pos
    SDL_FRect spriteRect = {x, y, static_cast<float>(loadedSurface->w),
                            static_cast<float>(loadedSurface->h)};
    SDL_DestroySurface(loadedSurface);

    return std::make_pair(spriteRect, spriteTexture);
}

void Yak::renderSprite(winRen& windowRenderer, spritePair sprite) {
    SDL_SetRenderDrawColor(windowRenderer->second, 30, 30, 30, 255);
    SDL_RenderClear(windowRenderer->second);
    SDL_RenderTexture(windowRenderer.value().second, sprite.value().second, nullptr,
                      &sprite.value().first);
    SDL_RenderPresent(windowRenderer->second);
}

void Yak::bindSpriteToWindow(spritePair& sprite, float width, float height) {
    if (sprite.value().first.x < 0.0f) sprite.value().first.x = 0.0f;
    if (sprite.value().first.y < 0.0f) sprite.value().first.y = 0.0f;
    if (sprite.value().first.x + sprite.value().first.w > width)
        sprite.value().first.x = width - sprite.value().first.w;
    if (sprite.value().first.y + sprite.value().first.h > height)
        sprite.value().first.y = height - sprite.value().first.h;
}
