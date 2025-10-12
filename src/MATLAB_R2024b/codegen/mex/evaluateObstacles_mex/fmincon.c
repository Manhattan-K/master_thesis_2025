/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fmincon.c
 *
 * Code generation for function 'fmincon'
 *
 */

/* Include files */
#include "fmincon.h"
#include "checkLinearInputs.h"
#include "compressBounds.h"
#include "computeConstraints_.h"
#include "computeFiniteDifferences.h"
#include "computeForwardDifferences.h"
#include "constraints.h"
#include "driver.h"
#include "evalObjAndConstrAndDerivatives.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_internal_types.h"
#include "evaluateObstacles_mex_types.h"
#include "factoryConstruct.h"
#include "factoryConstruct1.h"
#include "factoryConstruct2.h"
#include "factoryConstruct3.h"
#include "fillOutputStruct.h"
#include "followerMPCandUpdate.h"
#include "hasFiniteBounds.h"
#include "initActiveSet.h"
#include "loadProblem.h"
#include "rt_nonfinite.h"
#include "updateWorkingSetForNewQP.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T b_fmincon(evaluateObstacles_mexStackData *SD,
                 const real_T fun_workspace_x0[3], real_T fun_workspace_sys_n,
                 real_T fun_workspace_sys_m, real_T fun_workspace_sys_Ts,
                 const struct1_T *fun_workspace_robotParams,
                 real_T fun_workspace_N, real_T x0[40], const real_T lb_data[],
                 const int32_T lb_size[2], const real_T ub_data[],
                 const int32_T ub_size[2], const real_T nonlcon_workspace_x0[3],
                 const struct5_T *nonlcon_workspace_obstacles,
                 real_T nonlcon_workspace_N,
                 const struct3_T nonlcon_workspace_sys, real_T *exitflag,
                 real_T *output_iterations, real_T *output_funcCount,
                 char_T output_algorithm[3], real_T *output_constrviolation,
                 real_T *output_stepsize, real_T *output_lssteplength,
                 real_T *output_firstorderopt)
{
  l_struct_T MeritFunction;
  n_struct_T obj;
  real_T unusedExpr[1600];
  real_T fval;
  int32_T i;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVarMax;
  int16_T varargout_1_size_idx_0;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  *exitflag = checkLinearInputs(lb_data, lb_size, ub_data, ub_size);
  emlrtMEXProfilingFunctionEntry((char_T *)c_completeName, isMexOutdated);
  emxInitStruct_struct_T1(&SD->u2.f2.TrialState);
  SD->u2.f2.TrialState.cIneq.size[0] =
      constraints(x0, nonlcon_workspace_x0, nonlcon_workspace_obstacles->M_l,
                  nonlcon_workspace_obstacles->A_bar_l,
                  nonlcon_workspace_obstacles->B_bar_l.data,
                  nonlcon_workspace_obstacles->B_bar_l.size[0],
                  nonlcon_workspace_N, nonlcon_workspace_sys.n,
                  nonlcon_workspace_sys.Ts, SD->u2.f2.TrialState.cIneq.data);
  varargout_1_size_idx_0 = (int16_T)SD->u2.f2.TrialState.cIneq.size[0];
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  mConstrMax =
      (((SD->u2.f2.TrialState.cIneq.size[0] + lb_size[0] * lb_size[1]) +
        ub_size[0] * ub_size[1]) +
       SD->u2.f2.TrialState.cIneq.size[0]) +
      1;
  nVarMax = SD->u2.f2.TrialState.cIneq.size[0] + 41;
  maxDims = muIntScalarMax_sint32(nVarMax, mConstrMax);
  if (*exitflag == -2.0) {
    fval = rtInf;
    *output_iterations = 0.0;
    *output_funcCount = 0.0;
    output_algorithm[0] = 's';
    output_algorithm[1] = 'q';
    output_algorithm[2] = 'p';
    *output_constrviolation = rtInf;
    *output_stepsize = rtInf;
    *output_lssteplength = rtInf;
    *output_firstorderopt = rtInf;
  } else {
    int32_T mLB;
    factoryConstruct(SD->u2.f2.TrialState.cIneq.size[0] + 41, mConstrMax,
                     SD->u2.f2.TrialState.cIneq.size[0],
                     SD->u2.f2.TrialState.cIneq.size[0], &SD->u2.f2.TrialState);
    memcpy(&SD->u2.f2.TrialState.xstarsqp[0], &x0[0], 40U * sizeof(real_T));
    l_emxInitStruct_coder_internal_(&SD->u2.f2.FcnEvaluator);
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.value =
        varargout_1_size_idx_0;
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.sys.n = fun_workspace_sys_n;
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.sys.m = fun_workspace_sys_m;
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.sys.Ts = fun_workspace_sys_Ts;
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.robotParams = *fun_workspace_robotParams;
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.N = fun_workspace_N;
    emxCopyStruct_struct5_T(&SD->u2.f2.FcnEvaluator.next.next.next.next.next
                                 .next.next.value.workspace.obstacles,
                            nonlcon_workspace_obstacles);
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .N = nonlcon_workspace_N;
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .sys = nonlcon_workspace_sys;
    emxInitStruct_struct_T10(&SD->u2.f2.FiniteDifferences);
    SD->u2.f2.FiniteDifferences.objfun.workspace.sys.n = fun_workspace_sys_n;
    SD->u2.f2.FiniteDifferences.objfun.workspace.sys.Ts = fun_workspace_sys_Ts;
    SD->u2.f2.FiniteDifferences.objfun.workspace.robotParams =
        *fun_workspace_robotParams;
    SD->u2.f2.FiniteDifferences.objfun.workspace.N = fun_workspace_N;
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[0] = nonlcon_workspace_x0[0];
    SD->u2.f2.FiniteDifferences.objfun.workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f2.FiniteDifferences.nonlin.workspace.x0[0] =
        nonlcon_workspace_x0[0];
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[1] = nonlcon_workspace_x0[1];
    SD->u2.f2.FiniteDifferences.objfun.workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f2.FiniteDifferences.nonlin.workspace.x0[1] =
        nonlcon_workspace_x0[1];
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[2] = fun_workspace_x0[2];
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[2] = nonlcon_workspace_x0[2];
    SD->u2.f2.FiniteDifferences.objfun.workspace.x0[2] = fun_workspace_x0[2];
    SD->u2.f2.FiniteDifferences.nonlin.workspace.x0[2] =
        nonlcon_workspace_x0[2];
    emxCopyStruct_struct5_T(
        &SD->u2.f2.FiniteDifferences.nonlin.workspace.obstacles,
        nonlcon_workspace_obstacles);
    SD->u2.f2.FiniteDifferences.nonlin.workspace.N = nonlcon_workspace_N;
    SD->u2.f2.FiniteDifferences.nonlin.workspace.sys = nonlcon_workspace_sys;
    SD->u2.f2.FiniteDifferences.f_1 = 0.0;
    SD->u2.f2.FiniteDifferences.cIneq_1.size[0] = varargout_1_size_idx_0;
    SD->u2.f2.FiniteDifferences.mIneq = varargout_1_size_idx_0;
    SD->u2.f2.FiniteDifferences.numEvals = 0;
    SD->u2.f2.FiniteDifferences.hasBounds = hasFiniteBounds(
        SD->u2.f2.FiniteDifferences.hasLB, SD->u2.f2.FiniteDifferences.hasUB,
        lb_data, lb_size, ub_data, ub_size);
    SD->u2.f2.QPObjective.grad.size[0] = b_factoryConstruct(
        varargout_1_size_idx_0 + 41, &SD->u2.f2.QPObjective.Hx.size[0],
        &SD->u2.f2.QPObjective.hasLinear, &SD->u2.f2.QPObjective.nvar,
        &SD->u2.f2.QPObjective.maxVar, &SD->u2.f2.QPObjective.beta,
        &SD->u2.f2.QPObjective.rho, &SD->u2.f2.QPObjective.objtype,
        &SD->u2.f2.QPObjective.prev_objtype, &SD->u2.f2.QPObjective.prev_nvar,
        &SD->u2.f2.QPObjective.prev_hasLinear,
        &SD->u2.f2.QPObjective.gammaScalar);
    SD->u2.f2.QPObjective.hasLinear = true;
    SD->u2.f2.QPObjective.nvar = 40;
    SD->u2.f2.QPObjective.objtype = 3;
    emxInitStruct_struct_T5(&SD->u2.f2.memspace);
    i = SD->u2.f2.memspace.workspace_float->size[0] *
        SD->u2.f2.memspace.workspace_float->size[1];
    SD->u2.f2.memspace.workspace_float->size[0] = maxDims;
    SD->u2.f2.memspace.workspace_float->size[1] = varargout_1_size_idx_0 + 41;
    emxEnsureCapacity_real_T(SD->u2.f2.memspace.workspace_float, i);
    SD->u2.f2.memspace.workspace_int.size[0] = maxDims;
    SD->u2.f2.memspace.workspace_sort.size[0] = maxDims;
    emxInitStruct_struct_T(&SD->u2.f2.WorkingSet);
    c_factoryConstruct(varargout_1_size_idx_0, varargout_1_size_idx_0 + 41,
                       mConstrMax, &SD->u2.f2.WorkingSet);
    mLB = compressBounds(SD->u2.f2.WorkingSet.indexLB.data,
                         SD->u2.f2.WorkingSet.indexUB.data,
                         SD->u2.f2.WorkingSet.indexFixed.data, lb_data, lb_size,
                         ub_data, ub_size, &mUB, &mFixed);
    loadProblem(&SD->u2.f2.WorkingSet, varargout_1_size_idx_0, mLB, mUB, mFixed,
                mConstrMax);
    if ((lb_size[0] != 0) && (lb_size[1] != 0)) {
      i = (uint16_T)mLB;
      for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
        nVarMax = SD->u2.f2.WorkingSet.indexLB.data[mConstrMax];
        SD->u2.f2.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMax(
            SD->u2.f2.TrialState.xstarsqp[nVarMax - 1], lb_data[nVarMax - 1]);
      }
    }
    if ((ub_size[0] != 0) && (ub_size[1] != 0)) {
      i = (uint16_T)mUB;
      for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
        nVarMax = SD->u2.f2.WorkingSet.indexUB.data[mConstrMax];
        SD->u2.f2.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMin(
            SD->u2.f2.TrialState.xstarsqp[nVarMax - 1], ub_data[nVarMax - 1]);
      }
      i = (uint16_T)mFixed;
      for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
        nVarMax = SD->u2.f2.WorkingSet.indexFixed.data[mConstrMax];
        SD->u2.f2.TrialState.xstarsqp[nVarMax - 1] = ub_data[nVarMax - 1];
      }
    }
    SD->u2.f2.TrialState.sqpFval = evalObjAndConstrAndDerivatives(
        varargout_1_size_idx_0,
        SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value
            .workspace.x0,
        nonlcon_workspace_obstacles, nonlcon_workspace_N, nonlcon_workspace_sys,
        &SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
             .workspace,
        SD->u2.f2.TrialState.xstarsqp, SD->u2.f2.TrialState.cIneq.data,
        &SD->u2.f2.TrialState.cIneq.size[0], SD->u2.f2.TrialState.iNonIneq0,
        &nVarMax);
    computeForwardDifferences(
        &SD->u2.f2.FiniteDifferences, SD->u2.f2.TrialState.sqpFval,
        SD->u2.f2.TrialState.cIneq.data, SD->u2.f2.TrialState.iNonIneq0,
        SD->u2.f2.TrialState.xstarsqp, SD->u2.f2.TrialState.grad.data,
        SD->u2.f2.WorkingSet.Aineq, SD->u2.f2.TrialState.iNonIneq0,
        SD->u2.f2.WorkingSet.ldA, lb_data, ub_data);
    SD->u2.f2.TrialState.FunctionEvaluations =
        SD->u2.f2.FiniteDifferences.numEvals + 1;
    updateWorkingSetForNewQP(x0, &SD->u2.f2.WorkingSet, varargout_1_size_idx_0,
                             SD->u2.f2.TrialState.cIneq.data, mLB, lb_data,
                             lb_size, mUB, ub_data, ub_size, mFixed);
    initActiveSet(&SD->u2.f2.WorkingSet);
    d_factoryConstruct(SD->u2.f2.TrialState.sqpFval,
                       SD->u2.f2.TrialState.cIneq.data, varargout_1_size_idx_0,
                       &MeritFunction);
    emxInitStruct_struct_T6(&SD->u2.f2.obj);
    SD->u2.f2.obj.ldq = maxDims;
    i = SD->u2.f2.obj.QR->size[0] * SD->u2.f2.obj.QR->size[1];
    SD->u2.f2.obj.QR->size[0] = maxDims;
    SD->u2.f2.obj.QR->size[1] = maxDims;
    emxEnsureCapacity_real_T(SD->u2.f2.obj.QR, i);
    i = SD->u2.f2.obj.Q->size[0] * SD->u2.f2.obj.Q->size[1];
    SD->u2.f2.obj.Q->size[0] = maxDims;
    SD->u2.f2.obj.Q->size[1] = maxDims;
    emxEnsureCapacity_real_T(SD->u2.f2.obj.Q, i);
    nVarMax = maxDims * maxDims;
    for (i = 0; i < nVarMax; i++) {
      SD->u2.f2.obj.Q->data[i] = 0.0;
    }
    SD->u2.f2.obj.jpvt.size[0] = maxDims;
    memset(&SD->u2.f2.obj.jpvt.data[0], 0, (uint32_T)maxDims * sizeof(int32_T));
    SD->u2.f2.obj.mrows = 0;
    SD->u2.f2.obj.ncols = 0;
    i = SD->u2.f2.obj.tau->size[0];
    SD->u2.f2.obj.tau->size[0] = muIntScalarMin_sint32(maxDims, maxDims);
    emxEnsureCapacity_real_T(SD->u2.f2.obj.tau, i);
    SD->u2.f2.obj.minRowCol = 0;
    SD->u2.f2.obj.usedPivoting = false;
    emxInitStruct_struct_T7(&obj);
    i = obj.FMat->size[0] * obj.FMat->size[1];
    obj.FMat->size[0] = maxDims;
    obj.FMat->size[1] = maxDims;
    emxEnsureCapacity_real_T(obj.FMat, i);
    obj.ldm = maxDims;
    obj.ndims = 0;
    obj.info = 0;
    obj.ConvexCheck = true;
    obj.workspace_ = rtInf;
    obj.workspace2_ = rtInf;
    c_driver(SD, lb_data, lb_size, ub_data, ub_size, &SD->u2.f2.TrialState,
             &MeritFunction, &SD->u2.f2.FcnEvaluator,
             &SD->u2.f2.FiniteDifferences, &SD->u2.f2.memspace,
             &SD->u2.f2.WorkingSet, &SD->u2.f2.obj, &obj,
             &SD->u2.f2.QPObjective, varargout_1_size_idx_0, unusedExpr);
    emxFreeStruct_struct_T6(&obj);
    emxFreeStruct_struct_T5(&SD->u2.f2.obj);
    emxFreeStruct_struct_T(&SD->u2.f2.WorkingSet);
    emxFreeStruct_struct_T4(&SD->u2.f2.memspace);
    emxFreeStruct_struct_T8(&SD->u2.f2.FiniteDifferences);
    r_emxFreeStruct_coder_internal_(&SD->u2.f2.FcnEvaluator);
    memcpy(&x0[0], &SD->u2.f2.TrialState.xstarsqp[0], 40U * sizeof(real_T));
    fval = SD->u2.f2.TrialState.sqpFval;
    *exitflag = SD->u2.f2.TrialState.sqpExitFlag;
    *output_iterations = fillOutputStruct(
        SD->u2.f2.TrialState.FunctionEvaluations,
        SD->u2.f2.TrialState.sqpIterations, SD->u2.f2.TrialState.steplength,
        SD->u2.f2.TrialState.delta_x.data, MeritFunction.nlpPrimalFeasError,
        MeritFunction.firstOrderOpt, output_funcCount, output_algorithm,
        output_constrviolation, output_stepsize, output_lssteplength,
        output_firstorderopt);
  }
  emxFreeStruct_struct_T1(&SD->u2.f2.TrialState);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

