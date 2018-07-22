// NeoPixelFX 'channels' example
// =============================
// Some nice effects for NeoPixel strips.
// Initialization taken from Adafruit_NeoPixel library 'simple' example.
//
// This example shows how to use effect channels to control effects during runtime.
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
int period = 15;

// Set up a nice set of effects. This is the magic of the framework.
NeoPixelFX<compose_cover, // Choose a composition function. The 'cover' composition shows the first non-zero value.
           mirrored<CurrentColor>, // Show what is on the other side of the strip.
           confined<NUMPIXELS/2, offset<1, CurrentColor> >, // Show what is adjacent on half the strip.
           offset<NUMPIXELS/2, confined<1, RandomColor> >, // Show a random pixel at half-point.

           mirrored<CurrentColor>, // Show what is on the other side of the strip.
           confined<NUMPIXELS/2, offset<1, CurrentColor> >, // Show what is adjacent on half the strip.
           offset<NUMPIXELS/2, confined<1, moving<0x1 << 9, TURN, Rainbow<0x1 << 9> > > >, // Show a rainbow pixel at half-point.

           blinking<2, fixed<0, moving<0x1 << 8, TURN, Rainbow<0x1 << 8> > > >, // Strobe of unicolor (rainbow over time).

           blinking<2, RandomColor>, // Strobe of unicolor (random over time).

           constant_decaying<2, CurrentColor>, // Fade out (decay each channel by 'value') what is currently on the strip.
           mirrored<CurrentColor>, // Show what is on the other side of the strip.
           confined<NUMPIXELS/2, offset<1, CurrentColor> >, // Show what is adjacent on half the strip.
           moving<NUMPIXELS-1, TURN, confined<1, RandomColor> >, // Move a single random pixel around.

           fixed<0, moving<0x1 << 8, WRAP, Rainbow<0x1 << 8> > > // Show a single rainbow pixel everywhere
           > fx(pixels);

// Provide convenience handles for channels.
enum channels {
  CHANNEL_0 = 0x1 << 0,
  CHANNEL_1 = 0x1 << 1,
  CHANNEL_2 = 0x1 << 2,
  CHANNEL_3 = 0x1 << 3,
  CHANNEL_4 = 0x1 << 4,
  CHANNEL_5 = 0x1 << 5,
  CHANNEL_6 = 0x1 << 6,
  CHANNEL_7 = 0x1 << 7,
  CHANNEL_8 = 0x1 << 8,
  CHANNEL_9 = 0x1 << 9,
  CHANNEL_10 = 0x1 << 10,
  CHANNEL_11 = 0x1 << 11,
  CHANNEL_12 = 0x1 << 12,
};
typedef uint16_t channel_t;

// Define which channels belong to a program.
channel_t programs[] = {
  CHANNEL_0 | CHANNEL_1 | CHANNEL_2,
  CHANNEL_3 | CHANNEL_4 | CHANNEL_5,
  CHANNEL_6,
  CHANNEL_7,
  CHANNEL_8 | CHANNEL_9 | CHANNEL_10 | CHANNEL_11,
  CHANNEL_12
};

// Do all the required initialization once.
void setup() {
  // Call initialization of the NeoPixels library.
  pixels.begin();

  // The FX framework does not require any extra setup.
  // ...
}

int playtime = 0;
int current = 0;

// Periodically called main function.
void loop() {
  playtime = (playtime + 1) & 0x3ff;
  if (not playtime) {
    current = (current + 1) % (sizeof(programs) / sizeof(channel_t));
  }

  fx.show(programs[current]);
  fx.update(programs[current]);

  // Wait before showing the update.
  delay(period);
}

