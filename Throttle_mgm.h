/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Throttle_mgm.h
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

#ifndef RTW_HEADER_Throttle_mgm_h_
#define RTW_HEADER_Throttle_mgm_h_
#ifndef Throttle_mgm_COMMON_INCLUDES_
#define Throttle_mgm_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Throttle_mgm_COMMON_INCLUDES_ */

#include "VirtualBus.h"
#include "zero_crossing_types.h"

/* Includes for objects with custom storage classes */
#include "VirtualBus_TM.h"
#include "Virtualbus_TM.h"

/* Block signals and states (default storage) for system '<S6>/Temporal Filter_BMSError_TurtleMode' */
typedef struct {
  real_T active_count;          /* '<S6>/Temporal Filter_BMSError_TurtleMode' */
  real_T deactive_count;        /* '<S6>/Temporal Filter_BMSError_TurtleMode' */
  real_T return_count;          /* '<S6>/Temporal Filter_BMSError_TurtleMode' */
  uint8_T is_c11_Throttle_mgm;  /* '<S6>/Temporal Filter_BMSError_TurtleMode' */
  uint8_T is_active_c11_Throttle_mgm;
                                /* '<S6>/Temporal Filter_BMSError_TurtleMode' */
} DW_TemporalFilter_BMSError_Tu_T;

/* Block signals and states (default storage) for system '<S6>/Temporal Filter_BTF_Derating' */
typedef struct {
  real_T active_count;                 /* '<S6>/Temporal Filter_BTF_Derating' */
  real_T deactive_count;               /* '<S6>/Temporal Filter_BTF_Derating' */
  uint8_T is_c10_Throttle_mgm;         /* '<S6>/Temporal Filter_BTF_Derating' */
  uint8_T is_active_c10_Throttle_mgm;  /* '<S6>/Temporal Filter_BTF_Derating' */
} DW_TemporalFilter_BTF_Deratin_T;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_TemporalFilter_BTF_Deratin_T sf_TemporalFilter_InverterFault;
                             /* '<S9>/Temporal Filter_InverterFault_Derating' */
  DW_TemporalFilter_BMSError_Tu_T sf_TemporalFilter_FaultCode_Tur;
                               /* '<S6>/Temporal Filter_FaultCode_TurtleMode' */
  DW_TemporalFilter_BTF_Deratin_T sf_TemporalFilter_CTF_LampHandl;
                                    /* '<S6>/Temporal Filter_CTF_LampHandler' */
  DW_TemporalFilter_BTF_Deratin_T sf_TemporalFilter_BTF_Derating;/* '<S6>/Temporal Filter_BTF_Derating' */
  DW_TemporalFilter_BMSError_Tu_T sf_TemporalFilter_BMSError_Turt;
                                /* '<S6>/Temporal Filter_BMSError_TurtleMode' */
  real_T out;                /* '<S9>/Temporal Filter_InverterFault_Derating' */
  real_T out_l;                        /* '<S41>/Chart' */
  real_T out_i;                /* '<S6>/Temporal Filter_FaultCode_TurtleMode' */
  real_T out_n;                     /* '<S6>/Temporal Filter_CTF_LampHandler' */
  real_T out_f;                        /* '<S6>/Temporal Filter_BTF_Derating' */
  real_T out_j;                 /* '<S6>/Temporal Filter_BMSError_TurtleMode' */
  real_T Precharge_command;            /* '<S3>/Chart' */
  real_T Delay_DSTATE;                 /* '<S32>/Delay' */
  real_T Delay_DSTATE_g;               /* '<S28>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S27>/Delay' */
  real_T PrevY;                        /* '<S41>/Rate Limiter' */
  real_T count;                        /* '<S18>/Chart' */
  real_T counter;                      /* '<S3>/Startup' */
  real32_T torque_out;                 /* '<S18>/Chart' */
  CtrlWord_enum_t ControlWord;         /* '<S3>/Chart' */
  uint8_T is_c6_Throttle_mgm;          /* '<S26>/Chart' */
  uint8_T is_active_c6_Throttle_mgm;   /* '<S26>/Chart' */
  uint8_T is_c5_Throttle_mgm;          /* '<S41>/Chart' */
  uint8_T is_active_c5_Throttle_mgm;   /* '<S41>/Chart' */
  uint8_T is_c1_Throttle_mgm;          /* '<S18>/Chart' */
  uint8_T is_active_c1_Throttle_mgm;   /* '<S18>/Chart' */
  uint8_T is_c7_Throttle_mgm;          /* '<S31>/Duble_Track_mgm' */
  uint8_T is_active_c7_Throttle_mgm;   /* '<S31>/Duble_Track_mgm' */
  uint8_T is_c2_Throttle_mgm;          /* '<S3>/Startup' */
  uint8_T is_active_c2_Throttle_mgm;   /* '<S3>/Startup' */
  uint8_T is_c3_Throttle_mgm;          /* '<S3>/Chart' */
  uint8_T is_active_c3_Throttle_mgm;   /* '<S3>/Chart' */
  boolean_T icLoad;                    /* '<S27>/Delay' */
} DW_Throttle_mgm_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S28>/Delay' */
  ZCSigState Delay_Reset_ZCE_l;        /* '<S27>/Delay' */
} PrevZCX_Throttle_mgm_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [70;75;80;85;90;95]
   * Referenced by: '<S17>/1-D Lookup Table4'
   */
  real_T uDLookupTable4_tableData[6];

  /* Expression: [0;1;2;3;4;5]
   * Referenced by: '<S17>/1-D Lookup Table4'
   */
  real_T uDLookupTable4_bp01Data[6];

  /* Expression: [-10;-5;5;15;25;35;45;55;70;80;85]
   * Referenced by: '<S26>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[11];

  /* Expression: [-10;-5;0;3;4;5;6;7;8;9;10]
   * Referenced by: '<S26>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[11];

  /* Expression: [-100,-80,-60,-40,-20,0,20,40,60,80,100]
   * Referenced by: '<S7>/x-axis'
   */
  real_T xaxis_Value[11];

  /* Expression: [0 10 20 30 40 60 70 80 90 100]
   * Referenced by: '<S30>/x-axis'
   */
  real_T xaxis_Value_p[10];
} ConstP_Throttle_mgm_T;

