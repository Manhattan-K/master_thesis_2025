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
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void revertSolution(j_struct_T *obj)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emxArray_real_T *y;
  real_T *y_data;
  int32_T i;
  int32_T loop_ub;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  obj->sqpFval = obj->sqpFval_old;
  memcpy(&obj->xstarsqp[0], &obj->xstarsqp_old[0], 40U * sizeof(real_T));
  emxInit_real_T(&y, 1);
  i = y->size[0];
  y->size[0] = obj->cIneq.size[0];
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  loop_ub = obj->cIneq.size[0];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = obj->cIneq.data[i];
  }
  if (obj->mIneq >= 1) {
    n_t = (ptrdiff_t)obj->mIneq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &obj->cIneq_old.data[0], &incx_t, &y_data[0], &incy_t);
  }
  loop_ub = y->size[0];
  obj->cIneq.size[0] = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    obj->cIneq.data[i] = y_data[i];
  }
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (revertSolution.c) */
