/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    WIN,
    MAC,
    NUM,
    SYM,
    NAV,
    FN,
};

enum custom_keycodes {
    // toggle between mac and windows default layers
    SW_OS = SAFE_RANGE, // Define the custom keycode safely
};

// clang-format off
#define LAYOUT_LR( \
    l00, l01, l02, l03, l04, l05, l06, \
    l10, l11, l12, l13, l14, l15, l16, \
    l20, l21, l22, l23, l24, l25,      \
                        l30, l31, l32, \
                                       \
              r00, r01, r02, r03, r04, r05, r06, \
              r10, r11, r12, r13, r14, r15, r16, \
                   r20, r21, r22, r23, r24, r25, \
              r30, r31, r32                       \
) \
LAYOUT_split_3x6_3_ex2( \
    l00, l01, l02, l03, l04, l05, l06, \
    r00, r01, r02, r03, r04, r05, r06, \
    l10, l11, l12, l13, l14, l15, l16, \
    r10, r11, r12, r13, r14, r15, r16, \
    l20, l21, l22, l23, l24, l25,      \
    r20, r21, r22, r23, r24, r25,      \
    l30, l31, l32,                      \
    r30, r31, r32                       \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAC] = LAYOUT_LR(
    KC_ESC  , KC_Q        , KC_W        , KC_E        , KC_R        , KC_T   , G(KC_V),
    OSL(NUM), LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F), KC_G   , G(KC_C),
    OSL(FN) , KC_Z        , KC_X        , KC_C        , KC_V        , KC_B   ,
                                               OSL(SYM), KC_SPC , KC_TAB ,

              SELLINE, KC_Y        , KC_U        , KC_I        , KC_O        , KC_P        , KC_DEL ,
              SELWBAK, KC_H        , RGUI_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RCTL_T(KC_QUOT), OSL(NAV),
                       KC_N        , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH     , CW_TOGG,
              KC_BSPC, KC_ENT , OSL(SYM)
  ),

  [WIN] = LAYOUT_LR(
    KC_ESC  , KC_Q        , KC_W        , KC_E        , KC_R        , KC_T   , C(KC_V),
    OSL(NUM), LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G   , C(KC_C),
    OSL(FN) , KC_Z        , KC_X        , KC_C        , KC_V        , KC_B   ,
                                               OSL(SYM), KC_SPC , KC_TAB ,

              SELLINE, KC_Y   , KC_U        , KC_I        , KC_O        , KC_P        , KC_DEL ,
              SELWBAK, KC_H  , RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RGUI_T(KC_QUOT), OSL(NAV),
                       KC_N   , KC_M        , KC_COMM     , KC_DOT      , KC_SLSH     , CW_TOGG,
              KC_BSPC, KC_ENT , OSL(SYM)
  ),

  [SYM] = LAYOUT_LR(
    _______, KC_GRV , KC_TILD, KC_HASH, KC_AMPR, KC_PIPE, KC_VOLU,
    _______, KC_EXLM, KC_UNDS, KC_COLN, KC_EQL , KC_DLR , KC_VOLD,
    _______, KC_PERC, KC_QUES, KC_ASTR, KC_PLUS, KC_BSLS,
                                        _______, _______, _______,

              KC_MNXT, KC_CIRC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, SW_OS  ,
              KC_MPLY, KC_AT  , KC_LPRN, KC_RPRN, KC_COLN, KC_SCLN, _______,
                       KC_SLSH, KC_MINS, KC_LT  , KC_GT  , _______, UG_TOGG,
              _______, _______, _______
  ),

  [NAV] = LAYOUT_LR(
    _______, KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_PGDN, _______,
    _______, SELWBAK, KC_LEFT, KC_DOWN, KC_RGHT, SELWORD, _______,
    _______, _______, RCTL(KC_LEFT), _______, RCTL(KC_RIGHT), _______,
                                        _______, _______, _______,

              _______, _______, _______, _______, _______, _______, _______,
              _______, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______, _______,
                       _______, _______, _______, _______, _______, _______,
              _______, _______, _______
  ),

  [NUM] = LAYOUT_LR(
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______, _______,
    _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______,

              _______, KC_7   , KC_8   , KC_9   , KC_ASTR, _______, _______,
              _______, KC_4   , KC_5   , KC_6   , KC_PLUS, _______, _______,
                       KC_1   , KC_2   , KC_3   , KC_DOT , _______, _______,
              _______, KC_0   , _______
  ),

  [FN] = LAYOUT_LR(
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______, _______,
    _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______,

              _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, _______,
              _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______, _______,
                       KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______, _______,
              _______, _______, _______
  ),
};
// clang-format on

// set default layer based on os
bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
            default_layer_set(1UL << MAC);
            break;
        default:
            default_layer_set(1UL << WIN);
            break;
    }

    return true;
}

// define button to toggle between windows and mac default layers
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SW_OS:
            if (record->event.pressed) {
                // Check if the current default layer is Windows
                if (get_highest_layer(default_layer_state) == WIN) {
                    // If WIN, switch to MAC
                    default_layer_set(1UL << MAC);
                } else {
                    // Otherwise (if MAC or undefined), switch to WIN
                    default_layer_set(1UL << WIN);
                }
            };
            return false; // Skip standard processing for this key

            // ... handle other custom keycodes here ...
    }
    return true; // Process all other keys normally
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // 1. Force the background to black
    // This loops through the CURRENT batch of LEDs (led_min to led_max)
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 0, 0, 0);
    }

    // Define your target LED
    uint8_t indicator_led = 41;

    if (indicator_led >= led_min && indicator_led < led_max) {
        if (default_layer_state & (1UL << MAC)) {
            rgb_matrix_set_color(indicator_led, 50, 0, 0); // Red
        } else if (default_layer_state & (1UL << WIN)) {
            rgb_matrix_set_color(indicator_led, 0, 0, 50); // Blue
        } else {
            rgb_matrix_set_color(indicator_led, 0, 0, 0); // none
        }
    }

    // 4. Return false to allow other standard indicators (like Caps Lock) to work on top if needed
    return false;
}