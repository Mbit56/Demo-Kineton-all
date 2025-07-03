/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Throttle_mgm.c
 *
 * Code generated for Simulink model 'Throttle_mgm'.
 *
 * Model version                  : 3.8
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed May 14 09:17:27 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: TTControl HY-TTC580->TMS570 Cortex-R4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. Traceability
 *    3. MISRA C:2012 guidelines
 * Validation result: Passed (19), Warnings (6), Error (0)
 */

#include "Throttle_mgm.h"
#include "rtwtypes.h"
#include "VirtualBus_TM.h"
#include "Virtualbus_TM.h"
#include <math.h>
#include "VirtualBus.h"
#include "LookUp_real_T_real_Treal32_T.h"
#include "look1_ts16DdId_binlc.h"
#include "look1_binlx.h"
#include "look1_ts16DdId_binlca.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S6>/Temporal Filter_BMSError_TurtleMode' */
#define IN_ACTIVATION_PROCESS          ((uint8_T)1U)
#define IN_BACK_FROM_ERROR             ((uint8_T)2U)
#define IN_CONFIRM_ERROR_PROCESS       ((uint8_T)3U)
#define IN_INIT                        ((uint8_T)4U)
#define IN_OUTPUT                      ((uint8_T)5U)

/* Named constants for Chart: '<S6>/Temporal Filter_BTF_Derating' */
#define IN_ACTIVATION_PROCESS_i        ((uint8_T)1U)
#define IN_CONFIRM_ERROR_PROCESS_k     ((uint8_T)2U)
#define IN_INIT_k                      ((uint8_T)3U)
#define IN_OUTPUT_p                    ((uint8_T)4U)

/* Named constants for Chart: '<S3>/Chart' */
#define IN_fourth                      ((uint8_T)1U)
#define IN_second                      ((uint8_T)2U)
#define IN_start                       ((uint8_T)3U)
#define IN_third                       ((uint8_T)4U)

/* Named constants for Chart: '<S3>/Startup' */
#define IN_PowerOn                     ((uint8_T)1U)
#define IN_Standby                     ((uint8_T)2U)
#define IN_TrqContr1                   ((uint8_T)3U)

/* Named constants for Chart: '<S31>/Duble_Track_mgm' */
#define IN_APP_BROKE                   ((uint8_T)1U)
#define IN_COERENCE                    ((uint8_T)2U)
#define IN_COERENCE_CHECK              ((uint8_T)3U)
#define IN_INIT_l                      ((uint8_T)4U)
#define IN_NON_COERENCE_TRACK1         ((uint8_T)5U)
#define IN_NON_COERENCE_TRACK2         ((uint8_T)6U)
#define IN_TRACK1_FAULT                ((uint8_T)7U)
#define IN_TRACK2_FAULT                ((uint8_T)8U)

/* Named constants for Chart: '<S18>/Chart' */
#define IN_BYPASS                      ((uint8_T)1U)
#define IN_DERATING                    ((uint8_T)2U)
#define IN_INIT_b                      ((uint8_T)3U)
#define IN_TIMER                       ((uint8_T)4U)

/* Named constants for Chart: '<S41>/Chart' */
#define IN_FINAL                       ((uint8_T)1U)
#define IN_FIRSTSTEP                   ((uint8_T)2U)

/* Named constants for Chart: '<S26>/Chart' */
#define IN_INIT_f                      ((uint8_T)1U)
#define IN_VEH_LIMITER                 ((uint8_T)2U)

/* user code (top of source file) */
#include "Common.h"
#ifdef CAN_DEBUG
#include "debug.h"
#endif

/* Constant parameters (default storage) */
const ConstP_Throttle_mgm_T ConstP_Throttle_mgm = {
  /* Expression: [70;75;80;85;90;95]
   * Referenced by: '<S17>/1-D Lookup Table4'
   */
  { 70.0, 75.0, 80.0, 85.0, 90.0, 95.0 },

  /* Expression: [0;1;2;3;4;5]
   * Referenced by: '<S17>/1-D Lookup Table4'
   */
  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0 },

  /* Expression: [-10;-5;5;15;25;35;45;55;70;80;85]
   * Referenced by: '<S26>/1-D Lookup Table'
   */
  { -10.0, -5.0, 5.0, 15.0, 25.0, 35.0, 45.0, 55.0, 70.0, 80.0, 85.0 },

  /* Expression: [-10;-5;0;3;4;5;6;7;8;9;10]
   * Referenced by: '<S26>/1-D Lookup Table'
   */
  { -10.0, -5.0, 0.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 },

  /* Expression: [-100,-80,-60,-40,-20,0,20,40,60,80,100]
   * Referenced by: '<S7>/x-axis'
   */
  { -100.0, -80.0, -60.0, -40.0, -20.0, 0.0, 20.0, 40.0, 60.0, 80.0, 100.0 },

  /* Expression: [0 10 20 30 40 60 70 80 90 100]
   * Referenced by: '<S30>/x-axis'
   */
  { 0.0, 10.0, 20.0, 30.0, 40.0, 60.0, 70.0, 80.0, 90.0, 100.0 }
};

/* Block signals and states (default storage) */
DW_Throttle_mgm_T DW_Throttle_mgm;

/* Previous zero-crossings (trigger) states */
PrevZCX_Throttle_mgm_T PrevZCX_Throttle_mgm;
static void TemporalFilter_BMSError_Tu_Init(real_T *rty_out);
static void TemporalFilter_BMSError_TurtleM(boolean_T rtu_enable, real_T
  *rty_out, DW_TemporalFilter_BMSError_Tu_T *localDW);
static void TemporalFilter_BTF_Deratin_Init(real_T *rty_out);
static void TemporalFilter_BTF_Derating(boolean_T rtu_enable, real_T *rty_out,
  DW_TemporalFilter_BTF_Deratin_T *localDW);
static void SwitchCaseActionSubsystem(int16_T rtu_NoOvrdMax, int16_T
  rtu_NoOvrdMin, int16_T *rty_Out1, int16_T *rty_Out2);

/*
 * System initialize for atomic system:
 *    '<S6>/Temporal Filter_BMSError_TurtleMode'
 *    '<S6>/Temporal Filter_FaultCode_TurtleMode'
 */
