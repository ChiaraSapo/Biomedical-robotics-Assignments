/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'Torso'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Feb  8 19:05:20 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "Torso.h"
#include "Torso_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "rt_logging.h"
#include "androidinitialize.h"
#define UNUSED(x)                      x = x
#ifndef SAVEFILE
#define MATFILE2(file)                 #file ".mat"
#define MATFILE1(file)                 MATFILE2(file)
#define MATFILE                        MATFILE1(MODEL)
#else
#define QUOTE1(name)                   #name
#define QUOTE(name)                    QUOTE1(name)              /* need to expand name */
#define MATFILE                        QUOTE(SAVEFILE)
#endif

#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(Torso_M) == (NULL)) && !rtmGetStopRequested
    (Torso_M);
  while (runModel) {
    MW_sem_wait(&baserateTaskSem);

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(Torso_M->extModeInfo, 3, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Torso_M, true);
      }

      if (rtmGetStopRequested(Torso_M) == true) {
        rtmSetErrorStatus(Torso_M, "Simulation finished");
        break;
      }
    }

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(Torso_M->extModeInfo, 3, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Torso_M, true);
      }
    }

    Torso_step();

    /* Get model outputs here */
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(Torso_M) == (NULL)) &&
                      !rtmGetStopRequested(Torso_M));
    runModel = !stopRequested;
    rt_StopDataLogging(MATFILE, Torso_M->rtwLogInfo);
  }

  runModel = 0;
  terminateTask(arg);
  MW_pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(Torso_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  my_android_terminate();

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Torso_terminate();
  rtExtModeShutdown(3);
  MW_sem_post(&stopSem);
  return NULL;
}

jint JNICALL naMain(JNIEnv *pEnv, jobject pObj, jobjectArray pArgv, jobject
                    pMainActivity)
{
  int argc = 4;
  char *argv[4] = { "Torso", "-w", "-port", "17725" };

  my_android_init(pEnv, pObj, pArgv, pMainActivity);
  rtmSetErrorStatus(Torso_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  /* Initialize model */
  Torso_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(Torso_M));
  rtExtModeCheckInit(3);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(Torso_M->extModeInfo, 3, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(Torso_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* Call RTOS Initialization function */
  myRTOSInit(0.004, 0);

  /* Wait for stop semaphore */
  MW_sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(MW_sem_destroy(&timerTaskSem[i]), 0, "MW_sem_destroy");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
