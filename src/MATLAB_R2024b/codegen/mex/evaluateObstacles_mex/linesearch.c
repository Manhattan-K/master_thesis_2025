/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * linesearch.c
 *
 * Code generation for function 'linesearch'
 *
 */

/* Include files */
#include "linesearch.h"
#include "computeConstraints_.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "followerMPCandUpdate.h"
#include "leaderMPCandUpdate.h"
#include "leaderMPCandUpdateHalt.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
real_T b_linesearch(boolean_T *evalWellDefined, int32_T WorkingSet_nVar,
                    int32_T WorkingSet_ldA,
                    const emxArray_real_T *WorkingSet_Aineq,
                    j_struct_T *TrialState, real_T MeritFunction_penaltyParam,
                    real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                    real_T MeritFunction_phiFullStep,
                    int32_T c_FcnEvaluator_next_next_next_n,
                    const real_T d_FcnEvaluator_next_next_next_n[3],
                    const struct5_T *e_FcnEvaluator_next_next_next_n,
                    real_T f_FcnEvaluator_next_next_next_n,
                    const struct3_T g_FcnEvaluator_next_next_next_n,
                    const h_struct_T *h_FcnEvaluator_next_next_next_n,
                    boolean_T socTaken, int32_T *exitflag)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emxArray_real_T *y;
  const real_T *WorkingSet_Aineq_data;
  real_T alpha;
  real_T beta1;
  real_T phi_alpha;
  real_T *y_data;
  int32_T i;
  int32_T idx;
  int32_T loop_ub;
  int32_T mLinIneq;
  char_T TRANSA;
  WorkingSet_Aineq_data = WorkingSet_Aineq->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  mLinIneq = TrialState->mIneq - TrialState->mNonlinIneq;
  alpha = 1.0;
  *exitflag = 1;
  phi_alpha = MeritFunction_phiFullStep;
  emxInit_real_T(&y, 1);
  i = y->size[0];
  y->size[0] = TrialState->searchDir.size[0];
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  loop_ub = TrialState->searchDir.size[0];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = TrialState->searchDir.data[i];
  }
  if (WorkingSet_nVar >= 1) {
    n_t = (ptrdiff_t)WorkingSet_nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &TrialState->delta_x.data[0], &incx_t, &y_data[0], &incy_t);
  }
  loop_ub = y->size[0];
  TrialState->searchDir.size[0] = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    TrialState->searchDir.data[i] = y_data[i];
  }
  emxFree_real_T(&y);
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (TrialState->FunctionEvaluations < 4000) {
      if ((*evalWellDefined) &&
          (phi_alpha <=
           MeritFunction_phi + alpha * 0.0001 * MeritFunction_phiPrimePlus)) {
        exitg1 = 1;
      } else {
        __m256d r;
        int32_T vectorUB_tmp;
        boolean_T exitg2;
        boolean_T tooSmallX;
        alpha *= 0.7;
        i = (uint16_T)WorkingSet_nVar;
        loop_ub = ((uint16_T)WorkingSet_nVar >> 2) << 2;
        vectorUB_tmp = loop_ub - 4;
        for (idx = 0; idx <= vectorUB_tmp; idx += 4) {
          r = _mm256_loadu_pd(&TrialState->xstar.data[idx]);
          _mm256_storeu_pd(&TrialState->delta_x.data[idx],
                           _mm256_mul_pd(_mm256_set1_pd(alpha), r));
        }
        for (idx = loop_ub; idx < i; idx++) {
          TrialState->delta_x.data[idx] = alpha * TrialState->xstar.data[idx];
        }
        if (socTaken) {
          phi_alpha = alpha * alpha;
          if (WorkingSet_nVar >= 1) {
            n_t = (ptrdiff_t)WorkingSet_nVar;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            daxpy(&n_t, &phi_alpha, &TrialState->socDirection.data[0], &incx_t,
                  &TrialState->delta_x.data[0], &incy_t);
          }
        }
        tooSmallX = true;
        idx = 0;
        exitg2 = false;
        while ((!exitg2) && (idx <= (uint16_T)WorkingSet_nVar - 1)) {
          if (1.0E-6 * muDoubleScalarMax(
                           1.0, muDoubleScalarAbs(TrialState->xstarsqp[idx])) <=
              muDoubleScalarAbs(TrialState->delta_x.data[idx])) {
            tooSmallX = false;
            exitg2 = true;
          } else {
            idx++;
          }
        }
        if (tooSmallX) {
          *exitflag = -2;
          exitg1 = 1;
        } else {
          for (idx = 0; idx <= vectorUB_tmp; idx += 4) {
            __m256d r1;
            r = _mm256_loadu_pd(&TrialState->xstarsqp_old[idx]);
            r1 = _mm256_loadu_pd(&TrialState->delta_x.data[idx]);
            _mm256_storeu_pd(&TrialState->xstarsqp[idx], _mm256_add_pd(r, r1));
          }
          for (idx = loop_ub; idx < i; idx++) {
            TrialState->xstarsqp[idx] =
                TrialState->xstarsqp_old[idx] + TrialState->delta_x.data[idx];
          }
          phi_alpha = leaderMPCandUpdate_anonFcn1(
              h_FcnEvaluator_next_next_next_n->x0,
              h_FcnEvaluator_next_next_next_n->sys.n,
              h_FcnEvaluator_next_next_next_n->sys.Ts,
              h_FcnEvaluator_next_next_next_n->robotParams.W,
              h_FcnEvaluator_next_next_next_n->robotParams.W_hat,
              h_FcnEvaluator_next_next_next_n->robotParams.R_hat,
              h_FcnEvaluator_next_next_next_n->N, TrialState->xstarsqp);
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
            loop_ub = b_computeConstraints_(
                c_FcnEvaluator_next_next_next_n,
                d_FcnEvaluator_next_next_next_n,
                e_FcnEvaluator_next_next_next_n,
                f_FcnEvaluator_next_next_next_n,
                g_FcnEvaluator_next_next_next_n, TrialState->xstarsqp,
                TrialState->cIneq.data, TrialState->iNonIneq0);
          }
          TrialState->sqpFval = phi_alpha;
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
                  (real_T *)&WorkingSet_Aineq_data[0], &lda_t,
                  &TrialState->xstarsqp[0], &incx_t, &beta1,
                  &TrialState->cIneq.data[0], &incy_t);
          }
          TrialState->FunctionEvaluations++;
          *evalWellDefined = (loop_ub == 1);
          if (*evalWellDefined) {
            phi_alpha = 0.0;
            i = (uint16_T)TrialState->mIneq;
            for (idx = 0; idx < i; idx++) {
              beta1 = TrialState->cIneq.data[idx];
              if (beta1 > 0.0) {
                phi_alpha += beta1;
              }
            }
            phi_alpha =
                TrialState->sqpFval + MeritFunction_penaltyParam * phi_alpha;
          } else {
            phi_alpha = rtInf;
          }
        }
      }
    } else {
      *exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return alpha;
}

