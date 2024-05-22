/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: look1_iu8lftf_binlcpw.c
 *
 * Code generated for Simulink model 'CircuitInterface'.
 *
 * Model version                  : 1.58
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu May 23 00:55:02 2024
 */

#include "look1_iu8lftf_binlcpw.h"
#include <stdint.h>

float look1_iu8lftf_binlcpw(uint8_t u0, const uint8_t bp0[], const float table[],
  uint32_t maxIndex)
{
  float frac;
  float yL_0d0;
  uint32_t bpIdx;
  uint32_t iLeft;
  uint32_t iRght;
  uint8_t bpLeftVar;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    bpLeftVar = bp0[iLeft];
    frac = (float)(uint8_t)((uint32_t)u0 - bpLeftVar) / (float)(uint8_t)
      ((uint32_t)bp0[iLeft + 1U] - bpLeftVar);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
