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
#include "followerMPCandUpdate.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "linesearch.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "revertSolution.h"
#include "rt_nonfinite.h"
#include "saveJacobian.h"
#include "saveState.h"
#include "step.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include "mwmathutil.h"
#include "omp.h"
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
void c_driver(emlrtCTX aTLS, mexFunctionsStackData *SD, const real_T lb[40],
              const real_T ub[40], h_struct_T *TrialState,
              j_struct_T *MeritFunction,
              const s_coder_internal_stickyStruct *FcnEvaluator,
              o_struct_T *FiniteDifferences, f_struct_T *memspace,
              i_struct_T *WorkingSet, g_struct_T *QRManager,
              m_struct_T *CholManager, e_struct_T *QPObjective,
              int32_T fscales_cineq_constraint_size, real_T Hessian[1600])
{
  static const char_T qpoptions_SolverName[7] = {'f', 'm', 'i', 'n',
                                                 'c', 'o', 'n'};
  jmp_buf *volatile emlrtJBStack;
  n_struct_T expl_temp;
  struct_T Flags;
  int32_T b_i;
  int32_T c_driver_numThreads;
  int32_T i;
  int32_T i1;
  int32_T mConstr;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLinIneq;
  int32_T mUB;
  int32_T nVar;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  emlrtEnterParallelRegion(aTLS, omp_in_parallel());
  emlrtPushJmpBuf(aTLS, &emlrtJBStack);
  c_driver_numThreads = emlrtAllocRegionTLSs(
      aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(c_driver_numThreads)

  for (i = 0; i < 1600; i++) {
    Hessian[i] = iv[i];
  }
  emlrtPopJmpBuf(aTLS, &emlrtJBStack);
  emlrtExitParallelRegion(aTLS, omp_in_parallel());
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
                TrialState, lb, ub, &Flags.fevalOK, &Flags.done,
                &Flags.stepAccepted, &Flags.failedLineSearch, &Flags.stepType);
  saveJacobian(TrialState, nVar, mIneq, WorkingSet->Aineq,
               TrialState->iNonIneq0, WorkingSet->ldA);
  saveState(aTLS, TrialState);
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
        b_updateWorkingSetForNewQP(aTLS, TrialState->xstarsqp, WorkingSet,
                                   mIneq, TrialState->mNonlinIneq,
                                   TrialState->cIneq.data, mLB, lb, mUB, ub,
                                   mFixed);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i1 = 0; i1 < 7; i1++) {
        expl_temp.SolverName[i1] = qpoptions_SolverName[i1];
      }
      step(aTLS, SD, &Flags, Hessian, lb, ub, TrialState, MeritFunction,
           memspace, WorkingSet, QRManager, CholManager, QPObjective,
           &expl_temp);
      if (Flags.stepAccepted) {
        real_T fval;
        i1 = (uint16_T)nVar;
        y = ((uint16_T)nVar >> 2) << 2;
        vectorUB = y - 4;
        for (b_i = 0; b_i <= vectorUB; b_i += 4) {
          r = _mm256_loadu_pd(&TrialState->xstarsqp[b_i]);
          r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
          _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
        }
        for (b_i = y; b_i < i1; b_i++) {
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
              aTLS, FcnEvaluator->next.next.next.next.next.value,
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
          i1 = (uint16_T)mIneq;
          for (b_i = 0; b_i < i1; b_i++) {
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
            aTLS, &Flags.fevalOK, WorkingSet->nVar, WorkingSet->ldA,
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
      i1 = (uint16_T)nVar;
      y = ((uint16_T)nVar >> 2) << 2;
      vectorUB = y - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&TrialState->xstarsqp_old[b_i]);
        r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
        _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
      }
      for (b_i = y; b_i < i1; b_i++) {
        TrialState->xstarsqp[b_i] =
            TrialState->xstarsqp_old[b_i] + TrialState->delta_x.data[b_i];
      }
      i1 = (uint16_T)mConstr;
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
      for (b_i = y; b_i < i1; b_i++) {
        d = TrialState->lambdasqp->data[b_i];
        d += TrialState->steplength * (TrialState->lambda->data[b_i] - d);
        TrialState->lambdasqp->data[b_i] = d;
      }
      saveState(aTLS, TrialState);
      Flags.gradOK = computeForwardDifferences(
          FiniteDifferences, TrialState->sqpFval, TrialState->cIneq.data,
          TrialState->iNonIneq0, TrialState->xstarsqp, TrialState->grad.data,
          WorkingSet->Aineq, TrialState->iNonIneq0, WorkingSet->ldA, lb, ub);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      revertSolution(aTLS, TrialState);
    }
    b_test_exit(&Flags, memspace, MeritFunction, fscales_cineq_constraint_size,
                WorkingSet, TrialState, QRManager, lb, ub);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      computeDeltaLag(aTLS, nVar, WorkingSet->ldA, TrialState->mNonlinIneq,
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

void d_driver(emlrtCTX aTLS, mexFunctionsStackData *SD, const real_T lb[40],
              const real_T ub[40], h_struct_T *TrialState,
              j_struct_T *MeritFunction,
              const bb_coder_internal_stickyStruct *FcnEvaluator,
              p_struct_T *FiniteDifferences, f_struct_T *memspace,
              i_struct_T *WorkingSet, g_struct_T *QRManager,
              m_struct_T *CholManager, e_struct_T *QPObjective,
              int32_T fscales_cineq_constraint_size, real_T Hessian[1600])
{
  static const char_T qpoptions_SolverName[7] = {'f', 'm', 'i', 'n',
                                                 'c', 'o', 'n'};
  jmp_buf *volatile emlrtJBStack;
  n_struct_T expl_temp;
  struct_T Flags;
  int32_T b_i;
  int32_T d_driver_numThreads;
  int32_T i;
  int32_T i1;
  int32_T mConstr;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLinIneq;
  int32_T mUB;
  int32_T nVar;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  emlrtEnterParallelRegion(aTLS, omp_in_parallel());
  emlrtPushJmpBuf(aTLS, &emlrtJBStack);
  d_driver_numThreads = emlrtAllocRegionTLSs(
      aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(d_driver_numThreads)

  for (i = 0; i < 1600; i++) {
    Hessian[i] = iv[i];
  }
  emlrtPopJmpBuf(aTLS, &emlrtJBStack);
  emlrtExitParallelRegion(aTLS, omp_in_parallel());
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
                TrialState, lb, ub, &Flags.fevalOK, &Flags.done,
                &Flags.stepAccepted, &Flags.failedLineSearch, &Flags.stepType);
  saveJacobian(TrialState, nVar, mIneq, WorkingSet->Aineq,
               TrialState->iNonIneq0, WorkingSet->ldA);
  saveState(aTLS, TrialState);
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
        b_updateWorkingSetForNewQP(aTLS, TrialState->xstarsqp, WorkingSet,
                                   mIneq, TrialState->mNonlinIneq,
                                   TrialState->cIneq.data, mLB, lb, mUB, ub,
                                   mFixed);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i1 = 0; i1 < 7; i1++) {
        expl_temp.SolverName[i1] = qpoptions_SolverName[i1];
      }
      step(aTLS, SD, &Flags, Hessian, lb, ub, TrialState, MeritFunction,
           memspace, WorkingSet, QRManager, CholManager, QPObjective,
           &expl_temp);
      if (Flags.stepAccepted) {
        real_T fval;
        i1 = (uint16_T)nVar;
        y = ((uint16_T)nVar >> 2) << 2;
        vectorUB = y - 4;
        for (b_i = 0; b_i <= vectorUB; b_i += 4) {
          r = _mm256_loadu_pd(&TrialState->xstarsqp[b_i]);
          r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
          _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
        }
        for (b_i = y; b_i < i1; b_i++) {
          TrialState->xstarsqp[b_i] += TrialState->delta_x.data[b_i];
        }
        fval = leaderMPCandUpdateHalt_anonFcn1(
            aTLS,
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
              aTLS, FcnEvaluator->next.next.next.next.next.value,
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
          i1 = (uint16_T)mIneq;
          for (b_i = 0; b_i < i1; b_i++) {
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
            aTLS, &Flags.fevalOK, WorkingSet->nVar, WorkingSet->ldA,
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
      i1 = (uint16_T)nVar;
      y = ((uint16_T)nVar >> 2) << 2;
      vectorUB = y - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&TrialState->xstarsqp_old[b_i]);
        r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
        _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
      }
      for (b_i = y; b_i < i1; b_i++) {
        TrialState->xstarsqp[b_i] =
            TrialState->xstarsqp_old[b_i] + TrialState->delta_x.data[b_i];
      }
      i1 = (uint16_T)mConstr;
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
      for (b_i = y; b_i < i1; b_i++) {
        d = TrialState->lambdasqp->data[b_i];
        d += TrialState->steplength * (TrialState->lambda->data[b_i] - d);
        TrialState->lambdasqp->data[b_i] = d;
      }
      saveState(aTLS, TrialState);
      Flags.gradOK = b_computeForwardDifferences(
          FiniteDifferences, TrialState->sqpFval, TrialState->cIneq.data,
          TrialState->iNonIneq0, TrialState->xstarsqp, TrialState->grad.data,
          WorkingSet->Aineq, TrialState->iNonIneq0, WorkingSet->ldA, lb, ub);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      revertSolution(aTLS, TrialState);
    }
    b_test_exit(&Flags, memspace, MeritFunction, fscales_cineq_constraint_size,
                WorkingSet, TrialState, QRManager, lb, ub);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      computeDeltaLag(aTLS, nVar, WorkingSet->ldA, TrialState->mNonlinIneq,
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

void driver(emlrtCTX aTLS, mexFunctionsStackData *SD, const real_T lb[40],
            const real_T ub[40], h_struct_T *TrialState,
            j_struct_T *MeritFunction,
            const k_coder_internal_stickyStruct *FcnEvaluator,
            l_struct_T *FiniteDifferences, f_struct_T *memspace,
            i_struct_T *WorkingSet, g_struct_T *QRManager,
            m_struct_T *CholManager, e_struct_T *QPObjective,
            int32_T fscales_cineq_constraint_size, real_T Hessian[1600])
{
  static const char_T qpoptions_SolverName[7] = {'f', 'm', 'i', 'n',
                                                 'c', 'o', 'n'};
  jmp_buf *volatile emlrtJBStack;
  n_struct_T expl_temp;
  struct_T Flags;
  int32_T b_i;
  int32_T driver_numThreads;
  int32_T i;
  int32_T i1;
  int32_T mConstr;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLinIneq;
  int32_T mUB;
  int32_T nVar;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  emlrtEnterParallelRegion(aTLS, omp_in_parallel());
  emlrtPushJmpBuf(aTLS, &emlrtJBStack);
  driver_numThreads = emlrtAllocRegionTLSs(
      aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(driver_numThreads)

  for (i = 0; i < 1600; i++) {
    Hessian[i] = iv[i];
  }
  emlrtPopJmpBuf(aTLS, &emlrtJBStack);
  emlrtExitParallelRegion(aTLS, omp_in_parallel());
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
                TrialState, lb, ub, &Flags.fevalOK, &Flags.done,
                &Flags.stepAccepted, &Flags.failedLineSearch, &Flags.stepType);
  saveJacobian(TrialState, nVar, mIneq, WorkingSet->Aineq,
               TrialState->iNonIneq0, WorkingSet->ldA);
  saveState(aTLS, TrialState);
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
        b_updateWorkingSetForNewQP(aTLS, TrialState->xstarsqp, WorkingSet,
                                   mIneq, TrialState->mNonlinIneq,
                                   TrialState->cIneq.data, mLB, lb, mUB, ub,
                                   mFixed);
      }
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i1 = 0; i1 < 7; i1++) {
        expl_temp.SolverName[i1] = qpoptions_SolverName[i1];
      }
      step(aTLS, SD, &Flags, Hessian, lb, ub, TrialState, MeritFunction,
           memspace, WorkingSet, QRManager, CholManager, QPObjective,
           &expl_temp);
      if (Flags.stepAccepted) {
        real_T fval;
        i1 = (uint16_T)nVar;
        y = ((uint16_T)nVar >> 2) << 2;
        vectorUB = y - 4;
        for (b_i = 0; b_i <= vectorUB; b_i += 4) {
          r = _mm256_loadu_pd(&TrialState->xstarsqp[b_i]);
          r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
          _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
        }
        for (b_i = y; b_i < i1; b_i++) {
          TrialState->xstarsqp[b_i] += TrialState->delta_x.data[b_i];
        }
        fval = followerMPCandUpdate_anonFcn1(
            aTLS,
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
          y = computeConstraints_(aTLS,
                                  FcnEvaluator->next.next.next.next.next.value,
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
          i1 = (uint16_T)mIneq;
          for (b_i = 0; b_i < i1; b_i++) {
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
            aTLS, &Flags.fevalOK, WorkingSet->nVar, WorkingSet->ldA,
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
      i1 = (uint16_T)nVar;
      y = ((uint16_T)nVar >> 2) << 2;
      vectorUB = y - 4;
      for (b_i = 0; b_i <= vectorUB; b_i += 4) {
        r = _mm256_loadu_pd(&TrialState->xstarsqp_old[b_i]);
        r1 = _mm256_loadu_pd(&TrialState->delta_x.data[b_i]);
        _mm256_storeu_pd(&TrialState->xstarsqp[b_i], _mm256_add_pd(r, r1));
      }
      for (b_i = y; b_i < i1; b_i++) {
        TrialState->xstarsqp[b_i] =
            TrialState->xstarsqp_old[b_i] + TrialState->delta_x.data[b_i];
      }
      i1 = (uint16_T)mConstr;
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
      for (b_i = y; b_i < i1; b_i++) {
        d = TrialState->lambdasqp->data[b_i];
        d += TrialState->steplength * (TrialState->lambda->data[b_i] - d);
        TrialState->lambdasqp->data[b_i] = d;
      }
      saveState(aTLS, TrialState);
      Flags.gradOK = computeFiniteDifferences(
          FiniteDifferences, TrialState->sqpFval, TrialState->cIneq.data,
          TrialState->iNonIneq0, TrialState->xstarsqp, TrialState->grad.data,
          WorkingSet->Aineq, TrialState->iNonIneq0, WorkingSet->ldA, lb, ub);
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      revertSolution(aTLS, TrialState);
    }
    b_test_exit(&Flags, memspace, MeritFunction, fscales_cineq_constraint_size,
                WorkingSet, TrialState, QRManager, lb, ub);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      computeDeltaLag(aTLS, nVar, WorkingSet->ldA, TrialState->mNonlinIneq,
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
