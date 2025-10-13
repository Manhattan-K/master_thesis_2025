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
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "omp.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T computeFval_ReuseHx(emlrtCTX aTLS, const e_struct_T *obj,
                           emxArray_real_T *workspace, const real_T f_data[],
                           const real_T x_data[])
{
  __m256d r;
  __m256d r1;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  real_T val;
  real_T valPrime;
  real_T *workspace_data;
  int32_T b_i;
  int32_T computeFval_ReuseHx_numThreads;
  int32_T i;
  int32_T maxRegVar;
  int32_T vectorUB;
  workspace_data = workspace->data;
  val = 0.0;
  switch (obj->objtype) {
  case 5:
    val = obj->gammaScalar * x_data[obj->nvar - 1];
    break;
  case 3:
    if (obj->hasLinear) {
      i = obj->nvar;
      maxRegVar = (i / 4) << 2;
      vectorUB = maxRegVar - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&obj->Hx.data[b_i]);
        _mm256_storeu_pd(&workspace_data[b_i],
                         _mm256_add_pd(_mm256_mul_pd(_mm256_set1_pd(0.5), r),
                                       _mm256_loadu_pd(&f_data[b_i])));
      }
      if (i - maxRegVar < 1200) {
        for (b_i = maxRegVar; b_i < i; b_i++) {
          workspace_data[b_i] = 0.5 * obj->Hx.data[b_i] + f_data[b_i];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        computeFval_ReuseHx_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(computeFval_ReuseHx_numThreads)

        for (b_i = maxRegVar; b_i < i; b_i++) {
          workspace_data[b_i] = 0.5 * obj->Hx.data[b_i] + f_data[b_i];
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
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
    break;
  case 4:
    maxRegVar = obj->maxVar;
    if (obj->hasLinear) {
      i = obj->nvar;
      for (maxRegVar = 0; maxRegVar < i; maxRegVar++) {
        workspace_data[maxRegVar] = f_data[maxRegVar];
      }
      i = obj->maxVar - obj->nvar;
      for (maxRegVar = 0; maxRegVar <= i - 2; maxRegVar++) {
        workspace_data[obj->nvar + maxRegVar] = obj->rho;
      }
      i = (uint16_T)(obj->maxVar - 1);
      maxRegVar = (i / 4) << 2;
      vectorUB = maxRegVar - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&obj->Hx.data[b_i]);
        r1 = _mm256_loadu_pd(&workspace_data[b_i]);
        _mm256_storeu_pd(
            &workspace_data[b_i],
            _mm256_add_pd(r1, _mm256_mul_pd(_mm256_set1_pd(0.5), r)));
      }
      if (i - maxRegVar < 1200) {
        for (b_i = maxRegVar; b_i < i; b_i++) {
          workspace_data[b_i] += 0.5 * obj->Hx.data[b_i];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        computeFval_ReuseHx_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(computeFval_ReuseHx_numThreads)

        for (b_i = maxRegVar; b_i < i; b_i++) {
          workspace_data[b_i] += 0.5 * obj->Hx.data[b_i];
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
    } else {
      if (obj->maxVar - 1 >= 1) {
        n_t = (ptrdiff_t)(obj->maxVar - 1);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, (real_T *)&x_data[0], &incx_t,
                   (real_T *)&obj->Hx.data[0], &incy_t);
      }
      val *= 0.5;
      i = obj->nvar + 1;
      if (maxRegVar - i < 1200) {
        for (b_i = i; b_i < maxRegVar; b_i++) {
          val += x_data[b_i - 1] * obj->rho;
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        computeFval_ReuseHx_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel num_threads(computeFval_ReuseHx_numThreads) private(      \
        valPrime)
        {
          valPrime = 0.0;
#pragma omp for nowait
          for (b_i = i; b_i < maxRegVar; b_i++) {
            valPrime += x_data[b_i - 1] * obj->rho;
          }
          omp_set_nest_lock(&mexFunctions_nestLockGlobal);
          {

            val += valPrime;
          }
          omp_unset_nest_lock(&mexFunctions_nestLockGlobal);
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
    }
    break;
  }
  return val;
}

/* End of code generation (computeFval_ReuseHx.c) */
