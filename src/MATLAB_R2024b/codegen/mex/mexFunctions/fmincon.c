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
#include "compressBounds.h"
#include "computeConstraints_.h"
#include "computeFiniteDifferences.h"
#include "computeForwardDifferences.h"
#include "constraints.h"
#include "driver.h"
#include "evalObjAndConstrAndDerivatives.h"
#include "factoryConstruct.h"
#include "factoryConstruct1.h"
#include "factoryConstruct2.h"
#include "factoryConstruct3.h"
#include "fillOutputStruct.h"
#include "followerMPCandUpdate.h"
#include "hasFiniteBounds.h"
#include "initActiveSet.h"
#include "loadProblem.h"
#include "mexFunctions_data.h"
#include "mexFunctions_emxutil.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "updateWorkingSetForNewQP.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T b_fmincon(mexFunctionsStackData *SD, const real_T fun_workspace_x0[3],
                 real_T fun_workspace_sys_n, real_T fun_workspace_sys_m,
                 real_T fun_workspace_sys_Ts,
                 const struct1_T *fun_workspace_robotParams,
                 real_T fun_workspace_N, real_T x0[40], const real_T lb[40],
                 const real_T ub[40], const real_T nonlcon_workspace_x0[3],
                 const struct5_T *nonlcon_workspace_obstacles,
                 real_T nonlcon_workspace_N,
                 const struct3_T nonlcon_workspace_sys, real_T *exitflag,
                 real_T *output_iterations, real_T *output_funcCount,
                 char_T output_algorithm[3], real_T *output_constrviolation,
                 real_T *output_stepsize, real_T *output_lssteplength,
                 real_T *output_firstorderopt)
{
  g_struct_T obj;
  j_struct_T MeritFunction;
  m_struct_T b_obj;
  real_T unusedExpr[1600];
  real_T fval;
  int32_T i;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVarMax;
  int16_T varargout_1_size_idx_0;
  boolean_T exitg1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  *exitflag = rtInf;
  nVarMax = 0;
  exitg1 = false;
  while ((!exitg1) && (nVarMax < 40)) {
    if (lb[nVarMax] > ub[nVarMax]) {
      *exitflag = -2.0;
      exitg1 = true;
    } else {
      nVarMax++;
    }
  }
  emlrtMEXProfilingFunctionEntry((char_T *)c_completeName, isMexOutdated);
  emxInitStruct_struct_T1(&SD->u2.f2.TrialState);
  SD->u2.f2.TrialState.cIneq.size[0] = constraints(
      emlrtRootTLSGlobal, x0, nonlcon_workspace_x0,
      nonlcon_workspace_obstacles->M_l, nonlcon_workspace_obstacles->A_bar_l,
      nonlcon_workspace_obstacles->B_bar_l.data,
      nonlcon_workspace_obstacles->B_bar_l.size[0], nonlcon_workspace_N,
      nonlcon_workspace_sys.n, nonlcon_workspace_sys.Ts,
      SD->u2.f2.TrialState.cIneq.data);
  varargout_1_size_idx_0 = (int16_T)SD->u2.f2.TrialState.cIneq.size[0];
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  mConstrMax = (SD->u2.f2.TrialState.cIneq.size[0] +
                SD->u2.f2.TrialState.cIneq.size[0]) +
               81;
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
    k_emxInitStruct_coder_internal_(&SD->u2.f2.FcnEvaluator);
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
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[0] = nonlcon_workspace_x0[0];
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[1] = nonlcon_workspace_x0[1];
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[2] = fun_workspace_x0[2];
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[2] = nonlcon_workspace_x0[2];
    emxCopyStruct_struct5_T(&SD->u2.f2.FcnEvaluator.next.next.next.next.next
                                 .next.next.value.workspace.obstacles,
                            nonlcon_workspace_obstacles);
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .N = nonlcon_workspace_N;
    SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .sys = nonlcon_workspace_sys;
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
    emxInitStruct_struct_T3(&SD->u2.f2.memspace);
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
    mLB = compressBounds(
        SD->u2.f2.WorkingSet.indexLB.data, SD->u2.f2.WorkingSet.indexUB.data,
        SD->u2.f2.WorkingSet.indexFixed.data, lb, ub, &mUB, &mFixed);
    loadProblem(&SD->u2.f2.WorkingSet, varargout_1_size_idx_0, mLB, mUB, mFixed,
                mConstrMax);
    i = (uint16_T)mLB;
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->u2.f2.WorkingSet.indexLB.data[mConstrMax];
      SD->u2.f2.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMax(
          SD->u2.f2.TrialState.xstarsqp[nVarMax - 1], lb[nVarMax - 1]);
    }
    i = (uint16_T)mUB;
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->u2.f2.WorkingSet.indexUB.data[mConstrMax];
      SD->u2.f2.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMin(
          SD->u2.f2.TrialState.xstarsqp[nVarMax - 1], ub[nVarMax - 1]);
    }
    i = (uint16_T)mFixed;
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->u2.f2.WorkingSet.indexFixed.data[mConstrMax];
      SD->u2.f2.TrialState.xstarsqp[nVarMax - 1] = ub[nVarMax - 1];
    }
    SD->u2.f2.TrialState.sqpFval = evalObjAndConstrAndDerivatives(
        emlrtRootTLSGlobal,
        SD->u2.f2.FcnEvaluator.next.next.next.next.next.value,
        SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value
            .workspace.x0,
        &SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.value
             .workspace.obstacles,
        nonlcon_workspace_N, nonlcon_workspace_sys,
        &SD->u2.f2.FcnEvaluator.next.next.next.next.next.next.next.next.value
             .workspace,
        SD->u2.f2.TrialState.xstarsqp, SD->u2.f2.TrialState.cIneq.data,
        &SD->u2.f2.TrialState.cIneq.size[0], SD->u2.f2.TrialState.iNonIneq0,
        &nVarMax);
    emxInitStruct_struct_T8(&SD->u2.f2.FiniteDifferences);
    SD->u2.f2.FiniteDifferences.objfun.workspace.sys.n = fun_workspace_sys_n;
    SD->u2.f2.FiniteDifferences.objfun.workspace.sys.Ts = fun_workspace_sys_Ts;
    SD->u2.f2.FiniteDifferences.objfun.workspace.robotParams =
        *fun_workspace_robotParams;
    SD->u2.f2.FiniteDifferences.objfun.workspace.N = fun_workspace_N;
    SD->u2.f2.FiniteDifferences.objfun.workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f2.FiniteDifferences.nonlin.workspace.x0[0] =
        nonlcon_workspace_x0[0];
    SD->u2.f2.FiniteDifferences.objfun.workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f2.FiniteDifferences.nonlin.workspace.x0[1] =
        nonlcon_workspace_x0[1];
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
    SD->u2.f2.FiniteDifferences.hasBounds =
        hasFiniteBounds(SD->u2.f2.FiniteDifferences.hasLB,
                        SD->u2.f2.FiniteDifferences.hasUB, lb, ub);
    computeForwardDifferences(
        &SD->u2.f2.FiniteDifferences, SD->u2.f2.TrialState.sqpFval,
        SD->u2.f2.TrialState.cIneq.data, SD->u2.f2.TrialState.iNonIneq0,
        SD->u2.f2.TrialState.xstarsqp, SD->u2.f2.TrialState.grad.data,
        SD->u2.f2.WorkingSet.Aineq, SD->u2.f2.TrialState.iNonIneq0,
        SD->u2.f2.WorkingSet.ldA, lb, ub);
    SD->u2.f2.TrialState.FunctionEvaluations =
        SD->u2.f2.FiniteDifferences.numEvals + 1;
    updateWorkingSetForNewQP(
        emlrtRootTLSGlobal, x0, &SD->u2.f2.WorkingSet, varargout_1_size_idx_0,
        SD->u2.f2.TrialState.cIneq.data, mLB, lb, mUB, ub, mFixed);
    initActiveSet(&SD->u2.f2.WorkingSet);
    d_factoryConstruct(emlrtRootTLSGlobal, SD->u2.f2.TrialState.sqpFval,
                       SD->u2.f2.TrialState.cIneq.data, varargout_1_size_idx_0,
                       &MeritFunction);
    emxInitStruct_struct_T5(&obj);
    obj.ldq = maxDims;
    i = obj.QR->size[0] * obj.QR->size[1];
    obj.QR->size[0] = maxDims;
    obj.QR->size[1] = maxDims;
    emxEnsureCapacity_real_T(obj.QR, i);
    i = obj.Q->size[0] * obj.Q->size[1];
    obj.Q->size[0] = maxDims;
    obj.Q->size[1] = maxDims;
    emxEnsureCapacity_real_T(obj.Q, i);
    nVarMax = maxDims * maxDims;
    for (i = 0; i < nVarMax; i++) {
      obj.Q->data[i] = 0.0;
    }
    obj.jpvt.size[0] = maxDims;
    memset(&obj.jpvt.data[0], 0, (uint32_T)maxDims * sizeof(int32_T));
    obj.mrows = 0;
    obj.ncols = 0;
    i = obj.tau->size[0];
    obj.tau->size[0] = muIntScalarMin_sint32(maxDims, maxDims);
    emxEnsureCapacity_real_T(obj.tau, i);
    obj.minRowCol = 0;
    obj.usedPivoting = false;
    emxInitStruct_struct_T6(&b_obj);
    i = b_obj.FMat->size[0] * b_obj.FMat->size[1];
    b_obj.FMat->size[0] = maxDims;
    b_obj.FMat->size[1] = maxDims;
    emxEnsureCapacity_real_T(b_obj.FMat, i);
    b_obj.ldm = maxDims;
    b_obj.ndims = 0;
    b_obj.info = 0;
    b_obj.ConvexCheck = true;
    b_obj.workspace_ = rtInf;
    b_obj.workspace2_ = rtInf;
    c_driver(emlrtRootTLSGlobal, SD, lb, ub, &SD->u2.f2.TrialState,
             &MeritFunction, &SD->u2.f2.FcnEvaluator,
             &SD->u2.f2.FiniteDifferences, &SD->u2.f2.memspace,
             &SD->u2.f2.WorkingSet, &obj, &b_obj, &SD->u2.f2.QPObjective,
             varargout_1_size_idx_0, unusedExpr);
    emxFreeStruct_struct_T6(&b_obj);
    emxFreeStruct_struct_T5(&obj);
    emxFreeStruct_struct_T(&SD->u2.f2.WorkingSet);
    emxFreeStruct_struct_T3(&SD->u2.f2.memspace);
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

