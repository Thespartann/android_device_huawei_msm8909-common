# Sensors HAL
PRODUCT_PACKAGES += \
    calmodule.cfg \
    sensors.msm8909 \
    sensors.native

# Sensors configurations
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/sensors/hals.conf:system/etc/sensors/hals.conf
