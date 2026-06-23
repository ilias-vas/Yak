#include "../vendored/miniaudio/miniaudio.hpp"
#include <optional>
#include <string>

namespace Yak {
    std::optional<ma_engine*> initAudioEngine();
    void playSoundOnce(const std::string& filename, ma_engine* engine);
    void cleanupAudioEngine(ma_engine* engine);
}
