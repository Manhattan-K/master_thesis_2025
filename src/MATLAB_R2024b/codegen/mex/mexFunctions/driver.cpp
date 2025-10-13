//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// driver.cpp
//
// Code generation for function 'driver'
//

// Include files
#include "driver.h"
#include "BFGSUpdate.h"
#include "anonymous_function.h"
#include "computeConstraints_.h"
#include "computeDeltaLag.h"
#include "computeFiniteDifferences.h"
#include "computeForwardDifferences.h"
#include "computeLinearResiduals.h"
#include "followerMPCandUpdate.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "linesearch.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "mexFunctions_types1.h"
#include "mexFunctions_types2.h"
#include "revertSolution.h"
#include "rt_nonfinite.h"
#include "saveJacobian.h"
#include "saveState.h"
#include "step.h"
#include "stickyStruct.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static const int8_T iv[1600]{
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void driver(mexFunctionsStackData *SD, const real_T lb[40], const real_T ub[40],
            f_struct_T &b_TrialState, h_struct_T &b_MeritFunction,
            const ::coder::internal::r_stickyStruct &FcnEvaluator,
            q_struct_T &FiniteDifferences, c_struct_T &memspace,
            g_struct_T &WorkingSet, d_struct_T &b_QRManager,
            e_struct_T &b_CholManager, b_struct_T &QPObjective,
            int32_T fscales_cineq_constraint_size, real_T Hessian[1600])
{
  static const char_T qpoptions_SolverName[7]{'f', 'm', 'i', 'n',
                                              'c', 'o', 'n'};
  i_struct_T expl_temp;
  struct_T Flags;
  int32_T i;
  int32_T mConstr;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLinIneq;
  int32_T mUB;
  int32_T nVar;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  for (i = 0; i < 1600; i++) {
    Hessian[i] = iv[i];
  }
  nVar = WorkingSet.nVar;
  mFixed = WorkingSet.sizes[0];
  mIneq = WorkingSet.sizes[2];
  mLB = WorkingSet.sizes[3];
  mUB = WorkingSet.sizes[4];
  mConstr =
      ((WorkingSet.sizes[0] + WorkingSet.sizes[2]) + WorkingSet.sizes[3]) +
      WorkingSet.sizes[4];
  mLinIneq = WorkingSet.sizes[2] - b_TrialState.mNonlinIneq;
  y = ((WorkingSet.sizes[2] + WorkingSet.sizes[3]) + WorkingSet.sizes[4]) +
      (WorkingSet.sizes[0] << 1);
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet.nVar, y);
  b_TrialState.steplength = 1.0;
  Flags.gradOK =
      test_exit(b_MeritFunction, fscales_cineq_constraint_size, WorkingSet,
                b_TrialState, lb, ub, Flags.fevalOK, Flags.done,
                Flags.stepAccepted, Flags.failedLineSearch, Flags.stepType);
  TrialState::saveJacobian(b_TrialState, nVar, mIneq, WorkingSet.Aineq,
                           b_TrialState.iNonIneq0, WorkingSet.ldA);
  TrialState::saveState(b_TrialState);
  if (!Flags.done) {
    b_TrialState.sqpIterations = 1;
  }
  while (!Flags.done) {
    real_T d;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      boolean_T socTaken;
      if (Flags.stepType != 3) {
        internal::updateWorkingSetForNewQP(
            b_TrialState.xstarsqp, WorkingSet, mIneq, b_TrialState.mNonlinIneq,
            b_TrialState.cIneq.data, mLB, lb, mUB, ub, mFixed);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }
      b_step(SD, Flags, Hessian, lb, ub, b_TrialState, b_MeritFunction,
             memspace, WorkingSet, b_QRManager, b_CholManager, QPObjective,
             expl_temp);
      if (Flags.stepAccepted) {
        real_T fval;
        i = static_cast<uint16_T>(nVar);
        for (y = 0; y < i; y++) {
          b_TrialState.xstarsqp[y] += b_TrialState.delta_x.data[y];
        }
        fval = leaderMPCandUpdateHalt_anonFcn1(
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .x0,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .sys.n,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .sys.Ts,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .N,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .robotParams.Px,
            b_TrialState.xstarsqp);
        y = 1;
        socTaken = muDoubleScalarIsNaN(fval);
        if (muDoubleScalarIsInf(fval) || socTaken) {
          if (socTaken) {
            y = -3;
          } else if (fval < 0.0) {
            y = -1;
          } else {
            y = -2;
          }
        }
        if (y == 1) {
          y = utils::ObjNonlinEvaluator::computeConstraints_(
              FcnEvaluator, b_TrialState.xstarsqp, b_TrialState.cIneq.data,
              b_TrialState.iNonIneq0);
        }
        b_TrialState.sqpFval = fval;
        Flags.fevalOK = (y == 1);
        b_TrialState.FunctionEvaluations++;
        internal::computeLinearResiduals(b_TrialState.xstarsqp, nVar,
                                         b_TrialState.cIneq.data, mLinIneq,
                                         WorkingSet.Aineq, WorkingSet.ldA);
        if (Flags.fevalOK) {
          real_T constrViolationIneq;
          constrViolationIneq = 0.0;
          i = static_cast<uint16_T>(mIneq);
          for (y = 0; y < i; y++) {
            d = b_TrialState.cIneq.data[y];
            if (d > 0.0) {
              constrViolationIneq += d;
            }
          }
          b_MeritFunction.phiFullStep =
              fval + b_MeritFunction.penaltyParam * constrViolationIneq;
        } else {
          b_MeritFunction.phiFullStep = rtInf;
        }
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (b_MeritFunction.phi < b_MeritFunction.phiFullStep) &&
          (b_TrialState.sqpFval < b_TrialState.sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        d = c_linesearch(
            Flags.fevalOK, WorkingSet.nVar, WorkingSet.ldA, WorkingSet.Aineq,
            b_TrialState, b_MeritFunction.penaltyParam, b_MeritFunction.phi,
            b_MeritFunction.phiPrimePlus, b_MeritFunction.phiFullStep,
            FcnEvaluator, socTaken, y);
        b_TrialState.steplength = d;
        if (y > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      i = static_cast<uint16_T>(nVar);
      for (y = 0; y < i; y++) {
        b_TrialState.xstarsqp[y] =
            b_TrialState.xstarsqp_old[y] + b_TrialState.delta_x.data[y];
      }
      i = static_cast<uint16_T>(mConstr);
      for (y = 0; y < i; y++) {
        d = b_TrialState.lambdasqp[y];
        d += b_TrialState.steplength * (b_TrialState.lambda[y] - d);
        b_TrialState.lambdasqp[y] = d;
      }
      TrialState::saveState(b_TrialState);
      Flags.gradOK =
          utils::FiniteDifferences::internal::computeForwardDifferences(
              FiniteDifferences, b_TrialState.sqpFval, b_TrialState.cIneq.data,
              b_TrialState.iNonIneq0, b_TrialState.xstarsqp,
              b_TrialState.grad.data, WorkingSet.Aineq, b_TrialState.iNonIneq0,
              WorkingSet.ldA, lb, ub);
      b_TrialState.FunctionEvaluations += FiniteDifferences.numEvals;
    } else {
      TrialState::revertSolution(b_TrialState);
    }
    b_test_exit(Flags, memspace, b_MeritFunction, fscales_cineq_constraint_size,
                WorkingSet, b_TrialState, b_QRManager, lb, ub);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      stopping::computeDeltaLag(
          nVar, WorkingSet.ldA, b_TrialState.mNonlinIneq,
          b_TrialState.delta_gradLag.data, b_TrialState.grad.data,
          WorkingSet.Aineq, b_TrialState.iNonIneq0, b_TrialState.grad_old.data,
          b_TrialState.JacCineqTrans_old, b_TrialState.lambdasqp,
          mFixed + b_TrialState.iNonIneq0);
      TrialState::saveJacobian(b_TrialState, nVar, mIneq, WorkingSet.Aineq,
                               b_TrialState.iNonIneq0, WorkingSet.ldA);
      BFGSUpdate(nVar, Hessian, b_TrialState.delta_x.data,
                 b_TrialState.delta_gradLag.data, memspace.workspace_float);
      b_TrialState.sqpIterations++;
    }
  }
}

