#include "include/editor.hpp"
#include "include/game.hpp"
#include "include/graphics.hpp"
#include "include/window.hpp"

int main() {
    auto w{Yak::createWindow("test", 500, 500)};
    Yak::gameLoop(w);
    Yak::destroyWindow(w);
}