real_T c_fmincon(evaluateObstacles_mexStackData *SD,
                 const real_T fun_workspace_x0[3], real_T fun_workspace_sys_n,
                 real_T fun_workspace_sys_m, real_T fun_workspace_sys_Ts,
                 real_T fun_workspace_N,
                 const struct1_T *fun_workspace_robotParams, real_T x0[40],
                 const real_T lb_data[], const int32_T lb_size[2],
                 const real_T ub_data[], const int32_T ub_size[2],
                 const real_T nonlcon_workspace_x0[3],
                 const struct5_T *nonlcon_workspace_obstacles,
                 real_T nonlcon_workspace_N,
                 const struct3_T nonlcon_workspace_sys, real_T *exitflag,
                 real_T *output_iterations, real_T *output_funcCount,
                 char_T output_algorithm[3], real_T *output_constrviolation,
                 real_T *output_stepsize, real_T *output_lssteplength,
                 real_T *output_firstorderopt)
{
  l_struct_T MeritFunction;
  n_struct_T obj;
  real_T unusedExpr[1600];
  real_T fval;
  int32_T i;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVarMax;
  int16_T varargout_1_size_idx_0;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  *exitflag = checkLinearInputs(lb_data, lb_size, ub_data, ub_size);
  emlrtMEXProfilingFunctionEntry((char_T *)e_completeName, isMexOutdated);
  emxInitStruct_struct_T1(&SD->u2.f3.TrialState);
  SD->u2.f3.TrialState.cIneq.size[0] =
      constraints(x0, nonlcon_workspace_x0, nonlcon_workspace_obstacles->M_l,
                  nonlcon_workspace_obstacles->A_bar_l,
                  nonlcon_workspace_obstacles->B_bar_l.data,
                  nonlcon_workspace_obstacles->B_bar_l.size[0],
                  nonlcon_workspace_N, nonlcon_workspace_sys.n,
                  nonlcon_workspace_sys.Ts, SD->u2.f3.TrialState.cIneq.data);
  varargout_1_size_idx_0 = (int16_T)SD->u2.f3.TrialState.cIneq.size[0];
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  mConstrMax =
      (((SD->u2.f3.TrialState.cIneq.size[0] + lb_size[0] * lb_size[1]) +
        ub_size[0] * ub_size[1]) +
       SD->u2.f3.TrialState.cIneq.size[0]) +
      1;
  nVarMax = SD->u2.f3.TrialState.cIneq.size[0] + 41;
  maxDims = muIntScalarMax_sint32(nVarMax, mConstrMax);
  if (*exitflag == -2.0) {
    fval = rtInf;
    *output_iterations = 0.0;
    *output_funcCount = 0.0;
    output_algorithm[0] = 's';
    output_algorithm[1] = 'q';
    output_algorithm[2] = 'p';
    *output_constrviolation = rtInf;
    *output_stepsize = rtInf;
    *output_lssteplength = rtInf;
    *output_firstorderopt = rtInf;
  } else {
    int32_T mLB;
    factoryConstruct(SD->u2.f3.TrialState.cIneq.size[0] + 41, mConstrMax,
                     SD->u2.f3.TrialState.cIneq.size[0],
                     SD->u2.f3.TrialState.cIneq.size[0], &SD->u2.f3.TrialState);
    memcpy(&SD->u2.f3.TrialState.xstarsqp[0], &x0[0], 40U * sizeof(real_T));
    u_emxInitStruct_coder_internal_(&SD->u2.f3.FcnEvaluator);
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.value =
        varargout_1_size_idx_0;
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.sys.n = fun_workspace_sys_n;
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.sys.m = fun_workspace_sys_m;
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.sys.Ts = fun_workspace_sys_Ts;
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.N = fun_workspace_N;
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.robotParams = *fun_workspace_robotParams;
    emxCopyStruct_struct5_T(&SD->u2.f3.FcnEvaluator.next.next.next.next.next
                                 .next.next.value.workspace.obstacles,
                            nonlcon_workspace_obstacles);
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .N = nonlcon_workspace_N;
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .sys = nonlcon_workspace_sys;
    emxInitStruct_struct_T12(&SD->u2.f3.FiniteDifferences);
    SD->u2.f3.FiniteDifferences.objfun.workspace.sys.n = fun_workspace_sys_n;
    SD->u2.f3.FiniteDifferences.objfun.workspace.sys.Ts = fun_workspace_sys_Ts;
    SD->u2.f3.FiniteDifferences.objfun.workspace.N = fun_workspace_N;
    SD->u2.f3.FiniteDifferences.objfun.workspace.robotParams =
        *fun_workspace_robotParams;
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[0] = nonlcon_workspace_x0[0];
    SD->u2.f3.FiniteDifferences.objfun.workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f3.FiniteDifferences.nonlin.workspace.x0[0] =
        nonlcon_workspace_x0[0];
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[1] = nonlcon_workspace_x0[1];
    SD->u2.f3.FiniteDifferences.objfun.workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f3.FiniteDifferences.nonlin.workspace.x0[1] =
        nonlcon_workspace_x0[1];
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[2] = fun_workspace_x0[2];
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[2] = nonlcon_workspace_x0[2];
    SD->u2.f3.FiniteDifferences.objfun.workspace.x0[2] = fun_workspace_x0[2];
    SD->u2.f3.FiniteDifferences.nonlin.workspace.x0[2] =
        nonlcon_workspace_x0[2];
    emxCopyStruct_struct5_T(
        &SD->u2.f3.FiniteDifferences.nonlin.workspace.obstacles,
        nonlcon_workspace_obstacles);
    SD->u2.f3.FiniteDifferences.nonlin.workspace.N = nonlcon_workspace_N;
    SD->u2.f3.FiniteDifferences.nonlin.workspace.sys = nonlcon_workspace_sys;
    SD->u2.f3.FiniteDifferences.f_1 = 0.0;
    SD->u2.f3.FiniteDifferences.cIneq_1.size[0] = varargout_1_size_idx_0;
    SD->u2.f3.FiniteDifferences.mIneq = varargout_1_size_idx_0;
    SD->u2.f3.FiniteDifferences.numEvals = 0;
    SD->u2.f3.FiniteDifferences.hasBounds = hasFiniteBounds(
        SD->u2.f3.FiniteDifferences.hasLB, SD->u2.f3.FiniteDifferences.hasUB,
        lb_data, lb_size, ub_data, ub_size);
    SD->u2.f3.QPObjective.grad.size[0] = b_factoryConstruct(
        varargout_1_size_idx_0 + 41, &SD->u2.f3.QPObjective.Hx.size[0],
        &SD->u2.f3.QPObjective.hasLinear, &SD->u2.f3.QPObjective.nvar,
        &SD->u2.f3.QPObjective.maxVar, &SD->u2.f3.QPObjective.beta,
        &SD->u2.f3.QPObjective.rho, &SD->u2.f3.QPObjective.objtype,
        &SD->u2.f3.QPObjective.prev_objtype, &SD->u2.f3.QPObjective.prev_nvar,
        &SD->u2.f3.QPObjective.prev_hasLinear,
        &SD->u2.f3.QPObjective.gammaScalar);
    SD->u2.f3.QPObjective.hasLinear = true;
    SD->u2.f3.QPObjective.nvar = 40;
    SD->u2.f3.QPObjective.objtype = 3;
    emxInitStruct_struct_T5(&SD->u2.f3.memspace);
    i = SD->u2.f3.memspace.workspace_float->size[0] *
        SD->u2.f3.memspace.workspace_float->size[1];
    SD->u2.f3.memspace.workspace_float->size[0] = maxDims;
    SD->u2.f3.memspace.workspace_float->size[1] = varargout_1_size_idx_0 + 41;
    emxEnsureCapacity_real_T(SD->u2.f3.memspace.workspace_float, i);
    SD->u2.f3.memspace.workspace_int.size[0] = maxDims;
    SD->u2.f3.memspace.workspace_sort.size[0] = maxDims;
    emxInitStruct_struct_T(&SD->u2.f3.WorkingSet);
    c_factoryConstruct(varargout_1_size_idx_0, varargout_1_size_idx_0 + 41,
                       mConstrMax, &SD->u2.f3.WorkingSet);
    mLB = compressBounds(SD->u2.f3.WorkingSet.indexLB.data,
                         SD->u2.f3.WorkingSet.indexUB.data,
                         SD->u2.f3.WorkingSet.indexFixed.data, lb_data, lb_size,
                         ub_data, ub_size, &mUB, &mFixed);
    loadProblem(&SD->u2.f3.WorkingSet, varargout_1_size_idx_0, mLB, mUB, mFixed,
                mConstrMax);
    if ((lb_size[0] != 0) && (lb_size[1] != 0)) {
      i = (uint16_T)mLB;
      for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
        nVarMax = SD->u2.f3.WorkingSet.indexLB.data[mConstrMax];
        SD->u2.f3.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMax(
            SD->u2.f3.TrialState.xstarsqp[nVarMax - 1], lb_data[nVarMax - 1]);
      }
    }
    if ((ub_size[0] != 0) && (ub_size[1] != 0)) {
      i = (uint16_T)mUB;
      for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
        nVarMax = SD->u2.f3.WorkingSet.indexUB.data[mConstrMax];
        SD->u2.f3.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMin(
            SD->u2.f3.TrialState.xstarsqp[nVarMax - 1], ub_data[nVarMax - 1]);
      }
      i = (uint16_T)mFixed;
      for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
        nVarMax = SD->u2.f3.WorkingSet.indexFixed.data[mConstrMax];
        SD->u2.f3.TrialState.xstarsqp[nVarMax - 1] = ub_data[nVarMax - 1];
      }
    }
    SD->u2.f3.TrialState.sqpFval = b_evalObjAndConstrAndDerivative(
        varargout_1_size_idx_0,
        SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value
            .workspace.x0,
        nonlcon_workspace_obstacles, nonlcon_workspace_N, nonlcon_workspace_sys,
        &SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
             .workspace,
        SD->u2.f3.TrialState.xstarsqp, SD->u2.f3.TrialState.cIneq.data,
        &SD->u2.f3.TrialState.cIneq.size[0], SD->u2.f3.TrialState.iNonIneq0,
        &nVarMax);
    b_computeForwardDifferences(
        &SD->u2.f3.FiniteDifferences, SD->u2.f3.TrialState.sqpFval,
        SD->u2.f3.TrialState.cIneq.data, SD->u2.f3.TrialState.iNonIneq0,
        SD->u2.f3.TrialState.xstarsqp, SD->u2.f3.TrialState.grad.data,
        SD->u2.f3.WorkingSet.Aineq, SD->u2.f3.TrialState.iNonIneq0,
        SD->u2.f3.WorkingSet.ldA, lb_data, ub_data);
    SD->u2.f3.TrialState.FunctionEvaluations =
        SD->u2.f3.FiniteDifferences.numEvals + 1;
    updateWorkingSetForNewQP(x0, &SD->u2.f3.WorkingSet, varargout_1_size_idx_0,
                             SD->u2.f3.TrialState.cIneq.data, mLB, lb_data,
                             lb_size, mUB, ub_data, ub_size, mFixed);
    initActiveSet(&SD->u2.f3.WorkingSet);
    d_factoryConstruct(SD->u2.f3.TrialState.sqpFval,
                       SD->u2.f3.TrialState.cIneq.data, varargout_1_size_idx_0,
                       &MeritFunction);
    emxInitStruct_struct_T6(&SD->u2.f3.obj);
    SD->u2.f3.obj.ldq = maxDims;
    i = SD->u2.f3.obj.QR->size[0] * SD->u2.f3.obj.QR->size[1];
    SD->u2.f3.obj.QR->size[0] = maxDims;
    SD->u2.f3.obj.QR->size[1] = maxDims;
    emxEnsureCapacity_real_T(SD->u2.f3.obj.QR, i);
    i = SD->u2.f3.obj.Q->size[0] * SD->u2.f3.obj.Q->size[1];
    SD->u2.f3.obj.Q->size[0] = maxDims;
    SD->u2.f3.obj.Q->size[1] = maxDims;
    emxEnsureCapacity_real_T(SD->u2.f3.obj.Q, i);
    nVarMax = maxDims * maxDims;
    for (i = 0; i < nVarMax; i++) {
      SD->u2.f3.obj.Q->data[i] = 0.0;
    }
    SD->u2.f3.obj.jpvt.size[0] = maxDims;
    memset(&SD->u2.f3.obj.jpvt.data[0], 0, (uint32_T)maxDims * sizeof(int32_T));
    SD->u2.f3.obj.mrows = 0;
    SD->u2.f3.obj.ncols = 0;
    i = SD->u2.f3.obj.tau->size[0];
    SD->u2.f3.obj.tau->size[0] = muIntScalarMin_sint32(maxDims, maxDims);
    emxEnsureCapacity_real_T(SD->u2.f3.obj.tau, i);
    SD->u2.f3.obj.minRowCol = 0;
    SD->u2.f3.obj.usedPivoting = false;
    emxInitStruct_struct_T7(&obj);
    i = obj.FMat->size[0] * obj.FMat->size[1];
    obj.FMat->size[0] = maxDims;
    obj.FMat->size[1] = maxDims;
    emxEnsureCapacity_real_T(obj.FMat, i);
    obj.ldm = maxDims;
    obj.ndims = 0;
    obj.info = 0;
    obj.ConvexCheck = true;
    obj.workspace_ = rtInf;
    obj.workspace2_ = rtInf;
    d_driver(SD, lb_data, lb_size, ub_data, ub_size, &SD->u2.f3.TrialState,
             &MeritFunction, &SD->u2.f3.FcnEvaluator,
             &SD->u2.f3.FiniteDifferences, &SD->u2.f3.memspace,
             &SD->u2.f3.WorkingSet, &SD->u2.f3.obj, &obj,
             &SD->u2.f3.QPObjective, varargout_1_size_idx_0, unusedExpr);
    emxFreeStruct_struct_T6(&obj);
    emxFreeStruct_struct_T5(&SD->u2.f3.obj);
    emxFreeStruct_struct_T(&SD->u2.f3.WorkingSet);
    emxFreeStruct_struct_T4(&SD->u2.f3.memspace);
    emxFreeStruct_struct_T9(&SD->u2.f3.FiniteDifferences);
    ab_emxFreeStruct_coder_internal(&SD->u2.f3.FcnEvaluator);
    memcpy(&x0[0], &SD->u2.f3.TrialState.xstarsqp[0], 40U * sizeof(real_T));
    fval = SD->u2.f3.TrialState.sqpFval;
    *exitflag = SD->u2.f3.TrialState.sqpExitFlag;
    *output_iterations = fillOutputStruct(
        SD->u2.f3.TrialState.FunctionEvaluations,
        SD->u2.f3.TrialState.sqpIterations, SD->u2.f3.TrialState.steplength,
        SD->u2.f3.TrialState.delta_x.data, MeritFunction.nlpPrimalFeasError,
        MeritFunction.firstOrderOpt, output_funcCount, output_algorithm,
        output_constrviolation, output_stepsize, output_lssteplength,
        output_firstorderopt);
  }
  emxFreeStruct_struct_T1(&SD->u2.f3.TrialState);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