real_T c_fmincon(mexFunctionsStackData *SD, const real_T fun_workspace_x0[3],
                 real_T fun_workspace_sys_n, real_T fun_workspace_sys_m,
                 real_T fun_workspace_sys_Ts, real_T fun_workspace_N,
                 const struct1_T *fun_workspace_robotParams, real_T x0[40],
                 const real_T lb[40], const real_T ub[40],
                 const real_T nonlcon_workspace_x0[3],
                 const struct5_T *nonlcon_workspace_obstacles,
                 real_T nonlcon_workspace_N,
                 const struct3_T nonlcon_workspace_sys, real_T *exitflag,
                 real_T *output_iterations, real_T *output_funcCount,
                 char_T output_algorithm[3], real_T *output_constrviolation,
                 real_T *output_stepsize, real_T *output_lssteplength,
                 real_T *output_firstorderopt)
{
  g_struct_T obj;
  j_struct_T MeritFunction;
  m_struct_T b_obj;
  real_T unusedExpr[1600];
  real_T fval;
  int32_T i;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVarMax;
  int16_T varargout_1_size_idx_0;
  boolean_T exitg1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  *exitflag = rtInf;
  nVarMax = 0;
  exitg1 = false;
  while ((!exitg1) && (nVarMax < 40)) {
    if (lb[nVarMax] > ub[nVarMax]) {
      *exitflag = -2.0;
      exitg1 = true;
    } else {
      nVarMax++;
    }
  }
  emlrtMEXProfilingFunctionEntry((char_T *)e_completeName, isMexOutdated);
  emxInitStruct_struct_T1(&SD->u2.f3.TrialState);
  SD->u2.f3.TrialState.cIneq.size[0] = constraints(
      emlrtRootTLSGlobal, x0, nonlcon_workspace_x0,
      nonlcon_workspace_obstacles->M_l, nonlcon_workspace_obstacles->A_bar_l,
      nonlcon_workspace_obstacles->B_bar_l.data,
      nonlcon_workspace_obstacles->B_bar_l.size[0], nonlcon_workspace_N,
      nonlcon_workspace_sys.n, nonlcon_workspace_sys.Ts,
      SD->u2.f3.TrialState.cIneq.data);
  varargout_1_size_idx_0 = (int16_T)SD->u2.f3.TrialState.cIneq.size[0];
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  mConstrMax = (SD->u2.f3.TrialState.cIneq.size[0] +
                SD->u2.f3.TrialState.cIneq.size[0]) +
               81;
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
    s_emxInitStruct_coder_internal_(&SD->u2.f3.FcnEvaluator);
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
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[0] = nonlcon_workspace_x0[0];
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[1] = nonlcon_workspace_x0[1];
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
        .workspace.x0[2] = fun_workspace_x0[2];
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .x0[2] = nonlcon_workspace_x0[2];
    emxCopyStruct_struct5_T(&SD->u2.f3.FcnEvaluator.next.next.next.next.next
                                 .next.next.value.workspace.obstacles,
                            nonlcon_workspace_obstacles);
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .N = nonlcon_workspace_N;
    SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value.workspace
        .sys = nonlcon_workspace_sys;
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
    emxInitStruct_struct_T3(&SD->u2.f3.memspace);
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
    mLB = compressBounds(
        SD->u2.f3.WorkingSet.indexLB.data, SD->u2.f3.WorkingSet.indexUB.data,
        SD->u2.f3.WorkingSet.indexFixed.data, lb, ub, &mUB, &mFixed);
    loadProblem(&SD->u2.f3.WorkingSet, varargout_1_size_idx_0, mLB, mUB, mFixed,
                mConstrMax);
    i = (uint16_T)mLB;
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->u2.f3.WorkingSet.indexLB.data[mConstrMax];
      SD->u2.f3.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMax(
          SD->u2.f3.TrialState.xstarsqp[nVarMax - 1], lb[nVarMax - 1]);
    }
    i = (uint16_T)mUB;
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->u2.f3.WorkingSet.indexUB.data[mConstrMax];
      SD->u2.f3.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMin(
          SD->u2.f3.TrialState.xstarsqp[nVarMax - 1], ub[nVarMax - 1]);
    }
    i = (uint16_T)mFixed;
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->u2.f3.WorkingSet.indexFixed.data[mConstrMax];
      SD->u2.f3.TrialState.xstarsqp[nVarMax - 1] = ub[nVarMax - 1];
    }
    SD->u2.f3.TrialState.sqpFval = b_evalObjAndConstrAndDerivative(
        emlrtRootTLSGlobal,
        SD->u2.f3.FcnEvaluator.next.next.next.next.next.value,
        SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value
            .workspace.x0,
        &SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.value
             .workspace.obstacles,
        nonlcon_workspace_N, nonlcon_workspace_sys,
        &SD->u2.f3.FcnEvaluator.next.next.next.next.next.next.next.next.value
             .workspace,
        SD->u2.f3.TrialState.xstarsqp, SD->u2.f3.TrialState.cIneq.data,
        &SD->u2.f3.TrialState.cIneq.size[0], SD->u2.f3.TrialState.iNonIneq0,
        &nVarMax);
    emxInitStruct_struct_T9(&SD->u2.f3.FiniteDifferences);
    SD->u2.f3.FiniteDifferences.objfun.workspace.sys.n = fun_workspace_sys_n;
    SD->u2.f3.FiniteDifferences.objfun.workspace.sys.Ts = fun_workspace_sys_Ts;
    SD->u2.f3.FiniteDifferences.objfun.workspace.N = fun_workspace_N;
    SD->u2.f3.FiniteDifferences.objfun.workspace.robotParams =
        *fun_workspace_robotParams;
    SD->u2.f3.FiniteDifferences.objfun.workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f3.FiniteDifferences.nonlin.workspace.x0[0] =
        nonlcon_workspace_x0[0];
    SD->u2.f3.FiniteDifferences.objfun.workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f3.FiniteDifferences.nonlin.workspace.x0[1] =
        nonlcon_workspace_x0[1];
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
    SD->u2.f3.FiniteDifferences.hasBounds =
        hasFiniteBounds(SD->u2.f3.FiniteDifferences.hasLB,
                        SD->u2.f3.FiniteDifferences.hasUB, lb, ub);
    b_computeForwardDifferences(
        &SD->u2.f3.FiniteDifferences, SD->u2.f3.TrialState.sqpFval,
        SD->u2.f3.TrialState.cIneq.data, SD->u2.f3.TrialState.iNonIneq0,
        SD->u2.f3.TrialState.xstarsqp, SD->u2.f3.TrialState.grad.data,
        SD->u2.f3.WorkingSet.Aineq, SD->u2.f3.TrialState.iNonIneq0,
        SD->u2.f3.WorkingSet.ldA, lb, ub);
    SD->u2.f3.TrialState.FunctionEvaluations =
        SD->u2.f3.FiniteDifferences.numEvals + 1;
    updateWorkingSetForNewQP(
        emlrtRootTLSGlobal, x0, &SD->u2.f3.WorkingSet, varargout_1_size_idx_0,
        SD->u2.f3.TrialState.cIneq.data, mLB, lb, mUB, ub, mFixed);
    initActiveSet(&SD->u2.f3.WorkingSet);
    d_factoryConstruct(emlrtRootTLSGlobal, SD->u2.f3.TrialState.sqpFval,
                       SD->u2.f3.TrialState.cIneq.data, varargout_1_size_idx_0,
                       &MeritFunction);
    emxInitStruct_struct_T5(&obj);
    obj.ldq = maxDims;
    i = obj.QR->size[0] * obj.QR->size[1];
    obj.QR->size[0] = maxDims;
    obj.QR->size[1] = maxDims;
    emxEnsureCapacity_real_T(obj.QR, i);
    i = obj.Q->size[0] * obj.Q->size[1];
    obj.Q->size[0] = maxDims;
    obj.Q->size[1] = maxDims;
    emxEnsureCapacity_real_T(obj.Q, i);
    nVarMax = maxDims * maxDims;
    for (i = 0; i < nVarMax; i++) {
      obj.Q->data[i] = 0.0;
    }
    obj.jpvt.size[0] = maxDims;
    memset(&obj.jpvt.data[0], 0, (uint32_T)maxDims * sizeof(int32_T));
    obj.mrows = 0;
    obj.ncols = 0;
    i = obj.tau->size[0];
    obj.tau->size[0] = muIntScalarMin_sint32(maxDims, maxDims);
    emxEnsureCapacity_real_T(obj.tau, i);
    obj.minRowCol = 0;
    obj.usedPivoting = false;
    emxInitStruct_struct_T6(&b_obj);
    i = b_obj.FMat->size[0] * b_obj.FMat->size[1];
    b_obj.FMat->size[0] = maxDims;
    b_obj.FMat->size[1] = maxDims;
    emxEnsureCapacity_real_T(b_obj.FMat, i);
    b_obj.ldm = maxDims;
    b_obj.ndims = 0;
    b_obj.info = 0;
    b_obj.ConvexCheck = true;
    b_obj.workspace_ = rtInf;
    b_obj.workspace2_ = rtInf;
    d_driver(emlrtRootTLSGlobal, SD, lb, ub, &SD->u2.f3.TrialState,
             &MeritFunction, &SD->u2.f3.FcnEvaluator,
             &SD->u2.f3.FiniteDifferences, &SD->u2.f3.memspace,
             &SD->u2.f3.WorkingSet, &obj, &b_obj, &SD->u2.f3.QPObjective,
             varargout_1_size_idx_0, unusedExpr);
    emxFreeStruct_struct_T6(&b_obj);
    emxFreeStruct_struct_T5(&obj);
    emxFreeStruct_struct_T(&SD->u2.f3.WorkingSet);
    emxFreeStruct_struct_T3(&SD->u2.f3.memspace);
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

