/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSM.c
 *
 * Code generated for Simulink model 'FSM'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Apr 28 18:20:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FSM.h"
#include <stdint.h>
#include "GLOBAL_typedef.h"
#include "FSM_typedef.h"
#include "FSM_private.h"

/* Named constants for Chart: '<S1>/OVDetector' */
#define FSM_IN_OV                      ((uint8_t)1U)
#define FSM_IN_OVFAULT                 ((uint8_t)2U)
#define FSM_IN_SENSE                   ((uint8_t)3U)

/* Output and update for referenced model: 'FSM' */
void FSM(DW_FSM_f_T *localDW)
{
  /* Outputs for Atomic SubSystem: '<Root>/FSMTimingPart' */
  /* Chart: '<S1>/OVDetector' */
  /* Gateway: FSMTimingPart/OVDetector */
  /* During: FSMTimingPart/OVDetector */
  if (localDW->is_active_c3_FSM == 0U) {
    /* Entry: FSMTimingPart/OVDetector */
    localDW->is_active_c3_FSM = 1U;

    /* Entry Internal: FSMTimingPart/OVDetector */
    /* Transition: '<S2>:2' */
    localDW->is_c3_FSM = FSM_IN_SENSE;

    /* Entry 'SENSE': '<S2>:1' */
    SMKACADEMY.fsm.state = FSM_SENSE;
  } else {
    switch (localDW->is_c3_FSM) {
     case FSM_IN_OV:
      /* During 'OV': '<S2>:3' */
      /* Transition: '<S2>:5' */
      localDW->is_c3_FSM = FSM_IN_OVFAULT;

      /* Entry 'OVFAULT': '<S2>:4' */
      SMKACADEMY.fsm.state = FSM_OVERVOLTAGE_FAULT;
      break;

     case FSM_IN_OVFAULT:
      /* During 'OVFAULT': '<S2>:4' */
      SMKACADEMY.fsm.state = FSM_OVERVOLTAGE_FAULT;
      break;

     default:
      /* During 'SENSE': '<S2>:1' */
      /* Transition: '<S2>:6' */
      localDW->is_c3_FSM = FSM_IN_OV;

      /* Entry 'OV': '<S2>:3' */
      SMKACADEMY.fsm.state = FSM_OVERVOLTAGE;
      break;
    }
  }

  /* End of Chart: '<S1>/OVDetector' */
  /* End of Outputs for SubSystem: '<Root>/FSMTimingPart' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
