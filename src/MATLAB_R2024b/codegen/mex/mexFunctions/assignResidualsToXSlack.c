/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assignResidualsToXSlack.c
 *
 * Code generation for function 'assignResidualsToXSlack'
 *
 */

/* Include files */
#include "assignResidualsToXSlack.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void assignResidualsToXSlack(emlrtCTX aTLS, int32_T nVarOrig,
                             const i_struct_T *WorkingSet,
                             h_struct_T *TrialState, f_struct_T *memspace)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  real_T alpha1;
  real_T beta1;
  int32_T assignResidualsToXSlack_numThreads;
  int32_T i;
  int32_T idx;
  char_T TRANSA;
  if (WorkingSet->sizes[2] >= 1) {
    n_t = (ptrdiff_t)WorkingSet->sizes[2];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, (real_T *)&WorkingSet->bineq.data[0], &incx_t,
          &memspace->workspace_float->data[0], &incy_t);
  }
  if (WorkingSet->sizes[2] >= 1) {
    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)nVarOrig;
    n_t = (ptrdiff_t)WorkingSet->sizes[2];
    lda_t = (ptrdiff_t)WorkingSet->ldA;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &WorkingSet->Aineq->data[0], &lda_t,
          &TrialState->xstar.data[0], &incx_t, &beta1,
          &memspace->workspace_float->data[0], &incy_t);
  }
  i = (uint16_T)WorkingSet->sizes[2];
  if (i < 1200) {
    for (idx = 0; idx < i; idx++) {
      TrialState->xstar.data[nVarOrig + idx] =
          (real_T)(memspace->workspace_float->data[idx] > 0.0) *
          memspace->workspace_float->data[idx];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    assignResidualsToXSlack_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(assignResidualsToXSlack_numThreads)

    for (idx = 0; idx < i; idx++) {
      TrialState->xstar.data[nVarOrig + idx] =
          (real_T)(memspace->workspace_float->data[idx] > 0.0) *
          memspace->workspace_float->data[idx];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
}

/* End of code generation (assignResidualsToXSlack.c) */
