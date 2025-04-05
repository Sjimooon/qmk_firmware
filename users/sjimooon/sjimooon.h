#pragma once

#include "quantum.h"

enum sjimooon_layers
{
    L_COLE = 0, // Colemak
    L_GAME, // Game
    L_NUM, // Numpad
    L_SYM, // Symbols
    L_NAV, // Navigation
    L_MOUS, // Mouse
    L_BRDG // Bridge
};

enum td_keycodes {
    TD_QUOTE = 0,
    TD_ALT_TAB,
    TD_COUNT
};

enum custom_keycodes {
    // Symbols
    S_CIRCUMFLEX = SAFE_RANGE,
    S_DEGREE,
    S_GROVE,
    S_TILDE,
    // Modifiers
    S_LEFT_SHIFT_ALT,
    // Advanced
    S_SELECT_WORD,
    // RGB Matrix
    S_RGB_MATRIX_SAVE_EEPROM,
    S_RGB_MATRIX_RELOAD_EEPROM,
    S_RGB_MATRIX_TOGGLE,
    S_RGB_MATRIX_ANIMATION_NEXT,
    S_RGB_MATRIX_ANIMATION_PREVIOUS,
    S_RGB_MATRIX_HUE_UP,
    S_RGB_MATRIX_HUE_DOWN,
    S_RGB_MATRIX_SATURATION_UP,
    S_RGB_MATRIX_SATURATION_DOWN,
    S_RGB_MATRIX_VALUE_UP,
    S_RGB_MATRIX_VALUE_DOWN,
    S_RGB_MATRIX_SPEED_UP,
    S_RGB_MATRIX_SPEED_DOWN
};

tap_dance_action_t tap_dance_actions[TD_COUNT];

// Aliases for tap dance keycodes.
#define TD_QUOT TD_QUOTE
#define TD_ATAB TD_ALT_TAB

// Aliases for custom keycodes.
// Symbols
#define SS_CIRC S_CIRCUMFLEX
#define SS_DEG S_DEGREE
#define SS_GRV S_GROVE
#define SS_TILD S_TILDE
// Modifiers
#define SM_LSA S_LEFT_SHIFT_ALT
// Advanced
#define SA_SELW S_SELECT_WORD
// RGB Matrix
#define SR_SAVE S_RGB_MATRIX_SAVE_EEPROM
#define SR_RELO S_RGB_MATRIX_RELOAD_EEPROM
#define SR_TOGG S_RGB_MATRIX_TOGGLE
#define SR_ANIN S_RGB_MATRIX_ANIMATION_NEXT
#define SR_ANIP S_RGB_MATRIX_ANIMATION_PREVIOUS
#define SR_HUEU S_RGB_MATRIX_HUE_UP
#define SR_HUED S_RGB_MATRIX_HUE_DOWN
#define SR_SATU S_RGB_MATRIX_SATURATION_UP
#define SR_SATD S_RGB_MATRIX_SATURATION_DOWN
#define SR_VALU S_RGB_MATRIX_VALUE_UP
#define SR_VALD S_RGB_MATRIX_VALUE_DOWN
#define SR_SPDU S_RGB_MATRIX_SPEED_UP
#define SR_SPDD S_RGB_MATRIX_SPEED_DOWN

/**
 * Run initializing code.
 */
void keyboard_pre_init_sjimooon(void);

/**
 * Execute custom keycodes.
 *
 * @return `false` if no further processing should happen for this key.
 */
bool process_record_sjimooon(uint16_t keycode, keyrecord_t *record);

/**
 * Like `register_code16()` but with support for custom keycodes.
 * Will call the default function if `code` isn't a custom keycode.
 */
void register_code16_sjimooon(uint16_t code);

/**
 * Like `unregister_code16()` but with support for custom keycodes.
 * Will call the default function if `code` isn't a custom keycode.
 */
void unregister_code16_sjimooon(uint16_t code);

/**
 * Like `register_code16()` but with support for custom keycodes.
 * Will call the default function if `code` isn't a custom keycode.
 */
void tap_code16_sjimooon(uint16_t code);

/**
 * Like `register_code16_delay()` but with support for custom keycodes.
 * Will call the default function if `code` isn't a custom keycode.
 */
void tap_code16_delay_sjimooon(uint16_t code, uint16_t delay);
