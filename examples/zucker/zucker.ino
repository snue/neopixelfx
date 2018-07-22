// NeoPixelFX 'zucker' example
// =============================
//
// Created @FusionFestival 2018 for a cotton candy stand
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
#define NUMPIXELS      99

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter -- see the NeoPixel
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Delay between pixel updates (milliseconds)
int period = 15;

// Set up a nice set of effects. This is the magic of the framework.
NeoPixelFX<compose_cover, // Choose a composition function. The 'cover' composition shows the first non-zero value.
           mirrored<CurrentColor>, // Show what is on the other side of the strip.
           confined<NUMPIXELS/2+1, offset<1, CurrentColor> >, // Show what is adjacent on half the strip.
           offset<NUMPIXELS/2, confined<1, RandomColor> > // Show a random pixel at half-point.
           > fx1(pixels);

NeoPixelFX<compose_cover,
           mirrored<CurrentColor>, // Show what is on the other side of the strip.
           confined<NUMPIXELS/2+1, offset<1, CurrentColor> >, // Show what is adjacent on half the strip.
           offset<NUMPIXELS/2, confined<1, moving<0x1 << 9, TURN, Rainbow<0x1 << 9> > > > // Show a rainbow pixel at half-point.
           > fx2(pixels);

NeoPixelFX<compose_cover, // Choose a composition function. The 'cover' composition shows the first non-zero value.
           blinking<2, fixed<0, moving<0x1 << 8, TURN, Rainbow<0x1 << 8> > > >
           > fx3(pixels);

NeoPixelFX<compose_cover, // Choose a composition function. The 'cover' composition shows the first non-zero value.
           blinking<2, RandomColor>
           > fx4(pixels);

NeoPixelFX<compose_cover, // Choose a composition function. The 'cover' composition shows the first non-zero value.
           constant_decaying<2, CurrentColor>, // Fade out (decay each channel by 'value') what is currently on the strip.
           mirrored<CurrentColor>, // Show what is on the other side of the strip.
           confined<NUMPIXELS/2+1, offset<1, CurrentColor> >, // Show what is adjacent on half the strip.
           moving<NUMPIXELS-1, TURN, confined<1, RandomColor> > // Move a single random pixel around.
           > fx5(pixels);

NeoPixelFX<compose_cover,
           fixed<0, moving<0x1 << 8, WRAP, Rainbow<0x1 << 8> > > // Show a single rainbow pixel everywhere
           > fx6(pixels);


// Do all the required initialization once.
void setup() {
  // Call initialization of the NeoPixels library.
  pixels.begin();

  // The FX framework does not require any extra setup.
  // ...
}

int playtime = 0;
int program = 1;

const int PRG_CNT = 6;

// Periodically called main function.
void loop() {
  playtime = (playtime + 1) & 0x3ff;
  if (not playtime) {
    program = (program + 1) % PRG_CNT;
  }

  switch (program) {
  default:
  case 0:
    fx1.show();
    fx1.update();
    break;
  case 1:
    fx2.show();
    fx2.update();
    break;
  case 2:
    fx3.show();
    fx3.update();
    break;
  case 3:
    fx4.show();
    fx4.update();
    break;
  case 4:
    fx5.show();
    fx5.update();
    break;
  case 5:
    fx6.show();
    fx6.update();
    break;
  }

  // Wait before showing the update.
  delay(period);
}
