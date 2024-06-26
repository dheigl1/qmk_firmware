#include QMK_KEYBOARD_H


enum sofle_layers {
    _BASE,
    _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | 1    |   2  |   3  |   4  |   5  |   6  |                    |   7  |   8  |   9  |   0  |   ß  |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  | +    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   #  |ENTER |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LSTRG | LALT | LOS | ENTER| / SPACE /       \ SPACE\  | BSPC | ROS | RALT  | RSTRG |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_BASE] = LAYOUT(
  KC_1,     KC_2,  KC_3,  KC_4,  KC_5,  KC_6,                    KC_7,  KC_8,  KC_9,     KC_0,    KC_MINS,  KC_EQL,
  KC_ESC,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                    KC_Z,  KC_U,  KC_I,     KC_O,    KC_P,     KC_RBRC,
  KC_TAB,   KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                    KC_H,  KC_J,  KC_K,     KC_L,    KC_BSLS,  KC_ENT,
  KC_LSFT,  KC_Y,  KC_X,  KC_C,  KC_V,  KC_B, KC_MUTE,  KC_MUTE, KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
  KC_LCTL,  KC_LALT,  KC_LGUI, KC_ENT, LT(1, KC_SPC),            LT(1, KC_SPC), KC_BSPC, KC_RGUI, KC_RALT, KC_RCTL
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * | F1   | F2   | F3   | F4   | F5   | F6   |                    | F7   | F8   | F9   | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  Ö   |      |  Ü   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ä    |      |      |      |      |-------.    ,-------| LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      | ><   |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_SCLN, KC_TRNS, KC_LBRC, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_QUOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x07, 0xff, 0xff, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x1f, 0xff, 0xff, 0xc0, 0xf8, 0x00, 0x00, 0x10, 0x78, 0x00, 0x00, 0x00, 0x0f, 0x1e, 0x38,
        0x00, 0x7f, 0xfc, 0x0f, 0xc0, 0xfe, 0x00, 0x00, 0x10, 0x44, 0x44, 0x20, 0xc0, 0x10, 0x10, 0x26,
        0x01, 0xff, 0xf8, 0x0f, 0xc0, 0xff, 0x00, 0x00, 0x38, 0x40, 0x44, 0x30, 0x60, 0x20, 0x10, 0x22,
        0x03, 0xff, 0xf0, 0x0f, 0xc0, 0xff, 0x80, 0x00, 0x28, 0x42, 0x40, 0x50, 0x10, 0x20, 0x10, 0x21,
        0x07, 0xff, 0xe0, 0x0f, 0xc0, 0xff, 0xc0, 0x00, 0x00, 0x42, 0x28, 0x48, 0x10, 0x20, 0x18, 0x21,
        0x0f, 0xff, 0xc0, 0x0f, 0xc0, 0xff, 0xe0, 0x00, 0x44, 0x42, 0x28, 0x08, 0x08, 0x20, 0x10, 0x21,
        0x1f, 0xff, 0x80, 0x0f, 0xc0, 0xff, 0xf0, 0x00, 0x44, 0x44, 0x10, 0x80, 0x06, 0x20, 0x10, 0x22,
        0x3f, 0xff, 0x00, 0x0f, 0xc0, 0xff, 0xf8, 0x00, 0x00, 0x44, 0x10, 0x84, 0x82, 0x10, 0x10, 0x26,
        0x3f, 0xfe, 0x00, 0x0f, 0xc0, 0xff, 0xf8, 0x00, 0x82, 0x78, 0x10, 0x04, 0x00, 0x0f, 0x1e, 0x38,
        0x7f, 0xfc, 0x00, 0x0f, 0xc0, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x7f, 0xf8, 0x00, 0x0f, 0xc0, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x7f, 0xf0, 0x04, 0x0f, 0xc0, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x7f, 0xf0, 0x0c, 0x0f, 0xc0, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x7f, 0xe0, 0x1c, 0x0f, 0xc0, 0xff, 0xfc, 0x00, 0xc3, 0x0c, 0x18, 0x61, 0xf1, 0xc7, 0x7e, 0x3e,
        0x3f, 0xc0, 0x3c, 0x0f, 0xc0, 0xff, 0xf8, 0x00, 0xe3, 0x0e, 0x18, 0x61, 0xf8, 0xe6, 0x7f, 0x3e,
        0x3f, 0x80, 0x7c, 0x0f, 0xc0, 0xff, 0xf8, 0x00, 0xe3, 0x0f, 0x18, 0x61, 0x98, 0xee, 0x1c, 0x38,
        0x3f, 0x00, 0xfc, 0x0f, 0xc0, 0xff, 0xf8, 0x00, 0xe3, 0x0f, 0x18, 0x61, 0x98, 0x7c, 0x1c, 0x30,
        0x1e, 0x01, 0xfc, 0x00, 0x00, 0xff, 0xf0, 0x00, 0xe3, 0x0f, 0x98, 0x61, 0xf8, 0x38, 0x1c, 0x3e,
        0x0c, 0x01, 0xfe, 0x00, 0x01, 0xff, 0xe0, 0x00, 0xe3, 0x0d, 0xd8, 0x61, 0xf8, 0x38, 0x1c, 0x3e,
        0x00, 0x03, 0xfe, 0x00, 0x01, 0xff, 0xc0, 0x00, 0xe3, 0x0c, 0xf8, 0x61, 0x9c, 0x38, 0x1c, 0x3e,
        0x00, 0x07, 0xff, 0x00, 0x03, 0xff, 0x80, 0x00, 0xe3, 0x0c, 0xf8, 0x61, 0x8c, 0x38, 0x1c, 0x30,
        0x00, 0x0f, 0xff, 0x80, 0x07, 0xff, 0x00, 0x00, 0xe7, 0x0c, 0x78, 0x61, 0x9c, 0x38, 0x1c, 0x38,
        0x00, 0x1f, 0xff, 0xc0, 0x0f, 0xfc, 0x00, 0x00, 0x7f, 0x0c, 0x38, 0x61, 0xfc, 0x38, 0x1c, 0x3e,
        0x00, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x3e, 0x0c, 0x18, 0x61, 0xf8, 0x38, 0x18, 0x3e,
        0x00, 0x0f, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) {
    oled_write_P(PSTR("DH1"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code16(G(KC_MINS));
        } else {
            tap_code16(G(KC_EQL));
        }
    }
    return true;
}

#endif
