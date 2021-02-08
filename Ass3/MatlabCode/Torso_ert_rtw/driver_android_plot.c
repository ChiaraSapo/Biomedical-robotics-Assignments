/*
 * driver_android_plot.c
 *
 * Driver code
 *
 * Copyright 2016-2017 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include <android/log.h>
#include "driver_android_plot.h"

extern JavaVM *cachedJvm;
extern jobject cachedActivityObj;
extern jclass cachedMainActivityCls;


void initScope(int scopeID, int numInputPortsScope, const char *scopeAttributes, float *sampleTimes) {

    JNIEnv *pEnv;
    jmethodID initMethodID;
    char formatInitScope[] = {"(II[B[F)V"};

    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);


    initMethodID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "initScope", formatInitScope);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                            "Exception: on Getting MethodID of initScope.");
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
        return;
    }


    if (NULL != initMethodID) {
        jbyteArray stringAttributeArray;
        int strLen = strlen(scopeAttributes);

        stringAttributeArray = (*pEnv)->NewByteArray(pEnv, strLen);
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on creating new byte array.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->DeleteLocalRef(pEnv, stringAttributeArray);
            (*pEnv)->ExceptionClear(pEnv);
            return;
        }


        (*pEnv)->SetByteArrayRegion(pEnv, stringAttributeArray, 0, strLen, scopeAttributes);
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on setting attribute string array.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->DeleteLocalRef(pEnv, stringAttributeArray);
            (*pEnv)->ExceptionClear(pEnv);
            return;
        }

        jfloatArray sampleTimesArray;
        sampleTimesArray = (*pEnv)->NewFloatArray(pEnv, numInputPortsScope);
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on creating new float array.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->DeleteLocalRef(pEnv, sampleTimesArray);
            (*pEnv)->ExceptionClear(pEnv);
            return;
        }

        (*pEnv)->SetFloatArrayRegion(pEnv, sampleTimesArray, 0, numInputPortsScope, sampleTimes);
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on setting data array.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->DeleteLocalRef(pEnv, sampleTimesArray);
            (*pEnv)->ExceptionClear(pEnv);
            return;
        }
        
        (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, initMethodID, scopeID, numInputPortsScope,
                                stringAttributeArray, sampleTimesArray);

        // Clear the exception so user can proceed
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on calling CallVoidMethod.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->ExceptionClear(pEnv);
        }

        (*pEnv)->DeleteLocalRef(pEnv, stringAttributeArray);
        (*pEnv)->DeleteLocalRef(pEnv, sampleTimesArray);
    } else {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                            "ERROR: GetMethodID returned null reference.");
        // Clear the exception so user can proceed
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->ExceptionClear(pEnv);
        }
    }
}

void cachePlotData(int scopeID, int portIdx, float *data, int signalWidth, int sigNumDims, int *sigDims) {
    JNIEnv *pEnv;
    jmethodID cacheMethodID;
    char formatCachePlotData[] = {"(II[FI[I)V"};

    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    cacheMethodID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "cachePlotData",
                                         formatCachePlotData);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                            "Exception: on Getting MethodID of cachePlotData.");
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
        return;
    }

    if (NULL != cacheMethodID) {
        jfloatArray val;
        val = (*pEnv)->NewFloatArray(pEnv, signalWidth);
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on creating new float array.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->DeleteLocalRef(pEnv, val);
            (*pEnv)->ExceptionClear(pEnv);
            return;
        }

        (*pEnv)->SetFloatArrayRegion(pEnv, val, 0, signalWidth, data);
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on setting data array.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->DeleteLocalRef(pEnv, val);
            (*pEnv)->ExceptionClear(pEnv);
            return;
        }

        jintArray sigDimsArray;
        sigDimsArray = (*pEnv)->NewIntArray(pEnv, sigNumDims);
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on creating new int array.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->DeleteLocalRef(pEnv, sigDimsArray);
            (*pEnv)->ExceptionClear(pEnv);
            return;
        }

        (*pEnv)->SetIntArrayRegion(pEnv, sigDimsArray, 0, sigNumDims, sigDims);
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on setting data array.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->DeleteLocalRef(pEnv, sigDimsArray);
            (*pEnv)->ExceptionClear(pEnv);
            return;
        }

        (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, cacheMethodID, scopeID, portIdx, val, sigNumDims, sigDimsArray);

        // Clear the exception so user can proceed
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on calling Void Method cachePlotData.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->ExceptionClear(pEnv);
        }

        (*pEnv)->DeleteLocalRef(pEnv, val);
        (*pEnv)->DeleteLocalRef(pEnv, sigDimsArray);
    }
}

void plotData(int scopeID) {

    JNIEnv *pEnv;
    jmethodID plotMethodID;
    char formatPlotData[] = {"(I)V"};

    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    plotMethodID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "plotData", formatPlotData);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                            "Exception: on Getting MethodID of plotData.");
        (*pEnv)->ExceptionDescribe(pEnv);
        (*pEnv)->ExceptionClear(pEnv);
        return;
    }

    if (NULL != plotMethodID) {
        (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, plotMethodID, scopeID);

        // Clear the exception so user can proceed
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_plot",
                                "Exception: on calling Void Method plotData.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->ExceptionClear(pEnv);
        }
    }
}
