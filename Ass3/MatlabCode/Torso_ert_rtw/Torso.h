/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Torso.h
 *
 * Code generated for Simulink model 'Torso'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Feb  8 20:14:51 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Torso_h_
#define RTW_HEADER_Torso_h_
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef Torso_COMMON_INCLUDES_
#define Torso_COMMON_INCLUDES_
#include <stdlib.h>
#include "driver_android_plot.h"
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "driver_android_gyroscope.h"
#endif                                 /* Torso_COMMON_INCLUDES_ */

#include "Torso_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<Root>/Lowpass Filter1' */
typedef struct {
  real32_T LowpassFilter1;             /* '<Root>/Lowpass Filter1' */
} B_LowpassFilter1_Torso_T;

/* Block states (default storage) for system '<Root>/Lowpass Filter1' */
typedef struct {
  dsp_LowpassFilter_Torso_T obj;       /* '<Root>/Lowpass Filter1' */
  boolean_T objisempty;                /* '<Root>/Lowpass Filter1' */
  boolean_T isInitialized;             /* '<Root>/Lowpass Filter1' */
} DW_LowpassFilter1_Torso_T;

/* Block signals (default storage) */
typedef struct {
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T new_pos[3];                   /* '<Root>/MATLAB Function2' */
  real32_T TmpSignalConversionAtToWorkspac[3];
  real32_T MATLABSystem_o1;            /* '<S1>/MATLAB System' */
  real32_T MATLABSystem_o2;            /* '<S1>/MATLAB System' */
  real32_T MATLABSystem_o3;            /* '<S1>/MATLAB System' */
  B_LowpassFilter1_Torso_T LowpassFilter2;/* '<Root>/Lowpass Filter1' */
  B_LowpassFilter1_Torso_T LowpassFilter1;/* '<Root>/Lowpass Filter1' */
} B_Torso_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidG_T obj; /* '<S1>/MATLAB System' */
  struct {
    void *LoggedData;
  } FilteredDatarad_PWORK;             /* '<Root>/Filtered Data (rad)  ' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<Root>/To Workspace1' */

  struct {
    void *LoggedData;
  } Datarad2_PWORK;                    /* '<Root>/Data (rad) 2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  void *VRSink_PWORK[5];               /* '<Root>/VR Sink' */
  struct {
    void *LoggedData;
  } Datarad1_PWORK;                    /* '<Root>/Data (rad) 1' */

  struct {
    void *LoggedData;
  } UnfilteredDatarad1_PWORK;          /* '<Root>/Unfiltered Data (rad)  1' */

  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  DW_LowpassFilter1_Torso_T LowpassFilter2;/* '<Root>/Lowpass Filter1' */
  DW_LowpassFilter1_Torso_T LowpassFilter1;/* '<Root>/Lowpass Filter1' */
} DW_Torso_T;

/* Parameters (default storage) */
struct P_Torso_T_ {
  real_T Constant_Value;               /* Expression: 0.01
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_IC;
                               /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                * Referenced by: '<Root>/Discrete-Time Integrator1'
                                */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<Root>/Discrete-Time Integrator'
                                 */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Torso_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Torso_T Torso_P;

/* Block signals (default storage) */
extern B_Torso_T Torso_B;

/* Block states (default storage) */
extern DW_Torso_T Torso_DW;

/* Model entry point functions */
extern void Torso_initialize(void);
extern void Torso_step(void);
extern void Torso_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Torso_T *const Torso_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Torso'
 * '<S1>'   : 'Torso/Gyroscope'
 * '<S2>'   : 'Torso/MATLAB Function2'
 */
#endif                                 /* RTW_HEADER_Torso_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
