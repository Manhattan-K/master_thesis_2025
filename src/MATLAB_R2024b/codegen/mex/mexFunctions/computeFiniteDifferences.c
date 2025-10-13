/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeFiniteDifferences.c
 *
 * Code generation for function 'computeFiniteDifferences'
 *
 */

/* Include files */
#include "computeFiniteDifferences.h"
#include "finDiffEvalAndChkErr.h"
#include "fwdFinDiffInsideBnds.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
boolean_T computeFiniteDifferences(l_struct_T *obj, real_T fCurrent,
                                   const real_T cIneqCurrent_data[],
                                   int32_T ineq0, real_T xk[40],
                                   real_T gradf_data[],
                                   emxArray_real_T *JacCineqTrans,
                                   int32_T CineqColStart, int32_T ldJI,
                                   const real_T lb[40], const real_T ub[40])
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
    real_T c_t2_nonlin_workspace_obstacles;
    real_T c_t2_objfun_workspace_robotPara;
    real_T t2_nonlin_workspace_N;
    real_T t2_nonlin_workspace_sys_Ts;
    real_T t2_nonlin_workspace_sys_n;
    real_T t2_objfun_workspace_N;
    real_T t2_objfun_workspace_sys_Ts;
    real_T t2_objfun_workspace_sys_n;
    int32_T t2_mIneq;
    boolean_T guard1;
    boolean_T modifiedStep;
    modifiedStep = false;
    deltaX = 1.4901161193847656E-8 * (1.0 - 2.0 * (real_T)(xk[idx] < 0.0)) *
             muDoubleScalarMax(muDoubleScalarAbs(xk[idx]), 1.0);
    if (obj->hasLB[idx] || obj->hasUB[idx]) {
      if (obj->hasLB[idx] && obj->hasUB[idx]) {
        modifiedStep = fwdFinDiffInsideBnds(xk[idx], lb[idx], ub[idx], &deltaX);
      } else if (obj->hasUB[idx]) {
        if ((xk[idx] <= ub[idx]) && (xk[idx] + deltaX > ub[idx])) {
          deltaX = -deltaX;
          modifiedStep = true;
        }
      } else if ((xk[idx] >= lb[idx]) && (xk[idx] + deltaX < lb[idx])) {
        deltaX = -deltaX;
        modifiedStep = true;
      }
    }
    t2_objfun_workspace_sys_n = obj->objfun.workspace.sys.n;
    t2_objfun_workspace_sys_Ts = obj->objfun.workspace.sys.Ts;
    t2_objfun_workspace_N = obj->objfun.workspace.N;
    c_t2_objfun_workspace_robotPara = obj->objfun.workspace.robotParams.C;
    c_t2_nonlin_workspace_obstacles = obj->nonlin.workspace.obstacles.M_f;
    t2_nonlin_workspace_N = obj->nonlin.workspace.N;
    t2_nonlin_workspace_sys_n = obj->nonlin.workspace.sys.n;
    t2_nonlin_workspace_sys_Ts = obj->nonlin.workspace.sys.Ts;
    t2_mIneq = obj->mIneq;
    evalOK = finDiffEvalAndChkErr(
        obj->objfun.workspace.x0, t2_objfun_workspace_sys_n,
        t2_objfun_workspace_sys_Ts, t2_objfun_workspace_N,
        obj->objfun.workspace.X_L_stacked, obj->objfun.workspace.robotParams.Px,
        obj->objfun.workspace.robotParams.d_FL_sq,
        c_t2_objfun_workspace_robotPara,
        obj->objfun.workspace.robotParams.beta_N, obj->nonlin.workspace.x0,
        c_t2_nonlin_workspace_obstacles,
        obj->nonlin.workspace.obstacles.A_bar_f,
        obj->nonlin.workspace.obstacles.B_bar_f.data,
        obj->nonlin.workspace.obstacles.B_bar_f.size[0], t2_nonlin_workspace_N,
        t2_nonlin_workspace_sys_n, t2_nonlin_workspace_sys_Ts, t2_mIneq,
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
          if ((d >= lb[idx]) && obj->hasUB[idx] && (d <= ub[idx])) {
            modifiedStep = true;
          } else {
            modifiedStep = false;
          }
        } else {
          modifiedStep = false;
        }
        if ((!obj->hasBounds) || modifiedStep) {
          evalOK = finDiffEvalAndChkErr(
              obj->objfun.workspace.x0, t2_objfun_workspace_sys_n,
              t2_objfun_workspace_sys_Ts, t2_objfun_workspace_N,
              obj->objfun.workspace.X_L_stacked,
              obj->objfun.workspace.robotParams.Px,
              obj->objfun.workspace.robotParams.d_FL_sq,
              c_t2_objfun_workspace_robotPara,
              obj->objfun.workspace.robotParams.beta_N,
              obj->nonlin.workspace.x0, c_t2_nonlin_workspace_obstacles,
              obj->nonlin.workspace.obstacles.A_bar_f,
              obj->nonlin.workspace.obstacles.B_bar_f.data,
              obj->nonlin.workspace.obstacles.B_bar_f.size[0],
              t2_nonlin_workspace_N, t2_nonlin_workspace_sys_n,
              t2_nonlin_workspace_sys_Ts, t2_mIneq, obj->cIneq_1.data,
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
      t2_mIneq = (uint16_T)obj->mIneq;
      for (idx_row = 0; idx_row < t2_mIneq; idx_row++) {
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

/* End of code generation (computeFiniteDifferences.c) */
