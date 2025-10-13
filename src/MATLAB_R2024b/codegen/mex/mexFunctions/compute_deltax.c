/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compute_deltax.c
 *
 * Code generation for function 'compute_deltax'
 *
 */

/* Include files */
#include "compute_deltax.h"
#include "factor.h"
#include "fullColLDL2_.h"
#include "mexFunctions_types.h"
#include "partialColLDL3_.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "xgemm.h"
#include "blas.h"
#include "lapacke.h"
#include "omp.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void compute_deltax(emlrtCTX aTLS, const real_T H[1600], h_struct_T *solution,
                    f_struct_T *memspace, const g_struct_T *qrmanager,
                    m_struct_T *cholmanager, const e_struct_T *objective,
                    boolean_T alwaysPositiveDef)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  jmp_buf *volatile emlrtJBStack;
  real_T alpha1;
  real_T beta1;
  int32_T compute_deltax_numThreads;
  int32_T idx;
  int32_T idx_col;
  int32_T k;
  int32_T mNull;
  int32_T nVar;
  char_T TRANSA;
  char_T TRANSA1;
  char_T UPLO1;
  nVar = qrmanager->mrows - 1;
  mNull = qrmanager->mrows - qrmanager->ncols;
  if (mNull <= 0) {
    if (nVar >= 0) {
      memset(&solution->searchDir.data[0], 0,
             (uint32_T)(nVar + 1) * sizeof(real_T));
    }
  } else {
    __m256d r;
    int32_T LDimSizeP1;
    int32_T scalarLB;
    scalarLB = ((nVar + 1) / 4) << 2;
    LDimSizeP1 = scalarLB - 4;
    for (idx = 0; idx <= LDimSizeP1; idx += 4) {
      r = _mm256_loadu_pd(&objective->grad.data[idx]);
      _mm256_storeu_pd(&solution->searchDir.data[idx],
                       _mm256_mul_pd(r, _mm256_set1_pd(-1.0)));
    }
    if ((nVar - scalarLB) + 1 < 1200) {
      for (idx = scalarLB; idx <= nVar; idx++) {
        solution->searchDir.data[idx] = -objective->grad.data[idx];
      }
    } else {
      emlrtEnterParallelRegion(aTLS, omp_in_parallel());
      emlrtPushJmpBuf(aTLS, &emlrtJBStack);
      compute_deltax_numThreads = emlrtAllocRegionTLSs(
          aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(compute_deltax_numThreads)

      for (idx = scalarLB; idx <= nVar; idx++) {
        solution->searchDir.data[idx] = -objective->grad.data[idx];
      }
      emlrtPopJmpBuf(aTLS, &emlrtJBStack);
      emlrtExitParallelRegion(aTLS, omp_in_parallel());
    }
    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
      case 5:
        break;
      case 3: {
        int32_T LD_diagOffset;
        if (alwaysPositiveDef) {
          factor(aTLS, cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        } else {
          scalarLB = qrmanager->mrows;
          LDimSizeP1 = cholmanager->ldm + 1;
          cholmanager->ndims = qrmanager->mrows;
          for (idx_col = 0; idx_col < scalarLB; idx_col++) {
            LD_diagOffset = qrmanager->mrows * idx_col;
            nVar = cholmanager->ldm * idx_col;
            for (k = 0; k < scalarLB; k++) {
              cholmanager->FMat->data[nVar + k] = H[LD_diagOffset + k];
            }
          }
          if ((cholmanager->FMat->size[0] * cholmanager->FMat->size[1] >
               16384) &&
              (qrmanager->mrows > 128)) {
            boolean_T exitg1;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < scalarLB)) {
              LD_diagOffset = LDimSizeP1 * k + 1;
              nVar = scalarLB - k;
              if (k + 48 <= scalarLB) {
                partialColLDL3_(cholmanager, LD_diagOffset, nVar);
                k += 48;
              } else {
                fullColLDL2_(cholmanager, LD_diagOffset, nVar);
                exitg1 = true;
              }
            }
          } else {
            fullColLDL2_(cholmanager, 1, qrmanager->mrows);
          }
          if (cholmanager->ConvexCheck) {
            idx_col = 0;
            int32_T exitg2;
            do {
              exitg2 = 0;
              if (idx_col <= scalarLB - 1) {
                if (cholmanager->FMat
                        ->data[idx_col + cholmanager->ldm * idx_col] <= 0.0) {
                  cholmanager->info = -idx_col - 1;
                  exitg2 = 1;
                } else {
                  idx_col++;
                }
              } else {
                cholmanager->ConvexCheck = false;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }
        }
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else if (alwaysPositiveDef) {
          solve(cholmanager, solution->searchDir.data);
        } else {
          if (cholmanager->ndims >= 1) {
            TRANSA = 'U';
            TRANSA1 = 'N';
            UPLO1 = 'L';
            n_t = (ptrdiff_t)cholmanager->ndims;
            lda_t = (ptrdiff_t)cholmanager->ldm;
            incx_t = (ptrdiff_t)1;
            dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t, &cholmanager->FMat->data[0],
                  &lda_t, &solution->searchDir.data[0], &incx_t);
          }
          LD_diagOffset = cholmanager->ndims;
          if (LD_diagOffset < 1200) {
            for (idx = 0; idx < LD_diagOffset; idx++) {
              solution->searchDir.data[idx] /=
                  cholmanager->FMat->data[idx + cholmanager->ldm * idx];
            }
          } else {
            emlrtEnterParallelRegion(aTLS, omp_in_parallel());
            emlrtPushJmpBuf(aTLS, &emlrtJBStack);
            compute_deltax_numThreads = emlrtAllocRegionTLSs(
                aTLS, omp_in_parallel(), omp_get_max_threads(),
                omp_get_num_procs());
#pragma omp parallel for num_threads(compute_deltax_numThreads)

            for (idx = 0; idx < LD_diagOffset; idx++) {
              solution->searchDir.data[idx] /=
                  cholmanager->FMat->data[idx + cholmanager->ldm * idx];
            }
            emlrtPopJmpBuf(aTLS, &emlrtJBStack);
            emlrtExitParallelRegion(aTLS, omp_in_parallel());
          }
          if (cholmanager->ndims >= 1) {
            TRANSA = 'U';
            TRANSA1 = 'T';
            UPLO1 = 'L';
            n_t = (ptrdiff_t)cholmanager->ndims;
            lda_t = (ptrdiff_t)cholmanager->ldm;
            incx_t = (ptrdiff_t)1;
            dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t, &cholmanager->FMat->data[0],
                  &lda_t, &solution->searchDir.data[0], &incx_t);
          }
        }
      } break;
      case 4:
        if (alwaysPositiveDef) {
          factor(aTLS, cholmanager, H, objective->nvar, objective->nvar);
          if (cholmanager->info != 0) {
            solution->state = -6;
          } else {
            solve(cholmanager, solution->searchDir.data);
            nVar = qrmanager->mrows - objective->nvar;
            alpha1 = 1.0 / objective->beta;
            if (nVar >= 1) {
              n_t = (ptrdiff_t)nVar;
              incx_t = (ptrdiff_t)1;
              dscal(&n_t, &alpha1, &solution->searchDir.data[objective->nvar],
                    &incx_t);
            }
          }
        }
        break;
      }
    } else {
      int32_T nullStartIdx;
      nullStartIdx = qrmanager->ldq * qrmanager->ncols;
      if (objective->objtype == 5) {
        if (mNull < 1200) {
          for (idx = 0; idx < mNull; idx++) {
            memspace->workspace_float->data[idx] =
                -qrmanager->Q
                     ->data[nVar + qrmanager->ldq * (qrmanager->ncols + idx)];
          }
        } else {
          emlrtEnterParallelRegion(aTLS, omp_in_parallel());
          emlrtPushJmpBuf(aTLS, &emlrtJBStack);
          compute_deltax_numThreads =
              emlrtAllocRegionTLSs(aTLS, omp_in_parallel(),
                                   omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(compute_deltax_numThreads)

          for (idx = 0; idx < mNull; idx++) {
            memspace->workspace_float->data[idx] =
                -qrmanager->Q
                     ->data[nVar + qrmanager->ldq * (qrmanager->ncols + idx)];
          }
          emlrtPopJmpBuf(aTLS, &emlrtJBStack);
          emlrtExitParallelRegion(aTLS, omp_in_parallel());
        }
        if (qrmanager->mrows >= 1) {
          alpha1 = 1.0;
          beta1 = 0.0;
          TRANSA = 'N';
          m_t = (ptrdiff_t)qrmanager->mrows;
          n_t = (ptrdiff_t)mNull;
          lda_t = (ptrdiff_t)qrmanager->ldq;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dgemv(&TRANSA, &m_t, &n_t, &alpha1, &qrmanager->Q->data[nullStartIdx],
                &lda_t, &memspace->workspace_float->data[0], &incx_t, &beta1,
                &solution->searchDir.data[0], &incy_t);
        }
      } else {
        int32_T LD_diagOffset;
        if (objective->objtype == 3) {
          c_xgemm(qrmanager->mrows, mNull, qrmanager->mrows, H,
                  qrmanager->mrows, qrmanager->Q, nullStartIdx + 1,
                  qrmanager->ldq, memspace->workspace_float,
                  memspace->workspace_float->size[0]);
          d_xgemm(mNull, mNull, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx + 1, qrmanager->ldq, memspace->workspace_float,
                  memspace->workspace_float->size[0], cholmanager->FMat,
                  cholmanager->ldm);
        } else if (alwaysPositiveDef) {
          nVar = qrmanager->mrows;
          c_xgemm(objective->nvar, mNull, objective->nvar, H, objective->nvar,
                  qrmanager->Q, nullStartIdx + 1, qrmanager->ldq,
                  memspace->workspace_float,
                  memspace->workspace_float->size[0]);
          LD_diagOffset = objective->nvar + 1;
          scalarLB = ((((nVar - LD_diagOffset) + 1) / 4) << 2) + LD_diagOffset;
          LDimSizeP1 = scalarLB - 4;
          for (idx_col = 0; idx_col < mNull; idx_col++) {
            for (k = LD_diagOffset; k <= LDimSizeP1; k += 4) {
              r = _mm256_loadu_pd(
                  &qrmanager->Q->data[(k + qrmanager->Q->size[0] *
                                               (idx_col + qrmanager->ncols)) -
                                      1]);
              _mm256_storeu_pd(
                  &memspace->workspace_float->data
                       [(k + memspace->workspace_float->size[0] * idx_col) - 1],
                  _mm256_mul_pd(_mm256_set1_pd(objective->beta), r));
            }
            for (k = scalarLB; k <= nVar; k++) {
              memspace->workspace_float
                  ->data[(k + memspace->workspace_float->size[0] * idx_col) -
                         1] =
                  objective->beta *
                  qrmanager->Q->data[(k + qrmanager->Q->size[0] *
                                              (idx_col + qrmanager->ncols)) -
                                     1];
            }
          }
          d_xgemm(mNull, mNull, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx + 1, qrmanager->ldq, memspace->workspace_float,
                  memspace->workspace_float->size[0], cholmanager->FMat,
                  cholmanager->ldm);
        }
        if (alwaysPositiveDef) {
          cholmanager->ndims = mNull;
          n_t = LAPACKE_dpotrf_work(102, 'U', (ptrdiff_t)mNull,
                                    &cholmanager->FMat->data[0],
                                    (ptrdiff_t)cholmanager->ldm);
          scalarLB = (int32_T)n_t;
          if ((int32_T)n_t < 0) {
            nVar = cholmanager->FMat->size[0];
            LD_diagOffset = cholmanager->FMat->size[1];
            nVar *= LD_diagOffset;
            if (nVar < 1200) {
              for (idx = 0; idx < nVar; idx++) {
                cholmanager->FMat->data[idx] = rtNaN;
              }
            } else {
              emlrtEnterParallelRegion(aTLS, omp_in_parallel());
              emlrtPushJmpBuf(aTLS, &emlrtJBStack);
              compute_deltax_numThreads = emlrtAllocRegionTLSs(
                  aTLS, omp_in_parallel(), omp_get_max_threads(),
                  omp_get_num_procs());
#pragma omp parallel for num_threads(compute_deltax_numThreads)

              for (idx = 0; idx < nVar; idx++) {
                cholmanager->FMat->data[idx] = rtNaN;
              }
              emlrtPopJmpBuf(aTLS, &emlrtJBStack);
              emlrtExitParallelRegion(aTLS, omp_in_parallel());
            }
          }
          cholmanager->info = scalarLB;
        } else {
          LDimSizeP1 = cholmanager->ldm + 1;
          cholmanager->ndims = mNull;
          if ((cholmanager->FMat->size[0] * cholmanager->FMat->size[1] >
               16384) &&
              (mNull > 128)) {
            boolean_T exitg1;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < mNull)) {
              LD_diagOffset = LDimSizeP1 * k + 1;
              nVar = mNull - k;
              if (k + 48 <= mNull) {
                partialColLDL3_(cholmanager, LD_diagOffset, nVar);
                k += 48;
              } else {
                fullColLDL2_(cholmanager, LD_diagOffset, nVar);
                exitg1 = true;
              }
            }
          } else {
            fullColLDL2_(cholmanager, 1, mNull);
          }
          if (cholmanager->ConvexCheck) {
            idx_col = 0;
            int32_T exitg2;
            do {
              exitg2 = 0;
              if (idx_col <= mNull - 1) {
                if (cholmanager->FMat
                        ->data[idx_col + cholmanager->ldm * idx_col] <= 0.0) {
                  cholmanager->info = -idx_col - 1;
                  exitg2 = 1;
                } else {
                  idx_col++;
                }
              } else {
                cholmanager->ConvexCheck = false;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }
        }
        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          if (qrmanager->mrows >= 1) {
            alpha1 = -1.0;
            beta1 = 0.0;
            TRANSA = 'T';
            m_t = (ptrdiff_t)qrmanager->mrows;
            n_t = (ptrdiff_t)mNull;
            lda_t = (ptrdiff_t)qrmanager->ldq;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dgemv(&TRANSA, &m_t, &n_t, &alpha1,
                  &qrmanager->Q->data[nullStartIdx], &lda_t,
                  (real_T *)&objective->grad.data[0], &incx_t, &beta1,
                  &memspace->workspace_float->data[0], &incy_t);
          }
          if (alwaysPositiveDef) {
            if (cholmanager->ndims >= 1) {
              TRANSA = 'N';
              TRANSA1 = 'T';
              UPLO1 = 'U';
              n_t = (ptrdiff_t)cholmanager->ndims;
              lda_t = (ptrdiff_t)cholmanager->ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &cholmanager->FMat->data[0], &lda_t,
                    &memspace->workspace_float->data[0], &incx_t);
            }
            if (cholmanager->ndims >= 1) {
              TRANSA = 'N';
              TRANSA1 = 'N';
              UPLO1 = 'U';
              n_t = (ptrdiff_t)cholmanager->ndims;
              lda_t = (ptrdiff_t)cholmanager->ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &cholmanager->FMat->data[0], &lda_t,
                    &memspace->workspace_float->data[0], &incx_t);
            }
          } else {
            if (cholmanager->ndims >= 1) {
              TRANSA = 'U';
              TRANSA1 = 'N';
              UPLO1 = 'L';
              n_t = (ptrdiff_t)cholmanager->ndims;
              lda_t = (ptrdiff_t)cholmanager->ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &cholmanager->FMat->data[0], &lda_t,
                    &memspace->workspace_float->data[0], &incx_t);
            }
            LD_diagOffset = cholmanager->ndims;
            if (LD_diagOffset < 1200) {
              for (idx = 0; idx < LD_diagOffset; idx++) {
                memspace->workspace_float->data[idx] /=
                    cholmanager->FMat->data[idx + cholmanager->ldm * idx];
              }
            } else {
              emlrtEnterParallelRegion(aTLS, omp_in_parallel());
              emlrtPushJmpBuf(aTLS, &emlrtJBStack);
              compute_deltax_numThreads = emlrtAllocRegionTLSs(
                  aTLS, omp_in_parallel(), omp_get_max_threads(),
                  omp_get_num_procs());
#pragma omp parallel for num_threads(compute_deltax_numThreads)

              for (idx = 0; idx < LD_diagOffset; idx++) {
                memspace->workspace_float->data[idx] /=
                    cholmanager->FMat->data[idx + cholmanager->ldm * idx];
              }
              emlrtPopJmpBuf(aTLS, &emlrtJBStack);
              emlrtExitParallelRegion(aTLS, omp_in_parallel());
            }
            if (cholmanager->ndims >= 1) {
              TRANSA = 'U';
              TRANSA1 = 'T';
              UPLO1 = 'L';
              n_t = (ptrdiff_t)cholmanager->ndims;
              lda_t = (ptrdiff_t)cholmanager->ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &cholmanager->FMat->data[0], &lda_t,
                    &memspace->workspace_float->data[0], &incx_t);
            }
          }
          if (qrmanager->mrows >= 1) {
            alpha1 = 1.0;
            beta1 = 0.0;
            TRANSA = 'N';
            m_t = (ptrdiff_t)qrmanager->mrows;
            n_t = (ptrdiff_t)mNull;
            lda_t = (ptrdiff_t)qrmanager->ldq;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dgemv(&TRANSA, &m_t, &n_t, &alpha1,
                  &qrmanager->Q->data[nullStartIdx], &lda_t,
                  &memspace->workspace_float->data[0], &incx_t, &beta1,
                  &solution->searchDir.data[0], &incy_t);
          }
        }
      }
    }
  }
}

/* End of code generation (compute_deltax.c) */