void driver(mexFunctionsStackData *SD, const real_T lb[40], const real_T ub[40],
            f_struct_T &b_TrialState, h_struct_T &b_MeritFunction,
            const ::coder::internal::i_stickyStruct &FcnEvaluator,
            p_struct_T &FiniteDifferences, c_struct_T &memspace,
            g_struct_T &WorkingSet, d_struct_T &b_QRManager,
            e_struct_T &b_CholManager, b_struct_T &QPObjective,
            int32_T fscales_cineq_constraint_size, real_T Hessian[1600])
{
  static const char_T qpoptions_SolverName[7]{'f', 'm', 'i', 'n',
                                              'c', 'o', 'n'};
  i_struct_T expl_temp;
  struct_T Flags;
  int32_T i;
  int32_T mConstr;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLinIneq;
  int32_T mUB;
  int32_T nVar;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  for (i = 0; i < 1600; i++) {
    Hessian[i] = iv[i];
  }
  nVar = WorkingSet.nVar;
  mFixed = WorkingSet.sizes[0];
  mIneq = WorkingSet.sizes[2];
  mLB = WorkingSet.sizes[3];
  mUB = WorkingSet.sizes[4];
  mConstr =
      ((WorkingSet.sizes[0] + WorkingSet.sizes[2]) + WorkingSet.sizes[3]) +
      WorkingSet.sizes[4];
  mLinIneq = WorkingSet.sizes[2] - b_TrialState.mNonlinIneq;
  y = ((WorkingSet.sizes[2] + WorkingSet.sizes[3]) + WorkingSet.sizes[4]) +
      (WorkingSet.sizes[0] << 1);
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet.nVar, y);
  b_TrialState.steplength = 1.0;
  Flags.gradOK =
      test_exit(b_MeritFunction, fscales_cineq_constraint_size, WorkingSet,
                b_TrialState, lb, ub, Flags.fevalOK, Flags.done,
                Flags.stepAccepted, Flags.failedLineSearch, Flags.stepType);
  TrialState::saveJacobian(b_TrialState, nVar, mIneq, WorkingSet.Aineq,
                           b_TrialState.iNonIneq0, WorkingSet.ldA);
  TrialState::saveState(b_TrialState);
  if (!Flags.done) {
    b_TrialState.sqpIterations = 1;
  }
  while (!Flags.done) {
    real_T d;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      boolean_T socTaken;
      if (Flags.stepType != 3) {
        internal::updateWorkingSetForNewQP(
            b_TrialState.xstarsqp, WorkingSet, mIneq, b_TrialState.mNonlinIneq,
            b_TrialState.cIneq.data, mLB, lb, mUB, ub, mFixed);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }
      b_step(SD, Flags, Hessian, lb, ub, b_TrialState, b_MeritFunction,
             memspace, WorkingSet, b_QRManager, b_CholManager, QPObjective,
             expl_temp);
      if (Flags.stepAccepted) {
        real_T fval;
        i = static_cast<uint16_T>(nVar);
        for (y = 0; y < i; y++) {
          b_TrialState.xstarsqp[y] += b_TrialState.delta_x.data[y];
        }
        fval = leaderMPCandUpdate_anonFcn1(
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .x0,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .sys.n,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .sys.Ts,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .robotParams.W,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .robotParams.W_hat,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .robotParams.R_hat,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .N,
            b_TrialState.xstarsqp);
        y = 1;
        socTaken = muDoubleScalarIsNaN(fval);
        if (muDoubleScalarIsInf(fval) || socTaken) {
          if (socTaken) {
            y = -3;
          } else if (fval < 0.0) {
            y = -1;
          } else {
            y = -2;
          }
        }
        if (y == 1) {
          y = utils::ObjNonlinEvaluator::computeConstraints_(
              FcnEvaluator, b_TrialState.xstarsqp, b_TrialState.cIneq.data,
              b_TrialState.iNonIneq0);
        }
        b_TrialState.sqpFval = fval;
        Flags.fevalOK = (y == 1);
        b_TrialState.FunctionEvaluations++;
        internal::computeLinearResiduals(b_TrialState.xstarsqp, nVar,
                                         b_TrialState.cIneq.data, mLinIneq,
                                         WorkingSet.Aineq, WorkingSet.ldA);
        if (Flags.fevalOK) {
          real_T constrViolationIneq;
          constrViolationIneq = 0.0;
          i = static_cast<uint16_T>(mIneq);
          for (y = 0; y < i; y++) {
            d = b_TrialState.cIneq.data[y];
            if (d > 0.0) {
              constrViolationIneq += d;
            }
          }
          b_MeritFunction.phiFullStep =
              fval + b_MeritFunction.penaltyParam * constrViolationIneq;
        } else {
          b_MeritFunction.phiFullStep = rtInf;
        }
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (b_MeritFunction.phi < b_MeritFunction.phiFullStep) &&
          (b_TrialState.sqpFval < b_TrialState.sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        d = b_linesearch(
            Flags.fevalOK, WorkingSet.nVar, WorkingSet.ldA, WorkingSet.Aineq,
            b_TrialState, b_MeritFunction.penaltyParam, b_MeritFunction.phi,
            b_MeritFunction.phiPrimePlus, b_MeritFunction.phiFullStep,
            FcnEvaluator, socTaken, y);
        b_TrialState.steplength = d;
        if (y > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      i = static_cast<uint16_T>(nVar);
      for (y = 0; y < i; y++) {
        b_TrialState.xstarsqp[y] =
            b_TrialState.xstarsqp_old[y] + b_TrialState.delta_x.data[y];
      }
      i = static_cast<uint16_T>(mConstr);
      for (y = 0; y < i; y++) {
        d = b_TrialState.lambdasqp[y];
        d += b_TrialState.steplength * (b_TrialState.lambda[y] - d);
        b_TrialState.lambdasqp[y] = d;
      }
      TrialState::saveState(b_TrialState);
      Flags.gradOK =
          utils::FiniteDifferences::internal::computeForwardDifferences(
              FiniteDifferences, b_TrialState.sqpFval, b_TrialState.cIneq.data,
              b_TrialState.iNonIneq0, b_TrialState.xstarsqp,
              b_TrialState.grad.data, WorkingSet.Aineq, b_TrialState.iNonIneq0,
              WorkingSet.ldA, lb, ub);
      b_TrialState.FunctionEvaluations += FiniteDifferences.numEvals;
    } else {
      TrialState::revertSolution(b_TrialState);
    }
    b_test_exit(Flags, memspace, b_MeritFunction, fscales_cineq_constraint_size,
                WorkingSet, b_TrialState, b_QRManager, lb, ub);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      stopping::computeDeltaLag(
          nVar, WorkingSet.ldA, b_TrialState.mNonlinIneq,
          b_TrialState.delta_gradLag.data, b_TrialState.grad.data,
          WorkingSet.Aineq, b_TrialState.iNonIneq0, b_TrialState.grad_old.data,
          b_TrialState.JacCineqTrans_old, b_TrialState.lambdasqp,
          mFixed + b_TrialState.iNonIneq0);
      TrialState::saveJacobian(b_TrialState, nVar, mIneq, WorkingSet.Aineq,
                               b_TrialState.iNonIneq0, WorkingSet.ldA);
      BFGSUpdate(nVar, Hessian, b_TrialState.delta_x.data,
                 b_TrialState.delta_gradLag.data, memspace.workspace_float);
      b_TrialState.sqpIterations++;
    }
  }
}

