/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * evaluateObstacles.c
 *
 * Code generation for function 'evaluateObstacles'
 *
 */

/* Include files */
#include "evaluateObstacles.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "getObstacleInfo.h"
#include "kron.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void evaluateObstacles(const struct0_T obstacles_data[],
                       const int32_T obstacles_size[2], const real_T x_l[2],
                       const real_T x_f[2], const struct1_T *leaderParams,
                       const struct2_T *followerParams, const struct3_T *sys,
                       real_T N, struct4_T *obstaclesInRange)
{
  emxArray_real_T *A_constr;
  emxArray_real_T *b_I;
  emxArray_real_T *b_constr;
  emxArray_real_T *qi_f;
  emxArray_real_T *qi_l;
  real_T selector_data[576];
  real_T absxk;
  real_T predictionDist;
  real_T scale;
  real_T t;
  real_T y;
  real_T *A_constr_data;
  real_T *b_constr_data;
  real_T *qi_f_data;
  real_T *qi_l_data;
  int32_T b_i;
  int32_T b_loop_ub_tmp;
  int32_T c_loop_ub_tmp;
  int32_T i;
  int32_T j;
  int32_T loop_ub_tmp;
  int32_T m_tmp;
  int32_T x_tmp;
  uint32_T obsNum;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emlrtMEXProfilingFunctionEntry((char_T *)evaluateObstacles_complete_name,
                                 isMexOutdated);
  /*  Select the obstacles closer to the leader  */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  predictionDist = N * leaderParams->v_max / 7.5;
  emlrtMEXProfilingStatement(2, isMexOutdated);
  i = obstacles_size[1];
  loop_ub_tmp = obstacles_size[1] * obstacles_size[1];
  if (loop_ub_tmp - 1 >= 0) {
    memset(&selector_data[0], 0, (uint32_T)loop_ub_tmp * sizeof(real_T));
  }
  emlrtMEXProfilingStatement(3, isMexOutdated);
  obsNum = 0U;
  emlrtMEXProfilingStatement(4, isMexOutdated);
  for (b_i = 0; b_i < i; b_i++) {
    emlrtMEXProfilingStatement(5, isMexOutdated);
    emlrtMEXProfilingStatement(6, isMexOutdated);
    scale = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(x_l[0] - obstacles_data[b_i].center[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = muDoubleScalarAbs(x_l[1] - obstacles_data[b_i].center[1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * muDoubleScalarSqrt(y);
    if (predictionDist >= y - obstacles_data[b_i].radius) {
      emlrtMEXProfilingStatement(7, isMexOutdated);
      selector_data[b_i] = 1.0;
      emlrtMEXProfilingStatement(8, isMexOutdated);
      obsNum++;
      emlrtMEXProfilingStatement(9, isMexOutdated);
    }
    emlrtMEXProfilingStatement(10, isMexOutdated);
  }
  /*  Get the qi points for leader and follower */
  /*  Get q points of leader from obstacles */
  emlrtMEXProfilingStatement(11, isMexOutdated);
  emxInit_real_T(&qi_l, 2);
  emxInit_real_T(&A_constr, 2);
  getObstacleInfo(obstacles_data, obstacles_size, selector_data, obsNum, x_l,
                  qi_l, A_constr);
  qi_l_data = qi_l->data;
  /*  Get q points of follower from obstacles */
  emlrtMEXProfilingStatement(12, isMexOutdated);
  emxInit_real_T(&qi_f, 2);
  getObstacleInfo(obstacles_data, obstacles_size, selector_data, obsNum, x_f,
                  qi_f, A_constr);
  qi_f_data = qi_f->data;
  /*  Create A_bar and B_bar matrices */
  /*  Obtain the number of constraints */
  emlrtMEXProfilingStatement(13, isMexOutdated);
  obstaclesInRange->M_l = qi_l->size[1];
  emlrtMEXProfilingStatement(14, isMexOutdated);
  obstaclesInRange->M_f = qi_f->size[1];
  /*  A_bar and B_bar for leader */
  emlrtMEXProfilingStatement(15, isMexOutdated);
  emlrtMEXProfilingFunctionEntry((char_T *)constMatrices_complete_name,
                                 isMexOutdated);
  /*  Obtain the number of constraints */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  /*  Obtain the number of vertices */
  /*  Obtain the number of states n and number of inputs m */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  /*  The constraints are linear as (qi-x0)' x(t) <= (qi-x0)'qi. */
  emlrtMEXProfilingStatement(4, isMexOutdated);
  predictionDist = (real_T)qi_l->size[1] * 21.0;
  loop_ub_tmp = (int32_T)predictionDist;
  i = A_constr->size[0] * A_constr->size[1];
  A_constr->size[0] = (int32_T)predictionDist;
  A_constr->size[1] = (int32_T)sys->n;
  emxEnsureCapacity_real_T(A_constr, i);
  A_constr_data = A_constr->data;
  b_loop_ub_tmp = (int32_T)predictionDist * (int32_T)sys->n;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    A_constr_data[i] = 0.0;
  }
  emlrtMEXProfilingStatement(5, isMexOutdated);
  emxInit_real_T(&b_constr, 1);
  i = b_constr->size[0];
  b_constr->size[0] = (int32_T)predictionDist;
  emxEnsureCapacity_real_T(b_constr, i);
  b_constr_data = b_constr->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    b_constr_data[i] = 0.0;
  }
  emlrtMEXProfilingStatement(6, isMexOutdated);
  emlrtMEXProfilingStatement(7, isMexOutdated);
  i = qi_l->size[1];
  for (b_i = 0; b_i < i; b_i++) {
    emlrtMEXProfilingStatement(8, isMexOutdated);
    emlrtMEXProfilingStatement(9, isMexOutdated);
    predictionDist = x_l[0];
    scale = x_l[1];
    b_loop_ub_tmp = 2 * b_i + 1;
    for (j = 0; j < 21; j++) {
      emlrtMEXProfilingStatement(10, isMexOutdated);
      emlrtMEXProfilingStatement(11, isMexOutdated);
      c_loop_ub_tmp = b_i * 21 + j;
      absxk = qi_l_data[2 * b_i] - predictionDist;
      t = absxk;
      A_constr_data[c_loop_ub_tmp] = absxk;
      absxk = qi_l_data[b_loop_ub_tmp] - scale;
      A_constr_data[c_loop_ub_tmp + A_constr->size[0]] = absxk;
      A_constr_data[c_loop_ub_tmp + A_constr->size[0] * 2] = 0.0;
      emlrtMEXProfilingStatement(12, isMexOutdated);
      x_tmp = j << 1;
      b_constr_data[c_loop_ub_tmp] =
          t * (qi_l_data[2 * b_i] - leaderParams->robotShape[x_tmp]) +
          absxk *
              (qi_l_data[b_loop_ub_tmp] - leaderParams->robotShape[x_tmp + 1]);
      emlrtMEXProfilingStatement(13, isMexOutdated);
    }
    emlrtMEXProfilingStatement(14, isMexOutdated);
  }
  emxFree_real_T(&qi_l);
  /*  Stack diagonally to expand and make it a bound for all ts */
  emlrtMEXProfilingStatement(15, isMexOutdated);
  emxInit_real_T(&b_I, 2);
  if (N < 0.0) {
    y = 0.0;
  } else {
    y = N;
  }
  m_tmp = (int32_T)y;
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = (int32_T)y;
  b_I->size[1] = (int32_T)y;
  emxEnsureCapacity_real_T(b_I, i);
  qi_l_data = b_I->data;
  loop_ub_tmp = (int32_T)y * (int32_T)y;
  for (i = 0; i < loop_ub_tmp; i++) {
    qi_l_data[i] = 0.0;
  }
  if ((int32_T)y > 0) {
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < m_tmp; b_loop_ub_tmp++) {
      qi_l_data[b_loop_ub_tmp + b_I->size[0] * b_loop_ub_tmp] = 1.0;
    }
  }
  kron(b_I, A_constr, obstaclesInRange->A_bar_l);
  emlrtMEXProfilingStatement(16, isMexOutdated);
  repmat(b_constr, N, obstaclesInRange->B_bar_l);
  emlrtMEXProfilingStatement(17, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  /*  A_bar and B_bar for follower */
  emlrtMEXProfilingStatement(16, isMexOutdated);
  emlrtMEXProfilingFunctionEntry((char_T *)constMatrices_complete_name,
                                 isMexOutdated);
  /*  Obtain the number of constraints */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  /*  Obtain the number of vertices */
  /*  Obtain the number of states n and number of inputs m */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  /*  The constraints are linear as (qi-x0)' x(t) <= (qi-x0)'qi. */
  emlrtMEXProfilingStatement(4, isMexOutdated);
  predictionDist = (real_T)qi_f->size[1] * 4.0;
  b_loop_ub_tmp = (int32_T)predictionDist;
  i = A_constr->size[0] * A_constr->size[1];
  A_constr->size[0] = (int32_T)predictionDist;
  A_constr->size[1] = (int32_T)sys->n;
  emxEnsureCapacity_real_T(A_constr, i);
  A_constr_data = A_constr->data;
  c_loop_ub_tmp = (int32_T)predictionDist * (int32_T)sys->n;
  for (i = 0; i < c_loop_ub_tmp; i++) {
    A_constr_data[i] = 0.0;
  }
  emlrtMEXProfilingStatement(5, isMexOutdated);
  i = b_constr->size[0];
  b_constr->size[0] = (int32_T)predictionDist;
  emxEnsureCapacity_real_T(b_constr, i);
  b_constr_data = b_constr->data;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    b_constr_data[i] = 0.0;
  }
  emlrtMEXProfilingStatement(6, isMexOutdated);
  emlrtMEXProfilingStatement(7, isMexOutdated);
  i = qi_f->size[1];
  for (b_i = 0; b_i < i; b_i++) {
    emlrtMEXProfilingStatement(8, isMexOutdated);
    emlrtMEXProfilingStatement(9, isMexOutdated);
    predictionDist = x_f[0];
    scale = x_f[1];
    b_loop_ub_tmp = 2 * b_i + 1;
    for (j = 0; j < 4; j++) {
      emlrtMEXProfilingStatement(10, isMexOutdated);
      emlrtMEXProfilingStatement(11, isMexOutdated);
      c_loop_ub_tmp = (b_i << 2) + j;
      absxk = qi_f_data[2 * b_i] - predictionDist;
      t = absxk;
      A_constr_data[c_loop_ub_tmp] = absxk;
      absxk = qi_f_data[b_loop_ub_tmp] - scale;
      A_constr_data[c_loop_ub_tmp + A_constr->size[0]] = absxk;
      A_constr_data[c_loop_ub_tmp + A_constr->size[0] * 2] = 0.0;
      emlrtMEXProfilingStatement(12, isMexOutdated);
      x_tmp = j << 1;
      b_constr_data[c_loop_ub_tmp] =
          t * (qi_f_data[2 * b_i] - followerParams->robotShape[x_tmp]) +
          absxk * (qi_f_data[b_loop_ub_tmp] -
                   followerParams->robotShape[x_tmp + 1]);
      emlrtMEXProfilingStatement(13, isMexOutdated);
    }
    emlrtMEXProfilingStatement(14, isMexOutdated);
  }
  emxFree_real_T(&qi_f);
  /*  Stack diagonally to expand and make it a bound for all ts */
  emlrtMEXProfilingStatement(15, isMexOutdated);
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = (int32_T)y;
  b_I->size[1] = (int32_T)y;
  emxEnsureCapacity_real_T(b_I, i);
  qi_l_data = b_I->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    qi_l_data[i] = 0.0;
  }
  if ((int32_T)y > 0) {
    for (b_loop_ub_tmp = 0; b_loop_ub_tmp < m_tmp; b_loop_ub_tmp++) {
      qi_l_data[b_loop_ub_tmp + b_I->size[0] * b_loop_ub_tmp] = 1.0;
    }
  }
  kron(b_I, A_constr, obstaclesInRange->A_bar_f);
  emxFree_real_T(&b_I);
  emxFree_real_T(&A_constr);
  emlrtMEXProfilingStatement(16, isMexOutdated);
  repmat(b_constr, N, obstaclesInRange->B_bar_f);
  emxFree_real_T(&b_constr);
  emlrtMEXProfilingStatement(17, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtMEXProfilingStatement(17, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (evaluateObstacles.c) */