real_T c_linesearch(boolean_T *evalWellDefined, int32_T WorkingSet_nVar,
                    int32_T WorkingSet_ldA,
                    const emxArray_real_T *WorkingSet_Aineq,
                    j_struct_T *TrialState, real_T MeritFunction_penaltyParam,
                    real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                    real_T MeritFunction_phiFullStep,
                    int32_T c_FcnEvaluator_next_next_next_n,
                    const real_T d_FcnEvaluator_next_next_next_n[3],
                    const struct5_T *e_FcnEvaluator_next_next_next_n,
                    real_T f_FcnEvaluator_next_next_next_n,
                    const struct3_T g_FcnEvaluator_next_next_next_n,
                    const i_struct_T *h_FcnEvaluator_next_next_next_n,
                    boolean_T socTaken, int32_T *exitflag)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emxArray_real_T *y;
  const real_T *WorkingSet_Aineq_data;
  real_T alpha;
  real_T beta1;
  real_T phi_alpha;
  real_T *y_data;
  int32_T i;
  int32_T idx;
  int32_T loop_ub;
  int32_T mLinIneq;
  char_T TRANSA;
  WorkingSet_Aineq_data = WorkingSet_Aineq->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  mLinIneq = TrialState->mIneq - TrialState->mNonlinIneq;
  alpha = 1.0;
  *exitflag = 1;
  phi_alpha = MeritFunction_phiFullStep;
  emxInit_real_T(&y, 1);
  i = y->size[0];
  y->size[0] = TrialState->searchDir.size[0];
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  loop_ub = TrialState->searchDir.size[0];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = TrialState->searchDir.data[i];
  }
  if (WorkingSet_nVar >= 1) {
    n_t = (ptrdiff_t)WorkingSet_nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &TrialState->delta_x.data[0], &incx_t, &y_data[0], &incy_t);
  }
  loop_ub = y->size[0];
  TrialState->searchDir.size[0] = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    TrialState->searchDir.data[i] = y_data[i];
  }
  emxFree_real_T(&y);
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (TrialState->FunctionEvaluations < 4000) {
      if ((*evalWellDefined) &&
          (phi_alpha <=
           MeritFunction_phi + alpha * 0.0001 * MeritFunction_phiPrimePlus)) {
        exitg1 = 1;
      } else {
        __m256d r;
        int32_T vectorUB_tmp;
        boolean_T exitg2;
        boolean_T tooSmallX;
        alpha *= 0.7;
        i = (uint16_T)WorkingSet_nVar;
        loop_ub = ((uint16_T)WorkingSet_nVar >> 2) << 2;
        vectorUB_tmp = loop_ub - 4;
        for (idx = 0; idx <= vectorUB_tmp; idx += 4) {
          r = _mm256_loadu_pd(&TrialState->xstar.data[idx]);
          _mm256_storeu_pd(&TrialState->delta_x.data[idx],
                           _mm256_mul_pd(_mm256_set1_pd(alpha), r));
        }
        for (idx = loop_ub; idx < i; idx++) {
          TrialState->delta_x.data[idx] = alpha * TrialState->xstar.data[idx];
        }
        if (socTaken) {
          phi_alpha = alpha * alpha;
          if (WorkingSet_nVar >= 1) {
            n_t = (ptrdiff_t)WorkingSet_nVar;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            daxpy(&n_t, &phi_alpha, &TrialState->socDirection.data[0], &incx_t,
                  &TrialState->delta_x.data[0], &incy_t);
          }
        }
        tooSmallX = true;
        idx = 0;
        exitg2 = false;
        while ((!exitg2) && (idx <= (uint16_T)WorkingSet_nVar - 1)) {
          if (1.0E-6 * muDoubleScalarMax(
                           1.0, muDoubleScalarAbs(TrialState->xstarsqp[idx])) <=
              muDoubleScalarAbs(TrialState->delta_x.data[idx])) {
            tooSmallX = false;
            exitg2 = true;
          } else {
            idx++;
          }
        }
        if (tooSmallX) {
          *exitflag = -2;
          exitg1 = 1;
        } else {
          for (idx = 0; idx <= vectorUB_tmp; idx += 4) {
            __m256d r1;
            r = _mm256_loadu_pd(&TrialState->xstarsqp_old[idx]);
            r1 = _mm256_loadu_pd(&TrialState->delta_x.data[idx]);
            _mm256_storeu_pd(&TrialState->xstarsqp[idx], _mm256_add_pd(r, r1));
          }
          for (idx = loop_ub; idx < i; idx++) {
            TrialState->xstarsqp[idx] =
                TrialState->xstarsqp_old[idx] + TrialState->delta_x.data[idx];
          }
          phi_alpha = leaderMPCandUpdateHalt_anonFcn1(
              h_FcnEvaluator_next_next_next_n->x0,
              h_FcnEvaluator_next_next_next_n->sys.n,
              h_FcnEvaluator_next_next_next_n->sys.Ts,
              h_FcnEvaluator_next_next_next_n->N,
              h_FcnEvaluator_next_next_next_n->robotParams.Px,
              TrialState->xstarsqp);
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
            loop_ub = c_computeConstraints_(
                c_FcnEvaluator_next_next_next_n,
                d_FcnEvaluator_next_next_next_n,
                e_FcnEvaluator_next_next_next_n,
                f_FcnEvaluator_next_next_next_n,
                g_FcnEvaluator_next_next_next_n, TrialState->xstarsqp,
                TrialState->cIneq.data, TrialState->iNonIneq0);
          }
          TrialState->sqpFval = phi_alpha;
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
                  (real_T *)&WorkingSet_Aineq_data[0], &lda_t,
                  &TrialState->xstarsqp[0], &incx_t, &beta1,
                  &TrialState->cIneq.data[0], &incy_t);
          }
          TrialState->FunctionEvaluations++;
          *evalWellDefined = (loop_ub == 1);
          if (*evalWellDefined) {
            phi_alpha = 0.0;
            i = (uint16_T)TrialState->mIneq;
            for (idx = 0; idx < i; idx++) {
              beta1 = TrialState->cIneq.data[idx];
              if (beta1 > 0.0) {
                phi_alpha += beta1;
              }
            }
            phi_alpha =
                TrialState->sqpFval + MeritFunction_penaltyParam * phi_alpha;
          } else {
            phi_alpha = rtInf;
          }
        }
      }
    } else {
      *exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return alpha;
}

