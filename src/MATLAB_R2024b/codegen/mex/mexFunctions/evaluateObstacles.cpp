//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// evaluateObstacles.cpp
//
// Code generation for function 'evaluateObstacles'
//

// Include files
#include "evaluateObstacles.h"
#include "getObstacleInfo.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "mexFunctions_types2.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
void evaluateObstacles(const struct0_T obstacles_data[],
                       const int32_T obstacles_size[2], const real_T x_l[2],
                       const real_T x_f[2], const struct1_T *leaderParams,
                       const struct2_T *followerParams, const struct3_T *sys,
                       real_T N, struct4_T *obstaclesInRange)
{
  coder::array<real_T, 2U> A_constr;
  coder::array<real_T, 2U> b_I;
  coder::array<real_T, 2U> qi_f;
  coder::array<real_T, 2U> qi_l;
  coder::array<real_T, 1U> b_constr;
  real_T selector_data[576];
  real_T absxk;
  real_T predictionDist;
  real_T scale;
  real_T t;
  real_T t_tmp;
  real_T y;
  int32_T kidx;
  int32_T loop_ub_tmp;
  int32_T m_tmp;
  int32_T ma;
  int32_T mb;
  int32_T na;
  int32_T nb;
  uint32_T obsNum;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  //  Select the obstacles closer to the leader
  predictionDist = N * leaderParams->v_max / 7.5;
  kidx = obstacles_size[1];
  loop_ub_tmp = obstacles_size[1] * obstacles_size[1];
  if (loop_ub_tmp - 1 >= 0) {
    std::memset(&selector_data[0], 0,
                static_cast<uint32_T>(loop_ub_tmp) * sizeof(real_T));
  }
  obsNum = 0U;
  for (mb = 0; mb < kidx; mb++) {
    scale = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(x_l[0] - obstacles_data[mb].center[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = muDoubleScalarAbs(x_l[1] - obstacles_data[mb].center[1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * muDoubleScalarSqrt(y);
    if (predictionDist >= y - obstacles_data[mb].radius) {
      selector_data[mb] = 1.0;
      obsNum++;
    }
  }
  //  Get the qi points for leader and follower
  //  Get q points of leader from obstacles
  getObstacleInfo(obstacles_data, obstacles_size, selector_data,
                  static_cast<real_T>(obsNum), x_l, qi_l, A_constr);
  //  Get q points of follower from obstacles
  getObstacleInfo(obstacles_data, obstacles_size, selector_data,
                  static_cast<real_T>(obsNum), x_f, qi_f, A_constr);
  //  Create A_bar and B_bar matrices
  //  Obtain the number of constraints
  obstaclesInRange->M_l = qi_l.size(1);
  obstaclesInRange->M_f = qi_f.size(1);
  //  A_bar and B_bar for leader
  //  Obtain the number of constraints
  //  Obtain the number of vertices
  //  Obtain the number of states n and number of inputs m
  //  The constraints are linear as (qi-x0)' x(t) <= (qi-x0)'qi.
  predictionDist = static_cast<real_T>(qi_l.size(1)) * 21.0;
  loop_ub_tmp = static_cast<int32_T>(predictionDist);
  A_constr.set_size(loop_ub_tmp, static_cast<int32_T>(sys->n));
  ma = static_cast<int32_T>(predictionDist) * static_cast<int32_T>(sys->n);
  for (kidx = 0; kidx < ma; kidx++) {
    A_constr[kidx] = 0.0;
  }
  b_constr.set_size(loop_ub_tmp);
  for (kidx = 0; kidx < loop_ub_tmp; kidx++) {
    b_constr[kidx] = 0.0;
  }
  kidx = qi_l.size(1);
  for (mb = 0; mb < kidx; mb++) {
    predictionDist = x_l[0];
    scale = x_l[1];
    for (nb = 0; nb < 21; nb++) {
      ma = mb * 21 + nb;
      A_constr[ma + A_constr.size(0) * 2] = 0.0;
      absxk = qi_l[2 * mb];
      t = absxk - predictionDist;
      A_constr[ma] = t;
      na = nb << 1;
      y = t * (absxk - leaderParams->robotShape[na]);
      absxk = qi_l[2 * mb + 1];
      t = absxk - scale;
      A_constr[ma + A_constr.size(0)] = t;
      y += t * (absxk - leaderParams->robotShape[na + 1]);
      b_constr[ma] = y;
    }
  }
  //  Stack diagonally to expand and make it a bound for all ts
  if (N < 0.0) {
    t_tmp = 0.0;
  } else {
    t_tmp = N;
  }
  m_tmp = static_cast<int32_T>(t_tmp);
  b_I.set_size(static_cast<int32_T>(t_tmp), static_cast<int32_T>(t_tmp));
  loop_ub_tmp = static_cast<int32_T>(t_tmp) * static_cast<int32_T>(t_tmp);
  for (kidx = 0; kidx < loop_ub_tmp; kidx++) {
    b_I[kidx] = 0.0;
  }
  if (static_cast<int32_T>(t_tmp) > 0) {
    for (ma = 0; ma < m_tmp; ma++) {
      b_I[ma + b_I.size(0) * ma] = 1.0;
    }
  }
  ma = b_I.size(0);
  na = b_I.size(1);
  mb = A_constr.size(0);
  nb = A_constr.size(1);
  obstaclesInRange->A_bar_l.set_size(b_I.size(0) * A_constr.size(0),
                                     b_I.size(1) * A_constr.size(1));
  kidx = -1;
  for (int32_T b_j1{0}; b_j1 < na; b_j1++) {
    for (int32_T j2{0}; j2 < nb; j2++) {
      for (int32_T i1{0}; i1 < ma; i1++) {
        for (int32_T i2{0}; i2 < mb; i2++) {
          obstaclesInRange->A_bar_l[(kidx + i2) + 1] =
              b_I[i1 + b_I.size(0) * b_j1] *
              A_constr[i2 + A_constr.size(0) * j2];
        }
        if (mb - 1 >= 0) {
          kidx += mb;
        }
      }
    }
  }
  coder::repmat(b_constr, N, obstaclesInRange->B_bar_l);
  //  A_bar and B_bar for follower
  //  Obtain the number of constraints
  //  Obtain the number of vertices
  //  Obtain the number of states n and number of inputs m
  //  The constraints are linear as (qi-x0)' x(t) <= (qi-x0)'qi.
  predictionDist = static_cast<real_T>(qi_f.size(1)) * 4.0;
  ma = static_cast<int32_T>(predictionDist);
  A_constr.set_size(ma, static_cast<int32_T>(sys->n));
  na = static_cast<int32_T>(predictionDist) * static_cast<int32_T>(sys->n);
  for (kidx = 0; kidx < na; kidx++) {
    A_constr[kidx] = 0.0;
  }
  b_constr.set_size(ma);
  for (kidx = 0; kidx < ma; kidx++) {
    b_constr[kidx] = 0.0;
  }
  kidx = qi_f.size(1);
  for (mb = 0; mb < kidx; mb++) {
    predictionDist = x_f[0];
    scale = x_f[1];
    for (nb = 0; nb < 4; nb++) {
      ma = (mb << 2) + nb;
      A_constr[ma + A_constr.size(0) * 2] = 0.0;
      absxk = qi_f[2 * mb];
      t = absxk - predictionDist;
      A_constr[ma] = t;
      na = nb << 1;
      y = t * (absxk - followerParams->robotShape[na]);
      absxk = qi_f[2 * mb + 1];
      t = absxk - scale;
      A_constr[ma + A_constr.size(0)] = t;
      y += t * (absxk - followerParams->robotShape[na + 1]);
      b_constr[ma] = y;
    }
  }
  //  Stack diagonally to expand and make it a bound for all ts
  b_I.set_size(static_cast<int32_T>(t_tmp), static_cast<int32_T>(t_tmp));
  for (kidx = 0; kidx < loop_ub_tmp; kidx++) {
    b_I[kidx] = 0.0;
  }
  if (static_cast<int32_T>(t_tmp) > 0) {
    for (ma = 0; ma < m_tmp; ma++) {
      b_I[ma + b_I.size(0) * ma] = 1.0;
    }
  }
  ma = b_I.size(0);
  na = b_I.size(1);
  mb = A_constr.size(0);
  nb = A_constr.size(1);
  obstaclesInRange->A_bar_f.set_size(b_I.size(0) * A_constr.size(0),
                                     b_I.size(1) * A_constr.size(1));
  kidx = -1;
  for (int32_T b_j1{0}; b_j1 < na; b_j1++) {
    for (int32_T j2{0}; j2 < nb; j2++) {
      for (int32_T i1{0}; i1 < ma; i1++) {
        for (int32_T i2{0}; i2 < mb; i2++) {
          obstaclesInRange->A_bar_f[(kidx + i2) + 1] =
              b_I[i1 + b_I.size(0) * b_j1] *
              A_constr[i2 + A_constr.size(0) * j2];
        }
        if (mb - 1 >= 0) {
          kidx += mb;
        }
      }
    }
  }
  coder::repmat(b_constr, N, obstaclesInRange->B_bar_f);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

// End of code generation (evaluateObstacles.cpp)
