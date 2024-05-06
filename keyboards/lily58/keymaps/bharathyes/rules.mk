LTO_ENABLE = yes            # Link Time Optimization enabled
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_ENABLE = no            # OLED display
KEY_OVERRIDE_ENABLE = yes       # alters the keycode sent for certain combos
# AUTO_SHIFT_ENABLE = nyes      # get upper case on holding a key longer
CAPS_WORD_ENABLE = yes          # caps till whitespace character
# DYNAMIC_TAPPING_TERM_ENABLE = yes       # enable tab hold dynamic config
MOUSEKEY_ENABLE = yes       # mouse actions
LEADER_ENABLE = yes
UNICODE_COMMON = no
UNICODEMAP_ENABLE = no
TRI_LAYER_ENABLE = yes      # lower + raise gives adjust layer ( tri-layer )
DYNAMIC_MACRO_ENABLE = yes  # dynamic recorded macros (temp, resets on reboot)

# If you want to change the display of OLED, you need to change here
# SRC +=  ./lib/rgb_state_reader.c \
#         ./lib/layer_state_reader.c \
#         ./lib/logo_reader.c \
#         ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
