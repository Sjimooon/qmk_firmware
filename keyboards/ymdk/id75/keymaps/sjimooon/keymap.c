#include QMK_KEYBOARD_H

#include "keymap_danish.h"
#include "sjimooon.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_COLE] = LAYOUT_ortho_5x15(
        _______,     KC_1,        KC_2,        KC_3,        KC_4,       KC_5,        _______,     _______,     KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        _______,     _______,
        KC_DEL,      KC_Q,        KC_W,        KC_F,        KC_P,       KC_G,        _______,     _______,     KC_J,        KC_L,        KC_U,        KC_Y,        _______,     _______,     _______,
        KC_BSPC,     KC_A,        KC_R,        KC_S,        KC_T,       KC_D,        KC_ENT,      _______,     KC_H,        KC_N,        KC_E,        KC_I,        KC_O,        TD(TD_QUOT), TG(L_BRDG),
        _______,     KC_Z,        KC_X,        KC_C,        KC_V,       KC_B,        _______,     _______,     KC_K,        KC_M,        KC_COMM,     KC_DOT,      DK_MINS,     _______,     _______,
        _______,     TD(TD_ATAB),TD(TD_ESC),OSM(MOD_LALT),CW_TOGG,CTL_T(KC_SPC),LT(L_NAV, KC_TAB),KC_ENT,      OSL(L_SYM),  _______,     OSM(MOD_LGUI),_______,    _______,     _______,     _______
    ),
	//[L_GAME] = LAYOUT_ortho_5x15(
    //    _______,     _______,     _______,     _______,     _______,    _______,     KC_6,        KC_7,        KC_8,        KC_9,        KC_9,        KC_0,        _______,     _______,     _______,
    //    _______,     KC_CAPS,     KC_Q,        KC_W,        KC_E,       KC_R,        KC_T,        _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,
    //    _______,     KC_LSFT,     KC_A,        KC_S,        KC_D,       KC_F,        KC_G,        _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,
    //    _______,     KC_LCTL,     KC_Z,        KC_X,        KC_C,       KC_V,        KC_V,        _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,
    //    _______,     _______,     _______,     KC_LALT,     KC_B,       KC_SPC,      KC_TAB,      _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______
    //),
    [L_NUM] = LAYOUT_ortho_5x15(
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     _______,     _______,     KC_P7,       KC_P8,       KC_P9,       KC_PSLS,     _______,     _______,
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     _______,     _______,     KC_P4,       KC_P5,       KC_P6,       KC_PAST,     _______,     _______,
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     _______,     _______,     KC_P1,       KC_P2,       KC_P3,       KC_PMNS,     _______,     _______,
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     KC_PENT,     _______,     KC_P0,       KC_PDOT,     KC_DOT,      KC_PPLS,     KC_NUM,      _______
    ),
    [L_SYM] = LAYOUT_ortho_5x15(
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,
        _______,     DK_HALF,     DK_EXLM,     DK_LCBR,     DK_RCBR,    DK_QUES,     _______,     _______,     SS_CIRC,     DK_ASTR,     DK_SLSH,     DK_BSLS,     _______,     _______,     _______,
        _______,     DK_HASH,     DK_AMPR,     DK_LPRN,     DK_RPRN,    DK_PIPE,     _______,     _______,     SS_TILD,     DK_LABK,     DK_RABK,     DK_EQL,      DK_AE,       DK_OSTR,     _______,
        _______,     DK_AT,       DK_DLR,      DK_LBRC,     DK_RBRC,    SS_GRV,      _______,     _______,     SS_DEG,      DK_PLUS,     DK_MINS,     DK_PERC,     DK_ARNG,     _______,     _______,
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______
    ),
    [L_NAV] = LAYOUT_ortho_5x15(
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     KC_PGUP,     LSA(KC_COMM),KC_HOME,     KC_UP,       KC_END,      _______,     _______,     _______,
        _______,     KC_LSFT,     SM_LSA,      KC_LALT,     KC_LCTL,    _______,     _______,     KC_PGDN,     LSA(KC_DOT), KC_LEFT,     KC_DOWN,     KC_RGHT,     KC_INS,      _______,     _______,
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     _______,     _______,     KC_APP,      SA_SELW,     _______,     _______,     _______,     _______,
        _______,     _______,     _______,     _______,     _______,    _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______
    ),
    [L_BRDG] = LAYOUT_ortho_5x15(
        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     QK_BOOT,
        XXXXXXX,     SR_SPDU,     SR_HUEU,     SR_SATU,     SR_VALU,    SR_ANIN,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     QK_RBT,
        SR_RELO,     SR_SPDD,     SR_HUED,     SR_SATD,     SR_VALD,    SR_ANIP,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     TG(L_BRDG),
        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,    SR_TOGG,     XXXXXXX,     SR_SAVE,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX
    )
};

void keyboard_pre_init_user(void) {
    keyboard_pre_init_sjimooon();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_sjimooon(keycode, record);
}

//bool rgb_matrix_indicators_user(void) {
//    hsv_t hsv = {0, 255, 255};
//
//    // Limit 'v' (value) to current brightness.
//    if (hsv.v > rgb_matrix_get_val()) {
//        hsv.v = rgb_matrix_get_val();
//    }
//    rgb_t rgb = hsv_to_rgb(hsv);
//
//    rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);
//
//    return true;
//}
