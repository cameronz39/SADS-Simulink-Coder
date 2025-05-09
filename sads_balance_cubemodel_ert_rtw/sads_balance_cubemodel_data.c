/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel_data.c
 *
 * Code generated for Simulink model 'sads_balance_cubemodel'.
 *
 * Model version                  : 7.120
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May  6 13:39:33 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sads_balance_cubemodel.h"

/* Block parameters (default storage) */
P_sads_balance_cubemodel_T sads_balance_cubemodel_P = {
  /* Expression: 90
   * Referenced by: '<S4>/Sine Wave'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S4>/Sine Wave'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S4>/Sine Wave'
   */
  50.0,

  /* Expression: 0.1
   * Referenced by: '<S4>/Sine Wave'
   */
  0.1,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant2'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S11>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0.5
   * Referenced by: '<S12>/1//2'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S4>/Sine Wave1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Sine Wave1'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S4>/Sine Wave1'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S4>/Sine Wave1'
   */
  0.0,

  /* Computed Parameter: MID_Value
   * Referenced by: '<Root>/MID'
   */
  1,

  /* Computed Parameter: DATA_Value
   * Referenced by: '<Root>/DATA'
   */
  0,

  /* Computed Parameter: g_body_Y0
   * Referenced by: '<S5>/g_body'
   */
  0.0F,

  /* Computed Parameter: quat_Y0
   * Referenced by: '<S5>/quat'
   */
  0.0F,

  /* Computed Parameter: bodyRates_Y0
   * Referenced by: '<S5>/bodyRates'
   */
  0.0F,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S2>/Constant'
   */
  0.0F,

  /* Computed Parameter: m_mmu_Gain
   * Referenced by: '<S2>/m_mmu'
   */
  2.85F,

  /* Computed Parameter: distancetorevs_Gain
   * Referenced by: '<Root>/distance to # revs'
   */
  100.0F,

  /* Computed Parameter: revstosteps_Gain
   * Referenced by: '<Root>/#revs to steps'
   */
  6400.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<Root>/Gain3'
   */
  100.0F,

  /* Computed Parameter: Gain1_Gain_n
   * Referenced by: '<Root>/Gain1'
   */
  6400.0F,

  /* Computed Parameter: q_d_Value
   * Referenced by: '<Root>/q_d'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  -0.5F,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.00625F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Integral_Gain
   * Referenced by: '<Root>/Integral'
   */
  -0.5F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
