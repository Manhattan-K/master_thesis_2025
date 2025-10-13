/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * relaxed.c
 *
 * Code generation for function 'relaxed'
 *
 */

/* Include files */
#include "relaxed.h"
#include "assignResidualsToXSlack.h"
#include "driver1.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include "updatePenaltyParam.h"
#include "xasum.h"
#include "xdot.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void relaxed(emlrtCTX aTLS, const real_T Hessian[1600],
             const real_T grad_data[], h_struct_T *TrialState,
             j_struct_T *MeritFunction, f_struct_T *memspace,
             i_struct_T *WorkingSet, g_struct_T *QRManager,
             m_struct_T *CholManager, e_struct_T *QPObjective,
             n_struct_T *qpoptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T *x;
  const real_T *x_data;
  real_T beta;
  real_T betaPrime;
  real_T rho;
  int32_T idx;
  int32_T mIneq;
  int32_T nActiveLBArtificial;
  int32_T nActiveLBArtificialPrime;
  int32_T nVarMax;
  int32_T nVarOrig;
  int32_T relaxed_numThreads;
  int32_T temp;
  int32_T tmp_tmp;
  boolean_T tf;
  nVarOrig = WorkingSet->nVar + 1;
  nVarMax = WorkingSet->nVarMax;
  mIneq = WorkingSet->sizes[2];
  beta = 0.0;
  temp = (uint16_T)WorkingSet->nVar;
  if (temp < 1200) {
    for (idx = 0; idx < temp; idx++) {
      beta += Hessian[idx + 40 * idx];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    relaxed_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(relaxed_numThreads) private(betaPrime)
    {
      betaPrime = 0.0;
#pragma omp for nowait
      for (idx = 0; idx < temp; idx++) {
        betaPrime += Hessian[idx + 40 * idx];
      }
      omp_set_nest_lock(&mexFunctions_nestLockGlobal);
      {

        beta += betaPrime;
      }
      omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  beta /= (real_T)WorkingSet->nVar;
  if (TrialState->sqpIterations <= 1) {
    temp = QPObjective->nvar;
    if (temp < 1) {
      temp = 0;
    } else {
      n_t = (ptrdiff_t)temp;
      incx_t = (ptrdiff_t)1;
      n_t = idamax(&n_t, (real_T *)&grad_data[0], &incx_t);
      temp = (int32_T)n_t;
    }
    rho =
        100.0 * muDoubleScalarMax(1.0, muDoubleScalarAbs(grad_data[temp - 1]));
  } else {
    temp = WorkingSet->mConstr;
    x = TrialState->lambdasqp;
    x_data = x->data;
    if (temp < 1) {
      temp = 0;
    } else {
      n_t = (ptrdiff_t)temp;
      incx_t = (ptrdiff_t)1;
      n_t = idamax(&n_t, (real_T *)&x_data[0], &incx_t);
      temp = (int32_T)n_t;
    }
    rho = muDoubleScalarAbs(TrialState->lambdasqp->data[temp - 1]);
  }
  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = rho;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  setProblemType(WorkingSet, 2);
  assignResidualsToXSlack(aTLS, nVarOrig - 1, WorkingSet, TrialState, memspace);
  temp = qpoptions->MaxIterations;
  qpoptions->MaxIterations =
      ((qpoptions->MaxIterations + WorkingSet->nVar) - nVarOrig) + 1;
  b_driver(aTLS, Hessian, grad_data, TrialState, memspace, WorkingSet,
           QRManager, CholManager, QPObjective, qpoptions, qpoptions);
  qpoptions->MaxIterations = temp;
  nActiveLBArtificial = 0;
  temp = (uint16_T)WorkingSet->sizes[2];
  if (temp < 1200) {
    for (idx = 0; idx < temp; idx++) {
      tf = WorkingSet->isActiveConstr
               .data[(((WorkingSet->isActiveIdx[3] + WorkingSet->sizes[3]) -
                       WorkingSet->sizes[2]) +
                      idx) -
                     1];
      memspace->workspace_int.data[idx] = tf;
      nActiveLBArtificial += tf;
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    relaxed_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(relaxed_numThreads) private(                  \
        nActiveLBArtificialPrime, tf)
    {
      nActiveLBArtificialPrime = 0;
#pragma omp for nowait
      for (idx = 0; idx < temp; idx++) {
        tf = WorkingSet->isActiveConstr
                 .data[(((WorkingSet->isActiveIdx[3] + WorkingSet->sizes[3]) -
                         WorkingSet->sizes[2]) +
                        idx) -
                       1];
        memspace->workspace_int.data[idx] = tf;
        nActiveLBArtificialPrime += tf;
      }
      omp_set_nest_lock(&mexFunctions_nestLockGlobal);
      {

        nActiveLBArtificial += nActiveLBArtificialPrime;
      }
      omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  if (TrialState->state != -6) {
    temp = WorkingSet->nVarMax - nVarOrig;
    updatePenaltyParam(aTLS, MeritFunction, TrialState->sqpFval,
                       TrialState->cIneq.data, mIneq, TrialState->sqpIterations,
                       (TrialState->fstar -
                        rho * xasum(temp, TrialState->xstar.data, nVarOrig)) -
                           beta / 2.0 *
                               b_xdot(temp, TrialState->xstar.data, nVarOrig,
                                      TrialState->xstar.data, nVarOrig),
                       TrialState->xstar.data, nVarOrig, nVarMax - nVarOrig);
    temp = WorkingSet->isActiveIdx[2];
    nVarMax = WorkingSet->nActiveConstr;
    if ((nVarMax - temp) + 1 < 1200) {
      for (idx = temp; idx <= nVarMax; idx++) {
        if (WorkingSet->Wid.data[idx - 1] == 3) {
          TrialState->lambda->data[idx - 1] *=
              (real_T)memspace->workspace_int
                  .data[WorkingSet->Wlocalidx.data[idx - 1] - 1];
        }
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      relaxed_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(relaxed_numThreads)

      for (idx = temp; idx <= nVarMax; idx++) {
        if (WorkingSet->Wid.data[idx - 1] == 3) {
          TrialState->lambda->data[idx - 1] *=
              (real_T)memspace->workspace_int
                  .data[WorkingSet->Wlocalidx.data[idx - 1] - 1];
        }
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  temp = WorkingSet->sizes[0];
  nVarMax = WorkingSet->sizes[3] - WorkingSet->sizes[2];
  mIneq = WorkingSet->nActiveConstr;
  while ((mIneq > temp) && (nActiveLBArtificial > 0)) {
    if ((WorkingSet->Wid.data[mIneq - 1] == 4) &&
        (WorkingSet->Wlocalidx.data[mIneq - 1] > nVarMax)) {
      tmp_tmp = WorkingSet->nActiveConstr - 1;
      rho = TrialState->lambda->data[tmp_tmp];
      TrialState->lambda->data[tmp_tmp] = 0.0;
      TrialState->lambda->data[mIneq - 1] = rho;
      removeConstr(WorkingSet, mIneq);
      nActiveLBArtificial--;
    }
    mIneq--;
  }
  QPObjective->nvar = nVarOrig - 1;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  setProblemType(WorkingSet, 3);
  sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr, WorkingSet->sizes,
               WorkingSet->isActiveIdx, WorkingSet->Wid.data,
               WorkingSet->Wlocalidx.data, memspace->workspace_float);
}

/* End of code generation (relaxed.c) */
