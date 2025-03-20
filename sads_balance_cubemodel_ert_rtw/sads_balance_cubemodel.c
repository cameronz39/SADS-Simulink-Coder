/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel.c
 *
 * Code generated for Simulink model 'sads_balance_cubemodel'.
 *
 * Model version                  : 7.84
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Mar 18 18:41:56 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sads_balance_cubemodel.h"
#include "sads_balance_cubemodel_types.h"
#include "sads_balance_cubemodel_private.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "mw_stm32_i2c_ll.h"
#include "stm_timer_ll.h"

/* Block signals (default storage) */
B_sads_balance_cubemodel_T sads_balance_cubemodel_B;

/* Block states (default storage) */
DW_sads_balance_cubemodel_T sads_balance_cubemodel_DW;

/* Real-time model */
static RT_MODEL_sads_balance_cubemod_T sads_balance_cubemodel_M_;
RT_MODEL_sads_balance_cubemod_T *const sads_balance_cubemodel_M =
  &sads_balance_cubemodel_M_;

/* Forward declaration for local functions */
static void sads_balance_c_SystemCore_setup(stm32cube_blocks_I2CControlle_T *obj);
static void sads_balanc_SystemCore_setup_f3(stm32cube_blocks_TimerBlock_s_T *obj);
static void sads_balance_c_SystemCore_setup(stm32cube_blocks_I2CControlle_T *obj)
{
  STM32_I2C_Struct_T * i2cBlockStruct_loc;
  STM32_I2C_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S2>/Check Pipe Status' incorporates:
   *  MATLABSystem: '<S8>/I2C Controller Read2'
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

static void sads_balanc_SystemCore_setup_f3(stm32cube_blocks_TimerBlock_s_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 32);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void sads_balance_cubemodel_step(void)
{
  real32_T rtb_Divide[3];
  real32_T rtb_ElementProduct_idx_0;
  real32_T rtb_ElementProduct_idx_3;
  real32_T rtb_m_mmu;
  real32_T tmp;
  uint32_T status;
  uint16_T b_varargout_4;
  uint8_T b_bytesIn[76];
  uint8_T rtb_CheckPipeStatus_o1_0[4];
  uint8_T txData;

  /* MATLABSystem: '<S2>/Check Pipe Status' */
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

  /* Outputs for Enabled SubSystem: '<S2>/Read Incoming Data if data available' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (rtb_CheckPipeStatus_o1_0[2] > 0) {
    /* MATLABSystem: '<S8>/I2C Controller Read2' incorporates:
     *  MATLABSystem: '<S8>/MTi Driver'
     */
    txData = 6U;
    status = I2C_Controller_TransmitData_Polling
      (sads_balance_cubemodel_DW.obj.MW_I2C_HANDLE, 107, &txData, 1U, true, true,
       1U);
    if (status == 0U) {
      I2C_Controller_ReceiveData_Polling
        (sads_balance_cubemodel_DW.obj.MW_I2C_HANDLE, 107, &b_bytesIn[0], 76U,
         false, false, 1U);
    } else {
      /* MATLABSystem: '<S8>/MTi Driver' */
      memset(&b_bytesIn[0], 0, 76U * sizeof(uint8_T));
    }

    /* End of MATLABSystem: '<S8>/I2C Controller Read2' */

    /* MATLABSystem: '<S8>/MTi Driver' */
    /*         %% Define input properties */
    sads_balance_cubemodel_B.MTiDriver_o1[0] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o1[1] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o1[2] = 0.0F;

    /* MATLABSystem: '<S8>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o2[0] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o2[1] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o2[2] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o2[3] = 0.0F;

    /* MATLABSystem: '<S8>/MTi Driver' */
    rtb_Divide[0] = 0.0F;
    rtb_Divide[1] = 0.0F;
    rtb_Divide[2] = 0.0F;
    b_varargout_4 = 0U;

    /*  Call C-function implementing device output */
    MTi_Driver_Step(&b_bytesIn[0], &sads_balance_cubemodel_B.MTiDriver_o1[0],
                    &sads_balance_cubemodel_B.MTiDriver_o2[0], &rtb_Divide[0],
                    &b_varargout_4);
  }

  /* End of MATLABSystem: '<S2>/Check Pipe Status' */
  /* End of Outputs for SubSystem: '<S2>/Read Incoming Data if data available' */

  /* Product: '<S9>/Element Product' incorporates:
   *  Constant: '<Root>/q_d'
   *  Constant: '<S3>/Constant'
   *  Gain: '<Root>/Proportional'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   *  Product: '<S12>/Product2'
   *  Product: '<S12>/Product3'
   *  Sum: '<S12>/Sum'
   */
  rtb_ElementProduct_idx_0 = sads_balance_cubemodel_B.MTiDriver_o1[1] *
    sads_balance_cubemodel_P.Constant_Value;
  rtb_ElementProduct_idx_3 = (((sads_balance_cubemodel_B.MTiDriver_o2[0] *
    sads_balance_cubemodel_P.q_d_Value[2] -
    sads_balance_cubemodel_B.MTiDriver_o2[1] *
    sads_balance_cubemodel_P.q_d_Value[3]) + sads_balance_cubemodel_P.q_d_Value
    [0] * sads_balance_cubemodel_B.MTiDriver_o2[2]) +
    sads_balance_cubemodel_P.q_d_Value[1] *
    sads_balance_cubemodel_B.MTiDriver_o2[3]) *
    sads_balance_cubemodel_P.Proportional_Gain *
    sads_balance_cubemodel_B.MTiDriver_o1[2];

  /* Gain: '<S3>/m_mmu' incorporates:
   *  DotProduct: '<S3>/Dot Product'
   *  MATLABSystem: '<S8>/MTi Driver'
   */
  rtb_m_mmu = ((sads_balance_cubemodel_B.MTiDriver_o1[0] *
                sads_balance_cubemodel_B.MTiDriver_o1[0] +
                sads_balance_cubemodel_B.MTiDriver_o1[1] *
                sads_balance_cubemodel_B.MTiDriver_o1[1]) +
               sads_balance_cubemodel_B.MTiDriver_o1[2] *
               sads_balance_cubemodel_B.MTiDriver_o1[2]) *
    sads_balance_cubemodel_P.m_mmu_Gain;

  /* DataTypeConversion: '<Root>/Cast' incorporates:
   *  Constant: '<Root>/q_d'
   *  Constant: '<S3>/Constant'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Proportional'
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   *  Product: '<S3>/Divide'
   *  Product: '<S9>/Element Product'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S9>/Sum'
   */
  tmp = (real32_T)floor(((((sads_balance_cubemodel_B.MTiDriver_o2[0] *
    sads_balance_cubemodel_P.q_d_Value[1] + sads_balance_cubemodel_P.q_d_Value[0]
    * sads_balance_cubemodel_B.MTiDriver_o2[1]) +
    sads_balance_cubemodel_B.MTiDriver_o2[2] *
    sads_balance_cubemodel_P.q_d_Value[3]) - sads_balance_cubemodel_P.q_d_Value
    [2] * sads_balance_cubemodel_B.MTiDriver_o2[3]) *
    sads_balance_cubemodel_P.Proportional_Gain *
    sads_balance_cubemodel_B.MTiDriver_o1[2] -
    sads_balance_cubemodel_B.MTiDriver_o1[0] *
    sads_balance_cubemodel_P.Constant_Value) * (1.0F / rtb_m_mmu) *
                        sads_balance_cubemodel_P.Gain1_Gain);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.294967296E+9);
  }

  /* RateTransition: '<Root>/RT' incorporates:
   *  DataTypeConversion: '<Root>/Cast'
   */
  sads_balance_cubemodel_DW.RT_Buffer0 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* DataTypeConversion: '<Root>/Cast to int32' incorporates:
   *  Gain: '<Root>/distance to steps'
   *  Product: '<S3>/Divide'
   *  Sum: '<S9>/Sum'
   */
  tmp = (real32_T)floor(1.0F / rtb_m_mmu * (rtb_ElementProduct_idx_0 -
    rtb_ElementProduct_idx_3) * sads_balance_cubemodel_P.distancetosteps_Gain);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 4.294967296E+9);
  }

  /* RateTransition: '<Root>/RT3' incorporates:
   *  DataTypeConversion: '<Root>/Cast to int32'
   */
  sads_balance_cubemodel_DW.RT3_Buffer0 = tmp < 0.0F ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* MATLABSystem: '<Root>/Timer' */
  getTimerCounterValue(sads_balance_cubemodel_DW.obj_d.TimerHandle);
}

