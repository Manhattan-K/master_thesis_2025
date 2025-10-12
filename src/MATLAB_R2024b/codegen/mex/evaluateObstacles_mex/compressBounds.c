/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compressBounds.c
 *
 * Code generation for function 'compressBounds'
 *
 */

/* Include files */
#include "compressBounds.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
int32_T compressBounds(int32_T indexLB_data[], int32_T indexUB_data[],
                       int32_T indexFixed_data[], const real_T lb_data[],
                       const int32_T lb_size[2], const real_T ub_data[],
                       const int32_T ub_size[2], int32_T *mUB, int32_T *mFixed)
{
  int32_T idx;
  int32_T mLB;
  mLB = 0;
  *mUB = 0;
  *mFixed = 0;
  if ((ub_size[0] != 0) && (ub_size[1] != 0)) {
    if ((lb_size[0] != 0) && (lb_size[1] != 0)) {
      for (idx = 0; idx < 40; idx++) {
        real_T d;
        boolean_T guard1;
        d = lb_data[idx];
        guard1 = false;
        if ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d))) {
          if (muDoubleScalarAbs(d - ub_data[idx]) < 1.0E-6) {
            (*mFixed)++;
            indexFixed_data[*mFixed - 1] = idx + 1;
          } else {
            mLB++;
            indexLB_data[mLB - 1] = idx + 1;
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        if (guard1) {
          d = ub_data[idx];
          if ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d))) {
            (*mUB)++;
            indexUB_data[*mUB - 1] = idx + 1;
          }
        }
      }
    } else {
      for (idx = 0; idx < 40; idx++) {
        real_T d;
        d = ub_data[idx];
        if ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d))) {
          (*mUB)++;
          indexUB_data[*mUB - 1] = idx + 1;
        }
      }
    }
  } else if ((lb_size[0] != 0) && (lb_size[1] != 0)) {
    for (idx = 0; idx < 40; idx++) {
      real_T d;
      d = lb_data[idx];
      if ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d))) {
        mLB++;
        indexLB_data[mLB - 1] = idx + 1;
      }
    }
  }
  return mLB;
}

/* End of code generation (compressBounds.c) */
