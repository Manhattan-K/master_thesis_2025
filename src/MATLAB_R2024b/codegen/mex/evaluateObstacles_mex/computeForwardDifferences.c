/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeForwardDifferences.c
 *
 * Code generation for function 'computeForwardDifferences'
 *
 */

/* Include files */
#include "computeForwardDifferences.h"
#include "evaluateObstacles_mex_types.h"
#include "finDiffEvalAndChkErr.h"
#include "fwdFinDiffInsideBnds.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
boolean_T b_computeForwardDifferences(
    q_struct_T *obj, real_T fCurrent, const real_T cIneqCurrent_data[],
    int32_T ineq0, real_T xk[40], real_T gradf_data[],
    emxArray_real_T *JacCineqTrans, int32_T CineqColStart, int32_T ldJI,
    const real_T lb_data[], const real_T ub_data[])
{
  real_T deltaX;
  real_T *JacCineqTrans_data;
  int32_T idx;
  int32_T idx_row;
  boolean_T evalOK;
  boolean_T exitg1;
  JacCineqTrans_data = JacCineqTrans->data;
  evalOK = true;
  obj->numEvals = 0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 40)) {
    real_T c_t0_nonlin_workspace_obstacles;
    real_T t0_nonlin_workspace_N;
    real_T t0_nonlin_workspace_sys_Ts;
    real_T t0_nonlin_workspace_sys_n;
    real_T t0_objfun_workspace_N;
    real_T t0_objfun_workspace_sys_Ts;
    real_T t0_objfun_workspace_sys_n;
    int32_T t0_mIneq;
    boolean_T guard1;
    boolean_T modifiedStep;
    modifiedStep = false;
    deltaX = 1.4901161193847656E-8 * (1.0 - 2.0 * (real_T)(xk[idx] < 0.0)) *
             muDoubleScalarMax(muDoubleScalarAbs(xk[idx]), 1.0);
    if (obj->hasLB[idx] || obj->hasUB[idx]) {
      if (obj->hasLB[idx] && obj->hasUB[idx]) {
        modifiedStep =
            fwdFinDiffInsideBnds(xk[idx], lb_data[idx], ub_data[idx], &deltaX);
      } else if (obj->hasUB[idx]) {
        if ((xk[idx] <= ub_data[idx]) && (xk[idx] + deltaX > ub_data[idx])) {
          deltaX = -deltaX;
          modifiedStep = true;
        }
      } else if ((xk[idx] >= lb_data[idx]) &&
                 (xk[idx] + deltaX < lb_data[idx])) {
        deltaX = -deltaX;
        modifiedStep = true;
      }
    }
    t0_objfun_workspace_sys_n = obj->objfun.workspace.sys.n;
    t0_objfun_workspace_sys_Ts = obj->objfun.workspace.sys.Ts;
    t0_objfun_workspace_N = obj->objfun.workspace.N;
    c_t0_nonlin_workspace_obstacles = obj->nonlin.workspace.obstacles.M_l;
    t0_nonlin_workspace_N = obj->nonlin.workspace.N;
    t0_nonlin_workspace_sys_n = obj->nonlin.workspace.sys.n;
    t0_nonlin_workspace_sys_Ts = obj->nonlin.workspace.sys.Ts;
    t0_mIneq = obj->mIneq;
    evalOK = c_finDiffEvalAndChkErr(
        obj->objfun.workspace.x0, t0_objfun_workspace_sys_n,
        t0_objfun_workspace_sys_Ts, t0_objfun_workspace_N,
        obj->objfun.workspace.robotParams.Px, obj->nonlin.workspace.x0,
        c_t0_nonlin_workspace_obstacles,
        obj->nonlin.workspace.obstacles.A_bar_l,
        obj->nonlin.workspace.obstacles.B_bar_l.data,
        obj->nonlin.workspace.obstacles.B_bar_l.size[0], t0_nonlin_workspace_N,
        t0_nonlin_workspace_sys_n, t0_nonlin_workspace_sys_Ts, t0_mIneq,
        obj->cIneq_1.data, &obj->cIneq_1.size[0], idx + 1, deltaX, xk,
        &obj->f_1);
    obj->numEvals++;
    guard1 = false;
    if (!evalOK) {
      if (!modifiedStep) {
        deltaX = -deltaX;
        if (obj->hasLB[idx]) {
          real_T d;
          d = xk[idx] + deltaX;
          if ((d >= lb_data[idx]) && obj->hasUB[idx] && (d <= ub_data[idx])) {
            modifiedStep = true;
          } else {
            modifiedStep = false;
          }
        } else {
          modifiedStep = false;
        }
        if ((!obj->hasBounds) || modifiedStep) {
          evalOK = c_finDiffEvalAndChkErr(
              obj->objfun.workspace.x0, t0_objfun_workspace_sys_n,
              t0_objfun_workspace_sys_Ts, t0_objfun_workspace_N,
              obj->objfun.workspace.robotParams.Px, obj->nonlin.workspace.x0,
              c_t0_nonlin_workspace_obstacles,
              obj->nonlin.workspace.obstacles.A_bar_l,
              obj->nonlin.workspace.obstacles.B_bar_l.data,
              obj->nonlin.workspace.obstacles.B_bar_l.size[0],
              t0_nonlin_workspace_N, t0_nonlin_workspace_sys_n,
              t0_nonlin_workspace_sys_Ts, t0_mIneq, obj->cIneq_1.data,
              &obj->cIneq_1.size[0], idx + 1, deltaX, xk, &obj->f_1);
          obj->numEvals++;
        }
      }
      if (!evalOK) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      gradf_data[idx] = (obj->f_1 - fCurrent) / deltaX;
      t0_mIneq = (uint16_T)obj->mIneq;
      for (idx_row = 0; idx_row < t0_mIneq; idx_row++) {
        JacCineqTrans_data[idx + ldJI * ((CineqColStart + idx_row) - 1)] =
            (obj->cIneq_1.data[idx_row] -
             cIneqCurrent_data[(ineq0 + idx_row) - 1]) /
            deltaX;
      }
      idx++;
    }
  }
  return evalOK;
}

