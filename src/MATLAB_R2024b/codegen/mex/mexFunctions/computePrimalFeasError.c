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
#include "mexFunctions_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
real_T computePrimalFeasError(emlrtCTX aTLS, const real_T x[40],
                              int32_T mLinIneq, int32_T mNonlinIneq,
                              const real_T cIneq_data[],
                              const int32_T finiteLB_data[], int32_T mLB,
                              const real_T lb[40],
                              const int32_T finiteUB_data[], int32_T mUB,
                              const real_T ub[40])
{
  jmp_buf *volatile emlrtJBStack;
  real_T b_feasErrorPrime;
  real_T c_feasErrorPrime;
  real_T feasError;
  real_T feasErrorPrime;
  int32_T computePrimalFeasError_numThreads;
  int32_T idx;
  int32_T mIneq;
  feasError = 0.0;
  mIneq = mNonlinIneq + mLinIneq;
  if (mIneq < 1200) {
    for (idx = 0; idx < mIneq; idx++) {
      feasError = muDoubleScalarMax(feasError, cIneq_data[idx]);
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    computePrimalFeasError_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(computePrimalFeasError_numThreads) private(   \
        feasErrorPrime)
    {
      feasErrorPrime = rtMinusInf;
#pragma omp for nowait
      for (idx = 0; idx < mIneq; idx++) {
        feasErrorPrime = muDoubleScalarMax(feasErrorPrime, cIneq_data[idx]);
      }
      omp_set_nest_lock(&mexFunctions_nestLockGlobal);
      {

        feasError = muDoubleScalarMax(feasError, feasErrorPrime);
      }
      omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  mIneq = (uint16_T)mLB;
  if ((uint16_T)mLB < 1200) {
    for (idx = 0; idx < mIneq; idx++) {
      feasError = muDoubleScalarMax(feasError, lb[finiteLB_data[idx] - 1] -
                                                   x[finiteLB_data[idx] - 1]);
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    computePrimalFeasError_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(computePrimalFeasError_numThreads) private(   \
        b_feasErrorPrime)
    {
      b_feasErrorPrime = rtMinusInf;
#pragma omp for nowait
      for (idx = 0; idx < mIneq; idx++) {
        b_feasErrorPrime =
            muDoubleScalarMax(b_feasErrorPrime, lb[finiteLB_data[idx] - 1] -
                                                    x[finiteLB_data[idx] - 1]);
      }
      omp_set_nest_lock(&mexFunctions_nestLockGlobal);
      {

        feasError = muDoubleScalarMax(feasError, b_feasErrorPrime);
      }
      omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  mIneq = (uint16_T)mUB;
  if ((uint16_T)mUB < 1200) {
    for (idx = 0; idx < mIneq; idx++) {
      feasError = muDoubleScalarMax(feasError, x[finiteUB_data[idx] - 1] -
                                                   ub[finiteUB_data[idx] - 1]);
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    computePrimalFeasError_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(computePrimalFeasError_numThreads) private(   \
        c_feasErrorPrime)
    {
      c_feasErrorPrime = rtMinusInf;
#pragma omp for nowait
      for (idx = 0; idx < mIneq; idx++) {
        c_feasErrorPrime =
            muDoubleScalarMax(c_feasErrorPrime, x[finiteUB_data[idx] - 1] -
                                                    ub[finiteUB_data[idx] - 1]);
      }
      omp_set_nest_lock(&mexFunctions_nestLockGlobal);
      {

        feasError = muDoubleScalarMax(feasError, c_feasErrorPrime);
      }
      omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  return feasError;
}

/* End of code generation (computePrimalFeasError.c) */
