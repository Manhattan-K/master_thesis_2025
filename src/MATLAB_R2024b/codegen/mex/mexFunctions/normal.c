/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * normal.c
 *
 * Code generation for function 'normal'
 *
 */

/* Include files */
#include "normal.h"
#include "driver1.h"
#include "maxConstraintViolation.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "mwmathutil.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
void normal(emlrtCTX aTLS, mexFunctionsStackData *SD,
            const real_T Hessian[1600], const real_T grad_data[],
            h_struct_T *TrialState, j_struct_T *MeritFunction,
            f_struct_T *memspace, i_struct_T *WorkingSet, g_struct_T *QRManager,
            m_struct_T *CholManager, e_struct_T *QPObjective,
            const n_struct_T *qpoptions, struct_T *stepFlags)
{
  jmp_buf *volatile emlrtJBStack;
  real_T constrViolationIneq;
  real_T constrViolationIneqPrime;
  real_T d;
  real_T linearizedConstrViolPrev;
  real_T penaltyParamTrial;
  int32_T i;
  int32_T idx;
  int32_T normal_numThreads;
  boolean_T isEqAndIneqFeasible;
  b_driver(aTLS, Hessian, grad_data, TrialState, memspace, WorkingSet,
           QRManager, CholManager, QPObjective, qpoptions, qpoptions);
  isEqAndIneqFeasible =
      (maxConstraintViolation(aTLS, SD, WorkingSet, TrialState->xstar.data) <=
       1.0E-6);
  if ((TrialState->state > 0) ||
      ((TrialState->state == 0) && isEqAndIneqFeasible) ||
      ((TrialState->state != -6) && (WorkingSet->sizes[2] == 0))) {
    penaltyParamTrial = MeritFunction->penaltyParam;
    constrViolationIneq = 0.0;
    i = (uint16_T)WorkingSet->sizes[2];
    if (i < 1200) {
      for (idx = 0; idx < i; idx++) {
        d = TrialState->cIneq.data[idx];
        if (d > 0.0) {
          constrViolationIneq += d;
        }
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      normal_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(normal_numThreads) private(                   \
        constrViolationIneqPrime, d)
      {
        constrViolationIneqPrime = 0.0;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          d = TrialState->cIneq.data[idx];
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
    linearizedConstrViolPrev = MeritFunction->linearizedConstrViol;
    MeritFunction->linearizedConstrViol = 0.0;
    linearizedConstrViolPrev += constrViolationIneq;
    if ((linearizedConstrViolPrev > 2.2204460492503131E-16) &&
        (TrialState->fstar > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        penaltyParamTrial = 1.0;
      } else {
        penaltyParamTrial = 1.5;
      }
      penaltyParamTrial =
          penaltyParamTrial * TrialState->fstar / linearizedConstrViolPrev;
    }
    if (penaltyParamTrial < MeritFunction->penaltyParam) {
      MeritFunction->phi =
          TrialState->sqpFval + penaltyParamTrial * constrViolationIneq;
      if ((MeritFunction->initFval +
           penaltyParamTrial * MeritFunction->initConstrViolationIneq) -
              MeritFunction->phi >
          (real_T)MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) >
            TrialState->sqpIterations) {
          MeritFunction->threshold *= 10.0;
        }
        MeritFunction->penaltyParam =
            muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
      } else {
        MeritFunction->phi = TrialState->sqpFval +
                             MeritFunction->penaltyParam * constrViolationIneq;
      }
    } else {
      MeritFunction->penaltyParam =
          muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
      MeritFunction->phi = TrialState->sqpFval +
                           MeritFunction->penaltyParam * constrViolationIneq;
    }
    MeritFunction->phiPrimePlus = muDoubleScalarMin(
        TrialState->fstar - MeritFunction->penaltyParam * constrViolationIneq,
        0.0);
  } else if (TrialState->state != -6) {
    stepFlags->stepType = 2;
  }
  sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr, WorkingSet->sizes,
               WorkingSet->isActiveIdx, WorkingSet->Wid.data,
               WorkingSet->Wlocalidx.data, memspace->workspace_float);
}

/* End of code generation (normal.c) */
