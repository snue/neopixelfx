// NeoPixelFX library
// ==================
//
// Effects for NeoPixel strips based on the combination
// of C++ template based mutators and generators.
//
// Author: Stefan Nuernberger <kabelfrickler@gmail.com>
// License: LGPLv3 (see COPYING for details)

#ifndef NEOPIXELFX_MUTATORS_H
#define NEOPIXELFX_MUTATORS_H

template<uint16_t MIN, uint16_t MAX, typename FX>
class confined {
  FX chain_fx;
public:
  confined(const Adafruit_NeoPixel &pixel) : chain_fx(pixel) {}

  uint32_t getPixelColor(uint16_t pos) const {
    if ((MIN <= pos) && (pos <= MAX)) {
      return chain_fx.getPixelColor(pos);
    } else {
      return 0;
    }
  }

  void update() {
    chain_fx.update();
  }
};

template<uint16_t DISTANCE, bool WRAP, typename FX>
class moving {
  const Adafruit_NeoPixel &pixels;
  FX chain_fx;
  uint16_t offset;
  bool forward;

public:
  moving(const Adafruit_NeoPixel &pixel)
    : pixels(pixel), chain_fx(pixel), offset(0), forward(true)
  {}

  uint32_t getPixelColor(uint16_t pos) const {
    uint16_t mpos = (pos + offset) % pixels.numPixels();
    return chain_fx.getPixelColor(mpos);
  }

  void update() {
    if (forward) {
      if (offset == DISTANCE) {
        // need to wrap or turn
        offset = WRAP ? 0 : offset - 1;
        forward ^= WRAP ? 0 : 1;
      } else {
        offset++;
      }
    } else {
      if (offset == 0) {
        // need to wrap or turn
        offset = WRAP ? DISTANCE : 1;
        forward ^= WRAP ? 0 : 1;
      } else {
        offset--;
      }
    }
    
    chain_fx.update();
  }
};

#endif
