//
// Created by admin on 2018/12/7.
//
/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class jniUtils_FfempegUtils */

#ifndef _Included_jniUtils_FfempegUtils
#define _Included_jniUtils_FfempegUtils

#include "ffmpeg.h"
#include "android_log.h"

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

JavaVM *javaVM = NULL;
jobject jobject_global = NULL;
char *time2 = "time=";

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    javaVM = vm;
    JNIEnv *jniEnv = NULL;
    //获取环境
    jint ret = (*vm)->GetEnv(vm, (void **) &jniEnv, JNI_VERSION_1_6);
    if (ret != JNI_OK) {
        return -1;
    }
    return JNI_VERSION_1_6;
}

void progress(char *line) {
    char *p = strstr(line, time2);
    //如果不再这里做一个过滤字符串的判断，由于返回的字符串太多，导致项目崩溃，即使释放也没有效果
    if (p != NULL) {
        //输出日志格式
        //   __android_log_print(ANDROID_LOG_DEBUG,"MDL","%s\n",line);
        if (javaVM != NULL) {
            JNIEnv *jniEnv = NULL;
            (*javaVM)->AttachCurrentThread(javaVM, &jniEnv, NULL);
            // (*javaVM)->GetEnv(javaVM,(void **)&jniEnv,JNI_VERSION_1_6);
            //获得jclass对象
            //jclass jclass_global = (*jniEnv)->FindClass(jniEnv, "jniUtils/FfempegUtils");
            jclass jclass_global = (*jniEnv)->GetObjectClass(jniEnv, jobject_global);
            //获得FfempegUtils中的progress方法的 jmethodID
            jmethodID jMethod_progress = (*jniEnv)->GetMethodID(jniEnv, jclass_global, "progress",
                                                                "(Ljava/lang/String;)V");
            //字符指针转换成字符串
            jstring jString1 = (*jniEnv)->NewStringUTF(jniEnv, line);
            char *line2 = (char *) (*jniEnv)->GetStringUTFChars(jniEnv, jString1, 0);
            //调用FfempegUtils的progress方法
            (*jniEnv)->CallVoidMethod(jniEnv, jobject_global, jMethod_progress,
                                      jString1);
            //释放内存
            (*jniEnv)->ReleaseStringUTFChars(jniEnv, jString1, line2);
            (*jniEnv)->DeleteLocalRef(jniEnv, jString1);
        }
    }
}

JNIEXPORT jint JNICALL Java_jniUtils_FfempegUtils_runFfempeg
        (JNIEnv *env, jobject jobject, jobjectArray commands) {
//FFmpeg av_log() callback
    jobject_global = jobject;

    int argc = (*env)->GetArrayLength(env, commands);
    char *argv[argc];

    int i;
    for (i = 0; i < argc; i++) {
        jstring js = (jstring) (*env)->GetObjectArrayElement(env, commands, i);
        argv[i] = (char *) (*env)->GetStringUTFChars(env, js, 0);
    }
    int result = runFfempeg(argc, argv);
    //释放内存
    for (int i = 0; i < argc; i++) {
        free(argv[i]);
    }
    // free(argv);
    return result;
}


#ifdef __cplusplus
}
#endif
#endif

