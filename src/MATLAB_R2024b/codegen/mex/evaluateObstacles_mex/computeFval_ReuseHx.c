/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeFval_ReuseHx.c
 *
 * Code generation for function 'computeFval_ReuseHx'
 *
 */

/* Include files */
#include "computeFval_ReuseHx.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T computeFval_ReuseHx(const d_struct_T *obj, emxArray_real_T *workspace,
                           const real_T f_data[], const real_T x_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T val;
  real_T *workspace_data;
  int32_T b_i;
  int32_T vectorUB;
  workspace_data = workspace->data;
  val = 0.0;
  switch (obj->objtype) {
  case 5:
    val = obj->gammaScalar * x_data[obj->nvar - 1];
    break;
  case 3: {
    if (obj->hasLinear) {
      int32_T i;
      int32_T maxRegVar;
      i = obj->nvar;
      maxRegVar = (i / 4) << 2;
      vectorUB = maxRegVar - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        __m256d r;
        r = _mm256_loadu_pd(&obj->Hx.data[b_i]);
        _mm256_storeu_pd(&workspace_data[b_i],
                         _mm256_add_pd(_mm256_mul_pd(_mm256_set1_pd(0.5), r),
                                       _mm256_loadu_pd(&f_data[b_i])));
      }
      for (b_i = maxRegVar; b_i < i; b_i++) {
        workspace_data[b_i] = 0.5 * obj->Hx.data[b_i] + f_data[b_i];
      }
      if (obj->nvar >= 1) {
        n_t = (ptrdiff_t)obj->nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, (real_T *)&x_data[0], &incx_t, &workspace_data[0],
                   &incy_t);
      }
    } else {
      if (obj->nvar >= 1) {
        n_t = (ptrdiff_t)obj->nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, (real_T *)&x_data[0], &incx_t,
                   (real_T *)&obj->Hx.data[0], &incy_t);
      }
      val *= 0.5;
    }
  } break;
  case 4: {
    int32_T maxRegVar;
    maxRegVar = obj->maxVar;
    if (obj->hasLinear) {
      int32_T i;
      i = obj->nvar;
      for (b_i = 0; b_i < i; b_i++) {
        workspace_data[b_i] = f_data[b_i];
      }
      i = obj->maxVar - obj->nvar;
      for (b_i = 0; b_i <= i - 2; b_i++) {
        workspace_data[obj->nvar + b_i] = obj->rho;
      }
      i = (uint16_T)(obj->maxVar - 1);
      maxRegVar = (i / 4) << 2;
      vectorUB = maxRegVar - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        __m256d r;
        __m256d r1;
        r = _mm256_loadu_pd(&obj->Hx.data[b_i]);
        r1 = _mm256_loadu_pd(&workspace_data[b_i]);
        _mm256_storeu_pd(
            &workspace_data[b_i],
            _mm256_add_pd(r1, _mm256_mul_pd(_mm256_set1_pd(0.5), r)));
      }
      for (b_i = maxRegVar; b_i < i; b_i++) {
        workspace_data[b_i] += 0.5 * obj->Hx.data[b_i];
      }
      if (obj->maxVar - 1 >= 1) {
        n_t = (ptrdiff_t)(obj->maxVar - 1);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, (real_T *)&x_data[0], &incx_t, &workspace_data[0],
                   &incy_t);
      }
    } else {
      int32_T i;
      if (obj->maxVar - 1 >= 1) {
        n_t = (ptrdiff_t)(obj->maxVar - 1);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, (real_T *)&x_data[0], &incx_t,
                   (real_T *)&obj->Hx.data[0], &incy_t);
      }
      val *= 0.5;
      i = obj->nvar + 1;
      for (vectorUB = i; vectorUB < maxRegVar; vectorUB++) {
        val += x_data[vectorUB - 1] * obj->rho;
      }
    }
  } break;
  }
  return val;
}

/* End of code generation (computeFval_ReuseHx.c) */
