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
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Context for storing state of a tap dance action.
typedef struct {
    bool is_press_action;
    td_state_t state;
} td_context_t;

typedef struct {
    uint16_t kc1;
    uint16_t kc2;
    uint16_t kc3;
    uint16_t kc4;
    td_context_t *context;
} tap_dance_quad_t;

typedef struct {
    uint16_t kc1;
    uint16_t kc2;
    uint8_t layer;
    td_context_t *context;
} tap_dance_pair_layer_t;

// Tap once for 'kc1', hold to hold 'kc2', double tap to tap 'kc3', and tap and hold to hold 'kc4'.
#define ACTION_TAP_DANCE_QUAD(kc1, kc2, kc3, kc4) \
    { .fn = {td_quad_on_each_tap_fn, td_quad_finished_fn, td_quad_reset_fn, NULL}, .user_data = (void *)&((tap_dance_quad_t){kc1, kc2, kc3, kc4}) }

// Tap once for 'kc1' + 'kc2', hold for 'kc1' + 'kc2' then activate 'layer' momentarily with 'kc1' still held.
#define ACTION_TAP_DANCE_MOD_TAP_LAYER(kc1, kc2, layer) \
    { .fn = {NULL, td_mod_tap_layer_finished_fn, td_mod_tap_layer_reset_fn, NULL}, .user_data = (void *)&((tap_dance_pair_layer_t){kc1, kc2, layer}) }

/**
 * Perform initial setup. Must be called before using any tap dances.
 */
void initialize_tap_dance(void);

/**
 * Get a tap dance context with current tap dance information.
 */
td_context_t *get_context(tap_dance_state_t *state);

/**
 * Determine the current tap dance state.
 */
td_state_t cur_dance(tap_dance_state_t *state);

// Tap dance functions (send keycodes based on tap dance state).
void td_quad_on_each_tap_fn(tap_dance_state_t *state, void *user_data);
void td_quad_finished_fn(tap_dance_state_t *state, void *user_data);
void td_quad_reset_fn(tap_dance_state_t *state, void *user_data);

void td_mod_tap_layer_finished_fn(tap_dance_state_t *state, void *user_data);
void td_mod_tap_layer_reset_fn(tap_dance_state_t *state, void *user_data);
