/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdot.c
 *
 * Code generation for function 'xdot'
 *
 */

/* Include files */
#include "xdot.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T b_xdot(int32_T n, const real_T x_data[], int32_T ix0,
              const real_T y_data[], int32_T iy0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T d;
  if (n < 1) {
    d = 0.0;
  } else {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    d = ddot(&n_t, (real_T *)&x_data[ix0 - 1], &incx_t,
             (real_T *)&y_data[iy0 - 1], &incy_t);
  }
  return d;
}

real_T xdot(int32_T n, const emxArray_real_T *x, int32_T ix0,
            const real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  const real_T *x_data;
  x_data = x->data;
  n_t = (ptrdiff_t)n;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  return ddot(&n_t, (real_T *)&x_data[ix0 - 1], &incx_t, (real_T *)&y_data[0],
              &incy_t);
}

/* End of code generation (xdot.c) */
