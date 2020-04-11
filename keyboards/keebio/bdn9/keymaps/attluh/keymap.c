/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |     |        |
        | Press: Mute       | 6   | 7      |
        | 8                 | 9   | 0      |
        | Hold: Layer 2     | Min | Equals |
     */
    [0] = LAYOUT(
        KC_MUTE, KC_6   , KC_7,
        KC_8   , KC_9   , KC_0,
        MO(1)  , KC_MINS, KC_EQL
    ),
    /*
        | Press: Reset | [          | ]    |
        | Prev         | Play/Pause | Next |
        |              | KP *       | KP / |
     */
    [1] = LAYOUT(
        RESET  , KC_LBRC, KC_RBRC,
        KC_MPRV, KC_MPLY, KC_MNXT,
        _______, BL_TOGG, BL_STEP
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
