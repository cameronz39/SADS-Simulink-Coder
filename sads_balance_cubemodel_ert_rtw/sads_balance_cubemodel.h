/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sads_balance_cubemodel.h
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
#include "rt_nonfinite.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TmpRTBAtSineWave1Outport1;    /* '<S4>/Sine Wave1' */
  uint32_T I2CControllerWrite;         /* '<Root>/I2C Controller Write' */
  real32_T Divide[3];                  /* '<S2>/Divide' */
  real32_T CastToSingle1[4];           /* '<S4>/Cast To Single1' */
  real32_T PID_output[3];              /* '<Root>/Sum' */
  real32_T MTiDriver_o1[3];            /* '<S5>/MTi Driver' */
  real32_T MTiDriver_o2[4];            /* '<S5>/MTi Driver' */
  real32_T MTiDriver_o3[3];            /* '<S5>/MTi Driver' */
  int32_T DesiredPositionX;            /* '<Root>/Cast to int32' */
  int32_T DesiredPositionY;            /* '<Root>/Cast' */
  uint16_T MTiDriver_o4;               /* '<S5>/MTi Driver' */
  uint8_T CheckPipeStatus_o1[4];       /* '<S1>/Check Pipe Status' */
} B_sads_balance_cubemodel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_I2CControlle_T obj; /* '<Root>/I2C Controller Write' */
  stm32cube_blocks_I2CControl_f_T obj_g;/* '<S5>/I2C Controller Read2' */
  stm32cube_blocks_I2CControl_f_T obj_l;/* '<S1>/Check Pipe Status' */
  MTi_Driver_Sys_Obj_sads_balan_T obj_m;/* '<S5>/MTi Driver' */
  real_T TmpRTBAtSineWave1Outport1_Buffe;/* synthesized block */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<Root>/Discrete-Time Integrator' */
  int32_T counter;                     /* '<S4>/Sine Wave' */
  int32_T counter_c;                   /* '<S4>/Sine Wave1' */
  int8_T ReadIncomingDataifdataavailable;
                               /* '<S1>/Read Incoming Data if data available' */
} DW_sads_balance_cubemodel_T;

/* Parameters (default storage) */
struct P_sads_balance_cubemodel_T_ {
  real_T SineWave_Amp;                 /* Expression: 90
                                        * Referenced by: '<S4>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S4>/Sine Wave'
                                        */
  real_T SineWave_NumSamp;             /* Expression: 50
                                        * Referenced by: '<S4>/Sine Wave'
                                        */
  real_T SineWave_Offset;              /* Expression: 0.1
                                        * Referenced by: '<S4>/Sine Wave'
                                        */
  real_T TmpRTBAtSineWave1Outport1_Initi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T u2_Gain;                      /* Expression: 0.5
                                        * Referenced by: '<S12>/1//2'
                                        */
  real_T SineWave1_Amp;                /* Expression: 0
                                        * Referenced by: '<S4>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<S4>/Sine Wave1'
                                        */
  real_T SineWave1_NumSamp;            /* Expression: 50
                                        * Referenced by: '<S4>/Sine Wave1'
                                        */
  real_T SineWave1_Offset;             /* Expression: 0
                                        * Referenced by: '<S4>/Sine Wave1'
                                        */
  int32_T MID_Value;                   /* Computed Parameter: MID_Value
                                        * Referenced by: '<Root>/MID'
                                        */
  int32_T DATA_Value;                  /* Computed Parameter: DATA_Value
                                        * Referenced by: '<Root>/DATA'
                                        */
  real32_T g_body_Y0;                  /* Computed Parameter: g_body_Y0
                                        * Referenced by: '<S5>/g_body'
                                        */
  real32_T quat_Y0;                    /* Computed Parameter: quat_Y0
                                        * Referenced by: '<S5>/quat'
                                        */
  real32_T bodyRates_Y0;               /* Computed Parameter: bodyRates_Y0
                                        * Referenced by: '<S5>/bodyRates'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S2>/Constant'
                                        */
  real32_T m_mmu_Gain;                 /* Computed Parameter: m_mmu_Gain
                                        * Referenced by: '<S2>/m_mmu'
                                        */
  real32_T distancetorevs_Gain;       /* Computed Parameter: distancetorevs_Gain
                                       * Referenced by: '<Root>/distance to # revs'
                                       */
  real32_T revstosteps_Gain;           /* Computed Parameter: revstosteps_Gain
                                        * Referenced by: '<Root>/#revs to steps'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real32_T Gain1_Gain_n;               /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real32_T q_d_Value[4];               /* Computed Parameter: q_d_Value
                                        * Referenced by: '<Root>/q_d'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
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
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

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

/* External function called from main */
extern void sads_balance_cubemodel_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void sads_balance_cubemodel_initialize(void);
extern void sads_balance_cubemodel_step0(void);/* Sample time: [0.0125s, 0.0s] */
extern void sads_balance_cubemodel_step1(void);/* Sample time: [0.1s, 0.0s] */
extern void sads_balance_cubemodel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sads_balance_cubemod_T *const sads_balance_cubemodel_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Derivative' : Unused code path elimination
 * Block '<Root>/Cast To Single' : Eliminate redundant data type conversion
 * Block '<S7>/Product' : Unused code path elimination
 * Block '<S7>/Product1' : Unused code path elimination
 * Block '<S7>/Product2' : Unused code path elimination
 * Block '<S7>/Product3' : Unused code path elimination
 * Block '<S7>/Sum' : Unused code path elimination
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
 * '<S2>'   : 'sads_balance_cubemodel/Map PID to r_mmus2'
 * '<S3>'   : 'sads_balance_cubemodel/Quaternion Multiplication'
 * '<S4>'   : 'sads_balance_cubemodel/System Checkout'
 * '<S5>'   : 'sads_balance_cubemodel/IMU I2C Read/Read Incoming Data if data available'
 * '<S6>'   : 'sads_balance_cubemodel/Map PID to r_mmus2/Cross Product'
 * '<S7>'   : 'sads_balance_cubemodel/Quaternion Multiplication/q0'
 * '<S8>'   : 'sads_balance_cubemodel/Quaternion Multiplication/q1'
 * '<S9>'   : 'sads_balance_cubemodel/Quaternion Multiplication/q2'
 * '<S10>'  : 'sads_balance_cubemodel/Quaternion Multiplication/q3'
 * '<S11>'  : 'sads_balance_cubemodel/System Checkout/Degrees to Radians'
 * '<S12>'  : 'sads_balance_cubemodel/System Checkout/Rotation Angles to Quaternions'
 */
#endif                                 /* sads_balance_cubemodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
