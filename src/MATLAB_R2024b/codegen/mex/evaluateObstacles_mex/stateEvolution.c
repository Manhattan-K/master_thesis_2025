/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stateEvolution.c
 *
 * Code generation for function 'stateEvolution'
 *
 */

/* Include files */
#include "stateEvolution.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "modelDynamics.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void stateEvolution(const real_T U[40], const real_T x0[3], real_T sys_n,
                    real_T sys_Ts, real_T N, emxArray_real_T *x_pred)
{
  emxArray_real_T *r;
  real_T *r1;
  real_T *x_pred_data;
  int32_T i;
  int32_T loop_ub_tmp;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emlrtMEXProfilingFunctionEntry((char_T *)stateEvolution_complete_name,
                                 isMexOutdated);
  /*  Given the initial state, the prediction horizon N and the input */
  /*  values, the function evaluate and create a stacked matrix of the next */
  /*  N states of the system */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  loop_ub_tmp = (int32_T)(sys_n * N);
  i = x_pred->size[0];
  x_pred->size[0] = loop_ub_tmp;
  emxEnsureCapacity_real_T(x_pred, i);
  x_pred_data = x_pred->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    x_pred_data[i] = 0.0;
  }
  emlrtMEXProfilingStatement(2, isMexOutdated);
  emxInit_real_T(&r, 1);
  modelDynamics(x0, &U[0], sys_n, sys_Ts, r);
  r1 = r->data;
  x_pred_data[0] = r1[0];
  x_pred_data[1] = r1[1];
  x_pred_data[2] = r1[2];
  emlrtMEXProfilingStatement(3, isMexOutdated);
  i = (int32_T)(N - 1.0);
  for (loop_ub_tmp = 0; loop_ub_tmp < i; loop_ub_tmp++) {
    real_T b_x_pred_data[3];
    real_T curr_i;
    emlrtMEXProfilingStatement(4, isMexOutdated);
    emlrtMEXProfilingStatement(5, isMexOutdated);
    curr_i = ((real_T)loop_ub_tmp + 1.0) * 3.0;
    emlrtMEXProfilingStatement(6, isMexOutdated);
    emlrtMEXProfilingStatement(7, isMexOutdated);
    emlrtMEXProfilingStatement(8, isMexOutdated);
    b_x_pred_data[0] =
        x_pred_data[(int32_T)((((real_T)loop_ub_tmp + 1.0) - 1.0) * 3.0 + 1.0) -
                    1];
    b_x_pred_data[1] =
        x_pred_data[(int32_T)((((real_T)loop_ub_tmp + 1.0) - 1.0) * 3.0 + 1.0)];
    b_x_pred_data[2] =
        x_pred_data[(int32_T)((((real_T)loop_ub_tmp + 1.0) - 1.0) * 3.0 + 1.0) +
                    1];
    modelDynamics(b_x_pred_data,
                  &U[(int32_T)(((real_T)loop_ub_tmp + 1.0) * 2.0 + 1.0) - 1],
                  sys_n, sys_Ts, r);
    r1 = r->data;
    x_pred_data[(int32_T)(curr_i + 1.0) - 1] = r1[0];
    x_pred_data[(int32_T)((curr_i + 1.0) + 1.0) - 1] = r1[1];
    x_pred_data[(int32_T)((curr_i + 1.0) + 2.0) - 1] = r1[2];
    emlrtMEXProfilingStatement(9, isMexOutdated);
  }
  emxFree_real_T(&r);
  emlrtMEXProfilingStatement(10, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (stateEvolution.c) */
