/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * saveState.c
 *
 * Code generation for function 'saveState'
 *
 */

/* Include files */
#include "saveState.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "omp.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void saveState(emlrtCTX aTLS, h_struct_T *obj)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T *y;
  real_T *y_data;
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  int32_T saveState_numThreads;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  obj->sqpFval_old = obj->sqpFval;
  for (k = 0; k < 40; k++) {
    obj->xstarsqp_old[k] = obj->xstarsqp[k];
    obj->grad_old.data[k] = obj->grad.data[k];
  }
  emxInit_real_T(&y, 1);
  k = y->size[0];
  y->size[0] = obj->cIneq_old.size[0];
  emxEnsureCapacity_real_T(y, k);
  y_data = y->data;
  k = obj->cIneq_old.size[0];
  if (k < 1200) {
    for (i = 0; i < k; i++) {
      y_data[i] = obj->cIneq_old.data[i];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    saveState_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(saveState_numThreads)

    for (i = 0; i < k; i++) {
      y_data[i] = obj->cIneq_old.data[i];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  if (obj->mIneq >= 1) {
    n_t = (ptrdiff_t)obj->mIneq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &obj->cIneq.data[0], &incx_t, &y_data[0], &incy_t);
  }
  k = y->size[0];
  obj->cIneq_old.size[0] = y->size[0];
  loop_ub = y->size[0];
  if (y->size[0] < 1200) {
    for (i = 0; i < k; i++) {
      obj->cIneq_old.data[i] = y_data[i];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    saveState_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(saveState_numThreads)

    for (i = 0; i < loop_ub; i++) {
      obj->cIneq_old.data[i] = y_data[i];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

/* End of code generation (saveState.c) */
