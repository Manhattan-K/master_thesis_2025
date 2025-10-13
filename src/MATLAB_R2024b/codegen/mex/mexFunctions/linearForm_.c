/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * linearForm_.c
 *
 * Code generation for function 'linearForm_'
 *
 */

/* Include files */
#include "linearForm_.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void linearForm_(emlrtCTX aTLS, boolean_T obj_hasLinear, int32_T obj_nvar,
                 emxArray_real_T *workspace, const real_T H[1600],
                 const real_T f_data[], const real_T x_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  real_T alpha1;
  real_T beta1;
  real_T *workspace_data;
  int32_T i;
  int32_T linearForm__numThreads;
  char_T TRANSA;
  workspace_data = workspace->data;
  beta1 = 0.0;
  if (obj_hasLinear) {
    if (obj_nvar < 1200) {
      for (i = 0; i < obj_nvar; i++) {
        workspace_data[i] = f_data[i];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      linearForm__numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(linearForm__numThreads)

      for (i = 0; i < obj_nvar; i++) {
        workspace_data[i] = f_data[i];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    beta1 = 1.0;
  }
  if (obj_nvar >= 1) {
    alpha1 = 0.5;
    TRANSA = 'N';
    m_t = (ptrdiff_t)obj_nvar;
    n_t = (ptrdiff_t)obj_nvar;
    lda_t = (ptrdiff_t)obj_nvar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, (real_T *)&H[0], &lda_t,
          (real_T *)&x_data[0], &incx_t, &beta1, &workspace_data[0], &incy_t);
  }
}

/* End of code generation (linearForm_.c) */
