/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver.c
 *
 * Code generation for function 'driver'
 *
 */

/* Include files */
#include "driver.h"
#include "BFGSUpdate.h"
#include "computeConstraints_.h"
#include "computeDeltaLag.h"
#include "computeFiniteDifferences.h"
#include "computeForwardDifferences.h"
#include "computeLinearResiduals.h"
#include "evaluateObstacles_mex_internal_types.h"
#include "evaluateObstacles_mex_types.h"
#include "followerMPCandUpdate.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "linesearch.h"
#include "revertSolution.h"
#include "rt_nonfinite.h"
#include "saveJacobian.h"
#include "saveState.h"
#include "step.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include "mwmathutil.h"
#include <immintrin.h>
#include <string.h>

/* Variable Definitions */
static const int8_T iv[1600] = {
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

/* Function Definitions */
void c_driver(evaluateObstacles_mexStackData *SD, const real_T lb_data[],
              const int32_T lb_size[2], const real_T ub_data[],
              const int32_T ub_size[2], j_struct_T *TrialState,
              l_struct_T *MeritFunction,
              const r_coder_internal_stickyStruct *FcnEvaluator,
              p_struct_T *FiniteDifferences, e_struct_T *memspace,
              k_struct_T *WorkingSet, f_struct_T *QRManager,
              n_struct_T *CholManager, d_struct_T *QPObjective,
              int32_T fscales_cineq_constraint_size, real_T Hessian[1600])
{
  static const char_T qpoptions_SolverName[7] = {'f', 'm', 'i', 'n',
                                                 'c', 'o', 'n'};
  o_struct_T expl_temp;
  struct_T Flags;
  int32_T b_i;
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
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mConstr =
      ((WorkingSet->sizes[0] + WorkingSet->sizes[2]) + WorkingSet->sizes[3]) +
      WorkingSet->sizes[4];
  mLinIneq = WorkingSet->sizes[2] - TrialState->mNonlinIneq;
  y = ((WorkingSet->sizes[2] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
      (WorkingSet->sizes[0] << 1);
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet->nVar, y);
  TrialState->steplength = 1.0;
  Flags.gradOK =
      test_exit(MeritFunction, fscales_cineq_constraint_size, WorkingSet,
                TrialState, lb_data, ub_data, &Flags.fevalOK, &Flags.done,
                &Flags.stepAccepted, &Flags.failedLineSearch, &Flags.stepType);
  saveJacobian(TrialState, nVar, mIneq, WorkingSet->Aineq,
               TrialState->iNonIneq0, WorkingSet->ldA);
  saveState(TrialState);
  if (!Flags.done) {
    TrialState->sqpIterations = 1;
  }
  while (!Flags.done) {
    __m256d r;
    __m256d r1;
    real_T d;
    int32_T vectorUB;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      boolean_T socTaken;
      if (Flags.stepType != 3) {
        b_updateWorkingSetForNewQP(TrialState->xstarsqp, WorkingSet, mIneq,
                                   TrialState->mNonlinIneq,
                                   TrialState->cIneq.data, mLB, lb_data,
                                   lb_size, mUB, ub_data, ub_size, mFixed);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }
      step(SD, &Flags, Hessian, lb_data, lb_size, ub_data, ub_size, TrialState,
           MeritFunction, memspace, WorkingSet, QRManager, CholManager,
           QPObjective, &expl_temp);
      if (Flags.stepAccepted) {
        real_T fval;
        i = (uint16_T)nVar;
        y = ((uint16_T)nVar >> 2) << 2;
        vectorUB = y - 4;
        for (b_i = 0; b_i <= vectorUB; b_i += 4) {
          r = _mm256_loadu_pd(&TrialState->xstarsqp[b_i]);
          r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
          _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
        }
        for (b_i = y; b_i < i; b_i++) {
          TrialState->xstarsqp[b_i] += TrialState->delta_x.data[b_i];
        }
        fval = leaderMPCandUpdate_anonFcn1(
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.x0,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.sys.n,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.sys.Ts,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.robotParams.W,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.robotParams.W_hat,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.robotParams.R_hat,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.N,
            TrialState->xstarsqp);
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
          y = b_computeConstraints_(
              FcnEvaluator->next.next.next.next.next.value,
              FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                  .x0,
              &FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                   .obstacles,
              FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                  .N,
              FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                  .sys,
              TrialState->xstarsqp, TrialState->cIneq.data,
              TrialState->iNonIneq0);
        }
        TrialState->sqpFval = fval;
        Flags.fevalOK = (y == 1);
        TrialState->FunctionEvaluations++;
        computeLinearResiduals(TrialState->xstarsqp, nVar,
                               TrialState->cIneq.data, mLinIneq,
                               WorkingSet->Aineq, WorkingSet->ldA);
        if (Flags.fevalOK) {
          real_T constrViolationIneq;
          constrViolationIneq = 0.0;
          i = (uint16_T)mIneq;
          for (b_i = 0; b_i < i; b_i++) {
            d = TrialState->cIneq.data[b_i];
            if (d > 0.0) {
              constrViolationIneq += d;
            }
          }
          MeritFunction->phiFullStep =
              fval + MeritFunction->penaltyParam * constrViolationIneq;
        } else {
          MeritFunction->phiFullStep = rtInf;
        }
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        d = b_linesearch(
            &Flags.fevalOK, WorkingSet->nVar, WorkingSet->ldA,
            WorkingSet->Aineq, TrialState, MeritFunction->penaltyParam,
            MeritFunction->phi, MeritFunction->phiPrimePlus,
            MeritFunction->phiFullStep,
            FcnEvaluator->next.next.next.next.next.value,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace.x0,
            &FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                 .obstacles,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace.N,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                .sys,
            &FcnEvaluator->next.next.next.next.next.next.next.next.value
                 .workspace,
            socTaken, &y);
        TrialState->steplength = d;
        if (y > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      i = (uint16_T)nVar;
      y = ((uint16_T)nVar >> 2) << 2;
      vectorUB = y - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&TrialState->xstarsqp_old[b_i]);
        r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
        _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
      }
      for (b_i = y; b_i < i; b_i++) {
        TrialState->xstarsqp[b_i] =
            TrialState->xstarsqp_old[b_i] + TrialState->delta_x.data[b_i];
      }
      i = (uint16_T)mConstr;
      y = ((uint16_T)mConstr >> 2) << 2;
      vectorUB = y - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&TrialState->lambda->data[b_i]);
        r1 = _mm256_loadu_pd(&TrialState->lambdasqp->data[b_i]);
        _mm256_storeu_pd(
            &TrialState->lambdasqp->data[b_i],
            _mm256_add_pd(r1,
                          _mm256_mul_pd(_mm256_set1_pd(TrialState->steplength),
                                        _mm256_sub_pd(r, r1))));
      }
      for (b_i = y; b_i < i; b_i++) {
        d = TrialState->lambdasqp->data[b_i];
        d += TrialState->steplength * (TrialState->lambda->data[b_i] - d);
        TrialState->lambdasqp->data[b_i] = d;
      }
      saveState(TrialState);
      Flags.gradOK = computeForwardDifferences(
          FiniteDifferences, TrialState->sqpFval, TrialState->cIneq.data,
          TrialState->iNonIneq0, TrialState->xstarsqp, TrialState->grad.data,
          WorkingSet->Aineq, TrialState->iNonIneq0, WorkingSet->ldA, lb_data,
          ub_data);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      revertSolution(TrialState);
    }
    b_test_exit(&Flags, memspace, MeritFunction, fscales_cineq_constraint_size,
                WorkingSet, TrialState, QRManager, lb_data, lb_size, ub_data,
                ub_size);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      computeDeltaLag(nVar, WorkingSet->ldA, TrialState->mNonlinIneq,
                      TrialState->delta_gradLag.data, TrialState->grad.data,
                      WorkingSet->Aineq, TrialState->iNonIneq0,
                      TrialState->grad_old.data, TrialState->JacCineqTrans_old,
                      TrialState->lambdasqp, mFixed + TrialState->iNonIneq0);
      saveJacobian(TrialState, nVar, mIneq, WorkingSet->Aineq,
                   TrialState->iNonIneq0, WorkingSet->ldA);
      BFGSUpdate(nVar, Hessian, TrialState->delta_x.data,
                 TrialState->delta_gradLag.data, memspace->workspace_float);
      TrialState->sqpIterations++;
    }
  }
}

