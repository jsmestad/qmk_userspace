#pragma once

// PERMISSIVE_HOLD is the modern default for what IGNORE_MOD_TAP_INTERRUPT
// used to disable. This makes mod-taps trigger the hold if another key
// is pressed before releasing, even before TAPPING_TERM.
#define PERMISSIVE_HOLD

#undef DEBOUNCE
#define DEBOUNCE 1

// RGB LED strip
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_SLEEP
