#ifndef INPUT_H
#define INPUT_H

#include "SDL3/SDL_stdinc.h"
namespace Yak {
    bool  getNextEvent(bool done);
    float getDeltaTime(Uint64 lastTime);
}  // namespace Yak

#endif
