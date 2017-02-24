// NeoPixelFX library
// ==================
//
// Effects for NeoPixel strips based on the combination
// of C++ template based mutators and generators.
//
// Author: Stefan Nuernberger <kabelfrickler@gmail.com>
// License: LGPLv3 (see COPYING for details)

#ifndef NEOPIXELFX_GENERATORS_H
#define NEOPIXELFX_GENERATORS_H

class RandomColor {
  uint32_t color;
public:
 RandomColor(const Adafruit_NeoPixel&) : color(0) {}

  uint32_t getPixelColor(uint16_t pos) const {
    return color;
  }

  void update() {
    color = Adafruit_NeoPixel::Color(random(156), random(156), random(156));
  }
};

template<uint8_t R, uint8_t G, uint8_t B>
class ConstantColor {
public:
  ConstantColor(const Adafruit_NeoPixel &) {}

  uint32_t getPixelColor(uint16_t pos) const {
    return Adafruit_NeoPixel::Color(R, G, B);
  }

    void update() {
    // Constant color is constant.
  }
};

template<uint16_t PERIOD, uint16_t PHASE_R = 0, uint16_t PHASE_G = 0, uint16_t PHASE_B = 0>
class SineWave {
public:
  SineWave(const Adafruit_NeoPixel &) {}

  uint32_t getPixelColor(uint16_t pos) const {
    // TODO: do some neat trigonometry
    return Adafruit_NeoPixel::Color(0, 0, 0);
    // return {sin_color(pos + PHASE_R), sin_color(pos + PHASE_G), sin_color(pos + PHASE_B)};
  }

  void update() {
  }
};

#endif
