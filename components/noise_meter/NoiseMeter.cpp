// NoiseMeter.cpp
#include "NoiseMeter.h"
#include <cmath>
namespace esphome {
namespace noise_meter {
void NoiseMeter::update() {
  auto &buf = this->mic_->get_pcm_buffer();
  if (buf.empty()) return;
  double sum = 0;
  for (auto sample : buf) {
    double v = double(sample) / 2147483648.0;
    sum += v*v;
  }
  double rms = std::sqrt(sum / buf.size());
  double db = 20.0 * std::log10(rms + 1e-12);
  this->publish_state(db);
}
} // namespace noise_meter
} // namespace esphome
