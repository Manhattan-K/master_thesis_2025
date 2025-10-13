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
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
real_T computeComplError(emlrtCTX aTLS, int32_T fscales_cineq_constraint_size,
                         const real_T xCurrent[40], int32_T mIneq,
                         const real_T cIneq_data[],
                         const int32_T finiteLB_data[], int32_T mLB,
                         const real_T lb[40], const int32_T finiteUB_data[],
                         int32_T mUB, const real_T ub[40],
                         const emxArray_real_T *lambda, int32_T iL0)
{
  jmp_buf *volatile emlrtJBStack;
  const real_T *lambda_data;
  real_T b_nlpComplErrorPrime;
  real_T d;
  real_T d1;
  real_T lbDelta;
  real_T lbLambda;
  real_T nlpComplError;
  real_T nlpComplErrorPrime;
  real_T y;
  int32_T computeComplError_numThreads;
  int32_T i;
  int32_T idx;
  int32_T lbOffset;
  int32_T ubOffset;
  lambda_data = lambda->data;
  nlpComplError = 0.0;
  if ((mIneq + mLB) + mUB > 0) {
    if (fscales_cineq_constraint_size < 1200) {
      for (idx = 0; idx < fscales_cineq_constraint_size; idx++) {
        y = lambda_data[(iL0 + idx) - 1];
        d = cIneq_data[idx];
        nlpComplError = muDoubleScalarMax(
            nlpComplError,
            muDoubleScalarMin(muDoubleScalarAbs(d * y),
                              muDoubleScalarMin(muDoubleScalarAbs(d), y)));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      computeComplError_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(computeComplError_numThreads) private(        \
        lbDelta, y, lbLambda, d1)
      {
        lbDelta = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < fscales_cineq_constraint_size; idx++) {
          y = lambda_data[(iL0 + idx) - 1];
          d1 = cIneq_data[idx];
          lbLambda = d1 * y;
          lbDelta = muDoubleScalarMax(
              lbDelta,
              muDoubleScalarMin(muDoubleScalarAbs(lbLambda),
                                muDoubleScalarMin(muDoubleScalarAbs(d1), y)));
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          nlpComplError = muDoubleScalarMax(nlpComplError, lbDelta);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    lbOffset = (iL0 + mIneq) - 1;
    ubOffset = lbOffset + mLB;
    i = (uint16_T)mLB;
    if ((uint16_T)mLB < 1200) {
      for (idx = 0; idx < i; idx++) {
        lbDelta = xCurrent[finiteLB_data[idx] - 1] - lb[finiteLB_data[idx] - 1];
        lbLambda = lambda_data[lbOffset + idx];
        nlpComplError = muDoubleScalarMax(
            nlpComplError,
            muDoubleScalarMin(
                muDoubleScalarAbs(lbDelta * lbLambda),
                muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      computeComplError_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(computeComplError_numThreads) private(        \
        nlpComplErrorPrime, lbDelta, lbLambda)
      {
        nlpComplErrorPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          lbDelta =
              xCurrent[finiteLB_data[idx] - 1] - lb[finiteLB_data[idx] - 1];
          lbLambda = lambda_data[lbOffset + idx];
          nlpComplErrorPrime = muDoubleScalarMax(
              nlpComplErrorPrime,
              muDoubleScalarMin(
                  muDoubleScalarAbs(lbDelta * lbLambda),
                  muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          nlpComplError = muDoubleScalarMax(nlpComplError, nlpComplErrorPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    i = (uint16_T)mUB;
    if ((uint16_T)mUB < 1200) {
      for (idx = 0; idx < i; idx++) {
        lbDelta = ub[finiteUB_data[idx] - 1] - xCurrent[finiteUB_data[idx] - 1];
        lbLambda = lambda_data[ubOffset + idx];
        nlpComplError = muDoubleScalarMax(
            nlpComplError,
            muDoubleScalarMin(
                muDoubleScalarAbs(lbDelta * lbLambda),
                muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      computeComplError_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(computeComplError_numThreads) private(        \
        b_nlpComplErrorPrime, lbDelta, lbLambda)
      {
        b_nlpComplErrorPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          lbDelta =
              ub[finiteUB_data[idx] - 1] - xCurrent[finiteUB_data[idx] - 1];
          lbLambda = lambda_data[ubOffset + idx];
          b_nlpComplErrorPrime = muDoubleScalarMax(
              b_nlpComplErrorPrime,
              muDoubleScalarMin(
                  muDoubleScalarAbs(lbDelta * lbLambda),
                  muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          nlpComplError =
              muDoubleScalarMax(nlpComplError, b_nlpComplErrorPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  return nlpComplError;
}

/* End of code generation (computeComplError.c) */
