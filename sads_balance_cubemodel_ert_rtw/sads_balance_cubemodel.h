/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel.h
 *
 * Code generated for Simulink model 'sads_balance_cubemodel'.
 *
 * Model version                  : 7.165
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May 27 14:28:53 2025
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
#include "mw_stm32_i2c_ll.h"
#include "MTi_Driver.h"
#include "stm_uart.h"
#include "Comm_Driver.h"
#endif                             /* sads_balance_cubemodel_COMMON_INCLUDES_ */

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
  real32_T MTiDriver_o1[3];            /* '<S6>/MTi Driver' */
  real32_T MTiDriver_o3[3];            /* '<S6>/MTi Driver' */
  real32_T MTiDriver_o4[3];            /* '<S6>/MTi Driver' */
} B_sads_balance_cubemodel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_UARTWrite_sa_T obj; /* '<Root>/UART//USART Write1' */
  stm32cube_blocks_I2CControlle_T obj_a;/* '<S2>/I2C Controller Write1' */
  stm32cube_blocks_I2CControlle_T obj_a3;/* '<Root>/I2C Controller Write' */
  stm32cube_blocks_I2CControl_f_T obj_g;/* '<S6>/I2C Controller Read2' */
  stm32cube_blocks_I2CControl_f_T obj_l;/* '<S1>/Check Pipe Status' */
  MTi_Driver_Sys_Obj_sads_balan_T obj_m;/* '<S6>/MTi Driver' */
  Comm_Driver_Sys_Obj_sads_bala_T obj_o;/* '<Root>/Wiress Comms' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<Root>/Discrete-Time Integrator' */
} DW_sads_balance_cubemodel_T;

/* Parameters (default storage) */
struct P_sads_balance_cubemodel_T_ {
  real32_T STEPS_PER_REV;              /* Variable: STEPS_PER_REV
                                        * Referenced by:
                                        *   '<Root>/#revs to steps'
                                        *   '<Root>/Gain1'
                                        */
  int32_T DATA_Value;                  /* Computed Parameter: DATA_Value
                                        * Referenced by: '<S2>/DATA'
                                        */
  int32_T StartX_Value;                /* Computed Parameter: StartX_Value
                                        * Referenced by: '<S2>/Start X'
                                        */
  int32_T StartY_Value;                /* Computed Parameter: StartY_Value
                                        * Referenced by: '<S2>/Start Y'
                                        */
  int32_T MID_Value;                   /* Computed Parameter: MID_Value
                                        * Referenced by: '<S2>/MID'
                                        */
  int32_T DATA_Value_b;                /* Computed Parameter: DATA_Value_b
                                        * Referenced by: '<Root>/DATA'
                                        */
  int32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
  int32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<Root>/Saturation'
                                       */
  int32_T Saturation1_UpperSat;      /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
  int32_T Saturation1_LowerSat;      /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
  int32_T MID_Value_d;                 /* Computed Parameter: MID_Value_d
                                        * Referenced by: '<Root>/MID'
                                        */
  real32_T g_body_Y0;                  /* Computed Parameter: g_body_Y0
                                        * Referenced by: '<S6>/g_body'
                                        */
  real32_T quat_Y0;                    /* Computed Parameter: quat_Y0
                                        * Referenced by: '<S6>/quat'
                                        */
  real32_T bodyRates_Y0;               /* Computed Parameter: bodyRates_Y0
                                        * Referenced by: '<S6>/bodyRates'
                                        */
  real32_T eulerAngles_Y0;             /* Computed Parameter: eulerAngles_Y0
                                        * Referenced by: '<S6>/eulerAngles'
                                        */
  real32_T RollMountingError_Value;
                                  /* Computed Parameter: RollMountingError_Value
                                   * Referenced by: '<S1>/Roll Mounting Error'
                                   */
  real32_T PitchMountingError_Value;
                                 /* Computed Parameter: PitchMountingError_Value
                                  * Referenced by: '<S1>/Pitch Mounting Error'
                                  */
  real32_T m_mmu_Gain;                 /* Computed Parameter: m_mmu_Gain
                                        * Referenced by: '<S3>/m_mmu'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S3>/Constant'
                                        */
  real32_T q_d_Value[4];               /* Computed Parameter: q_d_Value
                                        * Referenced by: '<Root>/q_d'
                                        */
  real32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real32_T u2_Gain;                    /* Computed Parameter: u2_Gain
                                        * Referenced by: '<S7>/1//2'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real32_T DiscreteTimeIntegrator_IC[3];
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<Root>/Discrete-Time Integrator'
                                 */
  real32_T Integral_Gain;              /* Computed Parameter: Integral_Gain
                                        * Referenced by: '<Root>/Integral'
                                        */
  real32_T Derivative_Gain;            /* Computed Parameter: Derivative_Gain
                                        * Referenced by: '<Root>/Derivative'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real32_T distancetorevs_Gain;       /* Computed Parameter: distancetorevs_Gain
                                       * Referenced by: '<Root>/distance to # revs'
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

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Cast To Single' : Eliminate redundant data type conversion
 * Block '<S1>/Cast To Single' : Eliminate redundant data type conversion
 * Block '<S9>/Product' : Unused code path elimination
 * Block '<S9>/Product1' : Unused code path elimination
 * Block '<S9>/Product2' : Unused code path elimination
 * Block '<S9>/Product3' : Unused code path elimination
 * Block '<S9>/Sum' : Unused code path elimination
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
 * '<S1>'   : 'sads_balance_cubemodel/IMU I2C Read'
 * '<S2>'   : 'sads_balance_cubemodel/Initialize Function'
 * '<S3>'   : 'sads_balance_cubemodel/Map PID to r_mmus2'
 * '<S4>'   : 'sads_balance_cubemodel/Quaternion Multiplication'
 * '<S5>'   : 'sads_balance_cubemodel/IMU I2C Read/Degrees to Radians'
 * '<S6>'   : 'sads_balance_cubemodel/IMU I2C Read/Read Incoming Data if data available'
 * '<S7>'   : 'sads_balance_cubemodel/IMU I2C Read/Rotation Angles to Quaternions'
 * '<S8>'   : 'sads_balance_cubemodel/Map PID to r_mmus2/Cross Product'
 * '<S9>'   : 'sads_balance_cubemodel/Quaternion Multiplication/q0'
 * '<S10>'  : 'sads_balance_cubemodel/Quaternion Multiplication/q1'
 * '<S11>'  : 'sads_balance_cubemodel/Quaternion Multiplication/q2'
 * '<S12>'  : 'sads_balance_cubemodel/Quaternion Multiplication/q3'
 */
#endif                                 /* sads_balance_cubemodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
