# Init scripts
PRODUCT_PACKAGES += \
    init.qcom.usb.rc

# USB ID
PRODUCT_PROPERTY_OVERRIDES += \
    ro.usb.id.midi=90BA \
    ro.usb.id.midi_adb=90BB \
    ro.usb.id.mtp=1051 \
    ro.usb.id.mtp_adb=1052 \
    ro.usb.id.ptp=1083 \
    ro.usb.id.ptp_adb=1054 \
    ro.usb.id.ums=1037 \
    ro.usb.id.ums_adb=1038 \
    ro.usb.vid=12d1
