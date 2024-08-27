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
    TD_QUOTE,
    TD_ALT_TAB,
};

enum custom_keycodes {
    SI_CIRCUMFLEX = SAFE_RANGE,
    SI_DEGREE,
    SI_GROVE,
    SI_LEFT_SHIFT_ALT,
    SI_SELECT_WORD,
    SI_TILDE
};

// Aliases for tap dance keycodes.
#define TD_QUOT TD_QUOTE
#define TD_ATAB TD_ALT_TAB

// Aliases for custom keycodes.
#define SI_CIRC SI_CIRCUMFLEX
#define SI_DEG SI_DEGREE
#define SI_GRV SI_GROVE
#define SI_LSA SI_LEFT_SHIFT_ALT
#define SI_SELW SI_SELECT_WORD
#define SI_TILD SI_TILDE

/**
 * Execute custom keycodes.
 */
bool sjimooon_process_record_user(uint16_t keycode, keyrecord_t *record);
