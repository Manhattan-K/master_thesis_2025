/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * finDiffEvalAndChkErr.c
 *
 * Code generation for function 'finDiffEvalAndChkErr'
 *
 */

/* Include files */
#include "finDiffEvalAndChkErr.h"
#include "constraints.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_types.h"
#include "followerMPCandUpdate.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
boolean_T b_finDiffEvalAndChkErr(
    const real_T obj_objfun_workspace_x0[3], real_T obj_objfun_workspace_sys_n,
    real_T obj_objfun_workspace_sys_Ts,
    const real_T c_obj_objfun_workspace_robotPar[9],
    const real_T d_obj_objfun_workspace_robotPar[3600],
    const real_T e_obj_objfun_workspace_robotPar[1600],
    real_T obj_objfun_workspace_N, const real_T obj_nonlin_workspace_x0[3],
    real_T c_obj_nonlin_workspace_obstacle,
    const emxArray_real_T *d_obj_nonlin_workspace_obstacle,
    const real_T e_obj_nonlin_workspace_obstacle[],
    int32_T f_obj_nonlin_workspace_obstacle, real_T obj_nonlin_workspace_N,
    real_T obj_nonlin_workspace_sys_n, real_T obj_nonlin_workspace_sys_Ts,
    int32_T obj_mIneq, real_T cIneqPlus_data[], int32_T *cIneqPlus_size,
    int32_T dim, real_T delta, real_T xk[40], real_T *fplus)
{
  real_T temp_tmp;
  boolean_T evalOK;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  *fplus = leaderMPCandUpdate_anonFcn1(
      obj_objfun_workspace_x0, obj_objfun_workspace_sys_n,
      obj_objfun_workspace_sys_Ts, c_obj_objfun_workspace_robotPar,
      d_obj_objfun_workspace_robotPar, e_obj_objfun_workspace_robotPar,
      obj_objfun_workspace_N, xk);
  evalOK = ((!muDoubleScalarIsInf(*fplus)) && (!muDoubleScalarIsNaN(*fplus)));
  if (evalOK) {
    int32_T idx;
    emlrtMEXProfilingFunctionEntry((char_T *)c_completeName, isMexOutdated);
    *cIneqPlus_size = constraints(
        xk, obj_nonlin_workspace_x0, c_obj_nonlin_workspace_obstacle,
        d_obj_nonlin_workspace_obstacle, e_obj_nonlin_workspace_obstacle,
        f_obj_nonlin_workspace_obstacle, obj_nonlin_workspace_N,
        obj_nonlin_workspace_sys_n, obj_nonlin_workspace_sys_Ts,
        cIneqPlus_data);
    emlrtMEXProfilingFunctionExit(isMexOutdated);
    idx = 0;
    while (evalOK && (idx + 1 <= obj_mIneq)) {
      evalOK = ((!muDoubleScalarIsInf(cIneqPlus_data[idx])) &&
                (!muDoubleScalarIsNaN(cIneqPlus_data[idx])));
      idx++;
    }
    if (evalOK) {
      xk[dim - 1] = temp_tmp;
    }
  }
  return evalOK;
}

