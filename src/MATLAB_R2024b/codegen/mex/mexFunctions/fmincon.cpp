//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fmincon.cpp
//
// Code generation for function 'fmincon'
//

// Include files
#include "fmincon.h"
#include "anonymous_function.h"
#include "compressBounds.h"
#include "computeConstraints_.h"
#include "computeFiniteDifferences.h"
#include "computeForwardDifferences.h"
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
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "mexFunctions_types1.h"
#include "mexFunctions_types2.h"
#include "rt_nonfinite.h"
#include "stickyStruct.h"
#include "updateWorkingSetForNewQP.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>

// Function Definitions
namespace coder {
real_T d_fmincon(mexFunctionsStackData *SD, const e_anonymous_function &fun,
                 real_T x0[40], const real_T lb[40], const real_T ub[40],
                 const d_anonymous_function &nonlcon, real_T &exitflag,
                 real_T &output_iterations, real_T &output_funcCount,
                 char_T output_algorithm[3], real_T &output_constrviolation,
                 real_T &output_stepsize, real_T &output_lssteplength,
                 real_T &output_firstorderopt)
{
  d_struct_T obj;
  e_struct_T b_obj;
  h_struct_T MeritFunction;
  real_T unusedExpr[1600];
  real_T fval;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVarMax;
  int16_T Cineq_size_idx_0;
  boolean_T exitg1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  exitflag = rtInf;
  nVarMax = 0;
  exitg1 = false;
  while ((!exitg1) && (nVarMax < 40)) {
    if (lb[nVarMax] > ub[nVarMax]) {
      exitflag = -2.0;
      exitg1 = true;
    } else {
      nVarMax++;
    }
  }
  SD->f3.TrialState.cIneq.size[0] = followerMPCandUpdate_anonFcn2(
      nonlcon.workspace.x0, nonlcon.workspace.obstacles.M_l,
      nonlcon.workspace.obstacles.A_bar_l,
      nonlcon.workspace.obstacles.B_bar_l.data,
      nonlcon.workspace.obstacles.B_bar_l.size[0], nonlcon.workspace.N,
      nonlcon.workspace.sys.n, nonlcon.workspace.sys.Ts, x0,
      SD->f3.TrialState.cIneq.data);
  Cineq_size_idx_0 = static_cast<int16_T>(SD->f3.TrialState.cIneq.size[0]);
  mConstrMax =
      (SD->f3.TrialState.cIneq.size[0] + SD->f3.TrialState.cIneq.size[0]) + 81;
  nVarMax = SD->f3.TrialState.cIneq.size[0] + 41;
  maxDims = muIntScalarMax_sint32(nVarMax, mConstrMax);
  if (exitflag == -2.0) {
    fval = rtInf;
    output_iterations = 0.0;
    output_funcCount = 0.0;
    output_algorithm[0] = 's';
    output_algorithm[1] = 'q';
    output_algorithm[2] = 'p';
    output_constrviolation = rtInf;
    output_stepsize = rtInf;
    output_lssteplength = rtInf;
    output_firstorderopt = rtInf;
  } else {
    int32_T i;
    int32_T mLB;
    optim::coder::fminconsqp::TrialState::factoryConstruct(
        SD->f3.TrialState.cIneq.size[0] + 41, mConstrMax,
        SD->f3.TrialState.cIneq.size[0], SD->f3.TrialState.cIneq.size[0],
        SD->f3.TrialState);
    std::copy(&x0[0], &x0[40], &SD->f3.TrialState.xstarsqp[0]);
    SD->f3.FcnEvaluator.next.next.next.next.next.value = Cineq_size_idx_0;
    SD->f3.FcnEvaluator.next.next.next.next.next.next.next.next.value = fun;
    SD->f3.FcnEvaluator.next.next.next.next.next.next.next.value = nonlcon;
    SD->f3.QPObjective.grad.size[0] =
        optim::coder::qpactiveset::Objective::factoryConstruct(
            Cineq_size_idx_0 + 41, SD->f3.QPObjective.Hx.size[0],
            SD->f3.QPObjective.hasLinear, SD->f3.QPObjective.nvar,
            SD->f3.QPObjective.maxVar, SD->f3.QPObjective.beta,
            SD->f3.QPObjective.rho, SD->f3.QPObjective.objtype,
            SD->f3.QPObjective.prev_objtype, SD->f3.QPObjective.prev_nvar,
            SD->f3.QPObjective.prev_hasLinear, SD->f3.QPObjective.gammaScalar);
    SD->f3.QPObjective.hasLinear = true;
    SD->f3.QPObjective.nvar = 40;
    SD->f3.QPObjective.objtype = 3;
    SD->f3.memspace.workspace_float.set_size(maxDims, Cineq_size_idx_0 + 41);
    SD->f3.memspace.workspace_int.size[0] = maxDims;
    SD->f3.memspace.workspace_sort.size[0] = maxDims;
    optim::coder::qpactiveset::WorkingSet::factoryConstruct(
        static_cast<int32_T>(Cineq_size_idx_0), Cineq_size_idx_0 + 41,
        mConstrMax, SD->f3.WorkingSet);
    mLB = optim::coder::qpactiveset::initialize::compressBounds(
        SD->f3.WorkingSet.indexLB.data, SD->f3.WorkingSet.indexUB.data,
        SD->f3.WorkingSet.indexFixed.data, lb, ub, mUB, mFixed);
    optim::coder::qpactiveset::WorkingSet::loadProblem(
        SD->f3.WorkingSet, static_cast<int32_T>(Cineq_size_idx_0), mLB, mUB,
        mFixed, mConstrMax);
    i = static_cast<uint16_T>(mLB);
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->f3.WorkingSet.indexLB.data[mConstrMax];
      SD->f3.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMax(
          SD->f3.TrialState.xstarsqp[nVarMax - 1], lb[nVarMax - 1]);
    }
    i = static_cast<uint16_T>(mUB);
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->f3.WorkingSet.indexUB.data[mConstrMax];
      SD->f3.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMin(
          SD->f3.TrialState.xstarsqp[nVarMax - 1], ub[nVarMax - 1]);
    }
    i = static_cast<uint16_T>(mFixed);
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->f3.WorkingSet.indexFixed.data[mConstrMax];
      SD->f3.TrialState.xstarsqp[nVarMax - 1] = ub[nVarMax - 1];
    }
    SD->f3.TrialState.sqpFval =
        optim::coder::utils::ObjNonlinEvaluator::evalObjAndConstrAndDerivatives(
            SD->f3.FcnEvaluator, SD->f3.TrialState.xstarsqp,
            SD->f3.TrialState.cIneq.data, SD->f3.TrialState.cIneq.size[0],
            SD->f3.TrialState.iNonIneq0, nVarMax);
    SD->f3.FiniteDifferences.objfun = fun;
    SD->f3.FiniteDifferences.nonlin = nonlcon;
    SD->f3.FiniteDifferences.f_1 = 0.0;
    SD->f3.FiniteDifferences.cIneq_1.size[0] = Cineq_size_idx_0;
    SD->f3.FiniteDifferences.mIneq = Cineq_size_idx_0;
    SD->f3.FiniteDifferences.numEvals = 0;
    SD->f3.FiniteDifferences.hasBounds = optim::coder::utils::hasFiniteBounds(
        SD->f3.FiniteDifferences.hasLB, SD->f3.FiniteDifferences.hasUB, lb, ub);
    optim::coder::utils::FiniteDifferences::internal::computeForwardDifferences(
        SD->f3.FiniteDifferences, SD->f3.TrialState.sqpFval,
        SD->f3.TrialState.cIneq.data, SD->f3.TrialState.iNonIneq0,
        SD->f3.TrialState.xstarsqp, SD->f3.TrialState.grad.data,
        SD->f3.WorkingSet.Aineq, SD->f3.TrialState.iNonIneq0,
        SD->f3.WorkingSet.ldA, lb, ub);
    SD->f3.TrialState.FunctionEvaluations =
        SD->f3.FiniteDifferences.numEvals + 1;
    optim::coder::fminconsqp::internal::updateWorkingSetForNewQP(
        x0, SD->f3.WorkingSet, static_cast<int32_T>(Cineq_size_idx_0),
        SD->f3.TrialState.cIneq.data, mLB, lb, mUB, ub, mFixed);
    optim::coder::qpactiveset::WorkingSet::initActiveSet(SD->f3.WorkingSet);
    optim::coder::fminconsqp::MeritFunction::factoryConstruct(
        SD->f3.TrialState.sqpFval, SD->f3.TrialState.cIneq.data,
        static_cast<int32_T>(Cineq_size_idx_0), MeritFunction);
    obj.ldq = maxDims;
    obj.QR.set_size(maxDims, maxDims);
    obj.Q.set_size(maxDims, maxDims);
    nVarMax = maxDims * maxDims;
    for (i = 0; i < nVarMax; i++) {
      obj.Q[i] = 0.0;
    }
    obj.jpvt.size[0] = maxDims;
    std::memset(&obj.jpvt.data[0], 0,
                static_cast<uint32_T>(maxDims) * sizeof(int32_T));
    obj.mrows = 0;
    obj.ncols = 0;
    obj.tau.set_size(muIntScalarMin_sint32(maxDims, maxDims));
    obj.minRowCol = 0;
    obj.usedPivoting = false;
    b_obj.FMat.set_size(maxDims, maxDims);
    b_obj.ldm = maxDims;
    b_obj.ndims = 0;
    b_obj.info = 0;
    b_obj.ConvexCheck = true;
    b_obj.regTol_ = rtInf;
    b_obj.workspace_ = rtInf;
    b_obj.workspace2_ = rtInf;
    optim::coder::fminconsqp::driver(
        SD, lb, ub, SD->f3.TrialState, MeritFunction, SD->f3.FcnEvaluator,
        SD->f3.FiniteDifferences, SD->f3.memspace, SD->f3.WorkingSet, obj,
        b_obj, SD->f3.QPObjective, static_cast<int32_T>(Cineq_size_idx_0),
        unusedExpr);
    std::copy(&SD->f3.TrialState.xstarsqp[0], &SD->f3.TrialState.xstarsqp[40],
              &x0[0]);
    fval = SD->f3.TrialState.sqpFval;
    exitflag = SD->f3.TrialState.sqpExitFlag;
    output_iterations = optim::coder::fminconsqp::parseoutput::fillOutputStruct(
        SD->f3.TrialState.FunctionEvaluations, SD->f3.TrialState.sqpIterations,
        SD->f3.TrialState.steplength, SD->f3.TrialState.delta_x.data,
        MeritFunction.nlpPrimalFeasError, MeritFunction.firstOrderOpt,
        output_funcCount, output_algorithm, output_constrviolation,
        output_stepsize, output_lssteplength, output_firstorderopt);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

