# Display
PRODUCT_PACKAGES += \
    copybit.msm8909 \
    gralloc.msm8909 \
    hwcomposer.msm8909 \
    libion \
    libtinyxml \
    memtrack.msm8909

# Properties
PRODUCT_PROPERTY_OVERRIDES += \
    debug.composition.type=dyn \
    debug.mdpcomp.idletime=600 \
    persist.hwc.mdpcomp.enable=true \
    persist.hwc.ptor.enable=true \
    debug.enable.sglscale=1 \
    ro.opengles.version=196608
