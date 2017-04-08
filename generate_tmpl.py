#!/usr/bin/env python2

# Generate the partially specialized NeoPixelFX template code for an arbitrary
# maximum number of effects.
#
# Call as ./generate_tmpl.py [max_effects]
#
# If called without a parameter, a default value of 4 is assumed.

import sys

tmpl_filename = 'NeoPixelFX_tmpl.h'

max_fx = 4
if len(sys.argv) == 2:
  max_fx = int(sys.argv[1])

header = '''// NeoPixelFX library
// ==================
//
// Effects for NeoPixel strips based on the combination
// of C++ template based mutators and generators.
//
// Author: Stefan Nuernberger <kabelfrickler@gmail.com>
// License: LGPLv3 (see COPYING for details)
//
// This file was generated using: {}

#ifndef NEOPIXELFX_TMPL_H
#define NEOPIXELFX_TMPL_H

// Base template for an effects container. Multiple effects can be layered.
// The compose function template handles multiple overlapping effects on the strip.
// Currently up to {} effects are supported. If you require more, you can regenerate
// this file for more effects using the generate_tmpl.py script.
template<compose_fn = compose_xor,
'''

typenames = '  typename FX{} = void'

sys.stdout.write('Generating {} for {} effects... '.format(tmpl_filename, max_fx))
sys.stdout.flush()

tmpl = open(tmpl_filename, 'w')

# write intro
tmpl.write(header.format(' '.join(sys.argv), max_fx))
tmpl.write(',\n'.join(typenames.format(i+1) for i in range(max_fx)))
tmpl.write('>\nclass NeoPixelFX;\n')

comment = '''
// What follows is the partial template specialization for each number of supplied effects.
// The code is very repetitive and is therefore easily generated.
'''
tmpl.write(comment)

# write partial template specializations
for fx in range(1, max_fx+1):
    # template class declaration
    tmpl.write('\n// Partial template specialization for {} effects\ntemplate<compose_fn COMP, '.format(fx))
    tmpl.write(', '.join('typename FX{}'.format(i+1) for i in range(fx)))
    tmpl.write('>\nclass NeoPixelFX')
    if (fx < max_fx):
        tmpl.write('<COMP, ')
        tmpl.write(', '.join('FX{}'.format(i+1) for i in range(fx)))
        for i in range(max_fx - fx):
            tmpl.write(', void')
        tmpl.write('>')
    tmpl.write('{\nprivate:\n  Adafruit_NeoPixel &pixels; // The pixel strip to show effects.\n')
    # members
    tmpl.write('\n'.join('  FX{} fx{};'.format(i+1, i+1) for i in range(fx)))
    tmpl.write('\n')
    # constructor
    tmpl.write('\npublic:\n  NeoPixelFX(Adafruit_NeoPixel &pixel)\n    : pixels(pixel), ')
    tmpl.write(', '.join('fx{}(pixel)'.format(i+1) for i in range(fx)))
    tmpl.write('\n  {}\n')
    # show method
    show_method_intro = \
'''
  // Show the current effects on the strip.
  void show(uint16_t channels = 0xffff) const {
    // Draw all pixels.
    uint16_t numPixels = pixels.numPixels();
    for (uint16_t pos = 0; pos < numPixels; pos++) {
      uint32_t val = 0;
'''
    tmpl.write(show_method_intro)
    tmpl.write('      if (channels & (0x01 << 0)) val = fx1.getPixelColor(pos);\n')
    tmpl.write('\n'.join('      if (channels & (0x01 << {})) val = COMP(val, fx{}.getPixelColor(pos));'.format(i % 16, i+1) for i in range(1, fx)))

    show_method_outro = \
'''

      pixels.setPixelColor(pos, val);
    }

    pixels.show();
  }
'''
    tmpl.write(show_method_outro)

    # update method
    update_method_intro = \
'''
  // Update all effects in the list.
  void update(uint16_t channels = 0xffff) {
'''
    tmpl.write(update_method_intro)
    tmpl.write('\n'.join('    if (channels & (0x01 << {})) fx{}.update();'.format(i % 16, i+1) for i in range(fx)))
    tmpl.write('\n  }')

    # specialized template class end
    tmpl.write('\n};\n')

# write outro
tmpl.write('\n#endif\n')

sys.stdout.write(' done!\n')

