// Copyright 2022 Evils (@Evils)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

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
#define DEBUG_MATRIX_SCAN_RATE

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define TRANSIENT_EEPROM_SIZE 1024

#ifdef RGB_MATRIX_ENABLE

  #define RGB_DI_PIN GP28 // surrounding strip, then the matrix
  #define DRIVER_LED_TOTAL 21
  #define RGBLED_NUM 21
  #define RGB_MATRIX_KEYPRESSES
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 127   // limit brightness to not overamp the USB
  #define RGB_MATRIX_LED_FLUSH_LIMIT 8        // 16 is equivalent to limiting to 60fps
  #define RGB_DISABLE_AFTER_TIMEOUT 0         // number of ticks to wait until disabling effects
  #define RGB_DISABLE_WHEN_USB_SUSPENDED      // turn off effects when suspended
  //#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_ALL
  //#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_RGB_TEST
  #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_BREATHING

  #define ENABLE_RGB_MATRIX_ALPHAS_MODS
  #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_BREATHING
  #define ENABLE_RGB_MATRIX_BAND_VAL
  #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #define ENABLE_RGB_MATRIX_CYCLE_ALL
  #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
  #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
  #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
  #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #define ENABLE_RGB_MATRIX_RAINDROPS
  // enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
  #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
  // enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  #define ENABLE_RGB_MATRIX_MULTISPLASH
  #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

  #define NOP_FUDGE 0.1 // must be non-zero or the pico doesn't boot right

#endif