real_T fmincon(mexFunctionsStackData *SD, const real_T fun_workspace_x0[3],
               real_T fun_workspace_sys_n, real_T fun_workspace_sys_Ts,
               real_T fun_workspace_N,
               const real_T fun_workspace_X_L_stacked[60],
               const struct2_T *fun_workspace_robotParams, real_T x0[40],
               const real_T lb[40], const real_T ub[40],
               const real_T nonlcon_workspace_x0[3],
               const struct5_T *nonlcon_workspace_obstacles,
               real_T nonlcon_workspace_N,
               const struct3_T nonlcon_workspace_sys, real_T *exitflag,
               real_T *output_iterations, real_T *output_funcCount,
               char_T output_algorithm[3], real_T *output_constrviolation,
               real_T *output_stepsize, real_T *output_lssteplength,
               real_T *output_firstorderopt)
{
  g_struct_T obj;
  j_struct_T MeritFunction;
  k_coder_internal_stickyStruct FcnEvaluator;
  m_struct_T b_obj;
  real_T unusedExpr[1600];
  real_T fval;
  int32_T i;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVarMax;
  int16_T Cineq_size_idx_0;
  boolean_T exitg1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  *exitflag = rtInf;
  nVarMax = 0;
  exitg1 = false;
  while ((!exitg1) && (nVarMax < 40)) {
    if (lb[nVarMax] > ub[nVarMax]) {
      *exitflag = -2.0;
      exitg1 = true;
    } else {
      nVarMax++;
    }
  }
  emxInitStruct_struct_T1(&SD->u2.f1.TrialState);
  SD->u2.f1.TrialState.cIneq.size[0] = followerMPCandUpdate_anonFcn2(
      emlrtRootTLSGlobal, nonlcon_workspace_x0,
      nonlcon_workspace_obstacles->M_f, nonlcon_workspace_obstacles->A_bar_f,
      nonlcon_workspace_obstacles->B_bar_f.data,
      nonlcon_workspace_obstacles->B_bar_f.size[0], nonlcon_workspace_N,
      nonlcon_workspace_sys.n, nonlcon_workspace_sys.Ts, x0,
      SD->u2.f1.TrialState.cIneq.data);
  Cineq_size_idx_0 = (int16_T)SD->u2.f1.TrialState.cIneq.size[0];
  mConstrMax = (SD->u2.f1.TrialState.cIneq.size[0] +
                SD->u2.f1.TrialState.cIneq.size[0]) +
               81;
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
    c_emxInitStruct_coder_internal_(&FcnEvaluator);
    FcnEvaluator.next.next.next.next.next.value = Cineq_size_idx_0;
    FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.x0[0] =
        fun_workspace_x0[0];
    FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.x0[1] =
        fun_workspace_x0[1];
    FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.x0[2] =
        fun_workspace_x0[2];
    FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.sys.n =
        fun_workspace_sys_n;
    FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.sys
        .Ts = fun_workspace_sys_Ts;
    FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.N =
        fun_workspace_N;
    memcpy(&FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .X_L_stacked[0],
           &fun_workspace_X_L_stacked[0], 60U * sizeof(real_T));
    FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
        .robotParams = *fun_workspace_robotParams;
    FcnEvaluator.next.next.next.next.next.next.next.value.workspace.x0[0] =
        nonlcon_workspace_x0[0];
    FcnEvaluator.next.next.next.next.next.next.next.value.workspace.x0[1] =
        nonlcon_workspace_x0[1];
    FcnEvaluator.next.next.next.next.next.next.next.value.workspace.x0[2] =
        nonlcon_workspace_x0[2];
    emxCopyStruct_struct5_T(&FcnEvaluator.next.next.next.next.next.next.next
                                 .value.workspace.obstacles,
                            nonlcon_workspace_obstacles);
    FcnEvaluator.next.next.next.next.next.next.next.value.workspace.N =
        nonlcon_workspace_N;
    FcnEvaluator.next.next.next.next.next.next.next.value.workspace.sys =
        nonlcon_workspace_sys;
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
    emxInitStruct_struct_T3(&SD->u2.f1.memspace);
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
    mLB = compressBounds(
        SD->u2.f1.WorkingSet.indexLB.data, SD->u2.f1.WorkingSet.indexUB.data,
        SD->u2.f1.WorkingSet.indexFixed.data, lb, ub, &mUB, &mFixed);
    loadProblem(&SD->u2.f1.WorkingSet, Cineq_size_idx_0, mLB, mUB, mFixed,
                mConstrMax);
    i = (uint16_T)mLB;
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->u2.f1.WorkingSet.indexLB.data[mConstrMax];
      SD->u2.f1.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMax(
          SD->u2.f1.TrialState.xstarsqp[nVarMax - 1], lb[nVarMax - 1]);
    }
    i = (uint16_T)mUB;
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->u2.f1.WorkingSet.indexUB.data[mConstrMax];
      SD->u2.f1.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMin(
          SD->u2.f1.TrialState.xstarsqp[nVarMax - 1], ub[nVarMax - 1]);
    }
    i = (uint16_T)mFixed;
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->u2.f1.WorkingSet.indexFixed.data[mConstrMax];
      SD->u2.f1.TrialState.xstarsqp[nVarMax - 1] = ub[nVarMax - 1];
    }
    fval = followerMPCandUpdate_anonFcn1(
        emlrtRootTLSGlobal, fun_workspace_x0, fun_workspace_sys_n,
        fun_workspace_sys_Ts, fun_workspace_N, fun_workspace_X_L_stacked,
        fun_workspace_robotParams->Px, fun_workspace_robotParams->d_FL_sq,
        fun_workspace_robotParams->C, fun_workspace_robotParams->beta_N,
        SD->u2.f1.TrialState.xstarsqp);
    if ((!muDoubleScalarIsInf(fval)) && (!muDoubleScalarIsNaN(fval))) {
      computeConstraints_(
          emlrtRootTLSGlobal, Cineq_size_idx_0,
          FcnEvaluator.next.next.next.next.next.next.next.value.workspace.x0,
          nonlcon_workspace_obstacles, nonlcon_workspace_N,
          nonlcon_workspace_sys, SD->u2.f1.TrialState.xstarsqp,
          SD->u2.f1.TrialState.cIneq.data, SD->u2.f1.TrialState.iNonIneq0);
    }
    SD->u2.f1.TrialState.sqpFval = fval;
    emxInitStruct_struct_T4(&SD->u2.f1.obj);
    SD->u2.f1.obj.objfun.workspace.x0[0] = fun_workspace_x0[0];
    SD->u2.f1.obj.objfun.workspace.x0[1] = fun_workspace_x0[1];
    SD->u2.f1.obj.objfun.workspace.x0[2] = fun_workspace_x0[2];
    SD->u2.f1.obj.objfun.workspace.sys.n = fun_workspace_sys_n;
    SD->u2.f1.obj.objfun.workspace.sys.Ts = fun_workspace_sys_Ts;
    SD->u2.f1.obj.objfun.workspace.N = fun_workspace_N;
    memcpy(&SD->u2.f1.obj.objfun.workspace.X_L_stacked[0],
           &fun_workspace_X_L_stacked[0], 60U * sizeof(real_T));
    SD->u2.f1.obj.objfun.workspace.robotParams = *fun_workspace_robotParams;
    SD->u2.f1.obj.nonlin.workspace.x0[0] = nonlcon_workspace_x0[0];
    SD->u2.f1.obj.nonlin.workspace.x0[1] = nonlcon_workspace_x0[1];
    SD->u2.f1.obj.nonlin.workspace.x0[2] = nonlcon_workspace_x0[2];
    emxCopyStruct_struct5_T(&SD->u2.f1.obj.nonlin.workspace.obstacles,
                            nonlcon_workspace_obstacles);
    SD->u2.f1.obj.nonlin.workspace.N = nonlcon_workspace_N;
    SD->u2.f1.obj.nonlin.workspace.sys = nonlcon_workspace_sys;
    SD->u2.f1.obj.f_1 = 0.0;
    SD->u2.f1.obj.cIneq_1.size[0] = Cineq_size_idx_0;
    SD->u2.f1.obj.mIneq = Cineq_size_idx_0;
    SD->u2.f1.obj.numEvals = 0;
    SD->u2.f1.obj.hasBounds =
        hasFiniteBounds(SD->u2.f1.obj.hasLB, SD->u2.f1.obj.hasUB, lb, ub);
    computeFiniteDifferences(
        &SD->u2.f1.obj, fval, SD->u2.f1.TrialState.cIneq.data,
        SD->u2.f1.TrialState.iNonIneq0, SD->u2.f1.TrialState.xstarsqp,
        SD->u2.f1.TrialState.grad.data, SD->u2.f1.WorkingSet.Aineq,
        SD->u2.f1.TrialState.iNonIneq0, SD->u2.f1.WorkingSet.ldA, lb, ub);
    SD->u2.f1.TrialState.FunctionEvaluations = SD->u2.f1.obj.numEvals + 1;
    updateWorkingSetForNewQP(emlrtRootTLSGlobal, x0, &SD->u2.f1.WorkingSet,
                             Cineq_size_idx_0, SD->u2.f1.TrialState.cIneq.data,
                             mLB, lb, mUB, ub, mFixed);
    initActiveSet(&SD->u2.f1.WorkingSet);
    d_factoryConstruct(emlrtRootTLSGlobal, fval,
                       SD->u2.f1.TrialState.cIneq.data, Cineq_size_idx_0,
                       &MeritFunction);
    emxInitStruct_struct_T5(&obj);
    obj.ldq = maxDims;
    i = obj.QR->size[0] * obj.QR->size[1];
    obj.QR->size[0] = maxDims;
    obj.QR->size[1] = maxDims;
    emxEnsureCapacity_real_T(obj.QR, i);
    i = obj.Q->size[0] * obj.Q->size[1];
    obj.Q->size[0] = maxDims;
    obj.Q->size[1] = maxDims;
    emxEnsureCapacity_real_T(obj.Q, i);
    nVarMax = maxDims * maxDims;
    for (i = 0; i < nVarMax; i++) {
      obj.Q->data[i] = 0.0;
    }
    obj.jpvt.size[0] = maxDims;
    memset(&obj.jpvt.data[0], 0, (uint32_T)maxDims * sizeof(int32_T));
    obj.mrows = 0;
    obj.ncols = 0;
    i = obj.tau->size[0];
    obj.tau->size[0] = muIntScalarMin_sint32(maxDims, maxDims);
    emxEnsureCapacity_real_T(obj.tau, i);
    obj.minRowCol = 0;
    obj.usedPivoting = false;
    emxInitStruct_struct_T6(&b_obj);
    i = b_obj.FMat->size[0] * b_obj.FMat->size[1];
    b_obj.FMat->size[0] = maxDims;
    b_obj.FMat->size[1] = maxDims;
    emxEnsureCapacity_real_T(b_obj.FMat, i);
    b_obj.ldm = maxDims;
    b_obj.ndims = 0;
    b_obj.info = 0;
    b_obj.ConvexCheck = true;
    b_obj.workspace_ = rtInf;
    b_obj.workspace2_ = rtInf;
    driver(emlrtRootTLSGlobal, SD, lb, ub, &SD->u2.f1.TrialState,
           &MeritFunction, &FcnEvaluator, &SD->u2.f1.obj, &SD->u2.f1.memspace,
           &SD->u2.f1.WorkingSet, &obj, &b_obj, &SD->u2.f1.QPObjective,
           Cineq_size_idx_0, unusedExpr);
    emxFreeStruct_struct_T6(&b_obj);
    emxFreeStruct_struct_T5(&obj);
    emxFreeStruct_struct_T4(&SD->u2.f1.obj);
    emxFreeStruct_struct_T(&SD->u2.f1.WorkingSet);
    emxFreeStruct_struct_T3(&SD->u2.f1.memspace);
    j_emxFreeStruct_coder_internal_(&FcnEvaluator);
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
