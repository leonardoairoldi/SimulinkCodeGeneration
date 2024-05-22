/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SMKCODEACADEMY.c
 *
 * Code generated for Simulink model 'SMKCODEACADEMY'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu May 23 00:55:29 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SMKCODEACADEMY.h"
#include "FSM.h"
#include "CircuitInterface.h"

/* Block states (default storage) */
DW_SMKCODEACADEMY_T SMKCODEACADEMY_DW;

/* Real-time model */
static RT_MODEL_SMKCODEACADEMY_T SMKCODEACADEMY_M_;
RT_MODEL_SMKCODEACADEMY_T *const SMKCODEACADEMY_M = &SMKCODEACADEMY_M_;

/* Model step function for TID0 */
void ModelInputUnpack_Simulink(void)
                                   /* Explicit Task: Circuit.ModelInputUnpack */
{
  /* ModelReference: '<Root>/Circuit' */
  CircuitInterfaceTID0(&(SMKCODEACADEMY_DW.Circuit_InstanceData.rtb));
}

/* Model step function for TID1 */
void Model_Simulink(void)           /* Explicit Task: Circuit.CiruitSubsystem */
{
  /* ModelReference: '<Root>/Circuit' */
  CircuitInterfaceTID1(&(SMKCODEACADEMY_DW.Circuit_InstanceData.rtb),
                       &(SMKCODEACADEMY_DW.Circuit_InstanceData.rtdw));
}

/* Model step function for TID2 */
void ModelOutputPack_Simulink(void) /* Explicit Task: Circuit.ModelOutputPack */
{
  /* ModelReference: '<Root>/Circuit' */
  CircuitInterfaceTID2(&(SMKCODEACADEMY_DW.Circuit_InstanceData.rtb));
}

/* Model step function for TID3 */
void FSM_Simulink(void)                /* Explicit Task: FSM.FSMTimingPart */
{
  /* ModelReference: '<Root>/FSM' */
  FSM(&(SMKCODEACADEMY_DW.FSM_InstanceData.rtdw));
}

/* Model initialize function */
void Simulink_Init(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (SMKCODEACADEMY_M)->Timing.TaskCounters.cLimit[0] = 1;
  (SMKCODEACADEMY_M)->Timing.TaskCounters.cLimit[1] = 1;
  (SMKCODEACADEMY_M)->Timing.TaskCounters.cLimit[2] = 1;
  (SMKCODEACADEMY_M)->Timing.TaskCounters.cLimit[3] = 10;

  /* Model Initialize function for ModelReference Block: '<Root>/Circuit' */
  CircuitInterface_initialize();
}

/* Model terminate function */
void Simulink_End(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
