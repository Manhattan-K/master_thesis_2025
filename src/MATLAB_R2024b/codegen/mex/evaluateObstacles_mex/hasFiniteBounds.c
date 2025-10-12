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
                          const real_T lb_data[], const int32_T lb_size[2],
                          const real_T ub_data[], const int32_T ub_size[2])
{
  int32_T idx;
  boolean_T hasBounds;
  hasBounds = false;
  idx = 0;
  switch ((uint32_T)((ub_size[0] == 0) || (ub_size[1] == 0)) << 1 |
          (uint32_T)((lb_size[0] == 0) || (lb_size[1] == 0))) {
  case 0U:
    while ((!hasBounds) && (idx + 1 <= 40)) {
      hasLB[idx] = ((!muDoubleScalarIsInf(lb_data[idx])) &&
                    (!muDoubleScalarIsNaN(lb_data[idx])));
      hasUB[idx] = ((!muDoubleScalarIsInf(ub_data[idx])) &&
                    (!muDoubleScalarIsNaN(ub_data[idx])));
      if (hasLB[idx] || hasUB[idx]) {
        hasBounds = true;
      }
      idx++;
    }
    while (idx + 1 <= 40) {
      hasLB[idx] = ((!muDoubleScalarIsInf(lb_data[idx])) &&
                    (!muDoubleScalarIsNaN(lb_data[idx])));
      hasUB[idx] = ((!muDoubleScalarIsInf(ub_data[idx])) &&
                    (!muDoubleScalarIsNaN(ub_data[idx])));
      idx++;
    }
    break;
  case 1U:
    while ((!hasBounds) && (idx + 1 <= 40)) {
      hasLB[idx] = false;
      hasUB[idx] = ((!muDoubleScalarIsInf(ub_data[idx])) &&
                    (!muDoubleScalarIsNaN(ub_data[idx])));
      hasBounds = hasUB[idx];
      idx++;
    }
    while (idx + 1 <= 40) {
      hasLB[idx] = false;
      hasUB[idx] = ((!muDoubleScalarIsInf(ub_data[idx])) &&
                    (!muDoubleScalarIsNaN(ub_data[idx])));
      idx++;
    }
    break;
  case 2U:
    while ((!hasBounds) && (idx + 1 <= 40)) {
      hasLB[idx] = ((!muDoubleScalarIsInf(lb_data[idx])) &&
                    (!muDoubleScalarIsNaN(lb_data[idx])));
      hasUB[idx] = false;
      hasBounds = hasLB[idx];
      idx++;
    }
    while (idx + 1 <= 40) {
      hasLB[idx] = ((!muDoubleScalarIsInf(lb_data[idx])) &&
                    (!muDoubleScalarIsNaN(lb_data[idx])));
      hasUB[idx] = false;
      idx++;
    }
    break;
  default:
    for (idx = 0; idx < 40; idx++) {
      hasLB[idx] = false;
      hasUB[idx] = false;
    }
    break;
  }
  return hasBounds;
}

/* End of code generation (hasFiniteBounds.c) */
