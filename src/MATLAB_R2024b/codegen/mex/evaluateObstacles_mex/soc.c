/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * soc.c
 *
 * Code generation for function 'soc'
 *
 */

/* Include files */
#include "soc.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "evaluateObstacles_mex_internal_types.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSet.h"
#include "xcopy.h"
#include "xnrm2.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
boolean_T soc(const real_T Hessian[1600], const real_T grad_data[],
              j_struct_T *TrialState, e_struct_T *memspace,
              k_struct_T *WorkingSet, f_struct_T *QRManager,
              n_struct_T *CholManager, d_struct_T *QPObjective,
              const o_struct_T *qpoptions)
{
  __m256d r;
  int32_T b_idx;
  int32_T idx;
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T idx_global;
  int32_T mIneq;
  int32_T mLB;
  int32_T nVar_tmp;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  boolean_T success;
  nWIneq_old = WorkingSet->nWConstr[2];
  nWLower_old = WorkingSet->nWConstr[3];
  nWUpper_old = WorkingSet->nWConstr[4];
  nVar_tmp = WorkingSet->nVar;
  idx_global = (uint16_T)WorkingSet->nVar;
  memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0],
         (uint32_T)idx_global * sizeof(real_T));
  memcpy(&TrialState->socDirection.data[0], &TrialState->xstar.data[0],
         (uint32_T)idx_global * sizeof(real_T));
  xcopy(WorkingSet->mConstrMax, TrialState->lambda, TrialState->lambdaStopTest);
  updateWorkingSet(WorkingSet, TrialState->cIneq.data,
                   TrialState->searchDir.data, TrialState->workingset_old.data);
  idx_global = (uint16_T)WorkingSet->nVar;
  memcpy(&TrialState->xstar.data[0], &TrialState->xstarsqp[0],
         (uint32_T)idx_global * sizeof(real_T));
  b_driver(Hessian, grad_data, TrialState, memspace, WorkingSet, QRManager,
           CholManager, QPObjective, qpoptions, qpoptions);
  idx_global = (uint16_T)nVar_tmp;
  idxStartIneq = ((uint16_T)nVar_tmp >> 2) << 2;
  idxEndIneq = idxStartIneq - 4;
  for (idx = 0; idx <= idxEndIneq; idx += 4) {
    __m256d r1;
    r = _mm256_loadu_pd(&TrialState->socDirection.data[idx]);
    r1 = _mm256_loadu_pd(&TrialState->xstar.data[idx]);
    _mm256_storeu_pd(&TrialState->socDirection.data[idx], _mm256_sub_pd(r1, r));
    _mm256_storeu_pd(&TrialState->xstar.data[idx], r);
  }
  for (idx = idxStartIneq; idx < idx_global; idx++) {
    real_T d;
    real_T oldDirIdx;
    d = TrialState->socDirection.data[idx];
    oldDirIdx = d;
    d = TrialState->xstar.data[idx] - d;
    TrialState->socDirection.data[idx] = d;
    TrialState->xstar.data[idx] = oldDirIdx;
  }
  success = (xnrm2(nVar_tmp, TrialState->socDirection.data) <=
             2.0 * xnrm2(nVar_tmp, TrialState->xstar.data));
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  if (WorkingSet->sizes[2] > 0) {
    idx_global = (uint16_T)WorkingSet->sizes[2];
    idxStartIneq = (idx_global / 4) << 2;
    idxEndIneq = idxStartIneq - 4;
    for (idx = 0; idx <= idxEndIneq; idx += 4) {
      r = _mm256_loadu_pd(&TrialState->cIneq.data[idx]);
      _mm256_storeu_pd(&WorkingSet->bineq.data[idx],
                       _mm256_mul_pd(r, _mm256_set1_pd(-1.0)));
    }
    for (idx = idxStartIneq; idx < idx_global; idx++) {
      WorkingSet->bineq.data[idx] = -TrialState->cIneq.data[idx];
    }
    if (!success) {
      nVar_tmp = WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1];
      idxStartIneq = nVar_tmp + 1;
      idxEndIneq = WorkingSet->nActiveConstr;
      for (idx_global = idxStartIneq; idx_global <= idxEndIneq; idx_global++) {
        WorkingSet->isActiveConstr
            .data[(WorkingSet
                       ->isActiveIdx[WorkingSet->Wid.data[idx_global - 1] - 1] +
                   WorkingSet->Wlocalidx.data[idx_global - 1]) -
                  2] = false;
      }
      WorkingSet->nWConstr[2] = 0;
      WorkingSet->nWConstr[3] = 0;
      WorkingSet->nWConstr[4] = 0;
      WorkingSet->nActiveConstr = nVar_tmp;
      for (idx = 0; idx < nWIneq_old; idx++) {
        nVar_tmp = TrialState->workingset_old.data[idx];
        WorkingSet->nWConstr[2]++;
        WorkingSet->isActiveConstr
            .data[(WorkingSet->isActiveIdx[2] + nVar_tmp) - 2] = true;
        WorkingSet->nActiveConstr++;
        idx_global = WorkingSet->nActiveConstr - 1;
        WorkingSet->Wid.data[idx_global] = 3;
        WorkingSet->Wlocalidx.data[idx_global] = nVar_tmp;
        idxStartIneq = WorkingSet->ldA * (nVar_tmp - 1);
        idxEndIneq = WorkingSet->ldA * idx_global;
        idx_global = WorkingSet->nVar;
        for (b_idx = 0; b_idx < idx_global; b_idx++) {
          WorkingSet->ATwset->data[idxEndIneq + b_idx] =
              WorkingSet->Aineq->data[idxStartIneq + b_idx];
        }
        WorkingSet->bwset->data[WorkingSet->nActiveConstr - 1] =
            WorkingSet->bineq.data[nVar_tmp - 1];
      }
      for (idx = 0; idx < nWLower_old; idx++) {
        addBoundToActiveSetMatrix_(
            WorkingSet, 4, TrialState->workingset_old.data[idx + mIneq]);
      }
      for (idx = 0; idx < nWUpper_old; idx++) {
        addBoundToActiveSetMatrix_(
            WorkingSet, 5,
            TrialState->workingset_old.data[(idx + mIneq) + mLB]);
      }
    }
  }
  if (!success) {
    xcopy(WorkingSet->mConstrMax, TrialState->lambdaStopTest,
          TrialState->lambda);
  } else {
    sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr,
                 WorkingSet->sizes, WorkingSet->isActiveIdx,
                 WorkingSet->Wid.data, WorkingSet->Wlocalidx.data,
                 memspace->workspace_float);
  }
  return success;
}

/* End of code generation (soc.c) */
