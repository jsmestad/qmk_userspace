#pragma once

// PERMISSIVE_HOLD is the modern default for what IGNORE_MOD_TAP_INTERRUPT
// used to disable. This makes mod-taps trigger the hold if another key
// is pressed before releasing, even before TAPPING_TERM.
#define PERMISSIVE_HOLD

// Flow Tap: disable hold behavior during fast typing.
// Prevents accidental Ctrl from ESCC (Ctrl/Esc) during normal typing.
#define FLOW_TAP_TERM 150

#undef DEBOUNCE
#define DEBOUNCE 5

// RGB LED strip
#define WS2812_DI_PIN F5
#define RGBLIGHT_LED_COUNT 22
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_SLEEP
