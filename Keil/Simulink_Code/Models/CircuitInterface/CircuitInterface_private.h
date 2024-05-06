/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CircuitInterface_private.h
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

#ifndef RTW_HEADER_CircuitInterface_private_h_
#define RTW_HEADER_CircuitInterface_private_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "GLOBAL_typedef.h"
#include "ELECTRICAL_typedef.h"
#include "CircuitInterface_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern const uint8_t rtCP_pooled_Jy6xae4zx2O0[100];
extern const uint8_t rtCP_pooled_CH4j98SUmRRm[100];

#define rtCP_OCV_tableData             rtCP_pooled_Jy6xae4zx2O0  /* Computed Parameter: rtCP_OCV_tableData
                                                                  * Referenced by: '<S1>/OCV'
                                                                  */
#define rtCP_OCV_bp01Data              rtCP_pooled_CH4j98SUmRRm  /* Computed Parameter: rtCP_OCV_bp01Data
                                                                  * Referenced by: '<S1>/OCV'
                                                                  */

/* Exported data declaration */

/* Data with Imported storage */
extern GLOBAL_t SMKACADEMY;

#endif                              /* RTW_HEADER_CircuitInterface_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
