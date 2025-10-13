/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_exit.c
 *
 * Code generation for function 'test_exit'
 *
 */

/* Include files */
#include "test_exit.h"
#include "computeComplError.h"
#include "computeDualFeasError.h"
#include "computeGradLag.h"
#include "computePrimalFeasError.h"
#include "computeQ_.h"
#include "factorQRE.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSetForNewQP.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void b_test_exit(struct_T *Flags, f_struct_T *memspace,
                 j_struct_T *MeritFunction,
                 int32_T fscales_cineq_constraint_size, i_struct_T *WorkingSet,
                 h_struct_T *TrialState, g_struct_T *QRManager,
                 const real_T lb[40], const real_T ub[40])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emxArray_real_T *gradLag;
  const real_T *gradLag_data;
  real_T nlpComplErrorTmp;
  real_T optimRelativeFactor;
  real_T tol;
  int32_T fullRank_R;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLambda;
  int32_T mUB;
  int32_T nVar_tmp;
  int32_T rankR;
  char_T TRANSA;
  char_T TRANSA1;
  char_T UPLO1;
  boolean_T isFeasible;
  nVar_tmp = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mLambda =
      ((WorkingSet->sizes[0] + WorkingSet->sizes[2]) + WorkingSet->sizes[3]) +
      WorkingSet->sizes[4];
  if (mLambda >= 1) {
    n_t = (ptrdiff_t)mLambda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &TrialState->lambdasqp->data[0], &incx_t,
          &TrialState->lambdaStopTest->data[0], &incy_t);
  }
  computeGradLag(emlrtRootTLSGlobal, TrialState->gradLag.data, WorkingSet->ldA,
                 WorkingSet->nVar, TrialState->grad.data, WorkingSet->sizes[2],
                 WorkingSet->Aineq, WorkingSet->indexFixed.data,
                 WorkingSet->sizes[0], WorkingSet->indexLB.data,
                 WorkingSet->sizes[3], WorkingSet->indexUB.data,
                 WorkingSet->sizes[4], TrialState->lambdaStopTest);
  if (WorkingSet->nVar < 1) {
    fullRank_R = 0;
  } else {
    n_t = (ptrdiff_t)WorkingSet->nVar;
    incx_t = (ptrdiff_t)1;
    n_t = idamax(&n_t, &TrialState->grad.data[0], &incx_t);
    fullRank_R = (int32_T)n_t;
  }
  optimRelativeFactor = muDoubleScalarMax(
      1.0, muDoubleScalarAbs(TrialState->grad.data[fullRank_R - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(
      emlrtRootTLSGlobal, TrialState->xstarsqp,
      WorkingSet->sizes[2] - TrialState->mNonlinIneq, TrialState->mNonlinIneq,
      TrialState->cIneq.data, WorkingSet->indexLB.data, WorkingSet->sizes[3],
      lb, WorkingSet->indexUB.data, WorkingSet->sizes[4], ub);
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor =
        muDoubleScalarMax(1.0, MeritFunction->nlpPrimalFeasError);
  }
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                1.0E-6 * MeritFunction->feasRelativeFactor);
  Flags->gradOK =
      computeDualFeasError(WorkingSet->nVar, TrialState->gradLag.data,
                           &MeritFunction->nlpDualFeasError);
  if (!Flags->gradOK) {
    Flags->done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    boolean_T dxTooSmall;
    boolean_T exitg1;
    MeritFunction->nlpComplError = computeComplError(
        emlrtRootTLSGlobal, fscales_cineq_constraint_size, TrialState->xstarsqp,
        WorkingSet->sizes[2], TrialState->cIneq.data, WorkingSet->indexLB.data,
        WorkingSet->sizes[3], lb, WorkingSet->indexUB.data,
        WorkingSet->sizes[4], ub, TrialState->lambdaStopTest,
        WorkingSet->sizes[0] + 1);
    MeritFunction->firstOrderOpt = muDoubleScalarMax(
        MeritFunction->nlpDualFeasError, MeritFunction->nlpComplError);
    if (TrialState->sqpIterations > 1) {
      b_computeGradLag(emlrtRootTLSGlobal, memspace->workspace_float,
                       WorkingSet->ldA, WorkingSet->nVar, TrialState->grad.data,
                       WorkingSet->sizes[2], WorkingSet->Aineq,
                       WorkingSet->indexFixed.data, WorkingSet->sizes[0],
                       WorkingSet->indexLB.data, WorkingSet->sizes[3],
                       WorkingSet->indexUB.data, WorkingSet->sizes[4],
                       TrialState->lambdaStopTestPrev);
      gradLag = memspace->workspace_float;
      gradLag_data = gradLag->data;
      tol = 0.0;
      rankR = 0;
      exitg1 = false;
      while ((!exitg1) && (rankR <= (uint16_T)nVar_tmp - 1)) {
        dxTooSmall = ((!muDoubleScalarIsInf(gradLag_data[rankR])) &&
                      (!muDoubleScalarIsNaN(gradLag_data[rankR])));
        if (!dxTooSmall) {
          exitg1 = true;
        } else {
          tol = muDoubleScalarMax(tol, muDoubleScalarAbs(gradLag_data[rankR]));
          rankR++;
        }
      }
      nlpComplErrorTmp = computeComplError(
          emlrtRootTLSGlobal, fscales_cineq_constraint_size,
          TrialState->xstarsqp, WorkingSet->sizes[2], TrialState->cIneq.data,
          WorkingSet->indexLB.data, WorkingSet->sizes[3], lb,
          WorkingSet->indexUB.data, WorkingSet->sizes[4], ub,
          TrialState->lambdaStopTestPrev, WorkingSet->sizes[0] + 1);
      if ((tol < MeritFunction->nlpDualFeasError) &&
          (nlpComplErrorTmp < MeritFunction->nlpComplError)) {
        MeritFunction->nlpDualFeasError = tol;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        MeritFunction->firstOrderOpt = muDoubleScalarMax(tol, nlpComplErrorTmp);
        if (mLambda >= 1) {
          n_t = (ptrdiff_t)mLambda;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &TrialState->lambdaStopTestPrev->data[0], &incx_t,
                &TrialState->lambdaStopTest->data[0], &incy_t);
        }
      } else if (mLambda >= 1) {
        n_t = (ptrdiff_t)mLambda;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &TrialState->lambdaStopTest->data[0], &incx_t,
              &TrialState->lambdaStopTestPrev->data[0], &incy_t);
      }
    } else if (mLambda >= 1) {
      n_t = (ptrdiff_t)mLambda;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &TrialState->lambdaStopTest->data[0], &incx_t,
            &TrialState->lambdaStopTestPrev->data[0], &incy_t);
    }
    if (isFeasible &&
        (MeritFunction->nlpDualFeasError <= 1.0E-6 * optimRelativeFactor) &&
        (MeritFunction->nlpComplError <= 1.0E-6 * optimRelativeFactor)) {
      Flags->done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags->done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Flags->done = true;
        TrialState->sqpExitFlag = -3;
      } else {
        boolean_T guard1;
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          dxTooSmall = true;
          fullRank_R = (uint16_T)WorkingSet->nVar;
          rankR = 0;
          exitg1 = false;
          while ((!exitg1) && (rankR <= fullRank_R - 1)) {
            if (1.0E-6 *
                    muDoubleScalarMax(
                        1.0, muDoubleScalarAbs(TrialState->xstarsqp[rankR])) <=
                muDoubleScalarAbs(TrialState->delta_x.data[rankR])) {
              dxTooSmall = false;
              exitg1 = true;
            } else {
              rankR++;
            }
          }
          if (dxTooSmall) {
            if (!isFeasible) {
              if ((Flags->stepType == 2) || (WorkingSet->sizes[2] == 0)) {
                Flags->done = true;
                TrialState->sqpExitFlag = -2;
              } else {
                Flags->stepType = 2;
                Flags->failedLineSearch = false;
                Flags->stepAccepted = false;
                guard1 = true;
              }
            } else {
              int32_T nActiveConstr;
              nActiveConstr = WorkingSet->nActiveConstr;
              if (WorkingSet->nActiveConstr == 0) {
                Flags->done = true;
                TrialState->sqpExitFlag = 2;
              } else {
                real_T d;
                int32_T iQR_diag;
                if (TrialState->mNonlinIneq > 0) {
                  b_updateWorkingSetForNewQP(
                      emlrtRootTLSGlobal, TrialState->xstarsqp, WorkingSet,
                      WorkingSet->sizes[2], TrialState->mNonlinIneq,
                      TrialState->cIneq.data, WorkingSet->sizes[3], lb,
                      WorkingSet->sizes[4], ub, WorkingSet->sizes[0]);
                }
                for (fullRank_R = 0; fullRank_R < nActiveConstr; fullRank_R++) {
                  TrialState->lambda->data[fullRank_R] = 0.0;
                }
                factorQRE(QRManager, WorkingSet->ATwset, nVar_tmp,
                          nActiveConstr, WorkingSet->ldA);
                computeQ_(emlrtRootTLSGlobal, QRManager, QRManager->mrows);
                tol = -1.0;
                nlpComplErrorTmp = 0.0;
                TRANSA = 'T';
                m_t = (ptrdiff_t)nVar_tmp;
                n_t = (ptrdiff_t)nVar_tmp;
                lda_t = (ptrdiff_t)QRManager->ldq;
                incx_t = (ptrdiff_t)1;
                incy_t = (ptrdiff_t)1;
                dgemv(&TRANSA, &m_t, &n_t, &tol, &QRManager->Q->data[0], &lda_t,
                      &TrialState->grad.data[0], &incx_t, &nlpComplErrorTmp,
                      &memspace->workspace_float->data[0], &incy_t);
                tol = muDoubleScalarAbs(QRManager->QR->data[0]) *
                      muDoubleScalarMin(1.4901161193847656E-8,
                                        (real_T)muIntScalarMax_sint32(
                                            nVar_tmp, nActiveConstr) *
                                            2.2204460492503131E-16);
                fullRank_R = muIntScalarMin_sint32(nVar_tmp, nActiveConstr);
                rankR = 0;
                iQR_diag = 0;
                while (
                    (rankR < fullRank_R) &&
                    (muDoubleScalarAbs(QRManager->QR->data[iQR_diag]) > tol)) {
                  rankR++;
                  iQR_diag = (iQR_diag + QRManager->ldq) + 1;
                }
                if (rankR >= 1) {
                  TRANSA = 'N';
                  TRANSA1 = 'N';
                  UPLO1 = 'U';
                  n_t = (ptrdiff_t)rankR;
                  lda_t = (ptrdiff_t)QRManager->ldq;
                  incx_t = (ptrdiff_t)1;
                  dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                        &QRManager->QR->data[0], &lda_t,
                        &memspace->workspace_float->data[0], &incx_t);
                }
                fullRank_R = muIntScalarMin_sint32(nActiveConstr, fullRank_R);
                for (rankR = 0; rankR < fullRank_R; rankR++) {
                  TrialState->lambda->data[QRManager->jpvt.data[rankR] - 1] =
                      memspace->workspace_float->data[rankR];
                }
                sortLambdaQP(TrialState->lambda, WorkingSet->nActiveConstr,
                             WorkingSet->sizes, WorkingSet->isActiveIdx,
                             WorkingSet->Wid.data, WorkingSet->Wlocalidx.data,
                             memspace->workspace_float);
                b_computeGradLag(
                    emlrtRootTLSGlobal, memspace->workspace_float,
                    WorkingSet->ldA, nVar_tmp, TrialState->grad.data, mIneq,
                    WorkingSet->Aineq, WorkingSet->indexFixed.data, mFixed,
                    WorkingSet->indexLB.data, mLB, WorkingSet->indexUB.data,
                    mUB, TrialState->lambda);
                gradLag = memspace->workspace_float;
                gradLag_data = gradLag->data;
                tol = 0.0;
                rankR = 0;
                exitg1 = false;
                while ((!exitg1) && (rankR <= (uint16_T)nVar_tmp - 1)) {
                  dxTooSmall = ((!muDoubleScalarIsInf(gradLag_data[rankR])) &&
                                (!muDoubleScalarIsNaN(gradLag_data[rankR])));
                  if (!dxTooSmall) {
                    exitg1 = true;
                  } else {
                    tol = muDoubleScalarMax(
                        tol, muDoubleScalarAbs(gradLag_data[rankR]));
                    rankR++;
                  }
                }
                nlpComplErrorTmp = computeComplError(
                    emlrtRootTLSGlobal, fscales_cineq_constraint_size,
                    TrialState->xstarsqp, mIneq, TrialState->cIneq.data,
                    WorkingSet->indexLB.data, mLB, lb, WorkingSet->indexUB.data,
                    mUB, ub, TrialState->lambda, mFixed + 1);
                d = muDoubleScalarMax(tol, nlpComplErrorTmp);
                if (d <= muDoubleScalarMax(MeritFunction->nlpDualFeasError,
                                           MeritFunction->nlpComplError)) {
                  MeritFunction->nlpDualFeasError = tol;
                  MeritFunction->nlpComplError = nlpComplErrorTmp;
                  MeritFunction->firstOrderOpt = d;
                  if (mLambda >= 1) {
                    n_t = (ptrdiff_t)mLambda;
                    incx_t = (ptrdiff_t)1;
                    incy_t = (ptrdiff_t)1;
                    dcopy(&n_t, &TrialState->lambda->data[0], &incx_t,
                          &TrialState->lambdaStopTest->data[0], &incy_t);
                  }
                }
                if ((MeritFunction->nlpDualFeasError <=
                     1.0E-6 * optimRelativeFactor) &&
                    (MeritFunction->nlpComplError <=
                     1.0E-6 * optimRelativeFactor)) {
                  TrialState->sqpExitFlag = 1;
                } else {
                  TrialState->sqpExitFlag = 2;
                }
                Flags->done = true;
                guard1 = true;
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        if (guard1) {
          if (TrialState->sqpIterations >= 400) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          } else if (TrialState->FunctionEvaluations >= 4000) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          }
        }
      }
    }
  }
}

