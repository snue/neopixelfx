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

class CurrentColor {
  const Adafruit_NeoPixel &pixels;
public:
  CurrentColor(const Adafruit_NeoPixel &pixel) : pixels(pixel) {}

  uint32_t getPixelColor(uint16_t pos) const {
    return pixels.getPixelColor(pos % pixels.numPixels());
  }

  void update() {
  }
};

class RandomColor {
  uint32_t color;
public:
  RandomColor(const Adafruit_NeoPixel&) : color(0) {}

  uint32_t getPixelColor(uint16_t pos) const {
    return color;
  }

  void update() {
    uint8_t r = 0, g = 0, b = 0;

    uint8_t assign = random(7) + 1;
    if (assign & 0x1) {
      r = random(256);
    }
    if (assign & 0x2) {
      g = random(256);
    }
    if (assign & 0x4) {
      b = random(256);
    }
    color = Adafruit_NeoPixel::Color(r, g, b);
  }
};

template<uint32_t COLOR>
class ConstantColor {
public:
  ConstantColor(const Adafruit_NeoPixel &) {}

  uint32_t getPixelColor(uint16_t /* pos */) const {
    return COLOR;
  }

  void update() {
    // Constant color is constant.
  }
};

template<uint8_t R, uint8_t G, uint8_t B>
class ConstantRGBColor {
public:
  ConstantRGBColor(const Adafruit_NeoPixel &) {}

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

template<uint16_t WIDTH>
class Rainbow {
public:
  Rainbow(const Adafruit_NeoPixel &) {}
  enum {
    FULL = WIDTH/6,
    STEP = 0xff / FULL
  };

  uint32_t getPixelColor(uint16_t pos) const {
    uint16_t phase = (pos % WIDTH) * 6 / WIDTH;
    uint16_t amount = (pos % WIDTH) - (phase * FULL);

    switch (phase) {
    case 0:
      return Adafruit_NeoPixel::Color(0xff, amount * STEP, 0);
    case 1:
      return Adafruit_NeoPixel::Color(0xff - (amount * STEP), 0xff, 0);
    case 2:
      return Adafruit_NeoPixel::Color(0, 0xff, amount * STEP);
    case 3:
      return Adafruit_NeoPixel::Color(0, 0xff - (amount * STEP), 0xff);
    case 4:
      return Adafruit_NeoPixel::Color(amount * STEP, 0, 0xff);
    case 5:
      return Adafruit_NeoPixel::Color(0xff, 0, 0xff - (amount * STEP));
    default:
      // should not happen
      return Adafruit_NeoPixel::Color(0, 0, 0);
    }
  }

  void update() {
  }
};

// Rainbow with a more uniform luminosity
template<uint16_t WIDTH>
class Rainbow2 {
public:
  Rainbow2(const Adafruit_NeoPixel &) {}
  enum {
        FULL = WIDTH/3,
        STEP = 0xff / FULL
  };

  uint32_t getPixelColor(uint16_t pos) const {
    uint16_t phase = (pos % WIDTH) * 3 / WIDTH;
    uint16_t amount = (pos % WIDTH) - (phase * FULL);

    switch (phase) {
    case 0:
      return Adafruit_NeoPixel::Color(0xff - (amount * STEP), amount * STEP, 0);
    case 1:
      return Adafruit_NeoPixel::Color(0, 0xff - (amount * STEP), amount * STEP);
    case 2:
      return Adafruit_NeoPixel::Color(amount * STEP, 0, 0xff - (amount * STEP));
    default:
      // should not happen
      return Adafruit_NeoPixel::Color(0, 0, 0);
    }
  }

  void update() {
  }
};

#endif
