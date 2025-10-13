//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// test_exit.cpp
//
// Code generation for function 'test_exit'
//

// Include files
#include "test_exit.h"
#include "computeComplError.h"
#include "computeDualFeasError.h"
#include "computeGradLag.h"
#include "computePrimalFeasError.h"
#include "computeQ_.h"
#include "factorQRE.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSetForNewQP.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void b_test_exit(struct_T &Flags, c_struct_T &memspace,
                 h_struct_T &b_MeritFunction,
                 int32_T fscales_cineq_constraint_size, g_struct_T &WorkingSet,
                 f_struct_T &b_TrialState, d_struct_T &b_QRManager,
                 const real_T lb[40], const real_T ub[40])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
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
  char_T TRANSA;
  char_T TRANSA1;
  char_T UPLO1;
  boolean_T isFeasible;
  nVar_tmp = WorkingSet.nVar;
  mFixed = WorkingSet.sizes[0];
  mIneq = WorkingSet.sizes[2];
  mLB = WorkingSet.sizes[3];
  mUB = WorkingSet.sizes[4];
  mLambda =
      ((WorkingSet.sizes[0] + WorkingSet.sizes[2]) + WorkingSet.sizes[3]) +
      WorkingSet.sizes[4];
  if (mLambda >= 1) {
    n_t = (ptrdiff_t)mLambda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.lambdasqp.data())[0], &incx_t,
          &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
  }
  stopping::computeGradLag(
      b_TrialState.gradLag.data, WorkingSet.ldA, WorkingSet.nVar,
      b_TrialState.grad.data, WorkingSet.sizes[2], WorkingSet.Aineq,
      WorkingSet.indexFixed.data, WorkingSet.sizes[0], WorkingSet.indexLB.data,
      WorkingSet.sizes[3], WorkingSet.indexUB.data, WorkingSet.sizes[4],
      b_TrialState.lambdaStopTest);
  if (WorkingSet.nVar < 1) {
    fullRank_R = 0;
  } else {
    n_t = (ptrdiff_t)WorkingSet.nVar;
    incx_t = (ptrdiff_t)1;
    n_t = idamax(&n_t, &b_TrialState.grad.data[0], &incx_t);
    fullRank_R = (int32_T)n_t;
  }
  optimRelativeFactor = muDoubleScalarMax(
      1.0, muDoubleScalarAbs(b_TrialState.grad.data[fullRank_R - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  b_MeritFunction.nlpPrimalFeasError = stopping::computePrimalFeasError(
      b_TrialState.xstarsqp, WorkingSet.sizes[2] - b_TrialState.mNonlinIneq,
      b_TrialState.mNonlinIneq, b_TrialState.cIneq.data,
      WorkingSet.indexLB.data, WorkingSet.sizes[3], lb, WorkingSet.indexUB.data,
      WorkingSet.sizes[4], ub);
  if (b_TrialState.sqpIterations == 0) {
    b_MeritFunction.feasRelativeFactor =
        muDoubleScalarMax(1.0, b_MeritFunction.nlpPrimalFeasError);
  }
  isFeasible = (b_MeritFunction.nlpPrimalFeasError <=
                1.0E-6 * b_MeritFunction.feasRelativeFactor);
  Flags.gradOK =
      stopping::computeDualFeasError(WorkingSet.nVar, b_TrialState.gradLag.data,
                                     b_MeritFunction.nlpDualFeasError);
  if (!Flags.gradOK) {
    Flags.done = true;
    if (isFeasible) {
      b_TrialState.sqpExitFlag = 2;
    } else {
      b_TrialState.sqpExitFlag = -2;
    }
  } else {
    int32_T rankR;
    boolean_T dxTooSmall;
    boolean_T exitg1;
    b_MeritFunction.nlpComplError = stopping::computeComplError(
        fscales_cineq_constraint_size, b_TrialState.xstarsqp,
        WorkingSet.sizes[2], b_TrialState.cIneq.data, WorkingSet.indexLB.data,
        WorkingSet.sizes[3], lb, WorkingSet.indexUB.data, WorkingSet.sizes[4],
        ub, b_TrialState.lambdaStopTest, WorkingSet.sizes[0] + 1);
    b_MeritFunction.firstOrderOpt = muDoubleScalarMax(
        b_MeritFunction.nlpDualFeasError, b_MeritFunction.nlpComplError);
    if (b_TrialState.sqpIterations > 1) {
      stopping::computeGradLag(
          memspace.workspace_float, WorkingSet.ldA, WorkingSet.nVar,
          b_TrialState.grad.data, WorkingSet.sizes[2], WorkingSet.Aineq,
          WorkingSet.indexFixed.data, WorkingSet.sizes[0],
          WorkingSet.indexLB.data, WorkingSet.sizes[3], WorkingSet.indexUB.data,
          WorkingSet.sizes[4], b_TrialState.lambdaStopTestPrev);
      tol = 0.0;
      rankR = 0;
      exitg1 = false;
      while ((!exitg1) && (rankR <= static_cast<uint16_T>(nVar_tmp) - 1)) {
        dxTooSmall = ((!muDoubleScalarIsInf(memspace.workspace_float[rankR])) &&
                      (!muDoubleScalarIsNaN(memspace.workspace_float[rankR])));
        if (!dxTooSmall) {
          exitg1 = true;
        } else {
          tol = muDoubleScalarMax(
              tol, muDoubleScalarAbs(memspace.workspace_float[rankR]));
          rankR++;
        }
      }
      nlpComplErrorTmp = stopping::computeComplError(
          fscales_cineq_constraint_size, b_TrialState.xstarsqp,
          WorkingSet.sizes[2], b_TrialState.cIneq.data, WorkingSet.indexLB.data,
          WorkingSet.sizes[3], lb, WorkingSet.indexUB.data, WorkingSet.sizes[4],
          ub, b_TrialState.lambdaStopTestPrev, WorkingSet.sizes[0] + 1);
      if ((tol < b_MeritFunction.nlpDualFeasError) &&
          (nlpComplErrorTmp < b_MeritFunction.nlpComplError)) {
        b_MeritFunction.nlpDualFeasError = tol;
        b_MeritFunction.nlpComplError = nlpComplErrorTmp;
        b_MeritFunction.firstOrderOpt =
            muDoubleScalarMax(tol, nlpComplErrorTmp);
        if (mLambda >= 1) {
          n_t = (ptrdiff_t)mLambda;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &(b_TrialState.lambdaStopTestPrev.data())[0], &incx_t,
                &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
        }
      } else if (mLambda >= 1) {
        n_t = (ptrdiff_t)mLambda;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(b_TrialState.lambdaStopTest.data())[0], &incx_t,
              &(b_TrialState.lambdaStopTestPrev.data())[0], &incy_t);
      }
    } else if (mLambda >= 1) {
      n_t = (ptrdiff_t)mLambda;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(b_TrialState.lambdaStopTest.data())[0], &incx_t,
            &(b_TrialState.lambdaStopTestPrev.data())[0], &incy_t);
    }
    if (isFeasible &&
        (b_MeritFunction.nlpDualFeasError <= 1.0E-6 * optimRelativeFactor) &&
        (b_MeritFunction.nlpComplError <= 1.0E-6 * optimRelativeFactor)) {
      Flags.done = true;
      b_TrialState.sqpExitFlag = 1;
    } else {
      Flags.done = false;
      if (isFeasible && (b_TrialState.sqpFval < -1.0E+20)) {
        Flags.done = true;
        b_TrialState.sqpExitFlag = -3;
      } else {
        boolean_T guard1;
        guard1 = false;
        if (b_TrialState.sqpIterations > 0) {
          dxTooSmall = true;
          fullRank_R = static_cast<uint16_T>(WorkingSet.nVar);
          rankR = 0;
          exitg1 = false;
          while ((!exitg1) && (rankR <= fullRank_R - 1)) {
            if (1.0E-6 *
                    muDoubleScalarMax(
                        1.0, muDoubleScalarAbs(b_TrialState.xstarsqp[rankR])) <=
                muDoubleScalarAbs(b_TrialState.delta_x.data[rankR])) {
              dxTooSmall = false;
              exitg1 = true;
            } else {
              rankR++;
            }
          }
          if (dxTooSmall) {
            if (!isFeasible) {
              if ((Flags.stepType == 2) || (WorkingSet.sizes[2] == 0)) {
                Flags.done = true;
                b_TrialState.sqpExitFlag = -2;
              } else {
                Flags.stepType = 2;
                Flags.failedLineSearch = false;
                Flags.stepAccepted = false;
                guard1 = true;
              }
            } else {
              int32_T nActiveConstr;
              nActiveConstr = WorkingSet.nActiveConstr;
              if (WorkingSet.nActiveConstr == 0) {
                Flags.done = true;
                b_TrialState.sqpExitFlag = 2;
              } else {
                real_T d;
                int32_T iQR_diag;
                if (b_TrialState.mNonlinIneq > 0) {
                  internal::updateWorkingSetForNewQP(
                      b_TrialState.xstarsqp, WorkingSet, WorkingSet.sizes[2],
                      b_TrialState.mNonlinIneq, b_TrialState.cIneq.data,
                      WorkingSet.sizes[3], lb, WorkingSet.sizes[4], ub,
                      WorkingSet.sizes[0]);
                }
                for (fullRank_R = 0; fullRank_R < nActiveConstr; fullRank_R++) {
                  b_TrialState.lambda[fullRank_R] = 0.0;
                }
                QRManager::factorQRE(b_QRManager, WorkingSet.ATwset, nVar_tmp,
                                     nActiveConstr, WorkingSet.ldA);
                QRManager::computeQ_(b_QRManager, b_QRManager.mrows);
                tol = -1.0;
                nlpComplErrorTmp = 0.0;
                TRANSA = 'T';
                m_t = (ptrdiff_t)nVar_tmp;
                n_t = (ptrdiff_t)nVar_tmp;
                lda_t = (ptrdiff_t)b_QRManager.ldq;
                incx_t = (ptrdiff_t)1;
                incy_t = (ptrdiff_t)1;
                dgemv(&TRANSA, &m_t, &n_t, &tol, &(b_QRManager.Q.data())[0],
                      &lda_t, &b_TrialState.grad.data[0], &incx_t,
                      &nlpComplErrorTmp, &(memspace.workspace_float.data())[0],
                      &incy_t);
                tol =
                    muDoubleScalarAbs(b_QRManager.QR[0]) *
                    muDoubleScalarMin(1.4901161193847656E-8,
                                      static_cast<real_T>(muIntScalarMax_sint32(
                                          nVar_tmp, nActiveConstr)) *
                                          2.2204460492503131E-16);
                fullRank_R = muIntScalarMin_sint32(nVar_tmp, nActiveConstr);
                rankR = 0;
                iQR_diag = 0;
                while ((rankR < fullRank_R) &&
                       (muDoubleScalarAbs(b_QRManager.QR[iQR_diag]) > tol)) {
                  rankR++;
                  iQR_diag = (iQR_diag + b_QRManager.ldq) + 1;
                }
                if (rankR >= 1) {
                  TRANSA = 'N';
                  TRANSA1 = 'N';
                  UPLO1 = 'U';
                  n_t = (ptrdiff_t)rankR;
                  lda_t = (ptrdiff_t)b_QRManager.ldq;
                  incx_t = (ptrdiff_t)1;
                  dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                        &(b_QRManager.QR.data())[0], &lda_t,
                        &(memspace.workspace_float.data())[0], &incx_t);
                }
                fullRank_R = muIntScalarMin_sint32(nActiveConstr, fullRank_R);
                for (rankR = 0; rankR < fullRank_R; rankR++) {
                  b_TrialState.lambda[b_QRManager.jpvt.data[rankR] - 1] =
                      memspace.workspace_float[rankR];
                }
                qpactiveset::parseoutput::sortLambdaQP(
                    b_TrialState.lambda, WorkingSet.nActiveConstr,
                    WorkingSet.sizes, WorkingSet.isActiveIdx,
                    WorkingSet.Wid.data, WorkingSet.Wlocalidx.data,
                    memspace.workspace_float);
                stopping::computeGradLag(
                    memspace.workspace_float, WorkingSet.ldA, nVar_tmp,
                    b_TrialState.grad.data, mIneq, WorkingSet.Aineq,
                    WorkingSet.indexFixed.data, mFixed, WorkingSet.indexLB.data,
                    mLB, WorkingSet.indexUB.data, mUB, b_TrialState.lambda);
                tol = 0.0;
                rankR = 0;
                exitg1 = false;
                while ((!exitg1) &&
                       (rankR <= static_cast<uint16_T>(nVar_tmp) - 1)) {
                  dxTooSmall =
                      ((!muDoubleScalarIsInf(
                           memspace.workspace_float[rankR])) &&
                       (!muDoubleScalarIsNaN(memspace.workspace_float[rankR])));
                  if (!dxTooSmall) {
                    exitg1 = true;
                  } else {
                    tol = muDoubleScalarMax(
                        tol,
                        muDoubleScalarAbs(memspace.workspace_float[rankR]));
                    rankR++;
                  }
                }
                nlpComplErrorTmp = stopping::computeComplError(
                    fscales_cineq_constraint_size, b_TrialState.xstarsqp, mIneq,
                    b_TrialState.cIneq.data, WorkingSet.indexLB.data, mLB, lb,
                    WorkingSet.indexUB.data, mUB, ub, b_TrialState.lambda,
                    mFixed + 1);
                d = muDoubleScalarMax(tol, nlpComplErrorTmp);
                if (d <= muDoubleScalarMax(b_MeritFunction.nlpDualFeasError,
                                           b_MeritFunction.nlpComplError)) {
                  b_MeritFunction.nlpDualFeasError = tol;
                  b_MeritFunction.nlpComplError = nlpComplErrorTmp;
                  b_MeritFunction.firstOrderOpt = d;
                  if (mLambda >= 1) {
                    n_t = (ptrdiff_t)mLambda;
                    incx_t = (ptrdiff_t)1;
                    incy_t = (ptrdiff_t)1;
                    dcopy(&n_t, &(b_TrialState.lambda.data())[0], &incx_t,
                          &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
                  }
                }
                if ((b_MeritFunction.nlpDualFeasError <=
                     1.0E-6 * optimRelativeFactor) &&
                    (b_MeritFunction.nlpComplError <=
                     1.0E-6 * optimRelativeFactor)) {
                  b_TrialState.sqpExitFlag = 1;
                } else {
                  b_TrialState.sqpExitFlag = 2;
                }
                Flags.done = true;
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
          if (b_TrialState.sqpIterations >= 400) {
            Flags.done = true;
            b_TrialState.sqpExitFlag = 0;
          } else if (b_TrialState.FunctionEvaluations >= 4000) {
            Flags.done = true;
            b_TrialState.sqpExitFlag = 0;
          }
        }
      }
    }
  }
}

boolean_T test_exit(h_struct_T &b_MeritFunction,
                    int32_T fscales_cineq_constraint_size,
                    const g_struct_T &WorkingSet, f_struct_T &b_TrialState,
                    const real_T lb[40], const real_T ub[40],
                    boolean_T &Flags_fevalOK, boolean_T &Flags_done,
                    boolean_T &Flags_stepAccepted,
                    boolean_T &Flags_failedLineSearch, int32_T &Flags_stepType)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T optimRelativeFactor;
  int32_T idx_max;
  int32_T mLambda;
  boolean_T Flags_gradOK;
  boolean_T isFeasible;
  Flags_fevalOK = true;
  Flags_done = false;
  Flags_stepAccepted = false;
  Flags_failedLineSearch = false;
  Flags_stepType = 1;
  mLambda =
      ((WorkingSet.sizes[0] + WorkingSet.sizes[2]) + WorkingSet.sizes[3]) +
      WorkingSet.sizes[4];
  if (mLambda >= 1) {
    n_t = (ptrdiff_t)mLambda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.lambdasqp.data())[0], &incx_t,
          &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
  }
  stopping::computeGradLag(
      b_TrialState.gradLag.data, WorkingSet.ldA, WorkingSet.nVar,
      b_TrialState.grad.data, WorkingSet.sizes[2], WorkingSet.Aineq,
      WorkingSet.indexFixed.data, WorkingSet.sizes[0], WorkingSet.indexLB.data,
      WorkingSet.sizes[3], WorkingSet.indexUB.data, WorkingSet.sizes[4],
      b_TrialState.lambdaStopTest);
  if (WorkingSet.nVar < 1) {
    idx_max = 0;
  } else {
    n_t = (ptrdiff_t)WorkingSet.nVar;
    incx_t = (ptrdiff_t)1;
    n_t = idamax(&n_t, &b_TrialState.grad.data[0], &incx_t);
    idx_max = (int32_T)n_t;
  }
  optimRelativeFactor = muDoubleScalarMax(
      1.0, muDoubleScalarAbs(b_TrialState.grad.data[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  b_MeritFunction.nlpPrimalFeasError = stopping::computePrimalFeasError(
      b_TrialState.xstarsqp, WorkingSet.sizes[2] - b_TrialState.mNonlinIneq,
      b_TrialState.mNonlinIneq, b_TrialState.cIneq.data,
      WorkingSet.indexLB.data, WorkingSet.sizes[3], lb, WorkingSet.indexUB.data,
      WorkingSet.sizes[4], ub);
  b_MeritFunction.feasRelativeFactor =
      muDoubleScalarMax(1.0, b_MeritFunction.nlpPrimalFeasError);
  isFeasible = (b_MeritFunction.nlpPrimalFeasError <=
                1.0E-6 * b_MeritFunction.feasRelativeFactor);
  Flags_gradOK =
      stopping::computeDualFeasError(WorkingSet.nVar, b_TrialState.gradLag.data,
                                     b_MeritFunction.nlpDualFeasError);
  if (!Flags_gradOK) {
    Flags_done = true;
    if (isFeasible) {
      b_TrialState.sqpExitFlag = 2;
    } else {
      b_TrialState.sqpExitFlag = -2;
    }
  } else {
    b_MeritFunction.nlpComplError = stopping::computeComplError(
        fscales_cineq_constraint_size, b_TrialState.xstarsqp,
        WorkingSet.sizes[2], b_TrialState.cIneq.data, WorkingSet.indexLB.data,
        WorkingSet.sizes[3], lb, WorkingSet.indexUB.data, WorkingSet.sizes[4],
        ub, b_TrialState.lambdaStopTest, WorkingSet.sizes[0] + 1);
    b_MeritFunction.firstOrderOpt = muDoubleScalarMax(
        b_MeritFunction.nlpDualFeasError, b_MeritFunction.nlpComplError);
    if (mLambda >= 1) {
      n_t = (ptrdiff_t)mLambda;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(b_TrialState.lambdaStopTest.data())[0], &incx_t,
            &(b_TrialState.lambdaStopTestPrev.data())[0], &incy_t);
    }
    if (isFeasible &&
        (b_MeritFunction.nlpDualFeasError <= 1.0E-6 * optimRelativeFactor) &&
        (b_MeritFunction.nlpComplError <= 1.0E-6 * optimRelativeFactor)) {
      Flags_done = true;
      b_TrialState.sqpExitFlag = 1;
    } else if (isFeasible && (b_TrialState.sqpFval < -1.0E+20)) {
      Flags_done = true;
      b_TrialState.sqpExitFlag = -3;
    } else if (b_TrialState.FunctionEvaluations >= 4000) {
      Flags_done = true;
      b_TrialState.sqpExitFlag = 0;
    }
  }
  return Flags_gradOK;
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (test_exit.cpp)
