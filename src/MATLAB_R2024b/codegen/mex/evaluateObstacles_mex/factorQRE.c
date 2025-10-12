/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factorQRE.c
 *
 * Code generation for function 'factorQRE'
 *
 */

/* Include files */
#include "factorQRE.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void factorQRE(f_struct_T *obj, const emxArray_real_T *A, int32_T mrows,
               int32_T ncols, int32_T ldA)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  const real_T *A_data;
  int32_T idx;
  boolean_T guard1;
  A_data = A->data;
  idx = mrows * ncols;
  guard1 = false;
  if (idx > 0) {
    for (idx = 0; idx < ncols; idx++) {
      n_t = (ptrdiff_t)mrows;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, (real_T *)&A_data[ldA * idx], &incx_t,
            &obj->QR->data[obj->ldq * idx], &incy_t);
    }
    guard1 = true;
  } else if (idx == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = muIntScalarMin_sint32(mrows, ncols);
    xgeqp3(obj->QR, mrows, ncols, obj->jpvt.data, &obj->jpvt.size[0], obj->tau);
  }
}

/* End of code generation (factorQRE.c) */
