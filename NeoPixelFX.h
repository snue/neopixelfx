// NeoPixelFX library
// ==================
//
// Effects for NeoPixel strips based on the combination
// of C++ template based mutators and generators.
//
// Author: Stefan Nuernberger <kabelfrickler@gmail.com>
// License: LGPLv3 (see COPYING for details)

#ifndef NEOPIXELFX_H
#define NEOPIXELFX_H

// FIXME: Not all modifiers/generators listed below are implemented.

// Choose any modifiers:
// ---------------------
// confined
// offset
// mirrored
// moving
// blinking
// pulsing (intensity)
// decaying

// Choose one generator:
// ---------------------
// CurrentColor
// RandomColor
// ConstantColor
// ConstantRGBColor
// SineWave
// Rainbow
// Pattern

// Choose one composer function:
// -----------------------------
// compose_xor
// compose_or
// compose_and
// compose_cover
// compose_avg

// Define composer functions.

const uint32_t compose_xor(const uint32_t first, const uint32_t second) {
  return first ^ second;
}

const uint32_t compose_or(const uint32_t first, const uint32_t second) {
  return first | second;
}

const uint32_t compose_and(const uint32_t first, const uint32_t second) {
  return first ? (second ? first & second : first) : second;
}

const uint32_t compose_cover(const uint32_t first, const uint32_t second) {
  return second ? second : first;
}

const uint32_t compose_avg(const uint32_t first, const uint32_t second) {
  // FIXME: I am pretty sure there is a nicer bit-twiddling hack for this.
  // Compute average of channels 1 and 3
  uint32_t avg13 = (((first & 0x00ff00ff) + (second & 0x00ff00ff)) >> 1) & 0x00ff00ff;
  // Compute average of channels 2 and 4
  uint32_t avg24 = (((first >> 8) & 0x00ff00ff) + ((second >> 8) & 0x00ff00ff) >> 1) & 0x00ff00ff;
  // Return all channels average
  return avg13 | (avg24 << 8);
}

// Provide a convenience function pointer name for composer functions.
typedef const uint32_t (*compose_fn)(const uint32_t, const uint32_t);

// Declare some convenience mutator options.
enum wrap_style_t {
  WRAP = true,
  TURN = false
};

// Include effect templates.

#include "NeoPixelFX_tmpl.h"
#include "NeoPixelFX_mutators.h"
#include "NeoPixelFX_generators.h"

#endif
