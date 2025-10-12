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
#include "evaluateObstacles_mex_types.h"
#include "factor.h"
#include "fullColLDL2_.h"
#include "partialColLDL3_.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "xgemm.h"
#include "blas.h"
#include "lapacke.h"
#include <immintrin.h>
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void compute_deltax(const real_T H[1600], j_struct_T *solution,
                    e_struct_T *memspace, const f_struct_T *qrmanager,
                    n_struct_T *cholmanager, const d_struct_T *objective,
                    boolean_T alwaysPositiveDef)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  int32_T LDimSizeP1;
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T mNull_tmp;
  int32_T nVar;
  char_T TRANSA;
  char_T TRANSA1;
  char_T UPLO1;
  nVar = qrmanager->mrows - 1;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (mNull_tmp <= 0) {
    if (nVar >= 0) {
      memset(&solution->searchDir.data[0], 0,
             (uint32_T)(nVar + 1) * sizeof(real_T));
    }
  } else {
    __m256d r;
    int32_T LD_diagOffset;
    int32_T vectorUB;
    LD_diagOffset = ((nVar + 1) / 4) << 2;
    vectorUB = LD_diagOffset - 4;
    for (idx = 0; idx <= vectorUB; idx += 4) {
      r = _mm256_loadu_pd(&objective->grad.data[idx]);
      _mm256_storeu_pd(&solution->searchDir.data[idx],
                       _mm256_mul_pd(r, _mm256_set1_pd(-1.0)));
    }
    for (idx = LD_diagOffset; idx <= nVar; idx++) {
      solution->searchDir.data[idx] = -objective->grad.data[idx];
    }
    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
      case 5:
        break;
      case 3: {
        if (alwaysPositiveDef) {
          factor(cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        } else {
          vectorUB = qrmanager->mrows;
          LDimSizeP1 = cholmanager->ldm + 1;
          cholmanager->ndims = qrmanager->mrows;
          for (idx = 0; idx < vectorUB; idx++) {
            LD_diagOffset = qrmanager->mrows * idx;
            nVar = cholmanager->ldm * idx;
            for (k = 0; k < vectorUB; k++) {
              cholmanager->FMat->data[nVar + k] = H[LD_diagOffset + k];
            }
          }
          if ((cholmanager->FMat->size[0] * cholmanager->FMat->size[1] >
               16384) &&
              (qrmanager->mrows > 128)) {
            boolean_T exitg1;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < vectorUB)) {
              LD_diagOffset = LDimSizeP1 * k + 1;
              nVar = vectorUB - k;
              if (k + 48 <= vectorUB) {
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
            idx = 0;
            int32_T exitg2;
            do {
              exitg2 = 0;
              if (idx <= vectorUB - 1) {
                if (cholmanager->FMat->data[idx + cholmanager->ldm * idx] <=
                    0.0) {
                  cholmanager->info = -idx - 1;
                  exitg2 = 1;
                } else {
                  idx++;
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
          i = cholmanager->ndims;
          for (idx = 0; idx < i; idx++) {
            solution->searchDir.data[idx] /=
                cholmanager->FMat->data[idx + cholmanager->ldm * idx];
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
          factor(cholmanager, H, objective->nvar, objective->nvar);
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
      int32_T nullStartIdx_tmp;
      nullStartIdx_tmp = qrmanager->ldq * qrmanager->ncols;
      if (objective->objtype == 5) {
        for (idx = 0; idx < mNull_tmp; idx++) {
          memspace->workspace_float->data[idx] =
              -qrmanager->Q
                   ->data[nVar + qrmanager->ldq * (qrmanager->ncols + idx)];
        }
        if (qrmanager->mrows >= 1) {
          alpha1 = 1.0;
          beta1 = 0.0;
          TRANSA = 'N';
          m_t = (ptrdiff_t)qrmanager->mrows;
          n_t = (ptrdiff_t)mNull_tmp;
          lda_t = (ptrdiff_t)qrmanager->ldq;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dgemv(&TRANSA, &m_t, &n_t, &alpha1,
                &qrmanager->Q->data[nullStartIdx_tmp], &lda_t,
                &memspace->workspace_float->data[0], &incx_t, &beta1,
                &solution->searchDir.data[0], &incy_t);
        }
      } else {
        if (objective->objtype == 3) {
          c_xgemm(qrmanager->mrows, mNull_tmp, qrmanager->mrows, H,
                  qrmanager->mrows, qrmanager->Q, nullStartIdx_tmp + 1,
                  qrmanager->ldq, memspace->workspace_float,
                  memspace->workspace_float->size[0]);
          d_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp + 1, qrmanager->ldq,
                  memspace->workspace_float, memspace->workspace_float->size[0],
                  cholmanager->FMat, cholmanager->ldm);
        } else if (alwaysPositiveDef) {
          nVar = qrmanager->mrows;
          c_xgemm(objective->nvar, mNull_tmp, objective->nvar, H,
                  objective->nvar, qrmanager->Q, nullStartIdx_tmp + 1,
                  qrmanager->ldq, memspace->workspace_float,
                  memspace->workspace_float->size[0]);
          i = objective->nvar + 1;
          LD_diagOffset = ((((nVar - i) + 1) / 4) << 2) + i;
          vectorUB = LD_diagOffset - 4;
          for (LDimSizeP1 = 0; LDimSizeP1 < mNull_tmp; LDimSizeP1++) {
            for (k = i; k <= vectorUB; k += 4) {
              r = _mm256_loadu_pd(
                  &qrmanager->Q
                       ->data[(k + qrmanager->Q->size[0] *
                                       (LDimSizeP1 + qrmanager->ncols)) -
                              1]);
              _mm256_storeu_pd(
                  &memspace->workspace_float
                       ->data[(k + memspace->workspace_float->size[0] *
                                       LDimSizeP1) -
                              1],
                  _mm256_mul_pd(_mm256_set1_pd(objective->beta), r));
            }
            for (k = LD_diagOffset; k <= nVar; k++) {
              memspace->workspace_float
                  ->data[(k + memspace->workspace_float->size[0] * LDimSizeP1) -
                         1] =
                  objective->beta *
                  qrmanager->Q->data[(k + qrmanager->Q->size[0] *
                                              (LDimSizeP1 + qrmanager->ncols)) -
                                     1];
            }
          }
          d_xgemm(mNull_tmp, mNull_tmp, qrmanager->mrows, qrmanager->Q,
                  nullStartIdx_tmp + 1, qrmanager->ldq,
                  memspace->workspace_float, memspace->workspace_float->size[0],
                  cholmanager->FMat, cholmanager->ldm);
        }
        if (alwaysPositiveDef) {
          cholmanager->ndims = mNull_tmp;
          n_t = LAPACKE_dpotrf_work(102, 'U', (ptrdiff_t)mNull_tmp,
                                    &cholmanager->FMat->data[0],
                                    (ptrdiff_t)cholmanager->ldm);
          if ((int32_T)n_t < 0) {
            nVar = cholmanager->FMat->size[0];
            LD_diagOffset = cholmanager->FMat->size[1];
            nVar *= LD_diagOffset;
            for (i = 0; i < nVar; i++) {
              cholmanager->FMat->data[i] = rtNaN;
            }
          }
          cholmanager->info = (int32_T)n_t;
        } else {
          LDimSizeP1 = cholmanager->ldm + 1;
          cholmanager->ndims = mNull_tmp;
          if ((cholmanager->FMat->size[0] * cholmanager->FMat->size[1] >
               16384) &&
              (mNull_tmp > 128)) {
            boolean_T exitg1;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < mNull_tmp)) {
              LD_diagOffset = LDimSizeP1 * k + 1;
              nVar = mNull_tmp - k;
              if (k + 48 <= mNull_tmp) {
                partialColLDL3_(cholmanager, LD_diagOffset, nVar);
                k += 48;
              } else {
                fullColLDL2_(cholmanager, LD_diagOffset, nVar);
                exitg1 = true;
              }
            }
          } else {
            fullColLDL2_(cholmanager, 1, mNull_tmp);
          }
          if (cholmanager->ConvexCheck) {
            idx = 0;
            int32_T exitg2;
            do {
              exitg2 = 0;
              if (idx <= mNull_tmp - 1) {
                if (cholmanager->FMat->data[idx + cholmanager->ldm * idx] <=
                    0.0) {
                  cholmanager->info = -idx - 1;
                  exitg2 = 1;
                } else {
                  idx++;
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
            n_t = (ptrdiff_t)mNull_tmp;
            lda_t = (ptrdiff_t)qrmanager->ldq;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dgemv(&TRANSA, &m_t, &n_t, &alpha1,
                  &qrmanager->Q->data[nullStartIdx_tmp], &lda_t,
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
            i = cholmanager->ndims;
            for (idx = 0; idx < i; idx++) {
              memspace->workspace_float->data[idx] /=
                  cholmanager->FMat->data[idx + cholmanager->ldm * idx];
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
            n_t = (ptrdiff_t)mNull_tmp;
            lda_t = (ptrdiff_t)qrmanager->ldq;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dgemv(&TRANSA, &m_t, &n_t, &alpha1,
                  &qrmanager->Q->data[nullStartIdx_tmp], &lda_t,
                  &memspace->workspace_float->data[0], &incx_t, &beta1,
                  &solution->searchDir.data[0], &incy_t);
          }
        }
      }
    }
  }
}

/* End of code generation (compute_deltax.c) */
