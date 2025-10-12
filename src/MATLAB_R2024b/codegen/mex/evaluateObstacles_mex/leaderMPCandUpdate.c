/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * leaderMPCandUpdate.c
 *
 * Code generation for function 'leaderMPCandUpdate'
 *
 */

/* Include files */
#include "leaderMPCandUpdate.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "fmincon.h"
#include "rt_nonfinite.h"
#include "stateEvolution.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void leaderMPCandUpdate(evaluateObstacles_mexStackData *SD,
                        const struct3_T *sys, const real_T x0[3], real_T N,
                        const struct1_T *robotParams,
                        const struct5_T *obstacles, const real_T U_l_old[40],
                        emxArray_real_T *p_tp1, emxArray_real_T *X_L,
                        emxArray_real_T *X_L_stacked, struct6_T *c_error,
                        real_T u_t[2], real_T u_opt[40])
{
  real_T *X_L_data;
  real_T *X_L_stacked_data;
  int32_T b_loop_ub_tmp;
  int32_T i;
  int32_T loop_ub_tmp;
  emlrtMEXProfilingFunctionEntry((char_T *)c_leaderMPCandUpdate_complete_n,
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
  b_fmincon(SD, x0, sys->n, sys->m, sys->Ts, robotParams, N, u_opt,
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
  emxArray_real_T *x_pred;
  real_T y[60];
  real_T b_y[40];
  real_T beta1;
  real_T c_y;
  real_T varargout_1;
  real_T *x_pred_data;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emlrtMEXProfilingFunctionEntry((char_T *)d_completeName, isMexOutdated);
  emlrtMEXProfilingFunctionEntry((char_T *)leaderCost_complete_name,
                                 isMexOutdated);
  /*  LEADER COST FUNCTION as  */
  /*    J = q(0)'Wq(0) + q_staked' W_hat q_stacked + ... */
  /*        u_stacked' R_hat u_stacked */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  emxInit_real_T(&x_pred, 1);
  stateEvolution(U, x0, sys_n, sys_Ts, N, x_pred);
  x_pred_data = x_pred->data;
  emlrtMEXProfilingStatement(2, isMexOutdated);
  emlrtMEXProfilingStatement(3, isMexOutdated);
  if (x_pred->size[0] == 0) {
    memset(&y[0], 0, 60U * sizeof(real_T));
  } else {
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    varargout_1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)60;
    k_t = (ptrdiff_t)60;
    lda_t = (ptrdiff_t)x_pred->size[0];
    ldb_t = (ptrdiff_t)60;
    ldc_t = (ptrdiff_t)1;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &varargout_1, &x_pred_data[0],
          &lda_t, (real_T *)&robotParams_W_hat[0], &ldb_t, &beta1, &y[0],
          &ldc_t);
  }
  emlrtMEXProfilingStatement(4, isMexOutdated);
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
  emlrtMEXProfilingStatement(5, isMexOutdated);
  varargout_1 = 0.0;
  for (i = 0; i < 3; i++) {
    varargout_1 +=
        ((x0[0] * robotParams_W[3 * i] + x0[1] * robotParams_W[3 * i + 1]) +
         x0[2] * robotParams_W[3 * i + 2]) *
        x0[i];
  }
  beta1 = 0.0;
  for (i = 0; i < 60; i++) {
    beta1 += y[i] * x_pred_data[i];
  }
  emxFree_real_T(&x_pred);
  c_y = 0.0;
  for (i = 0; i < 40; i++) {
    c_y += b_y[i] * U[i];
  }
  varargout_1 = (varargout_1 + beta1) + c_y;
  emlrtMEXProfilingStatement(6, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return varargout_1;
}

/* End of code generation (leaderMPCandUpdate.c) */
