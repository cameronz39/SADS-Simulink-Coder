/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel.c
 *
 * Code generated for Simulink model 'sads_balance_cubemodel'.
 *
 * Model version                  : 7.62
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Feb 21 11:40:41 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sads_balance_cubemodel.h"
#include "sads_balance_cubemodel_types.h"
#include "rtwtypes.h"
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
static void sads_balance_c_SystemCore_setup(stm32cube_blocks_I2CControlle_T *obj);
static void sads_balance_c_SystemCore_setup(stm32cube_blocks_I2CControlle_T *obj)
{
  STM32_I2C_Struct_T * i2cBlockStruct_loc;
  STM32_I2C_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S1>/Check Pipe Status' incorporates:
   *  MATLABSystem: '<S2>/I2C Controller Read2'
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

/* Model step function */
void sads_balance_cubemodel_step(void)
{
  int32_T i;
  uint32_T status;
  uint8_T b_bytesIn[53];
  uint8_T rtb_CheckPipeStatus_o1_0[4];
  uint8_T txData;

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
       &rtb_CheckPipeStatus_o1_0[0], 4U, false, false, 1U);
  } else {
    rtb_CheckPipeStatus_o1_0[2] = 0U;
  }

  /* Outputs for Enabled SubSystem: '<S1>/Read Incoming Data if data available' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtb_CheckPipeStatus_o1_0[2] > 0) {
    /* MATLABSystem: '<S2>/I2C Controller Read2' incorporates:
     *  MATLABSystem: '<S2>/MTi Driver'
     */
    txData = 6U;
    status = I2C_Controller_TransmitData_Polling
      (sads_balance_cubemodel_DW.obj.MW_I2C_HANDLE, 107, &txData, 1U, true, true,
       1U);
    if (status == 0U) {
      I2C_Controller_ReceiveData_Polling
        (sads_balance_cubemodel_DW.obj.MW_I2C_HANDLE, 107, &b_bytesIn[0], 53U,
         false, false, 1U);
    } else {
      /* MATLABSystem: '<S2>/MTi Driver' */
      for (i = 0; i < 53; i++) {
        b_bytesIn[i] = 0U;
      }
    }

    /* End of MATLABSystem: '<S2>/I2C Controller Read2' */

    /* MATLABSystem: '<S2>/MTi Driver' */
    /*         %% Define input properties */
    sads_balance_cubemodel_B.MTiDriver_o1[0] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o1[1] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o1[2] = 0.0F;

    /* MATLABSystem: '<S2>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o2[0] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o2[1] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o2[2] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o2[3] = 0.0F;

    /* MATLABSystem: '<S2>/MTi Driver' */
    sads_balance_cubemodel_B.MTiDriver_o3[0] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o3[1] = 0.0F;
    sads_balance_cubemodel_B.MTiDriver_o3[2] = 0.0F;

    /* MATLABSystem: '<S2>/MTi Driver' */
    /*  Call C-function implementing device output */
    MTi_Driver_Step(&b_bytesIn[0], &sads_balance_cubemodel_B.MTiDriver_o1[0],
                    &sads_balance_cubemodel_B.MTiDriver_o2[0],
                    &sads_balance_cubemodel_B.MTiDriver_o3[0]);
    srUpdateBC(sads_balance_cubemodel_DW.ReadIncomingDataifdataavailable);
  }

  /* End of MATLABSystem: '<S1>/Check Pipe Status' */
  /* End of Outputs for SubSystem: '<S1>/Read Incoming Data if data available' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  sads_balance_cubemodel_M->Timing.taskTime0 =
    ((time_T)(++sads_balance_cubemodel_M->Timing.clockTick0)) *
    sads_balance_cubemodel_M->Timing.stepSize0;
}

/* Model initialize function */
void sads_balance_cubemodel_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(sads_balance_cubemodel_M, -1);
  sads_balance_cubemodel_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  sads_balance_cubemodel_M->Sizes.checksums[0] = (993480652U);
  sads_balance_cubemodel_M->Sizes.checksums[1] = (1544468600U);
  sads_balance_cubemodel_M->Sizes.checksums[2] = (518175809U);
  sads_balance_cubemodel_M->Sizes.checksums[3] = (2381944792U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    sads_balance_cubemodel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &sads_balance_cubemodel_DW.ReadIncomingDataifdataavailable;
    systemRan[3] = (sysRanDType *)
      &sads_balance_cubemodel_DW.ReadIncomingDataifdataavailable;
    systemRan[4] = (sysRanDType *)
      &sads_balance_cubemodel_DW.ReadIncomingDataifdataavailable;
    rteiSetModelMappingInfoPtr(sads_balance_cubemodel_M->extModeInfo,
      &sads_balance_cubemodel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sads_balance_cubemodel_M->extModeInfo,
                        sads_balance_cubemodel_M->Sizes.checksums);
    rteiSetTPtr(sads_balance_cubemodel_M->extModeInfo, rtmGetTPtr
                (sads_balance_cubemodel_M));
  }

  /* SystemInitialize for Enabled SubSystem: '<S1>/Read Incoming Data if data available' */
  /* Start for MATLABSystem: '<S2>/I2C Controller Read2' */
  sads_balance_cubemodel_DW.obj.isInitialized = 0;
  sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted = false;
  sads_balance_c_SystemCore_setup(&sads_balance_cubemodel_DW.obj);

  /* Start for MATLABSystem: '<S2>/MTi Driver' */
  /*  Constructor */
  /*  Support name-value pair arguments when constructing the object. */
  sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted = false;
  sads_balance_cubemodel_DW.obj_m.isInitialized = 1;

  /*         %% Define input properties */
  /*  Call C-function implementing device initialization */
  MTi_Driver_Init();
  sads_balance_cubemodel_DW.obj_m.isSetupComplete = true;

  /* SystemInitialize for MATLABSystem: '<S2>/MTi Driver' incorporates:
   *  Outport: '<S2>/euler'
   */
  sads_balance_cubemodel_B.MTiDriver_o1[0] = sads_balance_cubemodel_P.euler_Y0;
  sads_balance_cubemodel_B.MTiDriver_o1[1] = sads_balance_cubemodel_P.euler_Y0;
  sads_balance_cubemodel_B.MTiDriver_o1[2] = sads_balance_cubemodel_P.euler_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/MTi Driver' incorporates:
   *  Outport: '<S2>/quat'
   */
  sads_balance_cubemodel_B.MTiDriver_o2[0] = sads_balance_cubemodel_P.quat_Y0;
  sads_balance_cubemodel_B.MTiDriver_o2[1] = sads_balance_cubemodel_P.quat_Y0;
  sads_balance_cubemodel_B.MTiDriver_o2[2] = sads_balance_cubemodel_P.quat_Y0;
  sads_balance_cubemodel_B.MTiDriver_o2[3] = sads_balance_cubemodel_P.quat_Y0;

  /* SystemInitialize for MATLABSystem: '<S2>/MTi Driver' incorporates:
   *  Outport: '<S2>/bodyRates'
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
  /* Terminate for MATLABSystem: '<S2>/I2C Controller Read2' */
  if (!sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/I2C Controller Read2' */

  /* Terminate for MATLABSystem: '<S2>/MTi Driver' */
  if (!sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted) {
    sads_balance_cubemodel_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/MTi Driver' */
  /* End of Terminate for SubSystem: '<S1>/Read Incoming Data if data available' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
