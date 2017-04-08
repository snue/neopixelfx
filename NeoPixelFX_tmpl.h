// NeoPixelFX library
// ==================
//
// Effects for NeoPixel strips based on the combination
// of C++ template based mutators and generators.
//
// Author: Stefan Nuernberger <kabelfrickler@gmail.com>
// License: LGPLv3 (see COPYING for details)
//
// This file was generated using: ./generate_tmpl.py 16

#ifndef NEOPIXELFX_TMPL_H
#define NEOPIXELFX_TMPL_H

// Base template for an effects container. Multiple effects can be layered.
// The compose function template handles multiple overlapping effects on the strip.
// Currently up to 16 effects are supported. If you require more, you can regenerate
// this file for more effects using the generate_tmpl.py script.
template<compose_fn = compose_xor,
  typename FX1 = void,
  typename FX2 = void,
  typename FX3 = void,
  typename FX4 = void,
  typename FX5 = void,
  typename FX6 = void,
  typename FX7 = void,
  typename FX8 = void,
  typename FX9 = void,
  typename FX10 = void,
  typename FX11 = void,
  typename FX12 = void,
  typename FX13 = void,
  typename FX14 = void,
  typename FX15 = void,
  typename FX16 = void>
class NeoPixelFX;

// What follows is the partial template specialization for each number of supplied effects.
// The code is very repetitive and is therefore easily generated.

// Partial template specialization for 1 effects
template<compose_fn COMP, typename FX1>
class NeoPixelFX<COMP, FX1, void, void, void, void, void, void, void, void, void, void, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);


      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
  }
};

// Partial template specialization for 2 effects
template<compose_fn COMP, typename FX1, typename FX2>
class NeoPixelFX<COMP, FX1, FX2, void, void, void, void, void, void, void, void, void, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
  }
};

// Partial template specialization for 3 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3>
class NeoPixelFX<COMP, FX1, FX2, FX3, void, void, void, void, void, void, void, void, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
  }
};

// Partial template specialization for 4 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, void, void, void, void, void, void, void, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
  }
};

// Partial template specialization for 5 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, void, void, void, void, void, void, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
  }
};

// Partial template specialization for 6 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, FX6, void, void, void, void, void, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
  }
};

// Partial template specialization for 7 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6, typename FX7>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, FX6, FX7, void, void, void, void, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;
  FX7 fx7;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel), fx7(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));
      if (channels & (0x01 << 6)) val = COMP(val, fx7.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
    if (channels & (0x01 << 6)) fx7.update();
  }
};

// Partial template specialization for 8 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6, typename FX7, typename FX8>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, FX6, FX7, FX8, void, void, void, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;
  FX7 fx7;
  FX8 fx8;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel), fx7(pixel), fx8(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));
      if (channels & (0x01 << 6)) val = COMP(val, fx7.getPixelColor(pos));
      if (channels & (0x01 << 7)) val = COMP(val, fx8.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
    if (channels & (0x01 << 6)) fx7.update();
    if (channels & (0x01 << 7)) fx8.update();
  }
};

// Partial template specialization for 9 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6, typename FX7, typename FX8, typename FX9>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, FX6, FX7, FX8, FX9, void, void, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;
  FX7 fx7;
  FX8 fx8;
  FX9 fx9;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel), fx7(pixel), fx8(pixel), fx9(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));
      if (channels & (0x01 << 6)) val = COMP(val, fx7.getPixelColor(pos));
      if (channels & (0x01 << 7)) val = COMP(val, fx8.getPixelColor(pos));
      if (channels & (0x01 << 8)) val = COMP(val, fx9.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
    if (channels & (0x01 << 6)) fx7.update();
    if (channels & (0x01 << 7)) fx8.update();
    if (channels & (0x01 << 8)) fx9.update();
  }
};

