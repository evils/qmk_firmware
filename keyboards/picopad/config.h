// Copyright 2022 Evils (@Evils)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT


#include "config_common.h"

#define PRODUCT PicoPad Raspberry Pi RP2040
//#define MATRIX_ROW_PINS { GP0 }
//#define MATRIX_ROW_PINS { GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9 }
#define DEBUG_MATRIX_SCAN_RATE

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define RGB_DI_PIN A1

#define TRANSIENT_EEPROM_SIZE 1024
