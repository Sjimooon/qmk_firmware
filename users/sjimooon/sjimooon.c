#include "sjimooon.h"
#include "tap_dance.h"
#include "send_string.h"
#include "sendstring_danish.h"

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ' and hold or double tap for ".
    [TD_QUOT] = ACTION_TAP_DANCE_QUAD(DK_QUOT, DK_DQUO, DK_DQUO, KC_NO),
    // Tab once for Alt + Tab, hold for Alt + Tab then activate layer momentarily with Alt still held.
    [TD_ATAB] = ACTION_TAP_DANCE_MOD_TAP_LAYER(KC_LALT, KC_TAB, L_NAV)
};

bool sjimooon_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Tip: In VS Code, hit 'Ctrl + K' 'Ctrl + 3' to fold cases and 'Ctrl + K' + 'Ctrl + J' to unfold all.
    switch (keycode) {
        // Symbols
        case S_CIRCUMFLEX:
            // ^
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_RBRC)) " ");
            }
            break;
        case S_DEGREE:
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
        case S_GROVE:
            // `
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_EQL)) " ");
            }
            break;
        case S_TILDE:
            // ~
            if (record->event.pressed) {
                SEND_STRING(SS_RALT(SS_TAP(X_RBRC)) " ");
            }
            break;
        // Modifiers
        case S_LEFT_SHIFT_ALT:
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
        // Functions
        case S_SELECT_WORD:
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
        // RGB Matrix
        case S_RGB_MATRIX_SAVE_EEPROM:
            // Save RGB Matrix configuration to EEPROM.
            if (record->event.pressed) {
                if (rgb_matrix_is_enabled()) {
                    rgb_matrix_enable();
                }
                else {
                    rgb_matrix_disable();
                }
                rgb_matrix_mode(rgb_matrix_get_mode());
                rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val());
                rgb_matrix_set_speed(rgb_matrix_get_speed());
            }
            break;
        case S_RGB_MATRIX_RELOAD_EEPROM:
            // Reset RGB Matrix to configuration saved in EEPROM.
            if (record->event.pressed) {
                rgb_matrix_reload_from_eeprom();
            }
            break;
        case S_RGB_MATRIX_TOGGLE:
            // Toggle RGB matrix on or off.
            if (record->event.pressed) {
                rgb_matrix_toggle_noeeprom();
            }
            break;
        case S_RGB_MATRIX_ANIMATION_NEXT:
            // Next animation.
            if (record->event.pressed) {
                rgb_matrix_step_noeeprom();
            }
            break;
        case S_RGB_MATRIX_ANIMATION_PREVIOUS:
            // Previous animation.
            if (record->event.pressed) {
                rgb_matrix_step_reverse_noeeprom();
            }
            break;
        case S_RGB_MATRIX_HUE_UP:
            // Color hue up.
            if (record->event.pressed) {
                rgb_matrix_increase_hue_noeeprom();
            }
            break;
        case S_RGB_MATRIX_HUE_DOWN:
            // Color hue down.
            if (record->event.pressed) {
                rgb_matrix_decrease_hue_noeeprom();
            }
            break;
        case S_RGB_MATRIX_SATURATION_UP:
            // Color saturation up.
            if (record->event.pressed) {
                rgb_matrix_increase_sat_noeeprom();
            }
            break;
        case S_RGB_MATRIX_SATURATION_DOWN:
            // Color saturation down.
            if (record->event.pressed) {
                rgb_matrix_decrease_sat_noeeprom();
            }
            break;
        case S_RGB_MATRIX_VALUE_UP:
            // Color value (brightness) up.
            if (record->event.pressed) {
                rgb_matrix_increase_val_noeeprom();
            }
            break;
        case S_RGB_MATRIX_VALUE_DOWN:
            // Color value (brightness) down.
            if (record->event.pressed) {
                rgb_matrix_decrease_val_noeeprom();
            }
            break;
        case S_RGB_MATRIX_SPEED_UP:
            // Animation speed up.
            if (record->event.pressed) {
                rgb_matrix_increase_speed_noeeprom();
            }
            break;
        case S_RGB_MATRIX_SPEED_DOWN:
            // Animation speed down.
            if (record->event.pressed) {
                rgb_matrix_decrease_speed_noeeprom();
            }
            break;
        default:
            break;
    }

    return true;
}
