#pragma once

#define QMK_KEYS_PER_SCAN 4

// Makes tap and hold keys trigger the hold if another key is pressed
// before releasing, even if it hasn't hit the TAPPING_TERM.
#define PERMISSIVE_HOLD
