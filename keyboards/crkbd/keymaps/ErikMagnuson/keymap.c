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
      SYM
    };
    
    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [MAC] = LAYOUT_split_3x6_3_ex2(
          KC_ESC,           KC_Q,         KC_W,         KC_E,         KC_R, KC_T, G(KC_V),       KC_LEFT,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_DEL,
          OSL(NUM), LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F), KC_G, G(KC_C),      KC_RIGHT,    KC_H,    RGUI_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RCTL_T(KC_QUOT), OSL(NUM),
          KC_LSFT,          KC_Z,         KC_X,         KC_C,         KC_V, KC_B,                                                        KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                                                OSL(SYM),   KC_SPC,  KC_TAB,                    KC_BSPC,  KC_ENT, OSL(SYM)           
        ),

        [WIN] = LAYOUT_split_3x6_3_ex2(
          KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, C(KC_V),                                        KC_LEFT,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_DEL,
          OSL(NUM), LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, C(KC_C),      KC_RIGHT,   KC_H,    RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RGUI_T(KC_QUOT), OSL(NUM),
          KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                                            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                                                OSL(SYM),   KC_SPC,  KC_TAB,                    KC_BSPC,  KC_ENT, OSL(SYM)
        ),

        [SYM] = LAYOUT_split_3x6_3_ex2(
            _______, KC_GRV , KC_TILD, KC_HASH, KC_AMPR, KC_PIPE, _______,                      _______, KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR , _______, _______,
            _______, KC_EXLM, KC_UNDS, KC_COLN, KC_EQL, KC_DLR, _______,                        _______, KC_AT, KC_LPRN, KC_RPRN, KC_COLN, KC_SCLN, _______,
            _______, KC_PERC, KC_QUES, KC_ASTR, KC_PLUS, KC_BSLS,                                        KC_SLSH, KC_LBRC, KC_RBRC, _______, _______, _______,
                                                _______, _______, _______,                      _______, _______, _______ 
        ),

        [NUM] = LAYOUT_split_3x6_3_ex2(
            _______, _______,_______,_______,_______,_______,_______,                          _______, _______, KC_7, KC_8, KC_9, KC_ASTR, _______, 
            _______, _______,_______,_______,_______,_______,_______,                          _______, _______, KC_4, KC_5, KC_6, KC_PLUS,_______, 
            _______, _______,_______,_______,_______,_______,                                           _______, KC_1, KC_2, KC_3, KC_DOT, _______, 
                                                    _______, _______, _______,                 _______, KC_0, _______ 
        ),
    };

    bool process_detected_host_os_user(os_variant_t detected_os) {
        
        switch (detected_os) {
            case OS_MACOS:
                default_layer_set(MAC);
                break;
            default:
                default_layer_set(WIN);
                break;
        }

        return true;
    }
    
    #ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
        [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
        [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
        [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    };
    #endif