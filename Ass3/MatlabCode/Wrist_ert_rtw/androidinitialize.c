/* Copyright 2015-2019 The MathWorks, Inc. */


/* ---------------------------- */
/* RTOS-specific headers        */
/* Note: must be included first */
/* ---------------------------- */
#include "androidinitialize.h"

/* ---------------------------- */
/* Required Coder Target header */
/* ---------------------------- */
#include "MW_custom_RTOS_header.h"

/* Used for JNI calls */
JavaVM *cachedJvm;
jobject cachedActivityObj;
jclass cachedMainActivityCls;
jmethodID flashMessageID;

extern jint JNICALL naMain(JNIEnv *pEnv, jobject pObj, jobjectArray pArgv, jobject pMainActivity);



void JNICALL naOnAppStateChange(JNIEnv *pEnv, jobject pObj, jint state)
{
    /********
     *  Android Activity life cycle states are mapped as below:
     *  onCreate  : 1
     *  onStart   : 2
     *  onResume  : 3
     *  onPause   : 4
     *  onStop    : 5
     *  onDestroy : 6
     *******/
    switch(state) {
        case 1:
            /*ONCREATE CALLS GOES HERE*/
            break;
        case 2:
            /*ONSTART CALLS GOES HERE*/
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            /*ONSTOP CALLS GOES HERE*/
            break;
        case 6:
            terminateTask(NULL);    
            break;
        default:
            break;
    }
}

baseRateInfo_t baseRateInfo;

void MW_baseRateSignalHandler(int sigNo)
{
    int ret;
    if (baseRateInfo.sigNo == sigNo) {
        MW_sem_post(&baserateTaskSem);
    } else {
        LOGMESSAGE_ARG1("***Got unknown signal: %d***", sigNo);
    }
}

void MW_sem_wait(sem_t *sem)
{
    int status;
    while (((status = sem_wait(sem)) == -1) && (errno == EINTR)) {
        /* Restart if interrupted by a signal */
        continue;
    }
    
    CHECK_STATUS(status, 0, "sem_wait");
}

void MW_exitHandler(int sigNo)
{
    sem_post(&stopSem);
}

int MW_sem_post(sem_t *sem)
{
    return sem_post(sem);
}

int MW_sem_destroy(sem_t *sem)
{
    return sem_destroy(sem);
}

void MW_blockSignal(int sigNo, sigset_t *sigMask)
{
    int ret;
    sigaddset(sigMask, sigNo);
    ret = pthread_sigmask(SIG_BLOCK, sigMask, NULL);
    CHECK_STATUS(ret, 0, "pthread_sigmask");
}

void MW_setTaskPeriod(double periodInSeconds, int sigNo, sighandler_t handler)
{
    timer_t timerId;
    struct sigevent sev;
    struct itimerspec its;
    long stNanoSec;
    int ret;
    
    /* before creating timer lets initialize the signal handler */
    signal(sigNo, handler);
    
    /* Create a timer */
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = sigNo;
    sev.sigev_value.sival_ptr = &timerId;
    ret = timer_create(CLOCK_REALTIME, &sev, &timerId);
    CHECK_STATUS(ret, 0, "timer_create");
    
    /* Arm real-time scheduling timer */
    stNanoSec = (long)(periodInSeconds * 1e9);
    its.it_value.tv_sec = stNanoSec / 1000000000;
    its.it_value.tv_nsec = stNanoSec % 1000000000;
    its.it_interval.tv_sec = its.it_value.tv_sec;
    its.it_interval.tv_nsec = its.it_value.tv_nsec;
    ret = timer_settime(timerId, 0, &its, NULL);
    CHECK_STATUS(ret, 0, "timer_settime");
}

