/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateWorkingSet.c
 *
 * Code generation for function 'updateWorkingSet'
 *
 */

/* Include files */
#include "updateWorkingSet.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "omp.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void updateWorkingSet(emlrtCTX aTLS, i_struct_T *WorkingSet,
                      const real_T TrialState_cIneq_data[],
                      const real_T TrialState_searchDir_data[],
                      int32_T workspace_int_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T *y;
  real_T alpha1;
  real_T beta1;
  real_T *y_data;
  int32_T b_idx;
  int32_T idx;
  int32_T idxIneqOffset;
  int32_T updateWorkingSet_numThreads;
  char_T TRANSA;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  idxIneqOffset = WorkingSet->isActiveIdx[2];
  if (WorkingSet->sizes[2] > 0) {
    int32_T i;
    int32_T idx_Aineq;
    int32_T idx_lower;
    int32_T idx_upper;
    i = (uint16_T)WorkingSet->sizes[2];
    idx_Aineq = (i / 4) << 2;
    idx_lower = idx_Aineq - 4;
    for (idx = 0; idx <= idx_lower; idx += 4) {
      _mm256_storeu_pd(
          &WorkingSet->bineq.data[idx],
          _mm256_mul_pd(_mm256_loadu_pd(&TrialState_cIneq_data[idx]),
                        _mm256_set1_pd(-1.0)));
    }
    if (i - idx_Aineq < 1200) {
      for (idx = idx_Aineq; idx < i; idx++) {
        WorkingSet->bineq.data[idx] = -TrialState_cIneq_data[idx];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      updateWorkingSet_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(updateWorkingSet_numThreads)

      for (idx = idx_Aineq; idx < i; idx++) {
        WorkingSet->bineq.data[idx] = -TrialState_cIneq_data[idx];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    emxInit_real_T(&y, 1);
    i = y->size[0];
    y->size[0] = WorkingSet->bineq.size[0];
    emxEnsureCapacity_real_T(y, i);
    y_data = y->data;
    idx_Aineq = WorkingSet->bineq.size[0];
    if (idx_Aineq < 1200) {
      for (idx = 0; idx < idx_Aineq; idx++) {
        y_data[idx] = WorkingSet->bineq.data[idx];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      updateWorkingSet_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(updateWorkingSet_numThreads)

      for (idx = 0; idx < idx_Aineq; idx++) {
        y_data[idx] = WorkingSet->bineq.data[idx];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)WorkingSet->nVar;
    n_t = (ptrdiff_t)WorkingSet->sizes[2];
    lda_t = (ptrdiff_t)WorkingSet->ldA;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &WorkingSet->Aineq->data[0], &lda_t,
          (real_T *)&TrialState_searchDir_data[0], &incx_t, &beta1, &y_data[0],
          &incy_t);
    idx_Aineq = y->size[0];
    WorkingSet->bineq.size[0] = y->size[0];
    idx_lower = y->size[0];
    if (y->size[0] < 1200) {
      for (idx = 0; idx < idx_Aineq; idx++) {
        WorkingSet->bineq.data[idx] = y_data[idx];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      updateWorkingSet_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(updateWorkingSet_numThreads)

      for (idx = 0; idx < idx_lower; idx++) {
        WorkingSet->bineq.data[idx] = y_data[idx];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    idx_Aineq = 1;
    idx_lower = WorkingSet->sizes[2] + 1;
    idx_upper = (WorkingSet->sizes[2] + WorkingSet->sizes[3]) + 1;
    i = WorkingSet->nActiveConstr;
    for (b_idx = idxIneqOffset; b_idx <= i; b_idx++) {
      int32_T idx_Partition;
      switch (WorkingSet->Wid.data[b_idx - 1]) {
      case 3:
        idx_Partition = idx_Aineq;
        idx_Aineq++;
        WorkingSet->bwset->data[b_idx - 1] =
            y_data[WorkingSet->Wlocalidx.data[b_idx - 1] - 1];
        break;
      case 4:
        idx_Partition = idx_lower;
        idx_lower++;
        break;
      default:
        idx_Partition = idx_upper;
        idx_upper++;
        break;
      }
      workspace_int_data[idx_Partition - 1] =
          WorkingSet->Wlocalidx.data[b_idx - 1];
    }
    emxFree_real_T(&y);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

/* End of code generation (updateWorkingSet.c) */
