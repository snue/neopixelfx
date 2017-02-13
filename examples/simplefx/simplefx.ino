// NeoPixelFX 'simplefx' example
// =============================
// Some nice effects for NeoPixel strips.
// Initialization taken from Adafruit_NeoPixel library 'simple' example.
//
// Author: Stefan Nuernberger <kabelfrickler@gmail.com>
// License: LGPLv3 (same as the NeoPixel library)
//

// Include the Adafruit NeoPixel library.
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Include the effects library.
#include <NeoPixelFX.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter -- see the NeoPixel
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Delay between pixel updates (milliseconds)
int delayval = 150;

// Set up a nice set of effects.
NeoPixelFX<compose_xor, // Chose a composition function. You can try xor, or, and, cover.
  moving<NUMPIXELS/2, WRAP, confined<0,  2, ConstantColor< 40, 120, 40> > >, // Define one effect,
  moving<NUMPIXELS/2, TURN, confined<4,  8, ConstantColor< 40, 120, 40> > >, // and another effect,
  moving<NUMPIXELS,   TURN, confined<0,  1, ConstantColor<100, 100,  0> > >, // and another one,
  moving<NUMPIXELS/2, WRAP, confined<5, 10, ConstantColor<100,   0,  0> > >  // and one more.
  > fx(pixels); // The 'fx' is the actual name of the global effects set variable.

// Initialize the NeoPixel library.
void setup() {
   pixels.begin();
}

// Periodically called main function.
void loop() {
  // Show the current configuration on the strip.
  fx.show();

  // Update all effects to the next step.
  fx.update();

  // Wait before showing the update.
  delay(delayval);
}

