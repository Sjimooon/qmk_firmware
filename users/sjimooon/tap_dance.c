#include "tap_dance.h"
#include "sjimooon.h"

#define TD_CONTEXT_POOL_SIZE 10

typedef struct {
    td_context_t pool[TD_CONTEXT_POOL_SIZE];
    td_context_t *next;
} td_context_pool_t;

// Global pool of reuseable tap dance contexts.
static td_context_pool_t td_context_pool;

void initialize_tap_dance(void) {
    // Create the pool of reuseable tap dance contexts.
    size_t i;
    for (i = 0; i < TD_CONTEXT_POOL_SIZE; i++) {
        td_context_pool.pool[i].is_press_action = true;
        td_context_pool.pool[i].state = TD_NONE;
    }
    td_context_pool.next = td_context_pool.pool;
}

td_context_t *get_context(tap_dance_state_t *state) {
    td_context_t *context = td_context_pool.next;
    context->state = cur_dance(state);

    // Advance the 'next' pointer to the next context in the pool.
    // If the end has been reached, then go back to the first element.
    if (++td_context_pool.next < td_context_pool.pool + TD_CONTEXT_POOL_SIZE) {
        td_context_pool.next = td_context_pool.pool;
    }

    return context;
}

void recycle_context(td_context_t *context) {
    context->state = TD_NONE;
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

// Quad
void td_quad_on_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_dance_quad_t *data = (tap_dance_quad_t *)user_data;
    // If the tap dance key is tapped repeatedly (3 or more times), keep sending taps of the single tap keycode.
    if (state->count > 2) {
        if (state->count == 3) {
            tap_code16(data->kc1);
            tap_code16(data->kc1);
        }
        tap_code16(data->kc1);
    }
}

void td_quad_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_quad_t *data = (tap_dance_quad_t *)user_data;
    data->context = get_context(state);
    switch (data->context->state ) {
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

void td_quad_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_quad_t *data = (tap_dance_quad_t *)user_data;
    switch (data->context->state) {
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
    recycle_context(data->context);
}

// Quad Tap
void td_quad_on_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_dance_quad_t *data = (tap_dance_quad_t *)user_data;
    // If the tap dance key is tapped repeatedly (3 or more times), keep sending taps of the single tap keycode.
    if (state->count > 2) {
        if (state->count == 3) {
            if (process_keycode_sjimooon(data->kc1))
                tap_code16(data->kc1);
            if (process_keycode_sjimooon(data->kc1))
                tap_code16(data->kc1);
        }
        if (process_keycode_sjimooon(data->kc1))
            tap_code16(data->kc1);
    }
}

void td_quad_tap_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_quad_t *data = (tap_dance_quad_t *)user_data;
    data->context = get_context(state);
    switch (data->context->state ) {
        case TD_SINGLE_TAP:
            if (process_keycode_sjimooon(data->kc1))
                tap_code16(data->kc1);
            break;
        case TD_SINGLE_HOLD:
            if (process_keycode_sjimooon(data->kc2))
                tap_code16(data->kc2);
            break;
        case TD_DOUBLE_TAP:
            if (process_keycode_sjimooon(data->kc3))
                tap_code16(data->kc3);
            break;
        case TD_DOUBLE_HOLD:
            if (process_keycode_sjimooon(data->kc4))
                tap_code16(data->kc4);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            if (process_keycode_sjimooon(data->kc3))
                tap_code16(data->kc3);
            break;
        default:
            break;
    }
    recycle_context(data->context);
}

// Mod Tap Layer
void td_mod_tap_layer_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_layer_t *data = (tap_dance_pair_layer_t *)user_data;
    data->context = get_context(state);
    switch (data->context->state) {
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

void td_mod_tap_layer_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_layer_t *data = (tap_dance_pair_layer_t *)user_data;
    switch (data->context->state) {
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
    recycle_context(data->context);
}
