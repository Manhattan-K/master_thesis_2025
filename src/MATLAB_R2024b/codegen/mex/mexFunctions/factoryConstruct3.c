/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factoryConstruct3.c
 *
 * Code generation for function 'factoryConstruct3'
 *
 */

/* Include files */
#include "factoryConstruct3.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
void d_factoryConstruct(emlrtCTX aTLS, real_T fval,
                        const real_T Cineq_workspace_data[],
                        int32_T mNonlinIneq, j_struct_T *obj)
{
  jmp_buf *volatile emlrtJBStack;
  real_T d;
  real_T d1;
  real_T normResid;
  real_T normResidPrime;
  int32_T d_factoryConstruct_numThreads;
  int32_T i;
  int32_T idx;
  obj->penaltyParam = 1.0;
  obj->threshold = 0.0001;
  obj->nPenaltyDecreases = 0;
  obj->linearizedConstrViol = 0.0;
  obj->initFval = fval;
  normResid = 0.0;
  i = (uint16_T)mNonlinIneq;
  if ((uint16_T)mNonlinIneq < 1200) {
    for (idx = 0; idx < i; idx++) {
      d = Cineq_workspace_data[idx];
      if (d > 0.0) {
        normResid += d;
      }
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    d_factoryConstruct_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(d_factoryConstruct_numThreads) private(       \
        normResidPrime, d1)
    {
      normResidPrime = 0.0;
#pragma omp for nowait
      for (idx = 0; idx < i; idx++) {
        d1 = Cineq_workspace_data[idx];
        if (d1 > 0.0) {
          normResidPrime += d1;
        }
      }
      omp_set_nest_lock(&mexFunctions_nestLockGlobal);
      {

        normResid += normResidPrime;
      }
      omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  obj->initConstrViolationIneq = normResid;
  obj->phi = 0.0;
  obj->phiPrimePlus = 0.0;
  obj->phiFullStep = 0.0;
  obj->feasRelativeFactor = 0.0;
  obj->nlpPrimalFeasError = 0.0;
  obj->nlpDualFeasError = 0.0;
  obj->nlpComplError = 0.0;
  obj->firstOrderOpt = 0.0;
}

/* End of code generation (factoryConstruct3.c) */
