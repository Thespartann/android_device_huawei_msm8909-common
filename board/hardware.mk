# Lights
TARGET_PROVIDES_LIBLIGHT := true

# CMHW
BOARD_USES_CYANOGEN_HARDWARE := true
BOARD_HARDWARE_CLASS += \
    hardware/cyanogen/cmhw \
    $(VENDOR_PATH)/cmhw
TARGET_TAP_TO_WAKE_NODE := "/sys/touch_screen/easy_wakeup_gesture"

