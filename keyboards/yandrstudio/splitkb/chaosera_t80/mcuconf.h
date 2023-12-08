// Copyright 2023 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#ifdef I_AM_LEFT

#undef STM32_PWM_USE_TIM1
#define STM32_PWM_USE_TIM1 TRUE

#else

#undef STM32_PWM_USE_TIM2
#define STM32_PWM_USE_TIM2 TRUE

#endif

#undef STM32_SERIAL_USE_USART1
#define STM32_SERIAL_USE_USART1 TRUE

#undef STM32_PLLXTPRE
#define STM32_PLLXTPRE STM32_PLLXTPRE_DIV2
