/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel.c
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
#include "sads_balance_cubemodel_types.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
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
static void sads_balance_SystemCore_setup_f(stm32cube_blocks_I2CControlle_T *obj);
static void sads_balance_c_SystemCore_setup(stm32cube_blocks_I2CControlle_T *obj);
static void sads_balanc_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_sa_T *obj);
static void sads_balance_SystemCore_setup_f(stm32cube_blocks_I2CControlle_T *obj)
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

static void sads_balance_c_SystemCore_setup(stm32cube_blocks_I2CControlle_T *obj)
{
  STM32_I2C_Struct_T * i2cBlockStruct_loc;
  STM32_I2C_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<Root>/Check Pipe Status' */
  obj->isInitialized = 1;
  c.instance = I2C2;
  c.txCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  c.rxCommunicationMode = MW_I2C_COMMUNICATION_POLLING;
  obj->MW_I2C_BlockStruct.h_i2c = NULL;
  obj->MW_I2C_BlockStruct.rxBufferStructPtr = NULL;
  obj->MW_I2C_BlockStruct.txBufferStructPtr = NULL;
  i2cBlockStruct_loc = (STM32_I2C_Struct_T *)(&obj->MW_I2C_BlockStruct);
  obj->MW_I2C_HANDLE = I2C_Init(&c, i2cBlockStruct_loc);
  obj->isSetupComplete = true;
}

static void sads_balanc_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_sa_T *obj)
{
  UART_Type_T b;
  b.buffer.txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);

  /* Start for MATLABSystem: '<Root>/UART//USART Write1' */
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = USART3;

  /* Start for MATLABSystem: '<Root>/UART//USART Write1' */
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
}

