// Copyright 2022 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "nova75ble.h"

#ifdef BIU_BLE5_ENABLE
#    include "biu_ble_common.h"
#endif

#if defined(RGBLIGHT_ENABLE) && defined(BIU_BLE5_ENABLE)

const rgblight_segment_t PROGMEM bt_conn[] = RGBLIGHT_LAYER_SEGMENTS( {0, 4, HSV_GREEN} );         // 0
const rgblight_segment_t PROGMEM bt_pair[] = RGBLIGHT_LAYER_SEGMENTS( {0, 4, HSV_BLUE} );          // 1
const rgblight_segment_t PROGMEM usb_conn[] = RGBLIGHT_LAYER_SEGMENTS( {0, 4, HSV_GREEN} );        // 2
const rgblight_segment_t PROGMEM usb_pair[] = RGBLIGHT_LAYER_SEGMENTS( {0, 4, HSV_RED} );          // 3
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_WHITE}); // 4

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(bt_conn, bt_pair,
                                                                             usb_conn, usb_pair,
                                                                             my_capslock_layer);

void rgb_adv_unblink_all_layer(void) {
    for (uint8_t i = 0; i < 5; i++) {
        rgblight_unblink_layer(i);
    }
}

bool ble_led_update_kb(uint8_t channle, uint8_t state) {
    /*
    _ble_channle:
        BLE: 0-7
        USB: 0xa
        2G4: 0xb
    _ble_state:
        NRF_WORKING：1
        NRF_ADVING_NO_WL：8
        NRF_ADVING_WITH_WL：7

        USB_ACTIVE: 0xA0
        USB_DISCONNECTION：0xA1
    */
    rgb_adv_unblink_all_layer();
    if (channle <= 7) {
        if (state == 7) {
            rgblight_blink_layer_repeat(0, 500, 30);
        } else if (state == 8) {
            rgblight_blink_layer_repeat(1, 500, 30);
        } else if (state == 1) {
            rgblight_blink_layer_repeat(0, 3000, 1);
        }
    } else if (channle == 0xa) {
        rgblight_blink_layer_repeat(3, 500, 6);
        // if (state != 0xa0) {
        //     rgblight_blink_layer_repeat(3, 500, 10);
        // } else {
        //     rgblight_blink_layer_repeat(2, 3000, 1);
        // }
    }
    return true;
}

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        rgblight_set_layer_state(4, led_state.caps_lock);
    }
    return true;
}

void keyboard_post_init_kb(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
#endif
    rgblight_reload_from_eeprom();
    rgblight_layers = _rgb_layers;
    keyboard_post_init_user();
}

#endif


#ifndef BIU_BLE5_ENABLE
void keyboard_pre_init_kb(void) {
    palSetLineMode(RGB_BLE_SW, PAL_MODE_OUTPUT_PUSHPULL);
    writePin(RGB_BLE_SW, RGB_EN_STATE);
}
#endif
