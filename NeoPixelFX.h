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

// Choose any modifiers:
// ---------------------
// confined
// mirrored
// moving
// blinking
// pulsating (brightness)
// rotating (color channels)
// expanding
// shrinking / contracting
// dripping
// bouncing

// Choose one generator:
// ---------------------
// RandomColor
// ConstantColor
// SineWave
// Pattern

// Choose one composer function:
// -----------------------------
// compose_xor
// compose_or
// compose_and
// compose_cover


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
