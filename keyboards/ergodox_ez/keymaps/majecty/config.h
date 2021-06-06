#ifndef majecty_config_h_INCLUDED
#define majecty_config_h_INCLUDED
/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 250

#define FIRMWARE_VERSION u8"zbVpd/aqxzD"
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

#define COMBO_VARIABLE_LEN
#define COMBO_TERM 20

// #undef MK_COMBINED
#define MK_COMBINED
// #define MK_C_OFFSET_2 64

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 15
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 100

#define MOUSEKEY_WHEEL_INTERVAL 100
#define MOUSEKEY_WHEEL_MAX_SPEED 80
#define MOUSEKEY_WHEEL_TIME_TO_MAX 10

#endif // keyboards/ergodox_ez/keymaps/majecty/config_h_INCLUDED

