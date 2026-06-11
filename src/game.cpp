#include "../include/game.hpp"
#include "../include/graphics.hpp"
#include "../include/input.hpp"
#include "../include/window.hpp"
#include "SDL3/SDL_keyboard.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_timer.h"
#include <iostream>

void Yak::gameLoop(winRen& windowRenderer) {
    bool done = false;

    const float spriteSpeed = 500.0f;
    spritePair sprite = Yak::drawSprite("/Users/ilias/projects/yak/dog.png", windowRenderer, 0, 0);

    Uint64 lastTime = SDL_GetPerformanceCounter();
    while (!done) {
        done = Yak::getNextEvent(done);
        float deltaTime = Yak::getDeltaTime(lastTime);
        lastTime = SDL_GetPerformanceCounter();

        const bool* keyState = SDL_GetKeyboardState(nullptr);
        Yak::moveSprite(keyState, sprite, spriteSpeed, deltaTime);

        Yak::bindSpriteToWindow(sprite, 800, 600);

        Yak::renderSprite(windowRenderer, sprite);
    }
    Yak::cleanupAfterSprite(windowRenderer, sprite);
}