static void TemporalFilter_BMSError_Tu_Init(real_T *rty_out)
{
  *rty_out = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S6>/Temporal Filter_BMSError_TurtleMode'
 *    '<S6>/Temporal Filter_FaultCode_TurtleMode'
 */
static void TemporalFilter_BMSError_TurtleM(boolean_T rtu_enable, real_T
  *rty_out, DW_TemporalFilter_BMSError_Tu_T *localDW)
{
  /* Chart: '<S6>/Temporal Filter_BMSError_TurtleMode' */
  /* Gateway: ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_BMSError_TurtleMode */
  /* During: ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_BMSError_TurtleMode */
  if (((uint32_T)localDW->is_active_c11_Throttle_mgm) == 0U) {
    /* Entry: ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_BMSError_TurtleMode */
    localDW->is_active_c11_Throttle_mgm = 1U;

    /* Entry Internal: ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_BMSError_TurtleMode */
    /* Transition: '<S12>:2' */
    localDW->is_c11_Throttle_mgm = IN_INIT;

    /* Entry 'INIT': '<S12>:1' */
    /* '<S12>:1:3' active_count = 0; */
    localDW->active_count = 0.0;

    /* '<S12>:1:4' deactive_count = 0; */
    localDW->deactive_count = 0.0;

    /* '<S12>:1:5' return_count = 0; */
    localDW->return_count = 0.0;

    /* '<S12>:1:6' out = 0; */
    *rty_out = 0.0;
  } else {
    switch (localDW->is_c11_Throttle_mgm) {
     case IN_ACTIVATION_PROCESS:
      /* During 'ACTIVATION_PROCESS': '<S12>:3' */
      /* '<S12>:8:1' sf_internal_predicateOutput = (active_count == 500) && (enable >0); */
      if ((localDW->active_count == 500.0) && rtu_enable) {
        /* Transition: '<S12>:8' */
        localDW->is_c11_Throttle_mgm = IN_CONFIRM_ERROR_PROCESS;

        /* Entry 'CONFIRM_ERROR_PROCESS': '<S12>:7' */

        /* '<S12>:9:1' sf_internal_predicateOutput = enable==0; */
      } else if (!rtu_enable) {
        /* Transition: '<S12>:9' */
        localDW->is_c11_Throttle_mgm = IN_INIT;

        /* Entry 'INIT': '<S12>:1' */
        /* '<S12>:1:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S12>:1:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S12>:1:5' return_count = 0; */
        localDW->return_count = 0.0;

        /* '<S12>:1:6' out = 0; */
        *rty_out = 0.0;
      } else {
        /* '<S12>:3:3' active_count = active_count + 1; */
        localDW->active_count++;

        /* '<S12>:3:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S12>:3:5' return_count = 0; */
        localDW->return_count = 0.0;

        /* '<S12>:3:6' out = 0; */
        *rty_out = 0.0;
      }
      break;

     case IN_BACK_FROM_ERROR:
      /* During 'BACK_FROM_ERROR': '<S12>:33' */
      /* '<S12>:35:1' sf_internal_predicateOutput = (return_count == 200) && (enable >0); */
      if ((localDW->return_count == 200.0) && rtu_enable) {
        /* Transition: '<S12>:35' */
        localDW->is_c11_Throttle_mgm = IN_OUTPUT;

        /* Entry 'OUTPUT': '<S12>:23' */
        /* '<S12>:23:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S12>:23:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S12>:23:5' return_count = 0; */
        localDW->return_count = 0.0;

        /* '<S12>:23:6' out = 1; */
        *rty_out = 1.0;

        /* '<S12>:36:1' sf_internal_predicateOutput = (return_count == 200) && (enable == 0); */
      } else if ((localDW->return_count == 200.0) && (!rtu_enable)) {
        /* Transition: '<S12>:36' */
        localDW->is_c11_Throttle_mgm = IN_INIT;

        /* Entry 'INIT': '<S12>:1' */
        /* '<S12>:1:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S12>:1:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S12>:1:5' return_count = 0; */
        localDW->return_count = 0.0;

        /* '<S12>:1:6' out = 0; */
        *rty_out = 0.0;
      } else {
        /* '<S12>:33:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S12>:33:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S12>:33:5' return_count = return_count +1; */
        localDW->return_count++;

        /* '<S12>:33:6' out = 1; */
        *rty_out = 1.0;
      }
      break;

     case IN_CONFIRM_ERROR_PROCESS:
      /* During 'CONFIRM_ERROR_PROCESS': '<S12>:7' */
      /* '<S12>:30:1' sf_internal_predicateOutput = (deactive_count == 1500) && (enable >0); */
      if ((localDW->deactive_count == 1500.0) && rtu_enable) {
        /* Transition: '<S12>:30' */
        localDW->is_c11_Throttle_mgm = IN_OUTPUT;

        /* Entry 'OUTPUT': '<S12>:23' */
        /* '<S12>:23:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S12>:23:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S12>:23:5' return_count = 0; */
        localDW->return_count = 0.0;

        /* '<S12>:23:6' out = 1; */
        *rty_out = 1.0;

        /* '<S12>:31:1' sf_internal_predicateOutput = (deactive_count == 1500) && (enable == 0); */
      } else if ((localDW->deactive_count == 1500.0) && (!rtu_enable)) {
        /* Transition: '<S12>:31' */
        localDW->is_c11_Throttle_mgm = IN_INIT;

        /* Entry 'INIT': '<S12>:1' */
        /* '<S12>:1:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S12>:1:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S12>:1:5' return_count = 0; */
        localDW->return_count = 0.0;

        /* '<S12>:1:6' out = 0; */
        *rty_out = 0.0;
      } else {
        /* '<S12>:7:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S12>:7:4' deactive_count = deactive_count +1; */
        localDW->deactive_count++;

        /* '<S12>:7:5' return_count = 0; */
        localDW->return_count = 0.0;

        /* '<S12>:7:6' out = 1; */
        *rty_out = 1.0;
      }
      break;

     case IN_INIT:
      /* During 'INIT': '<S12>:1' */
      /* '<S12>:6:1' sf_internal_predicateOutput = enable >0; */
      if (rtu_enable) {
        /* Transition: '<S12>:6' */
        localDW->is_c11_Throttle_mgm = IN_ACTIVATION_PROCESS;

        /* Entry 'ACTIVATION_PROCESS': '<S12>:3' */
      }
      break;

     default:
      /* During 'OUTPUT': '<S12>:23' */
      /* '<S12>:34:1' sf_internal_predicateOutput = enable == 0; */
      if (!rtu_enable) {
        /* Transition: '<S12>:34' */
        localDW->is_c11_Throttle_mgm = IN_BACK_FROM_ERROR;

        /* Entry 'BACK_FROM_ERROR': '<S12>:33' */
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Temporal Filter_BMSError_TurtleMode' */
}

/*
 * System initialize for atomic system:
 *    '<S6>/Temporal Filter_BTF_Derating'
 *    '<S6>/Temporal Filter_CTF_LampHandler'
 *    '<S9>/Temporal Filter_InverterFault_Derating'
 */
static void TemporalFilter_BTF_Deratin_Init(real_T *rty_out)
{
  *rty_out = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S6>/Temporal Filter_BTF_Derating'
 *    '<S6>/Temporal Filter_CTF_LampHandler'
 *    '<S9>/Temporal Filter_InverterFault_Derating'
 */
static void TemporalFilter_BTF_Derating(boolean_T rtu_enable, real_T *rty_out,
  DW_TemporalFilter_BTF_Deratin_T *localDW)
{
  /* Chart: '<S6>/Temporal Filter_BTF_Derating' */
  /* Gateway: ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_BTF_Derating */
  /* During: ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_BTF_Derating */
  if (((uint32_T)localDW->is_active_c10_Throttle_mgm) == 0U) {
    /* Entry: ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_BTF_Derating */
    localDW->is_active_c10_Throttle_mgm = 1U;

    /* Entry Internal: ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_BTF_Derating */
    /* Transition: '<S13>:2' */
    localDW->is_c10_Throttle_mgm = IN_INIT_k;

    /* Entry 'INIT': '<S13>:1' */
    /* '<S13>:1:3' active_count = 0; */
    localDW->active_count = 0.0;

    /* '<S13>:1:4' deactive_count = 0; */
    localDW->deactive_count = 0.0;

    /* '<S13>:1:5' out = 0; */
    *rty_out = 0.0;
  } else {
    switch (localDW->is_c10_Throttle_mgm) {
     case IN_ACTIVATION_PROCESS_i:
      /* During 'ACTIVATION_PROCESS': '<S13>:3' */
      /* '<S13>:8:1' sf_internal_predicateOutput = (active_count == 500) && (enable >0); */
      if ((localDW->active_count == 500.0) && rtu_enable) {
        /* Transition: '<S13>:8' */
        localDW->is_c10_Throttle_mgm = IN_CONFIRM_ERROR_PROCESS_k;

        /* Entry 'CONFIRM_ERROR_PROCESS': '<S13>:7' */

        /* '<S13>:9:1' sf_internal_predicateOutput = enable==0; */
      } else if (!rtu_enable) {
        /* Transition: '<S13>:9' */
        localDW->is_c10_Throttle_mgm = IN_INIT_k;

        /* Entry 'INIT': '<S13>:1' */
        /* '<S13>:1:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S13>:1:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S13>:1:5' out = 0; */
        *rty_out = 0.0;
      } else {
        /* '<S13>:3:3' active_count = active_count + 1; */
        localDW->active_count++;

        /* '<S13>:3:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S13>:3:5' out = 0; */
        *rty_out = 0.0;
      }
      break;

     case IN_CONFIRM_ERROR_PROCESS_k:
      /* During 'CONFIRM_ERROR_PROCESS': '<S13>:7' */
      /* '<S13>:30:1' sf_internal_predicateOutput = (deactive_count == 1500) && (enable >0); */
      if ((localDW->deactive_count == 1500.0) && rtu_enable) {
        /* Transition: '<S13>:30' */
        localDW->is_c10_Throttle_mgm = IN_OUTPUT_p;

        /* Entry 'OUTPUT': '<S13>:23' */
        /* '<S13>:23:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S13>:23:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S13>:23:5' out = 1; */
        *rty_out = 1.0;

        /* '<S13>:31:1' sf_internal_predicateOutput = (deactive_count == 1500) && (enable == 0); */
      } else if ((localDW->deactive_count == 1500.0) && (!rtu_enable)) {
        /* Transition: '<S13>:31' */
        localDW->is_c10_Throttle_mgm = IN_INIT_k;

        /* Entry 'INIT': '<S13>:1' */
        /* '<S13>:1:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S13>:1:4' deactive_count = 0; */
        localDW->deactive_count = 0.0;

        /* '<S13>:1:5' out = 0; */
        *rty_out = 0.0;
      } else {
        /* '<S13>:7:3' active_count = 0; */
        localDW->active_count = 0.0;

        /* '<S13>:7:4' deactive_count = deactive_count +1; */
        localDW->deactive_count++;

        /* '<S13>:7:5' out = 1; */
        *rty_out = 1.0;
      }
      break;

     case IN_INIT_k:
      /* During 'INIT': '<S13>:1' */
      /* '<S13>:6:1' sf_internal_predicateOutput = enable >0; */
      if (rtu_enable) {
        /* Transition: '<S13>:6' */
        localDW->is_c10_Throttle_mgm = IN_ACTIVATION_PROCESS_i;

        /* Entry 'ACTIVATION_PROCESS': '<S13>:3' */
      }
      break;

     default:
      /* During 'OUTPUT': '<S13>:23' */
      break;
    }
  }

  /* End of Chart: '<S6>/Temporal Filter_BTF_Derating' */
}

/*
 * Output and update for action system:
 *    '<S4>/Switch Case Action Subsystem'
 *    '<S4>/Switch Case Action Subsystem3'
 *    '<S4>/Switch Case Action Subsystem4'
 *    '<S4>/Switch Case Action Subsystem5'
 */
static void SwitchCaseActionSubsystem(int16_T rtu_NoOvrdMax, int16_T
  rtu_NoOvrdMin, int16_T *rty_Out1, int16_T *rty_Out2)
{
  /* SignalConversion generated from: '<S50>/NoOvrdMax' */
  *rty_Out1 = rtu_NoOvrdMax;

  /* SignalConversion generated from: '<S50>/NoOvrdMin' */
  *rty_Out2 = rtu_NoOvrdMin;
}

/* Model step function */
void Throttle_mgm_step(void)
{
  /* local block i/o variables */
  boolean_T TurtleMode;
  real_T rtb_TmpSignalConversionAtLookup[2];
  real_T rtb_Divide;
  real_T rtb_Minus;
  real_T rtb_Switch1;
  real_T rtb_Switch3_c;
  real_T rtb_Switch_k;
  real_T rtb_lut_out;
  int32_T tmp;
  real32_T rtb_TmpSignalConversionAtLook_p[2];
  real32_T rtb_Abs;
  real32_T rtb_Divide_o;
  int16_T rtb_TmpSignalConversionAtLoo_pn[11];
  int16_T rtb_TmpSignalConversionAt1DLook[10];
  int16_T rtb_Merge;
  int16_T rtb_Merge1;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_h;
  boolean_T rtb_LessThan;
  boolean_T rtb_Pedalreleased;
  InverterControl_enum_t rtb_ModeReq;

  /* Outputs for Atomic SubSystem: '<Root>/ThrottleMgm' */
  /* Outputs for Atomic SubSystem: '<S2>/Calc_percentage_signal' */
  /* SignalConversion generated from: '<S7>/Lookup with Linear Point-slope Interpolation' incorporates:
   *  Inport: '<Root>/TM_Torque_Value_1'
   *  Inport: '<Root>/TM_Torque_Value_10'
   *  Inport: '<Root>/TM_Torque_Value_11'
   *  Inport: '<Root>/TM_Torque_Value_2'
   *  Inport: '<Root>/TM_Torque_Value_3'
   *  Inport: '<Root>/TM_Torque_Value_4'
   *  Inport: '<Root>/TM_Torque_Value_5'
   *  Inport: '<Root>/TM_Torque_Value_6'
   *  Inport: '<Root>/TM_Torque_Value_7'
   *  Inport: '<Root>/TM_Torque_Value_8'
   *  Inport: '<Root>/TM_Torque_Value_9'
   */
  rtb_TmpSignalConversionAtLoo_pn[0] = get_TM_Torque_Value_1();
  rtb_TmpSignalConversionAtLoo_pn[1] = get_TM_Torque_Value_2();
  rtb_TmpSignalConversionAtLoo_pn[2] = get_TM_Torque_Value_3();
  rtb_TmpSignalConversionAtLoo_pn[3] = get_TM_Torque_Value_4();
  rtb_TmpSignalConversionAtLoo_pn[4] = get_TM_Torque_Value_5();
  rtb_TmpSignalConversionAtLoo_pn[5] = get_TM_Torque_Value_6();
  rtb_TmpSignalConversionAtLoo_pn[6] = get_TM_Torque_Value_7();
  rtb_TmpSignalConversionAtLoo_pn[7] = get_TM_Torque_Value_8();
  rtb_TmpSignalConversionAtLoo_pn[8] = get_TM_Torque_Value_9();
  rtb_TmpSignalConversionAtLoo_pn[9] = get_TM_Torque_Value_10();
  rtb_TmpSignalConversionAtLoo_pn[10] = get_TM_Torque_Value_11();

  /* Product: '<S31>/Divide' incorporates:
   *  DataTypeConversion: '<S31>/Cast'
   *  DataTypeConversion: '<S31>/Cast1'
   *  Inport: '<Root>/TM_acc_track1'
   *  Inport: '<Root>/TM_acc_track2'
   */
  rtb_Divide_o = (real32_T)((real_T)(((real_T)get_TM_acc_track1()) / ((real_T)
    get_TM_acc_track2())));

  /* Chart: '<S31>/Duble_Track_mgm' incorporates:
   *  Inport: '<Root>/TM_acc_track1'
   *  Inport: '<Root>/TM_acc_track2'
   *  Inport: '<Root>/acc_track1_fault'
   *  Inport: '<Root>/acc_track2_fault'
   */
  /* Gateway: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/Subsystem/Duble_Track_mgm */
  /* During: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/Subsystem/Duble_Track_mgm */
  if (((uint32_T)DW_Throttle_mgm.is_active_c7_Throttle_mgm) == 0U) {
    /* Entry: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/Subsystem/Duble_Track_mgm */
    DW_Throttle_mgm.is_active_c7_Throttle_mgm = 1U;

    /* Entry Internal: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/Subsystem/Duble_Track_mgm */
    /* Transition: '<S34>:2' */
    DW_Throttle_mgm.is_c7_Throttle_mgm = IN_INIT_l;

    /* Entry 'INIT': '<S34>:1' */
    /* '<S34>:1:2' App = [(track1+2*track2)/2]; */
    set_TM_AccTrack(((2.0F * get_TM_acc_track2()) + get_TM_acc_track1()) / 2.0F);

    /* '<S34>:1:3' error=0; */
    set_TM_debug_AccError(0.0);
  } else {
    switch (DW_Throttle_mgm.is_c7_Throttle_mgm) {
     case IN_APP_BROKE:
      /* During 'APP_BROKE': '<S34>:22' */
      /* '<S34>:26:1' sf_internal_predicateOutput = (track1_fault ==0)&&(track2_fault ==0); */
      if ((get_TM_acc_track1_fault() == 0) && (get_TM_acc_track2_fault() == 0))
      {
        /* Transition: '<S34>:26' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_INIT_l;

        /* Entry 'INIT': '<S34>:1' */
        /* '<S34>:1:2' App = [(track1+2*track2)/2]; */
        set_TM_AccTrack(((2.0F * get_TM_acc_track2()) + get_TM_acc_track1()) /
                        2.0F);

        /* '<S34>:1:3' error=0; */
        set_TM_debug_AccError(0.0);
      } else {
        /* '<S34>:22:2' App = 0; */
        set_TM_AccTrack(0.0F);

        /* '<S34>:22:3' error=1; */
        set_TM_debug_AccError(1.0);
      }
      break;

     case IN_COERENCE:
      /* During 'COERENCE': '<S34>:3' */
      /* '<S34>:18:1' sf_internal_predicateOutput = track1_fault ==1; */
      if (get_TM_acc_track1_fault() == 1) {
        /* Transition: '<S34>:18' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_TRACK1_FAULT;

        /* Entry 'TRACK1_FAULT': '<S34>:4' */

        /* '<S34>:21:1' sf_internal_predicateOutput = track2_fault ==1; */
      } else if (get_TM_acc_track2_fault() == 1) {
        /* Transition: '<S34>:21' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_TRACK2_FAULT;

        /* Entry 'TRACK2_FAULT': '<S34>:5' */

        /* '<S34>:46:1' sf_internal_predicateOutput = (track1_2 < 1.9)||(track1_2 > 2.1); */
      } else if ((((real_T)rtb_Divide_o) < 1.9) || (((real_T)rtb_Divide_o) > 2.1))
      {
        /* Transition: '<S34>:46' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_COERENCE_CHECK;

        /* Entry 'COERENCE_CHECK': '<S34>:13' */
        /* '<S34>:13:2' App = [(track1+2*track2)/2]; */
        set_TM_AccTrack(((2.0F * get_TM_acc_track2()) + get_TM_acc_track1()) /
                        2.0F);

        /* '<S34>:13:3' error=0; */
        set_TM_debug_AccError(0.0);
      } else {
        /* '<S34>:3:2' App = [(track1+2*track2)/2]; */
        set_TM_AccTrack(((2.0F * get_TM_acc_track2()) + get_TM_acc_track1()) /
                        2.0F);

        /* '<S34>:3:3' error=0; */
        set_TM_debug_AccError(0.0);
      }
      break;

     case IN_COERENCE_CHECK:
      /* During 'COERENCE_CHECK': '<S34>:13' */
      /* '<S34>:16:1' sf_internal_predicateOutput = (track1_2 > 1.9)&&(track1_2<2.1); */
      if ((((real_T)rtb_Divide_o) > 1.9) && (((real_T)rtb_Divide_o) < 2.1)) {
        /* Transition: '<S34>:16' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_COERENCE;

        /* Entry 'COERENCE': '<S34>:3' */

        /* '<S34>:17:1' sf_internal_predicateOutput = [(track1_2 < 1.9)||(track1_2 > 2.1)]&&(track1<track2); */
      } else if (((((real_T)rtb_Divide_o) < 1.9) || (((real_T)rtb_Divide_o) >
                   2.1)) && (get_TM_acc_track1() < get_TM_acc_track2())) {
        /* Transition: '<S34>:17' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_NON_COERENCE_TRACK1;

        /* Entry 'NON_COERENCE_TRACK1': '<S34>:10' */

        /* '<S34>:41:1' sf_internal_predicateOutput = [(track1_2 < 1.9)||(track1_2 > 2.1)]&&(track1>track2); */
      } else if (((((real_T)rtb_Divide_o) < 1.9) || (((real_T)rtb_Divide_o) >
                   2.1)) && (get_TM_acc_track1() > get_TM_acc_track2())) {
        /* Transition: '<S34>:41' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_NON_COERENCE_TRACK2;

        /* Entry 'NON_COERENCE_TRACK2': '<S34>:40' */
      } else {
        /* no actions */
      }
      break;

     case IN_INIT_l:
      /* During 'INIT': '<S34>:1' */
      /* '<S34>:6:1' sf_internal_predicateOutput = (track1_fault ==1)&&(track2_fault ==0); */
      if ((get_TM_acc_track1_fault() == 1) && (get_TM_acc_track2_fault() == 0))
      {
        /* Transition: '<S34>:6' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_TRACK1_FAULT;

        /* Entry 'TRACK1_FAULT': '<S34>:4' */

        /* '<S34>:7:1' sf_internal_predicateOutput = (track1_fault ==0)&&(track2_fault ==1); */
      } else if ((get_TM_acc_track1_fault() == 0) && (get_TM_acc_track2_fault() ==
                  1)) {
        /* Transition: '<S34>:7' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_TRACK2_FAULT;

        /* Entry 'TRACK2_FAULT': '<S34>:5' */

        /* '<S34>:14:1' sf_internal_predicateOutput = (track1_fault == 0)&&(track2_fault==0); */
      } else if ((get_TM_acc_track1_fault() == 0) && (get_TM_acc_track2_fault() ==
                  0)) {
        /* Transition: '<S34>:14' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_COERENCE_CHECK;

        /* Entry 'COERENCE_CHECK': '<S34>:13' */
        /* '<S34>:13:2' App = [(track1+2*track2)/2]; */
        set_TM_AccTrack(((2.0F * get_TM_acc_track2()) + get_TM_acc_track1()) /
                        2.0F);

        /* '<S34>:13:3' error=0; */
        set_TM_debug_AccError(0.0);

        /* '<S34>:25:1' sf_internal_predicateOutput = (track1_fault ==1)&&(track1_fault ==1); */
      } else if (get_TM_acc_track1_fault() == 1) {
        /* Transition: '<S34>:25' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_APP_BROKE;

        /* Entry 'APP_BROKE': '<S34>:22' */
      } else {
        /* no actions */
      }
      break;

     case IN_NON_COERENCE_TRACK1:
      /* During 'NON_COERENCE_TRACK1': '<S34>:10' */
      /* '<S34>:19:1' sf_internal_predicateOutput = track2_fault ==1; */
      if (get_TM_acc_track2_fault() == 1) {
        /* Transition: '<S34>:19' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_TRACK2_FAULT;

        /* Entry 'TRACK2_FAULT': '<S34>:5' */

        /* '<S34>:20:1' sf_internal_predicateOutput = track1_fault ==1; */
      } else if (get_TM_acc_track1_fault() == 1) {
        /* Transition: '<S34>:20' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_TRACK1_FAULT;

        /* Entry 'TRACK1_FAULT': '<S34>:4' */

        /* '<S34>:44:1' sf_internal_predicateOutput = (track1_2 >= 1.9)&&(track1_2<=2.1); */
      } else if ((((real_T)rtb_Divide_o) >= 1.9) && (((real_T)rtb_Divide_o) <=
                  2.1)) {
        /* Transition: '<S34>:44' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_COERENCE_CHECK;

        /* Entry 'COERENCE_CHECK': '<S34>:13' */
        /* '<S34>:13:2' App = [(track1+2*track2)/2]; */
        set_TM_AccTrack(((2.0F * get_TM_acc_track2()) + get_TM_acc_track1()) /
                        2.0F);

        /* '<S34>:13:3' error=0; */
        set_TM_debug_AccError(0.0);
      } else {
        /* '<S34>:10:2' App = track1; */
        set_TM_AccTrack(get_TM_acc_track1());

        /* '<S34>:10:3' error=1; */
        set_TM_debug_AccError(1.0);
      }
      break;

     case IN_NON_COERENCE_TRACK2:
      /* During 'NON_COERENCE_TRACK2': '<S34>:40' */
      /* '<S34>:43:1' sf_internal_predicateOutput = track2_fault ==1; */
      if (get_TM_acc_track2_fault() == 1) {
        /* Transition: '<S34>:43' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_TRACK2_FAULT;

        /* Entry 'TRACK2_FAULT': '<S34>:5' */

        /* '<S34>:42:1' sf_internal_predicateOutput = track1_fault ==1; */
      } else if (get_TM_acc_track1_fault() == 1) {
        /* Transition: '<S34>:42' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_TRACK1_FAULT;

        /* Entry 'TRACK1_FAULT': '<S34>:4' */

        /* '<S34>:45:1' sf_internal_predicateOutput = (track1_2 >= 1.9)&&(track1_2<=2.1); */
      } else if ((((real_T)rtb_Divide_o) >= 1.9) && (((real_T)rtb_Divide_o) <=
                  2.1)) {
        /* Transition: '<S34>:45' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_COERENCE_CHECK;

        /* Entry 'COERENCE_CHECK': '<S34>:13' */
        /* '<S34>:13:2' App = [(track1+2*track2)/2]; */
        set_TM_AccTrack(((2.0F * get_TM_acc_track2()) + get_TM_acc_track1()) /
                        2.0F);

        /* '<S34>:13:3' error=0; */
        set_TM_debug_AccError(0.0);
      } else {
        /* '<S34>:40:2' App = track2; */
        set_TM_AccTrack(get_TM_acc_track2());

        /* '<S34>:40:3' error=1; */
        set_TM_debug_AccError(1.0);
      }
      break;

     case IN_TRACK1_FAULT:
      /* During 'TRACK1_FAULT': '<S34>:4' */
      /* '<S34>:27:1' sf_internal_predicateOutput = (track1_fault ==0)&&(track2_fault ==0); */
      if ((get_TM_acc_track1_fault() == 0) && (get_TM_acc_track2_fault() == 0))
      {
        /* Transition: '<S34>:27' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_INIT_l;

        /* Entry 'INIT': '<S34>:1' */
        /* '<S34>:1:2' App = [(track1+2*track2)/2]; */
        set_TM_AccTrack(((2.0F * get_TM_acc_track2()) + get_TM_acc_track1()) /
                        2.0F);

        /* '<S34>:1:3' error=0; */
        set_TM_debug_AccError(0.0);

        /* '<S34>:29:1' sf_internal_predicateOutput = track2_fault ==1; */
      } else if (get_TM_acc_track2_fault() == 1) {
        /* Transition: '<S34>:29' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_APP_BROKE;

        /* Entry 'APP_BROKE': '<S34>:22' */
      } else {
        /* '<S34>:4:2' App = track2; */
        set_TM_AccTrack(get_TM_acc_track2());

        /* '<S34>:4:3' error=1; */
        set_TM_debug_AccError(1.0);
      }
      break;

     default:
      /* During 'TRACK2_FAULT': '<S34>:5' */
      /* '<S34>:28:1' sf_internal_predicateOutput = (track1_fault ==0)&&(track2_fault ==0); */
      if ((get_TM_acc_track1_fault() == 0) && (get_TM_acc_track2_fault() == 0))
      {
        /* Transition: '<S34>:28' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_INIT_l;

        /* Entry 'INIT': '<S34>:1' */
        /* '<S34>:1:2' App = [(track1+2*track2)/2]; */
        set_TM_AccTrack(((2.0F * get_TM_acc_track2()) + get_TM_acc_track1()) /
                        2.0F);

        /* '<S34>:1:3' error=0; */
        set_TM_debug_AccError(0.0);

        /* '<S34>:32:1' sf_internal_predicateOutput = track1_fault==1; */
      } else if (get_TM_acc_track1_fault() == 1) {
        /* Transition: '<S34>:32' */
        DW_Throttle_mgm.is_c7_Throttle_mgm = IN_APP_BROKE;

        /* Entry 'APP_BROKE': '<S34>:22' */
      } else {
        /* '<S34>:5:2' App = track1; */
        set_TM_AccTrack(get_TM_acc_track1());

        /* '<S34>:5:3' error=1; */
        set_TM_debug_AccError(1.0);
      }
      break;
    }
  }

  /* End of Chart: '<S31>/Duble_Track_mgm' */

  /* Product: '<S32>/Divide' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S35>/Constant'
   *  Delay: '<S32>/Delay'
   *  Inport: '<Root>/TM_alfa_filter'
   *  Product: '<S35>/Product'
   *  Product: '<S35>/Product1'
   *  Sum: '<S35>/Add'
   *  Sum: '<S35>/Add1'
   */
  rtb_Divide = (((real_T)((real32_T)((100.0F - get_TM_alfa_filter()) *
    get_TM_AccTrack()))) + (((real_T)get_TM_alfa_filter()) *
    DW_Throttle_mgm.Delay_DSTATE)) / 100.0;

  /* Switch: '<S30>/Switch' incorporates:
   *  Inport: '<Root>/TM_EcoMode'
   *  Inport: '<Root>/TM_PowerMode'
   *  Logic: '<S30>/NAND'
   *  Logic: '<S30>/NOR'
   *  Logic: '<S30>/OR'
   *  Switch: '<S30>/Switch1'
   */
  if (((!get_TM_PowerMode()) && (!get_TM_EcoMode())) || ((get_TM_EcoMode()) &&
       (get_TM_PowerMode()))) {
    /* SignalConversion generated from: '<S16>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S16>/Constant12'
     *  Constant: '<S16>/Constant13'
     */
    rtb_TmpSignalConversionAtLookup[0] = 0.0;
    rtb_TmpSignalConversionAtLookup[1] = 100.0;

    /* SignalConversion generated from: '<S16>/Lookup Table Dynamic1' incorporates:
     *  Inport: '<Root>/TM_V_acc_max'
     *  Inport: '<Root>/TM_V_acc_min'
     */
    rtb_TmpSignalConversionAtLook_p[0] = get_TM_V_acc_min();
    rtb_TmpSignalConversionAtLook_p[1] = get_TM_V_acc_max();

    /* S-Function (sfix_look1_dyn): '<S16>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S16>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real32_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_Treal32_T( &(rtb_lut_out),
      &rtb_TmpSignalConversionAtLookup[0], rtb_Divide,
      &rtb_TmpSignalConversionAtLook_p[0], 1U);

    /* SignalConversion generated from: '<S30>/1-D Lookup Table' incorporates:
     *  Inport: '<Root>/TM_Torque_Value_1'
     *  Inport: '<Root>/TM_Torque_Value_10'
     *  Inport: '<Root>/TM_Torque_Value_2'
     *  Inport: '<Root>/TM_Torque_Value_3'
     *  Inport: '<Root>/TM_Torque_Value_4'
     *  Inport: '<Root>/TM_Torque_Value_5'
     *  Inport: '<Root>/TM_Torque_Value_6'
     *  Inport: '<Root>/TM_Torque_Value_7'
     *  Inport: '<Root>/TM_Torque_Value_8'
     *  Inport: '<Root>/TM_Torque_Value_9'
     */
    rtb_TmpSignalConversionAt1DLook[0] = get_TM_Torque_Value_1();
    rtb_TmpSignalConversionAt1DLook[1] = get_TM_Torque_Value_2();
    rtb_TmpSignalConversionAt1DLook[2] = get_TM_Torque_Value_3();
    rtb_TmpSignalConversionAt1DLook[3] = get_TM_Torque_Value_4();
    rtb_TmpSignalConversionAt1DLook[4] = get_TM_Torque_Value_5();
    rtb_TmpSignalConversionAt1DLook[5] = get_TM_Torque_Value_6();
    rtb_TmpSignalConversionAt1DLook[6] = get_TM_Torque_Value_7();
    rtb_TmpSignalConversionAt1DLook[7] = get_TM_Torque_Value_8();
    rtb_TmpSignalConversionAt1DLook[8] = get_TM_Torque_Value_9();
    rtb_TmpSignalConversionAt1DLook[9] = get_TM_Torque_Value_10();

    /* Lookup_n-D: '<S30>/1-D Lookup Table' incorporates:
     *  Constant: '<S30>/x-axis'
     *  S-Function (sfix_look1_dyn): '<S16>/Lookup Table Dynamic1'
     */
    rtb_Switch_k = look1_ts16DdId_binlc(rtb_lut_out,
      ConstP_Throttle_mgm.xaxis_Value_p, rtb_TmpSignalConversionAt1DLook, 9U);
  } else if (get_TM_PowerMode()) {
    /* Switch: '<S30>/Switch1' incorporates:
     *  Constant: '<S30>/Constant1'
     */
    rtb_Switch_k = get_PowerModeLimit();
  } else {
    /* Switch: '<S30>/Switch1' incorporates:
     *  Constant: '<S30>/Constant2'
     *  Switch: '<S30>/Switch2'
     */
    rtb_Switch_k = get_EcoModeLimit();
  }

  /* End of Switch: '<S30>/Switch' */

  /* RelationalOperator: '<S16>/Pedal  released' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_Pedalreleased = (rtb_Switch_k <= 3.0);

  /* Delay: '<S28>/Delay' */
  if (rtb_Pedalreleased && (((uint32_T)PrevZCX_Throttle_mgm.Delay_Reset_ZCE) !=
       POS_ZCSIG)) {
    DW_Throttle_mgm.Delay_DSTATE_g = 0.0;
  }

  PrevZCX_Throttle_mgm.Delay_Reset_ZCE = rtb_Pedalreleased ? ((ZCSigState)1) :
    ((ZCSigState)0);

  /* RelationalOperator: '<S44>/Compare' incorporates:
   *  Constant: '<S44>/Constant'
   *  Inport: '<Root>/TM_VehicleSpeedReal'
   */
  rtb_Compare_h = (get_TM_VehicleSpeedReal() >= 10.0F);

  /* Switch: '<S23>/Switch2' incorporates:
   *  Constant: '<S23>/Constant11'
   *  Constant: '<S23>/Constant3'
   *  Inport: '<Root>/TM_MotorRPM'
   *  Logic: '<S23>/OR1'
   *  RelationalOperator: '<S23>/Relational Operator3'
   *  RelationalOperator: '<S23>/Relational Operator4'
   */
  rtb_Divide_o = (real32_T)(((get_TM_MotorRPM() > 5) || (get_TM_MotorRPM() < -5))
    ? ((int32_T)1) : ((int32_T)0));

  /* RelationalOperator: '<S9>/Less Than' incorporates:
   *  Constant: '<S9>/Constant'
   *  Inport: '<Root>/TM_VehicleSpeedReal'
   */
  rtb_LessThan = (get_TM_VehicleSpeedReal() <= 5.0F);

  /* Switch: '<S23>/Switch1' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Product: '<S23>/Divide2'
   *  Product: '<S23>/Divide3'
   *  Switch: '<S9>/Switch4'
   */
  if (rtb_Compare_h) {
    /* Switch: '<S9>/Switch4' incorporates:
     *  Constant: '<S9>/Constant1'
     *  Inport: '<Root>/TM_CoastRegPerc'
     */
    if (rtb_LessThan) {
      rtb_Minus = 0.0;
    } else {
      rtb_Minus = (real_T)get_TM_CoastRegPerc();
    }

    rtb_Switch1 = ((real_T)rtb_Divide_o) * rtb_Minus;
  } else {
    if (rtb_LessThan) {
      /* Switch: '<S9>/Switch4' incorporates:
       *  Constant: '<S9>/Constant1'
       */
      rtb_Minus = 0.0;
    } else {
      /* Switch: '<S9>/Switch4' incorporates:
       *  Inport: '<Root>/TM_CoastRegPerc'
       */
      rtb_Minus = (real_T)get_TM_CoastRegPerc();
    }

    rtb_Switch1 = (((real_T)rtb_Divide_o) * rtb_Minus) / 2.2;
  }

  /* End of Switch: '<S23>/Switch1' */

  /* Product: '<S28>/Divide' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S49>/Constant'
   *  Delay: '<S28>/Delay'
   *  Inport: '<Root>/alfa2'
   *  Product: '<S49>/Product'
   *  Product: '<S49>/Product1'
   *  Sum: '<S49>/Add'
   *  Sum: '<S49>/Add1'
   */
  rtb_lut_out = ((((real_T)((real32_T)(100.0F - get_TM_alfa_filter2()))) *
                  rtb_Switch1) + (((real_T)get_TM_alfa_filter2()) *
    DW_Throttle_mgm.Delay_DSTATE_g)) / 100.0;

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   *  Inport: '<Root>/TM_BMS_FRAME_3_soc'
   */
  rtb_Compare = (get_TM_BMS_FRAME_3_soc() <= 10.0F);

  /* Chart: '<S6>/Temporal Filter_FaultCode_TurtleMode' incorporates:
   *  Inport: '<Root>/TM_InvFault1_Code'
   *  Inport: '<Root>/TM_InvFault2_Code'
   *  Logic: '<S6>/OR2'
   *  RelationalOperator: '<S6>/Equal'
   *  RelationalOperator: '<S6>/Equal1'
   */
  TemporalFilter_BMSError_TurtleM(((get_TM_InvFault1_Code() != 0U) ||
    (get_TM_InvFault2_Code() != 0U)), &DW_Throttle_mgm.out_i,
    &DW_Throttle_mgm.sf_TemporalFilter_FaultCode_Tur);

  /* Chart: '<S6>/Temporal Filter_BMSError_TurtleMode' incorporates:
   *  Inport: '<Root>/TM_BMS_FRAME_1_abs_voltage_error'
   *  Inport: '<Root>/TM_BMS_FRAME_1_contactor_error'
   *  Inport: '<Root>/TM_BMS_FRAME_1_ov_discharg_temp_err'
   *  Inport: '<Root>/TM_BMS_FRAME_1_over_charging_temp'
   *  Inport: '<Root>/TM_BMS_FRAME_1_overvoltage_error'
   *  Inport: '<Root>/TM_BMS_FRAME_1_pec_error'
   *  Inport: '<Root>/TM_BMS_FRAME_1_un_charg_temp_err'
   *  Inport: '<Root>/TM_BMS_FRAME_1_un_discharg_temp_err'
   *  Inport: '<Root>/TM_BMS_FRAME_1_undervoltage_error'
   *  Logic: '<S6>/OR1'
   */
  TemporalFilter_BMSError_TurtleM((((((((((get_TM_BMS_FRAME_1_contactor_error())
    || (get_TM_BMS_FRAME_1_ov_discharg_temp_err())) ||
    (get_TM_BMS_FRAME_1_un_discharg_temp_err())) ||
    (get_TM_BMS_FRAME_1_un_charg_temp_err())) ||
    (get_TM_BMS_FRAME_1_abs_voltage_error())) ||
    (get_TM_BMS_FRAME_1_over_charging_temp())) ||
    (get_TM_BMS_FRAME_1_undervoltage_error())) ||
    (get_TM_BMS_FRAME_1_overvoltage_error())) || (get_TM_BMS_FRAME_1_pec_error())),
    &DW_Throttle_mgm.out_j, &DW_Throttle_mgm.sf_TemporalFilter_BMSError_Turt);

  /* Logic: '<S6>/OR4' incorporates:
   *  Logic: '<S6>/OR3'
   */
  TurtleMode = (((DW_Throttle_mgm.out_i != 0.0) || (DW_Throttle_mgm.out_j != 0.0))
                || rtb_Compare);

  /* Switch: '<S9>/Switch3' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S9>/Vehicle_speed_max_R [km//h]'
   *  Inport: '<Root>/TM_request_gear'
   *  RelationalOperator: '<S9>/Equal'
   */
  if (get_TM_request_gear() == DRIVE_GEAR) {
    /* Switch: '<S9>/Switch8' incorporates:
     *  Constant: '<S9>/Vehicle_speed_max_GHOST'
     *  Constant: '<S9>/Vehicle_speed_max_Turtle'
     *  Inport: '<Root>/TM_GHOST_mode'
     *  Switch: '<S9>/Switch9'
     */
    if (TurtleMode) {
      rtb_Switch3_c = 35.0;
    } else if (get_TM_GHOST_mode()) {
      /* Switch: '<S9>/Switch9' incorporates:
       *  Inport: '<Root>/TM_Veh_speed_max'
       */
      rtb_Switch3_c = (real_T)get_TM_Veh_speed_max();
    } else {
      rtb_Switch3_c = 59.0;
    }

    /* End of Switch: '<S9>/Switch8' */
  } else {
    rtb_Switch3_c = 15.0;
  }

  /* End of Switch: '<S9>/Switch3' */

  /* Sum: '<S26>/Minus' incorporates:
   *  Inport: '<Root>/TM_VehicleSpeedReal'
   */
  rtb_Minus = rtb_Switch3_c - ((real_T)get_TM_VehicleSpeedReal());

  /* Switch: '<S26>/Switch4' incorporates:
   *  Constant: '<S26>/Constant1'
   *  Constant: '<S26>/Constant10'
   *  Constant: '<S26>/Constant9'
   *  Lookup_n-D: '<S26>/1-D Lookup Table'
   *  Product: '<S26>/Divide1'
   *  RelationalOperator: '<S26>/GreaterThan1'
   *  Sum: '<S26>/Minus'
   */
  if (rtb_Minus > 10.0) {
    rtb_Minus = 1.0;
  } else {
    rtb_Minus = look1_binlx(rtb_Minus,
      ConstP_Throttle_mgm.uDLookupTable_bp01Data,
      ConstP_Throttle_mgm.uDLookupTable_tableData, 10U) / 100.0;
  }

  /* End of Switch: '<S26>/Switch4' */

  /* Product: '<S26>/Product' incorporates:
   *  Switch: '<S16>/Switch3'
   */
  rtb_Switch_k *= rtb_Minus;

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Constant'
   *  Product: '<S23>/Divide'
   *  Product: '<S23>/Divide1'
   *  Switch: '<S9>/Switch7'
   */
  if (rtb_Compare_h) {
    /* Switch: '<S9>/Switch7' incorporates:
     *  Constant: '<S9>/Constant3'
     *  Inport: '<Root>/TM_BrakePressedRegPerc'
     */
    if (rtb_LessThan) {
      rtb_Minus = 0.0;
    } else {
      rtb_Minus = (real_T)get_TM_BrakePressedRegPerc();
    }

    rtb_Minus *= (real_T)rtb_Divide_o;
  } else {
    if (rtb_LessThan) {
      /* Switch: '<S9>/Switch7' incorporates:
       *  Constant: '<S9>/Constant3'
       */
      rtb_Minus = 0.0;
    } else {
      /* Switch: '<S9>/Switch7' incorporates:
       *  Inport: '<Root>/TM_BrakePressedRegPerc'
       */
      rtb_Minus = (real_T)get_TM_BrakePressedRegPerc();
    }

    rtb_Minus = (rtb_Minus * ((real_T)rtb_Divide_o)) / 2.2;
  }

  /* End of Switch: '<S23>/Switch' */

  /* Delay: '<S27>/Delay' incorporates:
   *  Inport: '<Root>/TM_BBrakePedalPressed'
   */
  DW_Throttle_mgm.icLoad = (((get_TM_BBrakePedalPressed()) && (((uint32_T)
    PrevZCX_Throttle_mgm.Delay_Reset_ZCE_l) != POS_ZCSIG)) ||
    (DW_Throttle_mgm.icLoad));
  PrevZCX_Throttle_mgm.Delay_Reset_ZCE_l = get_TM_BBrakePedalPressed() ?
    ((ZCSigState)1) : ((ZCSigState)0);
  if (DW_Throttle_mgm.icLoad) {
    DW_Throttle_mgm.Delay_DSTATE_d = rtb_Switch1;
  }

  /* Product: '<S27>/Divide' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S48>/Constant'
   *  Delay: '<S27>/Delay'
   *  Inport: '<Root>/alfa2'
   *  Product: '<S48>/Product'
   *  Product: '<S48>/Product1'
   *  Sum: '<S48>/Add'
   *  Sum: '<S48>/Add1'
   */
  rtb_Switch1 = ((((real_T)((real32_T)(100.0F - get_TM_alfa_filter2()))) *
                  rtb_Minus) + (((real_T)get_TM_alfa_filter2()) *
    DW_Throttle_mgm.Delay_DSTATE_d)) / 100.0;

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S20>/Constant'
   *  Inport: '<Root>/TM_BBrakePedalPressed'
   *  Inport: '<Root>/TM_request_gear'
   *  RelationalOperator: '<S9>/Equal2'
   *  Switch: '<S9>/Switch1'
   *  Switch: '<S9>/Switch5'
   *  Switch: '<S9>/Switch6'
   */
  if (get_TM_BBrakePedalPressed()) {
    rtb_Switch_k = rtb_Switch1;
  } else if (rtb_Pedalreleased) {
    /* Switch: '<S9>/Switch1' */
    rtb_Switch_k = rtb_lut_out;
  } else if (get_TM_request_gear() == NEUTRAL_GEAR) {
    /* Switch: '<S9>/Switch6' incorporates:
     *  Constant: '<S9>/Constant7'
     *  Switch: '<S9>/Switch1'
     */
    rtb_Switch_k = 0.0;
  } else if (TurtleMode) {
    /* Switch: '<S9>/Switch6' incorporates:
     *  Constant: '<S9>/Turtle torque Limit'
     *  Product: '<S9>/Product1'
     *  Switch: '<S9>/Switch1'
     *  Switch: '<S9>/Switch2'
     *  Switch: '<S9>/Switch5'
     */
    rtb_Switch_k *= 0.8;
  } else {
    /* no actions */
  }

  /* End of Switch: '<S9>/Switch' */

  /* Switch: '<S45>/Switch7' incorporates:
   *  Constant: '<S46>/Constant'
   *  Gain: '<S45>/Multiply'
   *  Inport: '<Root>/TM_request_gear'
   *  RelationalOperator: '<S45>/Equal1'
   */
  if (get_TM_request_gear() == DRIVE_GEAR) {
    rtb_Switch_k = -rtb_Switch_k;
  }

  /* End of Switch: '<S45>/Switch7' */

  /* Switch: '<S21>/Switch7' incorporates:
   *  Constant: '<S40>/Constant'
   *  Gain: '<S21>/Multiply'
   *  Inport: '<Root>/TM_request_gear'
   *  RelationalOperator: '<S21>/Equal1'
   */
  if (get_TM_request_gear() == NEUTRAL_GEAR) {
    rtb_Minus = 0.0;
  } else {
    rtb_Minus = rtb_Switch_k;
  }

  /* End of Switch: '<S21>/Switch7' */

  /* Switch: '<S17>/Switch1' incorporates:
   *  Abs: '<S17>/Abs1'
   *  Abs: '<S17>/Abs4'
   *  Constant: '<S37>/Constant'
   *  Inport: '<Root>/TM_InvtrDCCur'
   *  Inport: '<Root>/TM_LimReqDCCurrMax'
   *  Inport: '<Root>/TM_LimReqDCCurrMin'
   *  RelationalOperator: '<S37>/Compare'
   *  Sum: '<S17>/Subtract1'
   *  Sum: '<S17>/Subtract4'
   */
  if (get_TM_InvtrDCCur() >= 0.0) {
    rtb_Switch_k = get_TM_LimReqDCCurrMax() - get_TM_InvtrDCCur();
  } else {
    rtb_Switch_k = fabs(get_TM_LimReqDCCurrMin()) - fabs(get_TM_InvtrDCCur());
  }

  /* End of Switch: '<S17>/Switch1' */

  /* Switch: '<S17>/Switch5' incorporates:
   *  Constant: '<S17>/Constant1'
   *  Constant: '<S17>/Constant6'
   *  Constant: '<S36>/Constant'
   *  Product: '<S17>/Divide3'
   *  RelationalOperator: '<S36>/Compare'
   *  Saturate: '<S17>/Saturation'
   */
  if (rtb_Switch_k > 5.0) {
    rtb_Switch_k = 1.0;
  } else {
    /* Lookup_n-D: '<S17>/1-D Lookup Table4' incorporates:
     *  Switch: '<S17>/Switch1'
     */
    rtb_Switch_k = look1_binlx(rtb_Switch_k,
      ConstP_Throttle_mgm.uDLookupTable4_bp01Data,
      ConstP_Throttle_mgm.uDLookupTable4_tableData, 5U);

    /* Saturate: '<S17>/Saturation' */
    if (rtb_Switch_k > 100.0) {
      rtb_Switch_k = 100.0;
    } else if (rtb_Switch_k < 70.0) {
      rtb_Switch_k = 70.0;
    } else {
      /* no actions */
    }

    rtb_Switch_k /= 100.0;
  }

  /* End of Switch: '<S17>/Switch5' */

  /* Product: '<S17>/Product3' */
  rtb_Switch_k *= rtb_Minus;

  /* Switch: '<S41>/Switch3' incorporates:
   *  Constant: '<S41>/Constant1'
   *  Constant: '<S43>/Constant'
   *  Inport: '<Root>/TM_request_gear'
   *  RelationalOperator: '<S41>/GreaterThan'
   *  RelationalOperator: '<S41>/GreaterThan1'
   *  RelationalOperator: '<S41>/GreaterThan2'
   */
  if (get_TM_request_gear() == REVERSE_GEAR) {
    rtb_Pedalreleased = (rtb_Switch_k >= 0.0);
  } else {
    rtb_Pedalreleased = (rtb_Switch_k <= 0.0);
  }

  /* End of Switch: '<S41>/Switch3' */

  /* Chart: '<S41>/Chart' */
  /* Gateway: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Ratelimiter_for_regen_toreque_request/CCW/Chart */
  /* During: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Ratelimiter_for_regen_toreque_request/CCW/Chart */
  if (((uint32_T)DW_Throttle_mgm.is_active_c5_Throttle_mgm) == 0U) {
    /* Entry: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Ratelimiter_for_regen_toreque_request/CCW/Chart */
    DW_Throttle_mgm.is_active_c5_Throttle_mgm = 1U;

    /* Entry Internal: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Ratelimiter_for_regen_toreque_request/CCW/Chart */
    /* Transition: '<S42>:2' */
    DW_Throttle_mgm.is_c5_Throttle_mgm = IN_INIT_b;

    /* Entry 'INIT': '<S42>:1' */
    /* '<S42>:1:2' out=0; */
    DW_Throttle_mgm.out_l = 0.0;
  } else {
    switch (DW_Throttle_mgm.is_c5_Throttle_mgm) {
     case IN_FINAL:
      /* During 'FINAL': '<S42>:5' */
      /* '<S42>:7:1' sf_internal_predicateOutput = enable == 1; */
      if (rtb_Pedalreleased) {
        /* Transition: '<S42>:7' */
        DW_Throttle_mgm.is_c5_Throttle_mgm = IN_INIT_b;

        /* Entry 'INIT': '<S42>:1' */
        /* '<S42>:1:2' out=0; */
        DW_Throttle_mgm.out_l = 0.0;
      } else {
        /* '<S42>:5:2' out = in; */
        DW_Throttle_mgm.out_l = rtb_Switch_k;
      }
      break;

     case IN_FIRSTSTEP:
      /* During 'FIRSTSTEP': '<S42>:3' */
      /* Transition: '<S42>:6' */
      DW_Throttle_mgm.is_c5_Throttle_mgm = IN_FINAL;

      /* Entry 'FINAL': '<S42>:5' */
      break;

     default:
      /* During 'INIT': '<S42>:1' */
      /* '<S42>:4:1' sf_internal_predicateOutput = enable==0; */
      if (!rtb_Pedalreleased) {
        /* Transition: '<S42>:4' */
        DW_Throttle_mgm.is_c5_Throttle_mgm = IN_FIRSTSTEP;

        /* Entry 'FIRSTSTEP': '<S42>:3' */
        /* '<S42>:3:2' out=0; */
        DW_Throttle_mgm.out_l = 0.0;
      } else {
        /* '<S42>:1:2' out=0; */
        DW_Throttle_mgm.out_l = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S41>/Chart' */

  /* RateLimiter: '<S41>/Rate Limiter' */
  rtb_Minus = DW_Throttle_mgm.out_l - DW_Throttle_mgm.PrevY;
  if (rtb_Minus > 0.9) {
    rtb_Minus = DW_Throttle_mgm.PrevY + 0.9;
  } else if (rtb_Minus < -0.9) {
    rtb_Minus = DW_Throttle_mgm.PrevY - 0.9;
  } else {
    rtb_Minus = DW_Throttle_mgm.out_l;
  }

  DW_Throttle_mgm.PrevY = rtb_Minus;

  /* End of RateLimiter: '<S41>/Rate Limiter' */

  /* Switch: '<S41>/Switch' */
  if (rtb_Pedalreleased) {
    rtb_Divide_o = (real32_T)rtb_Switch_k;
  } else {
    rtb_Divide_o = (real32_T)rtb_Minus;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Abs: '<S18>/Abs' */
  rtb_Abs = fabsf(rtb_Divide_o);

  /* Chart: '<S6>/Temporal Filter_BTF_Derating' incorporates:
   *  Inport: '<Root>/TM_BMS_FRAME_1_ov_discharg_temp_err'
   *  Inport: '<Root>/TM_BMS_FRAME_1_over_charging_temp'
   *  Inport: '<Root>/TM_BMS_FRAME_1_un_charg_temp_err'
   *  Inport: '<Root>/TM_BMS_FRAME_1_un_discharg_temp_err'
   *  Logic: '<S6>/OR6'
   */
  TemporalFilter_BTF_Derating(((((get_TM_BMS_FRAME_1_ov_discharg_temp_err()) ||
    (get_TM_BMS_FRAME_1_un_charg_temp_err())) ||
    (get_TM_BMS_FRAME_1_over_charging_temp())) ||
    (get_TM_BMS_FRAME_1_un_discharg_temp_err())), &DW_Throttle_mgm.out_f,
    &DW_Throttle_mgm.sf_TemporalFilter_BTF_Derating);

  /* Chart: '<S9>/Temporal Filter_InverterFault_Derating' incorporates:
   *  Inport: '<Root>/TM_Derating_enable'
   */
  TemporalFilter_BTF_Derating(get_TM_Derating_enable(), &DW_Throttle_mgm.out,
    &DW_Throttle_mgm.sf_TemporalFilter_InverterFault);

  /* Logic: '<S9>/NOT' incorporates:
   *  Inport: '<Root>/Emergency_button'
   *  Logic: '<S18>/NOT'
   */
  rtb_Compare_h = !get_TM_Emergency_button();

  /* Logic: '<S9>/OR' incorporates:
   *  Logic: '<S9>/NOT'
   */
  rtb_Pedalreleased = ((((DW_Throttle_mgm.out != 0.0) || (get_TM_debug_AccError()
    != 0.0)) || rtb_Compare_h) || (DW_Throttle_mgm.out_f != 0.0));

  /* Logic: '<S18>/OR' incorporates:
   *  Logic: '<S9>/AND'
   */
  rtb_Compare_h = (rtb_Compare_h || rtb_Pedalreleased);

  /* Chart: '<S18>/Chart' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Constant: '<S9>/Constant5'
   */
  /* Gateway: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Derating/Chart */
  /* During: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Derating/Chart */
  if (((uint32_T)DW_Throttle_mgm.is_active_c1_Throttle_mgm) == 0U) {
    /* Entry: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Derating/Chart */
    DW_Throttle_mgm.is_active_c1_Throttle_mgm = 1U;

    /* Entry Internal: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Derating/Chart */
    /* Transition: '<S38>:2' */
    DW_Throttle_mgm.is_c1_Throttle_mgm = IN_INIT_b;

    /* Entry 'INIT': '<S38>:1' */
    /* '<S38>:1:2' torque_out = torque_in */
    DW_Throttle_mgm.torque_out = rtb_Abs;

    /* '<S38>:1:3' count = 0 */
    DW_Throttle_mgm.count = 0.0;
  } else {
    switch (DW_Throttle_mgm.is_c1_Throttle_mgm) {
     case IN_BYPASS:
      /* During 'BYPASS': '<S38>:28' */
      /* '<S38>:35:1' sf_internal_predicateOutput = torque_in>=torque_out; */
      if (rtb_Abs >= DW_Throttle_mgm.torque_out) {
        /* Transition: '<S38>:35' */
        DW_Throttle_mgm.is_c1_Throttle_mgm = IN_TIMER;

        /* Entry 'TIMER': '<S38>:4' */

        /* '<S38>:41:1' sf_internal_predicateOutput = enable == 0; */
      } else if (!rtb_Compare_h) {
        /* Transition: '<S38>:41' */
        DW_Throttle_mgm.is_c1_Throttle_mgm = IN_INIT_b;

        /* Entry 'INIT': '<S38>:1' */
        /* '<S38>:1:2' torque_out = torque_in */
        DW_Throttle_mgm.torque_out = rtb_Abs;

        /* '<S38>:1:3' count = 0 */
        DW_Throttle_mgm.count = 0.0;
      } else {
        /* '<S38>:28:3' torque_out = torque_in */
        DW_Throttle_mgm.torque_out = rtb_Abs;

        /* '<S38>:28:4' count = 0 */
        DW_Throttle_mgm.count = 0.0;
      }
      break;

     case IN_DERATING:
      /* During 'DERATING': '<S38>:7' */
      /* '<S38>:13:1' sf_internal_predicateOutput = enable ==0; */
      if (!rtb_Compare_h) {
        /* Transition: '<S38>:13' */
        DW_Throttle_mgm.is_c1_Throttle_mgm = IN_INIT_b;

        /* Entry 'INIT': '<S38>:1' */
        /* '<S38>:1:2' torque_out = torque_in */
        DW_Throttle_mgm.torque_out = rtb_Abs;

        /* '<S38>:1:3' count = 0 */
        DW_Throttle_mgm.count = 0.0;

        /* '<S38>:20:1' sf_internal_predicateOutput = count == 0 && torque_in>torque_out; */
      } else if ((DW_Throttle_mgm.count == 0.0) && (rtb_Abs >
                  DW_Throttle_mgm.torque_out)) {
        /* Transition: '<S38>:20' */
        DW_Throttle_mgm.is_c1_Throttle_mgm = IN_TIMER;

        /* Entry 'TIMER': '<S38>:4' */

        /* '<S38>:31:1' sf_internal_predicateOutput = torque_in<torque_out; */
      } else if (rtb_Abs < DW_Throttle_mgm.torque_out) {
        /* Transition: '<S38>:31' */
        DW_Throttle_mgm.is_c1_Throttle_mgm = IN_BYPASS;

        /* Entry 'BYPASS': '<S38>:28' */
        /* '<S38>:28:3' torque_out = torque_in */
        DW_Throttle_mgm.torque_out = rtb_Abs;

        /* '<S38>:28:4' count = 0 */
        DW_Throttle_mgm.count = 0.0;
      } else {
        /* no actions */
      }
      break;

     case IN_INIT_b:
      /* During 'INIT': '<S38>:1' */
      /* '<S38>:6:1' sf_internal_predicateOutput = enable ==1; */
      if (rtb_Compare_h) {
        /* Transition: '<S38>:6' */
        DW_Throttle_mgm.is_c1_Throttle_mgm = IN_TIMER;

        /* Entry 'TIMER': '<S38>:4' */
      } else {
        /* '<S38>:1:2' torque_out = torque_in */
        DW_Throttle_mgm.torque_out = rtb_Abs;
      }
      break;

     default:
      /* During 'TIMER': '<S38>:4' */
      /* '<S38>:9:1' sf_internal_predicateOutput = count == TimeInterval; */
      if (DW_Throttle_mgm.count == 100.0) {
        /* Transition: '<S38>:9' */
        DW_Throttle_mgm.is_c1_Throttle_mgm = IN_DERATING;

        /* Entry 'DERATING': '<S38>:7' */
        /* '<S38>:7:2' torque_out = torque_out -  Step */
        DW_Throttle_mgm.torque_out -= 10.0F;

        /* '<S38>:7:3' count = 0 */
        DW_Throttle_mgm.count = 0.0;

        /* '<S38>:10:1' sf_internal_predicateOutput = enable ==0; */
      } else if (!rtb_Compare_h) {
        /* Transition: '<S38>:10' */
        DW_Throttle_mgm.is_c1_Throttle_mgm = IN_INIT_b;

        /* Entry 'INIT': '<S38>:1' */
        /* '<S38>:1:2' torque_out = torque_in */
        DW_Throttle_mgm.torque_out = rtb_Abs;

        /* '<S38>:1:3' count = 0 */
        DW_Throttle_mgm.count = 0.0;

        /* '<S38>:34:1' sf_internal_predicateOutput = torque_in<torque_out; */
      } else if (rtb_Abs < DW_Throttle_mgm.torque_out) {
        /* Transition: '<S38>:34' */
        DW_Throttle_mgm.is_c1_Throttle_mgm = IN_BYPASS;

        /* Entry 'BYPASS': '<S38>:28' */
        /* '<S38>:28:3' torque_out = torque_in */
        DW_Throttle_mgm.torque_out = rtb_Abs;

        /* '<S38>:28:4' count = 0 */
        DW_Throttle_mgm.count = 0.0;
      } else {
        /* '<S38>:4:3' count = count + 1 */
        DW_Throttle_mgm.count++;
      }
      break;
    }
  }

  /* End of Chart: '<S18>/Chart' */

  /* Switch: '<S18>/Switch' */
  if (rtb_Compare_h) {
    /* Switch: '<S18>/Switch1' incorporates:
     *  Constant: '<S9>/Constant6'
     *  RelationalOperator: '<S18>/GreaterThan'
     */
    if (DW_Throttle_mgm.torque_out <= 10.0F) {
      /* Switch: '<S18>/Switch2' incorporates:
       *  Constant: '<S18>/Constant'
       *  Inport: '<Root>/Emergency_button'
       */
      if (get_TM_Emergency_button()) {
        /* Saturate: '<S18>/Saturation' */
        if (rtb_Abs > 10.0F) {
          rtb_Switch_k = 10.0;
        } else {
          rtb_Switch_k = (real_T)rtb_Abs;
        }

        /* End of Saturate: '<S18>/Saturation' */
      } else {
        rtb_Switch_k = 0.0;
      }

      /* End of Switch: '<S18>/Switch2' */
    } else {
      rtb_Switch_k = (real_T)DW_Throttle_mgm.torque_out;
    }

    /* End of Switch: '<S18>/Switch1' */
  } else {
    rtb_Switch_k = (real_T)rtb_Abs;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Switch: '<S18>/Switch3' incorporates:
   *  Constant: '<S18>/Constant1'
   *  Constant: '<S18>/Constant2'
   *  Constant: '<S39>/Constant'
   *  RelationalOperator: '<S39>/Compare'
   */
  if (rtb_Divide_o > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Product: '<S18>/Product' incorporates:
   *  Switch: '<S18>/Switch3'
   */
  rtb_Minus = ((real_T)tmp) * rtb_Switch_k;

  /* Lookup_n-D: '<S7>/Lookup with Linear Point-slope Interpolation' incorporates:
   *  Constant: '<S7>/x-axis'
   *  Switch: '<S3>/Switch'
   */
  rtb_Switch_k = look1_ts16DdId_binlca(rtb_Minus,
    ConstP_Throttle_mgm.xaxis_Value, rtb_TmpSignalConversionAtLoo_pn, 10U);

  /* RelationalOperator: '<S26>/GreaterThan4' incorporates:
   *  Inport: '<Root>/TM_VehicleSpeedReal'
   */
  rtb_Compare_h = (((real_T)get_TM_VehicleSpeedReal()) >= rtb_Switch3_c);

  /* Chart: '<S26>/Chart' incorporates:
   *  Inport: '<Root>/TM_VehicleSpeedReal'
   */
  /* Gateway: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Vehicle_speed_limit_mgm/Chart */
  /* During: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Vehicle_speed_limit_mgm/Chart */
  if (((uint32_T)DW_Throttle_mgm.is_active_c6_Throttle_mgm) == 0U) {
    /* Entry: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Vehicle_speed_limit_mgm/Chart */
    DW_Throttle_mgm.is_active_c6_Throttle_mgm = 1U;

    /* Entry Internal: ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Vehicle_speed_limit_mgm/Chart */
    /* Transition: '<S47>:21' */
    DW_Throttle_mgm.is_c6_Throttle_mgm = IN_INIT_f;

    /* Entry 'INIT': '<S47>:18' */
  } else if (((uint32_T)DW_Throttle_mgm.is_c6_Throttle_mgm) == IN_INIT_f) {
    /* During 'INIT': '<S47>:18' */
    /* '<S47>:19:1' sf_internal_predicateOutput = control_enable == 1; */
    if (rtb_Compare_h) {
      /* Transition: '<S47>:19' */
      /* '<S47>:19:1' condition = 0 */
      DW_Throttle_mgm.is_c6_Throttle_mgm = IN_VEH_LIMITER;

      /* Entry 'VEH_LIMITER': '<S47>:22' */
    } else {
      /* '<S47>:18:2' Acc_perc_out  = ACC_perc_in; */
    }

    /* During 'VEH_LIMITER': '<S47>:22' */
    /* '<S47>:20:1' sf_internal_predicateOutput = control_enable == 0 &&( (Veh_Speed_Max - VehicleSpeed) > 3); */
  } else if ((!rtb_Compare_h) && ((((real32_T)rtb_Switch3_c) -
               get_TM_VehicleSpeedReal()) > 3.0F)) {
    /* Transition: '<S47>:20' */
    /* '<S47>:20:1' condition = 1 */
    DW_Throttle_mgm.is_c6_Throttle_mgm = IN_INIT_f;

    /* Entry 'INIT': '<S47>:18' */
  } else {
    /* '<S47>:22:2' Acc_perc_out = 5; */
  }

  /* End of Chart: '<S26>/Chart' */

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   *  Inport: '<Root>/TM_Batt12V'
   */
  rtb_Compare_h = (get_TM_Batt12V() <= 9000U);

  /* Chart: '<S6>/Temporal Filter_CTF_LampHandler' incorporates:
   *  Inport: '<Root>/TM_BMS_FRAME_1_over_charging_temp'
   *  Inport: '<Root>/TM_BMS_FRAME_1_un_charg_temp_err'
   *  Logic: '<S6>/OR'
   */
  TemporalFilter_BTF_Derating(((get_TM_BMS_FRAME_1_over_charging_temp()) ||
    (get_TM_BMS_FRAME_1_un_charg_temp_err())), &DW_Throttle_mgm.out_n,
    &DW_Throttle_mgm.sf_TemporalFilter_CTF_LampHandl);

  /* Chart: '<S3>/Startup' incorporates:
   *  Inport: '<Root>/TM_InvtrModeCtrl'
   *  Inport: '<Root>/TM_StartBattEnable'
   */
  /* Gateway: ThrottleMgm/Calc_percentage_signal/Startup */
  /* During: ThrottleMgm/Calc_percentage_signal/Startup */
  if (((uint32_T)DW_Throttle_mgm.is_active_c2_Throttle_mgm) == 0U) {
    /* Entry: ThrottleMgm/Calc_percentage_signal/Startup */
    DW_Throttle_mgm.is_active_c2_Throttle_mgm = 1U;

    /* Entry Internal: ThrottleMgm/Calc_percentage_signal/Startup */
    /* Transition: '<S8>:21' */
    DW_Throttle_mgm.is_c2_Throttle_mgm = IN_PowerOn;

    /* Entry 'PowerOn': '<S8>:1' */
    /* '<S8>:1:2' ModeReq = InverterControl_enum_t.PowerOn; */
    rtb_ModeReq = PowerOn;

    /* '<S8>:1:3' counter = 0; */
    DW_Throttle_mgm.counter = 0.0;
  } else {
    switch (DW_Throttle_mgm.is_c2_Throttle_mgm) {
     case IN_PowerOn:
      /* During 'PowerOn': '<S8>:1' */
      /* '<S8>:8:1' sf_internal_predicateOutput = Precharge == true; */
      if (get_TM_StartBattEnable()) {
        /* Transition: '<S8>:8' */
        /* Transition: '<S8>:15' */
        DW_Throttle_mgm.is_c2_Throttle_mgm = IN_Standby;

        /* Entry 'Standby': '<S8>:4' */
        /* '<S8>:4:2' ModeReq = InverterControl_enum_t.Standby; */
        rtb_ModeReq = Standby;

        /* '<S8>:4:3' counter = counter + 1; */
        DW_Throttle_mgm.counter++;
      } else {
        /* '<S8>:1:2' ModeReq = InverterControl_enum_t.PowerOn; */
        rtb_ModeReq = PowerOn;

        /* '<S8>:1:3' counter = 0; */
        DW_Throttle_mgm.counter = 0.0;
      }
      break;

     case IN_Standby:
      /* During 'Standby': '<S8>:4' */
      /* '<S8>:17:1' sf_internal_predicateOutput = MG1MF == InverterControl_enum_t.Standby && counter >= 200; */
      if ((get_TM_InvtrModeCtrl() == Standby) && (DW_Throttle_mgm.counter >=
           200.0)) {
        /* Transition: '<S8>:17' */
        /* Transition: '<S8>:18' */
        DW_Throttle_mgm.is_c2_Throttle_mgm = IN_TrqContr1;

        /* Entry 'TrqContr1': '<S8>:22' */
        /* '<S8>:22:2' ModeReq = InverterControl_enum_t.TorqueControl; */
        rtb_ModeReq = TorqueControl;
      } else {
        /* '<S8>:4:2' ModeReq = InverterControl_enum_t.Standby; */
        rtb_ModeReq = Standby;

        /* '<S8>:4:3' counter = counter + 1; */
        DW_Throttle_mgm.counter++;
      }
      break;

     default:
      /* During 'TrqContr1': '<S8>:22' */
      /* '<S8>:22:2' ModeReq = InverterControl_enum_t.TorqueControl; */
      rtb_ModeReq = TorqueControl;
      break;
    }
  }

  /* End of Chart: '<S3>/Startup' */

  /* Chart: '<S3>/Chart' incorporates:
   *  Inport: '<Root>/TM_StatusWord'
   */
  /* Gateway: ThrottleMgm/Calc_percentage_signal/Chart */
  /* During: ThrottleMgm/Calc_percentage_signal/Chart */
  if (((uint32_T)DW_Throttle_mgm.is_active_c3_Throttle_mgm) == 0U) {
    /* Entry: ThrottleMgm/Calc_percentage_signal/Chart */
    DW_Throttle_mgm.is_active_c3_Throttle_mgm = 1U;

    /* Entry Internal: ThrottleMgm/Calc_percentage_signal/Chart */
    /* Transition: '<S5>:3' */
    DW_Throttle_mgm.is_c3_Throttle_mgm = IN_start;

    /* Entry 'start': '<S5>:2' */
    /* '<S5>:2:2' ControlWord= CtrlWord_enum_t.NoCommand; */
    DW_Throttle_mgm.ControlWord = NoCommand;

    /* '<S5>:2:3' Precharge_command = 0; */
    DW_Throttle_mgm.Precharge_command = 0.0;

    /* '<S5>:2:4' enable = 0; */
  } else {
    switch (DW_Throttle_mgm.is_c3_Throttle_mgm) {
     case IN_fourth:
      /* During 'fourth': '<S5>:15' */
      /* '<S5>:13:1' sf_internal_predicateOutput = status ~= StatusWord_enum_t.Enabled; */
      if (get_TM_StatusWord() != Enabled) {
        /* Transition: '<S5>:13' */
        DW_Throttle_mgm.is_c3_Throttle_mgm = IN_start;

        /* Entry 'start': '<S5>:2' */
        /* '<S5>:2:2' ControlWord= CtrlWord_enum_t.NoCommand; */
        DW_Throttle_mgm.ControlWord = NoCommand;

        /* '<S5>:2:3' Precharge_command = 0; */
        DW_Throttle_mgm.Precharge_command = 0.0;

        /* '<S5>:2:4' enable = 0; */
      }
      break;

     case IN_second:
      DW_Throttle_mgm.ControlWord = Energise;

      /* During 'second': '<S5>:4' */
      /* '<S5>:7:1' sf_internal_predicateOutput = status == StatusWord_enum_t.Energised; */
      if (get_TM_StatusWord() == Energised) {
        /* Transition: '<S5>:7' */
        /* '<S5>:7:1' Precharge_command =1; */
        DW_Throttle_mgm.Precharge_command = 1.0;
        DW_Throttle_mgm.is_c3_Throttle_mgm = IN_third;

        /* Entry 'third': '<S5>:6' */
        /* '<S5>:6:2' ControlWord= CtrlWord_enum_t.Enable; */
        DW_Throttle_mgm.ControlWord = Enable;
      }
      break;

     case IN_start:
      DW_Throttle_mgm.ControlWord = NoCommand;

      /* During 'start': '<S5>:2' */
      /* '<S5>:5:1' sf_internal_predicateOutput = status == StatusWord_enum_t.Shutdown_status; */
      if (get_TM_StatusWord() == Shutdown_status) {
        /* Transition: '<S5>:5' */
        DW_Throttle_mgm.is_c3_Throttle_mgm = IN_second;

        /* Entry 'second': '<S5>:4' */
        /* '<S5>:4:2' ControlWord= CtrlWord_enum_t.Energise; */
        DW_Throttle_mgm.ControlWord = Energise;
      }
      break;

     default:
      DW_Throttle_mgm.ControlWord = Enable;

      /* During 'third': '<S5>:6' */
      /* '<S5>:17:1' sf_internal_predicateOutput = status==StatusWord_enum_t.Enabled; */
      if (get_TM_StatusWord() == Enabled) {
        /* Transition: '<S5>:17' */
        DW_Throttle_mgm.is_c3_Throttle_mgm = IN_fourth;

        /* Entry 'fourth': '<S5>:15' */
        /* '<S5>:15:2' enable = 1; */
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* Update for Delay: '<S32>/Delay' */
  DW_Throttle_mgm.Delay_DSTATE = rtb_Divide;

  /* Update for Delay: '<S28>/Delay' */
  DW_Throttle_mgm.Delay_DSTATE_g = rtb_lut_out;

  /* Update for Delay: '<S27>/Delay' */
  DW_Throttle_mgm.icLoad = false;
  DW_Throttle_mgm.Delay_DSTATE_d = rtb_Switch1;

  /* End of Outputs for SubSystem: '<S2>/Calc_percentage_signal' */

  /* SwitchCase: '<S4>/Switch Case' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/TM_OverrideMode'
   */
  switch (get_TM_OverrideMode()) {
   case None:
    /* Outputs for IfAction SubSystem: '<S4>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    SwitchCaseActionSubsystem(100, -100, &rtb_Merge, &rtb_Merge1);

    /* End of Outputs for SubSystem: '<S4>/Switch Case Action Subsystem' */
    break;

   case DCVoltage:
    /* Outputs for IfAction SubSystem: '<S4>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    /* SignalConversion generated from: '<S51>/OvrdVoltMax' incorporates:
     *  Inport: '<Root>/TM_OvrdVoltMax'
     */
    rtb_Merge = get_TM_OvrdVoltMax();

    /* SignalConversion generated from: '<S51>/OvrdVoltMin' incorporates:
     *  Inport: '<Root>/TM_OvrdVoltMin'
     */
    rtb_Merge1 = get_TM_OvrdVoltMin();

    /* End of Outputs for SubSystem: '<S4>/Switch Case Action Subsystem1' */
    break;

   case DCCurrent:
    /* Outputs for IfAction SubSystem: '<S4>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    /* SignalConversion generated from: '<S52>/OvrdCurrMax' incorporates:
     *  Inport: '<Root>/TM_OvrdCurrMax'
     */
    rtb_Merge = get_TM_OvrdCurrMax();

    /* SignalConversion generated from: '<S52>/OvrdCurrMin' incorporates:
     *  Inport: '<Root>/TM_OvrdCurrMin'
     */
    rtb_Merge1 = get_TM_OvrdCurrMin();

    /* End of Outputs for SubSystem: '<S4>/Switch Case Action Subsystem2' */
    break;

   case Error:
    /* Outputs for IfAction SubSystem: '<S4>/Switch Case Action Subsystem3' incorporates:
     *  ActionPort: '<S53>/Action Port'
     */
    SwitchCaseActionSubsystem(100, -100, &rtb_Merge, &rtb_Merge1);

    /* End of Outputs for SubSystem: '<S4>/Switch Case Action Subsystem3' */
    break;

   case NoAction:
    /* Outputs for IfAction SubSystem: '<S4>/Switch Case Action Subsystem4' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    SwitchCaseActionSubsystem(100, -100, &rtb_Merge, &rtb_Merge1);

    /* End of Outputs for SubSystem: '<S4>/Switch Case Action Subsystem4' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S4>/Switch Case Action Subsystem5' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    SwitchCaseActionSubsystem(100, -100, &rtb_Merge, &rtb_Merge1);

    /* End of Outputs for SubSystem: '<S4>/Switch Case Action Subsystem5' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */

  /* Outputs for Atomic SubSystem: '<S2>/Calc_percentage_signal' */
  /* DataTypeConversion: '<Root>/Cast8' incorporates:
   *  Switch: '<S3>/Switch'
   */
  set_TM_AcceleratorReqPerc((int16_T)floor(rtb_Minus));

  /* Bias: '<Root>/Add Constant3' incorporates:
   *  Logic: '<S6>/OR5'
   */
  set_TM_VCU_VEHICLE_INFO_Stop((uint8_T)(((uint32_T)((rtb_Compare_h ||
    (DW_Throttle_mgm.out_i != 0.0)) ? ((int32_T)1) : ((int32_T)0))) + 1U));

  /* End of Outputs for SubSystem: '<S2>/Calc_percentage_signal' */
  /* End of Outputs for SubSystem: '<Root>/ThrottleMgm' */

  /* Bias: '<Root>/Add Constant' incorporates:
   *  DataTypeConversion: '<Root>/Cast15'
   */
  set_TM_VCU_VEHICLE_INFO_Batt12V_LC((uint8_T)((rtb_Compare_h ? ((uint32_T)1U) :
    ((uint32_T)0U)) + 1U));

  /* Bias: '<Root>/Add Constant1' incorporates:
   *  DataTypeConversion: '<Root>/Cast17'
   */
  set_TM_PowertrainError((uint8_T)(((uint32_T)((uint8_T)DW_Throttle_mgm.out_i))
    + 1U));

  /* Bias: '<Root>/Add Constant2' incorporates:
   *  DataTypeConversion: '<Root>/Cast18'
   */
  set_TM_BatteryChargeAlert((uint8_T)((rtb_Compare ? ((uint32_T)1U) : ((uint32_T)
    0U)) + 1U));

  /* Bias: '<Root>/Add Constant4' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Boolean7'
   */
  set_TM_VCU_VEHICLE_INFO_TurtleMode((uint8_T)((TurtleMode ? ((uint32_T)1U) :
    ((uint32_T)0U)) + 1U));

  /* Bias: '<Root>/Add Constant5' incorporates:
   *  DataTypeConversion: '<Root>/Cast20'
   */
  set_TM_ChargeTemperatureFault((uint8_T)(((uint32_T)((uint8_T)
    DW_Throttle_mgm.out_n)) + 1U));

  /* Bias: '<Root>/Add Constant6' incorporates:
   *  DataTypeConversion: '<Root>/Cast21'
   */
  set_TM_BatteryTemperatureFault((uint8_T)(((uint32_T)((uint8_T)
    DW_Throttle_mgm.out_f)) + 1U));

  /* Bias: '<Root>/Add Constant7' incorporates:
   *  DataTypeConversion: '<Root>/Cast22'
   */
  set_TM_TractionBatteryFault((uint8_T)(((uint32_T)((uint8_T)
    DW_Throttle_mgm.out_j)) + 1U));

  /* DataTypeConversion: '<Root>/Cast32' incorporates:
   *  Inport: '<Root>/TM_OverrideMode'
   */
  set_TM_OvrdMode((uint8_T)get_TM_OverrideMode());

  /* DataTypeConversion: '<Root>/Cast36' */
  set_TM_InvtrSetptModeReq((uint8_T)rtb_ModeReq);

  /* DataTypeConversion: '<Root>/Cast37' */
  set_TM_TorqueDemand((int16_T)floor(rtb_Switch_k));

  /* DataTypeConversion: '<Root>/Cast41' */
  set_TM_ControlWord(DW_Throttle_mgm.ControlWord);

  /* DataTypeConversion: '<Root>/Cast51' */
  set_TM_Precharge_command(DW_Throttle_mgm.Precharge_command != 0.0);

  /* DataTypeConversion: '<Root>/Cast To Boolean12' */
  set_TM_App_corence_error_flag(get_TM_debug_AccError() != 0.0);

  /* DataTypeConversion: '<Root>/Cast To Boolean10' */
  set_TM_heater_pin(rtb_Compare);

  /* DataTypeConversion: '<Root>/Cast To Boolean11' */
  set_TM_Flag_enable_derating(rtb_Pedalreleased);

  /* DataTypeConversion: '<Root>/Cast33' */
  set_TM_LimOvrdMax(rtb_Merge);

  /* DataTypeConversion: '<Root>/Cast34' */
  set_TM_LimOvrdMin(rtb_Merge1);
}

/* Model initialize function */
void Throttle_mgm_initialize(void)
{
  PrevZCX_Throttle_mgm.Delay_Reset_ZCE = POS_ZCSIG;
  PrevZCX_Throttle_mgm.Delay_Reset_ZCE_l = POS_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/ThrottleMgm' */
  /* SystemInitialize for Atomic SubSystem: '<S2>/Calc_percentage_signal' */
  /* InitializeConditions for Delay: '<S27>/Delay' */
  DW_Throttle_mgm.icLoad = true;

  /* SystemInitialize for Chart: '<S6>/Temporal Filter_FaultCode_TurtleMode' */
  TemporalFilter_BMSError_Tu_Init(&DW_Throttle_mgm.out_i);

  /* SystemInitialize for Chart: '<S6>/Temporal Filter_BMSError_TurtleMode' */
  TemporalFilter_BMSError_Tu_Init(&DW_Throttle_mgm.out_j);

  /* SystemInitialize for Chart: '<S6>/Temporal Filter_BTF_Derating' */
  TemporalFilter_BTF_Deratin_Init(&DW_Throttle_mgm.out_f);

  /* SystemInitialize for Chart: '<S9>/Temporal Filter_InverterFault_Derating' */
  TemporalFilter_BTF_Deratin_Init(&DW_Throttle_mgm.out);

  /* SystemInitialize for Chart: '<S6>/Temporal Filter_CTF_LampHandler' */
  TemporalFilter_BTF_Deratin_Init(&DW_Throttle_mgm.out_n);

  /* End of SystemInitialize for SubSystem: '<S2>/Calc_percentage_signal' */
  /* End of SystemInitialize for SubSystem: '<Root>/ThrottleMgm' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
