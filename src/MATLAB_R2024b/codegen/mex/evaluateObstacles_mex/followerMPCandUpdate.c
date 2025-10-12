/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * followerMPCandUpdate.c
 *
 * Code generation for function 'followerMPCandUpdate'
 *
 */

/* Include files */
#include "followerMPCandUpdate.h"
#include "constraints.h"
#include "eml_mtimes_helper.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "fmincon.h"
#include "followerCost.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "stateEvolution.h"
#include "sum.h"
#include "sumMatrixIncludeNaN.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
void followerMPCandUpdate(evaluateObstacles_mexStackData *SD,
                          const struct3_T *sys, const real_T x0[3],
                          const real_T X_L_stacked[60], real_T N,
                          const struct2_T *robotParams,
                          const struct5_T *obstacles, const real_T U_f_old[40],
                          emxArray_real_T *p_tp1, emxArray_real_T *X_F,
                          struct6_T *c_error, real_T u_t[2], real_T u_opt[40])
{
  emxArray_real_T *x_pred_stacked;
  real_T *X_F_data;
  real_T *x_pred_stacked_data;
  int32_T b_loop_ub_tmp;
  int32_T i;
  int32_T loop_ub_tmp;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emlrtMEXProfilingFunctionEntry((char_T *)c_followerMPCandUpdate_complete,
                                 isMexOutdated);
  /*  Variables definitions */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  /*  Get cost function */
  emlrtMEXProfilingStatement(2, isMexOutdated);
  /*  Get constraints function */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  /*  fmincon optimization */
  emlrtMEXProfilingStatement(5, isMexOutdated);
  memcpy(&u_opt[0], &U_f_old[0], 40U * sizeof(real_T));
  fmincon(SD, x0, sys->n, sys->Ts, N, X_L_stacked, robotParams, u_opt,
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
  emxInit_real_T(&x_pred_stacked, 1);
  stateEvolution(u_opt, x0, sys->n, sys->Ts, N, x_pred_stacked);
  x_pred_stacked_data = x_pred_stacked->data;
  emlrtMEXProfilingStatement(9, isMexOutdated);
  loop_ub_tmp = (int32_T)sys->n;
  i = X_F->size[0] * X_F->size[1];
  X_F->size[0] = (int32_T)sys->n;
  X_F->size[1] = (int32_T)N;
  emxEnsureCapacity_real_T(X_F, i);
  X_F_data = X_F->data;
  b_loop_ub_tmp = (int32_T)sys->n * (int32_T)N;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    X_F_data[i] = x_pred_stacked_data[i];
  }
  /*  Update the state and input with the first one predicted */
  emlrtMEXProfilingStatement(10, isMexOutdated);
  i = p_tp1->size[0];
  p_tp1->size[0] = (int32_T)sys->n;
  emxEnsureCapacity_real_T(p_tp1, i);
  X_F_data = p_tp1->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    X_F_data[i] = x_pred_stacked_data[i];
  }
  emxFree_real_T(&x_pred_stacked);
  emlrtMEXProfilingStatement(11, isMexOutdated);
  emlrtMEXProfilingStatement(12, isMexOutdated);
  u_t[0] = u_opt[0];
  u_t[1] = u_opt[1];
  /*  error = 0; */
  emlrtMEXProfilingStatement(13, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

real_T followerMPCandUpdate_anonFcn1(
    const real_T x0[3], real_T sys_n, real_T sys_Ts, real_T N,
    const real_T X_L_stacked[60], const real_T robotParams_Px[6],
    const real_T robotParams_d_FL_sq[20], real_T robotParams_C,
    const real_T robotParams_beta_N[20], const real_T U[40])
{
  __m256d r;
  emxArray_real_T c_X_L_stacked;
  emxArray_real_T *X_F_stacked;
  emxArray_real_T *b_x0;
  emxArray_real_T *projDiff;
  emxArray_real_T *y;
  real_T b_X_L_stacked[60];
  real_T a[20];
  real_T dv1[20];
  real_T dv[2];
  real_T varargout_1;
  real_T *X_F_stacked_data;
  real_T *projDiff_data;
  int32_T b_iv[2];
  int32_T b_iv1[2];
  int32_T col;
  int32_T i;
  int32_T loop_ub_tmp;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emlrtMEXProfilingFunctionEntry((char_T *)b_completeName, isMexOutdated);
  emlrtMEXProfilingFunctionEntry((char_T *)followerCost_complete_name,
                                 isMexOutdated);
  /*  FOLLOWER COST FUNCTION as  */
  /*    J = c*J_1 + J_2 */
  /*  J_1 checks the distance between the two robots */
  /*  q_L - q_F */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  emxInit_real_T(&X_F_stacked, 1);
  stateEvolution(U, x0, sys_n, sys_Ts, N, X_F_stacked);
  X_F_stacked_data = X_F_stacked->data;
  emlrtMEXProfilingStatement(2, isMexOutdated);
  emlrtMEXProfilingStatement(3, isMexOutdated);
  dv[0] = sys_n;
  dv[1] = N;
  /*  Px * stateDiff */
  emlrtMEXProfilingStatement(4, isMexOutdated);
  emxInit_real_T(&projDiff, 2);
  if (X_F_stacked->size[0] == 60) {
    for (i = 0; i <= 56; i += 4) {
      r = _mm256_loadu_pd(&X_F_stacked_data[i]);
      _mm256_storeu_pd(&b_X_L_stacked[i],
                       _mm256_sub_pd(_mm256_loadu_pd(&X_L_stacked[i]), r));
    }
    c_X_L_stacked.data = &b_X_L_stacked[0];
    b_iv[0] = (int32_T)sys_n;
    b_iv[1] = (int32_T)N;
    c_X_L_stacked.size = &b_iv[0];
    c_X_L_stacked.allocatedSize = 60;
    c_X_L_stacked.numDimensions = 2;
    c_X_L_stacked.canFreeData = false;
    b_mtimes(robotParams_Px, &c_X_L_stacked, projDiff);
  } else {
    binary_expand_op_3(projDiff, robotParams_Px, X_L_stacked, X_F_stacked, dv);
  }
  /*  Cost evaluation */
  /*  J_1 = sum((robotParams.beta_N) .* (sum(projDiff.^2, 1) -
   * robotParams.d_FL_sq) .^ 2); */
  emlrtMEXProfilingStatement(5, isMexOutdated);
  loop_ub_tmp = projDiff->size[1] << 1;
  i = projDiff->size[0] * projDiff->size[1];
  projDiff->size[0] = 2;
  emxEnsureCapacity_real_T(projDiff, i);
  projDiff_data = projDiff->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    varargout_1 = projDiff_data[i];
    projDiff_data[i] = varargout_1 * varargout_1;
  }
  emxInit_real_T(&y, 2);
  projDiff_data = y->data;
  if (projDiff->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub_tmp = projDiff->size[1];
    y->size[1] = projDiff->size[1];
    emxEnsureCapacity_real_T(y, i);
    projDiff_data = y->data;
    for (col = 0; col < loop_ub_tmp; col++) {
      projDiff_data[col] = sumColumnB(projDiff, col + 1);
    }
  }
  if (y->size[1] == 20) {
    for (i = 0; i <= 16; i += 4) {
      r = _mm256_loadu_pd(&projDiff_data[i]);
      _mm256_storeu_pd(
          &a[i], _mm256_sub_pd(r, _mm256_loadu_pd(&robotParams_d_FL_sq[i])));
    }
  } else {
    binary_expand_op_2(a, y, robotParams_d_FL_sq);
  }
  for (loop_ub_tmp = 0; loop_ub_tmp <= 16; loop_ub_tmp += 4) {
    r = _mm256_loadu_pd(&a[loop_ub_tmp]);
    _mm256_storeu_pd(&dv1[loop_ub_tmp], _mm256_mul_pd(r, r));
  }
  /*  J_2 accounts for the minimization of the travelled distance */
  /*  q_F(1:N) - q_F(0:N-1) */
  emlrtMEXProfilingStatement(6, isMexOutdated);
  varargout_1 = sys_n * (N - 1.0);
  if (varargout_1 < 1.0) {
    loop_ub_tmp = 3;
  } else {
    loop_ub_tmp = (int32_T)varargout_1 + 3;
  }
  emlrtMEXProfilingStatement(7, isMexOutdated);
  emlrtMEXProfilingStatement(8, isMexOutdated);
  /*  Px * distDiff */
  emlrtMEXProfilingStatement(9, isMexOutdated);
  if (X_F_stacked->size[0] == loop_ub_tmp) {
    int32_T vectorUB;
    emxInit_real_T(&b_x0, 1);
    i = b_x0->size[0];
    b_x0->size[0] = loop_ub_tmp;
    emxEnsureCapacity_real_T(b_x0, i);
    projDiff_data = b_x0->data;
    projDiff_data[0] = x0[0];
    projDiff_data[1] = x0[1];
    projDiff_data[2] = x0[2];
    for (i = 0; i <= loop_ub_tmp - 4; i++) {
      projDiff_data[i + 3] = X_F_stacked_data[i];
    }
    loop_ub_tmp = X_F_stacked->size[0];
    col = (X_F_stacked->size[0] / 4) << 2;
    vectorUB = col - 4;
    for (i = 0; i <= vectorUB; i += 4) {
      __m256d r1;
      r = _mm256_loadu_pd(&X_F_stacked_data[i]);
      r1 = _mm256_loadu_pd(&projDiff_data[i]);
      _mm256_storeu_pd(&X_F_stacked_data[i], _mm256_sub_pd(r, r1));
    }
    for (i = col; i < loop_ub_tmp; i++) {
      X_F_stacked_data[i] -= projDiff_data[i];
    }
    emxFree_real_T(&b_x0);
    c_X_L_stacked = *X_F_stacked;
    b_iv1[0] = (int32_T)sys_n;
    b_iv1[1] = (int32_T)N;
    c_X_L_stacked.size = &b_iv1[0];
    c_X_L_stacked.numDimensions = 2;
    b_mtimes(robotParams_Px, &c_X_L_stacked, projDiff);
  } else {
    binary_expand_op_1(projDiff, robotParams_Px, X_F_stacked, x0,
                       loop_ub_tmp - 4, dv);
  }
  emxFree_real_T(&X_F_stacked);
  /*  Cost evaluation */
  emlrtMEXProfilingStatement(10, isMexOutdated);
  loop_ub_tmp = projDiff->size[1] << 1;
  i = projDiff->size[0] * projDiff->size[1];
  projDiff->size[0] = 2;
  emxEnsureCapacity_real_T(projDiff, i);
  projDiff_data = projDiff->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    varargout_1 = projDiff_data[i];
    projDiff_data[i] = varargout_1 * varargout_1;
  }
  if (projDiff->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub_tmp = projDiff->size[1];
    y->size[1] = projDiff->size[1];
    emxEnsureCapacity_real_T(y, i);
    projDiff_data = y->data;
    for (col = 0; col < loop_ub_tmp; col++) {
      projDiff_data[col] = sumColumnB(projDiff, col + 1);
    }
  }
  emxFree_real_T(&projDiff);
  /*  Final cost */
  emlrtMEXProfilingStatement(11, isMexOutdated);
  varargout_1 = 0.0;
  for (i = 0; i < 20; i++) {
    varargout_1 += robotParams_beta_N[i] * dv1[i];
  }
  varargout_1 = robotParams_C * varargout_1 + sum(y);
  emxFree_real_T(&y);
  emlrtMEXProfilingStatement(12, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return varargout_1;
}

int32_T followerMPCandUpdate_anonFcn2(const real_T x0[3], real_T obstacles_M_f,
                                      const emxArray_real_T *obstacles_A_bar_f,
                                      const real_T obstacles_B_bar_f_data[],
                                      int32_T obstacles_B_bar_f_size, real_T N,
                                      real_T sys_n, real_T sys_Ts,
                                      const real_T U[40],
                                      real_T varargout_1_data[])
{
  emxArray_real_T *c_obst_av;
  real_T y_data[4200];
  real_T *c_obst_av_data;
  int32_T i;
  int32_T varargout_1_size;
  int32_T y_size;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emlrtMEXProfilingFunctionEntry((char_T *)completeName, isMexOutdated);
  emlrtMEXProfilingFunctionEntry((char_T *)constraints_complete_name,
                                 isMexOutdated);
  /*  Obtain the number of vertices */
  /*  Obtain the number of states n and number of inputs m */
  /*  Obstacle avoidance */
  /*  c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0 */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  emlrtMEXProfilingStatement(4, isMexOutdated);
  emxInit_real_T(&c_obst_av, 1);
  c_obst_av_data = c_obst_av->data;
  if (obstacles_M_f >= 1.0) {
    emlrtMEXProfilingStatement(5, isMexOutdated);
    stateEvolution(U, x0, sys_n, sys_Ts, N, c_obst_av);
    emlrtMEXProfilingStatement(6, isMexOutdated);
    y_size = mtimes(obstacles_A_bar_f, c_obst_av, y_data);
    if (y_size == obstacles_B_bar_f_size) {
      int32_T vectorUB;
      i = c_obst_av->size[0];
      c_obst_av->size[0] = y_size;
      emxEnsureCapacity_real_T(c_obst_av, i);
      c_obst_av_data = c_obst_av->data;
      varargout_1_size = (y_size / 4) << 2;
      vectorUB = varargout_1_size - 4;
      for (i = 0; i <= vectorUB; i += 4) {
        __m256d r;
        r = _mm256_loadu_pd(&y_data[i]);
        _mm256_storeu_pd(
            &c_obst_av_data[i],
            _mm256_sub_pd(r, _mm256_loadu_pd(&obstacles_B_bar_f_data[i])));
      }
      for (i = varargout_1_size; i < y_size; i++) {
        c_obst_av_data[i] = y_data[i] - obstacles_B_bar_f_data[i];
      }
    } else {
      binary_expand_op(c_obst_av, y_data, &y_size, obstacles_B_bar_f_data,
                       &obstacles_B_bar_f_size);
      c_obst_av_data = c_obst_av->data;
    }
    emlrtMEXProfilingStatement(9, isMexOutdated);
  } else {
    emlrtMEXProfilingStatement(7, isMexOutdated);
    /*  If there are no constraints */
    emlrtMEXProfilingStatement(8, isMexOutdated);
    c_obst_av->size[0] = 0;
    emlrtMEXProfilingStatement(9, isMexOutdated);
  }
  /*  Input constraints */
  /*  Defined in the fmincon function */
  /*  Final output */
  emlrtMEXProfilingStatement(10, isMexOutdated);
  y_size = c_obst_av->size[0];
  varargout_1_size = c_obst_av->size[0];
  for (i = 0; i < y_size; i++) {
    varargout_1_data[i] = c_obst_av_data[i];
  }
  emxFree_real_T(&c_obst_av);
  emlrtMEXProfilingStatement(12, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return varargout_1_size;
}

/* End of code generation (followerMPCandUpdate.c) */
