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
        KC_PSCR,   KC_INS,    MO(1)
    ),
    [1] = LAYOUT_ortho_3x3(
        QK_BOOT,   DB_TOGG,   MAGIC_TOGGLE_NKRO,
        RGB_MOD,   RGB_TOG,   RGB_RMOD,
        MO(2),     EE_CLR,    KC_TRNS
    )
};
