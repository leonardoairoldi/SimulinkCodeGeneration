/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CircuitInterface.c
 *
 * Code generated for Simulink model 'CircuitInterface'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon May  6 17:05:39 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CircuitInterface.h"
#include "GLOBAL_typedef.h"
#include "ELECTRICAL_typedef.h"
#include <stdint.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "CircuitInterface_private.h"
#include "look1_iu8lu32n24_binlcse.h"

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
    (SMKACADEMY.electrical.switch_state == SWITCH_OPEN);

  /* RateTransition generated from: '<Root>/ModelInputUnpack' incorporates:
   *  Constant: '<S2>/Constant1'
   *  DataStoreRead: '<S2>/Data Store Read1'
   *  RelationalOperator: '<S2>/Equal1'
   */
  localB->TmpRTBAtModelInputUnpackOutpo_m = (float)
    (SMKACADEMY.electrical.switch_state == SWITCH_PRECHARGE);

  /* RateTransition generated from: '<Root>/ModelInputUnpack' incorporates:
   *  Constant: '<S2>/Constant3'
   *  DataStoreRead: '<S2>/Data Store Read3'
   *  RelationalOperator: '<S2>/Equal3'
   */
  localB->TmpRTBAtModelInputUnpackOutpo_o = (float)
    (SMKACADEMY.electrical.switch_state == SWITCH_CLOSED);

  /* End of Outputs for SubSystem: '<Root>/ModelInputUnpack' */

  /* RateTransition generated from: '<Root>/ModelInputUnpack' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read4'
   */
  localB->TmpRTBAtModelInputUnpackOutpo_f = SMKACADEMY.electrical.perSOC;
}

/* Output and update for referenced model: 'CircuitInterface' */
void CircuitInterfaceTID1(B_CircuitInterface_c_T *localB,
  DW_CircuitInterface_f_T *localDW)
{
  float rtb_Delay1;
  int32_t rtb_Gain_d;

  /* Outputs for Atomic SubSystem: '<Root>/Model' */
  /* Delay: '<S1>/Delay1' */
  rtb_Delay1 = localDW->Delay1_DSTATE;

  /* Gain: '<S1>/Gain' incorporates:
   *  Lookup_n-D: '<S1>/OCV'
   *  RateTransition generated from: '<Root>/ModelInputUnpack'
   */
  rtb_Gain_d = 144 * look1_iu8lu32n24_binlcse
    (localB->TmpRTBAtModelInputUnpackOutpo_f, rtCP_OCV_bp01Data,
     rtCP_OCV_tableData, 99U);

  /* Switch: '<S1>/Switch2' incorporates:
   *  Delay: '<S1>/Delay1'
   *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn1'
   */
  if (localB->TmpRTBAtModelInputUnpackOutpo_o != 0.0F) {
    localDW->Delay1_DSTATE = (float)rtb_Gain_d;
  } else {
    localDW->Delay1_DSTATE = 0.004988F * localDW->DiscreteTransferFcn1_states;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Switch: '<S1>/Switch3' */
  if (!(localB->TmpRTBAtModelInputUnpackOutport != 0.0F)) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Switch: '<S1>/Switch3'
     */
    if (localB->TmpRTBAtModelInputUnpackOutpo_m != 0.0F) {
      rtb_Delay1 = (float)rtb_Gain_d;
    } else {
      rtb_Delay1 = 0.0F;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn1' incorporates:
   *  Switch: '<S1>/Switch3'
   */
  localDW->DiscreteTransferFcn1_states = rtb_Delay1 - -0.995F *
    localDW->DiscreteTransferFcn1_states;

  /* End of Outputs for SubSystem: '<Root>/Model' */

  /* RateTransition generated from: '<Root>/Model' */
  localB->TmpRTBAtModelOutport1 = (float)rtb_Gain_d;

  /* RateTransition generated from: '<Root>/Model' incorporates:
   *  Delay: '<S1>/Delay1'
   */
  localB->TmpRTBAtModelOutport2 = localDW->Delay1_DSTATE;
}

/* Output and update for referenced model: 'CircuitInterface' */
void CircuitInterfaceTID2(B_CircuitInterface_c_T *localB)
{
  float tmp;

  /* Outputs for Atomic SubSystem: '<Root>/ModelOutputPack' */
  /* DataTypeConversion: '<S3>/Cast1' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write1'
   */
  tmp = (float)floor(localB->TmpRTBAtModelOutport1);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (float)fmod(tmp, 65536.0);
  }

  SMKACADEMY.electrical.vSumOfCells = (uint16_t)(tmp < 0.0F ? (int32_t)(uint16_t)
    -(int16_t)(uint16_t)-tmp : (int32_t)(uint16_t)tmp);

  /* End of DataTypeConversion: '<S3>/Cast1' */

  /* DataTypeConversion: '<S3>/Cast' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write'
   */
  tmp = (float)floor(localB->TmpRTBAtModelOutport2);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (float)fmod(tmp, 65536.0);
  }

  SMKACADEMY.electrical.vTSAcc = (uint16_t)(tmp < 0.0F ? (int32_t)(uint16_t)-
    (int16_t)(uint16_t)-tmp : (int32_t)(uint16_t)tmp);

  /* End of DataTypeConversion: '<S3>/Cast' */
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
