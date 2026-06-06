#include "game.hpp"
#include "window.hpp"

int main() {
    auto w = engine::createWindow("Test", 1920, 1080);
    engine::loop(w);
}
