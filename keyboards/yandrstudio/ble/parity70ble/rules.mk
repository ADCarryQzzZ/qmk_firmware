# Build Options
BOOTMAGIC_ENABLE = yes     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
COMMAND_ENABLE = yes         # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover

CUSTOM_MATRIX = lite
QUANTUM_SRC += matrix_io.c 74hc595_io.c

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = st7735s_spi
QUANTUM_PAINTER_ANIMATIONS_ENABLE = yes

FLASH_DRIVER = spi

VPATH += $(KEYBOARD_PATH_2)/giftools/gifs/generated
SRC += mxrskey.qgf.c

RGBLIGHT_ENABLE = yes
RGBLIGHT_DRIVER = WS2812

# DEBOUNCE_TYPE = sym_eager_pk

# CONSOLE_ENABLE = yes         # Console for debug
# KEYBOARD_SHARED_EP = yes    # Free up some extra endpoints - needed if console+mouse+extra


# OPT_DEFS += -DFACTORY_TEST