// Partial template specialization for 10 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6, typename FX7, typename FX8, typename FX9, typename FX10>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, FX6, FX7, FX8, FX9, FX10, void, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;
  FX7 fx7;
  FX8 fx8;
  FX9 fx9;
  FX10 fx10;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel), fx7(pixel), fx8(pixel), fx9(pixel), fx10(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));
      if (channels & (0x01 << 6)) val = COMP(val, fx7.getPixelColor(pos));
      if (channels & (0x01 << 7)) val = COMP(val, fx8.getPixelColor(pos));
      if (channels & (0x01 << 8)) val = COMP(val, fx9.getPixelColor(pos));
      if (channels & (0x01 << 9)) val = COMP(val, fx10.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
    if (channels & (0x01 << 6)) fx7.update();
    if (channels & (0x01 << 7)) fx8.update();
    if (channels & (0x01 << 8)) fx9.update();
    if (channels & (0x01 << 9)) fx10.update();
  }
};

// Partial template specialization for 11 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6, typename FX7, typename FX8, typename FX9, typename FX10, typename FX11>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, FX6, FX7, FX8, FX9, FX10, FX11, void, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;
  FX7 fx7;
  FX8 fx8;
  FX9 fx9;
  FX10 fx10;
  FX11 fx11;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel), fx7(pixel), fx8(pixel), fx9(pixel), fx10(pixel), fx11(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));
      if (channels & (0x01 << 6)) val = COMP(val, fx7.getPixelColor(pos));
      if (channels & (0x01 << 7)) val = COMP(val, fx8.getPixelColor(pos));
      if (channels & (0x01 << 8)) val = COMP(val, fx9.getPixelColor(pos));
      if (channels & (0x01 << 9)) val = COMP(val, fx10.getPixelColor(pos));
      if (channels & (0x01 << 10)) val = COMP(val, fx11.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
    if (channels & (0x01 << 6)) fx7.update();
    if (channels & (0x01 << 7)) fx8.update();
    if (channels & (0x01 << 8)) fx9.update();
    if (channels & (0x01 << 9)) fx10.update();
    if (channels & (0x01 << 10)) fx11.update();
  }
};

// Partial template specialization for 12 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6, typename FX7, typename FX8, typename FX9, typename FX10, typename FX11, typename FX12>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, FX6, FX7, FX8, FX9, FX10, FX11, FX12, void, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;
  FX7 fx7;
  FX8 fx8;
  FX9 fx9;
  FX10 fx10;
  FX11 fx11;
  FX12 fx12;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel), fx7(pixel), fx8(pixel), fx9(pixel), fx10(pixel), fx11(pixel), fx12(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));
      if (channels & (0x01 << 6)) val = COMP(val, fx7.getPixelColor(pos));
      if (channels & (0x01 << 7)) val = COMP(val, fx8.getPixelColor(pos));
      if (channels & (0x01 << 8)) val = COMP(val, fx9.getPixelColor(pos));
      if (channels & (0x01 << 9)) val = COMP(val, fx10.getPixelColor(pos));
      if (channels & (0x01 << 10)) val = COMP(val, fx11.getPixelColor(pos));
      if (channels & (0x01 << 11)) val = COMP(val, fx12.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
    if (channels & (0x01 << 6)) fx7.update();
    if (channels & (0x01 << 7)) fx8.update();
    if (channels & (0x01 << 8)) fx9.update();
    if (channels & (0x01 << 9)) fx10.update();
    if (channels & (0x01 << 10)) fx11.update();
    if (channels & (0x01 << 11)) fx12.update();
  }
};

// Partial template specialization for 13 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6, typename FX7, typename FX8, typename FX9, typename FX10, typename FX11, typename FX12, typename FX13>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, FX6, FX7, FX8, FX9, FX10, FX11, FX12, FX13, void, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;
  FX7 fx7;
  FX8 fx8;
  FX9 fx9;
  FX10 fx10;
  FX11 fx11;
  FX12 fx12;
  FX13 fx13;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel), fx7(pixel), fx8(pixel), fx9(pixel), fx10(pixel), fx11(pixel), fx12(pixel), fx13(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));
      if (channels & (0x01 << 6)) val = COMP(val, fx7.getPixelColor(pos));
      if (channels & (0x01 << 7)) val = COMP(val, fx8.getPixelColor(pos));
      if (channels & (0x01 << 8)) val = COMP(val, fx9.getPixelColor(pos));
      if (channels & (0x01 << 9)) val = COMP(val, fx10.getPixelColor(pos));
      if (channels & (0x01 << 10)) val = COMP(val, fx11.getPixelColor(pos));
      if (channels & (0x01 << 11)) val = COMP(val, fx12.getPixelColor(pos));
      if (channels & (0x01 << 12)) val = COMP(val, fx13.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
    if (channels & (0x01 << 6)) fx7.update();
    if (channels & (0x01 << 7)) fx8.update();
    if (channels & (0x01 << 8)) fx9.update();
    if (channels & (0x01 << 9)) fx10.update();
    if (channels & (0x01 << 10)) fx11.update();
    if (channels & (0x01 << 11)) fx12.update();
    if (channels & (0x01 << 12)) fx13.update();
  }
};

