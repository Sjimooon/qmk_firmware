#include "tap_dance.h"

td_context_t get_context(tap_dance_state_t *state) {
    td_context_t context = {
        .is_press_action = true,
        .state = cur_dance(state)
    };

    return context;
}

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    } else {
        return TD_UNKNOWN;
    }
}

// Mod Tap Layer
void td_mod_tap_layer_finished_fn(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_layer_t *data = (tap_dance_pair_layer_t *)user_data;
    data->context = get_context(state);
    switch (data->context.state) {
        case TD_SINGLE_TAP:
            register_code(data->kc1);
            tap_code(data->kc2);
            break;
        case TD_SINGLE_HOLD:
            register_code(data->kc1);
            tap_code(data->kc2);
            layer_on(data->layer);
            break;
        default:
            break;
    }
}

void td_mod_tap_layer_reset_fn(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_layer_t *data = (tap_dance_pair_layer_t *)user_data;
    switch (data->context.state) {
        case TD_SINGLE_TAP:
            unregister_code(data->kc1);
            break;
        case TD_SINGLE_HOLD:
            layer_off(data->layer);
            unregister_code(data->kc1);
            break;
        default:
            break;
    }
    data->context.state = TD_NONE;
}

// Quad
void td_quad_finished_fn(tap_dance_state_t *state, void *user_data) {
    tap_dance_quad_t *data = (tap_dance_quad_t *)user_data;
    data->context = get_context(state);
    switch (data->context.state ) {
        case TD_SINGLE_TAP:
            register_code16(data->kc1);
            break;
        case TD_SINGLE_HOLD:
            register_code16(data->kc2);
            break;
        case TD_DOUBLE_TAP:
            register_code16(data->kc3);
            break;
        case TD_DOUBLE_HOLD:
            register_code16(data->kc4);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code16(data->kc1);
            register_code16(data->kc1);
            break;
        default:
            break;
    }
}

void td_quad_reset_fn(tap_dance_state_t *state, void *user_data) {
    tap_dance_quad_t *data = (tap_dance_quad_t *)user_data;
    switch (data->context.state) {
        case TD_SINGLE_TAP:
            unregister_code16(data->kc1);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(data->kc2);
            break;
        case TD_DOUBLE_TAP:
            unregister_code16(data->kc3);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code16(data->kc4);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(data->kc1);
            break;
        default:
            break;
    }
    data->context.state = TD_NONE;
}
