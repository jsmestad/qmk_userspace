# QMK Userspace - jsmestad

My QMK keymaps, stored externally from the main [qmk_firmware](https://github.com/qmk/qmk_firmware) repository using [External Userspace](https://docs.qmk.fm/newbs_external_userspace).

## Keyboards

| Keyboard | Build Target | Notes |
|---|---|---|
| Atreus62 | `atreus62:jsmestad` | Elite C controller, RGB underglow, Leader Key sequences |
| Ergodox EZ | `ergodox_ez:jsmestad` | Layer indicator LEDs, Space Cadet Shift |
| Keebio Iris | `keebio/iris/rev2:jsmestad` | Split, RGB underglow. **Change `rev2` to match your revision.** |
| Kinesis Advantage | `kinesis/alvicstep:jsmestad` | RGB strip, Space Cadet Shift. **Change `alvicstep` to match your controller (kint2pp, kint36, etc).** |

## Building locally

```sh
# One-time setup
brew install qmk/qmk/qmk
qmk setup
qmk config user.overlay_dir="$(realpath ~/code/github/qmk_userspace)"

# Compile a single keyboard
qmk compile -kb atreus62 -km jsmestad

# Compile all build targets
qmk userspace-compile
```

## Building with GitHub Actions

Push to the repo and GitHub Actions will compile all build targets automatically. Download firmware from the Releases tab.

## Migration Notes (from fork)

This repo replaces the old `jsmestad/qmk_firmware` fork. Key changes made during migration from the August 2022 codebase:

**All keymaps:**
- Removed obsolete includes (`action_layer.h`, `eeconfig.h`, `iris.h`, `atreus62.h`, `version.h`)
- `RESET` replaced with `QK_BOOT`, `DEBUG` replaced with `DB_TOGG`
- `LAYOUT_kc` / `LAYOUT_ergodox_pretty_kc` replaced with `LAYOUT` / `LAYOUT_ergodox_pretty` (explicit `KC_` prefixes)
- `RGB_TOG`/`RGB_MOD`/etc. replaced with `RM_TOGG`/`RM_NEXT`/etc.
- `KC_LSPO`/`KC_RSPC` replaced with `SC_LSPO`/`SC_RSPC`
- `uint32_t layer_state_set_user` replaced with `layer_state_t`
- `biton32()` replaced with `get_highest_layer()`

**Atreus62:**
- Leader Key API migrated from `LEADER_DICTIONARY()` / `matrix_scan_user` to the new `leader_sequence_two_keys()` / `leader_start_user()` / `leader_end_user()` callbacks

**Iris:**
- Keyboard path moved from `keyboards/iris/` to `keyboards/keebio/iris/`
- Removed `#include "config_common.h"` and `#ifndef CONFIG_USER_H` guards
- `RGBLIGHT_ANIMATIONS` replaced with individual `RGBLIGHT_EFFECT_*` defines

**Kinesis:**
- `LAYOUT_pretty` renamed to `LAYOUT`
- `KC_SLCK` renamed to `KC_SCRL`
- Removed `IGNORE_MOD_TAP_INTERRUPT` (this is now the default mod-tap behavior)
- `RGBLIGHT_ANIMATIONS` replaced with individual effect define
- `matrix_init_user` replaced with `keyboard_post_init_user`
- Removed obsolete `BLUETOOTH_ENABLE` and `SLEEP_LED_ENABLE` options