// Partial template specialization for 14 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6, typename FX7, typename FX8, typename FX9, typename FX10, typename FX11, typename FX12, typename FX13, typename FX14>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, FX6, FX7, FX8, FX9, FX10, FX11, FX12, FX13, FX14, void, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;
  FX7 fx7;
  FX8 fx8;
  FX9 fx9;
  FX10 fx10;
  FX11 fx11;
  FX12 fx12;
  FX13 fx13;
  FX14 fx14;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel), fx7(pixel), fx8(pixel), fx9(pixel), fx10(pixel), fx11(pixel), fx12(pixel), fx13(pixel), fx14(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));
      if (channels & (0x01 << 6)) val = COMP(val, fx7.getPixelColor(pos));
      if (channels & (0x01 << 7)) val = COMP(val, fx8.getPixelColor(pos));
      if (channels & (0x01 << 8)) val = COMP(val, fx9.getPixelColor(pos));
      if (channels & (0x01 << 9)) val = COMP(val, fx10.getPixelColor(pos));
      if (channels & (0x01 << 10)) val = COMP(val, fx11.getPixelColor(pos));
      if (channels & (0x01 << 11)) val = COMP(val, fx12.getPixelColor(pos));
      if (channels & (0x01 << 12)) val = COMP(val, fx13.getPixelColor(pos));
      if (channels & (0x01 << 13)) val = COMP(val, fx14.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
    if (channels & (0x01 << 6)) fx7.update();
    if (channels & (0x01 << 7)) fx8.update();
    if (channels & (0x01 << 8)) fx9.update();
    if (channels & (0x01 << 9)) fx10.update();
    if (channels & (0x01 << 10)) fx11.update();
    if (channels & (0x01 << 11)) fx12.update();
    if (channels & (0x01 << 12)) fx13.update();
    if (channels & (0x01 << 13)) fx14.update();
  }
};

// Partial template specialization for 15 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6, typename FX7, typename FX8, typename FX9, typename FX10, typename FX11, typename FX12, typename FX13, typename FX14, typename FX15>
class NeoPixelFX<COMP, FX1, FX2, FX3, FX4, FX5, FX6, FX7, FX8, FX9, FX10, FX11, FX12, FX13, FX14, FX15, void>{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;
  FX7 fx7;
  FX8 fx8;
  FX9 fx9;
  FX10 fx10;
  FX11 fx11;
  FX12 fx12;
  FX13 fx13;
  FX14 fx14;
  FX15 fx15;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel), fx7(pixel), fx8(pixel), fx9(pixel), fx10(pixel), fx11(pixel), fx12(pixel), fx13(pixel), fx14(pixel), fx15(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));
      if (channels & (0x01 << 6)) val = COMP(val, fx7.getPixelColor(pos));
      if (channels & (0x01 << 7)) val = COMP(val, fx8.getPixelColor(pos));
      if (channels & (0x01 << 8)) val = COMP(val, fx9.getPixelColor(pos));
      if (channels & (0x01 << 9)) val = COMP(val, fx10.getPixelColor(pos));
      if (channels & (0x01 << 10)) val = COMP(val, fx11.getPixelColor(pos));
      if (channels & (0x01 << 11)) val = COMP(val, fx12.getPixelColor(pos));
      if (channels & (0x01 << 12)) val = COMP(val, fx13.getPixelColor(pos));
      if (channels & (0x01 << 13)) val = COMP(val, fx14.getPixelColor(pos));
      if (channels & (0x01 << 14)) val = COMP(val, fx15.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
    if (channels & (0x01 << 6)) fx7.update();
    if (channels & (0x01 << 7)) fx8.update();
    if (channels & (0x01 << 8)) fx9.update();
    if (channels & (0x01 << 9)) fx10.update();
    if (channels & (0x01 << 10)) fx11.update();
    if (channels & (0x01 << 11)) fx12.update();
    if (channels & (0x01 << 12)) fx13.update();
    if (channels & (0x01 << 13)) fx14.update();
    if (channels & (0x01 << 14)) fx15.update();
  }
};

