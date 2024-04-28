/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CircuitInterface.h
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

#ifndef RTW_HEADER_CircuitInterface_h_
#define RTW_HEADER_CircuitInterface_h_
#ifndef CircuitInterface_COMMON_INCLUDES_
#define CircuitInterface_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "nesl_rtw_rtp.h"
#include "CircuitInterface_dcd86948_1_gateway.h"
#include "nesl_rtw.h"
#endif                                 /* CircuitInterface_COMMON_INCLUDES_ */

#include "CircuitInterface_types.h"
#include "rt_nonfinite.h"

/* Block signals for model 'CircuitInterface' */
typedef struct {
  NeModelParameters modelParameters;
  NeModelParameters modelParameters_m;
  double dv[8];
  NeParameterBundle expl_temp;
  double dv1[4];
  double dv2[4];
  double OUTPUT_1_0[3];                /* '<S13>/OUTPUT_1_0' */
  int iv[3];
  int iv1[2];
  int iv2[2];
  double TmpRTBAtModelOutport1;        /* '<Root>/Model' */
  double TmpRTBAtModelOutport2;        /* '<Root>/Model' */
  double TmpRTBAtModelOutport3;        /* '<Root>/Model' */
  double INPUT_1_1_1[4];               /* '<S13>/INPUT_1_1_1' */
  double RTP_1;                        /* '<S8>/RTP_1' */
  double STATE_1[4];                   /* '<S13>/STATE_1' */
  double d;
  double time;
  double time_c;
  double time_k;
  double time_cx;
  double time_b;
  double Pin;                          /* '<S1>/Product' */
  double time_tmp;
  double d1;
  float TmpRTBAtModelInputUnpackOutport;/* '<Root>/ModelInputUnpack' */
  int32_t isHit;
  int32_t i;
  int32_t isHit_p;
  int32_t i1;
  bool ok;
  bool b;
} B_CircuitInterface_c_T;

/* Block states (default storage) for model 'CircuitInterface' */
typedef struct {
  double INPUT_1_1_1_Discrete[2];      /* '<S13>/INPUT_1_1_1' */
  double STATE_1_Discrete[3];          /* '<S13>/STATE_1' */
  double OUTPUT_1_0_Discrete;          /* '<S13>/OUTPUT_1_0' */
  void* RTP_1_RtpManager;              /* '<S8>/RTP_1' */
  void* STATE_1_Simulator;             /* '<S13>/STATE_1' */
  void* STATE_1_SimData;               /* '<S13>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S13>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S13>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S13>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S13>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S13>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S13>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S13>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S13>/OUTPUT_1_0' */
  int STATE_1_Modes;                   /* '<S13>/STATE_1' */
  int OUTPUT_1_0_Modes;                /* '<S13>/OUTPUT_1_0' */
  bool RTP_1_SetParametersNeeded;      /* '<S8>/RTP_1' */
  bool STATE_1_FirstOutput;            /* '<S13>/STATE_1' */
  bool OUTPUT_1_0_FirstOutput;         /* '<S13>/OUTPUT_1_0' */
} DW_CircuitInterface_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_CircuitInterface_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_t clockTick0;
    uint32_t clockTick1;
  } Timing;
};

typedef struct {
  B_CircuitInterface_c_T rtb;
  DW_CircuitInterface_f_T rtdw;
  RT_MODEL_CircuitInterface_T rtm;
} MdlrefDW_CircuitInterface_T;

/* Model reference registration function */
extern void CircuitInterface_initialize(void);
extern void CircuitInterface_Init(B_CircuitInterface_c_T *localB,
  DW_CircuitInterface_f_T *localDW);
extern void CircuitInterfaceTID0(B_CircuitInterface_c_T *localB);
extern void CircuitInterfaceTID1(RT_MODEL_CircuitInterface_T * const
  CircuitInterface_M, B_CircuitInterface_c_T *localB, DW_CircuitInterface_f_T
  *localDW);
extern void CircuitInterfaceTID2(B_CircuitInterface_c_T *localB);
extern void CircuitInterface_Term(DW_CircuitInterface_f_T *localDW);

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
 * '<S4>'   : 'CircuitInterface/Model/PS-Simulink Converter'
 * '<S5>'   : 'CircuitInterface/Model/PS-Simulink Converter1'
 * '<S6>'   : 'CircuitInterface/Model/PS-Simulink Converter2'
 * '<S7>'   : 'CircuitInterface/Model/Simulink-PS Converter'
 * '<S8>'   : 'CircuitInterface/Model/Solver Configuration'
 * '<S9>'   : 'CircuitInterface/Model/PS-Simulink Converter/EVAL_KEY'
 * '<S10>'  : 'CircuitInterface/Model/PS-Simulink Converter1/EVAL_KEY'
 * '<S11>'  : 'CircuitInterface/Model/PS-Simulink Converter2/EVAL_KEY'
 * '<S12>'  : 'CircuitInterface/Model/Simulink-PS Converter/EVAL_KEY'
 * '<S13>'  : 'CircuitInterface/Model/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_CircuitInterface_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
