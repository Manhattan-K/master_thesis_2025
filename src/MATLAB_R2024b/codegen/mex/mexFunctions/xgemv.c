/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.c
 *
 * Code generation for function 'xgemv'
 *
 */

/* Include files */
#include "xgemv.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void xgemv(int32_T m, int32_T n, const emxArray_real_T *A, int32_T lda,
           const real_T x_data[], emxArray_real_T *y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  const real_T *A_data;
  real_T alpha1;
  real_T beta1;
  real_T *y_data;
  char_T TRANSA;
  y_data = y->data;
  A_data = A->data;
  alpha1 = -1.0;
  beta1 = 1.0;
  TRANSA = 'T';
  m_t = (ptrdiff_t)m;
  n_t = (ptrdiff_t)n;
  lda_t = (ptrdiff_t)lda;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dgemv(&TRANSA, &m_t, &n_t, &alpha1, (real_T *)&A_data[0], &lda_t,
        (real_T *)&x_data[0], &incx_t, &beta1, &y_data[0], &incy_t);
}

/* End of code generation (xgemv.c) */
