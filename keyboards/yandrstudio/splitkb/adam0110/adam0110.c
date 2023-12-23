// Copyright 2023 FxStudio <FXS@fx-studio.cn>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "adam0110.h"
#include "SEGGER_RTT.h"

bool is_keyboard_left(void) {
#ifdef I_AM_LEFT
    return true;
#else
    return false;
#endif
}

#ifdef RGB_MATRIX_ENABLE

#define xx NO_LED

led_config_t g_led_config = {
	{
	   //Left Hand
	   // 0   1   2   3   4   5   6   7   8   9   10  11  12  13
		{ 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63 },
		{ 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36 },
		{ 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, xx, 35 },
		{ 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9  },
		{ 0 , 1 , 2,  xx, xx, 3 , xx, xx, xx, 4 , 5 , 6 , 7 , 8  },
	   //Right Hand
		{ 80, 79, 66, 65, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx },
		{ 77, 78, 67, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx },
		{ 76, 75, 68, 64, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx },
		{ 73, 74, 69, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx },
		{ 72, xx, 71, 70, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx },
	},{
	// "Fine-tuned" complex configuration
	//Left Hand
	//      0         1          2         3          4        5        6           7        8          9       10         11        12        13
		{ 20, 10}, {30, 10},  {40, 10}, {50, 10}, {60, 10}, {70, 10}, {80, 10}, {90, 10}, {100, 10}, {110, 10}, {120, 10}, {130, 10}, {140, 10}, {150, 10},
		{ 20, 20}, {30, 20},  {40, 20}, {50, 20}, {60, 20}, {70, 20}, {80, 20}, {90, 20}, {100, 20}, {110, 20}, {120, 20}, {130, 20}, {140, 20}, {150, 20},
		{ 20, 30}, {30, 30},  {40, 30}, {50, 30}, {60, 30}, {70, 30}, {80, 30}, {90, 30}, {100, 30}, {110, 30}, {120, 30}, {130, 30},            {150, 30},
		{ 20, 40}, {30, 40},  {40, 40}, {50, 40}, {60, 40}, {70, 40}, {80, 40}, {90, 40}, {100, 40}, {110, 40}, {120, 40}, {130, 40}, {140, 40}, {150, 40},
		{ 20, 50}, {30, 50},  {40, 50},                     {70, 50},                                {110, 50}, {120, 50}, {130, 50}, {140, 50}, {150, 50},

		//Right Hand
		{160, 10}, {170, 10},  {180, 10}, {190, 10},
		{160, 20}, {170, 20},  {180, 20},
		{160, 30}, {170, 30},  {180, 30}, {190, 30},
		{160, 40}, {170, 40},  {180, 40},
		{160, 50},             {180, 50}, {190, 50}
	},
    {
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	4, 4, 4,       4,          4, 4, 4, 4, 4,

    4, 4, 4, 4,
    4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4,
    4,    4, 4
    }
};

#endif

void keyboard_post_init_kb(void) {
    SEGGER_RTT_Init();
    SEGGER_RTT_printf(0,"Demo Init!\r\n");
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_reload_from_eeprom();
#endif
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
#endif
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) { return false; }
    if (record->event.pressed) {
        SEGGER_RTT_printf(0,"Demo Init!\r\n");
    }
    return true;
}

uint32_t tt = 0;
void housekeeping_task_kb(void) {
    if (tt == 0) {
        tt = timer_read32();
    }
    uint32_t timer_now = timer_read32();
    if (TIMER_DIFF_32(timer_now, tt) >= 500) {
        SEGGER_RTT_printf(0,"Demo Running!\r\n");
        tt = timer_read32();
    }
};
