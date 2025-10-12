/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation_AMats_regularized_.c
 *
 * Code generation for function 'maxConstraintViolation_AMats_regularized_'
 *
 */

/* Include files */
#include "maxConstraintViolation_AMats_regularized_.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T c_maxConstraintViolation_AMats_(k_struct_T *obj, const real_T x_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  real_T v;
  int32_T idx;
  char_T TRANSA;
  v = 0.0;
  if (obj->Aineq->size[0] != 0) {
    int32_T i;
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
      m_t = (ptrdiff_t)40;
      n_t = (ptrdiff_t)obj->sizes[2];
      lda_t = (ptrdiff_t)obj->ldA;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dgemv(&TRANSA, &m_t, &n_t, &alpha1, &obj->Aineq->data[0], &lda_t,
            (real_T *)&x_data[0], &incx_t, &beta1,
            &obj->maxConstrWorkspace->data[0], &incy_t);
    }
    i = (uint16_T)obj->sizes[2];
    for (idx = 0; idx < i; idx++) {
      alpha1 = obj->maxConstrWorkspace->data[idx] - x_data[idx + 40];
      obj->maxConstrWorkspace->data[idx] = alpha1;
      v = muDoubleScalarMax(v, alpha1);
    }
  }
  return v;
}

/* End of code generation (maxConstraintViolation_AMats_regularized_.c) */
