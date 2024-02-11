// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPLIT_TRANSACTION_IDS_USER CAPS_WORD_SYNC
#define SPLIT_HAND_PIN GP4
#define USB_VBUS_PIN GP8
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP12
#define SERIAL_USART_RX_PIN GP13
#define SERIAL_USART_PIN_SWAP
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
#define I2C_DRIVER I2CD2
#define I2C1_SDA_PIN GP10
#define I2C1_SCL_PIN GP11


// RGB Matrix
#define RGB_MATRIX_LED_COUNT 68
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_aro_ace_splash

#define RGB_MATRIX_KEYREACTIVE_ENABLED
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SPLASH


//split syncing functionality
#define MASTER_LEFT
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_MODS_ENABLE





#undef RGB_MATRIX_NONE
#undef RGB_MATRIX_SOLID_COLOR    // Static single hue, no speed support
#undef RGB_MATRIX_ALPHAS_MODS          // Static dual hue, speed is hue for secondary hue
#undef RGB_MATRIX_GRADIENT_UP_DOWN     // Static gradient top to bottom, speed controls how much gradient changes
#undef RGB_MATRIX_GRADIENT_LEFT_RIGHT     // Static gradient left to right, speed controls how much gradient changes
#undef RGB_MATRIX_BREATHING            // Single hue brightness cycling animation
#undef RGB_MATRIX_BAND_SAT         // Single hue band fading saturation scrolling left to right
#undef RGB_MATRIX_BAND_VAL         // Single hue band fading brightness scrolling left to right
#undef RGB_MATRIX_BAND_PINWHEEL_SAT    // Single hue 3 blade spinning pinwheel fades saturation
#undef RGB_MATRIX_BAND_PINWHEEL_VAL    // Single hue 3 blade spinning pinwheel fades brightness
#undef RGB_MATRIX_BAND_SPIRAL_SAT      // Single hue spinning spiral fades saturation
#undef RGB_MATRIX_BAND_SPIRAL_VAL      // Single hue spinning spiral fades brightness
#undef RGB_MATRIX_CYCLE_ALL            // Full keyboard solid hue cycling through full gradient
#undef RGB_MATRIX_CYCLE_LEFT_RIGHT     // Full gradient scrolling left to right
#undef RGB_MATRIX_CYCLE_UP_DOWN        // Full gradient scrolling top to bottom
#undef RGB_MATRIX_CYCLE_OUT_IN         // Full gradient scrolling out to in
#undef RGB_MATRIX_CYCLE_OUT_IN_DUAL    // Full dual gradients scrolling out to in
#undef RGB_MATRIX_RAINBOW_MOVING_CHEVRON   // Full gradient Chevron shapped scrolling left to right
#undef RGB_MATRIX_CYCLE_PINWHEEL       // Full gradient spinning pinwheel around center of keyboard
#undef RGB_MATRIX_CYCLE_SPIRAL         // Full gradient spinning spiral around center of keyboard
#undef RGB_MATRIX_DUAL_BEACON          // Full gradient spinning around center of keyboard
#undef RGB_MATRIX_RAINBOW_BEACON       // Full tighter gradient spinning around center of keyboard
#undef RGB_MATRIX_RAINBOW_PINWHEELS    // Full dual gradients spinning two halfs of keyboard
#undef RGB_MATRIX_FLOWER_BLOOMING      // Full tighter gradient of first half scrolling left to right and second half scrolling right to left
#undef RGB_MATRIX_RAINDROPS            // Randomly changes a single key's hue
#undef RGB_MATRIX_JELLYBEAN_RAINDROPS  // Randomly changes a single key's hue and saturation
#undef RGB_MATRIX_HUE_BREATHING        // Hue shifts up a slight ammount at the same time, then shifts back
#undef RGB_MATRIX_HUE_PENDULUM         // Hue shifts up a slight ammount in a wave to the right, then back to the left
#undef RGB_MATRIX_HUE_WAVE             // Hue shifts up a slight ammount and then back down in a wave to the right
#undef RGB_MATRIX_PIXEL_FRACTAL        // Single hue fractal filled keys pulsing horizontally out to edges
#undef RGB_MATRIX_PIXEL_FLOW           // Pulsing RGB flow along LED wiring with random hues
#undef RGB_MATRIX_PIXEL_RAIN           // Randomly light keys with random hues
#undef RGB_MATRIX_TYPING_HEATMAP       // How hot is your WPM!
#undef RGB_MATRIX_DIGITAL_RAIN         // That famous computer simulation
#undef RGB_MATRIX_SOLID_REACTIVE
#undef RGB_MATRIX_SOLID_REACTIVE_SIMPLE    // Pulses keys hit to hue & value then fades value out #undef RGB_MATRIX_SOLID_REACTIVE       // Static single hue, pulses keys hit to shifted hue then fades to current hue #undef RGB_MATRIX_SOLID_REACTIVE_WIDE        // Hue & value pulse near a single key hit then fades value out
#undef RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE   // Hue & value pulse near multiple key hits then fades value out
#undef RGB_MATRIX_SOLID_REACTIVE_CROSS       // Hue & value pulse the same column and row of a single key hit then fades value out
#undef RGB_MATRIX_SOLID_REACTIVE_MULTICROSS  // Hue & value pulse the same column and row of multiple key hits then fades value out
#undef RGB_MATRIX_SOLID_REACTIVE_NEXUS       // Hue & value pulse away on the same column and row of a single key hit then fades value out
#undef RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS  // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#undef RGB_MATRIX_SPLASH               // Full gradient & value pulse away from a single key hit then fades value out
#undef RGB_MATRIX_SOLID_SPLASH         // Hue & value pulse away from a single key hit then fades value out
#undef RGB_MATRIX_STARLIGHT            // LEDs turn on and off at random at varying brightness, maintaining user set color
#undef RGB_MATRIX_STARLIGHT_DUAL_HUE   // LEDs turn on and off at random at varying brightness, modifies user set hue by +- 30
#undef RGB_MATRIX_STARLIGHT_DUAL_SAT   // LEDs turn on and off at random at varying brightness, modifies user set saturation by +- 30
#undef RGB_MATRIX_RIVERFLOW            // Modification to breathing animation, offset's animation depending on key location to simulate a river flowing
#undef RGB_MATRIX_EFFECT_MAX
#define RGB_MATRIX_ARO_ACE_SPLASH

//disable effects
#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN

#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

//#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH


