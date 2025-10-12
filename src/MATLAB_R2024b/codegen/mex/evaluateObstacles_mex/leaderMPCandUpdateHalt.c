/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * leaderMPCandUpdateHalt.c
 *
 * Code generation for function 'leaderMPCandUpdateHalt'
 *
 */

/* Include files */
#include "leaderMPCandUpdateHalt.h"
#include "eml_mtimes_helper.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "fmincon.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "stateEvolution.h"
#include "sum.h"
#include "sumMatrixIncludeNaN.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
void leaderMPCandUpdateHalt(evaluateObstacles_mexStackData *SD,
                            const struct3_T *sys, const real_T x0[3], real_T N,
                            const struct1_T *robotParams,
                            const struct5_T *obstacles,
                            const real_T U_l_old[40], emxArray_real_T *p_tp1,
                            emxArray_real_T *X_L, emxArray_real_T *X_L_stacked,
                            struct6_T *c_error, real_T u_t[2], real_T u_opt[40])
{
  real_T *X_L_data;
  real_T *X_L_stacked_data;
  int32_T b_loop_ub_tmp;
  int32_T i;
  int32_T loop_ub_tmp;
  emlrtMEXProfilingFunctionEntry((char_T *)c_leaderMPCandUpdateHalt_comple,
                                 isMexOutdated);
  /*  Variables definitions */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  /*  Get cost function */
  emlrtMEXProfilingStatement(2, isMexOutdated);
  /*  Get constraints function */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  /*  fmincon optimization */
  emlrtMEXProfilingStatement(5, isMexOutdated);
  memcpy(&u_opt[0], &U_l_old[0], 40U * sizeof(real_T));
  c_fmincon(SD, x0, sys->n, sys->m, sys->Ts, N, robotParams, u_opt,
            robotParams->lb.data, robotParams->lb.size, robotParams->ub.data,
            robotParams->ub.size, x0, obstacles, N, *sys, &c_error->QPexitflag,
            &c_error->QPoutput.iterations, &c_error->QPoutput.funcCount,
            c_error->QPoutput.algorithm, &c_error->QPoutput.constrviolation,
            &c_error->QPoutput.stepsize, &c_error->QPoutput.lssteplength,
            &c_error->QPoutput.firstorderopt);
  emlrtMEXProfilingStatement(6, isMexOutdated);
  emlrtMEXProfilingStatement(7, isMexOutdated);
  /*  States and output */
  emlrtMEXProfilingStatement(8, isMexOutdated);
  stateEvolution(u_opt, x0, sys->n, sys->Ts, N, X_L_stacked);
  X_L_stacked_data = X_L_stacked->data;
  emlrtMEXProfilingStatement(9, isMexOutdated);
  loop_ub_tmp = (int32_T)sys->n;
  i = X_L->size[0] * X_L->size[1];
  X_L->size[0] = (int32_T)sys->n;
  X_L->size[1] = (int32_T)N;
  emxEnsureCapacity_real_T(X_L, i);
  X_L_data = X_L->data;
  b_loop_ub_tmp = (int32_T)sys->n * (int32_T)N;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    X_L_data[i] = X_L_stacked_data[i];
  }
  /*  Update the state and input with the first one predicted */
  emlrtMEXProfilingStatement(10, isMexOutdated);
  i = p_tp1->size[0];
  p_tp1->size[0] = (int32_T)sys->n;
  emxEnsureCapacity_real_T(p_tp1, i);
  X_L_data = p_tp1->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    X_L_data[i] = X_L_stacked_data[i];
  }
  emlrtMEXProfilingStatement(11, isMexOutdated);
  emlrtMEXProfilingStatement(12, isMexOutdated);
  emlrtMEXProfilingStatement(13, isMexOutdated);
  u_t[0] = u_opt[0];
  u_t[1] = u_opt[1];
  emlrtMEXProfilingStatement(14, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
}

