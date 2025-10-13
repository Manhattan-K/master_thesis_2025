/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * evalObjAndConstrAndDerivatives.c
 *
 * Code generation for function 'evalObjAndConstrAndDerivatives'
 *
 */

/* Include files */
#include "evalObjAndConstrAndDerivatives.h"
#include "computeConstraints_.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
real_T b_evalObjAndConstrAndDerivative(
    emlrtCTX aTLS, int32_T c_obj_next_next_next_next_next_,
    const real_T d_obj_next_next_next_next_next_[3],
    const struct5_T *e_obj_next_next_next_next_next_,
    real_T f_obj_next_next_next_next_next_,
    const struct3_T g_obj_next_next_next_next_next_,
    const d_struct_T *h_obj_next_next_next_next_next_, const real_T x[40],
    real_T Cineq_workspace_data[], const int32_T *Cineq_workspace_size,
    int32_T ineq0, int32_T *status)
{
  jmp_buf *volatile emlrtJBStack;
  real_T b_Cineq_workspace_data[4241];
  real_T fval;
  int32_T b_evalObjAndConstrAndDerivative_numThreads;
  int32_T i;
  boolean_T b;
  fval = leaderMPCandUpdateHalt_anonFcn1(
      aTLS, h_obj_next_next_next_next_next_->x0,
      h_obj_next_next_next_next_next_->sys.n,
      h_obj_next_next_next_next_next_->sys.Ts,
      h_obj_next_next_next_next_next_->N,
      h_obj_next_next_next_next_next_->robotParams.Px, x);
  *status = 1;
  b = muDoubleScalarIsNaN(fval);
  if (muDoubleScalarIsInf(fval) || b) {
    if (b) {
      *status = -3;
    } else if (fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  }
  if (*status == 1) {
    int32_T loop_ub;
    loop_ub = *Cineq_workspace_size;
    if (loop_ub < 1200) {
      if (loop_ub - 1 >= 0) {
        memcpy(&b_Cineq_workspace_data[0], &Cineq_workspace_data[0],
               (uint32_T)loop_ub * sizeof(real_T));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      b_evalObjAndConstrAndDerivative_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_evalObjAndConstrAndDerivative_numThreads)

      for (i = 0; i < loop_ub; i++) {
        b_Cineq_workspace_data[i] = Cineq_workspace_data[i];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    *status = c_computeConstraints_(
        aTLS, c_obj_next_next_next_next_next_, d_obj_next_next_next_next_next_,
        e_obj_next_next_next_next_next_, f_obj_next_next_next_next_next_,
        g_obj_next_next_next_next_next_, x, b_Cineq_workspace_data, ineq0);
    if (loop_ub < 1200) {
      if (loop_ub - 1 >= 0) {
        memcpy(&Cineq_workspace_data[0], &b_Cineq_workspace_data[0],
               (uint32_T)loop_ub * sizeof(real_T));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      b_evalObjAndConstrAndDerivative_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_evalObjAndConstrAndDerivative_numThreads)

      for (i = 0; i < loop_ub; i++) {
        Cineq_workspace_data[i] = b_Cineq_workspace_data[i];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  return fval;
}

real_T evalObjAndConstrAndDerivatives(
    emlrtCTX aTLS, int32_T c_obj_next_next_next_next_next_,
    const real_T d_obj_next_next_next_next_next_[3],
    const struct5_T *e_obj_next_next_next_next_next_,
    real_T f_obj_next_next_next_next_next_,
    const struct3_T g_obj_next_next_next_next_next_,
    const c_struct_T *h_obj_next_next_next_next_next_, const real_T x[40],
    real_T Cineq_workspace_data[], const int32_T *Cineq_workspace_size,
    int32_T ineq0, int32_T *status)
{
  jmp_buf *volatile emlrtJBStack;
  real_T b_Cineq_workspace_data[4241];
  real_T fval;
  int32_T evalObjAndConstrAndDerivatives_numThreads;
  int32_T i;
  boolean_T b;
  fval = leaderMPCandUpdate_anonFcn1(
      h_obj_next_next_next_next_next_->x0,
      h_obj_next_next_next_next_next_->sys.n,
      h_obj_next_next_next_next_next_->sys.Ts,
      h_obj_next_next_next_next_next_->robotParams.W,
      h_obj_next_next_next_next_next_->robotParams.W_hat,
      h_obj_next_next_next_next_next_->robotParams.R_hat,
      h_obj_next_next_next_next_next_->N, x);
  *status = 1;
  b = muDoubleScalarIsNaN(fval);
  if (muDoubleScalarIsInf(fval) || b) {
    if (b) {
      *status = -3;
    } else if (fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  }
  if (*status == 1) {
    int32_T loop_ub;
    loop_ub = *Cineq_workspace_size;
    if (loop_ub < 1200) {
      if (loop_ub - 1 >= 0) {
        memcpy(&b_Cineq_workspace_data[0], &Cineq_workspace_data[0],
               (uint32_T)loop_ub * sizeof(real_T));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      evalObjAndConstrAndDerivatives_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(evalObjAndConstrAndDerivatives_numThreads)

      for (i = 0; i < loop_ub; i++) {
        b_Cineq_workspace_data[i] = Cineq_workspace_data[i];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    *status = b_computeConstraints_(
        aTLS, c_obj_next_next_next_next_next_, d_obj_next_next_next_next_next_,
        e_obj_next_next_next_next_next_, f_obj_next_next_next_next_next_,
        g_obj_next_next_next_next_next_, x, b_Cineq_workspace_data, ineq0);
    if (loop_ub < 1200) {
      if (loop_ub - 1 >= 0) {
        memcpy(&Cineq_workspace_data[0], &b_Cineq_workspace_data[0],
               (uint32_T)loop_ub * sizeof(real_T));
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      evalObjAndConstrAndDerivatives_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(evalObjAndConstrAndDerivatives_numThreads)

      for (i = 0; i < loop_ub; i++) {
        Cineq_workspace_data[i] = b_Cineq_workspace_data[i];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
  }
  return fval;
}

/* End of code generation (evalObjAndConstrAndDerivatives.c) */
