#include QMK_KEYBOARD_H

#include "keymap_danish.h"
#include "sjimooon.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_COLE] = LAYOUT_ortho_5x15(
        RGB_MOD,     KC_1,        KC_2,        KC_3,        KC_4,       KC_5,        KC_ESC,      KC_TRNS,     KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_TRNS,     QK_BOOT,
        KC_DEL,      KC_Q,        KC_W,        KC_F,        KC_P,       KC_G,        KC_TRNS,     KC_TRNS,     KC_J,        KC_L,        KC_U,        KC_Y,        KC_TRNS,     KC_TRNS,     QK_RBT,
        KC_BSPC,     KC_A,        KC_R,        KC_S,        KC_T,       KC_D,        KC_ENT,      KC_TRNS,     KC_H,        KC_N,        KC_E,        KC_I,        KC_O,        TD(TD_QUOT), KC_TRNS,
        KC_LSFT,     KC_Z,        KC_X,        KC_C,        KC_V,       KC_B,        KC_TRNS,     KC_TRNS,     KC_K,        KC_M,        KC_COMM,     KC_DOT,      DK_MINS,     KC_TRNS,     KC_TRNS,
        KC_LCTL,     TD(TD_ATAB), SI_LSA,    OSM(MOD_LALT), CW_TOGG, CTL_T(KC_SPC), LT(L_NAV, KC_TAB), KC_ENT, OSL(L_SYM),  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS
    ),
	//[L_GAME] = LAYOUT_ortho_5x15(
    //    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_6,        KC_7,        KC_8,        KC_9,        KC_9,        KC_0,        KC_TRNS,     KC_TRNS,     KC_TRNS,
    //    KC_TRNS,     KC_CAPS,     KC_Q,        KC_W,        KC_E,       KC_R,        KC_T,        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    //    RGB_MOD,     KC_LSFT,     KC_A,        KC_S,        KC_D,       KC_F,        KC_G,        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    //    KC_TRNS,     KC_LCTL,     KC_Z,        KC_X,        KC_C,       KC_V,        KC_V,        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    //    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_LALT,     KC_B,       KC_SPC,      KC_TAB,      KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS
    //),
    [L_NUM] = LAYOUT_ortho_5x15(
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_P7,       KC_P8,       KC_P9,       KC_PSLS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_P4,       KC_P5,       KC_P6,       KC_PAST,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_P1,       KC_P2,       KC_P3,       KC_PMNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_PENT,     KC_TRNS,     KC_P0,       KC_PDOT,     KC_DOT,      KC_PPLS,     KC_NUM,      KC_TRNS
    ),
    [L_SYM] = LAYOUT_ortho_5x15(
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     DK_HALF,     DK_EXLM,     DK_LCBR,     DK_RCBR,    DK_QUES,     KC_TRNS,     KC_TRNS,     SI_CIRC,     DK_ASTR,     DK_SLSH,     DK_BSLS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     DK_HASH,     DK_AMPR,     DK_LPRN,     DK_RPRN,    DK_PIPE,     KC_TRNS,     KC_TRNS,     SI_TILD,     DK_LABK,     DK_RABK,     DK_EQL,      DK_AE,       DK_OSTR,     KC_TRNS,
        KC_TRNS,     DK_AT,       DK_DLR,      DK_LBRC,     DK_RBRC,    SI_GRV,      KC_TRNS,     KC_TRNS,     SI_DEG,      DK_PLUS,     DK_MINS,     DK_PERC,     DK_ARNG,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS
    ),
    [L_NAV] = LAYOUT_ortho_5x15(
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_PGUP,     KC_HOME,     KC_UP,       KC_END,      KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_LSFT,     SI_LSA,      KC_LALT,     KC_LCTL,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_PGDN,     KC_LEFT,     KC_DOWN,     KC_RGHT,     KC_INS,      KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_APP,      SI_SELW,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return sjimooon_process_record_user(keycode, record);
}