boolean_T computeForwardDifferences(
    p_struct_T *obj, real_T fCurrent, const real_T cIneqCurrent_data[],
    int32_T ineq0, real_T xk[40], real_T gradf_data[],
    emxArray_real_T *JacCineqTrans, int32_T CineqColStart, int32_T ldJI,
    const real_T lb_data[], const real_T ub_data[])
{
  real_T deltaX;
  real_T *JacCineqTrans_data;
  int32_T idx;
  int32_T idx_row;
  boolean_T evalOK;
  boolean_T exitg1;
  JacCineqTrans_data = JacCineqTrans->data;
  evalOK = true;
  obj->numEvals = 0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 40)) {
    real_T c_t1_nonlin_workspace_obstacles;
    real_T t1_nonlin_workspace_N;
    real_T t1_nonlin_workspace_sys_Ts;
    real_T t1_nonlin_workspace_sys_n;
    real_T t1_objfun_workspace_N;
    real_T t1_objfun_workspace_sys_Ts;
    real_T t1_objfun_workspace_sys_n;
    int32_T t1_mIneq;
    boolean_T guard1;
    boolean_T modifiedStep;
    modifiedStep = false;
    deltaX = 1.4901161193847656E-8 * (1.0 - 2.0 * (real_T)(xk[idx] < 0.0)) *
             muDoubleScalarMax(muDoubleScalarAbs(xk[idx]), 1.0);
    if (obj->hasLB[idx] || obj->hasUB[idx]) {
      if (obj->hasLB[idx] && obj->hasUB[idx]) {
        modifiedStep =
            fwdFinDiffInsideBnds(xk[idx], lb_data[idx], ub_data[idx], &deltaX);
      } else if (obj->hasUB[idx]) {
        if ((xk[idx] <= ub_data[idx]) && (xk[idx] + deltaX > ub_data[idx])) {
          deltaX = -deltaX;
          modifiedStep = true;
        }
      } else if ((xk[idx] >= lb_data[idx]) &&
                 (xk[idx] + deltaX < lb_data[idx])) {
        deltaX = -deltaX;
        modifiedStep = true;
      }
    }
    t1_objfun_workspace_sys_n = obj->objfun.workspace.sys.n;
    t1_objfun_workspace_sys_Ts = obj->objfun.workspace.sys.Ts;
    t1_objfun_workspace_N = obj->objfun.workspace.N;
    c_t1_nonlin_workspace_obstacles = obj->nonlin.workspace.obstacles.M_l;
    t1_nonlin_workspace_N = obj->nonlin.workspace.N;
    t1_nonlin_workspace_sys_n = obj->nonlin.workspace.sys.n;
    t1_nonlin_workspace_sys_Ts = obj->nonlin.workspace.sys.Ts;
    t1_mIneq = obj->mIneq;
    evalOK = b_finDiffEvalAndChkErr(
        obj->objfun.workspace.x0, t1_objfun_workspace_sys_n,
        t1_objfun_workspace_sys_Ts, obj->objfun.workspace.robotParams.W,
        obj->objfun.workspace.robotParams.W_hat,
        obj->objfun.workspace.robotParams.R_hat, t1_objfun_workspace_N,
        obj->nonlin.workspace.x0, c_t1_nonlin_workspace_obstacles,
        obj->nonlin.workspace.obstacles.A_bar_l,
        obj->nonlin.workspace.obstacles.B_bar_l.data,
        obj->nonlin.workspace.obstacles.B_bar_l.size[0], t1_nonlin_workspace_N,
        t1_nonlin_workspace_sys_n, t1_nonlin_workspace_sys_Ts, t1_mIneq,
        obj->cIneq_1.data, &obj->cIneq_1.size[0], idx + 1, deltaX, xk,
        &obj->f_1);
    obj->numEvals++;
    guard1 = false;
    if (!evalOK) {
      if (!modifiedStep) {
        deltaX = -deltaX;
        if (obj->hasLB[idx]) {
          real_T d;
          d = xk[idx] + deltaX;
          if ((d >= lb_data[idx]) && obj->hasUB[idx] && (d <= ub_data[idx])) {
            modifiedStep = true;
          } else {
            modifiedStep = false;
          }
        } else {
          modifiedStep = false;
        }
        if ((!obj->hasBounds) || modifiedStep) {
          evalOK = b_finDiffEvalAndChkErr(
              obj->objfun.workspace.x0, t1_objfun_workspace_sys_n,
              t1_objfun_workspace_sys_Ts, obj->objfun.workspace.robotParams.W,
              obj->objfun.workspace.robotParams.W_hat,
              obj->objfun.workspace.robotParams.R_hat, t1_objfun_workspace_N,
              obj->nonlin.workspace.x0, c_t1_nonlin_workspace_obstacles,
              obj->nonlin.workspace.obstacles.A_bar_l,
              obj->nonlin.workspace.obstacles.B_bar_l.data,
              obj->nonlin.workspace.obstacles.B_bar_l.size[0],
              t1_nonlin_workspace_N, t1_nonlin_workspace_sys_n,
              t1_nonlin_workspace_sys_Ts, t1_mIneq, obj->cIneq_1.data,
              &obj->cIneq_1.size[0], idx + 1, deltaX, xk, &obj->f_1);
          obj->numEvals++;
        }
      }
      if (!evalOK) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      gradf_data[idx] = (obj->f_1 - fCurrent) / deltaX;
      t1_mIneq = (uint16_T)obj->mIneq;
      for (idx_row = 0; idx_row < t1_mIneq; idx_row++) {
        JacCineqTrans_data[idx + ldJI * ((CineqColStart + idx_row) - 1)] =
            (obj->cIneq_1.data[idx_row] -
             cIneqCurrent_data[(ineq0 + idx_row) - 1]) /
            deltaX;
      }
      idx++;
    }
  }
  return evalOK;
}

/* End of code generation (computeForwardDifferences.c) */