real_T d_fmincon(mexFunctionsStackData *SD, const c_anonymous_function &fun,
                 real_T x0[40], const real_T lb[40], const real_T ub[40],
                 const d_anonymous_function &nonlcon, real_T &exitflag,
                 real_T &output_iterations, real_T &output_funcCount,
                 char_T output_algorithm[3], real_T &output_constrviolation,
                 real_T &output_stepsize, real_T &output_lssteplength,
                 real_T &output_firstorderopt)
{
  d_struct_T obj;
  e_struct_T b_obj;
  h_struct_T MeritFunction;
  real_T unusedExpr[1600];
  real_T fval;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVarMax;
  int16_T Cineq_size_idx_0;
  boolean_T exitg1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  exitflag = rtInf;
  nVarMax = 0;
  exitg1 = false;
  while ((!exitg1) && (nVarMax < 40)) {
    if (lb[nVarMax] > ub[nVarMax]) {
      exitflag = -2.0;
      exitg1 = true;
    } else {
      nVarMax++;
    }
  }
  SD->f2.TrialState.cIneq.size[0] = followerMPCandUpdate_anonFcn2(
      nonlcon.workspace.x0, nonlcon.workspace.obstacles.M_l,
      nonlcon.workspace.obstacles.A_bar_l,
      nonlcon.workspace.obstacles.B_bar_l.data,
      nonlcon.workspace.obstacles.B_bar_l.size[0], nonlcon.workspace.N,
      nonlcon.workspace.sys.n, nonlcon.workspace.sys.Ts, x0,
      SD->f2.TrialState.cIneq.data);
  Cineq_size_idx_0 = static_cast<int16_T>(SD->f2.TrialState.cIneq.size[0]);
  mConstrMax =
      (SD->f2.TrialState.cIneq.size[0] + SD->f2.TrialState.cIneq.size[0]) + 81;
  nVarMax = SD->f2.TrialState.cIneq.size[0] + 41;
  maxDims = muIntScalarMax_sint32(nVarMax, mConstrMax);
  if (exitflag == -2.0) {
    fval = rtInf;
    output_iterations = 0.0;
    output_funcCount = 0.0;
    output_algorithm[0] = 's';
    output_algorithm[1] = 'q';
    output_algorithm[2] = 'p';
    output_constrviolation = rtInf;
    output_stepsize = rtInf;
    output_lssteplength = rtInf;
    output_firstorderopt = rtInf;
  } else {
    int32_T i;
    int32_T mLB;
    optim::coder::fminconsqp::TrialState::factoryConstruct(
        SD->f2.TrialState.cIneq.size[0] + 41, mConstrMax,
        SD->f2.TrialState.cIneq.size[0], SD->f2.TrialState.cIneq.size[0],
        SD->f2.TrialState);
    std::copy(&x0[0], &x0[40], &SD->f2.TrialState.xstarsqp[0]);
    SD->f2.FcnEvaluator.next.next.next.next.next.value = Cineq_size_idx_0;
    SD->f2.FcnEvaluator.next.next.next.next.next.next.next.next.value = fun;
    SD->f2.FcnEvaluator.next.next.next.next.next.next.next.value = nonlcon;
    SD->f2.QPObjective.grad.size[0] =
        optim::coder::qpactiveset::Objective::factoryConstruct(
            Cineq_size_idx_0 + 41, SD->f2.QPObjective.Hx.size[0],
            SD->f2.QPObjective.hasLinear, SD->f2.QPObjective.nvar,
            SD->f2.QPObjective.maxVar, SD->f2.QPObjective.beta,
            SD->f2.QPObjective.rho, SD->f2.QPObjective.objtype,
            SD->f2.QPObjective.prev_objtype, SD->f2.QPObjective.prev_nvar,
            SD->f2.QPObjective.prev_hasLinear, SD->f2.QPObjective.gammaScalar);
    SD->f2.QPObjective.hasLinear = true;
    SD->f2.QPObjective.nvar = 40;
    SD->f2.QPObjective.objtype = 3;
    SD->f2.memspace.workspace_float.set_size(maxDims, Cineq_size_idx_0 + 41);
    SD->f2.memspace.workspace_int.size[0] = maxDims;
    SD->f2.memspace.workspace_sort.size[0] = maxDims;
    optim::coder::qpactiveset::WorkingSet::factoryConstruct(
        static_cast<int32_T>(Cineq_size_idx_0), Cineq_size_idx_0 + 41,
        mConstrMax, SD->f2.WorkingSet);
    mLB = optim::coder::qpactiveset::initialize::compressBounds(
        SD->f2.WorkingSet.indexLB.data, SD->f2.WorkingSet.indexUB.data,
        SD->f2.WorkingSet.indexFixed.data, lb, ub, mUB, mFixed);
    optim::coder::qpactiveset::WorkingSet::loadProblem(
        SD->f2.WorkingSet, static_cast<int32_T>(Cineq_size_idx_0), mLB, mUB,
        mFixed, mConstrMax);
    i = static_cast<uint16_T>(mLB);
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->f2.WorkingSet.indexLB.data[mConstrMax];
      SD->f2.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMax(
          SD->f2.TrialState.xstarsqp[nVarMax - 1], lb[nVarMax - 1]);
    }
    i = static_cast<uint16_T>(mUB);
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->f2.WorkingSet.indexUB.data[mConstrMax];
      SD->f2.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMin(
          SD->f2.TrialState.xstarsqp[nVarMax - 1], ub[nVarMax - 1]);
    }
    i = static_cast<uint16_T>(mFixed);
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->f2.WorkingSet.indexFixed.data[mConstrMax];
      SD->f2.TrialState.xstarsqp[nVarMax - 1] = ub[nVarMax - 1];
    }
    SD->f2.TrialState.sqpFval =
        optim::coder::utils::ObjNonlinEvaluator::evalObjAndConstrAndDerivatives(
            SD->f2.FcnEvaluator, SD->f2.TrialState.xstarsqp,
            SD->f2.TrialState.cIneq.data, SD->f2.TrialState.cIneq.size[0],
            SD->f2.TrialState.iNonIneq0, nVarMax);
    SD->f2.FiniteDifferences.objfun = fun;
    SD->f2.FiniteDifferences.nonlin = nonlcon;
    SD->f2.FiniteDifferences.f_1 = 0.0;
    SD->f2.FiniteDifferences.cIneq_1.size[0] = Cineq_size_idx_0;
    SD->f2.FiniteDifferences.mIneq = Cineq_size_idx_0;
    SD->f2.FiniteDifferences.numEvals = 0;
    SD->f2.FiniteDifferences.hasBounds = optim::coder::utils::hasFiniteBounds(
        SD->f2.FiniteDifferences.hasLB, SD->f2.FiniteDifferences.hasUB, lb, ub);
    optim::coder::utils::FiniteDifferences::internal::computeForwardDifferences(
        SD->f2.FiniteDifferences, SD->f2.TrialState.sqpFval,
        SD->f2.TrialState.cIneq.data, SD->f2.TrialState.iNonIneq0,
        SD->f2.TrialState.xstarsqp, SD->f2.TrialState.grad.data,
        SD->f2.WorkingSet.Aineq, SD->f2.TrialState.iNonIneq0,
        SD->f2.WorkingSet.ldA, lb, ub);
    SD->f2.TrialState.FunctionEvaluations =
        SD->f2.FiniteDifferences.numEvals + 1;
    optim::coder::fminconsqp::internal::updateWorkingSetForNewQP(
        x0, SD->f2.WorkingSet, static_cast<int32_T>(Cineq_size_idx_0),
        SD->f2.TrialState.cIneq.data, mLB, lb, mUB, ub, mFixed);
    optim::coder::qpactiveset::WorkingSet::initActiveSet(SD->f2.WorkingSet);
    optim::coder::fminconsqp::MeritFunction::factoryConstruct(
        SD->f2.TrialState.sqpFval, SD->f2.TrialState.cIneq.data,
        static_cast<int32_T>(Cineq_size_idx_0), MeritFunction);
    obj.ldq = maxDims;
    obj.QR.set_size(maxDims, maxDims);
    obj.Q.set_size(maxDims, maxDims);
    nVarMax = maxDims * maxDims;
    for (i = 0; i < nVarMax; i++) {
      obj.Q[i] = 0.0;
    }
    obj.jpvt.size[0] = maxDims;
    std::memset(&obj.jpvt.data[0], 0,
                static_cast<uint32_T>(maxDims) * sizeof(int32_T));
    obj.mrows = 0;
    obj.ncols = 0;
    obj.tau.set_size(muIntScalarMin_sint32(maxDims, maxDims));
    obj.minRowCol = 0;
    obj.usedPivoting = false;
    b_obj.FMat.set_size(maxDims, maxDims);
    b_obj.ldm = maxDims;
    b_obj.ndims = 0;
    b_obj.info = 0;
    b_obj.ConvexCheck = true;
    b_obj.regTol_ = rtInf;
    b_obj.workspace_ = rtInf;
    b_obj.workspace2_ = rtInf;
    optim::coder::fminconsqp::driver(
        SD, lb, ub, SD->f2.TrialState, MeritFunction, SD->f2.FcnEvaluator,
        SD->f2.FiniteDifferences, SD->f2.memspace, SD->f2.WorkingSet, obj,
        b_obj, SD->f2.QPObjective, static_cast<int32_T>(Cineq_size_idx_0),
        unusedExpr);
    std::copy(&SD->f2.TrialState.xstarsqp[0], &SD->f2.TrialState.xstarsqp[40],
              &x0[0]);
    fval = SD->f2.TrialState.sqpFval;
    exitflag = SD->f2.TrialState.sqpExitFlag;
    output_iterations = optim::coder::fminconsqp::parseoutput::fillOutputStruct(
        SD->f2.TrialState.FunctionEvaluations, SD->f2.TrialState.sqpIterations,
        SD->f2.TrialState.steplength, SD->f2.TrialState.delta_x.data,
        MeritFunction.nlpPrimalFeasError, MeritFunction.firstOrderOpt,
        output_funcCount, output_algorithm, output_constrviolation,
        output_stepsize, output_lssteplength, output_firstorderopt);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

