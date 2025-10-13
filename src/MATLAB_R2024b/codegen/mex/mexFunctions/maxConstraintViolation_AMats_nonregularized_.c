/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation_AMats_nonregularized_.c
 *
 * Code generation for function 'maxConstraintViolation_AMats_nonregularized_'
 *
 */

/* Include files */
#include "maxConstraintViolation_AMats_nonregularized_.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T d_maxConstraintViolation_AMats_(emlrtCTX aTLS, i_struct_T *obj,
                                       const real_T x_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  real_T alpha1;
  real_T beta1;
  real_T v;
  real_T vPrime;
  int32_T d_maxConstraintViolation_AMats__numThreads;
  int32_T i;
  int32_T idx;
  char_T TRANSA;
  v = 0.0;
  if (obj->Aineq->size[0] != 0) {
    if (obj->sizes[2] >= 1) {
      n_t = (ptrdiff_t)obj->sizes[2];
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &obj->bineq.data[0], &incx_t,
            &obj->maxConstrWorkspace->data[0], &incy_t);
    }
    if (obj->sizes[2] >= 1) {
      alpha1 = 1.0;
      beta1 = -1.0;
      TRANSA = 'T';
      m_t = (ptrdiff_t)obj->nVar;
      n_t = (ptrdiff_t)obj->sizes[2];
      lda_t = (ptrdiff_t)obj->ldA;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dgemv(&TRANSA, &m_t, &n_t, &alpha1, &obj->Aineq->data[0], &lda_t,
            (real_T *)&x_data[0], &incx_t, &beta1,
            &obj->maxConstrWorkspace->data[0], &incy_t);
    }
    i = (uint16_T)obj->sizes[2];
    if (i < 1200) {
      for (idx = 0; idx < i; idx++) {
        v = muDoubleScalarMax(v, obj->maxConstrWorkspace->data[idx]);
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      d_maxConstraintViolation_AMats__numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(                                              \
        d_maxConstraintViolation_AMats__numThreads) private(vPrime)
      {
        vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < i; idx++) {
          vPrime =
              muDoubleScalarMax(vPrime, obj->maxConstrWorkspace->data[idx]);
        }
        omp_set_nest_lock(&mexFunctions_nestLockGlobal);
        {

          v = muDoubleScalarMax(v, vPrime);
        }
        omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  return v;
}

/* End of code generation (maxConstraintViolation_AMats_nonregularized_.c) */
