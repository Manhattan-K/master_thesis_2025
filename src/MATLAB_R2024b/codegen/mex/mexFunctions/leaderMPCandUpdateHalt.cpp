//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// leaderMPCandUpdateHalt.cpp
//
// Code generation for function 'leaderMPCandUpdateHalt'
//

// Include files
#include "leaderMPCandUpdateHalt.h"
#include "anonymous_function.h"
#include "eml_mtimes_helper.h"
#include "fmincon.h"
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
void leaderMPCandUpdateHalt(
    mexFunctionsStackData *SD, const struct3_T *sys, const real_T x0[3],
    real_T N, const struct1_T *robotParams, const struct5_T *obstacles,
    const real_T U_l_old[40], coder::array<real_T, 1U> &p_tp1,
    coder::array<real_T, 2U> &X_L, coder::array<real_T, 1U> &X_L_stacked,
    struct6_T *c_error, real_T u_t[2], real_T u_opt[40])
{
  coder::e_anonymous_function costF;
  int32_T b_loop_ub_tmp;
  int32_T loop_ub_tmp;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  //  Variables definitions
  //  Get cost function
  costF.workspace.N = N;
  costF.workspace.sys = *sys;
  costF.workspace.robotParams = *robotParams;
  //  Get constraints function
  SD->f6.constraintsF.workspace.N = N;
  costF.workspace.x0[0] = x0[0];
  SD->f6.constraintsF.workspace.x0[0] = x0[0];
  costF.workspace.x0[1] = x0[1];
  SD->f6.constraintsF.workspace.x0[1] = x0[1];
  costF.workspace.x0[2] = x0[2];
  SD->f6.constraintsF.workspace.x0[2] = x0[2];
  SD->f6.constraintsF.workspace.obstacles = *obstacles;
  SD->f6.constraintsF.workspace.robotParams = *robotParams;
  SD->f6.constraintsF.workspace.sys = *sys;
  //  fmincon optimization
  std::copy(&U_l_old[0], &U_l_old[40], &u_opt[0]);
  coder::d_fmincon(
      SD, costF, u_opt, robotParams->lb, robotParams->ub, SD->f6.constraintsF,
      c_error->QPexitflag, c_error->QPoutput.iterations,
      c_error->QPoutput.funcCount, c_error->QPoutput.algorithm,
      c_error->QPoutput.constrviolation, c_error->QPoutput.stepsize,
      c_error->QPoutput.lssteplength, c_error->QPoutput.firstorderopt);
  //  States and output
  stateEvolution(u_opt, x0, sys->n, sys->Ts, N, X_L_stacked);
  loop_ub_tmp = static_cast<int32_T>(sys->n);
  X_L.set_size(loop_ub_tmp, static_cast<int32_T>(N));
  b_loop_ub_tmp = static_cast<int32_T>(sys->n) * static_cast<int32_T>(N);
  for (int32_T i{0}; i < b_loop_ub_tmp; i++) {
    X_L[i] = X_L_stacked[i];
  }
  //  Update the state and input with the first one predicted
  p_tp1.set_size(loop_ub_tmp);
  for (int32_T i{0}; i < loop_ub_tmp; i++) {
    p_tp1[i] = X_L_stacked[i];
  }
  u_t[0] = u_opt[0];
  u_t[1] = u_opt[1];
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

real_T leaderMPCandUpdateHalt_anonFcn1(const real_T x0[3], real_T sys_n,
                                       real_T sys_Ts, real_T N,
                                       const real_T robotParams_Px[6],
                                       const real_T U[40])
{
  coder::array<real_T, 2U> b_X_L_stacked;
  coder::array<real_T, 2U> projDiff;
  coder::array<real_T, 2U> y;
  coder::array<real_T, 1U> X_L_stacked;
  coder::array<real_T, 1U> b_x0;
  real_T sz[2];
  real_T varargout_1;
  int32_T loop_ub;
  int32_T sz_idx_1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  //  The cost accounts for the minimization of the travelled distance
  //  q_F(1:N) - q_F(0:N-1)
  stateEvolution(U, x0, sys_n, sys_Ts, N, X_L_stacked);
  varargout_1 = sys_n * (N - 1.0);
  if (varargout_1 < 1.0) {
    loop_ub = 3;
  } else {
    loop_ub = static_cast<int32_T>(varargout_1) + 3;
  }
  sz[0] = sys_n;
  sz[1] = N;
  //  Px * distDiff
  if (X_L_stacked.size(0) == loop_ub) {
    b_x0.set_size(loop_ub);
    b_x0[0] = x0[0];
    b_x0[1] = x0[1];
    b_x0[2] = x0[2];
    for (sz_idx_1 = 0; sz_idx_1 <= loop_ub - 4; sz_idx_1++) {
      b_x0[sz_idx_1 + 3] = X_L_stacked[sz_idx_1];
    }
    loop_ub = X_L_stacked.size(0);
    for (sz_idx_1 = 0; sz_idx_1 < loop_ub; sz_idx_1++) {
      X_L_stacked[sz_idx_1] = X_L_stacked[sz_idx_1] - b_x0[sz_idx_1];
    }
    loop_ub = static_cast<int32_T>(sys_n);
    sz_idx_1 = static_cast<int32_T>(N);
    b_X_L_stacked = X_L_stacked.reshape(loop_ub, sz_idx_1);
    coder::internal::blas::mtimes(robotParams_Px, b_X_L_stacked, projDiff);
  } else {
    binary_expand_op_1(projDiff, robotParams_Px, X_L_stacked, x0, loop_ub - 4,
                       sz);
  }
  //  Cost evaluation
  loop_ub = projDiff.size(1) << 1;
  projDiff.set_size(2, projDiff.size(1));
  for (sz_idx_1 = 0; sz_idx_1 < loop_ub; sz_idx_1++) {
    varargout_1 = projDiff[sz_idx_1];
    projDiff[sz_idx_1] = varargout_1 * varargout_1;
  }
  if (projDiff.size(1) == 0) {
    y.set_size(1, 0);
  } else {
    sz_idx_1 = projDiff.size(1);
    y.set_size(1, projDiff.size(1));
    for (loop_ub = 0; loop_ub < sz_idx_1; loop_ub++) {
      y[loop_ub] = coder::sumColumnB(projDiff, loop_ub + 1);
    }
  }
  varargout_1 = coder::sum(y);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return varargout_1;
}

// End of code generation (leaderMPCandUpdateHalt.cpp)
