/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSM.h
 *
 * Code generated for Simulink model 'FSM'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon May  6 16:23:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FSM_h_
#define RTW_HEADER_FSM_h_
#ifndef FSM_COMMON_INCLUDES_
#define FSM_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#endif                                 /* FSM_COMMON_INCLUDES_ */

#include "FSM_types.h"

/* Block states (default storage) for model 'FSM' */
typedef struct {
  uint8_t is_active_c3_FSM;            /* '<S1>/OVDetector' */
  uint8_t is_c3_FSM;                   /* '<S1>/OVDetector' */
  uint8_t SMKACADEMY_fsm_hw_switch_prev;/* '<S1>/OVDetector' */
  uint8_t SMKACADEMY_fsm_hw_switch_start;/* '<S1>/OVDetector' */
} DW_FSM_f_T;

typedef struct {
  DW_FSM_f_T rtdw;
} MdlrefDW_FSM_T;

extern void FSM(DW_FSM_f_T *localDW);

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
 * '<Root>' : 'FSM'
 * '<S1>'   : 'FSM/FSMTimingPart'
 * '<S2>'   : 'FSM/FSMTimingPart/OVDetector'
 */
#endif                                 /* RTW_HEADER_FSM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
