//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linesearch.cpp
//
// Code generation for function 'linesearch'
//

// Include files
#include "linesearch.h"
#include "anonymous_function.h"
#include "computeConstraints_.h"
#include "followerMPCandUpdate.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "mexFunctions_data.h"
#include "mexFunctions_types.h"
#include "mexFunctions_types1.h"
#include "mexFunctions_types2.h"
#include "rt_nonfinite.h"
#include "stickyStruct.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
real_T b_linesearch(boolean_T &evalWellDefined, int32_T WorkingSet_nVar,
                    int32_T WorkingSet_ldA,
                    const array<real_T, 1U> &WorkingSet_Aineq,
                    f_struct_T &b_TrialState, real_T MeritFunction_penaltyParam,
                    real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                    real_T MeritFunction_phiFullStep,
                    const ::coder::internal::i_stickyStruct &FcnEvaluator,
                    boolean_T socTaken, int32_T &exitflag)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  array<real_T, 1U> y;
  real_T alpha;
  real_T beta1;
  real_T phi_alpha;
  int32_T i;
  int32_T loop_ub;
  int32_T mLinIneq;
  char_T TRANSA;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  mLinIneq = b_TrialState.mIneq - b_TrialState.mNonlinIneq;
  alpha = 1.0;
  exitflag = 1;
  phi_alpha = MeritFunction_phiFullStep;
  y.set_size(b_TrialState.searchDir.size[0]);
  loop_ub = b_TrialState.searchDir.size[0];
  for (i = 0; i < loop_ub; i++) {
    y[i] = b_TrialState.searchDir.data[i];
  }
  if (WorkingSet_nVar >= 1) {
    n_t = (ptrdiff_t)WorkingSet_nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &b_TrialState.delta_x.data[0], &incx_t, &(y.data())[0],
          &incy_t);
  }
  loop_ub = y.size(0);
  b_TrialState.searchDir.size[0] = y.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_TrialState.searchDir.data[i] = y[i];
  }
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (b_TrialState.FunctionEvaluations < 4000) {
      if (evalWellDefined &&
          (phi_alpha <=
           MeritFunction_phi + alpha * 0.0001 * MeritFunction_phiPrimePlus)) {
        exitg1 = 1;
      } else {
        boolean_T exitg2;
        boolean_T tooSmallX;
        alpha *= 0.7;
        i = static_cast<uint16_T>(WorkingSet_nVar);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          b_TrialState.delta_x.data[loop_ub] =
              alpha * b_TrialState.xstar.data[loop_ub];
        }
        if (socTaken) {
          phi_alpha = alpha * alpha;
          if (WorkingSet_nVar >= 1) {
            n_t = (ptrdiff_t)WorkingSet_nVar;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            daxpy(&n_t, &phi_alpha, &b_TrialState.socDirection.data[0], &incx_t,
                  &b_TrialState.delta_x.data[0], &incy_t);
          }
        }
        tooSmallX = true;
        loop_ub = 0;
        exitg2 = false;
        while ((!exitg2) &&
               (loop_ub <= static_cast<uint16_T>(WorkingSet_nVar) - 1)) {
          if (1.0E-6 *
                  muDoubleScalarMax(
                      1.0, muDoubleScalarAbs(b_TrialState.xstarsqp[loop_ub])) <=
              muDoubleScalarAbs(b_TrialState.delta_x.data[loop_ub])) {
            tooSmallX = false;
            exitg2 = true;
          } else {
            loop_ub++;
          }
        }
        if (tooSmallX) {
          exitflag = -2;
          exitg1 = 1;
        } else {
          for (loop_ub = 0; loop_ub < i; loop_ub++) {
            b_TrialState.xstarsqp[loop_ub] =
                b_TrialState.xstarsqp_old[loop_ub] +
                b_TrialState.delta_x.data[loop_ub];
          }
          phi_alpha = leaderMPCandUpdate_anonFcn1(
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.x0,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.sys.n,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.sys.Ts,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.robotParams.W,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.robotParams.W_hat,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.robotParams.R_hat,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.N,
              b_TrialState.xstarsqp);
          loop_ub = 1;
          tooSmallX = muDoubleScalarIsNaN(phi_alpha);
          if (muDoubleScalarIsInf(phi_alpha) || tooSmallX) {
            if (tooSmallX) {
              loop_ub = -3;
            } else if (phi_alpha < 0.0) {
              loop_ub = -1;
            } else {
              loop_ub = -2;
            }
          }
          if (loop_ub == 1) {
            loop_ub = utils::ObjNonlinEvaluator::computeConstraints_(
                FcnEvaluator, b_TrialState.xstarsqp, b_TrialState.cIneq.data,
                b_TrialState.iNonIneq0);
          }
          b_TrialState.sqpFval = phi_alpha;
          if (mLinIneq > 0) {
            phi_alpha = 1.0;
            beta1 = -1.0;
            TRANSA = 'T';
            m_t = (ptrdiff_t)WorkingSet_nVar;
            n_t = (ptrdiff_t)mLinIneq;
            lda_t = (ptrdiff_t)WorkingSet_ldA;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dgemv(&TRANSA, &m_t, &n_t, &phi_alpha,
                  &(WorkingSet_Aineq.data())[0], &lda_t,
                  &b_TrialState.xstarsqp[0], &incx_t, &beta1,
                  &b_TrialState.cIneq.data[0], &incy_t);
          }
          b_TrialState.FunctionEvaluations++;
          evalWellDefined = (loop_ub == 1);
          if (evalWellDefined) {
            phi_alpha = 0.0;
            i = static_cast<uint16_T>(b_TrialState.mIneq);
            for (loop_ub = 0; loop_ub < i; loop_ub++) {
              beta1 = b_TrialState.cIneq.data[loop_ub];
              if (beta1 > 0.0) {
                phi_alpha += beta1;
              }
            }
            phi_alpha =
                b_TrialState.sqpFval + MeritFunction_penaltyParam * phi_alpha;
          } else {
            phi_alpha = rtInf;
          }
        }
      }
    } else {
      exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return alpha;
}

