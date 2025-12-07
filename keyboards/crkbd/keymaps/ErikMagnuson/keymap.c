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
      _WIN,
      _MAC,
      _WINFN,
      _MACFN
    };
    
    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_WIN] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.                   ,--------------------------------------------------------------.
        KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_UP,                    KC_LEFT,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------+--------|
          OSL(1), LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, KC_DOWN, KC_RIGHT,     KC_H,    RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RGUI_T(KC_QUOT), KC_RALT,
    //|--------+--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------+--------|
                                           OSL(2),   KC_SPC,  KC_TAB,                  KC_BSPC,  KC_ENT, OSL(2)
                                        //`--------------------------'                   `--------------------------'
    ),

            [_WINFN] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------------.             ,--------------------------------------------------------------.
        KC_VOLU, KC_EXLM, KC_AT, KC_LBRC, KC_RBRC, KC_BSLS, LCTL(KC_V),                  LCTL(KC_Y), KC_P7, KC_P8, KC_P9, KC_PAST, KC_SCLN, KC_MNXT,
    //|--------------------------------------------------------------------|             |--------+--------+--------+--------+--------+--------+--------|
        KC_VOLD, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_MINUS, LCTL(KC_C),                LCTL(KC_Z), KC_P4, KC_P5, KC_P6, KC_PPLS, KC_COLN, KC_MPLY,
    //|--------+--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------+--------|
        DF(2), KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_UNDS,                                       KC_P1, KC_P2, KC_P3, KC_TRNS, KC_PEQL, UG_TOGG,
    //|--------+--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TRNS,  KC_TRNS, KC_TRNS,                    KC_TRNS,  KC_P0, KC_TRNS
                                        //`--------------------------'                   `--------------------------'
    ),
    
        [_MAC] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.                   ,--------------------------------------------------------------.
        KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_UP,                    KC_LEFT,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------+--------|
        OSL(3), LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F), KC_G, KC_DOWN, KC_RIGHT,     KC_H,    RGUI_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RCTL_T(KC_QUOT), KC_RALT,
    //|--------+--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------+--------|
                                           OSL(3),   KC_SPC,  KC_TAB,                  KC_BSPC,  KC_ENT, OSL(3)
                                        //`--------------------------'                   `--------------------------'
    
    ),
                [_MACFN] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------------.             ,--------------------------------------------------------------.
        KC_VOLU, KC_EXLM, KC_AT, KC_LBRC, KC_RBRC, KC_BSLS, LGUI(KC_V),              LGUI(KC_Y), KC_P7, KC_P8, KC_P9, KC_PAST, KC_SCLN, KC_MNXT,
    //|--------------------------------------------------------------------|             |--------+--------+--------+--------+--------+--------+--------|
        KC_VOLD, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_AMPR, LGUI(KC_C),             LGUI(KC_Z), KC_P4, KC_P5, KC_P6, KC_PPLS, KC_COLN, KC_MPLY,
    //|--------+--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------+--------|
        DF(2), KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_PIPE,                                       KC_P1, KC_P2, KC_P3, KC_TRNS, KC_PEQL, UG_TOGG,
    //|--------+--------+--------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TRNS,  KC_TRNS,  KC_MINUS,                   KC_UNDS,  KC_P0, KC_TRNS
                                        //`--------------------------'                   `--------------------------'
    ),                             //`--------------------------'                   `--------------------------'
    };

    bool process_detected_host_os_user(os_variant_t detected_os) {
        
        switch (detected_os) {
            case OS_MACOS:
                set_single_persistent_default_layer(_MAC);
                break;
            default:
                set_single_persistent_default_layer(_WIN);
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