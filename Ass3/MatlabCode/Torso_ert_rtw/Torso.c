/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Torso.c
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

#include "Torso.h"
#include "Torso_private.h"
#include "Torso_dt.h"

/* Block signals (default storage) */
B_Torso_T Torso_B;

/* Block states (default storage) */
DW_Torso_T Torso_DW;

/* Real-time model */
static RT_MODEL_Torso_T Torso_M_;
RT_MODEL_Torso_T *const Torso_M = &Torso_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Torso_M->Timing.TaskCounters.TID[1])++;
  if ((Torso_M->Timing.TaskCounters.TID[1]) > 3) {/* Sample time: [0.016s, 0.0s] */
    Torso_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Torso_M->Timing.TaskCounters.TID[2])++;
  if ((Torso_M->Timing.TaskCounters.TID[2]) > 24) {/* Sample time: [0.1s, 0.0s] */
    Torso_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    synthesized block
 *    synthesized block
 */
void Torso_LowpassFilter1_Init(DW_LowpassFilter1_Torso_T *localDW)
{
  static const real32_T tmp[52] = { -0.00101120991F, 0.00165727537F,
    0.00286568888F, 0.00288647762F, 0.000599275809F, -0.00314747426F,
    -0.00559198158F, -0.00394358439F, 0.00193960604F, 0.00837794412F,
    0.00979245454F, 0.0030922615F, -0.00868459139F, -0.0169635769F,
    -0.0132989893F, 0.00324401236F, 0.02278555F, 0.029430015F, 0.0125733707F,
    -0.0224886276F, -0.0530572236F, -0.0499811582F, 0.00410360191F, 0.100557461F,
    0.204762876F, 0.272240847F, 0.272240847F, 0.204762876F, 0.100557461F,
    0.00410360191F, -0.0499811582F, -0.0530572236F, -0.0224886276F,
    0.0125733707F, 0.029430015F, 0.02278555F, 0.00324401236F, -0.0132989893F,
    -0.0169635769F, -0.00868459139F, 0.0030922615F, 0.00979245454F,
    0.00837794412F, 0.00193960604F, -0.00394358439F, -0.00559198158F,
    -0.00314747426F, 0.000599275809F, 0.00288647762F, 0.00286568888F,
    0.00165727537F, -0.00101120991F };

  b_dspcodegen_FIRFilter_Torso_T *iobj_0;
  int32_T i;

  /* Start for MATLABSystem: '<Root>/Lowpass Filter1' */
  localDW->obj._pobj0.matlabCodegenIsDeleted = true;
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  iobj_0 = &localDW->obj._pobj0;
  localDW->obj._pobj0.isInitialized = 0;

  /* System object Constructor function: dsp.FIRFilter */
  localDW->obj._pobj0.cSFunObject.P0_InitialStates = 0.0F;
  for (i = 0; i < 52; i++) {
    iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
  }

  localDW->obj._pobj0.matlabCodegenIsDeleted = false;
  localDW->obj.FilterObj = &localDW->obj._pobj0;
  localDW->obj.NumChannels = 1;
  localDW->obj.isSetupComplete = true;

  /* End of Start for MATLABSystem: '<Root>/Lowpass Filter1' */

  /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter1' */
  iobj_0 = localDW->obj.FilterObj;
  if (iobj_0->isInitialized == 1) {
    /* System object Initialization function: dsp.FIRFilter */
    for (i = 0; i < 51; i++) {
      iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
    }
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter1' */
}

/*
 * Output and update for atomic system:
 *    synthesized block
 *    synthesized block
 */
void Torso_LowpassFilter1(real32_T rtu_0, B_LowpassFilter1_Torso_T *localB,
  DW_LowpassFilter1_Torso_T *localDW)
{
  b_dsp_FIRFilter_0_Torso_T *obj_0;
  b_dspcodegen_FIRFilter_Torso_T *obj;
  int32_T j;
  real32_T acc1;
  real32_T acc2;

  /* MATLABSystem: '<Root>/Lowpass Filter1' */
  obj = localDW->obj.FilterObj;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (j = 0; j < 51; j++) {
      obj->cSFunObject.W0_states[j] = obj->cSFunObject.P0_InitialStates;
    }
  }

  obj_0 = &obj->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  /* Consume delay line and beginning of input samples */
  acc2 = rtu_0 * obj->cSFunObject.P1_Coefficients[0];
  acc1 = acc2;
  for (j = 0; j < 51; j++) {
    acc2 = obj_0->P1_Coefficients[j + 1] * obj_0->W0_states[j];
    acc1 += acc2;
  }

  /* Update delay line for next frame */
  for (j = 49; j >= 0; j--) {
    obj_0->W0_states[j + 1] = obj_0->W0_states[j];
  }

  obj->cSFunObject.W0_states[0] = rtu_0;

  /* MATLABSystem: '<Root>/Lowpass Filter1' */
  localB->LowpassFilter1 = acc1;
}

/*
 * Termination for atomic system:
 *    synthesized block
 *    synthesized block
 */
void Torso_LowpassFilter1_Term(DW_LowpassFilter1_Torso_T *localDW)
{
  b_dspcodegen_FIRFilter_Torso_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.FilterObj;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  if (!localDW->obj._pobj0.matlabCodegenIsDeleted) {
    localDW->obj._pobj0.matlabCodegenIsDeleted = true;
    if (localDW->obj._pobj0.isInitialized == 1) {
      localDW->obj._pobj0.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lowpass Filter1' */
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void Torso_step(void)
{
  /* local block i/o variables */
  real32_T rtb_DiscreteTimeIntegrator1;
  real32_T rtb_DiscreteTimeIntegrator;
  real_T theta;
  real32_T out[3];
  if (Torso_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    rtb_DiscreteTimeIntegrator1 = Torso_DW.DiscreteTimeIntegrator1_DSTATE;
    Torso_LowpassFilter1(rtb_DiscreteTimeIntegrator1, &Torso_B.LowpassFilter1,
                         &Torso_DW.LowpassFilter1);

    /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    rtb_DiscreteTimeIntegrator = Torso_DW.DiscreteTimeIntegrator_DSTATE;
    Torso_LowpassFilter1(rtb_DiscreteTimeIntegrator, &Torso_B.LowpassFilter2,
                         &Torso_DW.LowpassFilter2);

    /* MATLABSystem: '<S1>/MATLAB System' */
    out[0] = 0.0F;
    out[1] = 0.0F;
    out[2] = 0.0F;
    GET_GYROSCOPE_DATA(&out[0], &out[1], &out[2]);

    /* MATLABSystem: '<S1>/MATLAB System' */
    Torso_B.MATLABSystem_o1 = out[0];

    /* MATLABSystem: '<S1>/MATLAB System' */
    Torso_B.MATLABSystem_o2 = out[1];

    /* MATLABSystem: '<S1>/MATLAB System' */
    Torso_B.MATLABSystem_o3 = out[2];

    /* SignalConversion generated from: '<Root>/To Workspace1' */
    Torso_B.TmpSignalConversionAtToWorkspac[0] =
      Torso_B.LowpassFilter2.LowpassFilter1;
    Torso_B.TmpSignalConversionAtToWorkspac[1] =
      Torso_B.LowpassFilter1.LowpassFilter1;
    Torso_B.TmpSignalConversionAtToWorkspac[2] = Torso_B.MATLABSystem_o3;

    /* Scope: '<Root>/Filtered Data (rad)  ' */
    /* Call plotting routine for a mobile target */
    {
      int_T scope3ID = 3;

      {
        int_T portIdx = 0;
        int_T signalWidth = 3;
        int_T sigNumDims = 1;
        int_T sigDims[1] = { 3 };

        real32_T up0[3];
        up0[0] = (real32_T)Torso_B.TmpSignalConversionAtToWorkspac[0];
        up0[1] = (real32_T)Torso_B.TmpSignalConversionAtToWorkspac[1];
        up0[2] = (real32_T)Torso_B.TmpSignalConversionAtToWorkspac[2];
        CACHE_PLOT_DATA(scope3ID,portIdx,up0,signalWidth,sigNumDims,sigDims);
      }

      PLOT_DATA(scope3ID);
    }

    /* End of Scope: '<Root>/Filtered Data (rad)  ' */

    /* ToWorkspace: '<Root>/To Workspace1' */
    rt_UpdateStructLogVar((StructLogVar *)Torso_DW.ToWorkspace1_PWORK.LoggedData,
                          (NULL), &Torso_B.TmpSignalConversionAtToWorkspac[0]);

    /* Gain: '<Root>/Gain2' */
    Torso_B.Gain2 = (real_T)Torso_P.Gain2_Gain *
      Torso_B.LowpassFilter1.LowpassFilter1;

    /* Gain: '<Root>/Gain1' */
    Torso_B.Gain1 = (real_T)Torso_P.Gain1_Gain *
      Torso_B.LowpassFilter2.LowpassFilter1;

    /* Constant: '<Root>/Constant' */
    Torso_B.Constant = Torso_P.Constant_Value;

    /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
     *  SignalConversion generated from: '<S2>/ SFunction '
     */
    theta = rt_atan2d_snf(Torso_B.Gain1, Torso_B.Gain2);
    if (fabs(Torso_B.Gain2) > fabs(0.1 * cos(theta))) {
      Torso_B.new_pos[0] = 0.1 * cos(theta);
    } else {
      Torso_B.new_pos[0] = Torso_B.Gain2;
    }

    theta = 0.1 * sin(theta);
    if (fabs(Torso_B.Gain1) > fabs(theta)) {
      Torso_B.new_pos[1] = theta;
    } else {
      Torso_B.new_pos[1] = Torso_B.Gain1;
    }

    Torso_B.new_pos[2] = Torso_B.Constant;

    /* End of MATLAB Function: '<Root>/MATLAB Function2' */

    /* Scope: '<Root>/Data (rad) 2' */
    /* Call plotting routine for a mobile target */
    {
      int_T scope2ID = 2;

      {
        int_T portIdx = 0;
        int_T signalWidth = 3;
        int_T sigNumDims = 1;
        int_T sigDims[1] = { 3 };

        real32_T up0[3];
        up0[0] = (real32_T)Torso_B.new_pos[0];
        up0[1] = (real32_T)Torso_B.new_pos[1];
        up0[2] = (real32_T)Torso_B.new_pos[2];
        CACHE_PLOT_DATA(scope2ID,portIdx,up0,signalWidth,sigNumDims,sigDims);
      }

      PLOT_DATA(scope2ID);
    }

    /* End of Scope: '<Root>/Data (rad) 2' */

    /* ToWorkspace: '<Root>/To Workspace' */
    rt_UpdateStructLogVar((StructLogVar *)Torso_DW.ToWorkspace_PWORK.LoggedData,
                          (NULL), &Torso_B.new_pos[0]);
  }

  if (Torso_M->Timing.TaskCounters.TID[2] == 0) {
  }

  if (Torso_M->Timing.TaskCounters.TID[1] == 0) {
    /* Scope: '<Root>/Data (rad) 1' */
    /* Call plotting routine for a mobile target */
    {
      int_T scope1ID = 1;

      {
        int_T portIdx = 0;
        int_T signalWidth = 3;
        int_T sigNumDims = 1;
        int_T sigDims[1] = { 3 };

        real32_T up0[3];
        up0[0] = (real32_T)Torso_B.Gain2;
        up0[1] = (real32_T)Torso_B.Gain1;
        up0[2] = (real32_T)Torso_B.Constant;
        CACHE_PLOT_DATA(scope1ID,portIdx,up0,signalWidth,sigNumDims,sigDims);
      }

      PLOT_DATA(scope1ID);
    }

    /* End of Scope: '<Root>/Data (rad) 1' */

    /* Scope: '<Root>/Unfiltered Data (rad)  1' */
    /* Call plotting routine for a mobile target */
    {
      int_T scope4ID = 4;

      {
        int_T portIdx = 0;
        int_T signalWidth = 3;
        int_T sigNumDims = 1;
        int_T sigDims[1] = { 3 };

        real32_T up0[3];
        up0[0] = (real32_T)Torso_B.MATLABSystem_o1;
        up0[1] = (real32_T)Torso_B.MATLABSystem_o2;
        up0[2] = (real32_T)Torso_B.MATLABSystem_o3;
        CACHE_PLOT_DATA(scope4ID,portIdx,up0,signalWidth,sigNumDims,sigDims);
      }

      PLOT_DATA(scope4ID);
    }

    /* End of Scope: '<Root>/Unfiltered Data (rad)  1' */
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(Torso_M->rtwLogInfo, (&Torso_M->Timing.taskTime0));
  if (Torso_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    Torso_DW.DiscreteTimeIntegrator1_DSTATE +=
      Torso_P.DiscreteTimeIntegrator1_gainval * Torso_B.MATLABSystem_o2;

    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    Torso_DW.DiscreteTimeIntegrator_DSTATE +=
      Torso_P.DiscreteTimeIntegrator_gainval * Torso_B.MATLABSystem_o1;
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(3);

  {                                    /* Sample time: [0.004s, 0.0s] */
    rtExtModeUpload(0, (real_T)Torso_M->Timing.taskTime0);
  }

  if (Torso_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.016s, 0.0s] */
    rtExtModeUpload(1, (real_T)((Torso_M->Timing.clockTick1) * 0.016));
  }

  if (Torso_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(2, (real_T)((Torso_M->Timing.clockTick2) * 0.1));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.004s, 0.0s] */
    if ((rtmGetTFinal(Torso_M)!=-1) &&
        !((rtmGetTFinal(Torso_M)-Torso_M->Timing.taskTime0) >
          Torso_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Torso_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Torso_M)) {
      rtmSetErrorStatus(Torso_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Torso_M->Timing.taskTime0 =
    ((time_T)(++Torso_M->Timing.clockTick0)) * Torso_M->Timing.stepSize0;
  if (Torso_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.016s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.016, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Torso_M->Timing.clockTick1++;
  }

  if (Torso_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Torso_M->Timing.clockTick2++;
  }

  rate_scheduler();
}

/* Model initialize function */
void Torso_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Torso_M, 90.0);
  Torso_M->Timing.stepSize0 = 0.004;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Torso_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Torso_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Torso_M->rtwLogInfo, (NULL));
    rtliSetLogT(Torso_M->rtwLogInfo, "tout");
    rtliSetLogX(Torso_M->rtwLogInfo, "");
    rtliSetLogXFinal(Torso_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Torso_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Torso_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Torso_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Torso_M->rtwLogInfo, 1);
    rtliSetLogY(Torso_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Torso_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Torso_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  Torso_M->Sizes.checksums[0] = (3641542897U);
  Torso_M->Sizes.checksums[1] = (1751017191U);
  Torso_M->Sizes.checksums[2] = (434612158U);
  Torso_M->Sizes.checksums[3] = (1620116833U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Torso_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Torso_M->extModeInfo,
      &Torso_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Torso_M->extModeInfo, Torso_M->Sizes.checksums);
    rteiSetTPtr(Torso_M->extModeInfo, rtmGetTPtr(Torso_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Torso_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Torso_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Torso_M), Torso_M->Timing.stepSize0, (&rtmGetErrorStatus(Torso_M)));

  /* SetupRuntimeResources for Scope: '<Root>/Filtered Data (rad)  ' */
  {
    const char* mobileScopeProperties3 =
      "{\"axesColor\":[0,0,0],\"axesScaling\":\"manual\",\"axesTickColor\":[0.686274509803922,0.686274509803922,0.686274509803922],\"blockType\":\"Scope\",\"displays\":[{\"lineColors\":[[1,1,0.0666666666666667],[0.0745098039215686,0.623529411764706,1],[1,0.411764705882353,0.16078431372549],[0.392156862745098,0.831372549019608,0.0745098039215686],[0.717647058823529,0.274509803921569,1],[0.0588235294117647,1,1],[1,0.0745098039215686,0.650980392156863]],\"lineStyles\":[\"-\",\"-\",\"-\",\"-\",\"-\",\"-\",\"-\"],\"lineWidths\":[0.75,0.75,0.75,0.75,0.75,0.75,0.75],\"showGrid\":true,\"showLegend\":false,\"yLimits\":[-1.58039,1.84548]}],\"frameBasedProcessing\":false,\"inputNames\":[\"Lowpass Filter2\",\"Lowpass Filter1\",\"Demux1\\/3\"],\"layoutDimensions\":[1,1],\"timeSpan\":90,\"timeSpanOverrunMode\":\"Wrap\"}";
    int_T numInputPortsScope3 = 1;
    int_T scope3ID = 3;
    real32_T sampleTimes3[1] = { 0.016 };

    INITIALIZE_PLOT(scope3ID,numInputPortsScope3,mobileScopeProperties3,
                    sampleTimes3);
  }

  /* End of Scope: '<Root>/Filtered Data (rad)  ' */
  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace1' */
  {
    static int_T rt_ToWksWidths[] = { 3 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 3 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] = "Torso/To Workspace1";
    Torso_DW.ToWorkspace1_PWORK.LoggedData = rt_CreateStructLogVar(
      Torso_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(Torso_M),
      Torso_M->Timing.stepSize0,
      (&rtmGetErrorStatus(Torso_M)),
      "FilteredDataTorso",
      0,
      0,
      1,
      0.016,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (Torso_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for Scope: '<Root>/Data (rad) 2' */
  {
    const char* mobileScopeProperties2 =
      "{\"axesColor\":[0,0,0],\"axesScaling\":\"manual\",\"axesTickColor\":[0.686274509803922,0.686274509803922,0.686274509803922],\"blockType\":\"Scope\",\"displays\":[{\"lineColors\":[[1,1,0.0666666666666667],[0.0745098039215686,0.623529411764706,1],[1,0.411764705882353,0.16078431372549],[0.392156862745098,0.831372549019608,0.0745098039215686],[0.717647058823529,0.274509803921569,1],[0.0588235294117647,1,1],[1,0.0745098039215686,0.650980392156863]],\"lineStyles\":[\"-\",\"-\",\"-\",\"-\",\"-\",\"-\",\"-\"],\"lineWidths\":[0.75,0.75,0.75,0.75,0.75,0.75,0.75],\"showGrid\":true,\"showLegend\":false,\"yLimits\":[-0.125,0.125]}],\"frameBasedProcessing\":false,\"inputNames\":[\"MATLAB Function2:1\",\"MATLAB Function2:2\",\"MATLAB Function2:3\"],\"layoutDimensions\":[1,1],\"timeSpan\":90,\"timeSpanOverrunMode\":\"Wrap\"}";
    int_T numInputPortsScope2 = 1;
    int_T scope2ID = 2;
    real32_T sampleTimes2[1] = { 0.016 };

    INITIALIZE_PLOT(scope2ID,numInputPortsScope2,mobileScopeProperties2,
                    sampleTimes2);
  }

  /* End of Scope: '<Root>/Data (rad) 2' */
  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 3 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 3 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] = "Torso/To Workspace";
    Torso_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      Torso_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(Torso_M),
      Torso_M->Timing.stepSize0,
      (&rtmGetErrorStatus(Torso_M)),
      "DataTorso",
      0,
      0,
      1,
      0.016,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (Torso_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for Scope: '<Root>/Data (rad) 1' */
  {
    const char* mobileScopeProperties1 =
      "{\"axesColor\":[0,0,0],\"axesScaling\":\"manual\",\"axesTickColor\":[0.686274509803922,0.686274509803922,0.686274509803922],\"blockType\":\"Scope\",\"displays\":[{\"lineColors\":[[1,1,0.0666666666666667],[0.0745098039215686,0.623529411764706,1],[1,0.411764705882353,0.16078431372549],[0.392156862745098,0.831372549019608,0.0745098039215686],[0.717647058823529,0.274509803921569,1],[0.0588235294117647,1,1],[1,0.0745098039215686,0.650980392156863]],\"lineStyles\":[\"-\",\"-\",\"-\",\"-\",\"-\",\"-\",\"-\"],\"lineWidths\":[0.75,0.75,0.75,0.75,0.75,0.75,0.75],\"showGrid\":true,\"showLegend\":false,\"yLimits\":[-0.31808,0.27975]}],\"frameBasedProcessing\":false,\"inputNames\":[\"Gain2\",\"Gain1\",\"Constant\"],\"layoutDimensions\":[1,1],\"timeSpan\":90,\"timeSpanOverrunMode\":\"Wrap\"}";
    int_T numInputPortsScope1 = 1;
    int_T scope1ID = 1;
    real32_T sampleTimes1[1] = { 0.016 };

    INITIALIZE_PLOT(scope1ID,numInputPortsScope1,mobileScopeProperties1,
                    sampleTimes1);
  }

  /* End of Scope: '<Root>/Data (rad) 1' */
  /* SetupRuntimeResources for Scope: '<Root>/Unfiltered Data (rad)  1' */
  {
    const char* mobileScopeProperties4 =
      "{\"axesColor\":[0,0,0],\"axesScaling\":\"manual\",\"axesTickColor\":[0.686274509803922,0.686274509803922,0.686274509803922],\"blockType\":\"Scope\",\"displays\":[{\"lineColors\":[[1,1,0.0666666666666667],[0.0745098039215686,0.623529411764706,1],[1,0.411764705882353,0.16078431372549],[0.392156862745098,0.831372549019608,0.0745098039215686],[0.717647058823529,0.274509803921569,1],[0.0588235294117647,1,1],[1,0.0745098039215686,0.650980392156863]],\"lineStyles\":[\"-\",\"-\",\"-\",\"-\",\"-\",\"-\",\"-\"],\"lineWidths\":[0.75,0.75,0.75,0.75,0.75,0.75,0.75],\"showGrid\":true,\"showLegend\":false,\"yLimits\":[-3.77401,5.80154]}],\"frameBasedProcessing\":false,\"inputNames\":[\"Gyroscope\\/1\",\"Gyroscope\\/2\",\"Gyroscope\\/3\"],\"layoutDimensions\":[1,1],\"timeSpan\":90,\"timeSpanOverrunMode\":\"Wrap\"}";
    int_T numInputPortsScope4 = 1;
    int_T scope4ID = 4;
    real32_T sampleTimes4[1] = { 0.016 };

    INITIALIZE_PLOT(scope4ID,numInputPortsScope4,mobileScopeProperties4,
                    sampleTimes4);
  }

  /* End of Scope: '<Root>/Unfiltered Data (rad)  1' */

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Torso_DW.DiscreteTimeIntegrator1_DSTATE = Torso_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  Torso_DW.DiscreteTimeIntegrator_DSTATE = Torso_P.DiscreteTimeIntegrator_IC;
  Torso_LowpassFilter1_Init(&Torso_DW.LowpassFilter1);
  Torso_LowpassFilter1_Init(&Torso_DW.LowpassFilter2);

  /* Start for MATLABSystem: '<S1>/MATLAB System' */
  Torso_DW.obj.matlabCodegenIsDeleted = false;
  Torso_DW.obj.isInitialized = 1;
  INITIALIZE_GYROSCOPE();
  Torso_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Torso_terminate(void)
{
  Torso_LowpassFilter1_Term(&Torso_DW.LowpassFilter1);
  Torso_LowpassFilter1_Term(&Torso_DW.LowpassFilter2);

  /* Terminate for MATLABSystem: '<S1>/MATLAB System' */
  if (!Torso_DW.obj.matlabCodegenIsDeleted) {
    Torso_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/MATLAB System' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
