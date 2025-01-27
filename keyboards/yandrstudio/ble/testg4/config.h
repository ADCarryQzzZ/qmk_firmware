// Copyright 2023 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID 0xAA96
#define PRODUCT_ID 0xAA7B
#define DEVICE_VER 0x0001
#define MANUFACTURER "OMMK_Y&R"
#define PRODUCT "TG4"

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 2

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define MATRIX_COL_PINS { B4, B5 }
#define MATRIX_ROW_PINS { B3 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define TAP_CODE_DELAY 15

/* W25QXX */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN A4
#define EXTERNAL_FLASH_PAGE_SIZE 256
#define EXTERNAL_FLASH_SECTOR_SIZE (4 * 1024)
#define EXTERNAL_FLASH_BLOCK_SIZE (64 * 1024)
#define EXTERNAL_FLASH_ADDRESS_SIZE 3
/* w25q32*/
#define EXTERNAL_FLASH_SIZE (8 * 1024 * 1024)
#define EXTERNAL_FLASH_SPI_CLOCK_DIVISOR 8

#define EXTERNAL_FLASH_SPI_TIMEOUT 50

// Wear-leveling driver configuration
// #define WEAR_LEVELING_LOGICAL_SIZE 1024
// #define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)

/* ST7735 TFT*/
// reset
#define ST7735_RES_PIN A3
// display/command rs pin
#define ST7735_DC_PIN A2
// chip select
#define ST7735_CS_PIN A1
// LED Anode
#define ST7735_BLK_PIN A0
// Byte Order
// #define TFT_COLOR_BYTE_ORDER TFT_COLOR_BYTE_ORDER_BGR
#define TFT_COLOR_BYTE_ORDER TFT_COLOR_BYTE_ORDER_RGB

#define ST7735S_NO_AUTOMATIC_VIEWPORT_OFFSETS
#define ST7735_NO_AUTOMATIC_VIEWPORT_OFFSETS

/* SPI For Flash and TFT*/
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN A5
#define SPI_SCK_PAL_MODE 5
#define SPI_MOSI_PIN A7
#define SPI_MOSI_PAL_MODE 5
#define SPI_MISO_PIN A6
#define SPI_MISO_PAL_MODE 5


#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0

#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
#define QUANTUM_PAINTER_CONCURRENT_ANIMATIONS 1
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE 512
// #define QUANTUM_PAINTER_DEBUG
// #define DEBUG_FLASH_SPI_OUTPUT

#define QP_STREAM_HAS_SPI_FLASH_IO
#define QP_USE_MULTI_THREAD


#define QP_THD_SIZE 640
#define KB_THD_SIZE 4096
#define BLE_THD_SIZE 2048
