/* Copyright 2022 @ Teimor Epstein
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Windows CapsLock language change */
#include "tap_dance_feats.h"

static td_tap_t caps_language_tap_state = {.is_press_action = true, .state = TD_NONE};
static td_tap_t super_tap_state = {.is_press_action = true, .state = TD_NONE};
static td_tap_t sleep_tap_state = {.is_press_action = true, .state = TD_NONE};
static td_tap_t page_up_tap_state = {.is_press_action = true, .state = TD_NONE};
static td_tap_t page_down_tap_state = {.is_press_action = true, .state = TD_NONE};

// CapsLock keycode custom functions
void win_caps_language_finished(qk_tap_dance_state_t *state, void *user_data) {
    caps_language_tap_state.state = current_dance(state);
    switch (caps_language_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_CAPS_LOCK);
            break;
        case TD_SINGLE_HOLD:
            register_code(KC_LGUI);
            register_code(KC_SPACE);
            break;
        default:
            break;
    }
}

void win_caps_language_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (caps_language_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_CAPS_LOCK);
            break;
        case TD_SINGLE_HOLD:
            unregister_code(KC_SPACE);
            unregister_code(KC_LGUI);
            break;
        default:
            break;
    }
    caps_language_tap_state.state = TD_NONE;
}

// Super key custom functions
void win_spr_finished(qk_tap_dance_state_t *state, void *user_data) {
    super_tap_state.state = current_dance(state);
    switch (super_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_LGUI);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_LGUI);
            register_code(KC_E);
            break;
        case TD_DOUBLE_HOLD:
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_T);
            break;
        default:
            break;
    }
}

void win_spr_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (super_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_LGUI);
            break;
        case TD_DOUBLE_TAP:
            unregister_code(KC_LGUI);
            unregister_code(KC_E);
            break;
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
            unregister_code(KC_T);
            break;
        default:
            break;
    }
    super_tap_state.state = TD_NONE;
}

// Sleep (Fn + esc) custom functions
void win_slp_finished(qk_tap_dance_state_t *state, void *user_data) {
    sleep_tap_state.state = current_dance(state);
    switch (sleep_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_TRNS);
            break;
        case TD_TRIPLE_HOLD:
            register_code(KC_SLEP);
        default:
            break;
    }
}

void win_slp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (sleep_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_TRNS);
            break;
        case TD_TRIPLE_HOLD:
            unregister_code(KC_SLEP);
            break;
        default:
            break;
    }
    sleep_tap_state.state = TD_NONE;
}

// End key custom functions
void win_page_up_finished(qk_tap_dance_state_t *state, void *user_data) {
    page_up_tap_state.state = current_dance(state);
    switch (page_up_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_END);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            register_code(KC_PGUP);
            break;
        default:
            break;
    }
}

void win_page_up_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (page_up_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_END);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            unregister_code(KC_PGUP);
            break;
        default:
            break;
    }
    page_up_tap_state.state = TD_NONE;
}

// Home key custom functions
void win_page_down_finished(qk_tap_dance_state_t *state, void *user_data) {
    page_down_tap_state.state = current_dance(state);
    switch (page_down_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_HOME);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            register_code(KC_PGDN);
            break;
        default:
            break;
    }
}

void win_page_down_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (page_down_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_HOME);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            unregister_code(KC_PGDN);
            break;
        default:
            break;
    }
    page_down_tap_state.state = TD_NONE;
}
