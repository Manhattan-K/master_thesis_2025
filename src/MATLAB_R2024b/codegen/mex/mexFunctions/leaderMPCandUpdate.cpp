//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// leaderMPCandUpdate.cpp
//
// Code generation for function 'leaderMPCandUpdate'
//

// Include files
#include "leaderMPCandUpdate.h"
#include "anonymous_function.h"
#include "fmincon.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "mexFunctions_types1.h"
#include "mexFunctions_types2.h"
#include "rt_nonfinite.h"
#include "stateEvolution.h"
#include "blas.h"
#include "coder_array.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Function Definitions
void leaderMPCandUpdate(mexFunctionsStackData *SD, const struct3_T *sys,
                        const real_T x0[3], real_T N,
                        const struct1_T *robotParams,
                        const struct5_T *obstacles, const real_T U_l_old[40],
                        coder::array<real_T, 1U> &p_tp1,
                        coder::array<real_T, 2U> &X_L,
                        coder::array<real_T, 1U> &X_L_stacked,
                        struct6_T *c_error, real_T u_t[2], real_T u_opt[40])
{
  coder::c_anonymous_function costF;
  int32_T b_loop_ub_tmp;
  int32_T loop_ub_tmp;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  //  Variables definitions
  //  Get cost function
  costF.workspace.N = N;
  costF.workspace.sys = *sys;
  costF.workspace.robotParams = *robotParams;
  //  Get constraints function
  SD->f5.constraintsF.workspace.N = N;
  costF.workspace.x0[0] = x0[0];
  SD->f5.constraintsF.workspace.x0[0] = x0[0];
  costF.workspace.x0[1] = x0[1];
  SD->f5.constraintsF.workspace.x0[1] = x0[1];
  costF.workspace.x0[2] = x0[2];
  SD->f5.constraintsF.workspace.x0[2] = x0[2];
  SD->f5.constraintsF.workspace.obstacles = *obstacles;
  SD->f5.constraintsF.workspace.robotParams = *robotParams;
  SD->f5.constraintsF.workspace.sys = *sys;
  //  fmincon optimization
  std::copy(&U_l_old[0], &U_l_old[40], &u_opt[0]);
  coder::d_fmincon(
      SD, costF, u_opt, robotParams->lb, robotParams->ub, SD->f5.constraintsF,
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

real_T leaderMPCandUpdate_anonFcn1(const real_T x0[3], real_T sys_n,
                                   real_T sys_Ts, const real_T robotParams_W[9],
                                   const real_T robotParams_W_hat[3600],
                                   const real_T robotParams_R_hat[1600],
                                   real_T N, const real_T U[40])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  coder::array<real_T, 1U> x_pred;
  real_T y[60];
  real_T b_y[40];
  real_T beta1;
  real_T c_y;
  real_T varargout_1;
  char_T TRANSA1;
  char_T TRANSB1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  //  LEADER COST FUNCTION as
  //    J = q(0)'Wq(0) + q_staked' W_hat q_stacked + ...
  //        u_stacked' R_hat u_stacked
  stateEvolution(U, x0, sys_n, sys_Ts, N, x_pred);
  if (x_pred.size(0) == 0) {
    std::memset(&y[0], 0, 60U * sizeof(real_T));
  } else {
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    varargout_1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)60;
    k_t = (ptrdiff_t)60;
    lda_t = (ptrdiff_t)x_pred.size(0);
    ldb_t = (ptrdiff_t)60;
    ldc_t = (ptrdiff_t)1;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &varargout_1,
          &(x_pred.data())[0], &lda_t, (real_T *)&robotParams_W_hat[0], &ldb_t,
          &beta1, &y[0], &ldc_t);
  }
  TRANSB1 = 'N';
  TRANSA1 = 'T';
  varargout_1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)1;
  n_t = (ptrdiff_t)40;
  k_t = (ptrdiff_t)40;
  lda_t = (ptrdiff_t)40;
  ldb_t = (ptrdiff_t)40;
  ldc_t = (ptrdiff_t)1;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &varargout_1, (real_T *)&U[0],
        &lda_t, (real_T *)&robotParams_R_hat[0], &ldb_t, &beta1, &b_y[0],
        &ldc_t);
  varargout_1 = 0.0;
  for (int32_T i{0}; i < 3; i++) {
    varargout_1 +=
        ((x0[0] * robotParams_W[3 * i] + x0[1] * robotParams_W[3 * i + 1]) +
         x0[2] * robotParams_W[3 * i + 2]) *
        x0[i];
  }
  beta1 = 0.0;
  for (int32_T i{0}; i < 60; i++) {
    beta1 += y[i] * x_pred[i];
  }
  c_y = 0.0;
  for (int32_T i{0}; i < 40; i++) {
    c_y += b_y[i] * U[i];
  }
  varargout_1 = (varargout_1 + beta1) + c_y;
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return varargout_1;
}

// End of code generation (leaderMPCandUpdate.cpp)