// Partial template specialization for 16 effects
template<compose_fn COMP, typename FX1, typename FX2, typename FX3, typename FX4, typename FX5, typename FX6, typename FX7, typename FX8, typename FX9, typename FX10, typename FX11, typename FX12, typename FX13, typename FX14, typename FX15, typename FX16>
class NeoPixelFX{
private:
  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.
  FX1 fx1;
  FX2 fx2;
  FX3 fx3;
  FX4 fx4;
  FX5 fx5;
  FX6 fx6;
  FX7 fx7;
  FX8 fx8;
  FX9 fx9;
  FX10 fx10;
  FX11 fx11;
  FX12 fx12;
  FX13 fx13;
  FX14 fx14;
  FX15 fx15;
  FX16 fx16;

public:
  NeoPixelFX(Adafruit_NeoPixel &pixel)
    : pixels(pixel), fx1(pixel), fx2(pixel), fx3(pixel), fx4(pixel), fx5(pixel), fx6(pixel), fx7(pixel), fx8(pixel), fx9(pixel), fx10(pixel), fx11(pixel), fx12(pixel), fx13(pixel), fx14(pixel), fx15(pixel), fx16(pixel)
  {}

  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);
      if (channels & (0x01 << 1)) val = COMP(val, fx2.getPixelColor(pos));
      if (channels & (0x01 << 2)) val = COMP(val, fx3.getPixelColor(pos));
      if (channels & (0x01 << 3)) val = COMP(val, fx4.getPixelColor(pos));
      if (channels & (0x01 << 4)) val = COMP(val, fx5.getPixelColor(pos));
      if (channels & (0x01 << 5)) val = COMP(val, fx6.getPixelColor(pos));
      if (channels & (0x01 << 6)) val = COMP(val, fx7.getPixelColor(pos));
      if (channels & (0x01 << 7)) val = COMP(val, fx8.getPixelColor(pos));
      if (channels & (0x01 << 8)) val = COMP(val, fx9.getPixelColor(pos));
      if (channels & (0x01 << 9)) val = COMP(val, fx10.getPixelColor(pos));
      if (channels & (0x01 << 10)) val = COMP(val, fx11.getPixelColor(pos));
      if (channels & (0x01 << 11)) val = COMP(val, fx12.getPixelColor(pos));
      if (channels & (0x01 << 12)) val = COMP(val, fx13.getPixelColor(pos));
      if (channels & (0x01 << 13)) val = COMP(val, fx14.getPixelColor(pos));
      if (channels & (0x01 << 14)) val = COMP(val, fx15.getPixelColor(pos));
      if (channels & (0x01 << 15)) val = COMP(val, fx16.getPixelColor(pos));

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }

  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
    if (channels & (0x01 << 0)) fx1.update();
    if (channels & (0x01 << 1)) fx2.update();
    if (channels & (0x01 << 2)) fx3.update();
    if (channels & (0x01 << 3)) fx4.update();
    if (channels & (0x01 << 4)) fx5.update();
    if (channels & (0x01 << 5)) fx6.update();
    if (channels & (0x01 << 6)) fx7.update();
    if (channels & (0x01 << 7)) fx8.update();
    if (channels & (0x01 << 8)) fx9.update();
    if (channels & (0x01 << 9)) fx10.update();
    if (channels & (0x01 << 10)) fx11.update();
    if (channels & (0x01 << 11)) fx12.update();
    if (channels & (0x01 << 12)) fx13.update();
    if (channels & (0x01 << 13)) fx14.update();
    if (channels & (0x01 << 14)) fx15.update();
    if (channels & (0x01 << 15)) fx16.update();
  }
};

#endif
