/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CircuitInterface.h
 *
 * Code generated for Simulink model 'CircuitInterface'.
 *
 * Model version                  : 1.58
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu May 23 00:55:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CircuitInterface_h_
#define RTW_HEADER_CircuitInterface_h_
#ifndef CircuitInterface_COMMON_INCLUDES_
#define CircuitInterface_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#endif                                 /* CircuitInterface_COMMON_INCLUDES_ */

#include "CircuitInterface_types.h"
#include "rt_nonfinite.h"

/* Block signals for model 'CircuitInterface' */
typedef struct {
  float TmpRTBAtModelInputUnpackOutport;/* '<Root>/ModelInputUnpack' */
  float TmpRTBAtModelInputUnpackOutpo_f;/* '<Root>/ModelInputUnpack' */
  float TmpRTBAtModelInputUnpackOutpo_o;/* '<Root>/ModelInputUnpack' */
  float TmpRTBAtModelOutport1;         /* '<Root>/Model' */
  float TmpRTBAtModelOutport2;         /* '<Root>/Model' */
  uint8_t TmpRTBAtModelInputUnpackOutpo_n;/* '<Root>/ModelInputUnpack' */
} B_CircuitInterface_c_T;

/* Block states (default storage) for model 'CircuitInterface' */
typedef struct {
  float Delay1_DSTATE;                 /* '<S1>/Delay1' */
  float DiscreteTransferFcn1_states;   /* '<S1>/Discrete Transfer Fcn1' */
} DW_CircuitInterface_f_T;

typedef struct {
  B_CircuitInterface_c_T rtb;
  DW_CircuitInterface_f_T rtdw;
} MdlrefDW_CircuitInterface_T;

/* Model reference registration function */
extern void CircuitInterface_initialize(void);
extern void CircuitInterfaceTID0(B_CircuitInterface_c_T *localB);
extern void CircuitInterfaceTID1(B_CircuitInterface_c_T *localB,
  DW_CircuitInterface_f_T *localDW);
extern void CircuitInterfaceTID2(B_CircuitInterface_c_T *localB);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S2>/Constant2' : Unused code path elimination
 * Block '<S2>/Equal2' : Unused code path elimination
 * Block '<S2>/Gain2' : Unused code path elimination
 * Block '<S1>/Cast' : Eliminate redundant data type conversion
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
 * '<Root>' : 'CircuitInterface'
 * '<S1>'   : 'CircuitInterface/Model'
 * '<S2>'   : 'CircuitInterface/ModelInputUnpack'
 * '<S3>'   : 'CircuitInterface/ModelOutputPack'
 */
#endif                                 /* RTW_HEADER_CircuitInterface_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
