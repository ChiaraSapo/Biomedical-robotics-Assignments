/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Wrist_data.c
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

#include "Wrist.h"
#include "Wrist_private.h"

/* Block parameters (default storage) */
P_Wrist_T Wrist_P = {
  /* Expression: 0.01
   * Referenced by: '<Root>/Constant'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator4_gainval
   * Referenced by: '<S3>/Discrete-Time Integrator4'
   */
  0.016F,

  /* Computed Parameter: DiscreteTimeIntegrator4_IC
   * Referenced by: '<S3>/Discrete-Time Integrator4'
   */
  0.0F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<Root>/Gain2'
   */
  0.096F,

  /* Computed Parameter: DiscreteTimeIntegrator5_gainval
   * Referenced by: '<S3>/Discrete-Time Integrator5'
   */
  0.016F,

  /* Computed Parameter: DiscreteTimeIntegrator5_IC
   * Referenced by: '<S3>/Discrete-Time Integrator5'
   */
  0.0F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  0.096F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S3>/Gain3'
   */
  1.0F,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S3>/Gain4'
   */
  1.0F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
