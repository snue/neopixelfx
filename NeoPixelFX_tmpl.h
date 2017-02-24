// NeoPixelFX library
// ==================
//
// Effects for NeoPixel strips based on the combination
// of C++ template based mutators and generators.
//
// Author: Stefan Nuernberger <kabelfrickler@gmail.com>
// License: LGPLv3 (see COPYING for details)

#ifndef NEOPIXELFX_TMPL_H
#define NEOPIXELFX_TMPL_H

// Base template for an effects container. Multiple effects can be layered.
// The compose function template handles multiple overlapping effects on the strip.
// Currently up to 4 effects are supported. If you require more, you can regenerate
// this file for more effects using the generate_tmpl.py script.
template<compose_fn = compose_xor,
        typename FX1 = void,
        typename FX2 = void,
        typename FX3 = void,
        typename FX4 = void>
class NeoPixelFX;

// What follows is the partial template specialization for each number of supplied effects.
// The code is very repetitive and is therefore easily generated.

// The FX template class for a single effect on the strip
template<typename FX1>
class NeoPixelFX<compose_xor, FX1, void, void, void> {
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects
  FX1  fx;
  bool fx_enabled;

public:
  NeoPixelFX (Adafruit_NeoPixel& pixel)
    : pixels(pixel), fx(pixel), fx_enabled(true)
  {}

  // Show the current effects on the strip.
  void show() {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();

    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = fx.getPixelColor();
      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects.
  void update() {
    fx.update();
  }

  // Enable effects
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void enable(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0: case 1:
      fx_enabled = true;
      break;
    default: /* do nothing */
      break;
    }
  }

  // Disable effects
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void disable(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0: case 1:
      fx_enabled = false;
      break;
    default: /* do nothing */
      break;
    }
  }

  // Toggle effects
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void toggle(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0: case 1:
      fx_enabled ^= 1;
      break;
    default: /* do nothing */
      break;
    }
  }
};

// Partial template specialization for two effects
template<compose_fn COMP,
        typename FX1,
        typename FX2>
class NeoPixelFX<COMP, FX1, FX2, void, void> {
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects
  FX1  fx1;
  FX2  fx2;
  bool fx1_enabled, fx2_enabled;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel),
      fx1_enabled(true), fx2_enabled(true)
  {}

  // Show the current effects on the strip.
  void show() {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = fx1.getPixelColor(pos);
      val = COMP(val, fx2.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update() {
    fx1.update();
    fx2.update();
  }

  // Enable effects.
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void enable(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0:
      fx1_enabled = true;
      fx2_enabled = true;
      break;
    case 1:
      fx1_enabled = true;
      break;
    case 2:
      fx2_enabled = true;
      break;
    default: /* do nothing */
      break;
    }
  }

  // Disable effects.
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void disable(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0:
      fx1_enabled = false;
      fx2_enabled = false;
      break;
    case 1:
      fx1_enabled = false;
      break;
    case 2:
      fx2_enabled = false;
      break;
    default: /* do nothing */
      break;
    }
  }

  // Toggle effects.
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void toggle(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0:
      fx1_enabled ^= 1;
      fx2_enabled ^= 1;
      break;
    case 1:
      fx1_enabled ^= 1;
      break;
    case 2:
      fx2_enabled ^= 1;
      break;
    default: /* do nothing */
      break;
    }
  }
};

// Partial template specialization for three effects
template<compose_fn COMP,
        typename FX1,
        typename FX2,
        typename FX3>
class NeoPixelFX<COMP, FX1, FX2, FX3, void> {
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  bool fx1_enabled, fx2_enabled, fx3_enabled;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel),
      fx1_enabled(true), fx2_enabled(true), fx3_enabled(true)
  {}

  // Show the current effects on the strip.
  void show() {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = fx1.getPixelColor(pos);
      val = COMP(val, fx2.getPixelColor(pos));
      val = COMP(val, fx3.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update() {
    fx1.update();
    fx2.update();
    fx3.update();
  }

  // Enable effects.
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void enable(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0:
      fx1_enabled = true;
      fx2_enabled = true;
      fx3_enabled = true;
      break;
    case 1:
      fx1_enabled = true;
      break;
    case 2:
      fx2_enabled = true;
      break;
    case 3:
      fx3_enabled = true;
      break;
    default: /* do nothing */
      break;
    }
  }

  // Disable effects.
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void disable(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0:
      fx1_enabled = false;
      fx2_enabled = false;
      fx3_enabled = false;
      break;
    case 1:
      fx1_enabled = false;
      break;
    case 2:
      fx2_enabled = false;
      break;
    case 3:
      fx3_enabled = false;
      break;
    default: /* do nothing */
      break;
    }
  }

  // Toggle effects.
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void toggle(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0:
      fx1_enabled ^= 1;
      fx2_enabled ^= 1;
      fx3_enabled ^= 1;
      break;
    case 1:
      fx1_enabled ^= 1;
      break;
    case 2:
      fx2_enabled ^= 1;
      break;
    case 3:
      fx3_enabled ^= 1;
      break;
    default: /* do nothing */
      break;
    }
  }
};

// Partial template specialization for four effects
template<compose_fn COMP,
        typename FX1,
        typename FX2,
        typename FX3,
        typename FX4>
class NeoPixelFX {
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  bool fx1_enabled, fx2_enabled, fx3_enabled, fx4_enabled;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel),
      fx1_enabled(true), fx2_enabled(true), fx3_enabled(true), fx4_enabled(true)
  {}

  // Show the current effects on the strip.
  void show() {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = fx1.getPixelColor(pos);
      val = COMP(val, fx2.getPixelColor(pos));
      val = COMP(val, fx3.getPixelColor(pos));
      val = COMP(val, fx4.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update() {
    fx1.update();
    fx2.update();
    fx3.update();
    fx4.update();
  }

  // Enable effects.
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void enable(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0:
      fx1_enabled = true;
      fx2_enabled = true;
      fx3_enabled = true;
      fx4_enabled = true;
      break;
    case 1:
      fx1_enabled = true;
      break;
    case 2:
      fx2_enabled = true;
      break;
    case 3:
      fx3_enabled = true;
      break;
    case 4:
      fx4_enabled = true;
      break;
    default: /* do nothing */
      break;
    }
  }

  // Disable effects.
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void disable(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0:
      fx1_enabled = false;
      fx2_enabled = false;
      fx3_enabled = false;
      fx4_enabled = false;
      break;
    case 1:
      fx1_enabled = false;
      break;
    case 2:
      fx2_enabled = false;
      break;
    case 3:
      fx3_enabled = false;
      break;
    case 4:
      fx4_enabled = false;
      break;
    default: /* do nothing */
      break;
    }
  }

  // Toggle effects.
  // \param fx_num effect index starting at 1 (use 0 for 'all')
  void toggle(uint16_t fx_num = 0) {
    switch (fx_num) {
    case 0:
      fx1_enabled ^= 1;
      fx2_enabled ^= 1;
      fx3_enabled ^= 1;
      fx4_enabled ^= 1;
      break;
    case 1:
      fx1_enabled ^= 1;
      break;
    case 2:
      fx2_enabled ^= 1;
      break;
    case 3:
      fx3_enabled ^= 1;
      break;
    case 4:
      fx4_enabled ^= 1;
      break;
    default: /* do nothing */
      break;
    }
  }
};

#endif
