/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel.h
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

#ifndef sads_balance_cubemodel_h_
#define sads_balance_cubemodel_h_
#ifndef sads_balance_cubemodel_COMMON_INCLUDES_
#define sads_balance_cubemodel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "StepperDrive.h"
#include "mw_stm32_i2c_ll.h"
#include "MTi_Driver.h"
#endif                             /* sads_balance_cubemodel_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "sads_balance_cubemodel_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T MTiDriver_o1[3];            /* '<S8>/MTi Driver' */
  real32_T MTiDriver_o2[4];            /* '<S8>/MTi Driver' */
  int32_T RT3;                         /* '<Root>/RT3' */
  int32_T DesiredPosition;             /* '<Root>/RT' */
} B_sads_balance_cubemodel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_I2CControlle_T obj; /* '<S8>/I2C Controller Read2' */
  stm32cube_blocks_I2CControlle_T obj_l;/* '<S2>/Check Pipe Status' */
  MTi_Driver_Sys_Obj_sads_balan_T obj_m;/* '<S8>/MTi Driver' */
  StepperDriveSysObj_sads_balan_T obj_p;/* '<S5>/MATLAB System' */
  stm32cube_blocks_TimerBlock_s_T obj_d;/* '<Root>/Timer' */
  volatile int32_T RT_Buffer0;         /* '<Root>/RT' */
  volatile int32_T RT3_Buffer0;        /* '<Root>/RT3' */
} DW_sads_balance_cubemodel_T;

/* Parameters (default storage) */
struct P_sads_balance_cubemodel_T_ {
  int32_T RT_InitialCondition;        /* Computed Parameter: RT_InitialCondition
                                       * Referenced by: '<Root>/RT'
                                       */
  int32_T RT3_InitialCondition;      /* Computed Parameter: RT3_InitialCondition
                                      * Referenced by: '<Root>/RT3'
                                      */
  real32_T g_body_Y0;                  /* Computed Parameter: g_body_Y0
                                        * Referenced by: '<S8>/g_body'
                                        */
  real32_T quat_Y0;                    /* Computed Parameter: quat_Y0
                                        * Referenced by: '<S8>/quat'
                                        */
  real32_T bodyRates_Y0;               /* Computed Parameter: bodyRates_Y0
                                        * Referenced by: '<S8>/bodyRates'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S3>/Constant'
                                        */
  real32_T q_d_Value[4];               /* Computed Parameter: q_d_Value
                                        * Referenced by: '<Root>/q_d'
                                        */
  real32_T Proportional_Gain;          /* Computed Parameter: Proportional_Gain
                                        * Referenced by: '<Root>/Proportional'
                                        */
  real32_T m_mmu_Gain;                 /* Computed Parameter: m_mmu_Gain
                                        * Referenced by: '<S3>/m_mmu'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real32_T distancetosteps_Gain;     /* Computed Parameter: distancetosteps_Gain
                                      * Referenced by: '<Root>/distance to steps'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_sads_balance_cubemode_T {
  const char_T * volatile errorStatus;
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

#ifdef __cpluscplus

extern "C"
{

#endif

  void TIM2_IRQHandler(void);
  void sads_balance_cubemodel_configure_interrupts (void);
  void sads_balance_cubemodel_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Derivative' : Unused code path elimination
 * Block '<Root>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<Root>/Integral' : Unused code path elimination
 * Block '<Root>/Cast To Single' : Eliminate redundant data type conversion
 * Block '<S10>/Product' : Unused code path elimination
 * Block '<S10>/Product1' : Unused code path elimination
 * Block '<S10>/Product2' : Unused code path elimination
 * Block '<S10>/Product3' : Unused code path elimination
 * Block '<S10>/Sum' : Unused code path elimination
 */

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
 * '<S1>'   : 'sads_balance_cubemodel/Hardware Interrupt'
 * '<S2>'   : 'sads_balance_cubemodel/IMU I2C Read'
 * '<S3>'   : 'sads_balance_cubemodel/Map PID to r_mmus2'
 * '<S4>'   : 'sads_balance_cubemodel/Quaternion Multiplication'
 * '<S5>'   : 'sads_balance_cubemodel/Stepper Driver'
 * '<S6>'   : 'sads_balance_cubemodel/Hardware Interrupt/ECSoC'
 * '<S7>'   : 'sads_balance_cubemodel/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S8>'   : 'sads_balance_cubemodel/IMU I2C Read/Read Incoming Data if data available'
 * '<S9>'   : 'sads_balance_cubemodel/Map PID to r_mmus2/Cross Product'
 * '<S10>'  : 'sads_balance_cubemodel/Quaternion Multiplication/q0'
 * '<S11>'  : 'sads_balance_cubemodel/Quaternion Multiplication/q1'
 * '<S12>'  : 'sads_balance_cubemodel/Quaternion Multiplication/q2'
 * '<S13>'  : 'sads_balance_cubemodel/Quaternion Multiplication/q3'
 */
#endif                                 /* sads_balance_cubemodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
