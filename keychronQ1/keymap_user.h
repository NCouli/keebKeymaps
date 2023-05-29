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

#pragma once

// clang-format off

enum layers{
    BASIC_L,
    BASIC_FN,
    WIN_BASE,
    WIN_FN
};

// clang-format on

// Tap dance enums
enum {
    CAPS_LANGUAGE_CHANGE,
    SUPER,
    SLEEP,
    PAGE_UP,
    PAGE_DOWN,
};

#ifdef TAP_DANCE_ENABLE
#   define KC_LGWIN TD(CAPS_LANGUAGE_CHANGE)
#   define KC_LGSUP TD(SUPER)
#   define KC_LGSLP TD(SLEEP)
#   define KC_LGEPU TD(PAGE_UP)
#   define KC_LGHPD TD(PAGE_DOWN)
#else
#   define KC_LGWIN KC_CAPS
#   define KC_LGSUP KC_LGUI
#   define KC_LGSLP KC_TRNS
#   define KC_LGEPU KC_END
#   define KC_LGHPD KC_HOME
#endif
#define KC_BASFN MO(BASIC_FN)
#define KC_WINFN MO(WIN_FN)
// temp
#define KC_LMAC C(G(KC_Q))
#define KC_MACPS G(S(KC_5))
// Default
#define KC_TASK G(KC_TAB)
#define KC_FLXP G(KC_E)