void flashMessage(const char* inMessage)
{
    if (flashMessageID != NULL) {
        JNIEnv *pEnv;
        jstring jMessage;
        (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
        jMessage = (*pEnv)->NewStringUTF(pEnv, inMessage);
        (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, flashMessageID, jMessage);
        (*pEnv)->DeleteLocalRef(pEnv, jMessage);
    }
}

void detachCurrentThreadFromJVM()
{
    if (cachedJvm != NULL) {
        (*cachedJvm)->DetachCurrentThread(cachedJvm);
    }
}

void my_android_init(JNIEnv *pEnv, jobject pObj, jobjectArray pArgv, jobject
        pMainActivity)
{
    (*pEnv)->GetJavaVM(pEnv, &cachedJvm);
    cachedMainActivityCls = (*pEnv)->NewGlobalRef(pEnv, (*pEnv)->GetObjectClass
            (pEnv, pMainActivity));
    cachedActivityObj = (*pEnv)->NewGlobalRef(pEnv, pMainActivity);
    flashMessageID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls,
            "flashMessage", "(Ljava/lang/String;)V");
    
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* pVm, void *reserved)
{
    JNIEnv* env;
    if ((*pVm)->GetEnv(pVm, (void **)&env, JNI_VERSION_1_6) != JNI_OK) {
        LOGMESSAGE_ARG1("Not version %d; Exiting", JNI_VERSION_1_6);
        return -1;
    }
    
    JNINativeMethod nm[2];
    nm[0].name = "naMain";
    nm[0].signature =
            "([Ljava/lang/String;Lcom/example/Wrist/Wrist;)I";
    nm[0].fnPtr = (void*)naMain;
    nm[1].name = "naOnAppStateChange";
    nm[1].signature =
            "(I)V";
    nm[1].fnPtr = (void*)naOnAppStateChange;
    
    jclass cls = (*env)->FindClass(env,
            "com/example/Wrist/Wrist");
    
    //Register methods with env->RegisterNatives.
    (*env)->RegisterNatives(env, cls, nm, 2);
    return JNI_VERSION_1_6;
}

void my_android_terminate()
{
}

void MW_pthread_exit(void *arg)
{
    detachCurrentThreadFromJVM();
}

int MW_pthread_join(pthread_t thread, void **value_ptr)
{
    return 0;
}

void myRTOSInit(double baseRatePeriod, int numSubrates)
{
    int ret;
    pthread_attr_t attr;
    pthread_t baseRateThread;
    size_t stackSize;
    unsigned long cpuMask = 0x1;
    unsigned int len = sizeof(cpuMask);
    
    /* Flash a message in the main activity */
    flashMessage("Starting the model");
    
    /* Initialize semaphore used for thread synchronization */
    ret = sem_init(&stopSem, 0, 0);
    CHECK_STATUS(ret, 0, "sem_init:stopSem");
    
    /* Create threads executing the Simulink model */
    ret = pthread_attr_init(&attr);
    CHECK_STATUS(ret, 0, "pthread_attr_init");
    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    CHECK_STATUS(ret, 0, "pthread_attr_setdetachstate");
    
    /* Block signal used for timer notification */
    baseRateInfo.period = baseRatePeriod;
    baseRateInfo.sigNo = SIGRTMIN;
    sigemptyset(&baseRateInfo.sigMask);
    MW_blockSignal(baseRateInfo.sigNo, &baseRateInfo.sigMask);
    ret = pthread_mutex_init (&baseRateInfo.sigWaitMutex, NULL);
    CHECK_STATUS(ret, 0, "pthread_mutex_init");
    ret = pthread_cond_init (&baseRateInfo.sigWait, NULL);
    CHECK_STATUS(ret, 0, "pthread_cond_init");
    signal(SIGTERM, MW_exitHandler);     /* kill */
    signal(SIGHUP, MW_exitHandler);      /* kill -HUP */
    signal(SIGINT, MW_exitHandler);      /* Interrupt from keyboard */
    signal(SIGQUIT, MW_exitHandler);     /* Quit from keyboard */
    
    MW_setTaskPeriod(baseRateInfo.period, baseRateInfo.sigNo, MW_baseRateSignalHandler);
    
    /* Create base rate task */
    ret = pthread_create(&baseRateThread, &attr, (void *) baseRateTask, (void *)
    &baseRateInfo);
    CHECK_STATUS(ret, 0, "pthread_create");
    
    ret = pthread_attr_destroy(&attr);
    CHECK_STATUS(ret, 0, "pthread_attr_destroy");
    
}

