//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// followerMPCandUpdate.cpp
//
// Code generation for function 'followerMPCandUpdate'
//

// Include files
#include "followerMPCandUpdate.h"
#include "anonymous_function.h"
#include "constraints.h"
#include "eml_mtimes_helper.h"
#include "fmincon.h"
#include "followerCost.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "mexFunctions_types1.h"
#include "mexFunctions_types2.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "stateEvolution.h"
#include "sum.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"
#include <algorithm>
#include <cstring>

// Function Definitions
void followerMPCandUpdate(mexFunctionsStackData *SD, const struct3_T *sys,
                          const real_T x0[3], const real_T X_L_stacked[60],
                          real_T N, const struct2_T *robotParams,
                          const struct5_T *obstacles, const real_T U_f_old[40],
                          coder::array<real_T, 1U> &p_tp1,
                          coder::array<real_T, 2U> &X_F, struct6_T *c_error,
                          real_T u_t[2], real_T u_opt[40])
{
  coder::anonymous_function costF;
  coder::array<real_T, 1U> x_pred_stacked;
  int32_T b_loop_ub_tmp;
  int32_T loop_ub_tmp;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  //  Variables definitions
  //  Get cost function
  costF.workspace.N = N;
  costF.workspace.x0[0] = x0[0];
  costF.workspace.x0[1] = x0[1];
  costF.workspace.x0[2] = x0[2];
  costF.workspace.sys = *sys;
  std::copy(&X_L_stacked[0], &X_L_stacked[60], &costF.workspace.X_L_stacked[0]);
  costF.workspace.robotParams = *robotParams;
  //  Get constraints function
  SD->f4.constraintsF.workspace.N = N;
  SD->f4.constraintsF.workspace.x0[0] = x0[0];
  SD->f4.constraintsF.workspace.x0[1] = x0[1];
  SD->f4.constraintsF.workspace.x0[2] = x0[2];
  SD->f4.constraintsF.workspace.obstacles = *obstacles;
  SD->f4.constraintsF.workspace.robotParams = *robotParams;
  SD->f4.constraintsF.workspace.sys = *sys;
  //  fmincon optimization
  std::copy(&U_f_old[0], &U_f_old[40], &u_opt[0]);
  coder::d_fmincon(
      SD, costF, u_opt, robotParams->lb, robotParams->ub, SD->f4.constraintsF,
      c_error->QPexitflag, c_error->QPoutput.iterations,
      c_error->QPoutput.funcCount, c_error->QPoutput.algorithm,
      c_error->QPoutput.constrviolation, c_error->QPoutput.stepsize,
      c_error->QPoutput.lssteplength, c_error->QPoutput.firstorderopt);
  //  States and output
  stateEvolution(u_opt, x0, sys->n, sys->Ts, N, x_pred_stacked);
  loop_ub_tmp = static_cast<int32_T>(sys->n);
  X_F.set_size(loop_ub_tmp, static_cast<int32_T>(N));
  b_loop_ub_tmp = static_cast<int32_T>(sys->n) * static_cast<int32_T>(N);
  for (int32_T i{0}; i < b_loop_ub_tmp; i++) {
    X_F[i] = x_pred_stacked[i];
  }
  //  Update the state and input with the first one predicted
  p_tp1.set_size(loop_ub_tmp);
  for (int32_T i{0}; i < loop_ub_tmp; i++) {
    p_tp1[i] = x_pred_stacked[i];
  }
  u_t[0] = u_opt[0];
  u_t[1] = u_opt[1];
  //  error = 0;
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

real_T followerMPCandUpdate_anonFcn1(
    const real_T x0[3], real_T sys_n, real_T sys_Ts, real_T N,
    const real_T X_L_stacked[60], const real_T robotParams_Px[6],
    const real_T robotParams_d_FL_sq[20], real_T robotParams_C,
    const real_T robotParams_beta_N[20], const real_T U[40])
{
  coder::array<real_T, 2U> b_X_F_stacked;
  coder::array<real_T, 2U> c_X_L_stacked;
  coder::array<real_T, 2U> projDiff;
  coder::array<real_T, 2U> y;
  coder::array<real_T, 1U> X_F_stacked;
  coder::array<real_T, 1U> b_x0;
  real_T b_X_L_stacked[60];
  real_T a[20];
  real_T dv1[20];
  real_T dv[2];
  real_T varargout_1;
  int32_T unnamed_idx_0;
  int32_T unnamed_idx_1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  //  FOLLOWER COST FUNCTION as
  //    J = c*J_1 + J_2
  //  J_1 checks the distance between the two robots
  //  q_L - q_F
  stateEvolution(U, x0, sys_n, sys_Ts, N, X_F_stacked);
  dv[0] = sys_n;
  dv[1] = N;
  //  Px * stateDiff
  if (X_F_stacked.size(0) == 60) {
    for (unnamed_idx_1 = 0; unnamed_idx_1 < 60; unnamed_idx_1++) {
      b_X_L_stacked[unnamed_idx_1] =
          X_L_stacked[unnamed_idx_1] - X_F_stacked[unnamed_idx_1];
    }
    unnamed_idx_0 = static_cast<int32_T>(sys_n);
    unnamed_idx_1 = static_cast<int32_T>(N);
    c_X_L_stacked.set(&b_X_L_stacked[0], unnamed_idx_0, unnamed_idx_1);
    coder::internal::blas::mtimes(robotParams_Px, c_X_L_stacked, projDiff);
  } else {
    binary_expand_op_3(projDiff, robotParams_Px, X_L_stacked, X_F_stacked, dv);
  }
  //  Cost evaluation
  //  J_1 = sum((robotParams.beta_N) .* (sum(projDiff.^2, 1) -
  //  robotParams.d_FL_sq) .^ 2);
  unnamed_idx_0 = projDiff.size(1) << 1;
  projDiff.set_size(2, projDiff.size(1));
  for (unnamed_idx_1 = 0; unnamed_idx_1 < unnamed_idx_0; unnamed_idx_1++) {
    varargout_1 = projDiff[unnamed_idx_1];
    projDiff[unnamed_idx_1] = varargout_1 * varargout_1;
  }
  if (projDiff.size(1) == 0) {
    y.set_size(1, 0);
  } else {
    unnamed_idx_1 = projDiff.size(1);
    y.set_size(1, projDiff.size(1));
    for (unnamed_idx_0 = 0; unnamed_idx_0 < unnamed_idx_1; unnamed_idx_0++) {
      y[unnamed_idx_0] = coder::sumColumnB(projDiff, unnamed_idx_0 + 1);
    }
  }
  if (y.size(1) == 20) {
    for (unnamed_idx_1 = 0; unnamed_idx_1 < 20; unnamed_idx_1++) {
      a[unnamed_idx_1] = y[unnamed_idx_1] - robotParams_d_FL_sq[unnamed_idx_1];
    }
  } else {
    binary_expand_op_2(a, y, robotParams_d_FL_sq);
  }
  for (unnamed_idx_0 = 0; unnamed_idx_0 < 20; unnamed_idx_0++) {
    varargout_1 = a[unnamed_idx_0];
    dv1[unnamed_idx_0] = varargout_1 * varargout_1;
  }
  //  J_2 accounts for the minimization of the travelled distance
  //  q_F(1:N) - q_F(0:N-1)
  varargout_1 = sys_n * (N - 1.0);
  if (varargout_1 < 1.0) {
    unnamed_idx_0 = 3;
  } else {
    unnamed_idx_0 = static_cast<int32_T>(varargout_1) + 3;
  }
  //  Px * distDiff
  if (X_F_stacked.size(0) == unnamed_idx_0) {
    b_x0.set_size(unnamed_idx_0);
    b_x0[0] = x0[0];
    b_x0[1] = x0[1];
    b_x0[2] = x0[2];
    for (unnamed_idx_1 = 0; unnamed_idx_1 <= unnamed_idx_0 - 4;
         unnamed_idx_1++) {
      b_x0[unnamed_idx_1 + 3] = X_F_stacked[unnamed_idx_1];
    }
    unnamed_idx_0 = X_F_stacked.size(0);
    for (unnamed_idx_1 = 0; unnamed_idx_1 < unnamed_idx_0; unnamed_idx_1++) {
      X_F_stacked[unnamed_idx_1] =
          X_F_stacked[unnamed_idx_1] - b_x0[unnamed_idx_1];
    }
    unnamed_idx_0 = static_cast<int32_T>(sys_n);
    unnamed_idx_1 = static_cast<int32_T>(N);
    b_X_F_stacked = X_F_stacked.reshape(unnamed_idx_0, unnamed_idx_1);
    coder::internal::blas::mtimes(robotParams_Px, b_X_F_stacked, projDiff);
  } else {
    binary_expand_op_1(projDiff, robotParams_Px, X_F_stacked, x0,
                       unnamed_idx_0 - 4, dv);
  }
  //  Cost evaluation
  unnamed_idx_0 = projDiff.size(1) << 1;
  projDiff.set_size(2, projDiff.size(1));
  for (unnamed_idx_1 = 0; unnamed_idx_1 < unnamed_idx_0; unnamed_idx_1++) {
    varargout_1 = projDiff[unnamed_idx_1];
    projDiff[unnamed_idx_1] = varargout_1 * varargout_1;
  }
  if (projDiff.size(1) == 0) {
    y.set_size(1, 0);
  } else {
    unnamed_idx_1 = projDiff.size(1);
    y.set_size(1, projDiff.size(1));
    for (unnamed_idx_0 = 0; unnamed_idx_0 < unnamed_idx_1; unnamed_idx_0++) {
      y[unnamed_idx_0] = coder::sumColumnB(projDiff, unnamed_idx_0 + 1);
    }
  }
  //  Final cost
  varargout_1 = 0.0;
  for (unnamed_idx_1 = 0; unnamed_idx_1 < 20; unnamed_idx_1++) {
    varargout_1 += robotParams_beta_N[unnamed_idx_1] * dv1[unnamed_idx_1];
  }
  varargout_1 = robotParams_C * varargout_1 + coder::sum(y);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return varargout_1;
}

int32_T
followerMPCandUpdate_anonFcn2(const real_T x0[3], real_T obstacles_M_f,
                              const coder::array<real_T, 2U> &obstacles_A_bar_f,
                              const real_T obstacles_B_bar_f_data[],
                              int32_T obstacles_B_bar_f_size, real_T N,
                              real_T sys_n, real_T sys_Ts, const real_T U[40],
                              real_T varargout_1_data[])
{
  coder::array<real_T, 1U> c_obst_av;
  real_T y_data[4200];
  int32_T varargout_1_size;
  int32_T y_size;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  //  Obtain the number of vertices
  //  Obtain the number of states n and number of inputs m
  //  Obstacle avoidance
  //  c(x) = A_bar * x_h - B_bar s.t    c(x) <= 0
  if (obstacles_M_f >= 1.0) {
    stateEvolution(U, x0, sys_n, sys_Ts, N, c_obst_av);
    y_size =
        coder::internal::blas::mtimes(obstacles_A_bar_f, c_obst_av, y_data);
    if (y_size == obstacles_B_bar_f_size) {
      c_obst_av.set_size(y_size);
      for (int32_T i{0}; i < y_size; i++) {
        c_obst_av[i] = y_data[i] - obstacles_B_bar_f_data[i];
      }
    } else {
      binary_expand_op(c_obst_av, y_data, y_size, obstacles_B_bar_f_data,
                       obstacles_B_bar_f_size);
    }
  } else {
    //  If there are no constraints
    c_obst_av.set_size(0);
  }
  //  Input constraints
  //  Defined in the fmincon function
  //  Final output
  y_size = c_obst_av.size(0);
  varargout_1_size = c_obst_av.size(0);
  for (int32_T i{0}; i < y_size; i++) {
    varargout_1_data[i] = c_obst_av[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return varargout_1_size;
}

// End of code generation (followerMPCandUpdate.cpp)
