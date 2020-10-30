#include QMK_KEYBOARD_H
#include "version.h"

LEADER_EXTERNS();

enum layers {
    BASE, // default layer
    SYMB, // symbols
    PAREN,// open and close paren
    NUMPAD,
    SHIFTNUM,
    MOVEEASY,
    MOVESHIFT,
    FUNCTION,
    MOUSE,
    WINDOW,
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD,
  ST_KAK_SAV,
  ST_DBL_BQ,
  ST_PAREN,
  ST_CBR,
  ST_BRC,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_ABK,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_TABX,
  ST_SFTAB,
  ST_WINX,
  // auto close double backquote
  ST_AC_DBL_BQ,
};

/*
enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_KAK_SAV,
  ST_DBL_BQ,
  ST_PAREN,
  ST_CBR,
  ST_BRC,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_ABK,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_TABX,
  ST_SFTAB,
  ST_WINX,
  // auto close double backquote
  ST_AC_DBL_BQ,
} */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
 /*
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_LEFT,              KC_RGHT,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_DEL,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TG(SYMB),             TG(SYMB),     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_BSLS,
  KC_BSPC,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
  KC_LSFT,         CTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    ALL_T(KC_NO),                  MEH_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,           CTL_T(KC_SLSH), KC_RSFT,
  LT(SYMB,KC_GRV), KC_QUOT,     LALT(KC_LSFT), KC_LEFT, KC_RGHT,                                              KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, TT(SYMB),
                                                           ALT_T(KC_APP), KC_LGUI,                KC_LALT, CTL_T(KC_ESC),
                                                                          KC_HOME,                 KC_PGUP,
                                                         KC_SPC, KC_BSPC, KC_END,                  KC_PGDN, KC_TAB, KC_ENT
),
*/
[BASE] = LAYOUT_ergodox_pretty(
  KC_EQUAL,      KC_1,         KC_2,         KC_3,      KC_4,      KC_5,         KC_6,                          LCAG_T(KC_5),KC_6,          KC_7,      KC_8,      KC_9,        KC_0,            KC_MINUS,
  KC_TAB,        KC_Q,         KC_W,         LT(1,KC_E),KC_R,      KC_T,         LCTL(KC_LALT),                 KC_LEAD,     KC_Y,          KC_U,      LT(9,KC_I),KC_O,        KC_P,            LT(8,KC_BSLASH),
  GUI_T(KC_BSPC),CTL_T(KC_A),  LALT_T(KC_S), LT(1,KC_D),LT(2,KC_F),KC_G,                                                     KC_H,          LT(8,KC_J),LT(9,KC_K),LALT_T(KC_L),CTL_T(KC_SCOLON),GUI_T(KC_QUOTE),
  OSM(MOD_RSFT), CTL_T(KC_Z),  KC_X,         LT(1,KC_C),KC_V,      LT(3,KC_B),   KC_GRAVE,                      KC_BSLASH,   LT(5,KC_N),    KC_M,      KC_COMMA,  KC_DOT,      KC_SLASH,        OSM(MOD_RSFT),
  OSM(MOD_LGUI), OSM(MOD_LCTL),OSM(MOD_LALT),OSL(5),    OSL(4),                                                                             KC_LANG1,  OSL(7),    KC_LBRACKET, KC_RBRACKET,     OSM(MOD_LGUI),
                                                                                 KC_HOME,     KC_END,   KC_LEFT,KC_RIGHT,
                                                                                              KC_PGUP,  KC_UP,
                                                                   SFT_T(KC_SPC),LT(2,KC_DEL),KC_PGDOWN,KC_DOWN,KC_F14,      SFT_T(KC_ENTER)
),
[SYMB] = LAYOUT_ergodox_pretty(
  _______, _______,   _______, _______, _______,     _______, _______,                   _______, _______, _______, _______,  _______,  _______,   RESET,
  _______, _______,   KC_LPRN, _______, KC_TAB,      KC_LPRN, _______,                   _______, KC_RPRN, KC_PLUS, KC_PIPE,  KC_QUOTE, _______, _______,
  _______, ST_KAK_SAV,KC_LCBR, _______, KC_ESC,      KC_LCBR,                                     KC_RCBR, KC_EQUAL,KC_BSLASH,KC_DQUO,  KC_COLN, _______,
  _______, _______,   KC_LBRC, _______, LSFT(KC_TAB),KC_LABK, KC_LABK,                   KC_RABK, KC_RBRC, _______, _______,  ST_DBL_BQ,_______, _______,
  _______, _______,   _______, _______, KC_LSHIFT,                                                         _______, _______,  _______,  _______, _______,
                                                              _______, _______, _______, _______,
                                                                       _______, _______,
                                                     KC_GRAVE,KC_TILD, _______, _______, KC_UNDS, KC_MINS
),
[PAREN] = LAYOUT_ergodox_pretty(
  _______,_______,_______,_______,  _______,_______,    _______,                  _______, _______,_______,   _______,    _______,     _______,_______,
  _______,_______,_______,ST_PAREN, _______,_______,    _______,                  _______, _______,_______,   ST_MACRO_6, ST_MACRO_7,  _______,_______,
  _______,_______,KC_BSPC,ST_CBR,   _______,_______,                                       _______,ST_MACRO_9,ST_MACRO_10,ST_MACRO_11, _______,_______,
  _______,_______,_______,ST_BRC,   _______,ST_ABK,     _______,                  _______, _______,_______,   _______,    ST_AC_DBL_BQ,_______,_______,
  _______,_______,_______,_______,  _______,                                                       _______,   _______,    _______,     _______,_______,
                                                        _______,_______, _______, _______,
                                                                _______, _______,
                                            ST_MACRO_5, _______,_______, _______, _______, _______
),