/* Block signals and states (default storage) */
extern DW_Throttle_mgm_T DW_Throttle_mgm;

/* Zero-crossing (trigger) state */
extern PrevZCX_Throttle_mgm_T PrevZCX_Throttle_mgm;

/* Constant parameters (default storage) */
extern const ConstP_Throttle_mgm_T ConstP_Throttle_mgm;

/* Model entry point functions */
extern void Throttle_mgm_initialize(void);
extern void Throttle_mgm_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Cast' : Unused code path elimination
 * Block '<Root>/Cast1' : Unused code path elimination
 * Block '<S16>/Display1' : Unused code path elimination
 * Block '<S16>/Display2' : Unused code path elimination
 * Block '<S16>/Display3' : Unused code path elimination
 * Block '<S16>/Relational Operator1' : Unused code path elimination
 * Block '<S9>/Display' : Unused code path elimination
 * Block '<S26>/Rate Limiter' : Unused code path elimination
 * Block '<S26>/Switch' : Unused code path elimination
 * Block '<S2>/Display' : Unused code path elimination
 * Block '<Root>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Boolean1' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Boolean2' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Boolean3' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Boolean4' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Boolean5' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Boolean6' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Boolean8' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Boolean9' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Single' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Single1' : Eliminate redundant data type conversion
 * Block '<Root>/Cast To Single2' : Eliminate redundant data type conversion
 * Block '<Root>/Cast10' : Eliminate redundant data type conversion
 * Block '<Root>/Cast11' : Eliminate redundant data type conversion
 * Block '<Root>/Cast12' : Eliminate redundant data type conversion
 * Block '<Root>/Cast13' : Eliminate redundant data type conversion
 * Block '<Root>/Cast14' : Eliminate redundant data type conversion
 * Block '<Root>/Cast16' : Eliminate redundant data type conversion
 * Block '<Root>/Cast19' : Eliminate redundant data type conversion
 * Block '<Root>/Cast23' : Eliminate redundant data type conversion
 * Block '<Root>/Cast24' : Eliminate redundant data type conversion
 * Block '<Root>/Cast25' : Eliminate redundant data type conversion
 * Block '<Root>/Cast26' : Eliminate redundant data type conversion
 * Block '<Root>/Cast27' : Eliminate redundant data type conversion
 * Block '<Root>/Cast28' : Eliminate redundant data type conversion
 * Block '<Root>/Cast29' : Eliminate redundant data type conversion
 * Block '<Root>/Cast3' : Eliminate redundant data type conversion
 * Block '<Root>/Cast30' : Eliminate redundant data type conversion
 * Block '<Root>/Cast31' : Eliminate redundant data type conversion
 * Block '<Root>/Cast35' : Eliminate redundant data type conversion
 * Block '<Root>/Cast38' : Eliminate redundant data type conversion
 * Block '<Root>/Cast39' : Eliminate redundant data type conversion
 * Block '<Root>/Cast4' : Eliminate redundant data type conversion
 * Block '<Root>/Cast40' : Eliminate redundant data type conversion
 * Block '<Root>/Cast42' : Eliminate redundant data type conversion
 * Block '<Root>/Cast43' : Eliminate redundant data type conversion
 * Block '<Root>/Cast44' : Eliminate redundant data type conversion
 * Block '<Root>/Cast45' : Eliminate redundant data type conversion
 * Block '<Root>/Cast46' : Eliminate redundant data type conversion
 * Block '<Root>/Cast47' : Eliminate redundant data type conversion
 * Block '<Root>/Cast48' : Eliminate redundant data type conversion
 * Block '<Root>/Cast49' : Eliminate redundant data type conversion
 * Block '<Root>/Cast5' : Eliminate redundant data type conversion
 * Block '<Root>/Cast50' : Eliminate redundant data type conversion
 * Block '<Root>/Cast52' : Eliminate redundant data type conversion
 * Block '<Root>/Cast53' : Eliminate redundant data type conversion
 * Block '<Root>/Cast55' : Eliminate redundant data type conversion
 * Block '<Root>/Cast56' : Eliminate redundant data type conversion
 * Block '<Root>/Cast57' : Eliminate redundant data type conversion
 * Block '<Root>/Cast58' : Eliminate redundant data type conversion
 * Block '<Root>/Cast6' : Eliminate redundant data type conversion
 * Block '<Root>/Cast7' : Eliminate redundant data type conversion
 * Block '<Root>/Cast9' : Eliminate redundant data type conversion
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S16>/1-D Lookup Table1' : Unused code path elimination
 * Block '<S16>/Add1' : Unused code path elimination
 * Block '<S16>/Constant1' : Unused code path elimination
 * Block '<S16>/Constant4' : Unused code path elimination
 * Block '<S16>/Constant5' : Unused code path elimination
 * Block '<S16>/Constant6' : Unused code path elimination
 * Block '<S16>/Gain' : Unused code path elimination
 * Block '<S16>/Gain1' : Unused code path elimination
 * Block '<S16>/Product' : Unused code path elimination
 * Block '<S16>/Relational Operator2' : Unused code path elimination
 * Block '<S16>/Saturation' : Unused code path elimination
 * Block '<S16>/Subtract' : Unused code path elimination
 * Block '<S16>/Switch4' : Unused code path elimination
 * Block '<S9>/max_veh_speed_ON' : Unused code path elimination
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
 * '<Root>' : 'Throttle_mgm'
 * '<S1>'   : 'Throttle_mgm/Model Info'
 * '<S2>'   : 'Throttle_mgm/ThrottleMgm'
 * '<S3>'   : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal'
 * '<S4>'   : 'Throttle_mgm/ThrottleMgm/Override_subsystem'
 * '<S5>'   : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Chart'
 * '<S6>'   : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation'
 * '<S7>'   : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/LookUp Table Conversion'
 * '<S8>'   : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Startup'
 * '<S9>'   : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode'
 * '<S10>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Compare To Constant'
 * '<S11>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Compare To Constant1'
 * '<S12>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_BMSError_TurtleMode'
 * '<S13>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_BTF_Derating'
 * '<S14>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_CTF_LampHandler'
 * '<S15>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/DashboardSignalsEvaluation/Temporal Filter_FaultCode_TurtleMode'
 * '<S16>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc'
 * '<S17>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/CurrentLimiter_Torque_request1'
 * '<S18>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Derating'
 * '<S19>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Enumerated Constant'
 * '<S20>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Enumerated Constant1'
 * '<S21>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Neutral check'
 * '<S22>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Ratelimiter_for_regen_toreque_request'
 * '<S23>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Reg_enable'
 * '<S24>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Request_mode_selection'
 * '<S25>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Temporal Filter_InverterFault_Derating'
 * '<S26>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Vehicle_speed_limit_mgm'
 * '<S27>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/reg_brake_filter'
 * '<S28>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/reg_coast_filter'
 * '<S29>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/Double_Track_Mgm'
 * '<S30>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/EngineModeEvaluation'
 * '<S31>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/Subsystem'
 * '<S32>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/accelerator_filter'
 * '<S33>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/Double_Track_Mgm/Single_Track_mgm'
 * '<S34>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/Subsystem/Duble_Track_mgm'
 * '<S35>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Acceleration_calc/accelerator_filter/First_order_filter'
 * '<S36>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/CurrentLimiter_Torque_request1/Compare To Constant3'
 * '<S37>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/CurrentLimiter_Torque_request1/Compare To Zero2'
 * '<S38>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Derating/Chart'
 * '<S39>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Derating/Compare To Constant'
 * '<S40>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Neutral check/Enumerated Constant'
 * '<S41>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Ratelimiter_for_regen_toreque_request/CCW'
 * '<S42>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Ratelimiter_for_regen_toreque_request/CCW/Chart'
 * '<S43>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Ratelimiter_for_regen_toreque_request/CCW/Enumerated Constant2'
 * '<S44>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Reg_enable/Compare To Constant'
 * '<S45>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Request_mode_selection/CCW'
 * '<S46>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Request_mode_selection/CCW/Enumerated Constant'
 * '<S47>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/Vehicle_speed_limit_mgm/Chart'
 * '<S48>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/reg_brake_filter/First_order_filter'
 * '<S49>'  : 'Throttle_mgm/ThrottleMgm/Calc_percentage_signal/Torque_control_mode/reg_coast_filter/First_order_filter'
 * '<S50>'  : 'Throttle_mgm/ThrottleMgm/Override_subsystem/Switch Case Action Subsystem'
 * '<S51>'  : 'Throttle_mgm/ThrottleMgm/Override_subsystem/Switch Case Action Subsystem1'
 * '<S52>'  : 'Throttle_mgm/ThrottleMgm/Override_subsystem/Switch Case Action Subsystem2'
 * '<S53>'  : 'Throttle_mgm/ThrottleMgm/Override_subsystem/Switch Case Action Subsystem3'
 * '<S54>'  : 'Throttle_mgm/ThrottleMgm/Override_subsystem/Switch Case Action Subsystem4'
 * '<S55>'  : 'Throttle_mgm/ThrottleMgm/Override_subsystem/Switch Case Action Subsystem5'
 */

/*-
 * Requirements for '<Root>': Throttle_mgm

 */
#endif                                 /* RTW_HEADER_Throttle_mgm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
