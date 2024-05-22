#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NAV,
    _NUMBERS,
    _FUN,
    _MEDIA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x6_5(
        KC_TRNS,    KC_Q,                KC_W,                  KC_E,                    KC_R,                   KC_T,                              KC_Y,       KC_U,                    KC_I,                  KC_O,                KC_P,                         KC_TRNS,
        KC_TRNS,    MT(MOD_LGUI, KC_A),  MT(MOD_LALT, KC_S),    MT(MOD_LCTL, KC_D),      MT(MOD_LSFT, KC_F),     KC_G,                              KC_H,       MT(MOD_LSFT, KC_J),      MT(MOD_LCTL, KC_K),    MT(MOD_LALT, KC_L),  MT(MOD_LGUI, KC_QUOTE),       KC_TRNS,
        KC_TRNS,    KC_Z,                KC_X,                  KC_C,                    KC_V,                   KC_B,                              KC_N,       KC_M,                    KC_COMM,               KC_DOT,              KC_SLASH,                     KC_TRNS,
                    KC_CAPS,             LT(_MEDIA, KC_ESC),    LT(_NAV, KC_SPC),        LT(KC_TRNS, KC_ENT),    KC_F18,                            KC_F19,     LT(_FUN, KC_TAB),        LT(_NUMBERS, KC_BSPC), KC_DEL,              KC_RGUI
    ),

    [_NAV] = LAYOUT_split_3x6_5(
        KC_TRNS,    KC_INS,      LCTL(KC_X),    LCTL(KC_C), LCTL(KC_V),  LCTL(KC_Z),              KC_TRNS,    KC_TRNS,        KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_LEFT,     KC_DOWN,       KC_UP,      KC_RIGHT,    LCTL(KC_Y),              KC_TRNS,    KC_LSFT,        KC_LCTL,       KC_LALT,     KC_RGUI,    KC_TRNS,
        KC_TRNS,    KC_HOME,     KC_PGDN,       KC_PGUP,    KC_END,      KC_CAPS,                 KC_TRNS,    KC_TRNS,        KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,
                    KC_TRNS,     KC_TRNS,       KC_TRNS,    KC_TRNS,     KC_TRNS,                 KC_TRNS,    KC_TRNS,        KC_TRNS,       KC_TRNS,     KC_TRNS
    ),

    [_NUMBERS] = LAYOUT_split_3x6_5(
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_LBRC,     KC_1,        KC_2,       KC_3,     KC_RBRC,       KC_TRNS,
        KC_TRNS,    KC_RGUI,  KC_LALT,  KC_LCTL,    KC_LSFT,   KC_TRNS,                  KC_SEMICOLON,KC_4,        KC_5,       KC_6,     KC_EQL,        KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_GRAVE,    KC_7,        KC_8,       KC_9,     KC_BACKSLASH,  KC_TRNS,

                    KC_TRNS,  KC_DOT,   KC_0,       KC_MINS,   KC_TRNS,                  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,  KC_TRNS
    ),
    
    [_FUN] = LAYOUT_split_3x6_5(
        KC_TRNS,    KC_TRNS,  KC_PGUP,  KC_UP,      KC_PGDN,  KC_TRNS,                  KC_TRNS,      KC_F1,    KC_F2,      KC_F3,    KC_F10,  KC_TRNS,
        KC_TRNS,    KC_RGUI,  KC_LALT,  KC_LCTL,    KC_LSFT,  KC_TRNS,                  KC_TRNS,      KC_F4,    KC_F5,      KC_F6,    KC_F11,  KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_HOME,  KC_TRNS,    KC_END,   KC_TRNS,                  KC_TRNS,      KC_F7,    KC_F8,      KC_F9,    KC_F12,  KC_TRNS,

                    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS
    ),
    
    [_MEDIA] = LAYOUT_split_3x6_5(
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,    KC_TRNS,              KC_TRNS,                KC_TRNS,           KC_TRNS,                KC_TRNS,
        KC_TRNS,    KC_RGUI,  KC_LALT,  KC_LCTL,    KC_LSFT,   KC_TRNS,                  KC_TRNS,    KC_MEDIA_PREV_TRACK,  KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,   KC_MEDIA_NEXT_TRACK,    KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,    KC_TRNS,              KC_TRNS,                KC_TRNS,           KC_TRNS,                KC_TRNS,

                    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,    KC_MEDIA_STOP,        KC_MEDIA_PLAY_PAUSE,    KC_AUDIO_MUTE,     KC_TRNS
    ),
};

layer_state_t layer_state_set_user(layer_state_t state)
{
    /*state = update_tri_layer_state(state, _NAV, _RAISE, _FUN);

    int16_t layer = _BASE;

    if (IS_LAYER_ON_STATE(state, _NAV))
    {
        layer = _NAV;
    }
    else if (IS_LAYER_ON_STATE(state, _RAISE))
    {
        layer = _RAISE;
    }
    else if (IS_LAYER_ON_STATE(state, _FUN))
    {
        layer = _FUN;
    }

    tap_code16(KC_F13 + layer); send input that layer has been changed with F13 + layer */

    return state;
}
