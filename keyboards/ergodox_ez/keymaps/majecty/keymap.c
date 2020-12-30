#include QMK_KEYBOARD_H

#define AAA KC_HOME
#define AAS KC_PGDN
#define AAE KC_PGUP
#define AAT KC_END
#define AAN KC_LEFT
#define AAI KC_DOWN
#define AAO KC_UP
#define AAP KC_RIGHT

// #include "g/config_default.h"
// #include "g/engine.h"
// #include "g/keymap_engine.h"
#include "g/keymap_combo.h"
#include "version.h"

LEADER_EXTERNS();

enum layers {
    BASE, // default layer
    SYMB, // symbols
    PAREN,// open and close paren
    NUMPAD,
    MOVEEASY,

    MOUSE,
    ASETNIOP,
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
  ST_HASET,
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
  KC_EQUAL,      KC_1,         KC_2,         KC_3,      KC_4,      KC_5,         KC_6,                          LCAG_T(KC_5),KC_6,          KC_7,      KC_8,     KC_9,        KC_0,            KC_MINUS,
  KC_TAB,        KC_Q,         KC_W,         KC_E,      KC_R,      KC_T,         LCTL(KC_LALT),                 KC_LEAD,     KC_Y,          KC_U,      KC_I,     KC_O,        KC_P,            LT(5,KC_BSLASH),
  TG(ASETNIOP),  CTL_T(KC_A),  LALT_T(KC_S), LT(1,KC_D),LT(2,KC_F),KC_G,                                                     KC_H,          LT(5,KC_J),KC_K,     LALT_T(KC_L),CTL_T(KC_SCOLON),GUI_T(KC_QUOTE),
  OSM(MOD_RSFT), CTL_T(KC_Z),  KC_X,         KC_C,      KC_V,      LT(3,KC_B),   KC_GRAVE,                      KC_BSLASH,   LT(4,KC_N),    KC_M,      KC_COMMA, KC_DOT,      KC_SLASH,        OSM(MOD_RSFT),
  OSM(MOD_LGUI), OSM(MOD_LCTL),OSM(MOD_LALT),KC_LEFT,   OSL(MOUSE),                                                                         KC_LANG1,  KC_DOWN,  KC_LBRACKET, KC_RBRACKET,     OSM(MOD_LGUI),
                                                                                 KC_HOME,     KC_END,   KC_LEFT,KC_RIGHT,
                                                                                              KC_PGUP,  KC_UP,
                                                                   SFT_T(KC_SPC),GUI_T(KC_DEL),KC_PGDOWN,KC_DOWN,KC_F14,      SFT_T(KC_ENTER)
),
[SYMB] = LAYOUT_ergodox_pretty(
  _______, _______,   _______, _______, _______,  _______,      _______,                   _______, _______,  _______, _______,  _______,  _______,  RESET,
  _______, KC_LCBR,   KC_RCBR, _______, KC_TAB,   LSFT(KC_TAB), _______,                   _______, ST_DBL_BQ,KC_EXLM, KC_AT,   KC_QUOTE, KC_PIPE, _______,
  _______, KC_LPRN,   KC_RPRN, _______, KC_ESC,   LSFT(KC_ESC),                                     KC_AMPR,  KC_HASH, KC_DLR,  KC_DQUO,  KC_BSLS, _______,
  _______, KC_LBRC,   KC_RBRC, _______, KC_COLN,  _______,      _______,                   _______, KC_ASTR,  KC_PERC, KC_CIRC, KC_PLUS,  KC_EQUAL,_______,
  _______, _______,   _______, _______, _______,                                                              _______, _______,  _______, _______, _______,
                                                                _______, _______, _______, _______,
                                                                         _______, _______,
                                                       KC_GRAVE,KC_TILD, _______, _______, KC_UNDS, KC_MINS
),
[PAREN] = LAYOUT_ergodox_pretty(
  _______,_______,_______,_______,   _______,_______,_______,                 _______, _______,      _______,_______,_______,       _______,_______,
  _______,KC_HOME,KC_END,ST_KAK_SAV, _______,_______,_______,                 _______, _______,      _______,_______,_______,       _______,_______,
  _______,KC_LABK,KC_RABK,KC_BSPC,   _______,_______,                                  LALT(KC_LEFT),_______,_______,LALT(KC_RIGHT),_______,_______,
  _______,KC_PGUP,KC_PGDN,_______,   _______,_______,_______,                 _______, _______,      _______,_______,_______,       _______,_______,
  _______,_______,_______,_______,   _______,                                                        _______,_______,_______,       _______,_______,
                                                   _______,_______, _______,_______,
                                                           _______, _______,
                                          _______, _______,_______, _______, _______, _______
),

