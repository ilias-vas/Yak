#include "../include/audio.hpp"
#include <iostream>
#include <optional>

std::optional<ma_engine*> Yak::initAudioEngine() {
    ma_result result;
    ma_engine* engine = new ma_engine;

    result = ma_engine_init(NULL, engine);
    if (result != MA_SUCCESS) {
        return std::nullopt;
    }

    return engine;
}

void Yak::playSoundOnce(const std::string& filename, ma_engine* engine) {
    ma_engine_play_sound(engine, filename.c_str(), nullptr);
}

void Yak::cleanupAudioEngine(ma_engine* engine) {
    ma_engine_uninit(engine);
}
