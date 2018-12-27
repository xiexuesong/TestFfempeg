//
// Created by admin on 2018/12/7.
//
/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class jniUtils_FfempegUtils */

#ifndef _Included_jniUtils_FfempegUtils
#define _Included_jniUtils_FfempegUtils

#include <android/log.h>
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

JNIEnv *jniEnv = NULL;
jobject jobject_global = NULL;
char* time2 = "time=";

void progress(char *line) {
    char* p = strstr(line,time2);
    if(p != NULL) {
        //输出日志格式
        __android_log_print(ANDROID_LOG_DEBUG,"MDL","%s\n",line);
        jclass jclass_global = (*jniEnv)->FindClass(jniEnv, "jniUtils/FfempegUtils");
        jmethodID jMethod_progress = (*jniEnv)->GetMethodID(jniEnv, jclass_global, "progress",
                                                            "(Ljava/lang/String;)V");

        jstring jString1 = (*jniEnv)->NewStringUTF(jniEnv, line);

        (*jniEnv)->CallVoidMethod(jniEnv, jobject_global, jMethod_progress,
                                  jString1);
        //释放内存
        (*jniEnv)->ReleaseStringUTFChars(jniEnv, jString1, line);
        (*jniEnv)->DeleteLocalRef(jniEnv, jString1);
    }
}

JNIEXPORT jint JNICALL Java_jniUtils_FfempegUtils_runFfempeg
        (JNIEnv *env, jobject jobject, jobjectArray commands) {
//FFmpeg av_log() callback
    jniEnv = env;
    jobject_global = jobject;


    int argc = (*env)->GetArrayLength(env, commands);
    char *argv[argc];

    LOGD("Kit argc %d\n", argc);
    int i;
    for (i = 0; i < argc; i++) {
        jstring js = (jstring) (*env)->GetObjectArrayElement(env, commands, i);
        argv[i] = (char *) (*env)->GetStringUTFChars(env, js, 0);
        LOGD("Kit argv %s\n", argv[i]);
    }
    int result = runFfempeg(argc,argv);
    //释放内存
    for (i = 0; i < argc; i++) {
        free(argv[i]);
    }
    //free(argv);
    return result;
}


#ifdef __cplusplus
}
#endif
#endif

