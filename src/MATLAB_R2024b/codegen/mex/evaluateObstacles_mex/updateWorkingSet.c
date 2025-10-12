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
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void updateWorkingSet(k_struct_T *WorkingSet,
                      const real_T TrialState_cIneq_data[],
                      const real_T TrialState_searchDir_data[],
                      int32_T workspace_int_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emxArray_real_T *y;
  real_T alpha1;
  real_T beta1;
  real_T *y_data;
  int32_T i;
  int32_T idx;
  int32_T idxIneqOffset;
  char_T TRANSA;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  idxIneqOffset = WorkingSet->isActiveIdx[2];
  if (WorkingSet->sizes[2] > 0) {
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
    for (idx = idx_Aineq; idx < i; idx++) {
      WorkingSet->bineq.data[idx] = -TrialState_cIneq_data[idx];
    }
    emxInit_real_T(&y, 1);
    i = y->size[0];
    y->size[0] = WorkingSet->bineq.size[0];
    emxEnsureCapacity_real_T(y, i);
    y_data = y->data;
    idx_Aineq = WorkingSet->bineq.size[0];
    for (i = 0; i < idx_Aineq; i++) {
      y_data[i] = WorkingSet->bineq.data[i];
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
    for (i = 0; i < idx_Aineq; i++) {
      WorkingSet->bineq.data[i] = y_data[i];
    }
    idx_Aineq = 1;
    idx_lower = WorkingSet->sizes[2] + 1;
    idx_upper = (WorkingSet->sizes[2] + WorkingSet->sizes[3]) + 1;
    i = WorkingSet->nActiveConstr;
    for (idx = idxIneqOffset; idx <= i; idx++) {
      int32_T idx_Partition;
      switch (WorkingSet->Wid.data[idx - 1]) {
      case 3:
        idx_Partition = idx_Aineq;
        idx_Aineq++;
        WorkingSet->bwset->data[idx - 1] =
            y_data[WorkingSet->Wlocalidx.data[idx - 1] - 1];
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
          WorkingSet->Wlocalidx.data[idx - 1];
    }
    emxFree_real_T(&y);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (updateWorkingSet.c) */
