/*
 * Torso_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torso".
 *
 * Model version              : 1.19
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Feb  8 19:05:20 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(codertarget_internal_androidG_T),
  sizeof(dsp_LowpassFilter_Torso_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "codertarget_internal_androidG_T",
  "dsp_LowpassFilter_Torso_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Torso_B.Gain2), 0, 0, 6 },

  { (char_T *)(&Torso_B.TmpSignalConversionAtToWorkspac[0]), 1, 0, 6 },

  { (char_T *)(&Torso_B.LowpassFilter2.LowpassFilter1), 1, 0, 1 },

  { (char_T *)(&Torso_B.LowpassFilter1.LowpassFilter1), 1, 0, 1 }
  ,

  { (char_T *)(&Torso_DW.obj), 14, 0, 1 },

  { (char_T *)(&Torso_DW.FilteredDatarad_PWORK.LoggedData), 11, 0, 11 },

  { (char_T *)(&Torso_DW.DiscreteTimeIntegrator1_DSTATE), 1, 0, 2 },

  { (char_T *)(&Torso_DW.LowpassFilter2.obj), 15, 0, 1 },

  { (char_T *)(&Torso_DW.LowpassFilter2.objisempty), 8, 0, 2 },

  { (char_T *)(&Torso_DW.LowpassFilter1.obj), 15, 0, 1 },

  { (char_T *)(&Torso_DW.LowpassFilter1.objisempty), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Torso_P.Constant_Value), 0, 0, 1 },

  { (char_T *)(&Torso_P.DiscreteTimeIntegrator1_gainval), 1, 0, 6 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] Torso_dt.h */