/* Model initialize function */
void sads_balance_cubemodel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for RateTransition: '<Root>/RT' */
  sads_balance_cubemodel_DW.RT_Buffer0 =
    sads_balance_cubemodel_P.RT_InitialCondition;

  /* InitializeConditions for RateTransition: '<Root>/RT3' */
  sads_balance_cubemodel_DW.RT3_Buffer0 =
    sads_balance_cubemodel_P.RT3_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<S2>/Read Incoming Data if data available' */
  /* Start for MATLABSystem: '<S8>/I2C Controller Read2' */
  sads_balance_cubemodel_DW.obj.isInitialized = 0;
  sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted = false;
  sads_balance_c_SystemCore_setup(&sads_balance_cubemodel_DW.obj);

  /* Start for MATLABSystem: '<S8>/MTi Driver' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted = false;
  sads_balance_cubemodel_DW.obj_m.isInitialized = 1;

  /*         %% Define input properties */
  /*  Call C-function implementing device initialization */
  MTi_Driver_Init();
  sads_balance_cubemodel_DW.obj_m.isSetupComplete = true;

  /* SystemInitialize for MATLABSystem: '<S8>/MTi Driver' incorporates:
   *  Outport: '<S8>/g_body'
   */
  sads_balance_cubemodel_B.MTiDriver_o1[0] = sads_balance_cubemodel_P.g_body_Y0;
  sads_balance_cubemodel_B.MTiDriver_o1[1] = sads_balance_cubemodel_P.g_body_Y0;
  sads_balance_cubemodel_B.MTiDriver_o1[2] = sads_balance_cubemodel_P.g_body_Y0;

  /* SystemInitialize for MATLABSystem: '<S8>/MTi Driver' incorporates:
   *  Outport: '<S8>/quat'
   */
  sads_balance_cubemodel_B.MTiDriver_o2[0] = sads_balance_cubemodel_P.quat_Y0;
  sads_balance_cubemodel_B.MTiDriver_o2[1] = sads_balance_cubemodel_P.quat_Y0;
  sads_balance_cubemodel_B.MTiDriver_o2[2] = sads_balance_cubemodel_P.quat_Y0;
  sads_balance_cubemodel_B.MTiDriver_o2[3] = sads_balance_cubemodel_P.quat_Y0;

  /* End of SystemInitialize for SubSystem: '<S2>/Read Incoming Data if data available' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Stepper Driver'
   */

  /* System initialize for function-call system: '<Root>/Stepper Driver' */

  /* Start for MATLABSystem: '<S5>/MATLAB System' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  sads_balance_cubemodel_DW.obj_p.matlabCodegenIsDeleted = false;
  sads_balance_cubemodel_DW.obj_p.isInitialized = 1;

  /*         %% Define input properties */
  /*  Call C-function implementing device initialization */
  StepperDrive_Init();
  sads_balance_cubemodel_DW.obj_p.isSetupComplete = true;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S2>/Check Pipe Status' */
  sads_balance_cubemodel_DW.obj_l.isInitialized = 0;
  sads_balance_cubemodel_DW.obj_l.matlabCodegenIsDeleted = false;
  sads_balance_c_SystemCore_setup(&sads_balance_cubemodel_DW.obj_l);

  /* Start for MATLABSystem: '<Root>/Timer' */
  sads_balance_cubemodel_DW.obj_d.isInitialized = 0;
  sads_balance_cubemodel_DW.obj_d.matlabCodegenIsDeleted = false;
  sads_balanc_SystemCore_setup_f3(&sads_balance_cubemodel_DW.obj_d);
}

