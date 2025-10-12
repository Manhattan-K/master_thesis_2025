/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * saveJacobian.c
 *
 * Code generation for function 'saveJacobian'
 *
 */

/* Include files */
#include "saveJacobian.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void saveJacobian(j_struct_T *obj, int32_T nVar, int32_T mIneq,
                  const emxArray_real_T *JacCineqTrans, int32_T ineqCol0,
                  int32_T ldJ)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emxArray_real_T *y;
  const real_T *JacCineqTrans_data;
  real_T *y_data;
  int32_T i;
  int32_T i1;
  int32_T iCol;
  int32_T idx_col;
  JacCineqTrans_data = JacCineqTrans->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  iCol = ldJ * (ineqCol0 - 1);
  i = mIneq - ineqCol0;
  emxInit_real_T(&y, 2);
  for (idx_col = 0; idx_col <= i; idx_col++) {
    int32_T i2;
    int32_T loop_ub_tmp;
    i1 = obj->JacCineqTrans_old->size[0];
    loop_ub_tmp = y->size[0] * y->size[1];
    y->size[0] = i1;
    i2 = obj->JacCineqTrans_old->size[1];
    y->size[1] = i2;
    emxEnsureCapacity_real_T(y, loop_ub_tmp);
    y_data = y->data;
    loop_ub_tmp = i1 * i2;
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      y_data[i1] = obj->JacCineqTrans_old->data[i1];
    }
    n_t = (ptrdiff_t)nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    i1 = idx_col * ldJ;
    dcopy(&n_t, (real_T *)&JacCineqTrans_data[iCol + i1], &incx_t, &y_data[i1],
          &incy_t);
    i1 = obj->JacCineqTrans_old->size[0] * obj->JacCineqTrans_old->size[1];
    obj->JacCineqTrans_old->size[0] = y->size[0];
    obj->JacCineqTrans_old->size[1] = y->size[1];
    emxEnsureCapacity_real_T(obj->JacCineqTrans_old, i1);
    loop_ub_tmp = y->size[0] * y->size[1];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      obj->JacCineqTrans_old->data[i1] = y_data[i1];
    }
  }
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (saveJacobian.c) */
