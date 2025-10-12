/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computePrimalFeasError.c
 *
 * Code generation for function 'computePrimalFeasError'
 *
 */

/* Include files */
#include "computePrimalFeasError.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T computePrimalFeasError(const real_T x[40], int32_T mLinIneq,
                              int32_T mNonlinIneq, const real_T cIneq_data[],
                              const int32_T finiteLB_data[], int32_T mLB,
                              const real_T lb_data[],
                              const int32_T finiteUB_data[], int32_T mUB,
                              const real_T ub_data[])
{
  real_T feasError;
  int32_T idx;
  int32_T mIneq;
  feasError = 0.0;
  mIneq = mNonlinIneq + mLinIneq;
  for (idx = 0; idx < mIneq; idx++) {
    feasError = muDoubleScalarMax(feasError, cIneq_data[idx]);
  }
  mIneq = (uint16_T)mLB;
  for (idx = 0; idx < mIneq; idx++) {
    feasError = muDoubleScalarMax(feasError, lb_data[finiteLB_data[idx] - 1] -
                                                 x[finiteLB_data[idx] - 1]);
  }
  mIneq = (uint16_T)mUB;
  for (idx = 0; idx < mIneq; idx++) {
    feasError = muDoubleScalarMax(
        feasError, x[finiteUB_data[idx] - 1] - ub_data[finiteUB_data[idx] - 1]);
  }
  return feasError;
}

/* End of code generation (computePrimalFeasError.c) */
