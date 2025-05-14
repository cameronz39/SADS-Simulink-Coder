/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel.c
 *
 * Code generated for Simulink model 'sads_balance_cubemodel'.
 *
 * Model version                  : 7.151
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May 13 13:47:34 2025
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
static void sads_balance_c_SystemCore_setup(stm32cube_blocks_I2CControl_f_T *obj)
{
  STM32_I2C_Struct_T * i2cBlockStruct_loc;
  STM32_I2C_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S1>/Check Pipe Status' incorporates:
   *  MATLABSystem: '<S6>/I2C Controller Read2'
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

  /* Start for MATLABSystem: '<Root>/I2C Controller Write' incorporates:
   *  MATLABSystem: '<S2>/I2C Controller Write1'
   */
  c.instance = I2C2;
  c.txCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  c.rxCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  obj->MW_I2C_BlockStruct.h_i2c = NULL;
  obj->MW_I2C_BlockStruct.rxBufferStructPtr = NULL;
  obj->MW_I2C_BlockStruct.txBufferStructPtr = NULL;
  i2cBlockStruct_loc = (STM32_I2C_Struct_T *)(&obj->MW_I2C_BlockStruct);
  obj->MW_I2C_HANDLE = I2C_Init(&c, i2cBlockStruct_loc);
}