boolean_T test_exit(j_struct_T *MeritFunction,
                    int32_T fscales_cineq_constraint_size,
                    const i_struct_T *WorkingSet, h_struct_T *TrialState,
                    const real_T lb[40], const real_T ub[40],
                    boolean_T *Flags_fevalOK, boolean_T *Flags_done,
                    boolean_T *Flags_stepAccepted,
                    boolean_T *Flags_failedLineSearch, int32_T *Flags_stepType)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T optimRelativeFactor;
  int32_T idx_max;
  int32_T mLambda;
  boolean_T Flags_gradOK;
  boolean_T isFeasible;
  *Flags_fevalOK = true;
  *Flags_done = false;
  *Flags_stepAccepted = false;
  *Flags_failedLineSearch = false;
  *Flags_stepType = 1;
  mLambda =
      ((WorkingSet->sizes[0] + WorkingSet->sizes[2]) + WorkingSet->sizes[3]) +
      WorkingSet->sizes[4];
  if (mLambda >= 1) {
    n_t = (ptrdiff_t)mLambda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &TrialState->lambdasqp->data[0], &incx_t,
          &TrialState->lambdaStopTest->data[0], &incy_t);
  }
  computeGradLag(emlrtRootTLSGlobal, TrialState->gradLag.data, WorkingSet->ldA,
                 WorkingSet->nVar, TrialState->grad.data, WorkingSet->sizes[2],
                 WorkingSet->Aineq, WorkingSet->indexFixed.data,
                 WorkingSet->sizes[0], WorkingSet->indexLB.data,
                 WorkingSet->sizes[3], WorkingSet->indexUB.data,
                 WorkingSet->sizes[4], TrialState->lambdaStopTest);
  if (WorkingSet->nVar < 1) {
    idx_max = 0;
  } else {
    n_t = (ptrdiff_t)WorkingSet->nVar;
    incx_t = (ptrdiff_t)1;
    n_t = idamax(&n_t, &TrialState->grad.data[0], &incx_t);
    idx_max = (int32_T)n_t;
  }
  optimRelativeFactor = muDoubleScalarMax(
      1.0, muDoubleScalarAbs(TrialState->grad.data[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  MeritFunction->nlpPrimalFeasError = computePrimalFeasError(
      emlrtRootTLSGlobal, TrialState->xstarsqp,
      WorkingSet->sizes[2] - TrialState->mNonlinIneq, TrialState->mNonlinIneq,
      TrialState->cIneq.data, WorkingSet->indexLB.data, WorkingSet->sizes[3],
      lb, WorkingSet->indexUB.data, WorkingSet->sizes[4], ub);
  MeritFunction->feasRelativeFactor =
      muDoubleScalarMax(1.0, MeritFunction->nlpPrimalFeasError);
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                1.0E-6 * MeritFunction->feasRelativeFactor);
  Flags_gradOK =
      computeDualFeasError(WorkingSet->nVar, TrialState->gradLag.data,
                           &MeritFunction->nlpDualFeasError);
  if (!Flags_gradOK) {
    *Flags_done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = computeComplError(
        emlrtRootTLSGlobal, fscales_cineq_constraint_size, TrialState->xstarsqp,
        WorkingSet->sizes[2], TrialState->cIneq.data, WorkingSet->indexLB.data,
        WorkingSet->sizes[3], lb, WorkingSet->indexUB.data,
        WorkingSet->sizes[4], ub, TrialState->lambdaStopTest,
        WorkingSet->sizes[0] + 1);
    MeritFunction->firstOrderOpt = muDoubleScalarMax(
        MeritFunction->nlpDualFeasError, MeritFunction->nlpComplError);
    if (mLambda >= 1) {
      n_t = (ptrdiff_t)mLambda;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &TrialState->lambdaStopTest->data[0], &incx_t,
            &TrialState->lambdaStopTestPrev->data[0], &incy_t);
    }
    if (isFeasible &&
        (MeritFunction->nlpDualFeasError <= 1.0E-6 * optimRelativeFactor) &&
        (MeritFunction->nlpComplError <= 1.0E-6 * optimRelativeFactor)) {
      *Flags_done = true;
      TrialState->sqpExitFlag = 1;
    } else if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
      *Flags_done = true;
      TrialState->sqpExitFlag = -3;
    } else if (TrialState->FunctionEvaluations >= 4000) {
      *Flags_done = true;
      TrialState->sqpExitFlag = 0;
    }
  }
  return Flags_gradOK;
}

/* End of code generation (test_exit.c) */
