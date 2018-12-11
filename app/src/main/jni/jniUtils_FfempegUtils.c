//
// Created by admin on 2018/12/7.
//
/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class jniUtils_FfempegUtils */

#ifndef _Included_jniUtils_FfempegUtils
#define _Included_jniUtils_FfempegUtils

#include <android/log.h>
#include "jniUtils_FfempegUtils.h"
#include "android_log.h"
#include "ffmpeg.h"

#ifdef __cplusplus


extern "C" {
#endif
/*
 * Class:     jniUtils_FfempegUtils
 * Method:    runFfempeg
 * Signature: ()V
 *
 *logcat  只能输出error 和 info
 */

JNIEXPORT jint JNICALL Java_jniUtils_FfempegUtils_runFfempeg
        (JNIEnv *env, jclass jclass , jobjectArray commands) {
//FFmpeg av_log() callback
    int argc = (*env)->GetArrayLength(env, commands);
    char *argv[argc];

    LOGD("Kit argc %d\n", argc);
    int i;
    for (i = 0; i < argc; i++) {
        jstring js = (jstring) (*env)->GetObjectArrayElement(env, commands, i);
        argv[i] = (char*) (*env)->GetStringUTFChars(env, js, 0);
        LOGD("Kit argv %s\n", argv[i]);
    }
    return runFfempeg(argc, argv);
}

#ifdef __cplusplus
}
#endif
#endif

