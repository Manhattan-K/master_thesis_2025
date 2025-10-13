/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compute_lambda.c
 *
 * Code generation for function 'compute_lambda'
 *
 */

/* Include files */
#include "compute_lambda.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include "omp.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void compute_lambda(emlrtCTX aTLS, emxArray_real_T *workspace,
                    h_struct_T *solution, const e_struct_T *objective,
                    const g_struct_T *qrmanager)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  real_T beta1;
  real_T tol;
  real_T *workspace_data;
  int32_T b_idx;
  int32_T compute_lambda_numThreads;
  int32_T nActiveConstr;
  char_T TRANSA;
  char_T TRANSA1;
  char_T UPLO1;
  workspace_data = workspace->data;
  nActiveConstr = qrmanager->ncols;
  if (qrmanager->ncols > 0) {
    int32_T idx;
    int32_T idxQR;
    boolean_T guard1;
    guard1 = false;
    if (objective->objtype != 4) {
      boolean_T nonDegenerate;
      tol = muDoubleScalarMin(1.4901161193847656E-8,
                              2.2204460492503131E-15 *
                                  (real_T)muIntScalarMax_sint32(
                                      qrmanager->mrows, qrmanager->ncols));
      if ((qrmanager->mrows > 0) && (qrmanager->ncols > 0)) {
        nonDegenerate = true;
      } else {
        nonDegenerate = false;
      }
      if (nonDegenerate) {
        boolean_T guard2;
        idx = nActiveConstr;
        guard2 = false;
        if (qrmanager->mrows < qrmanager->ncols) {
          idxQR = qrmanager->mrows + qrmanager->ldq * (qrmanager->ncols - 1);
          while ((idx > qrmanager->mrows) &&
                 (muDoubleScalarAbs(qrmanager->QR->data[idxQR - 1]) >= tol)) {
            idx--;
            idxQR -= qrmanager->ldq;
          }
          nonDegenerate = (idx == qrmanager->mrows);
          if (nonDegenerate) {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }
        if (guard2) {
          idxQR = idx + qrmanager->ldq * (idx - 1);
          while ((idx >= 1) &&
                 (muDoubleScalarAbs(qrmanager->QR->data[idxQR - 1]) >= tol)) {
            idx--;
            idxQR = (idxQR - qrmanager->ldq) - 1;
          }
          nonDegenerate = (idx == 0);
        }
      }
      if (!nonDegenerate) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      if (qrmanager->mrows >= 1) {
        tol = 1.0;
        beta1 = 0.0;
        TRANSA = 'T';
        m_t = (ptrdiff_t)qrmanager->mrows;
        n_t = (ptrdiff_t)qrmanager->ncols;
        lda_t = (ptrdiff_t)qrmanager->ldq;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dgemv(&TRANSA, &m_t, &n_t, &tol, &qrmanager->Q->data[0], &lda_t,
              (real_T *)&objective->grad.data[0], &incx_t, &beta1,
              &workspace_data[0], &incy_t);
      }
      TRANSA = 'N';
      TRANSA1 = 'N';
      UPLO1 = 'U';
      n_t = (ptrdiff_t)qrmanager->ncols;
      lda_t = (ptrdiff_t)qrmanager->ldq;
      incx_t = (ptrdiff_t)1;
      dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t, &qrmanager->QR->data[0], &lda_t,
            &workspace_data[0], &incx_t);
      idx = (nActiveConstr / 4) << 2;
      idxQR = idx - 4;
      for (b_idx = 0; b_idx <= idxQR; b_idx += 4) {
        __m256d r;
        r = _mm256_loadu_pd(&workspace_data[b_idx]);
        _mm256_storeu_pd(&solution->lambda->data[b_idx],
                         _mm256_mul_pd(r, _mm256_set1_pd(-1.0)));
      }
      if (nActiveConstr - idx < 1200) {
        for (b_idx = idx; b_idx < nActiveConstr; b_idx++) {
          solution->lambda->data[b_idx] = -workspace_data[b_idx];
        }
      } else {
        emlrtEnterParallelRegion(aTLS, omp_in_parallel());
        emlrtPushJmpBuf(aTLS, &emlrtJBStack);
        compute_lambda_numThreads =
            emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(),
                                 omp_get_num_procs());
#pragma omp parallel for num_threads(compute_lambda_numThreads)

        for (b_idx = idx; b_idx < nActiveConstr; b_idx++) {
          solution->lambda->data[b_idx] = -workspace_data[b_idx];
        }
        emlrtPopJmpBuf(aTLS, &emlrtJBStack);
        emlrtExitParallelRegion(aTLS, omp_in_parallel());
      }
    }
  }
}

/* End of code generation (compute_lambda.c) */
