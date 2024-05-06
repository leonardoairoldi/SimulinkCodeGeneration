/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FSM.c
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

#include "FSM.h"
#include <stdint.h>
#include "GLOBAL_typedef.h"
#include "FSM_typedef.h"
#include "ELECTRICAL_typedef.h"
#include "FSM_private.h"

/* Named constants for Chart: '<S1>/OVDetector' */
#define FSM_IN_STATE_FAULT             ((uint8_t)1U)
#define FSM_IN_STATE_PRECHARGE         ((uint8_t)2U)
#define FSM_IN_STATE_TSOFF             ((uint8_t)3U)
#define FSM_IN_STATE_TSON              ((uint8_t)4U)

/* Output and update for referenced model: 'FSM' */
void FSM(DW_FSM_f_T *localDW)
{
  /* Outputs for Atomic SubSystem: '<Root>/FSMTimingPart' */
  /* Chart: '<S1>/OVDetector' */
  /* Gateway: FSMTimingPart/OVDetector */
  localDW->SMKACADEMY_fsm_hw_switch_prev =
    localDW->SMKACADEMY_fsm_hw_switch_start;
  localDW->SMKACADEMY_fsm_hw_switch_start = SMKACADEMY.fsm.hw_switch;

  /* During: FSMTimingPart/OVDetector */
  if (localDW->is_active_c3_FSM == 0U) {
    localDW->SMKACADEMY_fsm_hw_switch_prev = SMKACADEMY.fsm.hw_switch;
    localDW->SMKACADEMY_fsm_hw_switch_start = SMKACADEMY.fsm.hw_switch;

    /* Entry: FSMTimingPart/OVDetector */
    localDW->is_active_c3_FSM = 1U;

    /* Entry Internal: FSMTimingPart/OVDetector */
    /* Transition: '<S2>:2' */
    localDW->is_c3_FSM = FSM_IN_STATE_TSOFF;

    /* Entry 'STATE_TSOFF': '<S2>:1' */
    SMKACADEMY.fsm.state = TS_OFF;
    SMKACADEMY.electrical.switch_state = SWITCH_DISCHARGE;
  } else {
    switch (localDW->is_c3_FSM) {
     case FSM_IN_STATE_FAULT:
      /* During 'STATE_FAULT': '<S2>:9' */
      SMKACADEMY.fsm.state = FAULT;
      break;

     case FSM_IN_STATE_PRECHARGE:
      /* During 'STATE_PRECHARGE': '<S2>:3' */
      if (SMKACADEMY.electrical.vTSAcc > 600) {
        /* Transition: '<S2>:19' */
        /* Transition: '<S2>:18' */
        /* Transition: '<S2>:12' */
        localDW->is_c3_FSM = FSM_IN_STATE_FAULT;

        /* Entry 'STATE_FAULT': '<S2>:9' */
        SMKACADEMY.fsm.state = FAULT;
      } else if ((SMKACADEMY.fsm.tPrecharge > 100) &&
                 (SMKACADEMY.electrical.vTSAcc > 0.95f * (float)
                  SMKACADEMY.electrical.vSumOfCells)) {
        /* Transition: '<S2>:5' */
        localDW->is_c3_FSM = FSM_IN_STATE_TSON;

        /* Entry 'STATE_TSON': '<S2>:4' */
        SMKACADEMY.fsm.state = TS_ON;
        SMKACADEMY.electrical.switch_state = SWITCH_CLOSED;
      } else if (((localDW->SMKACADEMY_fsm_hw_switch_prev !=
                   localDW->SMKACADEMY_fsm_hw_switch_start) &&
                  (localDW->SMKACADEMY_fsm_hw_switch_start == 1)) ||
                 (SMKACADEMY.fsm.tPrecharge > 140)) {
        /* Transition: '<S2>:28' */
        /* Transition: '<S2>:27' */
        /* Transition: '<S2>:29' */
        localDW->is_c3_FSM = FSM_IN_STATE_TSOFF;

        /* Entry 'STATE_TSOFF': '<S2>:1' */
        SMKACADEMY.fsm.state = TS_OFF;
        SMKACADEMY.electrical.switch_state = SWITCH_DISCHARGE;
      } else {
        SMKACADEMY.fsm.state = PRECHARGE;
        SMKACADEMY.electrical.switch_state = SWITCH_PRECHARGE;
        SMKACADEMY.fsm.tPrecharge = (uint8_t)(SMKACADEMY.fsm.tPrecharge + 1);
      }
      break;

     case FSM_IN_STATE_TSOFF:
      /* During 'STATE_TSOFF': '<S2>:1' */
      if (SMKACADEMY.electrical.vTSAcc > 600) {
        /* Transition: '<S2>:10' */
        /* Transition: '<S2>:12' */
        localDW->is_c3_FSM = FSM_IN_STATE_FAULT;

        /* Entry 'STATE_FAULT': '<S2>:9' */
        SMKACADEMY.fsm.state = FAULT;
      } else if ((localDW->SMKACADEMY_fsm_hw_switch_prev !=
                  localDW->SMKACADEMY_fsm_hw_switch_start) &&
                 (localDW->SMKACADEMY_fsm_hw_switch_start == 1)) {
        /* Transition: '<S2>:6' */
        localDW->is_c3_FSM = FSM_IN_STATE_PRECHARGE;

        /* Entry 'STATE_PRECHARGE': '<S2>:3' */
        SMKACADEMY.fsm.state = PRECHARGE;
        SMKACADEMY.electrical.switch_state = SWITCH_PRECHARGE;
        SMKACADEMY.fsm.tPrecharge = 1U;
      } else {
        SMKACADEMY.fsm.state = TS_OFF;
        SMKACADEMY.electrical.switch_state = SWITCH_DISCHARGE;
      }
      break;

     default:
      /* During 'STATE_TSON': '<S2>:4' */
      if (SMKACADEMY.electrical.vTSAcc > 600) {
        /* Transition: '<S2>:16' */
        /* Transition: '<S2>:17' */
        /* Transition: '<S2>:18' */
        /* Transition: '<S2>:12' */
        localDW->is_c3_FSM = FSM_IN_STATE_FAULT;

        /* Entry 'STATE_FAULT': '<S2>:9' */
        SMKACADEMY.fsm.state = FAULT;
      } else if ((localDW->SMKACADEMY_fsm_hw_switch_prev !=
                  localDW->SMKACADEMY_fsm_hw_switch_start) &&
                 (localDW->SMKACADEMY_fsm_hw_switch_start == 1)) {
        /* Transition: '<S2>:24' */
        /* Transition: '<S2>:25' */
        /* Transition: '<S2>:27' */
        /* Transition: '<S2>:29' */
        localDW->is_c3_FSM = FSM_IN_STATE_TSOFF;

        /* Entry 'STATE_TSOFF': '<S2>:1' */
        SMKACADEMY.fsm.state = TS_OFF;
        SMKACADEMY.electrical.switch_state = SWITCH_DISCHARGE;
      } else {
        SMKACADEMY.fsm.state = TS_ON;
        SMKACADEMY.electrical.switch_state = SWITCH_CLOSED;
      }
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
