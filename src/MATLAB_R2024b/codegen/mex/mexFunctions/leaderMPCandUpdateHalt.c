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
#include "fmincon.h"
#include "mexFunctions_data.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "stateEvolution.h"
#include "sum.h"
#include "sumMatrixIncludeNaN.h"
#include "omp.h"
#include <immintrin.h>
#include <string.h>

/* Function Definitions */
void leaderMPCandUpdateHalt(emlrtCTX aTLS, mexFunctionsStackData *SD,
                            const struct3_T *sys, const real_T x0[3], real_T N,
                            const struct1_T *robotParams,
                            const struct5_T *obstacles,
                            const real_T U_l_old[40], emxArray_real_T *p_tp1,
                            emxArray_real_T *X_L, emxArray_real_T *X_L_stacked,
                            struct6_T *b_error, real_T u_t[2], real_T u_opt[40])
{
  jmp_buf *volatile emlrtJBStack;
  real_T a__1;
  real_T *X_L_data;
  real_T *X_L_stacked_data;
  int32_T i;
  int32_T leaderMPCandUpdateHalt_numThreads;
  int32_T loop_ub;
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
            robotParams->lb, robotParams->ub, x0, obstacles, N, *sys,
            &b_error->QPexitflag, &b_error->QPoutput.iterations,
            &b_error->QPoutput.funcCount, b_error->QPoutput.algorithm,
            &b_error->QPoutput.constrviolation, &b_error->QPoutput.stepsize,
            &b_error->QPoutput.lssteplength, &b_error->QPoutput.firstorderopt);
  emlrtMEXProfilingStatement(6, isMexOutdated);
  emlrtMEXProfilingStatement(7, isMexOutdated);
  /*  States and output */
  emlrtMEXProfilingStatement(8, isMexOutdated);
  stateEvolution(u_opt, x0, sys->n, sys->Ts, N, X_L_stacked);
  X_L_stacked_data = X_L_stacked->data;
  emlrtMEXProfilingStatement(9, isMexOutdated);
  a__1 = sys->n;
  loop_ub = (int32_T)sys->n;
  loop_ub_tmp = X_L->size[0] * X_L->size[1];
  X_L->size[0] = (int32_T)sys->n;
  X_L->size[1] = (int32_T)N;
  emxEnsureCapacity_real_T(X_L, loop_ub_tmp);
  X_L_data = X_L->data;
  loop_ub_tmp = (int32_T)sys->n * (int32_T)N;
  if (loop_ub_tmp < 1200) {
    for (i = 0; i < loop_ub_tmp; i++) {
      X_L_data[i] = X_L_stacked_data[i];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    leaderMPCandUpdateHalt_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(leaderMPCandUpdateHalt_numThreads)

    for (i = 0; i < loop_ub_tmp; i++) {
      X_L_data[i] = X_L_stacked_data[i];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  /*  Update the state and input with the first one predicted */
  emlrtMEXProfilingStatement(10, isMexOutdated);
  loop_ub_tmp = p_tp1->size[0];
  p_tp1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(p_tp1, loop_ub_tmp);
  X_L_data = p_tp1->data;
  if ((int32_T)a__1 < 1200) {
    for (i = 0; i < loop_ub; i++) {
      X_L_data[i] = X_L_stacked_data[i];
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    leaderMPCandUpdateHalt_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(leaderMPCandUpdateHalt_numThreads)

    for (i = 0; i < loop_ub; i++) {
      X_L_data[i] = X_L_stacked_data[i];
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  emlrtMEXProfilingStatement(11, isMexOutdated);
  emlrtMEXProfilingStatement(12, isMexOutdated);
  emlrtMEXProfilingStatement(13, isMexOutdated);
  u_t[0] = u_opt[0];
  u_t[1] = u_opt[1];
  emlrtMEXProfilingStatement(14, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
}

real_T leaderMPCandUpdateHalt_anonFcn1(emlrtCTX aTLS, const real_T x0[3],
                                       real_T sys_n, real_T sys_Ts, real_T N,
                                       const real_T robotParams_Px[6],
                                       const real_T U[40])
{
  jmp_buf *volatile emlrtJBStack;
  emxArray_real_T b_X_L_stacked;
  emxArray_real_T *X_L_stacked;
  emxArray_real_T *b_x0;
  emxArray_real_T *projDiff;
  emxArray_real_T *y;
  real_T sz[2];
  real_T varargin_1;
  real_T varargout_1;
  real_T *X_L_stacked_data;
  real_T *x0_data;
  int32_T b_sz[2];
  int32_T col;
  int32_T leaderMPCandUpdateHalt_anonFcn1_numThreads;
  int32_T ncols;
  int32_T scalarLB;
  int32_T vectorUB;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
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
    ncols = 3;
  } else {
    ncols = (int32_T)varargout_1 + 3;
  }
  emlrtMEXProfilingStatement(3, isMexOutdated);
  emlrtMEXProfilingStatement(4, isMexOutdated);
  sz[0] = sys_n;
  sz[1] = N;
  /*  Px * distDiff */
  emlrtMEXProfilingStatement(5, isMexOutdated);
  emxInit_real_T(&projDiff, 2);
  if (X_L_stacked->size[0] == ncols) {
    emxInit_real_T(&b_x0, 1);
    scalarLB = b_x0->size[0];
    b_x0->size[0] = ncols;
    emxEnsureCapacity_real_T(b_x0, scalarLB);
    x0_data = b_x0->data;
    x0_data[0] = x0[0];
    x0_data[1] = x0[1];
    x0_data[2] = x0[2];
    if (ncols - 3 < 1200) {
      for (col = 0; col <= ncols - 4; col++) {
        x0_data[col + 3] = X_L_stacked_data[col];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      leaderMPCandUpdateHalt_anonFcn1_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(leaderMPCandUpdateHalt_anonFcn1_numThreads)

      for (col = 0; col <= ncols - 4; col++) {
        x0_data[col + 3] = X_L_stacked_data[col];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    ncols = X_L_stacked->size[0];
    scalarLB = (X_L_stacked->size[0] / 4) << 2;
    vectorUB = scalarLB - 4;
    for (col = 0; col <= vectorUB; col += 4) {
      __m256d r;
      __m256d r1;
      r = _mm256_loadu_pd(&X_L_stacked_data[col]);
      r1 = _mm256_loadu_pd(&x0_data[col]);
      _mm256_storeu_pd(&X_L_stacked_data[col], _mm256_sub_pd(r, r1));
    }
    if (X_L_stacked->size[0] - scalarLB < 1200) {
      for (col = scalarLB; col < ncols; col++) {
        X_L_stacked_data[col] -= x0_data[col];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      leaderMPCandUpdateHalt_anonFcn1_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(leaderMPCandUpdateHalt_anonFcn1_numThreads)

      for (col = scalarLB; col < ncols; col++) {
        X_L_stacked_data[col] -= x0_data[col];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    emxFree_real_T(&b_x0);
    b_X_L_stacked = *X_L_stacked;
    b_sz[0] = (int32_T)sz[0];
    b_sz[1] = (int32_T)sz[1];
    b_X_L_stacked.size = &b_sz[0];
    b_X_L_stacked.numDimensions = 2;
    b_mtimes(robotParams_Px, &b_X_L_stacked, projDiff);
  } else {
    binary_expand_op_1(aTLS, projDiff, robotParams_Px, X_L_stacked, x0,
                       ncols - 4, sz);
  }
  emxFree_real_T(&X_L_stacked);
  /*  Cost evaluation */
  emlrtMEXProfilingStatement(6, isMexOutdated);
  vectorUB = projDiff->size[1] << 1;
  scalarLB = projDiff->size[0] * projDiff->size[1];
  projDiff->size[0] = 2;
  emxEnsureCapacity_real_T(projDiff, scalarLB);
  X_L_stacked_data = projDiff->data;
  ncols = projDiff->size[1];
  if (vectorUB < 1200) {
    for (col = 0; col < vectorUB; col++) {
      varargout_1 = X_L_stacked_data[col];
      X_L_stacked_data[col] = varargout_1 * varargout_1;
    }
  } else {
    emlrtEnterParallelRegion(aTLS, omp_in_parallel());
    emlrtPushJmpBuf(aTLS, &emlrtJBStack);
    leaderMPCandUpdateHalt_anonFcn1_numThreads = emlrtAllocRegionTLSs(
        aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(                                          \
        leaderMPCandUpdateHalt_anonFcn1_numThreads) private(varargin_1)

    for (col = 0; col < vectorUB; col++) {
      varargin_1 = X_L_stacked_data[col];
      X_L_stacked_data[col] = varargin_1 * varargin_1;
    }
    emlrtPopJmpBuf(aTLS, &emlrtJBStack);
    emlrtExitParallelRegion(aTLS, omp_in_parallel());
  }
  emxInit_real_T(&y, 2);
  if (projDiff->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    scalarLB = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = ncols;
    emxEnsureCapacity_real_T(y, scalarLB);
    X_L_stacked_data = y->data;
    if (projDiff->size[1] < 1200) {
      for (col = 0; col < ncols; col++) {
        X_L_stacked_data[col] = sumColumnB(projDiff, col + 1);
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      leaderMPCandUpdateHalt_anonFcn1_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(leaderMPCandUpdateHalt_anonFcn1_numThreads)

      for (col = 0; col < ncols; col++) {
        X_L_stacked_data[col] = sumColumnB(projDiff, col + 1);
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  emxFree_real_T(&projDiff);
  varargout_1 = sum(y);
  emxFree_real_T(&y);
  emlrtMEXProfilingStatement(7, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
  return varargout_1;
}

/* End of code generation (leaderMPCandUpdateHalt.c) */
