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
#include "evaluateObstacles_mex_types.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T b_evalObjAndConstrAndDerivative(
    int32_T c_obj_next_next_next_next_next_,
    const real_T d_obj_next_next_next_next_next_[3],
    const struct5_T *e_obj_next_next_next_next_next_,
    real_T f_obj_next_next_next_next_next_,
    const struct3_T g_obj_next_next_next_next_next_,
    const i_struct_T *h_obj_next_next_next_next_next_, const real_T x[40],
    real_T Cineq_workspace_data[], const int32_T *Cineq_workspace_size,
    int32_T ineq0, int32_T *status)
{
  real_T b_Cineq_workspace_data[4241];
  real_T fval;
  boolean_T b;
  fval = leaderMPCandUpdateHalt_anonFcn1(
      h_obj_next_next_next_next_next_->x0,
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
    if (loop_ub - 1 >= 0) {
      memcpy(&b_Cineq_workspace_data[0], &Cineq_workspace_data[0],
             (uint32_T)loop_ub * sizeof(real_T));
    }
    *status = c_computeConstraints_(
        c_obj_next_next_next_next_next_, d_obj_next_next_next_next_next_,
        e_obj_next_next_next_next_next_, f_obj_next_next_next_next_next_,
        g_obj_next_next_next_next_next_, x, b_Cineq_workspace_data, ineq0);
    if (loop_ub - 1 >= 0) {
      memcpy(&Cineq_workspace_data[0], &b_Cineq_workspace_data[0],
             (uint32_T)loop_ub * sizeof(real_T));
    }
  }
  return fval;
}

real_T evalObjAndConstrAndDerivatives(
    int32_T c_obj_next_next_next_next_next_,
    const real_T d_obj_next_next_next_next_next_[3],
    const struct5_T *e_obj_next_next_next_next_next_,
    real_T f_obj_next_next_next_next_next_,
    const struct3_T g_obj_next_next_next_next_next_,
    const h_struct_T *h_obj_next_next_next_next_next_, const real_T x[40],
    real_T Cineq_workspace_data[], const int32_T *Cineq_workspace_size,
    int32_T ineq0, int32_T *status)
{
  real_T b_Cineq_workspace_data[4241];
  real_T fval;
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
    if (loop_ub - 1 >= 0) {
      memcpy(&b_Cineq_workspace_data[0], &Cineq_workspace_data[0],
             (uint32_T)loop_ub * sizeof(real_T));
    }
    *status = b_computeConstraints_(
        c_obj_next_next_next_next_next_, d_obj_next_next_next_next_next_,
        e_obj_next_next_next_next_next_, f_obj_next_next_next_next_next_,
        g_obj_next_next_next_next_next_, x, b_Cineq_workspace_data, ineq0);
    if (loop_ub - 1 >= 0) {
      memcpy(&Cineq_workspace_data[0], &b_Cineq_workspace_data[0],
             (uint32_T)loop_ub * sizeof(real_T));
    }
  }
  return fval;
}

/* End of code generation (evalObjAndConstrAndDerivatives.c) */
