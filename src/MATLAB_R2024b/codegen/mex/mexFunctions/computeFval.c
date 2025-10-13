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
#include "linearForm_.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "omp.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T computeFval(emlrtCTX aTLS, const e_struct_T *obj,
                   emxArray_real_T *workspace, const real_T H[1600],
                   const real_T f_data[], const real_T x_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  real_T val;
  real_T *workspace_data;
  int32_T b_workspace;
  int32_T computeFval_numThreads;
  val = 0.0;
  switch (obj->objtype) {
  case 5:
    val = obj->gammaScalar * x_data[obj->nvar - 1];
    break;
  case 3:
    linearForm_(aTLS, obj->hasLinear, obj->nvar, workspace, H, f_data, x_data);
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
    linearForm_(aTLS, obj->hasLinear, obj->nvar, workspace, H, f_data, x_data);
    workspace_data = workspace->data;
    i = obj->nvar + 1;
    i1 = obj->maxVar;
    scalarLB = (((i1 - i) / 4) << 2) + i;
    vectorUB = scalarLB - 4;
    for (b_workspace = i; b_workspace <= vectorUB; b_workspace += 4) {
      _mm256_storeu_pd(
          &workspace_data[b_workspace - 1],
          _mm256_add_pd(
              _mm256_mul_pd(_mm256_set1_pd(0.5 * obj->beta),
                            _mm256_loadu_pd(&x_data[b_workspace - 1])),
              _mm256_set1_pd(obj->rho)));
    }
    if (i1 - scalarLB < 1200) {
      for (b_workspace = scalarLB; b_workspace < i1; b_workspace++) {
        workspace_data[b_workspace - 1] =
            0.5 * obj->beta * x_data[b_workspace - 1] + obj->rho;
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      computeFval_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(computeFval_numThreads)

      for (b_workspace = scalarLB; b_workspace < i1; b_workspace++) {
        workspace_data[b_workspace - 1] =
            0.5 * obj->beta * x_data[b_workspace - 1] + obj->rho;
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
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
