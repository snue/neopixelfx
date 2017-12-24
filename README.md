# NeoPixelFX

A C++ template based framework/library to create effects on Adafruit NeoPixel LED strips. The framework uses the [Adafruit NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel) as the lower level interface to control the LEDs.

This code is released under the LGPLv3, just as the original [Adafruit NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel). See file COPYING for detailed licensing information.

## Usage

The basic principle for effect creation is the combination of generators and modifiers (mutators). A generator defines a basic color (e.g. a fixed color or a random color). Mutators can be used to move, confine, offset, or decay pixels. This allows the creator to define effects in terms of behavior, e.g. "Move a red pixel around".

## Examples

 * [simplefx](examples/simplefx/simplefx.ino) - Shows basic framework usage to create some effects
 * [channels](examples/channels/channels.ino) - Shows how to control effect channels to enable/disable effects at runtime

## TODO

The framework is still missing a lot of primitive mutators and generators. The currently implemented ones are mostly an easy proof-of-concept.

