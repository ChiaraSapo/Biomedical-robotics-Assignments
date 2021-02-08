/*
 * driver_android_gyroscope.c
 *
 * Driver code
 *
 * Copyright 2013 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>

extern JavaVM *cachedJvm;
extern jobject cachedActivityObj;
extern jclass cachedMainActivityCls;
static jmethodID sgGyroscopeSensorGetDataID;

void initGyroscope()
{
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    sgGyroscopeSensorGetDataID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, "getGyroscopeData",
    "()[F");    
}

void getGyroscopeData(float *outX, float *outY ,float *outZ)
{
    if (sgGyroscopeSensorGetDataID != NULL)
    {
        JNIEnv *pEnv;
        jfloatArray ret;
        jfloat values[3];        
        
        (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
        
        ret = (jfloatArray)(*pEnv)->CallObjectMethod(pEnv, cachedActivityObj, sgGyroscopeSensorGetDataID);       
        if ((*pEnv)->ExceptionCheck(pEnv)) 
            return; /* Exception during execution of getGyroscopeData */
        
        (*pEnv)->GetFloatArrayRegion(pEnv, ret, 0, 3, values);
        if ((*pEnv)->ExceptionCheck(pEnv)) 
        {
            (*pEnv)->DeleteLocalRef(pEnv, ret);
            return; /* ArrayIndexOutOfBoundsException */
        }
        
        
        *outX = values[0];
        *outY = values[1];
        *outZ = values[2];
        
        (*pEnv)->DeleteLocalRef(pEnv, ret);
    }
}

void terminateGyroscope()
{
}