/* Model step function */
void sads_balance_cubemodel_step(void)
{
  int32_T b_posTx[2];
  int32_T i;
  real32_T tmp[4];
  real32_T b_eulerAnglesTx[3];
  real32_T rtb_u2[3];
  real32_T rtb_Divide_idx_1;
  real32_T rtb_Divide_idx_2;
  real32_T rtb_Product1_e;
  real32_T rtb_Product3_c;
  real32_T rtb_Product_tmp;
  real32_T rtb_Product_tmp_0;
  real32_T rtb_Sum_m;
  real32_T rtb_m_mmu;
  real32_T rtb_sincos_o1_idx_0;
  real32_T rtb_sincos_o1_idx_1;
  real32_T rtb_sincos_o1_idx_2;
  uint32_T status;
  uint16_T b_varargout_5;
  uint8_T b_bytesIn[91];
  uint8_T uartWriteData[39];
  uint8_T rtb_WiressComms_o1_0[33];
  uint8_T rtb_CheckPipeStatus_o1_m_0[6];
  uint8_T rtb_CheckPipeStatus_o1_0[4];
  uint8_T txData;

  /* MATLABSystem: '<Root>/Check Pipe Status' */
  I2C_Controller_ReceiveData_Polling
    (sads_balance_cubemodel_DW.obj_o.MW_I2C_HANDLE, 18,
     &rtb_CheckPipeStatus_o1_m_0[0], 6U, false, true, 100U);

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
   *  EnablePort: '<S5>/Enable'
   */
  if (rtb_CheckPipeStatus_o1_0[2] > 0) {
    /* MATLABSystem: '<S5>/I2C Controller Read2' incorporates:
     *  MATLABSystem: '<S5>/MTi Driver'
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
      /* MATLABSystem: '<S5>/MTi Driver' */
      memset(&b_bytesIn[0], 0, 91U * sizeof(uint8_T));
    }

    /* End of MATLABSystem: '<S5>/I2C Controller Read2' */

    /* MATLABSystem: '<S5>/MTi Driver' */
    /*         %% Define input properties */
    sads_balance_cubemodel_B.MTiDriver_o1[0] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o1[1] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o1[2] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    tmp[0] = 0.0F;
    tmp[1] = 0.0F;
    tmp[2] = 0.0F;
    tmp[3] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o3[0] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o4[0] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o3[1] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o4[1] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o3[2] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o4[2] = 0.0F;

    /* MATLABSystem: '<S5>/MTi Driver' */
    b_varargout_5 = 0U;

    /*  Call C-function implementing device output */
    MTi_Driver_Step(&b_bytesIn[0], &sads_balance_cubemodel_B.MTiDriver_o1[0],
                    &tmp[0], &sads_balance_cubemodel_B.MTiDriver_o3[0],
                    &sads_balance_cubemodel_B.MTiDriver_o4[0], &b_varargout_5);
  }

  /* End of MATLABSystem: '<S1>/Check Pipe Status' */
  /* End of Outputs for SubSystem: '<S1>/Read Incoming Data if data available' */

  /* Sum: '<S1>/Minus' incorporates:
   *  Constant: '<S1>/Roll Mounting Error'
   */
  rtb_Product1_e = sads_balance_cubemodel_B.MTiDriver_o4[0] -
    sads_balance_cubemodel_P.RollMountingError_Value;

  /* Sum: '<S1>/Minus1' incorporates:
   *  Constant: '<S1>/Pitch Mounting Error'
   */
  rtb_Product3_c = sads_balance_cubemodel_B.MTiDriver_o4[1] -
    sads_balance_cubemodel_P.PitchMountingError_Value;

  /* MATLABSystem: '<Root>/Wiress Comms' incorporates:
   *  SignalConversion generated from: '<Root>/Wiress Comms'
   */
  b_eulerAnglesTx[0] = rtb_Product1_e;
  b_eulerAnglesTx[1] = rtb_Product3_c;
  b_eulerAnglesTx[2] = sads_balance_cubemodel_B.MTiDriver_o4[2];

  /* Gain: '<S6>/1//2' incorporates:
   *  Gain: '<S4>/Gain1'
   */
  rtb_m_mmu = sads_balance_cubemodel_P.Gain1_Gain * rtb_Product1_e *
    sads_balance_cubemodel_P.u2_Gain;

  /* Trigonometry: '<S6>/sincos' */
  rtb_sincos_o1_idx_0 = (real32_T)sin(rtb_m_mmu);
  rtb_Product1_e = (real32_T)cos(rtb_m_mmu);

  /* Gain: '<S6>/1//2' incorporates:
   *  Gain: '<S4>/Gain1'
   */
  rtb_m_mmu = sads_balance_cubemodel_P.Gain1_Gain * rtb_Product3_c *
    sads_balance_cubemodel_P.u2_Gain;

  /* Trigonometry: '<S6>/sincos' */
  rtb_sincos_o1_idx_1 = (real32_T)sin(rtb_m_mmu);
  rtb_Divide_idx_1 = (real32_T)cos(rtb_m_mmu);

  /* Gain: '<S6>/1//2' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S4>/Gain1'
   */
  rtb_m_mmu = sads_balance_cubemodel_P.Gain1_Gain *
    sads_balance_cubemodel_P.Constant_Value_o * sads_balance_cubemodel_P.u2_Gain;

  /* Trigonometry: '<S6>/sincos' */
  rtb_sincos_o1_idx_2 = (real32_T)sin(rtb_m_mmu);
  rtb_Divide_idx_2 = (real32_T)cos(rtb_m_mmu);

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

  /* Fcn: '<S6>/q0' incorporates:
   *  Fcn: '<S6>/q3'
   */
  rtb_Product_tmp = rtb_Product1_e * rtb_Divide_idx_1;
  rtb_Product_tmp_0 = rtb_sincos_o1_idx_0 * rtb_sincos_o1_idx_1;
  rtb_Product3_c = rtb_Product_tmp * rtb_Divide_idx_2 - rtb_Product_tmp_0 *
    rtb_sincos_o1_idx_2;

  /* Fcn: '<S6>/q1' incorporates:
   *  Fcn: '<S6>/q2'
   */
  rtb_sincos_o1_idx_1 *= rtb_Product1_e;
  rtb_sincos_o1_idx_0 *= rtb_Divide_idx_1;
  rtb_Product1_e = rtb_sincos_o1_idx_1 * rtb_sincos_o1_idx_2 +
    rtb_sincos_o1_idx_0 * rtb_Divide_idx_2;

  /* Fcn: '<S6>/q2' */
  rtb_Divide_idx_1 = rtb_sincos_o1_idx_1 * rtb_Divide_idx_2 -
    rtb_sincos_o1_idx_0 * rtb_sincos_o1_idx_2;

  /* Fcn: '<S6>/q3' */
  rtb_sincos_o1_idx_2 = rtb_Product_tmp * rtb_sincos_o1_idx_2 +
    rtb_Product_tmp_0 * rtb_Divide_idx_2;

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<Root>/q_d'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Product: '<S9>/Product2'
   *  Product: '<S9>/Product3'
   */
  rtb_Divide_idx_2 = ((rtb_Product3_c * sads_balance_cubemodel_P.q_d_Value[1] +
                       rtb_Product1_e * sads_balance_cubemodel_P.q_d_Value[0]) +
                      rtb_Divide_idx_1 * sads_balance_cubemodel_P.q_d_Value[3])
    - rtb_sincos_o1_idx_2 * sads_balance_cubemodel_P.q_d_Value[2];

  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<Root>/q_d'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/Product2'
   *  Product: '<S10>/Product3'
   */
  rtb_Sum_m = ((rtb_Product3_c * sads_balance_cubemodel_P.q_d_Value[2] -
                rtb_Product1_e * sads_balance_cubemodel_P.q_d_Value[3]) +
               rtb_Divide_idx_1 * sads_balance_cubemodel_P.q_d_Value[0]) +
    rtb_sincos_o1_idx_2 * sads_balance_cubemodel_P.q_d_Value[1];

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtb_Product_tmp = sads_balance_cubemodel_P.DiscreteTimeIntegrator_gainval *
    rtb_Divide_idx_2;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtb_sincos_o1_idx_0 = rtb_Product_tmp +
    sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtb_Product_tmp_0 = sads_balance_cubemodel_P.DiscreteTimeIntegrator_gainval *
    rtb_Sum_m;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtb_sincos_o1_idx_1 = rtb_Product_tmp_0 +
    sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* MATLABSystem: '<Root>/Wiress Comms' incorporates:
   *  MATLABSystem: '<S5>/MTi Driver'
   */
  /*         %% Define input properties */
  for (i = 0; i < 33; i++) {
    rtb_WiressComms_o1_0[i] = 0U;
  }

  /*  Call C-function implementing device output */
  rtb_u2[0] = sads_balance_cubemodel_B.MTiDriver_o3[0];
  rtb_u2[1] = sads_balance_cubemodel_B.MTiDriver_o3[1];
  rtb_u2[2] = sads_balance_cubemodel_B.MTiDriver_o3[2];

  /* DataTypeConversion: '<Root>/Cast to int32' incorporates:
   *  Constant: '<S2>/Constant'
   *  Gain: '<Root>/#revs to steps'
   *  Gain: '<Root>/Derivative'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Integral'
   *  Gain: '<Root>/distance to # revs'
   *  MATLABSystem: '<S5>/MTi Driver'
   *  Product: '<S2>/Divide'
   *  Product: '<S7>/Element Product'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S7>/Sum'
   */
  rtb_Sum_m = (real32_T)floor((sads_balance_cubemodel_B.MTiDriver_o1[1] *
    sads_balance_cubemodel_P.Constant_Value -
    ((sads_balance_cubemodel_P.Gain_Gain * rtb_Sum_m *
      sads_balance_cubemodel_P.Gain2_Gain +
      sads_balance_cubemodel_P.Integral_Gain * rtb_sincos_o1_idx_1) +
     sads_balance_cubemodel_P.Derivative_Gain *
     sads_balance_cubemodel_B.MTiDriver_o3[1]) *
    sads_balance_cubemodel_B.MTiDriver_o1[2]) * (1.0F / rtb_m_mmu) *
    sads_balance_cubemodel_P.distancetorevs_Gain *
    sads_balance_cubemodel_P.STEPS_PER_REV);
  if (rtIsNaNF(rtb_Sum_m) || rtIsInfF(rtb_Sum_m)) {
    rtb_Sum_m = 0.0F;
  } else {
    rtb_Sum_m = (real32_T)fmod(rtb_Sum_m, 4.294967296E+9);
  }

  /* MATLABSystem: '<Root>/Wiress Comms' incorporates:
   *  DataTypeConversion: '<Root>/Cast to int32'
   */
  b_posTx[0] = rtb_Sum_m < 0.0F ? -(int32_T)(uint32_T)-rtb_Sum_m : (int32_T)
    (uint32_T)rtb_Sum_m;

  /* DataTypeConversion: '<Root>/Cast' incorporates:
   *  Constant: '<S2>/Constant'
   *  Gain: '<Root>/Derivative'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Integral'
   *  MATLABSystem: '<S5>/MTi Driver'
   *  Product: '<S2>/Divide'
   *  Product: '<S7>/Element Product'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S7>/Sum'
   */
  rtb_Sum_m = (real32_T)floor((((sads_balance_cubemodel_P.Gain_Gain *
    rtb_Divide_idx_2 * sads_balance_cubemodel_P.Gain2_Gain +
    sads_balance_cubemodel_P.Integral_Gain * rtb_sincos_o1_idx_0) +
    sads_balance_cubemodel_P.Derivative_Gain *
    sads_balance_cubemodel_B.MTiDriver_o3[0]) *
    sads_balance_cubemodel_B.MTiDriver_o1[2] -
    sads_balance_cubemodel_B.MTiDriver_o1[0] *
    sads_balance_cubemodel_P.Constant_Value) * (1.0F / rtb_m_mmu) *
    sads_balance_cubemodel_P.Gain3_Gain * sads_balance_cubemodel_P.STEPS_PER_REV);
  if (rtIsNaNF(rtb_Sum_m) || rtIsInfF(rtb_Sum_m)) {
    rtb_Sum_m = 0.0F;
  } else {
    rtb_Sum_m = (real32_T)fmod(rtb_Sum_m, 4.294967296E+9);
  }

  /* MATLABSystem: '<Root>/Wiress Comms' incorporates:
   *  DataTypeConversion: '<Root>/Cast'
   */
  b_posTx[1] = rtb_Sum_m < 0.0F ? -(int32_T)(uint32_T)-rtb_Sum_m : (int32_T)
    (uint32_T)rtb_Sum_m;
  Comm_Driver_Step(&b_eulerAnglesTx[0], &rtb_u2[0], &b_posTx[0],
                   &rtb_WiressComms_o1_0[0]);

  /* MATLABSystem: '<Root>/UART//USART Write1' incorporates:
   *  MATLABSystem: '<Root>/Check Pipe Status'
   *  MATLABSystem: '<Root>/Wiress Comms'
   */
  for (i = 0; i < 33; i++) {
    uartWriteData[i] = rtb_WiressComms_o1_0[i];
  }

  for (i = 0; i < 6; i++) {
    uartWriteData[i + 33] = rtb_CheckPipeStatus_o1_m_0[i];
  }

  MW_UART_TransmitUsingInterrupt(sads_balance_cubemodel_DW.obj.UARTHandle,
    &uartWriteData[0], 39U, 0U, &status);

  /* End of MATLABSystem: '<Root>/UART//USART Write1' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[0] = rtb_Product_tmp +
    rtb_sincos_o1_idx_0;
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[1] = rtb_Product_tmp_0
    + rtb_sincos_o1_idx_1;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/q_d'
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   *  Sum: '<S11>/Sum'
   */
  rtb_sincos_o1_idx_0 = (((rtb_Product3_c * sads_balance_cubemodel_P.q_d_Value[3]
    + rtb_Product1_e * sads_balance_cubemodel_P.q_d_Value[2]) - rtb_Divide_idx_1
    * sads_balance_cubemodel_P.q_d_Value[1]) + rtb_sincos_o1_idx_2 *
    sads_balance_cubemodel_P.q_d_Value[0]) *
    sads_balance_cubemodel_P.DiscreteTimeIntegrator_gainval;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[2] =
    (rtb_sincos_o1_idx_0 +
     sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[2]) +
    rtb_sincos_o1_idx_0;
}

