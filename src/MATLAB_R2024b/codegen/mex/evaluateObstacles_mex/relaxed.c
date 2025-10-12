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
#include "evaluateObstacles_mex_internal_types.h"
#include "evaluateObstacles_mex_types.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include "updatePenaltyParam.h"
#include "xasum.h"
#include "xdot.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void relaxed(const real_T Hessian[1600], const real_T grad_data[],
             j_struct_T *TrialState, l_struct_T *MeritFunction,
             e_struct_T *memspace, k_struct_T *WorkingSet,
             f_struct_T *QRManager, n_struct_T *CholManager,
             d_struct_T *QPObjective, o_struct_T *qpoptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  emxArray_real_T *x;
  const real_T *x_data;
  real_T beta;
  real_T rho;
  int32_T idx;
  int32_T mIneq;
  int32_T nActiveLBArtificial;
  int32_T nVarOrig;
  int32_T temp;
  nVarOrig = WorkingSet->nVar + 1;
  mIneq = WorkingSet->sizes[2];
  beta = 0.0;
  temp = (uint16_T)WorkingSet->nVar;
  for (idx = 0; idx < temp; idx++) {
    beta += Hessian[idx + 40 * idx];
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
  assignResidualsToXSlack(nVarOrig - 1, WorkingSet, TrialState, memspace);
  temp = qpoptions->MaxIterations;
  qpoptions->MaxIterations =
      ((qpoptions->MaxIterations + WorkingSet->nVar) - nVarOrig) + 1;
  b_driver(Hessian, grad_data, TrialState, memspace, WorkingSet, QRManager,
           CholManager, QPObjective, qpoptions, qpoptions);
  qpoptions->MaxIterations = temp;
  nActiveLBArtificial = 0;
  temp = (uint16_T)WorkingSet->sizes[2];
  for (idx = 0; idx < temp; idx++) {
    boolean_T tf;
    tf = WorkingSet->isActiveConstr
             .data[(((WorkingSet->isActiveIdx[3] + WorkingSet->sizes[3]) -
                     WorkingSet->sizes[2]) +
                    idx) -
                   1];
    memspace->workspace_int.data[idx] = tf;
    nActiveLBArtificial += tf;
  }
  if (TrialState->state != -6) {
    temp = WorkingSet->nVarMax - nVarOrig;
    updatePenaltyParam(MeritFunction, TrialState->sqpFval,
                       TrialState->cIneq.data, mIneq, TrialState->sqpIterations,
                       (TrialState->fstar -
                        rho * xasum(temp, TrialState->xstar.data, nVarOrig)) -
                           beta / 2.0 *
                               b_xdot(temp, TrialState->xstar.data, nVarOrig,
                                      TrialState->xstar.data, nVarOrig),
                       TrialState->xstar.data, nVarOrig,
                       WorkingSet->nVarMax - nVarOrig);
    temp = WorkingSet->isActiveIdx[2];
    mIneq = WorkingSet->nActiveConstr;
    for (idx = temp; idx <= mIneq; idx++) {
      if (WorkingSet->Wid.data[idx - 1] == 3) {
        TrialState->lambda->data[idx - 1] *=
            (real_T)memspace->workspace_int
                .data[WorkingSet->Wlocalidx.data[idx - 1] - 1];
      }
    }
  }
  temp = WorkingSet->sizes[0];
  mIneq = WorkingSet->sizes[3] - WorkingSet->sizes[2];
  idx = WorkingSet->nActiveConstr;
  while ((idx > temp) && (nActiveLBArtificial > 0)) {
    if ((WorkingSet->Wid.data[idx - 1] == 4) &&
        (WorkingSet->Wlocalidx.data[idx - 1] > mIneq)) {
      int32_T tmp_tmp;
      tmp_tmp = WorkingSet->nActiveConstr - 1;
      beta = TrialState->lambda->data[tmp_tmp];
      TrialState->lambda->data[tmp_tmp] = 0.0;
      TrialState->lambda->data[idx - 1] = beta;
      removeConstr(WorkingSet, idx);
      nActiveLBArtificial--;
    }
    idx--;
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