real_T c_linesearch(boolean_T &evalWellDefined, int32_T WorkingSet_nVar,
                    int32_T WorkingSet_ldA,
                    const array<real_T, 1U> &WorkingSet_Aineq,
                    f_struct_T &b_TrialState, real_T MeritFunction_penaltyParam,
                    real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                    real_T MeritFunction_phiFullStep,
                    const ::coder::internal::r_stickyStruct &FcnEvaluator,
                    boolean_T socTaken, int32_T &exitflag)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  array<real_T, 1U> y;
  real_T alpha;
  real_T beta1;
  real_T phi_alpha;
  int32_T i;
  int32_T loop_ub;
  int32_T mLinIneq;
  char_T TRANSA;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  mLinIneq = b_TrialState.mIneq - b_TrialState.mNonlinIneq;
  alpha = 1.0;
  exitflag = 1;
  phi_alpha = MeritFunction_phiFullStep;
  y.set_size(b_TrialState.searchDir.size[0]);
  loop_ub = b_TrialState.searchDir.size[0];
  for (i = 0; i < loop_ub; i++) {
    y[i] = b_TrialState.searchDir.data[i];
  }
  if (WorkingSet_nVar >= 1) {
    n_t = (ptrdiff_t)WorkingSet_nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &b_TrialState.delta_x.data[0], &incx_t, &(y.data())[0],
          &incy_t);
  }
  loop_ub = y.size(0);
  b_TrialState.searchDir.size[0] = y.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_TrialState.searchDir.data[i] = y[i];
  }
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (b_TrialState.FunctionEvaluations < 4000) {
      if (evalWellDefined &&
          (phi_alpha <=
           MeritFunction_phi + alpha * 0.0001 * MeritFunction_phiPrimePlus)) {
        exitg1 = 1;
      } else {
        boolean_T exitg2;
        boolean_T tooSmallX;
        alpha *= 0.7;
        i = static_cast<uint16_T>(WorkingSet_nVar);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          b_TrialState.delta_x.data[loop_ub] =
              alpha * b_TrialState.xstar.data[loop_ub];
        }
        if (socTaken) {
          phi_alpha = alpha * alpha;
          if (WorkingSet_nVar >= 1) {
            n_t = (ptrdiff_t)WorkingSet_nVar;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            daxpy(&n_t, &phi_alpha, &b_TrialState.socDirection.data[0], &incx_t,
                  &b_TrialState.delta_x.data[0], &incy_t);
          }
        }
        tooSmallX = true;
        loop_ub = 0;
        exitg2 = false;
        while ((!exitg2) &&
               (loop_ub <= static_cast<uint16_T>(WorkingSet_nVar) - 1)) {
          if (1.0E-6 *
                  muDoubleScalarMax(
                      1.0, muDoubleScalarAbs(b_TrialState.xstarsqp[loop_ub])) <=
              muDoubleScalarAbs(b_TrialState.delta_x.data[loop_ub])) {
            tooSmallX = false;
            exitg2 = true;
          } else {
            loop_ub++;
          }
        }
        if (tooSmallX) {
          exitflag = -2;
          exitg1 = 1;
        } else {
          for (loop_ub = 0; loop_ub < i; loop_ub++) {
            b_TrialState.xstarsqp[loop_ub] =
                b_TrialState.xstarsqp_old[loop_ub] +
                b_TrialState.delta_x.data[loop_ub];
          }
          phi_alpha = leaderMPCandUpdateHalt_anonFcn1(
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.x0,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.sys.n,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.sys.Ts,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.N,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.robotParams.Px,
              b_TrialState.xstarsqp);
          loop_ub = 1;
          tooSmallX = muDoubleScalarIsNaN(phi_alpha);
          if (muDoubleScalarIsInf(phi_alpha) || tooSmallX) {
            if (tooSmallX) {
              loop_ub = -3;
            } else if (phi_alpha < 0.0) {
              loop_ub = -1;
            } else {
              loop_ub = -2;
            }
          }
          if (loop_ub == 1) {
            loop_ub = utils::ObjNonlinEvaluator::computeConstraints_(
                FcnEvaluator, b_TrialState.xstarsqp, b_TrialState.cIneq.data,
                b_TrialState.iNonIneq0);
          }
          b_TrialState.sqpFval = phi_alpha;
          if (mLinIneq > 0) {
            phi_alpha = 1.0;
            beta1 = -1.0;
            TRANSA = 'T';
            m_t = (ptrdiff_t)WorkingSet_nVar;
            n_t = (ptrdiff_t)mLinIneq;
            lda_t = (ptrdiff_t)WorkingSet_ldA;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dgemv(&TRANSA, &m_t, &n_t, &phi_alpha,
                  &(WorkingSet_Aineq.data())[0], &lda_t,
                  &b_TrialState.xstarsqp[0], &incx_t, &beta1,
                  &b_TrialState.cIneq.data[0], &incy_t);
          }
          b_TrialState.FunctionEvaluations++;
          evalWellDefined = (loop_ub == 1);
          if (evalWellDefined) {
            phi_alpha = 0.0;
            i = static_cast<uint16_T>(b_TrialState.mIneq);
            for (loop_ub = 0; loop_ub < i; loop_ub++) {
              beta1 = b_TrialState.cIneq.data[loop_ub];
              if (beta1 > 0.0) {
                phi_alpha += beta1;
              }
            }
            phi_alpha =
                b_TrialState.sqpFval + MeritFunction_penaltyParam * phi_alpha;
          } else {
            phi_alpha = rtInf;
          }
        }
      }
    } else {
      exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return alpha;
}

