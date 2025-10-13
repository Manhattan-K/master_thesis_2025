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
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSet.h"
#include "xcopy.h"
#include "xnrm2.h"
#include "omp.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
boolean_T soc(emlrtCTX aTLS, const real_T Hessian[1600],
              const real_T grad_data[], h_struct_T *TrialState,
              f_struct_T *memspace, i_struct_T *WorkingSet,
              g_struct_T *QRManager, m_struct_T *CholManager,
              e_struct_T *QPObjective, const n_struct_T *qpoptions)
{
  __m256d r;
  jmp_buf *volatile emlrtJBStack;
  real_T d;
  real_T oldDirIdx;
  int32_T i;
  int32_T idx;
  int32_T idxEndIneq;
  int32_T idxStartIneq_tmp;
  int32_T k;
  int32_T mConstrMax;
  int32_T mIneq;
  int32_T mLB;
  int32_T nVar;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  int32_T soc_numThreads;
  int32_T vectorUB;
  boolean_T success;
  nWIneq_old = WorkingSet->nWConstr[2];
  nWLower_old = WorkingSet->nWConstr[3];
  nWUpper_old = WorkingSet->nWConstr[4];
  nVar = WorkingSet->nVar;
  mConstrMax = WorkingSet->mConstrMax;
  i = (uint16_T)WorkingSet->nVar;
  if (i < 1200) {
    if (i - 1 >= 0) {
      memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0],
             (uint32_T)i * sizeof(real_T));
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    soc_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(soc_numThreads)

    for (k = 0; k < i; k++) {
      TrialState->xstarsqp[k] = TrialState->xstarsqp_old[k];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  i = (uint16_T)WorkingSet->nVar;
  if (i < 1200) {
    if (i - 1 >= 0) {
      memcpy(&TrialState->socDirection.data[0], &TrialState->xstar.data[0],
             (uint32_T)i * sizeof(real_T));
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    soc_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(soc_numThreads)

    for (k = 0; k < i; k++) {
      TrialState->socDirection.data[k] = TrialState->xstar.data[k];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  xcopy(WorkingSet->mConstrMax, TrialState->lambda, TrialState->lambdaStopTest);
  updateWorkingSet(aTLS, WorkingSet, TrialState->cIneq.data,
                   TrialState->searchDir.data, TrialState->workingset_old.data);
  i = (uint16_T)WorkingSet->nVar;
  if (i < 1200) {
    if (i - 1 >= 0) {
      memcpy(&TrialState->xstar.data[0], &TrialState->xstarsqp[0],
             (uint32_T)i * sizeof(real_T));
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    soc_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(soc_numThreads)

    for (k = 0; k < i; k++) {
      TrialState->xstar.data[k] = TrialState->xstarsqp[k];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  b_driver(aTLS, Hessian, grad_data, TrialState, memspace, WorkingSet,
           QRManager, CholManager, QPObjective, qpoptions, qpoptions);
  i = (uint16_T)nVar;
  idxStartIneq_tmp = (uint16_T)nVar;
  idxEndIneq = ((uint16_T)nVar >> 2) << 2;
  vectorUB = idxEndIneq - 4;
  for (k = 0; k <= vectorUB; k += 4) {
    __m256d r1;
    r = _mm256_loadu_pd(&TrialState->socDirection.data[k]);
    r1 = _mm256_loadu_pd(&TrialState->xstar.data[k]);
    _mm256_storeu_pd(&TrialState->socDirection.data[k], _mm256_sub_pd(r1, r));
    _mm256_storeu_pd(&TrialState->xstar.data[k], r);
  }
  if ((uint16_T)nVar - idxEndIneq < 1200) {
    for (k = idxEndIneq; k < i; k++) {
      d = TrialState->socDirection.data[k];
      oldDirIdx = d;
      d = TrialState->xstar.data[k] - d;
      TrialState->socDirection.data[k] = d;
      TrialState->xstar.data[k] = oldDirIdx;
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    soc_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(soc_numThreads) private(oldDirIdx, d)

    for (k = idxEndIneq; k < idxStartIneq_tmp; k++) {
      d = TrialState->socDirection.data[k];
      oldDirIdx = d;
      d = TrialState->xstar.data[k] - d;
      TrialState->socDirection.data[k] = d;
      TrialState->xstar.data[k] = oldDirIdx;
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  success = (xnrm2(nVar, TrialState->socDirection.data) <=
             2.0 * xnrm2(nVar, TrialState->xstar.data));
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  if (WorkingSet->sizes[2] > 0) {
    i = (uint16_T)WorkingSet->sizes[2];
    idxEndIneq = (i / 4) << 2;
    vectorUB = idxEndIneq - 4;
    for (k = 0; k <= vectorUB; k += 4) {
      r = _mm256_loadu_pd(&TrialState->cIneq.data[k]);
      _mm256_storeu_pd(&WorkingSet->bineq.data[k],
                       _mm256_mul_pd(r, _mm256_set1_pd(-1.0)));
    }
    if (i - idxEndIneq < 1200) {
      for (k = idxEndIneq; k < i; k++) {
        WorkingSet->bineq.data[k] = -TrialState->cIneq.data[k];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      soc_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(soc_numThreads)

      for (k = idxEndIneq; k < i; k++) {
        WorkingSet->bineq.data[k] = -TrialState->cIneq.data[k];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    if (!success) {
      idxStartIneq_tmp = WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1];
      nVar = idxStartIneq_tmp + 1;
      idxEndIneq = WorkingSet->nActiveConstr;
      for (vectorUB = nVar; vectorUB <= idxEndIneq; vectorUB++) {
        WorkingSet->isActiveConstr.data
            [(WorkingSet->isActiveIdx[WorkingSet->Wid.data[vectorUB - 1] - 1] +
              WorkingSet->Wlocalidx.data[vectorUB - 1]) -
             2] = false;
      }
      WorkingSet->nWConstr[2] = 0;
      WorkingSet->nWConstr[3] = 0;
      WorkingSet->nWConstr[4] = 0;
      WorkingSet->nActiveConstr = idxStartIneq_tmp;
      for (vectorUB = 0; vectorUB < nWIneq_old; vectorUB++) {
        idxStartIneq_tmp = TrialState->workingset_old.data[vectorUB];
        WorkingSet->nWConstr[2]++;
        WorkingSet->isActiveConstr
            .data[(WorkingSet->isActiveIdx[2] + idxStartIneq_tmp) - 2] = true;
        WorkingSet->nActiveConstr++;
        i = WorkingSet->nActiveConstr - 1;
        WorkingSet->Wid.data[i] = 3;
        WorkingSet->Wlocalidx.data[i] = idxStartIneq_tmp;
        idxEndIneq = WorkingSet->ldA * (idxStartIneq_tmp - 1);
        nVar = WorkingSet->ldA * i;
        i = WorkingSet->nVar;
        for (idx = 0; idx < i; idx++) {
          WorkingSet->ATwset->data[nVar + idx] =
              WorkingSet->Aineq->data[idxEndIneq + idx];
        }
        WorkingSet->bwset->data[WorkingSet->nActiveConstr - 1] =
            WorkingSet->bineq.data[idxStartIneq_tmp - 1];
      }
      for (vectorUB = 0; vectorUB < nWLower_old; vectorUB++) {
        addBoundToActiveSetMatrix_(
            WorkingSet, 4, TrialState->workingset_old.data[vectorUB + mIneq]);
      }
      for (vectorUB = 0; vectorUB < nWUpper_old; vectorUB++) {
        addBoundToActiveSetMatrix_(
            WorkingSet, 5,
            TrialState->workingset_old.data[(vectorUB + mIneq) + mLB]);
      }
    }
  }
  if (!success) {
    xcopy(mConstrMax, TrialState->lambdaStopTest, TrialState->lambda);
  } else {
    sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr,
                 WorkingSet->sizes, WorkingSet->isActiveIdx,
                 WorkingSet->Wid.data, WorkingSet->Wlocalidx.data,
                 memspace->workspace_float);
  }
  return success;
}

/* End of code generation (soc.c) */
