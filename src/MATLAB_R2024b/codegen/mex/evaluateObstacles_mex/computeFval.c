/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeFval.c
 *
 * Code generation for function 'computeFval'
 *
 */

/* Include files */
#include "computeFval.h"
#include "evaluateObstacles_mex_types.h"
#include "linearForm_.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T computeFval(const d_struct_T *obj, emxArray_real_T *workspace,
                   const real_T H[1600], const real_T f_data[],
                   const real_T x_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T val;
  real_T *workspace_data;
  int32_T idx;
  val = 0.0;
  switch (obj->objtype) {
  case 5:
    val = obj->gammaScalar * x_data[obj->nvar - 1];
    break;
  case 3:
    linearForm_(obj->hasLinear, obj->nvar, workspace, H, f_data, x_data);
    workspace_data = workspace->data;
    if (obj->nvar >= 1) {
      n_t = (ptrdiff_t)obj->nvar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      val = ddot(&n_t, (real_T *)&x_data[0], &incx_t, &workspace_data[0],
                 &incy_t);
    }
    break;
  case 4: {
    int32_T i;
    int32_T i1;
    int32_T scalarLB;
    int32_T vectorUB;
    linearForm_(obj->hasLinear, obj->nvar, workspace, H, f_data, x_data);
    workspace_data = workspace->data;
    i = obj->nvar + 1;
    i1 = obj->maxVar;
    scalarLB = (((i1 - i) / 4) << 2) + i;
    vectorUB = scalarLB - 4;
    for (idx = i; idx <= vectorUB; idx += 4) {
      _mm256_storeu_pd(
          &workspace_data[idx - 1],
          _mm256_add_pd(_mm256_mul_pd(_mm256_set1_pd(0.5 * obj->beta),
                                      _mm256_loadu_pd(&x_data[idx - 1])),
                        _mm256_set1_pd(obj->rho)));
    }
    for (idx = scalarLB; idx < i1; idx++) {
      workspace_data[idx - 1] = 0.5 * obj->beta * x_data[idx - 1] + obj->rho;
    }
    if (obj->maxVar - 1 >= 1) {
      n_t = (ptrdiff_t)(obj->maxVar - 1);
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      val = ddot(&n_t, (real_T *)&x_data[0], &incx_t, &workspace_data[0],
                 &incy_t);
    }
  } break;
  }
  return val;
}

/* End of code generation (computeFval.c) */