void d_driver(evaluateObstacles_mexStackData *SD, const real_T lb_data[],
              const int32_T lb_size[2], const real_T ub_data[],
              const int32_T ub_size[2], j_struct_T *TrialState,
              l_struct_T *MeritFunction,
              const bb_coder_internal_stickyStruct *FcnEvaluator,
              q_struct_T *FiniteDifferences, e_struct_T *memspace,
              k_struct_T *WorkingSet, f_struct_T *QRManager,
              n_struct_T *CholManager, d_struct_T *QPObjective,
              int32_T fscales_cineq_constraint_size, real_T Hessian[1600])
{
  static const char_T qpoptions_SolverName[7] = {'f', 'm', 'i', 'n',
                                                 'c', 'o', 'n'};
  o_struct_T expl_temp;
  struct_T Flags;
  int32_T b_i;
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
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mConstr =
      ((WorkingSet->sizes[0] + WorkingSet->sizes[2]) + WorkingSet->sizes[3]) +
      WorkingSet->sizes[4];
  mLinIneq = WorkingSet->sizes[2] - TrialState->mNonlinIneq;
  y = ((WorkingSet->sizes[2] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
      (WorkingSet->sizes[0] << 1);
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet->nVar, y);
  TrialState->steplength = 1.0;
  Flags.gradOK =
      test_exit(MeritFunction, fscales_cineq_constraint_size, WorkingSet,
                TrialState, lb_data, ub_data, &Flags.fevalOK, &Flags.done,
                &Flags.stepAccepted, &Flags.failedLineSearch, &Flags.stepType);
  saveJacobian(TrialState, nVar, mIneq, WorkingSet->Aineq,
               TrialState->iNonIneq0, WorkingSet->ldA);
  saveState(TrialState);
  if (!Flags.done) {
    TrialState->sqpIterations = 1;
  }
  while (!Flags.done) {
    __m256d r;
    __m256d r1;
    real_T d;
    int32_T vectorUB;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      boolean_T socTaken;
      if (Flags.stepType != 3) {
        b_updateWorkingSetForNewQP(TrialState->xstarsqp, WorkingSet, mIneq,
                                   TrialState->mNonlinIneq,
                                   TrialState->cIneq.data, mLB, lb_data,
                                   lb_size, mUB, ub_data, ub_size, mFixed);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }
      step(SD, &Flags, Hessian, lb_data, lb_size, ub_data, ub_size, TrialState,
           MeritFunction, memspace, WorkingSet, QRManager, CholManager,
           QPObjective, &expl_temp);
      if (Flags.stepAccepted) {
        real_T fval;
        i = (uint16_T)nVar;
        y = ((uint16_T)nVar >> 2) << 2;
        vectorUB = y - 4;
        for (b_i = 0; b_i <= vectorUB; b_i += 4) {
          r = _mm256_loadu_pd(&TrialState->xstarsqp[b_i]);
          r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
          _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
        }
        for (b_i = y; b_i < i; b_i++) {
          TrialState->xstarsqp[b_i] += TrialState->delta_x.data[b_i];
        }
        fval = leaderMPCandUpdateHalt_anonFcn1(
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.x0,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.sys.n,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.sys.Ts,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.N,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.robotParams.Px,
            TrialState->xstarsqp);
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
          y = c_computeConstraints_(
              FcnEvaluator->next.next.next.next.next.value,
              FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                  .x0,
              &FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                   .obstacles,
              FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                  .N,
              FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                  .sys,
              TrialState->xstarsqp, TrialState->cIneq.data,
              TrialState->iNonIneq0);
        }
        TrialState->sqpFval = fval;
        Flags.fevalOK = (y == 1);
        TrialState->FunctionEvaluations++;
        computeLinearResiduals(TrialState->xstarsqp, nVar,
                               TrialState->cIneq.data, mLinIneq,
                               WorkingSet->Aineq, WorkingSet->ldA);
        if (Flags.fevalOK) {
          real_T constrViolationIneq;
          constrViolationIneq = 0.0;
          i = (uint16_T)mIneq;
          for (b_i = 0; b_i < i; b_i++) {
            d = TrialState->cIneq.data[b_i];
            if (d > 0.0) {
              constrViolationIneq += d;
            }
          }
          MeritFunction->phiFullStep =
              fval + MeritFunction->penaltyParam * constrViolationIneq;
        } else {
          MeritFunction->phiFullStep = rtInf;
        }
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        d = c_linesearch(
            &Flags.fevalOK, WorkingSet->nVar, WorkingSet->ldA,
            WorkingSet->Aineq, TrialState, MeritFunction->penaltyParam,
            MeritFunction->phi, MeritFunction->phiPrimePlus,
            MeritFunction->phiFullStep,
            FcnEvaluator->next.next.next.next.next.value,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace.x0,
            &FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                 .obstacles,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace.N,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                .sys,
            &FcnEvaluator->next.next.next.next.next.next.next.next.value
                 .workspace,
            socTaken, &y);
        TrialState->steplength = d;
        if (y > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      i = (uint16_T)nVar;
      y = ((uint16_T)nVar >> 2) << 2;
      vectorUB = y - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&TrialState->xstarsqp_old[b_i]);
        r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
        _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
      }
      for (b_i = y; b_i < i; b_i++) {
        TrialState->xstarsqp[b_i] =
            TrialState->xstarsqp_old[b_i] + TrialState->delta_x.data[b_i];
      }
      i = (uint16_T)mConstr;
      y = ((uint16_T)mConstr >> 2) << 2;
      vectorUB = y - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&TrialState->lambda->data[b_i]);
        r1 = _mm256_loadu_pd(&TrialState->lambdasqp->data[b_i]);
        _mm256_storeu_pd(
            &TrialState->lambdasqp->data[b_i],
            _mm256_add_pd(r1,
                          _mm256_mul_pd(_mm256_set1_pd(TrialState->steplength),
                                        _mm256_sub_pd(r, r1))));
      }
      for (b_i = y; b_i < i; b_i++) {
        d = TrialState->lambdasqp->data[b_i];
        d += TrialState->steplength * (TrialState->lambda->data[b_i] - d);
        TrialState->lambdasqp->data[b_i] = d;
      }
      saveState(TrialState);
      Flags.gradOK = b_computeForwardDifferences(
          FiniteDifferences, TrialState->sqpFval, TrialState->cIneq.data,
          TrialState->iNonIneq0, TrialState->xstarsqp, TrialState->grad.data,
          WorkingSet->Aineq, TrialState->iNonIneq0, WorkingSet->ldA, lb_data,
          ub_data);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      revertSolution(TrialState);
    }
    b_test_exit(&Flags, memspace, MeritFunction, fscales_cineq_constraint_size,
                WorkingSet, TrialState, QRManager, lb_data, lb_size, ub_data,
                ub_size);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      computeDeltaLag(nVar, WorkingSet->ldA, TrialState->mNonlinIneq,
                      TrialState->delta_gradLag.data, TrialState->grad.data,
                      WorkingSet->Aineq, TrialState->iNonIneq0,
                      TrialState->grad_old.data, TrialState->JacCineqTrans_old,
                      TrialState->lambdasqp, mFixed + TrialState->iNonIneq0);
      saveJacobian(TrialState, nVar, mIneq, WorkingSet->Aineq,
                   TrialState->iNonIneq0, WorkingSet->ldA);
      BFGSUpdate(nVar, Hessian, TrialState->delta_x.data,
                 TrialState->delta_gradLag.data, memspace->workspace_float);
      TrialState->sqpIterations++;
    }
  }
}

