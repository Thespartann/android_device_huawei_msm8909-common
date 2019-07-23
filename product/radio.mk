# Radio properties
PRODUCT_PROPERTY_OVERRIDES += \
    persist.data.target=dpm1 \
    persist.radio.no_cons_man_roam=1 \
    persist.radio.sib16_support=1\
    rild.libpath=/system/vendor/lib/libril-qc-qmi-1.so \
    ril.ecclist=000,08,100,101,102,110,112,118,119,120,122,911,999 \
    ril.ecclist1=000,08,100,101,102,110,112,118,119,120,122,911,999 \
    ro.telephony.ril.config=simactivation \
    ro.hwpp.cust_ons_bin=true
