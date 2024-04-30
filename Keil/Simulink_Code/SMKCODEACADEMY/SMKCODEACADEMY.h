/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SMKCODEACADEMY.h
 *
 * Code generated for Simulink model 'SMKCODEACADEMY'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Apr 30 10:13:33 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SMKCODEACADEMY_h_
#define RTW_HEADER_SMKCODEACADEMY_h_
#ifndef SMKCODEACADEMY_COMMON_INCLUDES_
#define SMKCODEACADEMY_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#endif                                 /* SMKCODEACADEMY_COMMON_INCLUDES_ */

#include "SMKCODEACADEMY_types.h"
#include "CircuitInterface.h"
#include "FSM.h"
#include "GLOBAL_typedef.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
#define rtmCounterLimit(rtm, idx)      ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  MdlrefDW_CircuitInterface_T Circuit_InstanceData;/* '<Root>/Circuit' */
  MdlrefDW_FSM_T FSM_InstanceData;     /* '<Root>/FSM' */
} DW_SMKCODEACADEMY_T;

/* Real-time Model Data Structure */
struct tag_RTM_SMKCODEACADEMY_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_t TID[4];
      uint32_t cLimit[4];
    } TaskCounters;
  } Timing;
};

/* Block states (default storage) */
extern DW_SMKCODEACADEMY_T SMKCODEACADEMY_DW;

/* Model entry point functions */
extern void Simulink_Init(void);
extern void ModelInputUnpack_Simulink(void);
extern void Model_Simulink(void);
extern void ModelOutputPack_Simulink(void);
extern void FSM_Simulink(void);
extern void Simulink_End(void);

/* Real-time Model object */
extern RT_MODEL_SMKCODEACADEMY_T *const SMKCODEACADEMY_M;

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
 * '<Root>' : 'SMKCODEACADEMY'
 */
#endif                                 /* RTW_HEADER_SMKCODEACADEMY_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
