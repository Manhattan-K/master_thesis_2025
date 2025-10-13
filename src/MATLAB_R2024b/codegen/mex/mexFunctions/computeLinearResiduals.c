/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeLinearResiduals.c
 *
 * Code generation for function 'computeLinearResiduals'
 *
 */

/* Include files */
#include "computeLinearResiduals.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void computeLinearResiduals(const real_T x[40], int32_T nVar,
                            real_T workspaceIneq_data[], int32_T mLinIneq,
                            const emxArray_real_T *AineqT, int32_T ldAi)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  const real_T *AineqT_data;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  AineqT_data = AineqT->data;
  if (mLinIneq > 0) {
    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mLinIneq;
    lda_t = (ptrdiff_t)ldAi;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, (real_T *)&AineqT_data[0], &lda_t,
          (real_T *)&x[0], &incx_t, &beta1, &workspaceIneq_data[0], &incy_t);
  }
}

/* End of code generation (computeLinearResiduals.c) */