/* Model terminate function */
void sads_balance_cubemodel_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Check Pipe Status' */
  if (!sads_balance_cubemodel_DW.obj_l.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Check Pipe Status' */

  /* Terminate for Enabled SubSystem: '<S2>/Read Incoming Data if data available' */
  /* Terminate for MATLABSystem: '<S8>/I2C Controller Read2' */
  if (!sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/I2C Controller Read2' */

  /* Terminate for MATLABSystem: '<S8>/MTi Driver' */
  if (!sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/MTi Driver' */
  /* End of Terminate for SubSystem: '<S2>/Read Incoming Data if data available' */
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Stepper Driver'
   */
  /* Termination for function-call system: '<Root>/Stepper Driver' */

  /* Terminate for MATLABSystem: '<S5>/MATLAB System' */
  if (!sads_balance_cubemodel_DW.obj_p.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/MATLAB System' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<Root>/Timer' */
  if (!sads_balance_cubemodel_DW.obj_d.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((sads_balance_cubemodel_DW.obj_d.isInitialized == 1) &&
        sads_balance_cubemodel_DW.obj_d.isSetupComplete) {
      disableCounter(sads_balance_cubemodel_DW.obj_d.TimerHandle);
      disableTimerInterrupts(sads_balance_cubemodel_DW.obj_d.TimerHandle, 32);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Timer' */
}

void sads_balance_cubemodel_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(43,&TIM2_IRQHandler,2);
  MW_NVIC_EnableIRQ(43);
}

/* Hardware Interrupt Block: '<S7>/Hardware Interrupt' */
void TIM2_IRQHandler(void)
{
  /* Event: TIM2 Update */
  /* Check event TIM2 Update occurred */
  if (0 != ((0 != LL_TIM_IsEnabledIT_UPDATE(TIM2)) && (0 !=
        LL_TIM_IsActiveFlag_UPDATE(TIM2)))) {
    /* Clear occurred TIM2 Update event */
    LL_TIM_ClearFlag_UPDATE(TIM2);
    if (1 == runModel) {
      {
        /* RateTransition: '<Root>/RT3' */
        sads_balance_cubemodel_B.RT3 = sads_balance_cubemodel_DW.RT3_Buffer0;

        /* RateTransition: '<Root>/RT' */
        sads_balance_cubemodel_B.DesiredPosition =
          sads_balance_cubemodel_DW.RT_Buffer0;

        /* S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Stepper Driver' */

        /* MATLABSystem: '<S5>/MATLAB System' */
        /*         %% Define input properties */
        /*  Call C-function implementing device output */
        StepperDrive_Step(sads_balance_cubemodel_B.RT3,
                          sads_balance_cubemodel_B.DesiredPosition);

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S7>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
}

void sads_balance_cubemodel_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(43);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
