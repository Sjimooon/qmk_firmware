#include "sjimooon.h"
#include "tap_dance.h"
#include "send_string.h"
#include "sendstring_danish.h"

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ', twice for "
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(DK_QUOT, DK_DQUO),
    // Tab once for Alt + Tab, hold for Alt + Tab then activate layer momentarily with Alt held
    [TD_ATAB] = ACTION_TAP_DANCE_MOD_TAP_LAYER(KC_LALT, KC_TAB, L_NAV),
};

bool sjimooon_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SI_CIRC:
            // ^
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_RBRC)) " ");
            }
            break;
        case SI_DEG:
            // ° (Alt + 0176)
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_P0);
                tap_code(KC_P1);
                tap_code(KC_P7);
                tap_code(KC_P6);
                unregister_code(KC_LALT);
            }
            break;
        case SI_GRV:
            // `
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_EQL)) " ");
            }
            break;
        case SI_SELW:
            // Select Word
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_LEFT);
                register_code(KC_LSFT);
                tap_code(KC_RGHT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            break;
        case SI_LSA:
            // Left Shift and Left Alt
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LALT);
            }
            else {
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            break;
        case SI_TILD:
            // ~
            if (record->event.pressed) {
                SEND_STRING(SS_RALT(SS_TAP(X_RBRC)) " ");
            }
            break;
        default:
            break;
    }

    return true;
}