real_T fmincon(evaluateObstacles_mexStackData *SD,
               const real_T fun_workspace_x0[3], real_T fun_workspace_sys_n,
               real_T fun_workspace_sys_Ts, real_T fun_workspace_N,
               const real_T fun_workspace_X_L_stacked[60],
               const struct2_T *fun_workspace_robotParams, real_T x0[40],
               const real_T lb_data[], const int32_T lb_size[2],
               const real_T ub_data[], const int32_T ub_size[2],
               const real_T nonlcon_workspace_x0[3],
               const struct5_T *nonlcon_workspace_obstacles,
               real_T nonlcon_workspace_N,
               const struct3_T nonlcon_workspace_sys, real_T *exitflag,
               real_T *output_iterations, real_T *output_funcCount,
               char_T output_algorithm[3], real_T *output_constrviolation,
               real_T *output_stepsize, real_T *output_lssteplength,
               real_T *output_firstorderopt)
{
  l_struct_T MeritFunction;
  n_struct_T obj;
  real_T unusedExpr[1600];
  real_T fval;
  int32_T i;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVarMax;
  int16_T Cineq_size_idx_0;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  *exitflag = checkLinearInputs(lb_data, lb_size, ub_data, ub_size);
  emxInitStruct_struct_T1(&SD->u2.f1.TrialState);
  SD->u2.f1.TrialState.cIneq.size[0] = followerMPCandUpdate_anonFcn2(
      nonlcon_workspace_x0, nonlcon_workspace_obstacles->M_f,
      nonlcon_workspace_obstacles->A_bar_f,
      nonlcon_workspace_obstacles->B_bar_f.data,
      nonlcon_workspace_obstacles->B_bar_f.size[0], nonlcon_workspace_N,
      nonlcon_workspace_sys.n, nonlcon_workspace_sys.Ts, x0,
      SD->u2.f1.TrialState.cIneq.data);
  Cineq_size_idx_0 = (int16_T)SD->u2.f1.TrialState.cIneq.size[0];
  mConstrMax =
      (((SD->u2.f1.TrialState.cIneq.size[0] + lb_size[0] * lb_size[1]) +
        ub_size[0] * ub_size[1]) +
       SD->u2.f1.TrialState.cIneq.size[0]) +
      1;
  nVarMax = SD->u2.f1.TrialState.cIneq.size[0] + 41;
  maxDims = muIntScalarMax_sint32(nVarMax, mConstrMax);
  if (*exitflag == -2.0) {
    fval = rtInf;
    *output_iterations = 0.0;
    *output_funcCount = 0.0;
    output_algorithm[0] = 's';
    output_algorithm[1] = 'q';
    output_algorithm[2] = 'p';
    *output_constrviolation = rtInf;
    *output_stepsize = rtInf;
    *output_lssteplength = rtInf;
    *output_firstorderopt = rtInf;
  } else {
    int32_T mLB;
    factoryConstruct(SD->u2.f1.TrialState.cIneq.size[0] + 41, mConstrMax,
                     SD->u2.f1.TrialState.cIneq.size[0],
                     SD->u2.f1.TrialState.cIneq.size[0], &SD->u2.f1.TrialState);
    memcpy(&SD->u2.f1.TrialState.xstarsqp[0], &x0[0], 40U * sizeof(real_T));
    c_emxInitStruct_coder_internal_(&SD->u2.f1.FcnEvaluator);
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.value = Cineq_size_idx_0;
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[2] = fun_workspace_x0[2];
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.sys.n = fun_workspace_sys_n;
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.sys.Ts = fun_workspace_sys_Ts;
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.N = fun_workspace_N;
    memcpy(&SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.next.value
                .workspace.X_L_stacked[0],
           &fun_workspace_X_L_stacked[0], 60U * sizeof(real_T));
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.robotParams = *fun_workspace_robotParams;
    emxCopyStruct_struct5_T(&SD->u2.f1.FcnEvaluator.next.next.next.next.next
                                 .next.next.value.workspace.obstacles,
                            nonlcon_workspace_obstacles);
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .N = nonlcon_workspace_N;
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .sys = nonlcon_workspace_sys;
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[0] = nonlcon_workspace_x0[0];
    emxInitStruct_struct_T4(&SD->u2.f1.FiniteDifferences);
    SD->u2.f1.FiniteDifferences.objfun.workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[1] = nonlcon_workspace_x0[1];
    SD->u2.f1.FiniteDifferences.objfun.workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f1.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[2] = nonlcon_workspace_x0[2];
    SD->u2.f1.FiniteDifferences.objfun.workspace.x0[2] = fun_workspace_x0[2];
    SD->u2.f1.FiniteDifferences.objfun.workspace.sys.n = fun_workspace_sys_n;
    SD->u2.f1.FiniteDifferences.objfun.workspace.sys.Ts = fun_workspace_sys_Ts;
    SD->u2.f1.FiniteDifferences.objfun.workspace.N = fun_workspace_N;
    memcpy(&SD->u2.f1.FiniteDifferences.objfun.workspace.X_L_stacked[0],
           &fun_workspace_X_L_stacked[0], 60U * sizeof(real_T));
    SD->u2.f1.FiniteDifferences.objfun.workspace.robotParams =
        *fun_workspace_robotParams;
    SD->u2.f1.FiniteDifferences.nonlin.workspace.x0[0] =
        nonlcon_workspace_x0[0];
    SD->u2.f1.FiniteDifferences.nonlin.workspace.x0[1] =
        nonlcon_workspace_x0[1];
    SD->u2.f1.FiniteDifferences.nonlin.workspace.x0[2] =
        nonlcon_workspace_x0[2];
    emxCopyStruct_struct5_T(
        &SD->u2.f1.FiniteDifferences.nonlin.workspace.obstacles,
        nonlcon_workspace_obstacles);
    SD->u2.f1.FiniteDifferences.nonlin.workspace.N = nonlcon_workspace_N;
    SD->u2.f1.FiniteDifferences.nonlin.workspace.sys = nonlcon_workspace_sys;
    SD->u2.f1.FiniteDifferences.f_1 = 0.0;
    SD->u2.f1.FiniteDifferences.cIneq_1.size[0] = Cineq_size_idx_0;
    SD->u2.f1.FiniteDifferences.mIneq = Cineq_size_idx_0;
    SD->u2.f1.FiniteDifferences.numEvals = 0;
    SD->u2.f1.FiniteDifferences.hasBounds = hasFiniteBounds(
        SD->u2.f1.FiniteDifferences.hasLB, SD->u2.f1.FiniteDifferences.hasUB,
        lb_data, lb_size, ub_data, ub_size);
    SD->u2.f1.QPObjective.grad.size[0] = b_factoryConstruct(
        Cineq_size_idx_0 + 41, &SD->u2.f1.QPObjective.Hx.size[0],
        &SD->u2.f1.QPObjective.hasLinear, &SD->u2.f1.QPObjective.nvar,
        &SD->u2.f1.QPObjective.maxVar, &SD->u2.f1.QPObjective.beta,
        &SD->u2.f1.QPObjective.rho, &SD->u2.f1.QPObjective.objtype,
        &SD->u2.f1.QPObjective.prev_objtype, &SD->u2.f1.QPObjective.prev_nvar,
        &SD->u2.f1.QPObjective.prev_hasLinear,
        &SD->u2.f1.QPObjective.gammaScalar);
    SD->u2.f1.QPObjective.hasLinear = true;
    SD->u2.f1.QPObjective.nvar = 40;
    SD->u2.f1.QPObjective.objtype = 3;
    emxInitStruct_struct_T5(&SD->u2.f1.memspace);
    i = SD->u2.f1.memspace.workspace_float->size[0] *
        SD->u2.f1.memspace.workspace_float->size[1];
    SD->u2.f1.memspace.workspace_float->size[0] = maxDims;
    SD->u2.f1.memspace.workspace_float->size[1] = Cineq_size_idx_0 + 41;
    emxEnsureCapacity_real_T(SD->u2.f1.memspace.workspace_float, i);
    SD->u2.f1.memspace.workspace_int.size[0] = maxDims;
    SD->u2.f1.memspace.workspace_sort.size[0] = maxDims;
    emxInitStruct_struct_T(&SD->u2.f1.WorkingSet);
    c_factoryConstruct(Cineq_size_idx_0, Cineq_size_idx_0 + 41, mConstrMax,
                       &SD->u2.f1.WorkingSet);
    mLB = compressBounds(SD->u2.f1.WorkingSet.indexLB.data,
                         SD->u2.f1.WorkingSet.indexUB.data,
                         SD->u2.f1.WorkingSet.indexFixed.data, lb_data, lb_size,
                         ub_data, ub_size, &mUB, &mFixed);
    loadProblem(&SD->u2.f1.WorkingSet, Cineq_size_idx_0, mLB, mUB, mFixed,
                mConstrMax);
    if ((lb_size[0] != 0) && (lb_size[1] != 0)) {
      i = (uint16_T)mLB;
      for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
        nVarMax = SD->u2.f1.WorkingSet.indexLB.data[mConstrMax];
        SD->u2.f1.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMax(
            SD->u2.f1.TrialState.xstarsqp[nVarMax - 1], lb_data[nVarMax - 1]);
      }
    }
    if ((ub_size[0] != 0) && (ub_size[1] != 0)) {
      i = (uint16_T)mUB;
      for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
        nVarMax = SD->u2.f1.WorkingSet.indexUB.data[mConstrMax];
        SD->u2.f1.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMin(
            SD->u2.f1.TrialState.xstarsqp[nVarMax - 1], ub_data[nVarMax - 1]);
      }
      i = (uint16_T)mFixed;
      for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
        nVarMax = SD->u2.f1.WorkingSet.indexFixed.data[mConstrMax];
        SD->u2.f1.TrialState.xstarsqp[nVarMax - 1] = ub_data[nVarMax - 1];
      }
    }
    fval = followerMPCandUpdate_anonFcn1(
        fun_workspace_x0, fun_workspace_sys_n, fun_workspace_sys_Ts,
        fun_workspace_N, fun_workspace_X_L_stacked,
        fun_workspace_robotParams->Px, fun_workspace_robotParams->d_FL_sq,
        fun_workspace_robotParams->C, fun_workspace_robotParams->beta_N,
        SD->u2.f1.TrialState.xstarsqp);
    if ((!muDoubleScalarIsInf(fval)) && (!muDoubleScalarIsNaN(fval))) {
      computeConstraints_(Cineq_size_idx_0,
                          SD->u2.f1.FcnEvaluator.next.next.next.next.next.next
                              .next.value.workspace.x0,
                          nonlcon_workspace_obstacles, nonlcon_workspace_N,
                          nonlcon_workspace_sys, SD->u2.f1.TrialState.xstarsqp,
                          SD->u2.f1.TrialState.cIneq.data,
                          SD->u2.f1.TrialState.iNonIneq0);
    }
    SD->u2.f1.TrialState.sqpFval = fval;
    computeFiniteDifferences(
        &SD->u2.f1.FiniteDifferences, fval, SD->u2.f1.TrialState.cIneq.data,
        SD->u2.f1.TrialState.iNonIneq0, SD->u2.f1.TrialState.xstarsqp,
        SD->u2.f1.TrialState.grad.data, SD->u2.f1.WorkingSet.Aineq,
        SD->u2.f1.TrialState.iNonIneq0, SD->u2.f1.WorkingSet.ldA, lb_data,
        ub_data);
    SD->u2.f1.TrialState.FunctionEvaluations =
        SD->u2.f1.FiniteDifferences.numEvals + 1;
    updateWorkingSetForNewQP(x0, &SD->u2.f1.WorkingSet, Cineq_size_idx_0,
                             SD->u2.f1.TrialState.cIneq.data, mLB, lb_data,
                             lb_size, mUB, ub_data, ub_size, mFixed);
    initActiveSet(&SD->u2.f1.WorkingSet);
    d_factoryConstruct(fval, SD->u2.f1.TrialState.cIneq.data, Cineq_size_idx_0,
                       &MeritFunction);
    emxInitStruct_struct_T6(&SD->u2.f1.obj);
    SD->u2.f1.obj.ldq = maxDims;
    i = SD->u2.f1.obj.QR->size[0] * SD->u2.f1.obj.QR->size[1];
    SD->u2.f1.obj.QR->size[0] = maxDims;
    SD->u2.f1.obj.QR->size[1] = maxDims;
    emxEnsureCapacity_real_T(SD->u2.f1.obj.QR, i);
    i = SD->u2.f1.obj.Q->size[0] * SD->u2.f1.obj.Q->size[1];
    SD->u2.f1.obj.Q->size[0] = maxDims;
    SD->u2.f1.obj.Q->size[1] = maxDims;
    emxEnsureCapacity_real_T(SD->u2.f1.obj.Q, i);
    nVarMax = maxDims * maxDims;
    for (i = 0; i < nVarMax; i++) {
      SD->u2.f1.obj.Q->data[i] = 0.0;
    }
    SD->u2.f1.obj.jpvt.size[0] = maxDims;
    memset(&SD->u2.f1.obj.jpvt.data[0], 0, (uint32_T)maxDims * sizeof(int32_T));
    SD->u2.f1.obj.mrows = 0;
    SD->u2.f1.obj.ncols = 0;
    i = SD->u2.f1.obj.tau->size[0];
    SD->u2.f1.obj.tau->size[0] = muIntScalarMin_sint32(maxDims, maxDims);
    emxEnsureCapacity_real_T(SD->u2.f1.obj.tau, i);
    SD->u2.f1.obj.minRowCol = 0;
    SD->u2.f1.obj.usedPivoting = false;
    emxInitStruct_struct_T7(&obj);
    i = obj.FMat->size[0] * obj.FMat->size[1];
    obj.FMat->size[0] = maxDims;
    obj.FMat->size[1] = maxDims;
    emxEnsureCapacity_real_T(obj.FMat, i);
    obj.ldm = maxDims;
    obj.ndims = 0;
    obj.info = 0;
    obj.ConvexCheck = true;
    obj.workspace_ = rtInf;
    obj.workspace2_ = rtInf;
    driver(SD, lb_data, lb_size, ub_data, ub_size, &SD->u2.f1.TrialState,
           &MeritFunction, &SD->u2.f1.FcnEvaluator,
           &SD->u2.f1.FiniteDifferences, &SD->u2.f1.memspace,
           &SD->u2.f1.WorkingSet, &SD->u2.f1.obj, &obj, &SD->u2.f1.QPObjective,
           Cineq_size_idx_0, unusedExpr);
    emxFreeStruct_struct_T6(&obj);
    emxFreeStruct_struct_T5(&SD->u2.f1.obj);
    emxFreeStruct_struct_T(&SD->u2.f1.WorkingSet);
    emxFreeStruct_struct_T4(&SD->u2.f1.memspace);
    emxFreeStruct_struct_T3(&SD->u2.f1.FiniteDifferences);
    j_emxFreeStruct_coder_internal_(&SD->u2.f1.FcnEvaluator);
    memcpy(&x0[0], &SD->u2.f1.TrialState.xstarsqp[0], 40U * sizeof(real_T));
    fval = SD->u2.f1.TrialState.sqpFval;
    *exitflag = SD->u2.f1.TrialState.sqpExitFlag;
    *output_iterations = fillOutputStruct(
        SD->u2.f1.TrialState.FunctionEvaluations,
        SD->u2.f1.TrialState.sqpIterations, SD->u2.f1.TrialState.steplength,
        SD->u2.f1.TrialState.delta_x.data, MeritFunction.nlpPrimalFeasError,
        MeritFunction.firstOrderOpt, output_funcCount, output_algorithm,
        output_constrviolation, output_stepsize, output_lssteplength,
        output_firstorderopt);
  }
  emxFreeStruct_struct_T1(&SD->u2.f1.TrialState);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

/* End of code generation (fmincon.c) */
