# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
# LINK_TIME_OPTIMIZATION_ENABLE = yes
LTO_ENABLE = yes
COMMAND_ENABLE = no
WEBUSB_ENABLE = yes
ORYX_ENABLE = yes
ORYX_CONFIGURATOR = yes
DYNAMIC_MACRO_ENABLE = yes
LEADER_ENABLE = yes

VPATH  +=  keyboards/gboards/
# SRC                 +=  g/engine.c
COMBO_ENABLE=yes
