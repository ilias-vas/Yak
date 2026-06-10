#include "include/editor.hpp"
#include "include/game.hpp"
#include "include/graphics.hpp"
#include "include/window.hpp"

int main() {
    auto w = Yak::createWindowAndRenderer("test", 800, 600);
    Yak::gameLoop(w);
}
