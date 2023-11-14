// Copyright 2023 Y&R-studio (@superYoungMonk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
/*
    K000, K001,  K002,  K003,  K004,  K005,  K006, K007, K008, K009, K010, K011, \
    K100, K101,  K102,  K103,  K104,  K105,  K106, K107, K108, K109,       K111, \
    K200, K201,  K202,  K203,  K204,  K205,  K206, K207, K208, K209, K110,       \
    K300, K301,  K302,         K304,  K305,        K307,       K309, K310        \
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        // 0     1                                          6        7        8        9        10       11
        KC_ESC,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,             KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_UP,   KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,         KC_SPC, LT(1, KC_SPC),    KC_LEFT,          KC_DOWN, KC_RGHT),
    LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_TAB,  KC_BSLS, KC_QUOT, KC_SCLN,KC_COMM,KC_DOT,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS),
    LAYOUT(
        KC_F12,  KC_F1,  KC_F2,   KC_F3,  KC_F4,  KC_F5,   KC_F6,    KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11,
        KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS,  KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,KC_TRNS,         KC_TRNS,KC_TRNS,           KC_TRNS,          KC_TRNS, KC_TRNS),
    LAYOUT(
        KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,KC_TRNS,         KC_TRNS,KC_TRNS,           KC_TRNS,         KC_TRNS, KC_TRNS),
};
