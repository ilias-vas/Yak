#include "include/game.hpp"
#include "include/window.hpp"
#include "include/audio.hpp"
#include "vendored/miniaudio/miniaudio.hpp"

int main() {
    auto w = Yak::createWindowAndRenderer("test", 800, 600);
    Yak::gameLoop(w);
}