// numpad
[NUMPAD] = LAYOUT_ergodox_pretty(
  _______, _______,    _______,  _______,_______,    _______, _______,                    _______, _______,      _______,_______,_______, _______, _______,
  _______, KC_HOME    ,_______,  _______,KC_END,     _______, _______,                    _______, KC_KP_PLUS,   KC_KP_7,KC_KP_8,KC_KP_9, KC_PAST, _______,
  _______, ST_MACRO_12,KC_PGDOWN,KC_PGUP,ST_MACRO_13,_______,                                      KC_KP_MINUS,  KC_KP_4,KC_KP_5,KC_KP_6, KC_PSLS, _______,
  _______, _______,    _______,  _______,_______,    _______, _______,                    _______, LT(6,KC_KP_0),KC_KP_1,KC_KP_2,KC_KP_3, KC_PDOT, _______,
  _______, _______,    _______,  _______,_______,                                                                KC_PEQL,KC_PCMM, _______, _______, _______,
                                                              _______, _______, KC_HOME,  KC_END,
                                                                       _______, KC_PGUP,
                                                     _______, _______, _______, KC_PGDOWN,KC_SPACE, _______
),

[SHIFTNUM] = LAYOUT_ergodox_pretty(
  _______,_______,_______,_______,_______,_______,_______,                   _______, _______, _______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,                   _______, _______, _______,_______,_______,_______,_______,
  _______,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,                                    KC_CIRC, KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DQUO,
  _______,_______,_______,_______,_______,_______,_______,                   _______, _______, _______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,                                                     _______,_______,_______,_______,_______,
                                                  _______, _______, _______, _______,
                                                           _______, _______,
                                         _______, _______, _______, _______, _______, _______
),

[MOVEEASY] = LAYOUT_ergodox_pretty(
  _______, _______,    _______,  _______, _______,    _______,   _______,                  _______, _______, _______, _______, _______, _______, _______,
  _______, KC_HOME,    _______,  _______, KC_END,     _______,   _______,                  _______, _______, _______, _______, _______, _______, _______,
  _______, ST_MACRO_12,KC_PGDOWN,KC_PGUP, ST_MACRO_13,_______,                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
  _______, _______,    _______,  _______, _______,    LT(6,KC_B),_______,                  _______, _______, _______, _______, _______, _______, _______,
  _______, _______,    _______,  _______, _______,                                                           _______, _______, _______, _______, _______,
                                                                 _______, _______, _______,_______,
                                                                          _______, _______,
                                                        _______, _______, _______, _______,_______, ST_MACRO_14
),


[MOVESHIFT] = LAYOUT_ergodox_pretty(
  _______, _______,      _______,       _______,     _______,     _______, _______,                   _______,_______,      _______,      _______,      _______,       _______,      _______,
  _______, LSFT(KC_HOME),_______,       _______,     LSFT(KC_END),_______, _______,                   _______,_______,      KC_PGUP,      _______,      _______,       _______,      _______,
  _______, ST_MACRO_15,  LSFT(KC_PGDN),LSFT(KC_PGUP),ST_MACRO_16, _______,                                    LSFT(KC_LEFT),LSFT(KC_DOWN),LSFT(KC_UP),  LSFT(KC_RIGHT),_______,      _______,
  _______, _______,      _______,       _______,      _______,    _______, _______,                   _______,_______,      OSM(MOD_LSFT),OSM(MOD_RGUI),OSM(MOD_RALT), OSM(MOD_RCTL),_______,
  _______, _______,      _______,       _______,      _______,                                                              _______,      _______,      _______,       _______,      _______,
                                                                           _______, _______, _______, _______,
                                                                                    _______, _______,
                                                                  _______, _______, _______, _______, _______,_______
),

  // function keys