real_T leaderMPCandUpdateHalt_anonFcn1(const real_T x0[3], real_T sys_n,
                                       real_T sys_Ts, real_T N,
                                       const real_T robotParams_Px[6],
                                       const real_T U[40])
{
  emxArray_real_T b_X_L_stacked;
  emxArray_real_T *X_L_stacked;
  emxArray_real_T *b_x0;
  emxArray_real_T *projDiff;
  emxArray_real_T *y;
  real_T sz[2];
  real_T varargout_1;
  real_T *X_L_stacked_data;
  real_T *x0_data;
  int32_T b_sz[2];
  int32_T i;
  int32_T loop_ub;
  int32_T scalarLB;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emlrtMEXProfilingFunctionEntry((char_T *)f_completeName, isMexOutdated);
  emlrtMEXProfilingFunctionEntry((char_T *)leaderCostHalt_complete_name,
                                 isMexOutdated);
  /*  The cost accounts for the minimization of the travelled distance */
  /*  q_F(1:N) - q_F(0:N-1) */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  emxInit_real_T(&X_L_stacked, 1);
  stateEvolution(U, x0, sys_n, sys_Ts, N, X_L_stacked);
  X_L_stacked_data = X_L_stacked->data;
  emlrtMEXProfilingStatement(2, isMexOutdated);
  varargout_1 = sys_n * (N - 1.0);
  if (varargout_1 < 1.0) {
    loop_ub = 3;
  } else {
    loop_ub = (int32_T)varargout_1 + 3;
  }
  emlrtMEXProfilingStatement(3, isMexOutdated);
  emlrtMEXProfilingStatement(4, isMexOutdated);
  sz[0] = sys_n;
  sz[1] = N;
  /*  Px * distDiff */
  emlrtMEXProfilingStatement(5, isMexOutdated);
  emxInit_real_T(&projDiff, 2);
  if (X_L_stacked->size[0] == loop_ub) {
    int32_T vectorUB;
    emxInit_real_T(&b_x0, 1);
    i = b_x0->size[0];
    b_x0->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_x0, i);
    x0_data = b_x0->data;
    x0_data[0] = x0[0];
    x0_data[1] = x0[1];
    x0_data[2] = x0[2];
    for (i = 0; i <= loop_ub - 4; i++) {
      x0_data[i + 3] = X_L_stacked_data[i];
    }
    loop_ub = X_L_stacked->size[0];
    scalarLB = (X_L_stacked->size[0] / 4) << 2;
    vectorUB = scalarLB - 4;
    for (i = 0; i <= vectorUB; i += 4) {
      __m256d r;
      __m256d r1;
      r = _mm256_loadu_pd(&X_L_stacked_data[i]);
      r1 = _mm256_loadu_pd(&x0_data[i]);
      _mm256_storeu_pd(&X_L_stacked_data[i], _mm256_sub_pd(r, r1));
    }
    for (i = scalarLB; i < loop_ub; i++) {
      X_L_stacked_data[i] -= x0_data[i];
    }
    emxFree_real_T(&b_x0);
    b_X_L_stacked = *X_L_stacked;
    b_sz[0] = (int32_T)sys_n;
    b_sz[1] = (int32_T)N;
    b_X_L_stacked.size = &b_sz[0];
    b_X_L_stacked.numDimensions = 2;
    b_mtimes(robotParams_Px, &b_X_L_stacked, projDiff);
  } else {
    binary_expand_op_1(projDiff, robotParams_Px, X_L_stacked, x0, loop_ub - 4,
                       sz);
  }
  emxFree_real_T(&X_L_stacked);
  /*  Cost evaluation */
  emlrtMEXProfilingStatement(6, isMexOutdated);
  loop_ub = projDiff->size[1] << 1;
  i = projDiff->size[0] * projDiff->size[1];
  projDiff->size[0] = 2;
  emxEnsureCapacity_real_T(projDiff, i);
  X_L_stacked_data = projDiff->data;
  for (i = 0; i < loop_ub; i++) {
    varargout_1 = X_L_stacked_data[i];
    X_L_stacked_data[i] = varargout_1 * varargout_1;
  }
  emxInit_real_T(&y, 2);
  if (projDiff->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = projDiff->size[1];
    y->size[1] = projDiff->size[1];
    emxEnsureCapacity_real_T(y, i);
    X_L_stacked_data = y->data;
    for (scalarLB = 0; scalarLB < loop_ub; scalarLB++) {
      X_L_stacked_data[scalarLB] = sumColumnB(projDiff, scalarLB + 1);
    }
  }
  emxFree_real_T(&projDiff);
  varargout_1 = sum(y);
  emxFree_real_T(&y);
  emlrtMEXProfilingStatement(7, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return varargout_1;
}

/* End of code generation (leaderMPCandUpdateHalt.c) */