real_T linesearch(boolean_T *evalWellDefined, int32_T WorkingSet_nVar,
                  int32_T WorkingSet_ldA,
                  const emxArray_real_T *WorkingSet_Aineq,
                  j_struct_T *TrialState, real_T MeritFunction_penaltyParam,
                  real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                  real_T MeritFunction_phiFullStep,
                  int32_T c_FcnEvaluator_next_next_next_n,
                  const real_T d_FcnEvaluator_next_next_next_n[3],
                  const struct5_T *e_FcnEvaluator_next_next_next_n,
                  real_T f_FcnEvaluator_next_next_next_n,
                  const struct3_T g_FcnEvaluator_next_next_next_n,
                  const c_struct_T *h_FcnEvaluator_next_next_next_n,
                  boolean_T socTaken, int32_T *exitflag)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emxArray_real_T *y;
  real_T workspaceIneq_data[4241];
  const real_T *WorkingSet_Aineq_data;
  real_T alpha;
  real_T beta1;
  real_T phi_alpha;
  real_T *y_data;
  int32_T i;
  int32_T idx;
  int32_T loop_ub;
  int32_T mLinIneq;
  char_T TRANSA;
  WorkingSet_Aineq_data = WorkingSet_Aineq->data;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  mLinIneq = TrialState->mIneq - TrialState->mNonlinIneq;
  alpha = 1.0;
  *exitflag = 1;
  phi_alpha = MeritFunction_phiFullStep;
  emxInit_real_T(&y, 1);
  i = y->size[0];
  y->size[0] = TrialState->searchDir.size[0];
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  loop_ub = TrialState->searchDir.size[0];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = TrialState->searchDir.data[i];
  }
  if (WorkingSet_nVar >= 1) {
    n_t = (ptrdiff_t)WorkingSet_nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &TrialState->delta_x.data[0], &incx_t, &y_data[0], &incy_t);
  }
  loop_ub = y->size[0];
  TrialState->searchDir.size[0] = y->size[0];
  for (i = 0; i < loop_ub; i++) {
    TrialState->searchDir.data[i] = y_data[i];
  }
  emxFree_real_T(&y);
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (TrialState->FunctionEvaluations < 4000) {
      if ((*evalWellDefined) &&
          (phi_alpha <=
           MeritFunction_phi + alpha * 0.0001 * MeritFunction_phiPrimePlus)) {
        exitg1 = 1;
      } else {
        __m256d r;
        int32_T vectorUB_tmp;
        boolean_T exitg2;
        boolean_T tooSmallX;
        alpha *= 0.7;
        i = (uint16_T)WorkingSet_nVar;
        loop_ub = ((uint16_T)WorkingSet_nVar >> 2) << 2;
        vectorUB_tmp = loop_ub - 4;
        for (idx = 0; idx <= vectorUB_tmp; idx += 4) {
          r = _mm256_loadu_pd(&TrialState->xstar.data[idx]);
          _mm256_storeu_pd(&TrialState->delta_x.data[idx],
                           _mm256_mul_pd(_mm256_set1_pd(alpha), r));
        }
        for (idx = loop_ub; idx < i; idx++) {
          TrialState->delta_x.data[idx] = alpha * TrialState->xstar.data[idx];
        }
        if (socTaken) {
          phi_alpha = alpha * alpha;
          if (WorkingSet_nVar >= 1) {
            n_t = (ptrdiff_t)WorkingSet_nVar;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            daxpy(&n_t, &phi_alpha, &TrialState->socDirection.data[0], &incx_t,
                  &TrialState->delta_x.data[0], &incy_t);
          }
        }
        tooSmallX = true;
        idx = 0;
        exitg2 = false;
        while ((!exitg2) && (idx <= (uint16_T)WorkingSet_nVar - 1)) {
          if (1.0E-6 * muDoubleScalarMax(
                           1.0, muDoubleScalarAbs(TrialState->xstarsqp[idx])) <=
              muDoubleScalarAbs(TrialState->delta_x.data[idx])) {
            tooSmallX = false;
            exitg2 = true;
          } else {
            idx++;
          }
        }
        if (tooSmallX) {
          *exitflag = -2;
          exitg1 = 1;
        } else {
          real_T fval;
          for (idx = 0; idx <= vectorUB_tmp; idx += 4) {
            __m256d r1;
            r = _mm256_loadu_pd(&TrialState->xstarsqp_old[idx]);
            r1 = _mm256_loadu_pd(&TrialState->delta_x.data[idx]);
            _mm256_storeu_pd(&TrialState->xstarsqp[idx], _mm256_add_pd(r, r1));
          }
          for (idx = loop_ub; idx < i; idx++) {
            TrialState->xstarsqp[idx] =
                TrialState->xstarsqp_old[idx] + TrialState->delta_x.data[idx];
          }
          vectorUB_tmp = TrialState->cIneq.size[0];
          loop_ub = TrialState->cIneq.size[0];
          if (loop_ub - 1 >= 0) {
            memcpy(&workspaceIneq_data[0], &TrialState->cIneq.data[0],
                   (uint32_T)loop_ub * sizeof(real_T));
          }
          fval = followerMPCandUpdate_anonFcn1(
              h_FcnEvaluator_next_next_next_n->x0,
              h_FcnEvaluator_next_next_next_n->sys.n,
              h_FcnEvaluator_next_next_next_n->sys.Ts,
              h_FcnEvaluator_next_next_next_n->N,
              h_FcnEvaluator_next_next_next_n->X_L_stacked,
              h_FcnEvaluator_next_next_next_n->robotParams.Px,
              h_FcnEvaluator_next_next_next_n->robotParams.d_FL_sq,
              h_FcnEvaluator_next_next_next_n->robotParams.C,
              h_FcnEvaluator_next_next_next_n->robotParams.beta_N,
              TrialState->xstarsqp);
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
            loop_ub = computeConstraints_(
                c_FcnEvaluator_next_next_next_n,
                d_FcnEvaluator_next_next_next_n,
                e_FcnEvaluator_next_next_next_n,
                f_FcnEvaluator_next_next_next_n,
                g_FcnEvaluator_next_next_next_n, TrialState->xstarsqp,
                workspaceIneq_data, TrialState->iNonIneq0);
          }
          TrialState->sqpFval = fval;
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
                  (real_T *)&WorkingSet_Aineq_data[0], &lda_t,
                  &TrialState->xstarsqp[0], &incx_t, &beta1,
                  &workspaceIneq_data[0], &incy_t);
          }
          if (vectorUB_tmp - 1 >= 0) {
            memcpy(&TrialState->cIneq.data[0], &workspaceIneq_data[0],
                   (uint32_T)vectorUB_tmp * sizeof(real_T));
          }
          TrialState->FunctionEvaluations++;
          *evalWellDefined = (loop_ub == 1);
          if (*evalWellDefined) {
            phi_alpha = 0.0;
            i = (uint16_T)TrialState->mIneq;
            for (idx = 0; idx < i; idx++) {
              beta1 = workspaceIneq_data[idx];
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
      *exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  return alpha;
}

/* End of code generation (linesearch.c) */