boolean_T c_finDiffEvalAndChkErr(
    const real_T obj_objfun_workspace_x0[3], real_T obj_objfun_workspace_sys_n,
    real_T obj_objfun_workspace_sys_Ts, real_T obj_objfun_workspace_N,
    const real_T c_obj_objfun_workspace_robotPar[6],
    const real_T obj_nonlin_workspace_x0[3],
    real_T c_obj_nonlin_workspace_obstacle,
    const emxArray_real_T *d_obj_nonlin_workspace_obstacle,
    const real_T e_obj_nonlin_workspace_obstacle[],
    int32_T f_obj_nonlin_workspace_obstacle, real_T obj_nonlin_workspace_N,
    real_T obj_nonlin_workspace_sys_n, real_T obj_nonlin_workspace_sys_Ts,
    int32_T obj_mIneq, real_T cIneqPlus_data[], int32_T *cIneqPlus_size,
    int32_T dim, real_T delta, real_T xk[40], real_T *fplus)
{
  real_T temp_tmp;
  boolean_T evalOK;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  *fplus = leaderMPCandUpdateHalt_anonFcn1(
      obj_objfun_workspace_x0, obj_objfun_workspace_sys_n,
      obj_objfun_workspace_sys_Ts, obj_objfun_workspace_N,
      c_obj_objfun_workspace_robotPar, xk);
  evalOK = ((!muDoubleScalarIsInf(*fplus)) && (!muDoubleScalarIsNaN(*fplus)));
  if (evalOK) {
    int32_T idx;
    emlrtMEXProfilingFunctionEntry((char_T *)e_completeName, isMexOutdated);
    *cIneqPlus_size = constraints(
        xk, obj_nonlin_workspace_x0, c_obj_nonlin_workspace_obstacle,
        d_obj_nonlin_workspace_obstacle, e_obj_nonlin_workspace_obstacle,
        f_obj_nonlin_workspace_obstacle, obj_nonlin_workspace_N,
        obj_nonlin_workspace_sys_n, obj_nonlin_workspace_sys_Ts,
        cIneqPlus_data);
    emlrtMEXProfilingFunctionExit(isMexOutdated);
    idx = 0;
    while (evalOK && (idx + 1 <= obj_mIneq)) {
      evalOK = ((!muDoubleScalarIsInf(cIneqPlus_data[idx])) &&
                (!muDoubleScalarIsNaN(cIneqPlus_data[idx])));
      idx++;
    }
    if (evalOK) {
      xk[dim - 1] = temp_tmp;
    }
  }
  return evalOK;
}

boolean_T finDiffEvalAndChkErr(
    const real_T obj_objfun_workspace_x0[3], real_T obj_objfun_workspace_sys_n,
    real_T obj_objfun_workspace_sys_Ts, real_T obj_objfun_workspace_N,
    const real_T c_obj_objfun_workspace_X_L_stac[60],
    const real_T c_obj_objfun_workspace_robotPar[6],
    const real_T d_obj_objfun_workspace_robotPar[20],
    real_T e_obj_objfun_workspace_robotPar,
    const real_T f_obj_objfun_workspace_robotPar[20],
    const real_T obj_nonlin_workspace_x0[3],
    real_T c_obj_nonlin_workspace_obstacle,
    const emxArray_real_T *d_obj_nonlin_workspace_obstacle,
    const real_T e_obj_nonlin_workspace_obstacle[],
    int32_T f_obj_nonlin_workspace_obstacle, real_T obj_nonlin_workspace_N,
    real_T obj_nonlin_workspace_sys_n, real_T obj_nonlin_workspace_sys_Ts,
    int32_T obj_mIneq, real_T cIneqPlus_data[], int32_T *cIneqPlus_size,
    int32_T dim, real_T delta, real_T xk[40], real_T *fplus)
{
  real_T temp_tmp;
  boolean_T evalOK;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  *fplus = followerMPCandUpdate_anonFcn1(
      obj_objfun_workspace_x0, obj_objfun_workspace_sys_n,
      obj_objfun_workspace_sys_Ts, obj_objfun_workspace_N,
      c_obj_objfun_workspace_X_L_stac, c_obj_objfun_workspace_robotPar,
      d_obj_objfun_workspace_robotPar, e_obj_objfun_workspace_robotPar,
      f_obj_objfun_workspace_robotPar, xk);
  evalOK = ((!muDoubleScalarIsInf(*fplus)) && (!muDoubleScalarIsNaN(*fplus)));
  if (evalOK) {
    int32_T idx;
    *cIneqPlus_size = followerMPCandUpdate_anonFcn2(
        obj_nonlin_workspace_x0, c_obj_nonlin_workspace_obstacle,
        d_obj_nonlin_workspace_obstacle, e_obj_nonlin_workspace_obstacle,
        f_obj_nonlin_workspace_obstacle, obj_nonlin_workspace_N,
        obj_nonlin_workspace_sys_n, obj_nonlin_workspace_sys_Ts, xk,
        cIneqPlus_data);
    idx = 0;
    while (evalOK && (idx + 1 <= obj_mIneq)) {
      evalOK = ((!muDoubleScalarIsInf(cIneqPlus_data[idx])) &&
                (!muDoubleScalarIsNaN(cIneqPlus_data[idx])));
      idx++;
    }
    if (evalOK) {
      xk[dim - 1] = temp_tmp;
    }
  }
  return evalOK;
}

/* End of code generation (finDiffEvalAndChkErr.c) */