real_T linesearch(boolean_T &evalWellDefined, int32_T WorkingSet_nVar,
                  int32_T WorkingSet_ldA,
                  const array<real_T, 1U> &WorkingSet_Aineq,
                  f_struct_T &b_TrialState, real_T MeritFunction_penaltyParam,
                  real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                  real_T MeritFunction_phiFullStep,
                  const ::coder::internal::bb_stickyStruct &FcnEvaluator,
                  boolean_T socTaken, int32_T &exitflag)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  array<real_T, 1U> y;
  real_T workspaceIneq_data[4241];
  real_T alpha;
  real_T beta1;
  real_T phi_alpha;
  int32_T loop_ub;
  int32_T mLinIneq;
  int32_T workspaceIneq_size;
  char_T TRANSA;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  mLinIneq = b_TrialState.mIneq - b_TrialState.mNonlinIneq;
  alpha = 1.0;
  exitflag = 1;
  phi_alpha = MeritFunction_phiFullStep;
  y.set_size(b_TrialState.searchDir.size[0]);
  loop_ub = b_TrialState.searchDir.size[0];
  for (workspaceIneq_size = 0; workspaceIneq_size < loop_ub;
       workspaceIneq_size++) {
    y[workspaceIneq_size] = b_TrialState.searchDir.data[workspaceIneq_size];
  }
  if (WorkingSet_nVar >= 1) {
    n_t = (ptrdiff_t)WorkingSet_nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &b_TrialState.delta_x.data[0], &incx_t, &(y.data())[0],
          &incy_t);
  }
  loop_ub = y.size(0);
  b_TrialState.searchDir.size[0] = y.size(0);
  for (workspaceIneq_size = 0; workspaceIneq_size < loop_ub;
       workspaceIneq_size++) {
    b_TrialState.searchDir.data[workspaceIneq_size] = y[workspaceIneq_size];
  }
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (b_TrialState.FunctionEvaluations < 4000) {
      if (evalWellDefined &&
          (phi_alpha <=
           MeritFunction_phi + alpha * 0.0001 * MeritFunction_phiPrimePlus)) {
        exitg1 = 1;
      } else {
        boolean_T exitg2;
        boolean_T tooSmallX;
        alpha *= 0.7;
        workspaceIneq_size = static_cast<uint16_T>(WorkingSet_nVar);
        for (loop_ub = 0; loop_ub < workspaceIneq_size; loop_ub++) {
          b_TrialState.delta_x.data[loop_ub] =
              alpha * b_TrialState.xstar.data[loop_ub];
        }
        if (socTaken) {
          phi_alpha = alpha * alpha;
          if (WorkingSet_nVar >= 1) {
            n_t = (ptrdiff_t)WorkingSet_nVar;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            daxpy(&n_t, &phi_alpha, &b_TrialState.socDirection.data[0], &incx_t,
                  &b_TrialState.delta_x.data[0], &incy_t);
          }
        }
        tooSmallX = true;
        loop_ub = 0;
        exitg2 = false;
        while ((!exitg2) &&
               (loop_ub <= static_cast<uint16_T>(WorkingSet_nVar) - 1)) {
          if (1.0E-6 *
                  muDoubleScalarMax(
                      1.0, muDoubleScalarAbs(b_TrialState.xstarsqp[loop_ub])) <=
              muDoubleScalarAbs(b_TrialState.delta_x.data[loop_ub])) {
            tooSmallX = false;
            exitg2 = true;
          } else {
            loop_ub++;
          }
        }
        if (tooSmallX) {
          exitflag = -2;
          exitg1 = 1;
        } else {
          real_T fval;
          for (loop_ub = 0; loop_ub < workspaceIneq_size; loop_ub++) {
            b_TrialState.xstarsqp[loop_ub] =
                b_TrialState.xstarsqp_old[loop_ub] +
                b_TrialState.delta_x.data[loop_ub];
          }
          workspaceIneq_size = b_TrialState.cIneq.size[0];
          loop_ub = b_TrialState.cIneq.size[0];
          if (loop_ub - 1 >= 0) {
            std::copy(&b_TrialState.cIneq.data[0],
                      &b_TrialState.cIneq.data[loop_ub],
                      &workspaceIneq_data[0]);
          }
          fval = followerMPCandUpdate_anonFcn1(
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.x0,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.sys.n,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.sys.Ts,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.N,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.X_L_stacked,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.robotParams.Px,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.robotParams.d_FL_sq,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.robotParams.C,
              FcnEvaluator.next.next.next.next.next.next.next.next.value
                  .workspace.robotParams.beta_N,
              b_TrialState.xstarsqp);
          loop_ub = 1;
          tooSmallX = muDoubleScalarIsNaN(fval);
          if (muDoubleScalarIsInf(fval) || tooSmallX) {
            if (tooSmallX) {
              loop_ub = -3;
            } else if (fval < 0.0) {
              loop_ub = -1;
            } else {
              loop_ub = -2;
            }
          }
          if (loop_ub == 1) {
            loop_ub = utils::ObjNonlinEvaluator::computeConstraints_(
                FcnEvaluator, b_TrialState.xstarsqp, workspaceIneq_data,
                b_TrialState.iNonIneq0);
          }
          b_TrialState.sqpFval = fval;
          if (mLinIneq > 0) {
            phi_alpha = 1.0;
            beta1 = -1.0;
            TRANSA = 'T';
            m_t = (ptrdiff_t)WorkingSet_nVar;
            n_t = (ptrdiff_t)mLinIneq;
            lda_t = (ptrdiff_t)WorkingSet_ldA;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dgemv(&TRANSA, &m_t, &n_t, &phi_alpha,
                  &(WorkingSet_Aineq.data())[0], &lda_t,
                  &b_TrialState.xstarsqp[0], &incx_t, &beta1,
                  &workspaceIneq_data[0], &incy_t);
          }
          if (workspaceIneq_size - 1 >= 0) {
            std::copy(&workspaceIneq_data[0],
                      &workspaceIneq_data[workspaceIneq_size],
                      &b_TrialState.cIneq.data[0]);
          }
          b_TrialState.FunctionEvaluations++;
          evalWellDefined = (loop_ub == 1);
          if (evalWellDefined) {
            phi_alpha = 0.0;
            workspaceIneq_size = static_cast<uint16_T>(b_TrialState.mIneq);
            for (loop_ub = 0; loop_ub < workspaceIneq_size; loop_ub++) {
              beta1 = workspaceIneq_data[loop_ub];
              if (beta1 > 0.0) {
                phi_alpha += beta1;
              }
            }
            phi_alpha = fval + MeritFunction_penaltyParam * phi_alpha;
          } else {
            phi_alpha = rtInf;
          }
        }
      }
    } else {
      exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return alpha;
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (linesearch.cpp)
