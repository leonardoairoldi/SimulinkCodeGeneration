/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: look1_iu8lu32n24_binlcse.c
 *
 * Code generated for Simulink model 'CircuitInterface'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon May  6 16:22:41 2024
 */

#include "look1_iu8lu32n24_binlcse.h"
#include <stdint.h>

uint8_t look1_iu8lu32n24_binlcse(uint8_t u0, const uint8_t bp0[], const uint8_t
  table[], uint32_t maxIndex)
{
  uint32_t frac;
  uint32_t iLeft;
  uint32_t iRght;
  uint8_t bpLeftVar;
  uint8_t y;
  uint8_t yL_0d0;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    frac = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = (iRght + iLeft) >> 1U;
    }

    bpLeftVar = bp0[iLeft];
    frac = ((uint32_t)(uint8_t)((uint32_t)u0 - bpLeftVar) << 24) / (uint8_t)
      ((uint32_t)bp0[iLeft + 1U] - bpLeftVar);
  } else {
    iLeft = maxIndex - 1U;
    frac = 16777216U;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  bpLeftVar = table[iLeft + 1U];
  yL_0d0 = table[iLeft];
  if (bpLeftVar >= yL_0d0) {
    y = (uint8_t)((uint32_t)(uint8_t)(((uint8_t)((uint32_t)bpLeftVar - yL_0d0) *
      frac) >> 24) + yL_0d0);
  } else {
    y = (uint8_t)((uint32_t)yL_0d0 - (uint8_t)(((uint8_t)((uint32_t)yL_0d0 -
      bpLeftVar) * frac) >> 24));
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
