/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Wrist_types.h
 *
 * Code generated for Simulink model 'Wrist'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Feb  8 18:48:42 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Wrist_types_h_
#define RTW_HEADER_Wrist_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_kNr580oAvktpq4durSNhwG
#define struct_tag_kNr580oAvktpq4durSNhwG

struct tag_kNr580oAvktpq4durSNhwG
{
  int32_T S0_isInitialized;
  real32_T W0_states[53];
  real32_T P0_InitialStates;
  real32_T P1_Coefficients[54];
};

#endif                                 /*struct_tag_kNr580oAvktpq4durSNhwG*/

#ifndef typedef_b_dsp_FIRFilter_0_Wrist_T
#define typedef_b_dsp_FIRFilter_0_Wrist_T

typedef struct tag_kNr580oAvktpq4durSNhwG b_dsp_FIRFilter_0_Wrist_T;

#endif                                 /*typedef_b_dsp_FIRFilter_0_Wrist_T*/

#ifndef struct_tag_T2y1ra2gWjGiv7mMd80wCF
#define struct_tag_T2y1ra2gWjGiv7mMd80wCF

struct tag_T2y1ra2gWjGiv7mMd80wCF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_Wrist_T cSFunObject;
};

#endif                                 /*struct_tag_T2y1ra2gWjGiv7mMd80wCF*/

#ifndef typedef_b_dspcodegen_FIRFilter_Wrist_T
#define typedef_b_dspcodegen_FIRFilter_Wrist_T

typedef struct tag_T2y1ra2gWjGiv7mMd80wCF b_dspcodegen_FIRFilter_Wrist_T;

#endif                                /*typedef_b_dspcodegen_FIRFilter_Wrist_T*/

#ifndef struct_tag_85JHXFNpe6qZAV50lt4pM
#define struct_tag_85JHXFNpe6qZAV50lt4pM

struct tag_85JHXFNpe6qZAV50lt4pM
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_Wrist_T *FilterObj;
  b_dspcodegen_FIRFilter_Wrist_T _pobj0;
};

#endif                                 /*struct_tag_85JHXFNpe6qZAV50lt4pM*/

#ifndef typedef_dsp_LowpassFilter_Wrist_T
#define typedef_dsp_LowpassFilter_Wrist_T

typedef struct tag_85JHXFNpe6qZAV50lt4pM dsp_LowpassFilter_Wrist_T;

#endif                                 /*typedef_dsp_LowpassFilter_Wrist_T*/

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
typedef struct P_Wrist_T_ P_Wrist_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Wrist_T RT_MODEL_Wrist_T;

#endif                                 /* RTW_HEADER_Wrist_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
