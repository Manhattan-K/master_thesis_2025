/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updatePenaltyParam.c
 *
 * Code generation for function 'updatePenaltyParam'
 *
 */

/* Include files */
#include "updatePenaltyParam.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void updatePenaltyParam(emlrtCTX aTLS, j_struct_T *obj, real_T fval,
                        const real_T ineq_workspace_data[], int32_T mIneq,
                        int32_T sqpiter, real_T qpval, const real_T x_data[],
                        int32_T iReg0, int32_T nRegularized)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  real_T constrViolationIneq;
  real_T constrViolationIneqPrime;
  real_T d;
  real_T linearizedConstrViolPrev;
  real_T penaltyParamTrial;
  int32_T i;
  int32_T idx;
  int32_T updatePenaltyParam_numThreads;
  penaltyParamTrial = obj->penaltyParam;
  constrViolationIneq = 0.0;
  i = (uint16_T)mIneq;
  if ((uint16_T)mIneq < 1200) {
    for (idx = 0; idx < i; idx++) {
      linearizedConstrViolPrev = ineq_workspace_data[idx];
      if (linearizedConstrViolPrev > 0.0) {
        constrViolationIneq += linearizedConstrViolPrev;
      }
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    updatePenaltyParam_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(updatePenaltyParam_numThreads) private(       \
        constrViolationIneqPrime, d)
    {
      constrViolationIneqPrime = 0.0;
#pragma omp for nowait
      for (idx = 0; idx < i; idx++) {
        d = ineq_workspace_data[idx];
        if (d > 0.0) {
          constrViolationIneqPrime += d;
        }
      }
      omp_set_nest_lock(&mexFunctions_nestLockGlobal);
      {

        constrViolationIneq += constrViolationIneqPrime;
      }
      omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  linearizedConstrViolPrev = obj->linearizedConstrViol;
  if (nRegularized < 1) {
    obj->linearizedConstrViol = 0.0;
  } else {
    n_t = (ptrdiff_t)nRegularized;
    incx_t = (ptrdiff_t)1;
    obj->linearizedConstrViol =
        dasum(&n_t, (real_T *)&x_data[iReg0 - 1], &incx_t);
  }
  linearizedConstrViolPrev = (constrViolationIneq + linearizedConstrViolPrev) -
                             obj->linearizedConstrViol;
  if ((linearizedConstrViolPrev > 2.2204460492503131E-16) && (qpval > 0.0)) {
    if (fval == 0.0) {
      penaltyParamTrial = 1.0;
    } else {
      penaltyParamTrial = 1.5;
    }
    penaltyParamTrial = penaltyParamTrial * qpval / linearizedConstrViolPrev;
  }
  if (penaltyParamTrial < obj->penaltyParam) {
    obj->phi = fval + penaltyParamTrial * constrViolationIneq;
    if ((obj->initFval + penaltyParamTrial * obj->initConstrViolationIneq) -
            obj->phi >
        (real_T)obj->nPenaltyDecreases * obj->threshold) {
      obj->nPenaltyDecreases++;
      if ((obj->nPenaltyDecreases << 1) > sqpiter) {
        obj->threshold *= 10.0;
      }
      obj->penaltyParam = muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
    } else {
      obj->phi = fval + obj->penaltyParam * constrViolationIneq;
    }
  } else {
    obj->penaltyParam = muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
    obj->phi = fval + obj->penaltyParam * constrViolationIneq;
  }
  obj->phiPrimePlus =
      muDoubleScalarMin(qpval - obj->penaltyParam * constrViolationIneq, 0.0);
}

/* End of code generation (updatePenaltyParam.c) */
