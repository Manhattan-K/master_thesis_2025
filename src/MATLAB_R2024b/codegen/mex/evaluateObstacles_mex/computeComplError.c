/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeComplError.c
 *
 * Code generation for function 'computeComplError'
 *
 */

/* Include files */
#include "computeComplError.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T computeComplError(int32_T fscales_cineq_constraint_size,
                         const real_T xCurrent[40], int32_T mIneq,
                         const real_T cIneq_data[],
                         const int32_T finiteLB_data[], int32_T mLB,
                         const real_T lb_data[], const int32_T finiteUB_data[],
                         int32_T mUB, const real_T ub_data[],
                         const emxArray_real_T *lambda, int32_T iL0)
{
  const real_T *lambda_data;
  real_T nlpComplError;
  int32_T idx;
  lambda_data = lambda->data;
  nlpComplError = 0.0;
  if ((mIneq + mLB) + mUB > 0) {
    real_T lbDelta;
    real_T lbLambda;
    int32_T i;
    int32_T lbOffset;
    int32_T ubOffset;
    for (idx = 0; idx < fscales_cineq_constraint_size; idx++) {
      lbDelta = lambda_data[(iL0 + idx) - 1];
      lbLambda = cIneq_data[idx];
      nlpComplError = muDoubleScalarMax(
          nlpComplError,
          muDoubleScalarMin(
              muDoubleScalarAbs(lbLambda * lbDelta),
              muDoubleScalarMin(muDoubleScalarAbs(lbLambda), lbDelta)));
    }
    lbOffset = (iL0 + mIneq) - 1;
    ubOffset = lbOffset + mLB;
    i = (uint16_T)mLB;
    for (idx = 0; idx < i; idx++) {
      lbDelta =
          xCurrent[finiteLB_data[idx] - 1] - lb_data[finiteLB_data[idx] - 1];
      lbLambda = lambda_data[lbOffset + idx];
      nlpComplError = muDoubleScalarMax(
          nlpComplError,
          muDoubleScalarMin(
              muDoubleScalarAbs(lbDelta * lbLambda),
              muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
    }
    i = (uint16_T)mUB;
    for (idx = 0; idx < i; idx++) {
      lbDelta =
          ub_data[finiteUB_data[idx] - 1] - xCurrent[finiteUB_data[idx] - 1];
      lbLambda = lambda_data[ubOffset + idx];
      nlpComplError = muDoubleScalarMax(
          nlpComplError,
          muDoubleScalarMin(
              muDoubleScalarAbs(lbDelta * lbLambda),
              muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
    }
  }
  return nlpComplError;
}

/* End of code generation (computeComplError.c) */