/* Model step function */
void sads_balance_cubemodel_step(void)
{
  int32_T rtb_TmpSignalConversionAtI2CCon[4];
  int32_T i;
  real32_T tmp[4];
  real32_T rtb_Derivative_idx_0;
  real32_T rtb_Derivative_idx_1;
  real32_T rtb_Derivative_idx_2;
  real32_T rtb_Divide_idx_0;
  real32_T rtb_Divide_idx_1;
  real32_T rtb_Divide_idx_2;
  real32_T rtb_Sum_k;
  real32_T rtb_Sum_ll_tmp;
  real32_T rtb_Sum_ll_tmp_0;
  uint32_T status;
  uint16_T b_varargout_5;
  uint8_T b_bytesIn[91];
  uint8_T SwappedDataBytes[17];
  uint8_T txDataSwapLoc[16];
  uint8_T rtb_CheckPipeStatus_o1_0[4];
  uint8_T txData;

  /* MATLABSystem: '<S1>/Check Pipe Status' */
  txData = 4U;
  status = I2C_Controller_TransmitData_Polling
    (sads_balance_cubemodel_DW.obj_l.MW_I2C_HANDLE, 107, &txData, 1U, true, true,
     1U);
  if (status == 0U) {
    I2C_Controller_ReceiveData_Polling
      (sads_balance_cubemodel_DW.obj_l.MW_I2C_HANDLE, 107,
       &rtb_CheckPipeStatus_o1_0[0], 4U, false, false, 1U);
  } else {
    rtb_CheckPipeStatus_o1_0[2] = 0U;
  }

  /* Outputs for Enabled SubSystem: '<S1>/Read Incoming Data if data available' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtb_CheckPipeStatus_o1_0[2] > 0) {
    /* MATLABSystem: '<S6>/I2C Controller Read2' incorporates:
     *  MATLABSystem: '<S6>/MTi Driver'
     */
    txData = 6U;
    status = I2C_Controller_TransmitData_Polling
      (sads_balance_cubemodel_DW.obj_g.MW_I2C_HANDLE, 107, &txData, 1U, true,
       true, 1U);
    if (status == 0U) {
      I2C_Controller_ReceiveData_Polling
        (sads_balance_cubemodel_DW.obj_g.MW_I2C_HANDLE, 107, &b_bytesIn[0], 91U,
         false, false, 1U);
    } else {
      /* MATLABSystem: '<S6>/MTi Driver' */
      memset(&b_bytesIn[0], 0, 91U * sizeof(uint8_T));
    }

    /* End of MATLABSystem: '<S6>/I2C Controller Read2' */

    /* MATLABSystem: '<S6>/MTi Driver' */
    /*         %% Define input properties */
    sads_balance_cubemodel_B.MTiDriver_o1[0] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o1[1] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o1[2] = 0.0F;

    /* MATLABSystem: '<S6>/MTi Driver' */
    tmp[0] = 0.0F;
    tmp[1] = 0.0F;
    tmp[2] = 0.0F;
    tmp[3] = 0.0F;

    /* MATLABSystem: '<S6>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o3[0] = 0.0F;

    /* MATLABSystem: '<S6>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o4[0] = 0.0F;

    /* MATLABSystem: '<S6>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o3[1] = 0.0F;

    /* MATLABSystem: '<S6>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o4[1] = 0.0F;

    /* MATLABSystem: '<S6>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o3[2] = 0.0F;

    /* MATLABSystem: '<S6>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o4[2] = 0.0F;

    /* MATLABSystem: '<S6>/MTi Driver' */
    b_varargout_5 = 0U;

    /*  Call C-function implementing device output */
    MTi_Driver_Step(&b_bytesIn[0], &sads_balance_cubemodel_B.MTiDriver_o1[0],
                    &tmp[0], &sads_balance_cubemodel_B.MTiDriver_o3[0],
                    &sads_balance_cubemodel_B.MTiDriver_o4[0], &b_varargout_5);
  }

  /* End of MATLABSystem: '<S1>/Check Pipe Status' */
  /* End of Outputs for SubSystem: '<S1>/Read Incoming Data if data available' */

  /* Gain: '<S7>/1//2' incorporates:
   *  Constant: '<S1>/Roll Mounting Error'
   *  Gain: '<S5>/Gain1'
   *  Sum: '<S1>/Minus'
   */
  rtb_Sum_k = (sads_balance_cubemodel_B.MTiDriver_o4[0] -
               sads_balance_cubemodel_P.RollMountingError_Value) *
    sads_balance_cubemodel_P.Gain1_Gain * sads_balance_cubemodel_P.u2_Gain;

  /* Trigonometry: '<S7>/sincos' */
  rtb_Derivative_idx_0 = (real32_T)sin(rtb_Sum_k);
  rtb_Divide_idx_0 = (real32_T)cos(rtb_Sum_k);

  /* Gain: '<S7>/1//2' incorporates:
   *  Constant: '<S1>/Pitch Mounting Error'
   *  Gain: '<S5>/Gain1'
   *  Sum: '<S1>/Minus1'
   */
  rtb_Sum_k = (sads_balance_cubemodel_B.MTiDriver_o4[1] -
               sads_balance_cubemodel_P.PitchMountingError_Value) *
    sads_balance_cubemodel_P.Gain1_Gain * sads_balance_cubemodel_P.u2_Gain;

  /* Trigonometry: '<S7>/sincos' */
  rtb_Derivative_idx_1 = (real32_T)sin(rtb_Sum_k);
  rtb_Divide_idx_1 = (real32_T)cos(rtb_Sum_k);

  /* Gain: '<S7>/1//2' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S5>/Gain1'
   */
  rtb_Sum_k = sads_balance_cubemodel_P.Gain1_Gain *
    sads_balance_cubemodel_P.Constant_Value_o * sads_balance_cubemodel_P.u2_Gain;

  /* Trigonometry: '<S7>/sincos' */
  rtb_Derivative_idx_2 = (real32_T)sin(rtb_Sum_k);
  rtb_Divide_idx_2 = (real32_T)cos(rtb_Sum_k);

  /* Fcn: '<S7>/q0' incorporates:
   *  Fcn: '<S7>/q3'
   */
  rtb_Sum_ll_tmp = rtb_Divide_idx_0 * rtb_Divide_idx_1;
  rtb_Sum_ll_tmp_0 = rtb_Derivative_idx_0 * rtb_Derivative_idx_1;
  rtb_Sum_k = rtb_Sum_ll_tmp * rtb_Divide_idx_2 - rtb_Sum_ll_tmp_0 *
    rtb_Derivative_idx_2;

  /* Fcn: '<S7>/q1' incorporates:
   *  Fcn: '<S7>/q2'
   */
  rtb_Divide_idx_0 *= rtb_Derivative_idx_1;
  rtb_Divide_idx_1 *= rtb_Derivative_idx_0;
  rtb_Derivative_idx_0 = rtb_Divide_idx_0 * rtb_Derivative_idx_2 +
    rtb_Divide_idx_1 * rtb_Divide_idx_2;

  /* Fcn: '<S7>/q2' */
  rtb_Divide_idx_1 = rtb_Divide_idx_0 * rtb_Divide_idx_2 - rtb_Divide_idx_1 *
    rtb_Derivative_idx_2;

  /* Fcn: '<S7>/q3' */
  rtb_Derivative_idx_2 = rtb_Sum_ll_tmp * rtb_Derivative_idx_2 +
    rtb_Sum_ll_tmp_0 * rtb_Divide_idx_2;

  /* Gain: '<S3>/m_mmu' incorporates:
   *  DotProduct: '<S3>/Dot Product'
   *  MATLABSystem: '<S6>/MTi Driver'
   */
  rtb_Divide_idx_2 = ((sads_balance_cubemodel_B.MTiDriver_o1[0] *
                       sads_balance_cubemodel_B.MTiDriver_o1[0] +
                       sads_balance_cubemodel_B.MTiDriver_o1[1] *
                       sads_balance_cubemodel_B.MTiDriver_o1[1]) +
                      sads_balance_cubemodel_B.MTiDriver_o1[2] *
                      sads_balance_cubemodel_B.MTiDriver_o1[2]) *
    sads_balance_cubemodel_P.m_mmu_Gain;

  /* DataTypeConversion: '<Root>/Cast to int32' incorporates:
   *  Constant: '<Root>/q_d'
   *  Constant: '<S3>/Constant'
   *  Gain: '<Root>/#revs to steps'
   *  Gain: '<Root>/Derivative'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/distance to # revs'
   *  MATLABSystem: '<S6>/MTi Driver'
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   *  Product: '<S3>/Divide'
   *  Product: '<S8>/Element Product'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S8>/Sum'
   */
  rtb_Sum_ll_tmp = (real32_T)floor((sads_balance_cubemodel_B.MTiDriver_o1[1] *
    sads_balance_cubemodel_P.Constant_Value - ((((rtb_Sum_k *
    sads_balance_cubemodel_P.q_d_Value[2] - rtb_Derivative_idx_0 *
    sads_balance_cubemodel_P.q_d_Value[3]) + rtb_Divide_idx_1 *
    sads_balance_cubemodel_P.q_d_Value[0]) + rtb_Derivative_idx_2 *
    sads_balance_cubemodel_P.q_d_Value[1]) * sads_balance_cubemodel_P.Gain_Gain *
    sads_balance_cubemodel_P.Gain2_Gain +
    sads_balance_cubemodel_P.Derivative_Gain *
    sads_balance_cubemodel_B.MTiDriver_o3[1]) *
    sads_balance_cubemodel_B.MTiDriver_o1[2]) * (1.0F / rtb_Divide_idx_2) *
    sads_balance_cubemodel_P.distancetorevs_Gain *
    sads_balance_cubemodel_P.STEPS_PER_REV);
  if (rtIsNaNF(rtb_Sum_ll_tmp) || rtIsInfF(rtb_Sum_ll_tmp)) {
    rtb_Sum_ll_tmp = 0.0F;
  } else {
    rtb_Sum_ll_tmp = (real32_T)fmod(rtb_Sum_ll_tmp, 4.294967296E+9);
  }

  i = rtb_Sum_ll_tmp < 0.0F ? -(int32_T)(uint32_T)-rtb_Sum_ll_tmp : (int32_T)
    (uint32_T)rtb_Sum_ll_tmp;

  /* End of DataTypeConversion: '<Root>/Cast to int32' */

  /* Saturate: '<Root>/Saturation' */
  if (i > sads_balance_cubemodel_P.Saturation_UpperSat) {
    /* SignalConversion generated from: '<Root>/I2C Controller Write' */
    rtb_TmpSignalConversionAtI2CCon[0] =
      sads_balance_cubemodel_P.Saturation_UpperSat;
  } else if (i < sads_balance_cubemodel_P.Saturation_LowerSat) {
    /* SignalConversion generated from: '<Root>/I2C Controller Write' */
    rtb_TmpSignalConversionAtI2CCon[0] =
      sads_balance_cubemodel_P.Saturation_LowerSat;
  } else {
    /* SignalConversion generated from: '<Root>/I2C Controller Write' */
    rtb_TmpSignalConversionAtI2CCon[0] = i;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* DataTypeConversion: '<Root>/Cast' incorporates:
   *  Constant: '<Root>/q_d'
   *  Constant: '<S3>/Constant'
   *  Gain: '<Root>/Derivative'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   *  MATLABSystem: '<S6>/MTi Driver'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/Product2'
   *  Product: '<S10>/Product3'
   *  Product: '<S3>/Divide'
   *  Product: '<S8>/Element Product'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S8>/Sum'
   */
  rtb_Sum_ll_tmp = (real32_T)floor((((((rtb_Sum_k *
    sads_balance_cubemodel_P.q_d_Value[1] + rtb_Derivative_idx_0 *
    sads_balance_cubemodel_P.q_d_Value[0]) + rtb_Divide_idx_1 *
    sads_balance_cubemodel_P.q_d_Value[3]) - rtb_Derivative_idx_2 *
    sads_balance_cubemodel_P.q_d_Value[2]) * sads_balance_cubemodel_P.Gain_Gain *
    sads_balance_cubemodel_P.Gain2_Gain +
    sads_balance_cubemodel_P.Derivative_Gain *
    sads_balance_cubemodel_B.MTiDriver_o3[0]) *
    sads_balance_cubemodel_B.MTiDriver_o1[2] -
    sads_balance_cubemodel_B.MTiDriver_o1[0] *
    sads_balance_cubemodel_P.Constant_Value) * (1.0F / rtb_Divide_idx_2) *
    sads_balance_cubemodel_P.Gain3_Gain * sads_balance_cubemodel_P.STEPS_PER_REV);
  if (rtIsNaNF(rtb_Sum_ll_tmp) || rtIsInfF(rtb_Sum_ll_tmp)) {
    rtb_Sum_ll_tmp = 0.0F;
  } else {
    rtb_Sum_ll_tmp = (real32_T)fmod(rtb_Sum_ll_tmp, 4.294967296E+9);
  }

  i = rtb_Sum_ll_tmp < 0.0F ? -(int32_T)(uint32_T)-rtb_Sum_ll_tmp : (int32_T)
    (uint32_T)rtb_Sum_ll_tmp;

  /* End of DataTypeConversion: '<Root>/Cast' */

  /* Saturate: '<Root>/Saturation1' */
  if (i > sads_balance_cubemodel_P.Saturation1_UpperSat) {
    /* SignalConversion generated from: '<Root>/I2C Controller Write' */
    rtb_TmpSignalConversionAtI2CCon[1] =
      sads_balance_cubemodel_P.Saturation1_UpperSat;
  } else if (i < sads_balance_cubemodel_P.Saturation1_LowerSat) {
    /* SignalConversion generated from: '<Root>/I2C Controller Write' */
    rtb_TmpSignalConversionAtI2CCon[1] =
      sads_balance_cubemodel_P.Saturation1_LowerSat;
  } else {
    /* SignalConversion generated from: '<Root>/I2C Controller Write' */
    rtb_TmpSignalConversionAtI2CCon[1] = i;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* SignalConversion generated from: '<Root>/I2C Controller Write' incorporates:
   *  Constant: '<Root>/DATA'
   *  Constant: '<Root>/MID'
   */
  rtb_TmpSignalConversionAtI2CCon[2] = sads_balance_cubemodel_P.MID_Value_d;
  rtb_TmpSignalConversionAtI2CCon[3] = sads_balance_cubemodel_P.DATA_Value_b;

  /* MATLABSystem: '<Root>/I2C Controller Write' */
  memcpy((void *)&txDataSwapLoc[0], (void *)&rtb_TmpSignalConversionAtI2CCon[0],
         (size_t)16 * sizeof(uint8_T));
  SwappedDataBytes[0] = 0U;
  for (i = 0; i < 16; i++) {
    SwappedDataBytes[i + 1] = txDataSwapLoc[i];
  }

  I2C_Controller_TransmitData_Polling
    (sads_balance_cubemodel_DW.obj_a.MW_I2C_HANDLE, 66, &SwappedDataBytes[0],
     17U, false, false, 2U);

  /* End of MATLABSystem: '<Root>/I2C Controller Write' */
}

/* Model initialize function */
void sads_balance_cubemodel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T rtb_TmpSignalConversionAtI2CCon[4];
    int32_T i;
    uint8_T SwappedDataBytes[17];
    uint8_T txDataSwapLoc[16];

    /* SystemInitialize for Enabled SubSystem: '<S1>/Read Incoming Data if data available' */
    /* Start for MATLABSystem: '<S6>/I2C Controller Read2' */
    sads_balance_cubemodel_DW.obj_g.isInitialized = 0;
    sads_balance_cubemodel_DW.obj_g.matlabCodegenIsDeleted = false;
    sads_balance_c_SystemCore_setup(&sads_balance_cubemodel_DW.obj_g);

    /* Start for MATLABSystem: '<S6>/MTi Driver' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted = false;
    sads_balance_cubemodel_DW.obj_m.isInitialized = 1;

    /*         %% Define input properties */
    /*  Call C-function implementing device initialization */
    MTi_Driver_Init();
    sads_balance_cubemodel_DW.obj_m.isSetupComplete = true;

    /* SystemInitialize for MATLABSystem: '<S6>/MTi Driver' incorporates:
     *  Outport: '<S6>/g_body'
     */
    sads_balance_cubemodel_B.MTiDriver_o1[0] =
      sads_balance_cubemodel_P.g_body_Y0;

    /* SystemInitialize for MATLABSystem: '<S6>/MTi Driver' incorporates:
     *  Outport: '<S6>/bodyRates'
     */
    sads_balance_cubemodel_B.MTiDriver_o3[0] =
      sads_balance_cubemodel_P.bodyRates_Y0;

    /* SystemInitialize for MATLABSystem: '<S6>/MTi Driver' incorporates:
     *  Outport: '<S6>/eulerAngles'
     */
    sads_balance_cubemodel_B.MTiDriver_o4[0] =
      sads_balance_cubemodel_P.eulerAngles_Y0;

    /* SystemInitialize for MATLABSystem: '<S6>/MTi Driver' incorporates:
     *  Outport: '<S6>/g_body'
     */
    sads_balance_cubemodel_B.MTiDriver_o1[1] =
      sads_balance_cubemodel_P.g_body_Y0;

    /* SystemInitialize for MATLABSystem: '<S6>/MTi Driver' incorporates:
     *  Outport: '<S6>/bodyRates'
     */
    sads_balance_cubemodel_B.MTiDriver_o3[1] =
      sads_balance_cubemodel_P.bodyRates_Y0;

    /* SystemInitialize for MATLABSystem: '<S6>/MTi Driver' incorporates:
     *  Outport: '<S6>/eulerAngles'
     */
    sads_balance_cubemodel_B.MTiDriver_o4[1] =
      sads_balance_cubemodel_P.eulerAngles_Y0;

    /* SystemInitialize for MATLABSystem: '<S6>/MTi Driver' incorporates:
     *  Outport: '<S6>/g_body'
     */
    sads_balance_cubemodel_B.MTiDriver_o1[2] =
      sads_balance_cubemodel_P.g_body_Y0;

    /* SystemInitialize for MATLABSystem: '<S6>/MTi Driver' incorporates:
     *  Outport: '<S6>/bodyRates'
     */
    sads_balance_cubemodel_B.MTiDriver_o3[2] =
      sads_balance_cubemodel_P.bodyRates_Y0;

    /* SystemInitialize for MATLABSystem: '<S6>/MTi Driver' incorporates:
     *  Outport: '<S6>/eulerAngles'
     */
    sads_balance_cubemodel_B.MTiDriver_o4[2] =
      sads_balance_cubemodel_P.eulerAngles_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Read Incoming Data if data available' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Initialize Function' */
    /* Start for MATLABSystem: '<S2>/I2C Controller Write1' */
    sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted = false;
    sads_balance_cubemodel_DW.obj.isSetupComplete = false;
    sads_balance_cubemodel_DW.obj.isInitialized = 1;
    sads_bala_I2CDrvBlock_setupImpl(&sads_balance_cubemodel_DW.obj);
    sads_balance_cubemodel_DW.obj.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize Function' */

    /* Start for MATLABSystem: '<S1>/Check Pipe Status' */
    sads_balance_cubemodel_DW.obj_l.isInitialized = 0;
    sads_balance_cubemodel_DW.obj_l.matlabCodegenIsDeleted = false;
    sads_balance_c_SystemCore_setup(&sads_balance_cubemodel_DW.obj_l);

    /* Start for MATLABSystem: '<Root>/I2C Controller Write' */
    sads_balance_cubemodel_DW.obj_a.matlabCodegenIsDeleted = false;
    sads_balance_cubemodel_DW.obj_a.isSetupComplete = false;
    sads_balance_cubemodel_DW.obj_a.isInitialized = 1;
    sads_bala_I2CDrvBlock_setupImpl(&sads_balance_cubemodel_DW.obj_a);
    sads_balance_cubemodel_DW.obj_a.isSetupComplete = true;

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* SignalConversion generated from: '<S2>/I2C Controller Write1' incorporates:
     *  Constant: '<S2>/DATA'
     *  Constant: '<S2>/MID'
     *  Constant: '<S2>/Start X'
     *  Constant: '<S2>/Start Y'
     */
    rtb_TmpSignalConversionAtI2CCon[0] = sads_balance_cubemodel_P.StartX_Value;
    rtb_TmpSignalConversionAtI2CCon[1] = sads_balance_cubemodel_P.StartY_Value;
    rtb_TmpSignalConversionAtI2CCon[2] = sads_balance_cubemodel_P.MID_Value;
    rtb_TmpSignalConversionAtI2CCon[3] = sads_balance_cubemodel_P.DATA_Value;

    /* MATLABSystem: '<S2>/I2C Controller Write1' */
    memcpy((void *)&txDataSwapLoc[0], (void *)&rtb_TmpSignalConversionAtI2CCon[0],
           (size_t)16 * sizeof(uint8_T));
    SwappedDataBytes[0] = 0U;
    for (i = 0; i < 16; i++) {
      SwappedDataBytes[i + 1] = txDataSwapLoc[i];
    }

    I2C_Controller_TransmitData_Polling
      (sads_balance_cubemodel_DW.obj.MW_I2C_HANDLE, 66, &SwappedDataBytes[0],
       17U, false, false, 100U);

    /* End of MATLABSystem: '<S2>/I2C Controller Write1' */
    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
  }
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
  /* Terminate for MATLABSystem: '<S6>/I2C Controller Read2' */
  if (!sads_balance_cubemodel_DW.obj_g.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/I2C Controller Read2' */

  /* Terminate for MATLABSystem: '<S6>/MTi Driver' */
  if (!sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/MTi Driver' */
  /* End of Terminate for SubSystem: '<S1>/Read Incoming Data if data available' */

  /* Terminate for MATLABSystem: '<Root>/I2C Controller Write' */
  if (!sads_balance_cubemodel_DW.obj_a.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/I2C Controller Write' */

  /* Terminate for Atomic SubSystem: '<Root>/Initialize Function' */
  /* Terminate for MATLABSystem: '<S2>/I2C Controller Write1' */
  if (!sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Controller Write1' */
  /* End of Terminate for SubSystem: '<Root>/Initialize Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
