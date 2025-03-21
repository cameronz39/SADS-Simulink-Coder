/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel_types.h
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

#ifndef sads_balance_cubemodel_types_h_
#define sads_balance_cubemodel_types_h_
#include "rtwtypes.h"
#include "mw_stm32_i2c_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_Bsne03NJRJrqr6CZlqkIVB
#define struct_tag_Bsne03NJRJrqr6CZlqkIVB

struct tag_Bsne03NJRJrqr6CZlqkIVB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_Bsne03NJRJrqr6CZlqkIVB */

#ifndef typedef_StepperDriveSysObj_sads_balan_T
#define typedef_StepperDriveSysObj_sads_balan_T

typedef struct tag_Bsne03NJRJrqr6CZlqkIVB StepperDriveSysObj_sads_balan_T;

#endif                             /* typedef_StepperDriveSysObj_sads_balan_T */

/* Custom Type definition for MATLABSystem: '<S8>/I2C Controller Read2' */
#include "mw_stm32_i2c_ll.h"
#include "mw_stm32_i2c_ll.h"
#include "mw_stm32_i2c_ll.h"
#ifndef struct_tag_pu2p5c8LXP2BpmWuMrlbBG
#define struct_tag_pu2p5c8LXP2BpmWuMrlbBG

struct tag_pu2p5c8LXP2BpmWuMrlbBG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  STM32_I2C_Struct_T * MW_I2C_HANDLE;
  STM32_I2C_Struct_T MW_I2C_BlockStruct;
};

#endif                                 /* struct_tag_pu2p5c8LXP2BpmWuMrlbBG */

#ifndef typedef_stm32cube_blocks_I2CControlle_T
#define typedef_stm32cube_blocks_I2CControlle_T

typedef struct tag_pu2p5c8LXP2BpmWuMrlbBG stm32cube_blocks_I2CControlle_T;

#endif                             /* typedef_stm32cube_blocks_I2CControlle_T */

#ifndef struct_tag_ayIc4J5yzVhZTlnbhUyj1C
#define struct_tag_ayIc4J5yzVhZTlnbhUyj1C

struct tag_ayIc4J5yzVhZTlnbhUyj1C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_ayIc4J5yzVhZTlnbhUyj1C */

#ifndef typedef_MTi_Driver_Sys_Obj_sads_balan_T
#define typedef_MTi_Driver_Sys_Obj_sads_balan_T

typedef struct tag_ayIc4J5yzVhZTlnbhUyj1C MTi_Driver_Sys_Obj_sads_balan_T;

#endif                             /* typedef_MTi_Driver_Sys_Obj_sads_balan_T */

/* Custom Type definition for MATLABSystem: '<Root>/Timer' */
#include "stm_timer_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_7tj0KRDTWyWWGG811kfCoC
#define struct_tag_7tj0KRDTWyWWGG811kfCoC

struct tag_7tj0KRDTWyWWGG811kfCoC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_7tj0KRDTWyWWGG811kfCoC */

#ifndef typedef_stm32cube_blocks_TimerBlock_s_T
#define typedef_stm32cube_blocks_TimerBlock_s_T

typedef struct tag_7tj0KRDTWyWWGG811kfCoC stm32cube_blocks_TimerBlock_s_T;

#endif                             /* typedef_stm32cube_blocks_TimerBlock_s_T */

/* Parameters (default storage) */
typedef struct P_sads_balance_cubemodel_T_ P_sads_balance_cubemodel_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_sads_balance_cubemode_T RT_MODEL_sads_balance_cubemod_T;

#endif                                 /* sads_balance_cubemodel_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
