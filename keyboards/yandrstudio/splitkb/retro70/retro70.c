// Copyright 2023 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "retro70.h"

#ifdef SPLIT_KEYBOARD

bool is_keyboard_left(void) {
#ifdef I_AM_LEFT
    return true;
#else
    return false;
#endif
}

#endif