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
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void factor(n_struct_T *obj, const real_T A[1600], int32_T ndims, int32_T ldA)
{
  ptrdiff_t info_t;
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
  if ((int32_T)info_t < 0) {
    ix0 = obj->FMat->size[0];
    iy0 = obj->FMat->size[1];
    ix0 *= iy0;
    for (iy0 = 0; iy0 < ix0; iy0++) {
      obj->FMat->data[iy0] = rtNaN;
    }
  }
  obj->info = (int32_T)info_t;
}

/* End of code generation (factor.c) */
