#include "esphome.h"
namespace esphome {
namespace noise_meter {
class NoiseMeter : public PollingComponent, public Sensor {
 public:
  explicit NoiseMeter(microphone::I2SAudioComponent *mic)
    : PollingComponent(1000), mic_(mic) {}
  void update() override;
 private:
  microphone::I2SAudioComponent *mic_;
};
} // namespace noise_meter
} // namespace esphome