// numpad
[NUMPAD] = LAYOUT_ergodox_pretty(
  _______, _______,_______,  _______,_______, _______, _______,                    _______, _______, _______,_______,_______, _______, _______,
  _______, KC_1,   KC_2,     KC_3,   KC_4,    KC_5,    _______,                    _______, KC_6,    KC_7,   KC_8,   KC_9,    KC_0,    _______,
  _______, KC_F1,  KC_F2,    KC_F3,  KC_F4,   KC_F5,                                        KC_F6,   KC_F7,  KC_F8,  KC_F9,   KC_F10,  _______,
  _______, KC_F11, KC_F12,   KC_F13, KC_F14,  _______, _______,                    _______, KC_LEFT, KC_DOWN,KC_UP,  KC_RIGHT,_______, _______,
  _______, _______,_______,  _______,_______,                                                        _______,_______,_______, _______, _______,
                                                       _______, _______, KC_HOME,  KC_END,
                                                                _______, KC_PGUP,
                                              _______, _______, _______, KC_PGDOWN,KC_SPACE, _______
),

[MOVEEASY] = LAYOUT_ergodox_pretty(
  _______, _______,    _______,  _______, _______,    _______,   _______,                  _______, _______, _______, _______, _______, _______, _______,
  _______, KC_HOME,    _______,  _______, KC_END,     _______,   _______,                  _______, _______, _______, _______, _______, _______, _______,
  _______, ST_MACRO_12,KC_PGDOWN,KC_PGUP, ST_MACRO_13,_______,                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
  _______, _______,    _______,  _______, _______,    _______,   _______,                  _______, _______, _______, _______, _______, _______, _______,
  _______, _______,    _______,  _______, _______,                                                           _______, _______, _______, _______, _______,
                                                                 _______, _______, _______,_______,
                                                                          _______, _______,
                                                        _______, _______, _______, _______,_______, ST_MACRO_14
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

[ASETNIOP] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______,_______,_______,_______,_______,_______,                         _______, _______, _______, _______, _______, _______, _______,
  _______, _______,_______,_______,_______,_______,_______,                         _______, _______, _______, _______, _______, _______, _______,
  _______, KC_A,   KC_S,   KC_E,   KC_T,   ST_HASET,                                         _______,    KC_N,    KC_I,    KC_O,    KC_P, _______,
  _______, AAA,    AAS,    AAE,    AAT,    _______,_______,                         _______, _______,     AAN,     AAI,     AAO,     AAP, _______,
  _______, _______,_______,_______,KC_LCTL,                                                           KC_LALT,KC_LANG1, _______, _______, _______,
                                                   _______,       _______, _______, _______,
                                                                  _______, _______,
                                     SFT_T(KC_SPC),GUI_T(KC_DEL), _______, _______, _______,SFT_T(KC_ENT)
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
          SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_GRAVE));

        }
        return false;
      case ST_PAREN:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_9)) SS_DELAY(10) SS_LSFT(SS_TAP(X_0)) SS_DELAY(10) SS_TAP(X_LEFT));

        }
        return false;
      case ST_CBR:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(10) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(10) SS_TAP(X_LEFT));

        }
        return false;
      case ST_BRC:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(10) SS_TAP(X_RBRACKET) SS_DELAY(10) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_5:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_6:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_BSLASH)) SS_DELAY(10) SS_LSFT(SS_TAP(X_BSLASH)) SS_DELAY(10) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_7:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(10) SS_TAP(X_QUOTE) SS_DELAY(10) SS_TAP(X_LEFT));

        }
        return false;
      case ST_ABK:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(10) SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(10) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_9:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_GRAVE));

        }
        return false;
      case ST_MACRO_10:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_LEFT));

        }
        return false;
      case ST_MACRO_11:
        if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(10) SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(10) SS_TAP(X_LEFT));

        }
        return false;
      case ST_AC_DBL_BQ:
        if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_GRAVE) SS_DELAY(10) SS_TAP(X_LEFT));

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
      case ST_HASET:
        if (record->event.pressed) {
          SEND_STRING("asetniop");
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
