#include "tap_dance.h"

// Global tap dance context.
static td_context_t td_context = {
    .is_press_action = true,
    .state = TD_NONE
};

/*
 * Assumed states for tab and hold actions.
 *
 * Tab (release within tapping term)
 * (1) tab:      pressed = true,  finished = false, interrupted = false
 * (2) release:  pressed = false, finished = false, interrupted = false/true
 * (3) finished: pressed = false, finished = true,  interrupted = false/true
 * (4) reset:    pressed = false, finished = true,  interrupted = false/true
 *
 * Hold (release after tapping term)
 * (1) tab:      pressed = true,  finished = false, interrupted = false
 * (2) finished: pressed = true,  finished = true,  interrupted = false/true
 * (3) release:  pressed = false, finished = true,  interrupted = false/true
 * (4) reset:    pressed = false, finished = true,  interrupted = false/true
 */

void cur_dance_release(tap_dance_state_t *state, td_context_t *context) {
    if (state->finished)
        return;

    if (state->count == 1)
        context->state = TD_SINGLE_TAP;
    else if (state->count == 2)
        context->state = TD_DOUBLE_TAP;
}

void cur_dance_finished(tap_dance_state_t *state, td_context_t *context) {
    if (state->count == 1) {
        if (state->pressed || state->interrupted)
            context->state = TD_SINGLE_HOLD;
        else
            context->state = TD_SINGLE_TAP;
    } else if (state->count == 2) {
        if (state->pressed || state->interrupted)
            context->state = TD_DOUBLE_HOLD;
        else
            context->state = TD_DOUBLE_TAP;
    } else {
        context->state = TD_UNKNOWN;
    }
}

void td_tap_hold_release_fn(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;
    td_tap_hold_release(state, pair->kc1, pair->kc2);
}
void td_tap_hold_finished_fn(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;
    td_tap_hold_finished(state, pair->kc1, pair->kc2);
}
void td_tap_hold_reset_fn(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;
    td_tap_hold_reset(state, pair->kc1, pair->kc2);
}

void td_mod_tap_layer_finished_fn(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_layer_t *data = (tap_dance_pair_layer_t *)user_data;
    td_mod_tap_layer_finished(state, data->kc1, data->kc2, data->layer);
}
void td_mod_tap_layer_reset_fn(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_layer_t *data = (tap_dance_pair_layer_t *)user_data;
    td_mod_tap_layer_reset(state, data->kc1, data->kc2, data->layer);
}

// Tap Hold
void td_tap_hold_release(tap_dance_state_t *state, uint16_t tap_keycode, uint16_t hold_keycode) {
    cur_dance_release(state, &td_context);
    switch (td_context.state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code(tap_keycode);
            break;
        default:
            break;
    }
}

void td_tap_hold_finished(tap_dance_state_t *state, uint16_t tap_keycode, uint16_t hold_keycode) {
    cur_dance_finished(state, &td_context);
    switch (td_context.state) {
        case TD_SINGLE_HOLD:
            register_code(hold_keycode);
            break;
        case TD_DOUBLE_HOLD:
            register_code(tap_keycode);
            break;
        default:
            break;
    }
}

void td_tap_hold_reset(tap_dance_state_t *state, uint16_t tap_keycode, uint16_t hold_keycode) {
    switch (td_context.state) {
        case TD_SINGLE_HOLD:
            unregister_code(hold_keycode);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(tap_keycode);
            break;
        default:
            break;
    }
    td_context.state = TD_NONE;
}

// Mod Tap Layer
void td_mod_tap_layer_finished(tap_dance_state_t *state, uint16_t modifier_keycode, uint16_t tap_keycode, uint8_t layer) {
    cur_dance_finished(state, &td_context);
    switch (td_context.state) {
        case TD_SINGLE_TAP:
            register_code(modifier_keycode);
            tap_code(tap_keycode);
            break;
        case TD_SINGLE_HOLD:
            register_code(modifier_keycode);
            tap_code(tap_keycode);
            layer_on(layer);
            break;
        default:
            break;
    }
}

void td_mod_tap_layer_reset(tap_dance_state_t *state, uint16_t modifier_keycode, uint16_t tap_keycode, uint8_t layer) {
    switch (td_context.state) {
        case TD_SINGLE_TAP:
            unregister_code(modifier_keycode);
            break;
        case TD_SINGLE_HOLD:
            layer_off(layer);
            unregister_code(modifier_keycode);
            break;
        default:
            break;
    }
    td_context.state = TD_NONE;
}
