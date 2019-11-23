# Exclude SSC targets
ifneq ($(TARGET_USES_SSC),true)
# Disable temporarily for compilling error
ifneq ($(BUILD_TINY_ANDROID),true)
LOCAL_PATH := $(call my-dir)

# HAL module implemenation stored in
include $(CLEAR_VARS)

ifeq ($(USE_SENSOR_MULTI_HAL),true)
  LOCAL_MODULE := sensors.native
  LOCAL_VENDOR_MODULE := true
  LOCAL_MODULE_PATH_32 := $(TARGET_OUT_VENDOR)/lib
LOCAL_MODULE := sensors.msm8909
endif
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw

LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS += -DLOG_TAG=\"Sensors\"

LOCAL_C_INCLUDES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

# Export calibration library needed dependency headers
LOCAL_COPY_HEADERS_TO := sensors/inc
LOCAL_COPY_HEADERS := 	\
		CalibrationModule.h \
		sensors_extension.h \
		sensors.h

LOCAL_SRC_FILES :=	\
		sensors.cpp \
		SensorBase.cpp \
		LightSensor.cpp	\
		ProximitySensor.cpp \
		CompassSensor.cpp \
		Accelerometer.cpp \
		Gyroscope.cpp \
		Bmp180.cpp \
		InputEventReader.cpp \
		CalibrationManager.cpp \
		NativeSensorManager.cpp \
		VirtualSensor.cpp \
		sensors_XML.cpp \
		SignificantMotion.cpp

LOCAL_C_INCLUDES += external/libxml2/include \

    LOCAL_C_INCLUDES += external/icu/icu4c/source/common

LOCAL_SHARED_LIBRARIES := liblog libcutils libdl libxml2 libutils

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := libcalmodule_common
LOCAL_SRC_FILES := \
		   algo/common/common_wrapper.c \
		   algo/common/compass/AKFS_AOC.c \
		   algo/common/compass/AKFS_Device.c \
		   algo/common/compass/AKFS_Direction.c \
		   algo/common/compass/AKFS_VNorm.c

LOCAL_SHARED_LIBRARIES := liblog libcutils
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR_SHARED_LIBRARIES)

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := calmodule.cfg
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_OUT_VENDOR_ETC)
LOCAL_SRC_FILES := calmodule.cfg

include $(BUILD_PREBUILT)

endif #BUILD_TINY_ANDROID
endif #TARGET_USES_SSC
