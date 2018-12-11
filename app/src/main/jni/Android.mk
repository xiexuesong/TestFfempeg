LOCAL_PATH:=$(call my-dir)
INCLUDE_PATH:=../jni
FFEMPEG_LIB_PATH:=../jniLibs/armeabi-v7a

include $(CLEAR_VARS)
LOCAL_MODULE:=libavcodec
LOCAL_SRC_FILES:=$(FFEMPEG_LIB_PATH)/libavcodec.so
LOCAL_EXPORT_C_INCLUDES:=$(INCLUDE_PATH)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:=libavutil
LOCAL_SRC_FILES:=$(FFEMPEG_LIB_PATH)/libavutil.so
LOCAL_EXPORT_C_INCLUDES:=$(INCLUDE_PATH)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:=libavformat
LOCAL_SRC_FILES:=$(FFEMPEG_LIB_PATH)/libavformat.so
LOCAL_EXPORT_C_INCLUDES:=$(INCLUDE_PATH)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:=libavfilter
LOCAL_SRC_FILES:=$(FFEMPEG_LIB_PATH)/libavfilter.so
LOCAL_EXPORT_C_INCLUDES:=$(INCLUDE_PATH)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:=libavdevice
LOCAL_SRC_FILES:=$(FFEMPEG_LIB_PATH)/libavdevice.so
LOCAL_EXPORT_C_INCLUDES:=$(INCLUDE_PATH)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:=libswresample
LOCAL_SRC_FILES:=$(FFEMPEG_LIB_PATH)/libswresample.so
LOCAL_EXPORT_C_INCLUDES:=$(INCLUDE_PATH)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE:=libswscale
LOCAL_SRC_FILES:=$(FFEMPEG_LIB_PATH)/libswscale.so
LOCAL_EXPORT_C_INCLUDES:=$(INCLUDE_PATH)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := ffempeg
LOCAL_SRC_FILES := jniUtils_FfempegUtils.c \
                    cmdutils.c \
                    ffmpeg.c \
                    ffmpeg_opt.c \
                    ffmpeg_filter.c
LOCAL_C_INCLUDES := D:/FFmpeg-n4.0.1/FFmpeg-n4.0.1
LOCAL_LDLIBS := -llog -lz -ldl
LOCAL_SHARED_LIBRARIES := libavutil libavformat libavcodec libavfilter libavdevice libswresample libswscale
include $(BUILD_SHARED_LIBRARY)