real_T d_fmincon(mexFunctionsStackData *SD, const anonymous_function &fun,
                 real_T x0[40], const real_T lb[40], const real_T ub[40],
                 const b_anonymous_function &nonlcon, real_T &exitflag,
                 real_T &output_iterations, real_T &output_funcCount,
                 char_T output_algorithm[3], real_T &output_constrviolation,
                 real_T &output_stepsize, real_T &output_lssteplength,
                 real_T &output_firstorderopt)
{
  internal::bb_stickyStruct FcnEvaluator;
  d_struct_T obj;
  e_struct_T b_obj;
  h_struct_T MeritFunction;
  real_T unusedExpr[1600];
  real_T fval;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVarMax;
  int16_T Cineq_size_idx_0;
  boolean_T exitg1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  exitflag = rtInf;
  nVarMax = 0;
  exitg1 = false;
  while ((!exitg1) && (nVarMax < 40)) {
    if (lb[nVarMax] > ub[nVarMax]) {
      exitflag = -2.0;
      exitg1 = true;
    } else {
      nVarMax++;
    }
  }
  SD->f1.TrialState.cIneq.size[0] = followerMPCandUpdate_anonFcn2(
      nonlcon.workspace.x0, nonlcon.workspace.obstacles.M_f,
      nonlcon.workspace.obstacles.A_bar_f,
      nonlcon.workspace.obstacles.B_bar_f.data,
      nonlcon.workspace.obstacles.B_bar_f.size[0], nonlcon.workspace.N,
      nonlcon.workspace.sys.n, nonlcon.workspace.sys.Ts, x0,
      SD->f1.TrialState.cIneq.data);
  Cineq_size_idx_0 = static_cast<int16_T>(SD->f1.TrialState.cIneq.size[0]);
  mConstrMax =
      (SD->f1.TrialState.cIneq.size[0] + SD->f1.TrialState.cIneq.size[0]) + 81;
  nVarMax = SD->f1.TrialState.cIneq.size[0] + 41;
  maxDims = muIntScalarMax_sint32(nVarMax, mConstrMax);
  if (exitflag == -2.0) {
    fval = rtInf;
    output_iterations = 0.0;
    output_funcCount = 0.0;
    output_algorithm[0] = 's';
    output_algorithm[1] = 'q';
    output_algorithm[2] = 'p';
    output_constrviolation = rtInf;
    output_stepsize = rtInf;
    output_lssteplength = rtInf;
    output_firstorderopt = rtInf;
  } else {
    int32_T i;
    int32_T mLB;
    optim::coder::fminconsqp::TrialState::factoryConstruct(
        SD->f1.TrialState.cIneq.size[0] + 41, mConstrMax,
        SD->f1.TrialState.cIneq.size[0], SD->f1.TrialState.cIneq.size[0],
        SD->f1.TrialState);
    std::copy(&x0[0], &x0[40], &SD->f1.TrialState.xstarsqp[0]);
    FcnEvaluator.next.next.next.next.next.value = Cineq_size_idx_0;
    FcnEvaluator.next.next.next.next.next.next.next.next.value = fun;
    FcnEvaluator.next.next.next.next.next.next.next.value = nonlcon;
    SD->f1.QPObjective.grad.size[0] =
        optim::coder::qpactiveset::Objective::factoryConstruct(
            Cineq_size_idx_0 + 41, SD->f1.QPObjective.Hx.size[0],
            SD->f1.QPObjective.hasLinear, SD->f1.QPObjective.nvar,
            SD->f1.QPObjective.maxVar, SD->f1.QPObjective.beta,
            SD->f1.QPObjective.rho, SD->f1.QPObjective.objtype,
            SD->f1.QPObjective.prev_objtype, SD->f1.QPObjective.prev_nvar,
            SD->f1.QPObjective.prev_hasLinear, SD->f1.QPObjective.gammaScalar);
    SD->f1.QPObjective.hasLinear = true;
    SD->f1.QPObjective.nvar = 40;
    SD->f1.QPObjective.objtype = 3;
    SD->f1.memspace.workspace_float.set_size(maxDims, Cineq_size_idx_0 + 41);
    SD->f1.memspace.workspace_int.size[0] = maxDims;
    SD->f1.memspace.workspace_sort.size[0] = maxDims;
    optim::coder::qpactiveset::WorkingSet::factoryConstruct(
        static_cast<int32_T>(Cineq_size_idx_0), Cineq_size_idx_0 + 41,
        mConstrMax, SD->f1.WorkingSet);
    mLB = optim::coder::qpactiveset::initialize::compressBounds(
        SD->f1.WorkingSet.indexLB.data, SD->f1.WorkingSet.indexUB.data,
        SD->f1.WorkingSet.indexFixed.data, lb, ub, mUB, mFixed);
    optim::coder::qpactiveset::WorkingSet::loadProblem(
        SD->f1.WorkingSet, static_cast<int32_T>(Cineq_size_idx_0), mLB, mUB,
        mFixed, mConstrMax);
    i = static_cast<uint16_T>(mLB);
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->f1.WorkingSet.indexLB.data[mConstrMax];
      SD->f1.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMax(
          SD->f1.TrialState.xstarsqp[nVarMax - 1], lb[nVarMax - 1]);
    }
    i = static_cast<uint16_T>(mUB);
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->f1.WorkingSet.indexUB.data[mConstrMax];
      SD->f1.TrialState.xstarsqp[nVarMax - 1] = muDoubleScalarMin(
          SD->f1.TrialState.xstarsqp[nVarMax - 1], ub[nVarMax - 1]);
    }
    i = static_cast<uint16_T>(mFixed);
    for (mConstrMax = 0; mConstrMax < i; mConstrMax++) {
      nVarMax = SD->f1.WorkingSet.indexFixed.data[mConstrMax];
      SD->f1.TrialState.xstarsqp[nVarMax - 1] = ub[nVarMax - 1];
    }
    fval = followerMPCandUpdate_anonFcn1(
        fun.workspace.x0, fun.workspace.sys.n, fun.workspace.sys.Ts,
        fun.workspace.N, fun.workspace.X_L_stacked,
        fun.workspace.robotParams.Px, fun.workspace.robotParams.d_FL_sq,
        fun.workspace.robotParams.C, fun.workspace.robotParams.beta_N,
        SD->f1.TrialState.xstarsqp);
    if ((!muDoubleScalarIsInf(fval)) && (!muDoubleScalarIsNaN(fval))) {
      optim::coder::utils::ObjNonlinEvaluator::computeConstraints_(
          FcnEvaluator, SD->f1.TrialState.xstarsqp,
          SD->f1.TrialState.cIneq.data, SD->f1.TrialState.iNonIneq0);
    }
    SD->f1.TrialState.sqpFval = fval;
    SD->f1.obj.objfun = fun;
    SD->f1.obj.nonlin = nonlcon;
    SD->f1.obj.f_1 = 0.0;
    SD->f1.obj.cIneq_1.size[0] = Cineq_size_idx_0;
    SD->f1.obj.mIneq = Cineq_size_idx_0;
    SD->f1.obj.numEvals = 0;
    SD->f1.obj.hasBounds = optim::coder::utils::hasFiniteBounds(
        SD->f1.obj.hasLB, SD->f1.obj.hasUB, lb, ub);
    optim::coder::utils::FiniteDifferences::computeFiniteDifferences(
        SD->f1.obj, fval, SD->f1.TrialState.cIneq.data,
        SD->f1.TrialState.iNonIneq0, SD->f1.TrialState.xstarsqp,
        SD->f1.TrialState.grad.data, SD->f1.WorkingSet.Aineq,
        SD->f1.TrialState.iNonIneq0, SD->f1.WorkingSet.ldA, lb, ub);
    SD->f1.TrialState.FunctionEvaluations = SD->f1.obj.numEvals + 1;
    optim::coder::fminconsqp::internal::updateWorkingSetForNewQP(
        x0, SD->f1.WorkingSet, static_cast<int32_T>(Cineq_size_idx_0),
        SD->f1.TrialState.cIneq.data, mLB, lb, mUB, ub, mFixed);
    optim::coder::qpactiveset::WorkingSet::initActiveSet(SD->f1.WorkingSet);
    optim::coder::fminconsqp::MeritFunction::factoryConstruct(
        fval, SD->f1.TrialState.cIneq.data,
        static_cast<int32_T>(Cineq_size_idx_0), MeritFunction);
    obj.ldq = maxDims;
    obj.QR.set_size(maxDims, maxDims);
    obj.Q.set_size(maxDims, maxDims);
    nVarMax = maxDims * maxDims;
    for (i = 0; i < nVarMax; i++) {
      obj.Q[i] = 0.0;
    }
    obj.jpvt.size[0] = maxDims;
    std::memset(&obj.jpvt.data[0], 0,
                static_cast<uint32_T>(maxDims) * sizeof(int32_T));
    obj.mrows = 0;
    obj.ncols = 0;
    obj.tau.set_size(muIntScalarMin_sint32(maxDims, maxDims));
    obj.minRowCol = 0;
    obj.usedPivoting = false;
    b_obj.FMat.set_size(maxDims, maxDims);
    b_obj.ldm = maxDims;
    b_obj.ndims = 0;
    b_obj.info = 0;
    b_obj.ConvexCheck = true;
    b_obj.regTol_ = rtInf;
    b_obj.workspace_ = rtInf;
    b_obj.workspace2_ = rtInf;
    optim::coder::fminconsqp::driver(
        SD, lb, ub, SD->f1.TrialState, MeritFunction, FcnEvaluator, SD->f1.obj,
        SD->f1.memspace, SD->f1.WorkingSet, obj, b_obj, SD->f1.QPObjective,
        static_cast<int32_T>(Cineq_size_idx_0), unusedExpr);
    std::copy(&SD->f1.TrialState.xstarsqp[0], &SD->f1.TrialState.xstarsqp[40],
              &x0[0]);
    fval = SD->f1.TrialState.sqpFval;
    exitflag = SD->f1.TrialState.sqpExitFlag;
    output_iterations = optim::coder::fminconsqp::parseoutput::fillOutputStruct(
        SD->f1.TrialState.FunctionEvaluations, SD->f1.TrialState.sqpIterations,
        SD->f1.TrialState.steplength, SD->f1.TrialState.delta_x.data,
        MeritFunction.nlpPrimalFeasError, MeritFunction.firstOrderOpt,
        output_funcCount, output_algorithm, output_constrviolation,
        output_stepsize, output_lssteplength, output_firstorderopt);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return fval;
}

} // namespace coder

// End of code generation (fmincon.cpp)
