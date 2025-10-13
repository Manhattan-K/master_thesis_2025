/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * revertSolution.c
 *
 * Code generation for function 'revertSolution'
 *
 */

/* Include files */
#include "revertSolution.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void revertSolution(emlrtCTX aTLS, h_struct_T *obj)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T *y;
  real_T *y_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T loop_ub;
  int32_T revertSolution_numThreads;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  obj->sqpFval = obj->sqpFval_old;
  memcpy(&obj->xstarsqp[0], &obj->xstarsqp_old[0], 40U * sizeof(real_T));
  emxInit_real_T(&y, 1);
  loop_ub = y->size[0];
  y->size[0] = obj->cIneq.size[0];
  emxEnsureCapacity_real_T(y, loop_ub);
  y_data = y->data;
  loop_ub = obj->cIneq.size[0];
  if (loop_ub < 1200) {
    for (i = 0; i < loop_ub; i++) {
      y_data[i] = obj->cIneq.data[i];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    revertSolution_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(revertSolution_numThreads)

    for (i = 0; i < loop_ub; i++) {
      y_data[i] = obj->cIneq.data[i];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  if (obj->mIneq >= 1) {
    n_t = (ptrdiff_t)obj->mIneq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &obj->cIneq_old.data[0], &incx_t, &y_data[0], &incy_t);
  }
  loop_ub = y->size[0];
  obj->cIneq.size[0] = y->size[0];
  b_loop_ub = y->size[0];
  if (y->size[0] < 1200) {
    for (i = 0; i < loop_ub; i++) {
      obj->cIneq.data[i] = y_data[i];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    revertSolution_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(revertSolution_numThreads)

    for (i = 0; i < b_loop_ub; i++) {
      obj->cIneq.data[i] = y_data[i];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

/* End of code generation (revertSolution.c) */
