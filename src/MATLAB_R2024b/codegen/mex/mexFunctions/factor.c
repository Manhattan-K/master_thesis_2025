/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factor.c
 *
 * Code generation for function 'factor'
 *
 */

/* Include files */
#include "factor.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void factor(emlrtCTX aTLS, m_struct_T *obj, const real_T A[1600], int32_T ndims,
            int32_T ldA)
{
  ptrdiff_t info_t;
  jmp_buf *volatile emlrtJBStack;
  int32_T factor_numThreads;
  int32_T i;
  int32_T idx;
  int32_T ix0;
  int32_T iy0;
  int32_T k;
  obj->ndims = ndims;
  for (idx = 0; idx < ndims; idx++) {
    ix0 = ldA * idx;
    iy0 = obj->ldm * idx;
    for (k = 0; k < ndims; k++) {
      obj->FMat->data[iy0 + k] = A[ix0 + k];
    }
  }
  info_t = LAPACKE_dpotrf_work(102, 'U', (ptrdiff_t)ndims, &obj->FMat->data[0],
                               (ptrdiff_t)obj->ldm);
  idx = (int32_T)info_t;
  if ((int32_T)info_t < 0) {
    ix0 = obj->FMat->size[0];
    iy0 = obj->FMat->size[1];
    ix0 *= iy0;
    if (ix0 < 1200) {
      for (i = 0; i < ix0; i++) {
        obj->FMat->data[i] = rtNaN;
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      factor_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(factor_numThreads)

      for (i = 0; i < ix0; i++) {
        obj->FMat->data[i] = rtNaN;
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  obj->info = idx;
}

/* End of code generation (factor.c) */
