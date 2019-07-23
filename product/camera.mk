# Camera packages
PRODUCT_PACKAGES += \
    camera.msm8909 \
    Snap \
    libboringssl-compat

# Camera properties
PRODUCT_PROPERTY_OVERRIDES += \
    camera2.portability.force_api=1 \
    media.stagefright.legacyencoder=true \
    media.stagefright.less-secure=true \
    persist.camera.hal.debug.mask=0
