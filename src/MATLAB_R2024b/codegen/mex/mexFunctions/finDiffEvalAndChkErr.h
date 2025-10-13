/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * finDiffEvalAndChkErr.h
 *
 * Code generation for function 'finDiffEvalAndChkErr'
 *
 */

#pragma once

/* Include files */
#include "mexFunctions_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
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
    int32_T dim, real_T delta, real_T xk[40], real_T *fplus);

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
    int32_T dim, real_T delta, real_T xk[40], real_T *fplus);

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
    int32_T dim, real_T delta, real_T xk[40], real_T *fplus);

/* End of code generation (finDiffEvalAndChkErr.h) */