/* Model initialize function */
void sads_balance_cubemodel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[0] =
    sads_balance_cubemodel_P.DiscreteTimeIntegrator_IC[0];
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[1] =
    sads_balance_cubemodel_P.DiscreteTimeIntegrator_IC[1];
  sads_balance_cubemodel_DW.DiscreteTimeIntegrator_DSTATE[2] =
    sads_balance_cubemodel_P.DiscreteTimeIntegrator_IC[2];

  /* SystemInitialize for Enabled SubSystem: '<S1>/Read Incoming Data if data available' */
  /* Start for MATLABSystem: '<S5>/I2C Controller Read2' */
  sads_balance_cubemodel_DW.obj_g.isInitialized = 0;
  sads_balance_cubemodel_DW.obj_g.matlabCodegenIsDeleted = false;
  sads_balance_SystemCore_setup_f(&sads_balance_cubemodel_DW.obj_g);

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

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/bodyRates'
   */
  sads_balance_cubemodel_B.MTiDriver_o3[0] =
    sads_balance_cubemodel_P.bodyRates_Y0;

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/eulerAngles'
   */
  sads_balance_cubemodel_B.MTiDriver_o4[0] =
    sads_balance_cubemodel_P.eulerAngles_Y0;

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/g_body'
   */
  sads_balance_cubemodel_B.MTiDriver_o1[1] = sads_balance_cubemodel_P.g_body_Y0;

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/bodyRates'
   */
  sads_balance_cubemodel_B.MTiDriver_o3[1] =
    sads_balance_cubemodel_P.bodyRates_Y0;

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/eulerAngles'
   */
  sads_balance_cubemodel_B.MTiDriver_o4[1] =
    sads_balance_cubemodel_P.eulerAngles_Y0;

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/g_body'
   */
  sads_balance_cubemodel_B.MTiDriver_o1[2] = sads_balance_cubemodel_P.g_body_Y0;

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/bodyRates'
   */
  sads_balance_cubemodel_B.MTiDriver_o3[2] =
    sads_balance_cubemodel_P.bodyRates_Y0;

  /* SystemInitialize for MATLABSystem: '<S5>/MTi Driver' incorporates:
   *  Outport: '<S5>/eulerAngles'
   */
  sads_balance_cubemodel_B.MTiDriver_o4[2] =
    sads_balance_cubemodel_P.eulerAngles_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Read Incoming Data if data available' */

  /* Start for MATLABSystem: '<Root>/Check Pipe Status' */
  sads_balance_cubemodel_DW.obj_o.isInitialized = 0;
  sads_balance_cubemodel_DW.obj_o.matlabCodegenIsDeleted = false;
  sads_balance_c_SystemCore_setup(&sads_balance_cubemodel_DW.obj_o);

  /* Start for MATLABSystem: '<S1>/Check Pipe Status' */
  sads_balance_cubemodel_DW.obj_l.isInitialized = 0;
  sads_balance_cubemodel_DW.obj_l.matlabCodegenIsDeleted = false;
  sads_balance_SystemCore_setup_f(&sads_balance_cubemodel_DW.obj_l);

  /* Start for MATLABSystem: '<Root>/Wiress Comms' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  sads_balance_cubemodel_DW.obj_o1.matlabCodegenIsDeleted = false;
  sads_balance_cubemodel_DW.obj_o1.isInitialized = 1;

  /*         %% Define input properties */
  /*  Call C-function implementing device initialization */
  Comm_Driver_Init();
  sads_balance_cubemodel_DW.obj_o1.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/UART//USART Write1' */
  sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted = false;
  sads_balance_cubemodel_DW.obj.isSetupComplete = false;
  sads_balance_cubemodel_DW.obj.isInitialized = 1;
  sads_balanc_UARTWrite_setupImpl(&sads_balance_cubemodel_DW.obj);
  sads_balance_cubemodel_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void sads_balance_cubemodel_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Check Pipe Status' */
  if (!sads_balance_cubemodel_DW.obj_o.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Check Pipe Status' */

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
  /* End of Terminate for SubSystem: '<S1>/Read Incoming Data if data available' */

  /* Terminate for MATLABSystem: '<Root>/Wiress Comms' */
  if (!sads_balance_cubemodel_DW.obj_o1.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_o1.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Wiress Comms' */

  /* Terminate for MATLABSystem: '<Root>/UART//USART Write1' */
  if (!sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted = true;
    if ((sads_balance_cubemodel_DW.obj.isInitialized == 1) &&
        sads_balance_cubemodel_DW.obj.isSetupComplete) {
      MW_UART_DeInit(sads_balance_cubemodel_DW.obj.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/UART//USART Write1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
