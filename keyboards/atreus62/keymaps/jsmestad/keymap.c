// Copyright 2018-2026 Justin Smestad (@jsmestad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAMING 3
#define _ADJUST 4

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    RAISE,
    LOWER,
    ADJUST,
    GAMING,
};

#define ESCC MT(MOD_LCTL, KC_ESC) // Control (hold), Escape (tap)
#define SPCC MT(MOD_LGUI, KC_SPC) // Win/Cmd (hold), Space (tap)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ESCC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        SC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, KC_LGUI, KC_LALT, _______, LOWER,   KC_BSPC, KC_DEL,    KC_ENT,  KC_SPC,  RAISE,   QK_LEAD, KC_LBRC, KC_RBRC, _______
    //,--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------.
    ),

    [_LOWER] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, KC_UP,   _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LBRC, KC_RBRC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, GAMING
    //,--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------.
    ),

    [_RAISE] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
        KC_GRV,  _______, _______, _______, _______, _______,                      KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_PLUS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      _______, _______, KC_LABK, KC_RABK, KC_QUES, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        ADJUST,  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______
    //,--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------.
    ),

    [_GAMING] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_ESC,  KC_LGUI, KC_LALT, _______, LOWER,   KC_SPC,  KC_BSPC,   KC_ENT,  KC_SPC,  RAISE,   QK_LEAD, KC_LBRC, KC_RBRC, TO(0)
    //,--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------.
    ),

    [_ADJUST] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, _______,                     _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, RM_HUED, RM_SATD, RM_VALD, _______,                     _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, QK_BOOT
    //,--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------.
    )
};

void matrix_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(HSV_RED);
}

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RAISE:
            rgblight_sethsv_noeeprom(HSV_AZURE);
            break;
        case _LOWER:
            rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
            break;
        case _ADJUST:
            rgblight_sethsv_noeeprom(HSV_WHITE);
            break;
        case _GAMING:
            rgblight_sethsv_noeeprom(HSV_PURPLE);
            break;
        default:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << _QWERTY);
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}

// Leader Key sequences
void leader_start_user(void) {
    rgblight_sethsv_noeeprom(HSV_GOLD);
}

void leader_end_user(void) {
    bool succeeded = false;

    if (leader_sequence_two_keys(KC_I, KC_E)) {
        // macOS Emoji Selector
        SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_SPACE))));
        succeeded = true;
    } else if (leader_sequence_two_keys(KC_F, KC_F)) {
        // macOS Spotlight
        SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
        succeeded = true;
    } else if (leader_sequence_two_keys(KC_F, KC_D)) {
        // fd triggers Escape (matching Emacs)
        SEND_STRING(SS_TAP(X_ESCAPE));
        succeeded = true;
    }

    if (succeeded) {
        rgblight_sethsv_noeeprom(HSV_GREEN);
        wait_ms(300);
    } else {
        rgblight_sethsv_noeeprom(HSV_WHITE);
        for (int i = 0; i < 4; i++) {
            rgblight_toggle_noeeprom();
            wait_ms(100);
            rgblight_toggle_noeeprom();
            wait_ms(100);
        }
    }
    rgblight_sethsv_noeeprom(HSV_RED);
}