void driver(mexFunctionsStackData *SD, const real_T lb[40], const real_T ub[40],
            f_struct_T &b_TrialState, h_struct_T &b_MeritFunction,
            const ::coder::internal::bb_stickyStruct &FcnEvaluator,
            o_struct_T &FiniteDifferences, c_struct_T &memspace,
            g_struct_T &WorkingSet, d_struct_T &b_QRManager,
            e_struct_T &b_CholManager, b_struct_T &QPObjective,
            int32_T fscales_cineq_constraint_size, real_T Hessian[1600])
{
  static const char_T qpoptions_SolverName[7]{'f', 'm', 'i', 'n',
                                              'c', 'o', 'n'};
  i_struct_T expl_temp;
  struct_T Flags;
  int32_T i;
  int32_T mConstr;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLinIneq;
  int32_T mUB;
  int32_T nVar;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  for (i = 0; i < 1600; i++) {
    Hessian[i] = iv[i];
  }
  nVar = WorkingSet.nVar;
  mFixed = WorkingSet.sizes[0];
  mIneq = WorkingSet.sizes[2];
  mLB = WorkingSet.sizes[3];
  mUB = WorkingSet.sizes[4];
  mConstr =
      ((WorkingSet.sizes[0] + WorkingSet.sizes[2]) + WorkingSet.sizes[3]) +
      WorkingSet.sizes[4];
  mLinIneq = WorkingSet.sizes[2] - b_TrialState.mNonlinIneq;
  y = ((WorkingSet.sizes[2] + WorkingSet.sizes[3]) + WorkingSet.sizes[4]) +
      (WorkingSet.sizes[0] << 1);
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet.nVar, y);
  b_TrialState.steplength = 1.0;
  Flags.gradOK =
      test_exit(b_MeritFunction, fscales_cineq_constraint_size, WorkingSet,
                b_TrialState, lb, ub, Flags.fevalOK, Flags.done,
                Flags.stepAccepted, Flags.failedLineSearch, Flags.stepType);
  TrialState::saveJacobian(b_TrialState, nVar, mIneq, WorkingSet.Aineq,
                           b_TrialState.iNonIneq0, WorkingSet.ldA);
  TrialState::saveState(b_TrialState);
  if (!Flags.done) {
    b_TrialState.sqpIterations = 1;
  }
  while (!Flags.done) {
    real_T d;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      boolean_T socTaken;
      if (Flags.stepType != 3) {
        internal::updateWorkingSetForNewQP(
            b_TrialState.xstarsqp, WorkingSet, mIneq, b_TrialState.mNonlinIneq,
            b_TrialState.cIneq.data, mLB, lb, mUB, ub, mFixed);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }
      b_step(SD, Flags, Hessian, lb, ub, b_TrialState, b_MeritFunction,
             memspace, WorkingSet, b_QRManager, b_CholManager, QPObjective,
             expl_temp);
      if (Flags.stepAccepted) {
        real_T fval;
        i = static_cast<uint16_T>(nVar);
        for (y = 0; y < i; y++) {
          b_TrialState.xstarsqp[y] += b_TrialState.delta_x.data[y];
        }
        fval = followerMPCandUpdate_anonFcn1(
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .x0,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .sys.n,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .sys.Ts,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .N,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .X_L_stacked,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .robotParams.Px,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .robotParams.d_FL_sq,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .robotParams.C,
            FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace
                .robotParams.beta_N,
            b_TrialState.xstarsqp);
        y = 1;
        socTaken = muDoubleScalarIsNaN(fval);
        if (muDoubleScalarIsInf(fval) || socTaken) {
          if (socTaken) {
            y = -3;
          } else if (fval < 0.0) {
            y = -1;
          } else {
            y = -2;
          }
        }
        if (y == 1) {
          y = utils::ObjNonlinEvaluator::computeConstraints_(
              FcnEvaluator, b_TrialState.xstarsqp, b_TrialState.cIneq.data,
              b_TrialState.iNonIneq0);
        }
        b_TrialState.sqpFval = fval;
        Flags.fevalOK = (y == 1);
        b_TrialState.FunctionEvaluations++;
        internal::computeLinearResiduals(b_TrialState.xstarsqp, nVar,
                                         b_TrialState.cIneq.data, mLinIneq,
                                         WorkingSet.Aineq, WorkingSet.ldA);
        if (Flags.fevalOK) {
          real_T constrViolationIneq;
          constrViolationIneq = 0.0;
          i = static_cast<uint16_T>(mIneq);
          for (y = 0; y < i; y++) {
            d = b_TrialState.cIneq.data[y];
            if (d > 0.0) {
              constrViolationIneq += d;
            }
          }
          b_MeritFunction.phiFullStep =
              fval + b_MeritFunction.penaltyParam * constrViolationIneq;
        } else {
          b_MeritFunction.phiFullStep = rtInf;
        }
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (b_MeritFunction.phi < b_MeritFunction.phiFullStep) &&
          (b_TrialState.sqpFval < b_TrialState.sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        d = linesearch(Flags.fevalOK, WorkingSet.nVar, WorkingSet.ldA,
                       WorkingSet.Aineq, b_TrialState,
                       b_MeritFunction.penaltyParam, b_MeritFunction.phi,
                       b_MeritFunction.phiPrimePlus,
                       b_MeritFunction.phiFullStep, FcnEvaluator, socTaken, y);
        b_TrialState.steplength = d;
        if (y > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      i = static_cast<uint16_T>(nVar);
      for (y = 0; y < i; y++) {
        b_TrialState.xstarsqp[y] =
            b_TrialState.xstarsqp_old[y] + b_TrialState.delta_x.data[y];
      }
      i = static_cast<uint16_T>(mConstr);
      for (y = 0; y < i; y++) {
        d = b_TrialState.lambdasqp[y];
        d += b_TrialState.steplength * (b_TrialState.lambda[y] - d);
        b_TrialState.lambdasqp[y] = d;
      }
      TrialState::saveState(b_TrialState);
      Flags.gradOK = utils::FiniteDifferences::computeFiniteDifferences(
          FiniteDifferences, b_TrialState.sqpFval, b_TrialState.cIneq.data,
          b_TrialState.iNonIneq0, b_TrialState.xstarsqp, b_TrialState.grad.data,
          WorkingSet.Aineq, b_TrialState.iNonIneq0, WorkingSet.ldA, lb, ub);
      b_TrialState.FunctionEvaluations += FiniteDifferences.numEvals;
    } else {
      TrialState::revertSolution(b_TrialState);
    }
    b_test_exit(Flags, memspace, b_MeritFunction, fscales_cineq_constraint_size,
                WorkingSet, b_TrialState, b_QRManager, lb, ub);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      stopping::computeDeltaLag(
          nVar, WorkingSet.ldA, b_TrialState.mNonlinIneq,
          b_TrialState.delta_gradLag.data, b_TrialState.grad.data,
          WorkingSet.Aineq, b_TrialState.iNonIneq0, b_TrialState.grad_old.data,
          b_TrialState.JacCineqTrans_old, b_TrialState.lambdasqp,
          mFixed + b_TrialState.iNonIneq0);
      TrialState::saveJacobian(b_TrialState, nVar, mIneq, WorkingSet.Aineq,
                               b_TrialState.iNonIneq0, WorkingSet.ldA);
      BFGSUpdate(nVar, Hessian, b_TrialState.delta_x.data,
                 b_TrialState.delta_gradLag.data, memspace.workspace_float);
      b_TrialState.sqpIterations++;
    }
  }
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (driver.cpp)
