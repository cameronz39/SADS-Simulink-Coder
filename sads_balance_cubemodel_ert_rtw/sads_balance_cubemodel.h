/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel.h
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

#ifndef sads_balance_cubemodel_h_
#define sads_balance_cubemodel_h_
#ifndef sads_balance_cubemodel_COMMON_INCLUDES_
#define sads_balance_cubemodel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "mw_stm32_i2c_ll.h"
#include "MTi_Driver.h"
#endif                             /* sads_balance_cubemodel_COMMON_INCLUDES_ */

#include "sads_balance_cubemodel_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T MTiDriver_o1[3];            /* '<S2>/MTi Driver' */
  real32_T MTiDriver_o2[4];            /* '<S2>/MTi Driver' */
  real32_T MTiDriver_o3[3];            /* '<S2>/MTi Driver' */
} B_sads_balance_cubemodel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_I2CControlle_T obj; /* '<S2>/I2C Controller Read2' */
  stm32cube_blocks_I2CControlle_T obj_l;/* '<S1>/Check Pipe Status' */
  MTi_Driver_Sys_Obj_sads_balan_T obj_m;/* '<S2>/MTi Driver' */
  int8_T ReadIncomingDataifdataavailable;
                               /* '<S1>/Read Incoming Data if data available' */
} DW_sads_balance_cubemodel_T;

/* Parameters (default storage) */
struct P_sads_balance_cubemodel_T_ {
  real32_T euler_Y0;                   /* Computed Parameter: euler_Y0
                                        * Referenced by: '<S2>/euler'
                                        */
  real32_T quat_Y0;                    /* Computed Parameter: quat_Y0
                                        * Referenced by: '<S2>/quat'
                                        */
  real32_T bodyRates_Y0;               /* Computed Parameter: bodyRates_Y0
                                        * Referenced by: '<S2>/bodyRates'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_sads_balance_cubemode_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_sads_balance_cubemodel_T sads_balance_cubemodel_P;

/* Block signals (default storage) */
extern B_sads_balance_cubemodel_T sads_balance_cubemodel_B;

/* Block states (default storage) */
extern DW_sads_balance_cubemodel_T sads_balance_cubemodel_DW;

/* Model entry point functions */
extern void sads_balance_cubemodel_initialize(void);
extern void sads_balance_cubemodel_step(void);
extern void sads_balance_cubemodel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sads_balance_cubemod_T *const sads_balance_cubemodel_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sads_balance_cubemodel'
 * '<S1>'   : 'sads_balance_cubemodel/IMU I2C Read'
 * '<S2>'   : 'sads_balance_cubemodel/IMU I2C Read/Read Incoming Data if data available'
 */
#endif                                 /* sads_balance_cubemodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
