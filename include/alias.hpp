#pragma once

#include <optional>
#include <SDL3/SDL.h>

using winRen = std::optional<std::pair<SDL_Window*, SDL_Renderer*>>;
using spritePair = std::optional<std::pair<SDL_FRect, SDL_Texture*>>;
