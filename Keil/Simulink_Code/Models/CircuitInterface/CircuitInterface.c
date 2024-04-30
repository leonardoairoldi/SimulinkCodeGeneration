/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CircuitInterface.c
 *
 * Code generated for Simulink model 'CircuitInterface'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Apr 30 10:13:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CircuitInterface.h"
#include "GLOBAL_typedef.h"
#include "ELECTRICAL_typedef.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <stdint.h>
#include "CircuitInterface_private.h"

/* Output and update for referenced model: 'CircuitInterface' */
void CircuitInterfaceTID0(B_CircuitInterface_c_T *localB)
{
  /* Outputs for Atomic SubSystem: '<Root>/ModelInputUnpack' */
  /* RateTransition generated from: '<Root>/ModelInputUnpack' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataStoreRead: '<S2>/Data Store Read'
   *  RelationalOperator: '<S2>/Equal'
   */
  localB->TmpRTBAtModelInputUnpackOutport = (float)
    (SMKACADEMY.electrical.switch_state == SWITCH_CLOSED);

  /* End of Outputs for SubSystem: '<Root>/ModelInputUnpack' */
}

/* Output and update for referenced model: 'CircuitInterface' */
void CircuitInterfaceTID1(B_CircuitInterface_c_T *localB,
  DW_CircuitInterface_f_T *localDW)
{
  /* Outputs for Atomic SubSystem: '<Root>/Model' */
  /* RateTransition generated from: '<Root>/Model' incorporates:
   *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
   */
  localB->Vout = 0.002497F * localDW->DiscreteTransferFcn_states;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  SignalConversion generated from: '<S1>/Switch_State'
   */
  if ((localB->TmpRTBAtModelInputUnpackOutport != 0.0F) ||
      (localDW->DiscreteTimeIntegrator_PrevRese != 0)) {
    localDW->DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  /* RateTransition generated from: '<Root>/Model' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   */
  localB->Pin = localDW->DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' incorporates:
   *  SignalConversion generated from: '<S1>/Switch_State'
   */
  localDW->DiscreteTransferFcn_states = localB->TmpRTBAtModelInputUnpackOutport
    - -0.9975F * localDW->DiscreteTransferFcn_states;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  SignalConversion generated from: '<S1>/Switch_State'
   */
  localDW->DiscreteTimeIntegrator_DSTATE += 0.005;
  if (localB->TmpRTBAtModelInputUnpackOutport > 0.0F) {
    localDW->DiscreteTimeIntegrator_PrevRese = 1;
  } else if (localB->TmpRTBAtModelInputUnpackOutport < 0.0F) {
    localDW->DiscreteTimeIntegrator_PrevRese = -1;
  } else if (localB->TmpRTBAtModelInputUnpackOutport == 0.0F) {
    localDW->DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    localDW->DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* RateTransition generated from: '<Root>/Model' incorporates:
   *  SignalConversion generated from: '<S1>/Switch_State'
   */
  localB->Vin = localB->TmpRTBAtModelInputUnpackOutport;

  /* End of Outputs for SubSystem: '<Root>/Model' */
}

/* Output and update for referenced model: 'CircuitInterface' */
void CircuitInterfaceTID2(B_CircuitInterface_c_T *localB)
{
  double tmp;
  float tmp_0;

  /* Outputs for Atomic SubSystem: '<Root>/ModelOutputPack' */
  /* DataTypeConversion: '<S3>/Cast' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write'
   *  Gain: '<S3>/Gain'
   */
  tmp_0 = (float)floor(1000.0F * localB->Vout);
  if (rtIsNaNF(tmp_0) || rtIsInfF(tmp_0)) {
    tmp_0 = 0.0F;
  } else {
    tmp_0 = (float)fmod(tmp_0, 65536.0);
  }

  SMKACADEMY.electrical.Vout = (uint16_t)(tmp_0 < 0.0F ? (int32_t)(uint16_t)-
    (int16_t)(uint16_t)-tmp_0 : (int32_t)(uint16_t)tmp_0);

  /* End of DataTypeConversion: '<S3>/Cast' */

  /* DataTypeConversion: '<S3>/Cast1' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write1'
   *  Gain: '<S3>/Gain1'
   */
  tmp_0 = (float)floor(1000.0F * localB->Vin);
  if (rtIsNaNF(tmp_0) || rtIsInfF(tmp_0)) {
    tmp_0 = 0.0F;
  } else {
    tmp_0 = (float)fmod(tmp_0, 65536.0);
  }

  SMKACADEMY.electrical.Vin = (uint16_t)(tmp_0 < 0.0F ? (int32_t)(uint16_t)-
    (int16_t)(uint16_t)-tmp_0 : (int32_t)(uint16_t)tmp_0);

  /* End of DataTypeConversion: '<S3>/Cast1' */

  /* DataTypeConversion: '<S3>/Cast2' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write2'
   *  Gain: '<S3>/Gain2'
   */
  tmp = floor(1000.0 * localB->Pin);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  SMKACADEMY.electrical.Pin = (uint16_t)(tmp < 0.0 ? (int32_t)(uint16_t)-
    (int16_t)(uint16_t)-tmp : (int32_t)(uint16_t)tmp);

  /* End of DataTypeConversion: '<S3>/Cast2' */
  /* End of Outputs for SubSystem: '<Root>/ModelOutputPack' */
}

/* Model initialize function */
void CircuitInterface_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(double));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
