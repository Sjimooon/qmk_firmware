#include "sjimooon.h"
#include "tap_dance.h"
#include "send_string.h"
#include "sendstring_danish.h"

// Default keypress information.
static keyrecord_t default_keyrecord_press = {
    .event = {
        .key = {
            .col = 0,
            .row = 0
        },
        .pressed = true,
        .time = 0
    }
};

static keyrecord_t default_keyrecord_release = {
    .event = {
        .key = {
            .col = 0,
            .row = 0
        },
        .pressed = false,
        .time = 0
    }
};

/**
 * Unregister a registered keycode. Support for custom keycodes.
 */
static void release_code16_sjimooon(uint16_t code, uint16_t delay);

tap_dance_action_t tap_dance_actions[] = {
    // Tab once for Alt + Tab, hold for Alt + Tab then activate layer momentarily with Alt still held.
    [TD_ATAB] = ACTION_TAP_DANCE_MOD_TAP_LAYER(KC_LALT, KC_TAB, L_NAV),
    // Tab once for Esc, hold for
    [TD_ESC] = ACTION_TAP_DANCE_QUAD_TAP(KC_ESC, S(KC_ESC), KC_NO, KC_NO),
    // Tap once for ' and hold or double tap for ".
    [TD_QUOT] = ACTION_TAP_DANCE_QUAD_TAP(DK_QUOT, DK_DQUO, DK_DQUO, S_TILDE),
    //[TD_PRRE] = ACTION_TAP_DANCE_QUAD(SA_PRRE, SA_PRRE, SA_PRRE, SA_PRRE)
};

void keyboard_pre_init_sjimooon(void) {
    initialize_tap_dance();
}

bool process_record_sjimooon(uint16_t keycode, keyrecord_t *record) {
    // Tip: In VS Code, hit 'Ctrl + K' 'Ctrl + 3' to fold cases and 'Ctrl + K' + 'Ctrl + J' to unfold all.
    switch (keycode) {
        // Symbols
        case S_CIRCUMFLEX:
            // ^
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_RBRC)) " ");
            }
            return false;
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
            return false;
        case S_GROVE:
            // `
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_EQL)) " ");
            }
            return false;
        case S_TILDE:
            // ~
            if (record->event.pressed) {
                SEND_STRING(SS_RALT(SS_TAP(X_RBRC)) " ");
            }
            return false;
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
            return false;
        // Advanced
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
            return false;
        case S_PRESS_RELEASE:
            if (record->event.pressed) {
                SEND_STRING("PRESS ");
            } else {
                SEND_STRING("RELEASE ");
            }
            return false;
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
            return false;
        case S_RGB_MATRIX_RELOAD_EEPROM:
            // Reset RGB Matrix to configuration saved in EEPROM.
            if (record->event.pressed) {
                rgb_matrix_reload_from_eeprom();
            }
            return false;
        case S_RGB_MATRIX_TOGGLE:
            // Toggle RGB matrix on or off.
            if (record->event.pressed) {
                rgb_matrix_toggle_noeeprom();
            }
            return false;
        case S_RGB_MATRIX_ANIMATION_NEXT:
            // Next animation.
            if (record->event.pressed) {
                rgb_matrix_step_noeeprom();
            }
            return false;
        case S_RGB_MATRIX_ANIMATION_PREVIOUS:
            // Previous animation.
            if (record->event.pressed) {
                rgb_matrix_step_reverse_noeeprom();
            }
            return false;
        case S_RGB_MATRIX_HUE_UP:
            // Color hue up.
            if (record->event.pressed) {
                rgb_matrix_increase_hue_noeeprom();
            }
            return false;
        case S_RGB_MATRIX_HUE_DOWN:
            // Color hue down.
            if (record->event.pressed) {
                rgb_matrix_decrease_hue_noeeprom();
            }
            return false;
        case S_RGB_MATRIX_SATURATION_UP:
            // Color saturation up.
            if (record->event.pressed) {
                rgb_matrix_increase_sat_noeeprom();
            }
            return false;
        case S_RGB_MATRIX_SATURATION_DOWN:
            // Color saturation down.
            if (record->event.pressed) {
                rgb_matrix_decrease_sat_noeeprom();
            }
            return false;
        case S_RGB_MATRIX_VALUE_UP:
            // Color value (brightness) up.
            if (record->event.pressed) {
                rgb_matrix_increase_val_noeeprom();
            }
            return false;
        case S_RGB_MATRIX_VALUE_DOWN:
            // Color value (brightness) down.
            if (record->event.pressed) {
                rgb_matrix_decrease_val_noeeprom();
            }
            return false;
        case S_RGB_MATRIX_SPEED_UP:
            // Animation speed up.
            if (record->event.pressed) {
                rgb_matrix_increase_speed_noeeprom();
            }
            return false;
        case S_RGB_MATRIX_SPEED_DOWN:
            // Animation speed down.
            if (record->event.pressed) {
                rgb_matrix_decrease_speed_noeeprom();
            }
            return false;
        default:
            break;
    }

    return true;
}

// Custom keycode register, unregister, and tap functions.
void register_code16_sjimooon(uint16_t code) {
    if (process_record_sjimooon(code, &default_keyrecord_press))
        register_code16(code);
}

void unregister_code16_sjimooon(uint16_t code) {
    if (process_record_sjimooon(code, &default_keyrecord_release))
        unregister_code16(code);
}

void tap_code16_sjimooon(uint16_t code) {
    if (process_record_sjimooon(code, &default_keyrecord_press)) {
        tap_code16(code);

        return;
    }

    // Release the pressed custom keycode after the same delay that `tap_code16()` use internally.
    release_code16_sjimooon(code, code == KC_CAPS_LOCK ? TAP_HOLD_CAPS_DELAY : TAP_CODE_DELAY);
}

void tap_code16_delay_sjimooon(uint16_t code, uint16_t delay) {
    if (process_record_sjimooon(code, &default_keyrecord_press)) {
        tap_code16_delay(code, delay);

        return;
    }

    // Release the pressed custom keycode after the delay.
    release_code16_sjimooon(code, delay);
}

void release_code16_sjimooon(uint16_t code, uint16_t delay) {
    for (uint16_t i = delay; i > 0; i--) {
        wait_ms(1);
    }

    process_record_sjimooon(code, &default_keyrecord_release);
}
