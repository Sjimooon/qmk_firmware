#pragma once

#include "quantum.h"

// Tap dance states.
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    //TD_TRIPLE_TAP,
    //TD_TRIPLE_HOLD
} td_state_t;

// Context for storing state of a tap dance action.
typedef struct {
    bool is_press_action;
    td_state_t state;
} td_context_t;

typedef struct {
    uint16_t kc1;
    uint16_t kc2;
    uint8_t layer;
} tap_dance_pair_layer_t;

#define ACTION_TAP_DANCE_TAB_HOLD(kc1, kc2) \
    { .fn = {NULL, td_tap_hold_finished_fn, td_tap_hold_reset_fn, td_tap_hold_release_fn}, .user_data = (void *)&((tap_dance_pair_t){kc1, kc2}) }

#define ACTION_TAP_DANCE_MOD_TAP_LAYER(kc1, kc2, layer) \
    { .fn = {NULL, td_mod_tap_layer_finished_fn, td_mod_tap_layer_reset_fn, NULL}, .user_data = (void *)&((tap_dance_pair_layer_t){kc1, kc2, layer}) }

/**
 * Determine the current tap dance state on key release.
 */
void cur_dance_release(tap_dance_state_t *state, td_context_t *tap);

/**
 * Determine the current tap dance state when the tapping term duration has passed.
 */
void cur_dance_finished(tap_dance_state_t *state, td_context_t *tap);

// Tap dance action functions (calls logic funtions).
void td_tap_hold_release_fn(tap_dance_state_t *state, void *user_data);
void td_tap_hold_finished_fn(tap_dance_state_t *state, void *user_data);
void td_tap_hold_reset_fn(tap_dance_state_t *state, void *user_data);

void td_mod_tap_layer_finished_fn(tap_dance_state_t *state, void *user_data);
void td_mod_tap_layer_reset_fn(tap_dance_state_t *state, void *user_data);

// Tap dance logic functions (sends keycodes based on tap dance state).
void td_tap_hold_release(tap_dance_state_t *state, uint16_t tap_keycode, uint16_t hold_keycode);
void td_tap_hold_finished(tap_dance_state_t *state, uint16_t tap_keycode, uint16_t hold_keycode);
void td_tap_hold_reset(tap_dance_state_t *state, uint16_t tap_keycode, uint16_t hold_keycode);

void td_mod_tap_layer_finished(tap_dance_state_t *state, uint16_t modifier_keycode, uint16_t tap_keycode, uint8_t layer);
void td_mod_tap_layer_reset(tap_dance_state_t *state, uint16_t modifier_keycode, uint16_t tap_keycode, uint8_t layer);
