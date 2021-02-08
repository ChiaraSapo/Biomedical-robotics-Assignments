/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Torso_types.h
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

#ifndef RTW_HEADER_Torso_types_h_
#define RTW_HEADER_Torso_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_gOYGp865C7WRHfLNH0fDl
#define struct_tag_gOYGp865C7WRHfLNH0fDl

struct tag_gOYGp865C7WRHfLNH0fDl
{
  int32_T S0_isInitialized;
  real32_T W0_states[51];
  real32_T P0_InitialStates;
  real32_T P1_Coefficients[52];
};

#endif                                 /*struct_tag_gOYGp865C7WRHfLNH0fDl*/

#ifndef typedef_b_dsp_FIRFilter_0_Torso_T
#define typedef_b_dsp_FIRFilter_0_Torso_T

typedef struct tag_gOYGp865C7WRHfLNH0fDl b_dsp_FIRFilter_0_Torso_T;

#endif                                 /*typedef_b_dsp_FIRFilter_0_Torso_T*/

#ifndef struct_tag_RZ8iX2wBHyAtWkvs4REWJC
#define struct_tag_RZ8iX2wBHyAtWkvs4REWJC

struct tag_RZ8iX2wBHyAtWkvs4REWJC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_Torso_T cSFunObject;
};

#endif                                 /*struct_tag_RZ8iX2wBHyAtWkvs4REWJC*/

#ifndef typedef_b_dspcodegen_FIRFilter_Torso_T
#define typedef_b_dspcodegen_FIRFilter_Torso_T

typedef struct tag_RZ8iX2wBHyAtWkvs4REWJC b_dspcodegen_FIRFilter_Torso_T;

#endif                                /*typedef_b_dspcodegen_FIRFilter_Torso_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_Torso_T
#define typedef_cell_wrap_Torso_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_Torso_T;

#endif                                 /*typedef_cell_wrap_Torso_T*/

#ifndef struct_tag_lX0Jy3KYsMx6LXJVGZFstD
#define struct_tag_lX0Jy3KYsMx6LXJVGZFstD

struct tag_lX0Jy3KYsMx6LXJVGZFstD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_Torso_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_Torso_T *FilterObj;
  b_dspcodegen_FIRFilter_Torso_T _pobj0;
};

#endif                                 /*struct_tag_lX0Jy3KYsMx6LXJVGZFstD*/

#ifndef typedef_dsp_LowpassFilter_Torso_T
#define typedef_dsp_LowpassFilter_Torso_T

typedef struct tag_lX0Jy3KYsMx6LXJVGZFstD dsp_LowpassFilter_Torso_T;

#endif                                 /*typedef_dsp_LowpassFilter_Torso_T*/

#ifndef struct_tag_vbWD4xgzOzlHh6Jb9sJx9E
#define struct_tag_vbWD4xgzOzlHh6Jb9sJx9E

struct tag_vbWD4xgzOzlHh6Jb9sJx9E
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /*struct_tag_vbWD4xgzOzlHh6Jb9sJx9E*/

#ifndef typedef_codertarget_internal_androidG_T
#define typedef_codertarget_internal_androidG_T

typedef struct tag_vbWD4xgzOzlHh6Jb9sJx9E codertarget_internal_androidG_T;

#endif                               /*typedef_codertarget_internal_androidG_T*/

/* Parameters (default storage) */
typedef struct P_Torso_T_ P_Torso_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Torso_T RT_MODEL_Torso_T;

#endif                                 /* RTW_HEADER_Torso_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