[FUNCTION] = LAYOUT_ergodox_pretty(
  _______, KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,                   _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______,
                                                                 _______, _______,
                                               _______, _______, _______, _______, _______, _______
),

// mouse keys
[MOUSE] = LAYOUT_ergodox_pretty(
  _______, _______,    _______, _______, _______,_______, DM_RSTP,                   DM_RSTP,_______, _______, _______, _______, _______, RESET,
  _______, KC_WH_U,    KC_WH_L, KC_MS_U, KC_WH_R,_______, DM_REC1,                   DM_PLY1,_______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
  _______, KC_WH_D,    KC_MS_L, KC_MS_D, KC_MS_R,_______,                                    _______, _______, KC_ACL2, _______, _______, KC_MPLY,
  _______, KC_LCTL,    KC_LALT, KC_LGUI, KC_LSFT,_______, DM_REC2,                   DM_PLY2,_______, _______, _______, _______, _______, _______,
  _______, WEBUSB_PAIR,_______, _______, KC_BTN3,                                                     KC_BTN3, _______, _______, _______, _______,
                                                          _______, _______, _______, _______,
                                                                   _______, _______,
                                               KC_MS_BTN1,KC_LSFT, _______, _______, _______,KC_BTN2
),

// web browsing
[WINDOW] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______,     _______,      _______,
  _______, _______, _______, _______, _______, _______, _______,                                 _______, ST_WINX, KC_LCTL, _______, LSFT(KC_ESC),LSFT(KC_TAB), _______,
  _______, _______, _______, _______, _______, _______,                                                   ST_TABX, KC_LALT, _______, KC_ESC,      KC_TAB,       _______,
  _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, KC_LCTL, _______, _______,     KC_ESCAPE,    _______,
  _______, _______, _______, _______, _______,                                                                     _______, _______, _______,     _______,      _______,
                                                        _______, _______, _______, _______,
                                                                 _______, _______,
                                        LALT(KC_LEFT),  _______, _______, _______, _______, LALT(KC_RIGHT)
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif

      case ST_KAK_SAV:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_A))));

        }
        return false;
      case ST_DBL_BQ:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_GRAVE));

        }
        return false;
      case ST_PAREN:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(100) SS_LSFT(SS_TAP(X_0)) SS_DELAY(100) SS_TAP(X_LEFT));

        }
        return false;
      case ST_CBR:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(100) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(100) SS_TAP(X_LEFT));

        }
        return false;
      case ST_BRC:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_5:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_6:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_BSLASH)) SS_DELAY(100) SS_LSFT(SS_TAP(X_BSLASH)) SS_DELAY(100) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_7:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_LEFT));

        }
        return false;
      case ST_ABK:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_9:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_GRAVE));

        }
        return false;
      case ST_MACRO_10:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_11:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_TAP(X_LEFT));

        }
        return false;
      case ST_AC_DBL_BQ:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_12:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));

        }
        return false;
      case ST_MACRO_13:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));

        }
        return false;
      case ST_MACRO_14:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_TAP(X_BSLASH)));

        }
        return false;
      case ST_MACRO_15:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));

        }
        return false;
      case ST_MACRO_16:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))));

        }
        return false;
      case ST_TABX:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_TAP(X_F4)));

        }
        return false;
      case ST_SFTAB:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_TAB)));

        }
        return false;
      case ST_WINX:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_TAP(X_F4)));

        }
        return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_LGUI(SS_TAP(X_F)))));
    }
    SEQ_ONE_KEY(KC_T) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_LGUI(SS_TAP(X_T)))));
    }
    SEQ_ONE_KEY(KC_S) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_LGUI(SS_TAP(X_L)))));
    }
    SEQ_TWO_KEYS(KC_S, KC_T) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_LGUI(SS_TAP(X_S)))));
    }
    SEQ_ONE_KEY(KC_M) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_LGUI(SS_TAP(X_M)))));
    }
    SEQ_ONE_KEY(KC_D) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_LGUI(SS_TAP(X_D)))));
    }
    SEQ_TWO_KEYS(KC_O, KC_S) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_LGUI(SS_TAP(X_O)))));
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}
