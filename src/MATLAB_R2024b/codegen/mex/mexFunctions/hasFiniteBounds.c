/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * hasFiniteBounds.c
 *
 * Code generation for function 'hasFiniteBounds'
 *
 */

/* Include files */
#include "hasFiniteBounds.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
boolean_T hasFiniteBounds(boolean_T hasLB[40], boolean_T hasUB[40],
                          const real_T lb[40], const real_T ub[40])
{
  int32_T idx;
  boolean_T hasBounds;
  hasBounds = false;
  idx = 0;
  while ((!hasBounds) && (idx + 1 <= 40)) {
    hasLB[idx] =
        ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx])));
    hasUB[idx] =
        ((!muDoubleScalarIsInf(ub[idx])) && (!muDoubleScalarIsNaN(ub[idx])));
    if (hasLB[idx] || hasUB[idx]) {
      hasBounds = true;
    }
    idx++;
  }
  while (idx + 1 <= 40) {
    hasLB[idx] =
        ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx])));
    hasUB[idx] =
        ((!muDoubleScalarIsInf(ub[idx])) && (!muDoubleScalarIsNaN(ub[idx])));
    idx++;
  }
  return hasBounds;
}

/* End of code generation (hasFiniteBounds.c) */
