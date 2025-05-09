/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel.c
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
#include "sads_balance_cubemodel_types.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <stddef.h>
#include "mw_stm32_i2c_ll.h"
#include "sads_balance_cubemodel_private.h"

/* Block signals (default storage) */
B_sads_balance_cubemodel_T sads_balance_cubemodel_B;

/* Block states (default storage) */
DW_sads_balance_cubemodel_T sads_balance_cubemodel_DW;

/* Real-time model */
static RT_MODEL_sads_balance_cubemod_T sads_balance_cubemodel_M_;
RT_MODEL_sads_balance_cubemod_T *const sads_balance_cubemodel_M =
  &sads_balance_cubemodel_M_;

/* Forward declaration for local functions */
static void sads_balance_c_SystemCore_setup(stm32cube_blocks_I2CControl_f_T *obj);
static void sads_bala_I2CDrvBlock_setupImpl(stm32cube_blocks_I2CControlle_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void sads_balance_cubemodel_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(sads_balance_cubemodel_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  sads_balance_cubemodel_M->Timing.RateInteraction.TID0_1 =
    (sads_balance_cubemodel_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (sads_balance_cubemodel_M->Timing.TaskCounters.TID[1])++;
  if ((sads_balance_cubemodel_M->Timing.TaskCounters.TID[1]) > 7) {/* Sample time: [0.1s, 0.0s] */
    sads_balance_cubemodel_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void sads_balance_c_SystemCore_setup(stm32cube_blocks_I2CControl_f_T *obj)
{
  STM32_I2C_Struct_T * i2cBlockStruct_loc;
  STM32_I2C_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S1>/Check Pipe Status' incorporates:
   *  MATLABSystem: '<S5>/I2C Controller Read2'
   */
  obj->isInitialized = 1;
  c.instance = I2C1;
  c.txCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  c.rxCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  obj->MW_I2C_BlockStruct.h_i2c = NULL;
  obj->MW_I2C_BlockStruct.rxBufferStructPtr = NULL;
  obj->MW_I2C_BlockStruct.txBufferStructPtr = NULL;
  i2cBlockStruct_loc = (STM32_I2C_Struct_T *)(&obj->MW_I2C_BlockStruct);
  obj->MW_I2C_HANDLE = I2C_Init(&c, i2cBlockStruct_loc);
  obj->isSetupComplete = true;
}

static void sads_bala_I2CDrvBlock_setupImpl(stm32cube_blocks_I2CControlle_T *obj)
{
  STM32_I2C_Struct_T * i2cBlockStruct_loc;
  STM32_I2C_ModuleStruct_T c;

  /* Start for MATLABSystem: '<Root>/I2C Controller Write' */
  c.instance = I2C2;
  c.txCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  c.rxCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  obj->MW_I2C_BlockStruct.h_i2c = NULL;
  obj->MW_I2C_BlockStruct.rxBufferStructPtr = NULL;
  obj->MW_I2C_BlockStruct.txBufferStructPtr = NULL;
  i2cBlockStruct_loc = (STM32_I2C_Struct_T *)(&obj->MW_I2C_BlockStruct);
  obj->MW_I2C_HANDLE = I2C_Init(&c, i2cBlockStruct_loc);
}

/* Model step function for TID0 */
void sads_balance_cubemodel_step0(void) /* Sample time: [0.0125s, 0.0s] */
{
  real_T CastToSingle1_tmp;
  real_T CastToSingle1_tmp_0;
  real_T rtb_sincos_o1_idx_0;
  real_T rtb_sincos_o1_idx_1;
  real_T rtb_sincos_o1_idx_2;
  real_T rtb_sincos_o2_idx_0;
  real_T rtb_sincos_o2_idx_1;
  real_T rtb_sincos_o2_idx_2;
  int32_T rtb_TmpSignalConversionAtI2CCon[4];
  int32_T i;
  real32_T DiscreteTimeIntegrator_idx_0;
  real32_T DiscreteTimeIntegrator_idx_0_tm;
  real32_T DiscreteTimeIntegrator_idx_1;
  real32_T DiscreteTimeIntegrator_idx_1_tm;
  real32_T DiscreteTimeIntegrator_idx_2;
  real32_T DiscreteTimeIntegrator_idx_2_tm;
  real32_T rtb_Sum_g;
  real32_T rtb_Sum_m;
  real32_T rtb_m_mmu;
  uint32_T status;
  uint8_T b_bytesIn[76];
  uint8_T SwappedDataBytes[17];
  uint8_T txDataSwapLoc[16];
  uint8_T txData;

  {                                    /* Sample time: [0.0125s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(sads_balance_cubemodel_DW.ReadIncomingDataifdataavailable);

  /* MATLABSystem: '<S1>/Check Pipe Status' */
  txData = 4U;
  status = I2C_Controller_TransmitData_Polling
    (sads_balance_cubemodel_DW.obj_l.MW_I2C_HANDLE, 107, &txData, 1U, true, true,
     1U);
  if (status == 0U) {
    I2C_Controller_ReceiveData_Polling
      (sads_balance_cubemodel_DW.obj_l.MW_I2C_HANDLE, 107,
       &sads_balance_cubemodel_B.CheckPipeStatus_o1[0], 4U, false, false, 1U);
  } else {
    /* MATLABSystem: '<S1>/Check Pipe Status' */
    sads_balance_cubemodel_B.CheckPipeStatus_o1[0] = 0U;
    sads_balance_cubemodel_B.CheckPipeStatus_o1[1] = 0U;
    sads_balance_cubemodel_B.CheckPipeStatus_o1[2] = 0U;
    sads_balance_cubemodel_B.CheckPipeStatus_o1[3] = 0U;
  }

  /* End of MATLABSystem: '<S1>/Check Pipe Status' */

  /* Outputs for Enabled SubSystem: '<S1>/Read Incoming Data if data available' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (sads_balance_cubemodel_B.CheckPipeStatus_o1[2] > 0) {
    /* MATLABSystem: '<S5>/I2C Controller Read2' incorporates:
     *  MATLABSystem: '<S5>/MTi Driver'
     */
    txData = 6U;
    status = I2C_Controller_TransmitData_Polling
      (sads_balance_cubemodel_DW.obj_g.MW_I2C_HANDLE, 107, &txData, 1U, true,
       true, 1U);
    if (status == 0U) {
      I2C_Controller_ReceiveData_Polling
        (sads_balance_cubemodel_DW.obj_g.MW_I2C_HANDLE, 107, &b_bytesIn[0], 76U,
         false, false, 1U);
    } else {
      /* MATLABSystem: '<S5>/MTi Driver' */
      memset(&b_bytesIn[0], 0, 76U * sizeof(uint8_T));
    }

    /* End of MATLABSystem: '<S5>/I2C Controller Read2' */

    /* MATLABSystem: '<S5>/MTi Driver' */
    /*         %% Define input properties */
    sads_balance_cubemodel_B.MTiDriver_o1[0] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o1[1] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o1[2] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o2[0] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o2[1] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o2[2] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o2[3] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o3[0] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o3[1] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o3[2] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o4 = 0U;

    /*  Call C-function implementing device output */
    MTi_Driver_Step(&b_bytesIn[0], &sads_balance_cubemodel_B.MTiDriver_o1[0],
                    &sads_balance_cubemodel_B.MTiDriver_o2[0],
                    &sads_balance_cubemodel_B.MTiDriver_o3[0],
                    &sads_balance_cubemodel_B.MTiDriver_o4);
    srUpdateBC(sads_balance_cubemodel_DW.ReadIncomingDataifdataavailable);
  }

  /* End of Outputs for SubSystem: '<S1>/Read Incoming Data if data available' */
  /* Gain: '<S2>/m_mmu' incorporates:
   *  DotProduct: '<S2>/Dot Product'
   *  MATLABSystem: '<S5>/MTi Driver'
   */
  rtb_m_mmu = ((sads_balance_cubemodel_B.MTiDriver_o1[0] *
                sads_balance_cubemodel_B.MTiDriver_o1[0] +
                sads_balance_cubemodel_B.MTiDriver_o1[1] *
                sads_balance_cubemodel_B.MTiDriver_o1[1]) +
               sads_balance_cubemodel_B.MTiDriver_o1[2] *
               sads_balance_cubemodel_B.MTiDriver_o1[2]) *
    sads_balance_cubemodel_P.m_mmu_Gain;

  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<S2>/Constant'
   *  Product: '<S6>/Element Product'
   *  Sum: '<S6>/Sum'
   */
  sads_balance_cubemodel_B.Divide[0] = (sads_balance_cubemodel_B.MTiDriver_o1[1]
    * sads_balance_cubemodel_P.Constant_Value -
    sads_balance_cubemodel_B.MTiDriver_o1[2] * 0.0F) * (1.0F / rtb_m_mmu);
  sads_balance_cubemodel_B.Divide[1] = (sads_balance_cubemodel_B.MTiDriver_o1[2]
    * 0.0F - sads_balance_cubemodel_B.MTiDriver_o1[0] *
    sads_balance_cubemodel_P.Constant_Value) * (1.0F / rtb_m_mmu);
  sads_balance_cubemodel_B.Divide[2] = (sads_balance_cubemodel_B.MTiDriver_o1[0]
    * 0.0F - sads_balance_cubemodel_B.MTiDriver_o1[1] * 0.0F) * (1.0F /
    rtb_m_mmu);

  /* DataTypeConversion: '<Root>/Cast to int32' incorporates:
   *  Gain: '<Root>/#revs to steps'
   *  Gain: '<Root>/distance to # revs'
   */
  rtb_m_mmu = (real32_T)floor(sads_balance_cubemodel_P.distancetorevs_Gain *
    sads_balance_cubemodel_B.Divide[0] *
    sads_balance_cubemodel_P.revstosteps_Gain);
  if (rtIsNaNF(rtb_m_mmu) || rtIsInfF(rtb_m_mmu)) {
    rtb_m_mmu = 0.0F;
  } else {
    rtb_m_mmu = (real32_T)fmod(rtb_m_mmu, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Cast to int32' */
  sads_balance_cubemodel_B.DesiredPositionX = rtb_m_mmu < 0.0F ? -(int32_T)
    (uint32_T)-rtb_m_mmu : (int32_T)(uint32_T)rtb_m_mmu;

  /* DataTypeConversion: '<Root>/Cast' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain3'
   */
  rtb_m_mmu = (real32_T)floor(sads_balance_cubemodel_P.Gain3_Gain *
    sads_balance_cubemodel_B.Divide[1] * sads_balance_cubemodel_P.Gain1_Gain_n);
  if (rtIsNaNF(rtb_m_mmu) || rtIsInfF(rtb_m_mmu)) {
    rtb_m_mmu = 0.0F;
  } else {
    rtb_m_mmu = (real32_T)fmod(rtb_m_mmu, 4.294967296E+9);
  }

  /* DataTypeConversion: '<Root>/Cast' */
  sads_balance_cubemodel_B.DesiredPositionY = rtb_m_mmu < 0.0F ? -(int32_T)
    (uint32_T)-rtb_m_mmu : (int32_T)(uint32_T)rtb_m_mmu;

  /* SignalConversion generated from: '<Root>/I2C Controller Write' incorporates:
   *  Constant: '<Root>/DATA'
   *  Constant: '<Root>/MID'
   */
  rtb_TmpSignalConversionAtI2CCon[0] = sads_balance_cubemodel_B.DesiredPositionX;
  rtb_TmpSignalConversionAtI2CCon[1] = sads_balance_cubemodel_B.DesiredPositionY;
  rtb_TmpSignalConversionAtI2CCon[2] = sads_balance_cubemodel_P.MID_Value;
  rtb_TmpSignalConversionAtI2CCon[3] = sads_balance_cubemodel_P.DATA_Value;

  /* MATLABSystem: '<Root>/I2C Controller Write' */
  memcpy((void *)&txDataSwapLoc[0], (void *)&rtb_TmpSignalConversionAtI2CCon[0],
         (size_t)16 * sizeof(uint8_T));
  SwappedDataBytes[0] = 0U;
  for (i = 0; i < 16; i++) {
    SwappedDataBytes[i + 1] = txDataSwapLoc[i];
  }

  /* MATLABSystem: '<Root>/I2C Controller Write' */
  sads_balance_cubemodel_B.I2CControllerWrite =
    I2C_Controller_TransmitData_Polling
    (sads_balance_cubemodel_DW.obj.MW_I2C_HANDLE, 66, &SwappedDataBytes[0], 17U,
     false, false, 100U);

  /* RateTransition generated from: '<S4>/Sine Wave1' */
  if (sads_balance_cubemodel_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S4>/Sine Wave1' */
    sads_balance_cubemodel_B.TmpRTBAtSineWave1Outport1 =
      sads_balance_cubemodel_DW.TmpRTBAtSineWave1Outport1_Buffe;
  }

  /* End of RateTransition generated from: '<S4>/Sine Wave1' */

  /* Gain: '<S12>/1//2' incorporates:
   *  Gain: '<S11>/Gain1'
   *  Sin: '<S4>/Sine Wave'
   */
  rtb_sincos_o2_idx_2 = (sin(((real_T)sads_balance_cubemodel_DW.counter +
    sads_balance_cubemodel_P.SineWave_Offset) * 2.0 * 3.1415926535897931 /
    sads_balance_cubemodel_P.SineWave_NumSamp) *
    sads_balance_cubemodel_P.SineWave_Amp +
    sads_balance_cubemodel_P.SineWave_Bias) *
    sads_balance_cubemodel_P.Gain1_Gain * sads_balance_cubemodel_P.u2_Gain;

  /* Trigonometry: '<S12>/sincos' */
  rtb_sincos_o1_idx_0 = sin(rtb_sincos_o2_idx_2);
  rtb_sincos_o2_idx_0 = cos(rtb_sincos_o2_idx_2);

  /* Gain: '<S12>/1//2' incorporates:
   *  Gain: '<S11>/Gain1'
   */
  rtb_sincos_o2_idx_2 = sads_balance_cubemodel_P.Gain1_Gain *
    sads_balance_cubemodel_B.TmpRTBAtSineWave1Outport1 *
    sads_balance_cubemodel_P.u2_Gain;

  /* Trigonometry: '<S12>/sincos' */
  rtb_sincos_o1_idx_1 = sin(rtb_sincos_o2_idx_2);
  rtb_sincos_o2_idx_1 = cos(rtb_sincos_o2_idx_2);

  /* Gain: '<S12>/1//2' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Gain: '<S11>/Gain1'
   */
  rtb_sincos_o2_idx_2 = sads_balance_cubemodel_P.Gain1_Gain *
    sads_balance_cubemodel_P.Constant2_Value * sads_balance_cubemodel_P.u2_Gain;

  /* Trigonometry: '<S12>/sincos' */
  rtb_sincos_o1_idx_2 = sin(rtb_sincos_o2_idx_2);
  rtb_sincos_o2_idx_2 = cos(rtb_sincos_o2_idx_2);

  /* Fcn: '<S12>/q0' incorporates:
   *  Fcn: '<S12>/q3'
   */
  CastToSingle1_tmp = rtb_sincos_o2_idx_0 * rtb_sincos_o2_idx_1;
  CastToSingle1_tmp_0 = rtb_sincos_o1_idx_0 * rtb_sincos_o1_idx_1;

  /* DataTypeConversion: '<S4>/Cast To Single1' incorporates:
   *  Fcn: '<S12>/q0'
   */
  sads_balance_cubemodel_B.CastToSingle1[0] = (real32_T)(CastToSingle1_tmp *
    rtb_sincos_o2_idx_2 - CastToSingle1_tmp_0 * rtb_sincos_o1_idx_2);

  /* Fcn: '<S12>/q1' incorporates:
   *  Fcn: '<S12>/q2'
   */
  rtb_sincos_o2_idx_0 *= rtb_sincos_o1_idx_1;
  rtb_sincos_o1_idx_0 *= rtb_sincos_o2_idx_1;

  /* DataTypeConversion: '<S4>/Cast To Single1' incorporates:
   *  Fcn: '<S12>/q1'
   *  Fcn: '<S12>/q2'
   *  Fcn: '<S12>/q3'
   */
  sads_balance_cubemodel_B.CastToSingle1[1] = (real32_T)(rtb_sincos_o2_idx_0 *
    rtb_sincos_o1_idx_2 + rtb_sincos_o1_idx_0 * rtb_sincos_o2_idx_2);
  sads_balance_cubemodel_B.CastToSingle1[2] = (real32_T)(rtb_sincos_o2_idx_0 *
    rtb_sincos_o2_idx_2 - rtb_sincos_o1_idx_0 * rtb_sincos_o1_idx_2);
  sads_balance_cubemodel_B.CastToSingle1[3] = (real32_T)(CastToSingle1_tmp *
    rtb_sincos_o1_idx_2 + CastToSingle1_tmp_0 * rtb_sincos_o2_idx_2);

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<Root>/q_d'
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product1'
   *  Product: '<S8>/Product2'
   *  Product: '<S8>/Product3'
   */
  rtb_m_mmu = ((sads_balance_cubemodel_B.CastToSingle1[0] *
                sads_balance_cubemodel_P.q_d_Value[1] +
                sads_balance_cubemodel_P.q_d_Value[0] *
                sads_balance_cubemodel_B.CastToSingle1[1]) +
               sads_balance_cubemodel_B.CastToSingle1[2] *
               sads_balance_cubemodel_P.q_d_Value[3]) -
    sads_balance_cubemodel_P.q_d_Value[2] *
    sads_balance_cubemodel_B.CastToSingle1[3];

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<Root>/q_d'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Product: '<S9>/Product2'
   *  Product: '<S9>/Product3'
   */
  rtb_Sum_m = ((sads_balance_cubemodel_B.CastToSingle1[0] *
                sads_balance_cubemodel_P.q_d_Value[2] -
                sads_balance_cubemodel_B.CastToSingle1[1] *
                sads_balance_cubemodel_P.q_d_Value[3]) +
               sads_balance_cubemodel_P.q_d_Value[0] *
               sads_balance_cubemodel_B.CastToSingle1[2]) +
    sads_balance_cubemodel_P.q_d_Value[1] *
    sads_balance_cubemodel_B.CastToSingle1[3];

  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<Root>/q_d'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/Product2'
   *  Product: '<S10>/Product3'
   */
  rtb_Sum_g = ((sads_balance_cubemodel_B.CastToSingle1[0] *
                sads_balance_cubemodel_P.q_d_Value[3] +
                sads_balance_cubemodel_B.CastToSingle1[1] *
                sads_balance_cubemodel_P.q_d_Value[2]) -
               sads_balance_cubemodel_P.q_d_Value[1] *
               sads_balance_cubemodel_B.CastToSingle1[2]) +
    sads_balance_cubemodel_P.q_d_Value[0] *
    sads_balance_cubemodel_B.CastToSingle1[3];

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  DiscreteTimeIntegrator_idx_0_tm =
    sads_balance_cubemodel_P.DiscreteTimeIntegrator_gainval * rtb_m_mmu;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  DiscreteTimeIntegrator_idx_0 = DiscreteTimeIntegrator_idx_0_tm +
    sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  DiscreteTimeIntegrator_idx_1_tm =
    sads_balance_cubemodel_P.DiscreteTimeIntegrator_gainval * rtb_Sum_m;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  DiscreteTimeIntegrator_idx_1 = DiscreteTimeIntegrator_idx_1_tm +
    sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  DiscreteTimeIntegrator_idx_2_tm =
    sads_balance_cubemodel_P.DiscreteTimeIntegrator_gainval * rtb_Sum_g;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  DiscreteTimeIntegrator_idx_2 = DiscreteTimeIntegrator_idx_2_tm +
    sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[2];

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Integral'
   */
  sads_balance_cubemodel_B.PID_output[0] = sads_balance_cubemodel_P.Gain_Gain *
    rtb_m_mmu + sads_balance_cubemodel_P.Integral_Gain *
    DiscreteTimeIntegrator_idx_0;
  sads_balance_cubemodel_B.PID_output[1] = sads_balance_cubemodel_P.Gain_Gain *
    rtb_Sum_m + sads_balance_cubemodel_P.Integral_Gain *
    DiscreteTimeIntegrator_idx_1;
  sads_balance_cubemodel_B.PID_output[2] = sads_balance_cubemodel_P.Gain_Gain *
    rtb_Sum_g + sads_balance_cubemodel_P.Integral_Gain *
    DiscreteTimeIntegrator_idx_2;

  /* Update for Sin: '<S4>/Sine Wave' */
  sads_balance_cubemodel_DW.counter++;
  if (sads_balance_cubemodel_DW.counter ==
      sads_balance_cubemodel_P.SineWave_NumSamp) {
    sads_balance_cubemodel_DW.counter = 0;
  }

  /* End of Update for Sin: '<S4>/Sine Wave' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[0] =
    DiscreteTimeIntegrator_idx_0_tm + DiscreteTimeIntegrator_idx_0;
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[1] =
    DiscreteTimeIntegrator_idx_1_tm + DiscreteTimeIntegrator_idx_1;
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[2] =
    DiscreteTimeIntegrator_idx_2_tm + DiscreteTimeIntegrator_idx_2;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  sads_balance_cubemodel_M->Timing.taskTime0 =
    ((time_T)(++sads_balance_cubemodel_M->Timing.clockTick0)) *
    sads_balance_cubemodel_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void sads_balance_cubemodel_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_SineWave1;

  /* Sin: '<S4>/Sine Wave1' */
  rtb_SineWave1 = sin(((real_T)sads_balance_cubemodel_DW.counter_c +
                       sads_balance_cubemodel_P.SineWave1_Offset) * 2.0 *
                      3.1415926535897931 /
                      sads_balance_cubemodel_P.SineWave1_NumSamp) *
    sads_balance_cubemodel_P.SineWave1_Amp +
    sads_balance_cubemodel_P.SineWave1_Bias;

  /* RateTransition generated from: '<S4>/Sine Wave1' */
  sads_balance_cubemodel_DW.TmpRTBAtSineWave1Outport1_Buffe = rtb_SineWave1;

  /* Update for Sin: '<S4>/Sine Wave1' */
  sads_balance_cubemodel_DW.counter_c++;
  if (sads_balance_cubemodel_DW.counter_c ==
      sads_balance_cubemodel_P.SineWave1_NumSamp) {
    sads_balance_cubemodel_DW.counter_c = 0;
  }

  /* End of Update for Sin: '<S4>/Sine Wave1' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  sads_balance_cubemodel_M->Timing.clockTick1++;
}

/* Model initialize function */
void sads_balance_cubemodel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(sads_balance_cubemodel_M, 1.0);
  sads_balance_cubemodel_M->Timing.stepSize0 = 0.0125;

  /* External mode info */
  sads_balance_cubemodel_M->Sizes.checksums[0] = (141820174U);
  sads_balance_cubemodel_M->Sizes.checksums[1] = (3489915465U);
  sads_balance_cubemodel_M->Sizes.checksums[2] = (1174087572U);
  sads_balance_cubemodel_M->Sizes.checksums[3] = (2115115653U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    sads_balance_cubemodel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &sads_balance_cubemodel_DW.ReadIncomingDataifdataavailable;
    systemRan[4] = (sysRanDType *)
      &sads_balance_cubemodel_DW.ReadIncomingDataifdataavailable;
    systemRan[5] = (sysRanDType *)
      &sads_balance_cubemodel_DW.ReadIncomingDataifdataavailable;
    rteiSetModelMappingInfoPtr(sads_balance_cubemodel_M->extModeInfo,
      &sads_balance_cubemodel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sads_balance_cubemodel_M->extModeInfo,
                        sads_balance_cubemodel_M->Sizes.checksums);
    rteiSetTPtr(sads_balance_cubemodel_M->extModeInfo, rtmGetTPtr
                (sads_balance_cubemodel_M));
  }

  /* Start for RateTransition generated from: '<S4>/Sine Wave1' */
  sads_balance_cubemodel_B.TmpRTBAtSineWave1Outport1 =
    sads_balance_cubemodel_P.TmpRTBAtSineWave1Outport1_Initi;

  /* InitializeConditions for RateTransition generated from: '<S4>/Sine Wave1' */
  sads_balance_cubemodel_DW.TmpRTBAtSineWave1Outport1_Buffe =
    sads_balance_cubemodel_P.TmpRTBAtSineWave1Outport1_Initi;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[0] =
    sads_balance_cubemodel_P.DiscreteTimeIntegrator_IC[0];
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[1] =
    sads_balance_cubemodel_P.DiscreteTimeIntegrator_IC[1];
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[2] =
    sads_balance_cubemodel_P.DiscreteTimeIntegrator_IC[2];

  /* Start for MATLABSystem: '<S5>/I2C Controller Read2' */
  sads_balance_cubemodel_DW.obj_g.isInitialized = 0;
  sads_balance_cubemodel_DW.obj_g.matlabCodegenIsDeleted = false;
  sads_balance_c_SystemCore_setup(&sads_balance_cubemodel_DW.obj_g);

  /* Start for MATLABSystem: '<S5>/MTi Driver' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted = false;
  sads_balance_cubemodel_DW.obj_m.isInitialized = 1;

  /*         %% Define input properties */
  /*  Call C-function implementing device initialization */
  MTi_Driver_Init();
  sads_balance_cubemodel_DW.obj_m.isSetupComplete = true;

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/g_body'
   */
  sads_balance_cubemodel_B.MTiDriver_o1[0] = sads_balance_cubemodel_P.g_body_Y0;
  sads_balance_cubemodel_B.MTiDriver_o1[1] = sads_balance_cubemodel_P.g_body_Y0;
  sads_balance_cubemodel_B.MTiDriver_o1[2] = sads_balance_cubemodel_P.g_body_Y0;

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/quat'
   */
  sads_balance_cubemodel_B.MTiDriver_o2[0] = sads_balance_cubemodel_P.quat_Y0;
  sads_balance_cubemodel_B.MTiDriver_o2[1] = sads_balance_cubemodel_P.quat_Y0;
  sads_balance_cubemodel_B.MTiDriver_o2[2] = sads_balance_cubemodel_P.quat_Y0;
  sads_balance_cubemodel_B.MTiDriver_o2[3] = sads_balance_cubemodel_P.quat_Y0;

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/bodyRates'
   */
  sads_balance_cubemodel_B.MTiDriver_o3[0] =
    sads_balance_cubemodel_P.bodyRates_Y0;
  sads_balance_cubemodel_B.MTiDriver_o3[1] =
    sads_balance_cubemodel_P.bodyRates_Y0;
  sads_balance_cubemodel_B.MTiDriver_o3[2] =
    sads_balance_cubemodel_P.bodyRates_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Read Incoming Data if data available' */

  /* Start for MATLABSystem: '<S1>/Check Pipe Status' */
  sads_balance_cubemodel_DW.obj_l.isInitialized = 0;
  sads_balance_cubemodel_DW.obj_l.matlabCodegenIsDeleted = false;
  sads_balance_c_SystemCore_setup(&sads_balance_cubemodel_DW.obj_l);

  /* Start for MATLABSystem: '<Root>/I2C Controller Write' */
  sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted = false;
  sads_balance_cubemodel_DW.obj.isSetupComplete = false;
  sads_balance_cubemodel_DW.obj.isInitialized = 1;
  sads_bala_I2CDrvBlock_setupImpl(&sads_balance_cubemodel_DW.obj);
  sads_balance_cubemodel_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void sads_balance_cubemodel_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Check Pipe Status' */
  if (!sads_balance_cubemodel_DW.obj_l.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Check Pipe Status' */

  /* Terminate for Enabled SubSystem: '<S1>/Read Incoming Data if data available' */
  /* Terminate for MATLABSystem: '<S5>/I2C Controller Read2' */
  if (!sads_balance_cubemodel_DW.obj_g.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/I2C Controller Read2' */

  /* Terminate for MATLABSystem: '<S5>/MTi Driver' */
  if (!sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/MTi Driver' */
  /* Terminate for MATLABSystem: '<Root>/I2C Controller Write' */
  if (!sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/I2C Controller Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