void driver(evaluateObstacles_mexStackData *SD, const real_T lb_data[],
            const int32_T lb_size[2], const real_T ub_data[],
            const int32_T ub_size[2], j_struct_T *TrialState,
            l_struct_T *MeritFunction,
            const i_coder_internal_stickyStruct *FcnEvaluator,
            m_struct_T *FiniteDifferences, e_struct_T *memspace,
            k_struct_T *WorkingSet, f_struct_T *QRManager,
            n_struct_T *CholManager, d_struct_T *QPObjective,
            int32_T fscales_cineq_constraint_size, real_T Hessian[1600])
{
  static const char_T qpoptions_SolverName[7] = {'f', 'm', 'i', 'n',
                                                 'c', 'o', 'n'};
  o_struct_T expl_temp;
  struct_T Flags;
  int32_T b_i;
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
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mConstr =
      ((WorkingSet->sizes[0] + WorkingSet->sizes[2]) + WorkingSet->sizes[3]) +
      WorkingSet->sizes[4];
  mLinIneq = WorkingSet->sizes[2] - TrialState->mNonlinIneq;
  y = ((WorkingSet->sizes[2] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
      (WorkingSet->sizes[0] << 1);
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet->nVar, y);
  TrialState->steplength = 1.0;
  Flags.gradOK =
      test_exit(MeritFunction, fscales_cineq_constraint_size, WorkingSet,
                TrialState, lb_data, ub_data, &Flags.fevalOK, &Flags.done,
                &Flags.stepAccepted, &Flags.failedLineSearch, &Flags.stepType);
  saveJacobian(TrialState, nVar, mIneq, WorkingSet->Aineq,
               TrialState->iNonIneq0, WorkingSet->ldA);
  saveState(TrialState);
  if (!Flags.done) {
    TrialState->sqpIterations = 1;
  }
  while (!Flags.done) {
    __m256d r;
    __m256d r1;
    real_T d;
    int32_T vectorUB;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      boolean_T socTaken;
      if (Flags.stepType != 3) {
        b_updateWorkingSetForNewQP(TrialState->xstarsqp, WorkingSet, mIneq,
                                   TrialState->mNonlinIneq,
                                   TrialState->cIneq.data, mLB, lb_data,
                                   lb_size, mUB, ub_data, ub_size, mFixed);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }
      step(SD, &Flags, Hessian, lb_data, lb_size, ub_data, ub_size, TrialState,
           MeritFunction, memspace, WorkingSet, QRManager, CholManager,
           QPObjective, &expl_temp);
      if (Flags.stepAccepted) {
        real_T fval;
        i = (uint16_T)nVar;
        y = ((uint16_T)nVar >> 2) << 2;
        vectorUB = y - 4;
        for (b_i = 0; b_i <= vectorUB; b_i += 4) {
          r = _mm256_loadu_pd(&TrialState->xstarsqp[b_i]);
          r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
          _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
        }
        for (b_i = y; b_i < i; b_i++) {
          TrialState->xstarsqp[b_i] += TrialState->delta_x.data[b_i];
        }
        fval = followerMPCandUpdate_anonFcn1(
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.x0,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.sys.n,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.sys.Ts,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.N,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.X_L_stacked,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.robotParams.Px,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.robotParams.d_FL_sq,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.robotParams.C,
            FcnEvaluator->next.next.next.next.next.next.next.next.value
                .workspace.robotParams.beta_N,
            TrialState->xstarsqp);
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
          y = computeConstraints_(FcnEvaluator->next.next.next.next.next.value,
                                  FcnEvaluator->next.next.next.next.next.next
                                      .next.value.workspace.x0,
                                  &FcnEvaluator->next.next.next.next.next.next
                                       .next.value.workspace.obstacles,
                                  FcnEvaluator->next.next.next.next.next.next
                                      .next.value.workspace.N,
                                  FcnEvaluator->next.next.next.next.next.next
                                      .next.value.workspace.sys,
                                  TrialState->xstarsqp, TrialState->cIneq.data,
                                  TrialState->iNonIneq0);
        }
        TrialState->sqpFval = fval;
        Flags.fevalOK = (y == 1);
        TrialState->FunctionEvaluations++;
        computeLinearResiduals(TrialState->xstarsqp, nVar,
                               TrialState->cIneq.data, mLinIneq,
                               WorkingSet->Aineq, WorkingSet->ldA);
        if (Flags.fevalOK) {
          real_T constrViolationIneq;
          constrViolationIneq = 0.0;
          i = (uint16_T)mIneq;
          for (b_i = 0; b_i < i; b_i++) {
            d = TrialState->cIneq.data[b_i];
            if (d > 0.0) {
              constrViolationIneq += d;
            }
          }
          MeritFunction->phiFullStep =
              fval + MeritFunction->penaltyParam * constrViolationIneq;
        } else {
          MeritFunction->phiFullStep = rtInf;
        }
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        d = linesearch(
            &Flags.fevalOK, WorkingSet->nVar, WorkingSet->ldA,
            WorkingSet->Aineq, TrialState, MeritFunction->penaltyParam,
            MeritFunction->phi, MeritFunction->phiPrimePlus,
            MeritFunction->phiFullStep,
            FcnEvaluator->next.next.next.next.next.value,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace.x0,
            &FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                 .obstacles,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace.N,
            FcnEvaluator->next.next.next.next.next.next.next.value.workspace
                .sys,
            &FcnEvaluator->next.next.next.next.next.next.next.next.value
                 .workspace,
            socTaken, &y);
        TrialState->steplength = d;
        if (y > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      i = (uint16_T)nVar;
      y = ((uint16_T)nVar >> 2) << 2;
      vectorUB = y - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&TrialState->xstarsqp_old[b_i]);
        r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
        _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
      }
      for (b_i = y; b_i < i; b_i++) {
        TrialState->xstarsqp[b_i] =
            TrialState->xstarsqp_old[b_i] + TrialState->delta_x.data[b_i];
      }
      i = (uint16_T)mConstr;
      y = ((uint16_T)mConstr >> 2) << 2;
      vectorUB = y - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&TrialState->lambda->data[b_i]);
        r1 = _mm256_loadu_pd(&TrialState->lambdasqp->data[b_i]);
        _mm256_storeu_pd(
            &TrialState->lambdasqp->data[b_i],
            _mm256_add_pd(r1,
                          _mm256_mul_pd(_mm256_set1_pd(TrialState->steplength),
                                        _mm256_sub_pd(r, r1))));
      }
      for (b_i = y; b_i < i; b_i++) {
        d = TrialState->lambdasqp->data[b_i];
        d += TrialState->steplength * (TrialState->lambda->data[b_i] - d);
        TrialState->lambdasqp->data[b_i] = d;
      }
      saveState(TrialState);
      Flags.gradOK = computeFiniteDifferences(
          FiniteDifferences, TrialState->sqpFval, TrialState->cIneq.data,
          TrialState->iNonIneq0, TrialState->xstarsqp, TrialState->grad.data,
          WorkingSet->Aineq, TrialState->iNonIneq0, WorkingSet->ldA, lb_data,
          ub_data);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      revertSolution(TrialState);
    }
    b_test_exit(&Flags, memspace, MeritFunction, fscales_cineq_constraint_size,
                WorkingSet, TrialState, QRManager, lb_data, lb_size, ub_data,
                ub_size);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      computeDeltaLag(nVar, WorkingSet->ldA, TrialState->mNonlinIneq,
                      TrialState->delta_gradLag.data, TrialState->grad.data,
                      WorkingSet->Aineq, TrialState->iNonIneq0,
                      TrialState->grad_old.data, TrialState->JacCineqTrans_old,
                      TrialState->lambdasqp, mFixed + TrialState->iNonIneq0);
      saveJacobian(TrialState, nVar, mIneq, WorkingSet->Aineq,
                   TrialState->iNonIneq0, WorkingSet->ldA);
      BFGSUpdate(nVar, Hessian, TrialState->delta_x.data,
                 TrialState->delta_gradLag.data, memspace->workspace_float);
      TrialState->sqpIterations++;
    }
  }
}

/* End of code generation (driver.c) */
