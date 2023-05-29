# Build Options
#   change yes to no to disable
#
MOUSEKEY_ENABLE = no        # Mouse keys
NKRO_ENABLE = yes           # Enable N-Key Rollover

# Personal Configuration Settings

VIA_ENABLE = yes
TAP_DANCE_ENABLE = yes

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_user.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dance_user.c
    SRC += tap_dance_setup.c
    SRC += tap_dance_feats.c
endif