/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Torso_private.h
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

#ifndef RTW_HEADER_Torso_private_h_
#define RTW_HEADER_Torso_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "Torso.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void Torso_LowpassFilter1_Init(DW_LowpassFilter1_Torso_T *localDW);
extern void Torso_LowpassFilter1(real32_T rtu_0, B_LowpassFilter1_Torso_T
  *localB, DW_LowpassFilter1_Torso_T *localDW);
extern void Torso_LowpassFilter1_Term(DW_LowpassFilter1_Torso_T *localDW);

#endif                                 /* RTW_HEADER_Torso_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
