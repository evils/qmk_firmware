#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ 1 │ 2 │ 3 │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┤
     * │ 7 │ 8 │ 9 │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x3(
        KC_VOLD,   KC_MUTE,   KC_VOLU,
        KC_LEFT,   KC_MPLY,   KC_RGHT,
        KC_PSCR,   KC_INS,   MO(1)
    ),
    [1] = LAYOUT_ortho_3x3(
        QK_BOOT,   DB_TOGG,   MAGIC_TOGGLE_NKRO,
        EE_CLR,   KC_UP,   RGB_TOG,
        MO(2),   KC_DOWN,   KC_TRNS
    ),
    [2] = LAYOUT_ortho_3x3(
        KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   MO(3)
    ),
    [3] = LAYOUT_ortho_3x3(
        KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS
    )
};
