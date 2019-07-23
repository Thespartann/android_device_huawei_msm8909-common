# Hardware permissions
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/handheld_core_hardware.xml:system/etc/permissions/handheld_core_hardware.xml

# Lights packages
PRODUCT_PACKAGES += \
    lights.msm8909

# Compat symbols
PRODUCT_PACKAGES += \
    libshim_cutils
