#include "../include/game.hpp"
#include "../include/graphics.hpp"
#include "../include/input.hpp"
#include "SDL3/SDL_keyboard.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_timer.h"
#include "SDL3/SDL_video.h"
#include <iostream>

void Yak::gameLoop(std::optional<std::pair<SDL_Window*, SDL_Renderer*>>& windowRenderer) {
    bool done = false;

    const float spriteSpeed = 200.0f;
    auto        sprite = Yak::drawSprite("/Users/ilias/projects/Yak/dog.png", windowRenderer);

    Uint64 lastTime = SDL_GetPerformanceCounter();
    while (!done) {
        done = Yak::getNextEvent(done);
        float deltaTime = Yak::getDeltaTime(lastTime);
        lastTime = SDL_GetPerformanceCounter();

        // process input
        const bool* keyState = SDL_GetKeyboardState(nullptr);
        if (keyState[SDL_SCANCODE_W]) {
            sprite.value().first.y -= spriteSpeed * deltaTime;
        }
        if (keyState[SDL_SCANCODE_S]) {
            sprite.value().first.y += spriteSpeed * deltaTime;
        }
        if (keyState[SDL_SCANCODE_A]) {
            sprite.value().first.x -= spriteSpeed * deltaTime;
        }
        if (keyState[SDL_SCANCODE_D]) {
            sprite.value().first.x += spriteSpeed * deltaTime;
        }

        // boundary clamping
        if (sprite.value().first.x < 0.0f) sprite.value().first.x = 0.0f;
        if (sprite.value().first.y < 0.0f) sprite.value().first.y = 0.0f;
        if (sprite.value().first.x + sprite.value().first.w > 800.0f)
            sprite.value().first.x = 800.0f - sprite.value().first.w;
        if (sprite.value().first.y + sprite.value().first.h > 600.0f)
            sprite.value().first.y = 600.0f - sprite.value().first.h;

        // render sprite
        SDL_SetRenderDrawColor(windowRenderer->second, 30, 30, 30, 255);
        SDL_RenderClear(windowRenderer->second);

        SDL_RenderTexture(windowRenderer.value().second, sprite.value().second, nullptr,
                          &sprite.value().first);
        SDL_RenderPresent(windowRenderer->second);
    }

    // cleanup
    SDL_DestroyTexture(sprite.value().second);
    SDL_DestroyRenderer(windowRenderer.value().second);
    SDL_DestroyWindow(windowRenderer.value().first);
    SDL_Quit();
}
