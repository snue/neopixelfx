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
int period = 100;

// Set up a nice set of effects. This is the magic of the framework.
NeoPixelFX<compose_avg, // Choose a composition function. You can try _xor, _or, _and, _cover, or _avg.
                        // Composition controls how the values from all following effects are combined.
           CurrentColor, // Show what is currently on the strip. This is a basic generator.
           offset<NUMPIXELS/2, CurrentColor>, // Show what is on the other side of the strip.
           moving<NUMPIXELS-1, WRAP, confined<1, RandomColor> > // Move a single random pixel around.
           > fx(pixels); // Initialize this global 'fx' set to act on the pixel strip.

// Do all the required initialization once.
void setup() {
  // Call initialization of the NeoPixels library.
  pixels.begin();

  // The FX framework does not require any extra setup.
  // ...
}

// Periodically called main function.
void loop() {
  // Show the current configuration on the strip.
  fx.show();

  // Update all effects to the next step.
  fx.update();

  // Wait before showing the update.
  delay(period);
}

