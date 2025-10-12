/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeDeltaLag.c
 *
 * Code generation for function 'computeDeltaLag'
 *
 */

/* Include files */
#include "computeDeltaLag.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void computeDeltaLag(int32_T nVar, int32_T ldJ, int32_T mNonlinIneq,
                     real_T workspace_data[], const real_T grad_data[],
                     const emxArray_real_T *JacIneqTrans, int32_T ineqJ0,
                     const real_T grad_old_data[],
                     const emxArray_real_T *JacIneqTrans_old,
                     const emxArray_real_T *lambda, int32_T ineqL0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  const real_T *JacIneqTrans_data;
  const real_T *JacIneqTrans_old_data;
  const real_T *lambda_data;
  real_T a;
  real_T beta1;
  int32_T i;
  char_T TRANSA;
  lambda_data = lambda->data;
  JacIneqTrans_old_data = JacIneqTrans_old->data;
  JacIneqTrans_data = JacIneqTrans->data;
  i = (uint16_T)nVar;
  memcpy(&workspace_data[0], &grad_data[0], (uint32_T)i * sizeof(real_T));
  if (nVar >= 1) {
    a = -1.0;
    n_t = (ptrdiff_t)nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    daxpy(&n_t, &a, (real_T *)&grad_old_data[0], &incx_t, &workspace_data[0],
          &incy_t);
  }
  if (mNonlinIneq > 0) {
    a = 1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mNonlinIneq;
    lda_t = (ptrdiff_t)ldJ;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &a,
          (real_T *)&JacIneqTrans_data[ldJ * (ineqJ0 - 1)], &lda_t,
          (real_T *)&lambda_data[ineqL0 - 1], &incx_t, &beta1,
          &workspace_data[0], &incy_t);
    a = -1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mNonlinIneq;
    lda_t = (ptrdiff_t)ldJ;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &a, (real_T *)&JacIneqTrans_old_data[0], &lda_t,
          (real_T *)&lambda_data[ineqL0 - 1], &incx_t, &beta1,
          &workspace_data[0], &incy_t);
  }
}

/* End of code generation (computeDeltaLag.c) */
