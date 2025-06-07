/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel_data.c
 *
 * Code generated for Simulink model 'sads_balance_cubemodel'.
 *
 * Model version                  : 7.173
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sat Jun  7 13:55:19 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sads_balance_cubemodel.h"

/* Block parameters (default storage) */
P_sads_balance_cubemodel_T sads_balance_cubemodel_P = {
  /* Variable: STEPS_PER_REV
   * Referenced by:
   *   '<Root>/#revs to steps'
   *   '<Root>/Gain1'
   */
  3200.0F,

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

  /* Computed Parameter: eulerAngles_Y0
   * Referenced by: '<S5>/eulerAngles'
   */
  0.0F,

  /* Computed Parameter: RollMountingError_Value
   * Referenced by: '<S1>/Roll Mounting Error'
   */
  -1.35F,

  /* Computed Parameter: PitchMountingError_Value
   * Referenced by: '<S1>/Pitch Mounting Error'
   */
  -1.11F,

  /* Computed Parameter: m_mmu_Gain
   * Referenced by: '<S2>/m_mmu'
   */
  2.85F,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S2>/Constant'
   */
  0.0F,

  /* Computed Parameter: q_d_Value
   * Referenced by: '<Root>/q_d'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S1>/Constant'
   */
  0.0F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S4>/Gain1'
   */
  0.0174532924F,

  /* Computed Parameter: u2_Gain
   * Referenced by: '<S6>/1//2'
   */
  0.5F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  -0.5F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<Root>/Gain2'
   */
  5.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.05F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Integral_Gain
   * Referenced by: '<Root>/Integral'
   */
  -0.5F,

  /* Computed Parameter: Derivative_Gain
   * Referenced by: '<Root>/Derivative'
   */
  -0.5F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<Root>/Gain3'
   */
  100.0F,

  /* Computed Parameter: distancetorevs_Gain
   * Referenced by: '<Root>/distance to # revs'
   */
  100.0F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
