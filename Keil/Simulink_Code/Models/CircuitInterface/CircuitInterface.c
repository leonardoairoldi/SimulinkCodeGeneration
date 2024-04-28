/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CircuitInterface.c
 *
 * Code generated for Simulink model 'CircuitInterface'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Apr 28 18:20:15 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CircuitInterface.h"
#include "GLOBAL_typedef.h"
#include "ELECTRICAL_typedef.h"
#include <stddef.h>
#include <math.h>
#include "rt_nonfinite.h"
#include <stdint.h>
#include "CircuitInterface_private.h"
#include "CircuitInterface_types.h"

/* System initialize for referenced model: 'CircuitInterface' */
void CircuitInterface_Init(B_CircuitInterface_c_T *localB,
  DW_CircuitInterface_f_T *localDW)
{
  NeslRtpManager *manager;
  NeslRtpManager *manager_0;
  NeslSimulationData *tmp_0;
  NeslSimulator *tmp;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  char *msg;
  char *msg_0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Model' */
  /* Start for SimscapeRtp: '<S8>/RTP_1' */
  manager_0 = nesl_lease_rtp_manager(
    "CircuitInterface/Model/Solver Configuration_1", 0);
  manager = manager_0;
  localB->b = pointer_is_null(manager_0);
  if (localB->b) {
    CircuitInterface_dcd86948_1_gateway();
    manager = nesl_lease_rtp_manager(
      "CircuitInterface/Model/Solver Configuration_1", 0);
  }

  localDW->RTP_1_RtpManager = (void *)manager;
  localDW->RTP_1_SetParametersNeeded = true;

  /* End of Start for SimscapeRtp: '<S8>/RTP_1' */

  /* Start for SimscapeExecutionBlock: '<S13>/STATE_1' */
  tmp = nesl_lease_simulator("CircuitInterface/Model/Solver Configuration_1", 0,
    0);
  localDW->STATE_1_Simulator = (void *)tmp;
  localB->b = pointer_is_null(localDW->STATE_1_Simulator);
  if (localB->b) {
    CircuitInterface_dcd86948_1_gateway();
    tmp = nesl_lease_simulator("CircuitInterface/Model/Solver Configuration_1",
      0, 0);
    localDW->STATE_1_Simulator = (void *)tmp;
  }

  ;
  tmp_0 = nesl_create_simulation_data();
  localDW->STATE_1_SimData = (void *)tmp_0;
  diagnosticManager = rtw_create_diagnostics();
  localDW->STATE_1_DiagMgr = (void *)diagnosticManager;
  localB->modelParameters.mSolverType = NE_SOLVER_TYPE_DISCRETE;
  localB->modelParameters.mSolverAbsTol = 0.001;
  localB->modelParameters.mSolverRelTol = 0.001;
  localB->modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
  localB->modelParameters.mStartTime = 0.0;
  localB->modelParameters.mLoadInitialState = false;
  localB->modelParameters.mUseSimState = false;
  localB->modelParameters.mLinTrimCompile = false;
  localB->modelParameters.mLoggingMode = SSC_LOGGING_OFF;
  localB->modelParameters.mRTWModifiedTimeStamp = 6.36217375E+8;
  localB->modelParameters.mUseModelRefSolver = false;
  localB->modelParameters.mTargetFPGAHIL = false;
  localB->d1 = 0.001;
  localB->modelParameters.mSolverTolerance = localB->d1;
  localB->d1 = 0.005;
  localB->modelParameters.mFixedStepSize = localB->d1;
  localB->b = false;
  localB->modelParameters.mVariableStepSolver = localB->b;
  localB->b = false;
  localB->modelParameters.mIsUsingODEN = localB->b;
  localB->modelParameters.mZcDisabled = true;
  diagnosticManager = (NeuDiagnosticManager *)localDW->STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  localB->i1 = nesl_initialize_simulator((NeslSimulator *)
    localDW->STATE_1_Simulator, &localB->modelParameters, diagnosticManager);
  if (localB->i1 != 0) {
    localB->b = error_buffer_is_empty(((void*) 0));
    if (localB->b) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      ((void) 0);
    }
  }

  /* End of Start for SimscapeExecutionBlock: '<S13>/STATE_1' */

  /* Start for SimscapeExecutionBlock: '<S13>/OUTPUT_1_0' */
  tmp = nesl_lease_simulator("CircuitInterface/Model/Solver Configuration_1", 1,
    0);
  localDW->OUTPUT_1_0_Simulator = (void *)tmp;
  localB->b = pointer_is_null(localDW->OUTPUT_1_0_Simulator);
  if (localB->b) {
    CircuitInterface_dcd86948_1_gateway();
    tmp = nesl_lease_simulator("CircuitInterface/Model/Solver Configuration_1",
      1, 0);
    localDW->OUTPUT_1_0_Simulator = (void *)tmp;
  }

  ;
  tmp_0 = nesl_create_simulation_data();
  localDW->OUTPUT_1_0_SimData = (void *)tmp_0;
  diagnosticManager = rtw_create_diagnostics();
  localDW->OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
  localB->modelParameters_m.mSolverType = NE_SOLVER_TYPE_DISCRETE;
  localB->modelParameters_m.mSolverAbsTol = 0.001;
  localB->modelParameters_m.mSolverRelTol = 0.001;
  localB->modelParameters_m.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
  localB->modelParameters_m.mStartTime = 0.0;
  localB->modelParameters_m.mLoadInitialState = false;
  localB->modelParameters_m.mUseSimState = false;
  localB->modelParameters_m.mLinTrimCompile = false;
  localB->modelParameters_m.mLoggingMode = SSC_LOGGING_OFF;
  localB->modelParameters_m.mRTWModifiedTimeStamp = 6.36217375E+8;
  localB->modelParameters_m.mUseModelRefSolver = false;
  localB->modelParameters_m.mTargetFPGAHIL = false;
  localB->d1 = 0.001;
  localB->modelParameters_m.mSolverTolerance = localB->d1;
  localB->d1 = 0.005;
  localB->modelParameters_m.mFixedStepSize = localB->d1;
  localB->b = false;
  localB->modelParameters_m.mVariableStepSolver = localB->b;
  localB->b = false;
  localB->modelParameters_m.mIsUsingODEN = localB->b;
  localB->modelParameters_m.mZcDisabled = true;
  diagnosticManager = (NeuDiagnosticManager *)localDW->OUTPUT_1_0_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  localB->i1 = nesl_initialize_simulator((NeslSimulator *)
    localDW->OUTPUT_1_0_Simulator, &localB->modelParameters_m, diagnosticManager);
  if (localB->i1 != 0) {
    localB->b = error_buffer_is_empty(((void*) 0));
    if (localB->b) {
      msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
      ((void) 0);
    }
  }

  /* End of Start for SimscapeExecutionBlock: '<S13>/OUTPUT_1_0' */
  /* End of SystemInitialize for SubSystem: '<Root>/Model' */
}

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
void CircuitInterfaceTID1(RT_MODEL_CircuitInterface_T * const CircuitInterface_M,
  B_CircuitInterface_c_T *localB, DW_CircuitInterface_f_T *localDW)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diag;
  NeuDiagnosticTree *diagTree;
  NeuDiagnosticTree *diagnosticTree;
  NeuDiagnosticTree *diagnosticTree_0;
  NeuDiagnosticTree *diagnosticTree_1;
  char *msg;
  char *msg_0;
  char *msg_1;
  char *msg_2;

  /* Outputs for Atomic SubSystem: '<Root>/Model' */
  /* SimscapeInputBlock: '<S13>/INPUT_1_1_1' incorporates:
   *  DataTypeConversion: '<S1>/Cast'
   */
  localB->INPUT_1_1_1[0] = localB->TmpRTBAtModelInputUnpackOutport;
  localB->INPUT_1_1_1[1] = 0.0;
  localB->INPUT_1_1_1[2] = 0.0;
  localDW->INPUT_1_1_1_Discrete[0] = !(localB->INPUT_1_1_1[0] ==
    localDW->INPUT_1_1_1_Discrete[1]);
  localDW->INPUT_1_1_1_Discrete[1] = localB->INPUT_1_1_1[0];
  localB->INPUT_1_1_1[0] = localDW->INPUT_1_1_1_Discrete[1];
  localB->INPUT_1_1_1[3] = localDW->INPUT_1_1_1_Discrete[0];

  /* SimscapeRtp: '<S8>/RTP_1' incorporates:
   *  Constant: '<S1>/Subsystem_around_RTP_8A769BFB_v'
   */
  if (localDW->RTP_1_SetParametersNeeded) {
    localB->d = 0.0;
    diag = rtw_create_diagnostics();
    diagTree = neu_diagnostic_manager_get_initial_tree(diag);
    localB->expl_temp.mRealParameters.mN = 1;
    localB->expl_temp.mRealParameters.mX = &localB->d;
    localB->expl_temp.mLogicalParameters.mN = 0;
    localB->expl_temp.mLogicalParameters.mX = NULL;
    localB->expl_temp.mIntegerParameters.mN = 0;
    localB->expl_temp.mIntegerParameters.mX = NULL;
    localB->expl_temp.mIndexParameters.mN = 0;
    localB->expl_temp.mIndexParameters.mX = NULL;
    localB->ok = nesl_rtp_manager_set_rtps((NeslRtpManager *)
      localDW->RTP_1_RtpManager, (CircuitInterface_M->Timing.clockTick0 * 0.005),
      localB->expl_temp, diag);
    if (!localB->ok) {
      localB->ok = error_buffer_is_empty(((void*) 0));
      if (localB->ok) {
        msg = rtw_diagnostics_msg(diagTree);
        ((void) 0);
      }
    }
  }

  localDW->RTP_1_SetParametersNeeded = false;

  /* End of SimscapeRtp: '<S8>/RTP_1' */

  /* SimscapeExecutionBlock: '<S13>/STATE_1' incorporates:
   *  SimscapeExecutionBlock: '<S13>/OUTPUT_1_0'
   */
  simulationData = (NeslSimulationData *)localDW->STATE_1_SimData;
  localB->time_tmp = (CircuitInterface_M->Timing.clockTick0 * 0.005);
  localB->time = localB->time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &localB->time;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 3;
  simulationData->mData->mDiscStates.mX = &localDW->STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 1;
  simulationData->mData->mModeVector.mX = &localDW->STATE_1_Modes;
  localB->ok = false;
  simulationData->mData->mFoundZcEvents = localB->ok;
  simulationData->mData->mIsMajorTimeStep = true;
  localB->ok = false;
  simulationData->mData->mIsSolverAssertCheck = localB->ok;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  localB->iv1[0] = 0;
  localB->dv1[0] = localB->INPUT_1_1_1[0];
  localB->dv1[1] = localB->INPUT_1_1_1[1];
  localB->dv1[2] = localB->INPUT_1_1_1[2];
  localB->dv1[3] = localB->INPUT_1_1_1[3];
  localB->iv1[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &localB->dv1[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &localB->iv1[0];
  simulationData->mData->mOutputs.mN = 4;
  simulationData->mData->mOutputs.mX = &localB->STATE_1[0];
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  localB->Pin = (CircuitInterface_M->Timing.clockTick1 * 0.005);
  localB->time_c = localB->Pin;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &localB->time_c;
  localB->isHit = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &localB->isHit;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diag = (NeuDiagnosticManager *)localDW->STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diag);
  localB->i = ne_simulator_method((NeslSimulator *)localDW->STATE_1_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diag);
  if (localB->i != 0) {
    localB->ok = error_buffer_is_empty(((void*) 0));
    if (localB->ok) {
      msg_0 = rtw_diagnostics_msg(diagnosticTree);
      ((void) 0);
    }
  }

  /* End of SimscapeExecutionBlock: '<S13>/STATE_1' */

  /* SimscapeExecutionBlock: '<S13>/OUTPUT_1_0' */
  simulationData = (NeslSimulationData *)localDW->OUTPUT_1_0_SimData;
  localB->time_k = localB->time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &localB->time_k;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &localDW->OUTPUT_1_0_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = &localDW->OUTPUT_1_0_Modes;
  localB->ok = false;
  simulationData->mData->mFoundZcEvents = localB->ok;
  simulationData->mData->mIsMajorTimeStep = true;
  localB->ok = false;
  simulationData->mData->mIsSolverAssertCheck = localB->ok;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  localB->iv[0] = 0;
  localB->dv[0] = localB->INPUT_1_1_1[0];
  localB->dv[1] = localB->INPUT_1_1_1[1];
  localB->dv[2] = localB->INPUT_1_1_1[2];
  localB->dv[3] = localB->INPUT_1_1_1[3];
  localB->iv[1] = 4;
  localB->dv[4] = localB->STATE_1[0];
  localB->dv[5] = localB->STATE_1[1];
  localB->dv[6] = localB->STATE_1[2];
  localB->dv[7] = localB->STATE_1[3];
  localB->iv[2] = 8;
  simulationData->mData->mInputValues.mN = 8;
  simulationData->mData->mInputValues.mX = &localB->dv[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &localB->iv[0];
  simulationData->mData->mOutputs.mN = 3;
  simulationData->mData->mOutputs.mX = &localB->OUTPUT_1_0[0];
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  localB->time_cx = localB->Pin;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &localB->time_cx;
  localB->isHit_p = 0;
  simulationData->mData->mSampleHits.mN = 1;
  simulationData->mData->mSampleHits.mX = &localB->isHit_p;
  simulationData->mData->mIsFundamentalSampleHit = true;
  diag = (NeuDiagnosticManager *)localDW->OUTPUT_1_0_DiagMgr;
  diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diag);
  localB->i = ne_simulator_method((NeslSimulator *)localDW->OUTPUT_1_0_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diag);
  if (localB->i != 0) {
    localB->ok = error_buffer_is_empty(((void*) 0));
    if (localB->ok) {
      msg_1 = rtw_diagnostics_msg(diagnosticTree_0);
      ((void) 0);
    }
  }

  /* Product: '<S1>/Product' */
  localB->Pin = localB->OUTPUT_1_0[0] * localB->OUTPUT_1_0[1];

  /* Update for SimscapeExecutionBlock: '<S13>/STATE_1' */
  simulationData = (NeslSimulationData *)localDW->STATE_1_SimData;
  localB->time_b = localB->time_tmp;
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &localB->time_b;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 3;
  simulationData->mData->mDiscStates.mX = &localDW->STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 1;
  simulationData->mData->mModeVector.mX = &localDW->STATE_1_Modes;
  localB->ok = false;
  simulationData->mData->mFoundZcEvents = localB->ok;
  simulationData->mData->mIsMajorTimeStep = true;
  localB->ok = false;
  simulationData->mData->mIsSolverAssertCheck = localB->ok;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsModeUpdateTimeStep = true;
  localB->iv2[0] = 0;
  localB->dv2[0] = localB->INPUT_1_1_1[0];
  localB->dv2[1] = localB->INPUT_1_1_1[1];
  localB->dv2[2] = localB->INPUT_1_1_1[2];
  localB->dv2[3] = localB->INPUT_1_1_1[3];
  localB->iv2[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &localB->dv2[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &localB->iv2[0];
  diag = (NeuDiagnosticManager *)localDW->STATE_1_DiagMgr;
  diagnosticTree_1 = neu_diagnostic_manager_get_initial_tree(diag);
  localB->i = ne_simulator_method((NeslSimulator *)localDW->STATE_1_Simulator,
    NESL_SIM_UPDATE, simulationData, diag);
  if (localB->i != 0) {
    localB->ok = error_buffer_is_empty(((void*) 0));
    if (localB->ok) {
      msg_2 = rtw_diagnostics_msg(diagnosticTree_1);
      ((void) 0);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Model' */

  /* RateTransition generated from: '<Root>/Model' */
  localB->TmpRTBAtModelOutport1 = localB->OUTPUT_1_0[2];

  /* RateTransition generated from: '<Root>/Model' */
  localB->TmpRTBAtModelOutport2 = localB->OUTPUT_1_0[1];

  /* RateTransition generated from: '<Root>/Model' */
  localB->TmpRTBAtModelOutport3 = localB->Pin;
}

/* Output and update for referenced model: 'CircuitInterface' */
void CircuitInterfaceTID2(B_CircuitInterface_c_T *localB)
{
  double tmp;

  /* Outputs for Atomic SubSystem: '<Root>/ModelOutputPack' */
  /* DataTypeConversion: '<S3>/Cast' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write'
   *  Gain: '<S3>/Gain'
   */
  tmp = floor(1000.0 * localB->TmpRTBAtModelOutport1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  SMKACADEMY.electrical.Vout = (uint16_t)(tmp < 0.0 ? (int32_t)(uint16_t)-
    (int16_t)(uint16_t)-tmp : (int32_t)(uint16_t)tmp);

  /* End of DataTypeConversion: '<S3>/Cast' */

  /* DataTypeConversion: '<S3>/Cast1' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write1'
   *  Gain: '<S3>/Gain1'
   */
  tmp = floor(1000.0 * localB->TmpRTBAtModelOutport2);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  SMKACADEMY.electrical.Vin = (uint16_t)(tmp < 0.0 ? (int32_t)(uint16_t)-
    (int16_t)(uint16_t)-tmp : (int32_t)(uint16_t)tmp);

  /* End of DataTypeConversion: '<S3>/Cast1' */

  /* DataTypeConversion: '<S3>/Cast2' incorporates:
   *  DataStoreWrite: '<S3>/Data Store Write2'
   *  Gain: '<S3>/Gain2'
   */
  tmp = floor(1000.0 * localB->TmpRTBAtModelOutport3);
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

/* Termination for referenced model: 'CircuitInterface' */
void CircuitInterface_Term(DW_CircuitInterface_f_T *localDW)
{
  /* Terminate for Atomic SubSystem: '<Root>/Model' */
  /* Terminate for SimscapeExecutionBlock: '<S13>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    localDW->STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)localDW->STATE_1_SimData);
  nesl_erase_simulator("CircuitInterface/Model/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S13>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    localDW->OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)localDW->OUTPUT_1_0_SimData);
  nesl_erase_simulator("CircuitInterface/Model/Solver Configuration_1");
  nesl_destroy_registry();

  /* End of Terminate for SubSystem: '<Root>/Model' */
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
