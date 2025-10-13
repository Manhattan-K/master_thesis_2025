//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// compute_deltax.cpp
//
// Code generation for function 'compute_deltax'
//

// Include files
#include "compute_deltax.h"
#include "factor.h"
#include "fullColLDL2_.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "partialColLDL3_.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "xgemm.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_deltax(const real_T H[1600], f_struct_T &solution,
                    c_struct_T &memspace, const d_struct_T &qrmanager,
                    e_struct_T &cholmanager, const b_struct_T &objective,
                    boolean_T alwaysPositiveDef)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  int32_T mNull_tmp;
  int32_T nVar;
  char_T TRANSA;
  char_T TRANSA1;
  char_T UPLO1;
  nVar = qrmanager.mrows - 1;
  mNull_tmp = qrmanager.mrows - qrmanager.ncols;
  if (mNull_tmp <= 0) {
    if (nVar >= 0) {
      std::memset(&solution.searchDir.data[0], 0,
                  static_cast<uint32_T>(nVar + 1) * sizeof(real_T));
    }
  } else {
    int32_T idx;
    for (idx = 0; idx <= nVar; idx++) {
      solution.searchDir.data[idx] = -objective.grad.data[idx];
    }
    if (qrmanager.ncols <= 0) {
      switch (objective.objtype) {
      case 5:
        break;
      case 3: {
        int32_T LDimSizeP1;
        if (alwaysPositiveDef) {
          CholManager::factor(cholmanager, H, qrmanager.mrows, qrmanager.mrows);
        } else {
          int32_T idx_row;
          int32_T k;
          int32_T order;
          idx_row = qrmanager.mrows;
          LDimSizeP1 = cholmanager.ldm + 1;
          cholmanager.ndims = qrmanager.mrows;
          for (idx = 0; idx < idx_row; idx++) {
            nVar = qrmanager.mrows * idx;
            order = cholmanager.ldm * idx;
            for (k = 0; k < idx_row; k++) {
              cholmanager.FMat[order + k] = H[nVar + k];
            }
          }
          if (qrmanager.mrows < 1) {
            nVar = -1;
          } else {
            n_t = (ptrdiff_t)qrmanager.mrows;
            incx_t = (ptrdiff_t)(cholmanager.ldm + 1);
            n_t = idamax(&n_t, &(cholmanager.FMat.data())[0], &incx_t);
            nVar = (int32_T)n_t - 1;
          }
          cholmanager.regTol_ = muDoubleScalarMax(
              muDoubleScalarAbs(
                  cholmanager.FMat[nVar + cholmanager.ldm * nVar]) *
                  2.2204460492503131E-16,
              0.0);
          if ((cholmanager.FMat.size(0) * cholmanager.FMat.size(1) > 16384) &&
              (qrmanager.mrows > 128)) {
            boolean_T exitg1;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < idx_row)) {
              nVar = LDimSizeP1 * k + 1;
              order = idx_row - k;
              if (k + 48 <= idx_row) {
                DynamicRegCholManager::partialColLDL3_(cholmanager, nVar,
                                                       order);
                k += 48;
              } else {
                DynamicRegCholManager::fullColLDL2_(cholmanager, nVar, order);
                exitg1 = true;
              }
            }
          } else {
            DynamicRegCholManager::fullColLDL2_(cholmanager, 1,
                                                qrmanager.mrows);
          }
          if (cholmanager.ConvexCheck) {
            idx = 0;
            int32_T exitg2;
            do {
              exitg2 = 0;
              if (idx <= idx_row - 1) {
                if (cholmanager.FMat[idx + cholmanager.ldm * idx] <= 0.0) {
                  cholmanager.info = -idx - 1;
                  exitg2 = 1;
                } else {
                  idx++;
                }
              } else {
                cholmanager.ConvexCheck = false;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }
        }
        if (cholmanager.info != 0) {
          solution.state = -6;
        } else if (alwaysPositiveDef) {
          CholManager::solve(cholmanager, solution.searchDir.data);
        } else {
          if (cholmanager.ndims >= 1) {
            TRANSA = 'U';
            TRANSA1 = 'N';
            UPLO1 = 'L';
            n_t = (ptrdiff_t)cholmanager.ndims;
            lda_t = (ptrdiff_t)cholmanager.ldm;
            incx_t = (ptrdiff_t)1;
            dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                  &(cholmanager.FMat.data())[0], &lda_t,
                  &solution.searchDir.data[0], &incx_t);
          }
          LDimSizeP1 = cholmanager.ndims;
          for (idx = 0; idx < LDimSizeP1; idx++) {
            solution.searchDir.data[idx] /=
                cholmanager.FMat[idx + cholmanager.ldm * idx];
          }
          if (cholmanager.ndims >= 1) {
            TRANSA = 'U';
            TRANSA1 = 'T';
            UPLO1 = 'L';
            n_t = (ptrdiff_t)cholmanager.ndims;
            lda_t = (ptrdiff_t)cholmanager.ldm;
            incx_t = (ptrdiff_t)1;
            dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                  &(cholmanager.FMat.data())[0], &lda_t,
                  &solution.searchDir.data[0], &incx_t);
          }
        }
      } break;
      case 4:
        if (alwaysPositiveDef) {
          CholManager::factor(cholmanager, H, objective.nvar, objective.nvar);
          if (cholmanager.info != 0) {
            solution.state = -6;
          } else {
            CholManager::solve(cholmanager, solution.searchDir.data);
            nVar = qrmanager.mrows - objective.nvar;
            alpha1 = 1.0 / objective.beta;
            if (nVar >= 1) {
              n_t = (ptrdiff_t)nVar;
              incx_t = (ptrdiff_t)1;
              dscal(&n_t, &alpha1, &solution.searchDir.data[objective.nvar],
                    &incx_t);
            }
          }
        }
        break;
      }
    } else {
      int32_T nullStartIdx_tmp;
      nullStartIdx_tmp = qrmanager.ldq * qrmanager.ncols;
      if (objective.objtype == 5) {
        for (idx = 0; idx < mNull_tmp; idx++) {
          memspace.workspace_float[idx] =
              -qrmanager.Q[nVar + qrmanager.ldq * (qrmanager.ncols + idx)];
        }
        if (qrmanager.mrows >= 1) {
          alpha1 = 1.0;
          beta1 = 0.0;
          TRANSA = 'N';
          m_t = (ptrdiff_t)qrmanager.mrows;
          n_t = (ptrdiff_t)mNull_tmp;
          lda_t = (ptrdiff_t)qrmanager.ldq;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dgemv(&TRANSA, &m_t, &n_t, &alpha1,
                (real_T *)&qrmanager.Q[nullStartIdx_tmp], &lda_t,
                &(memspace.workspace_float.data())[0], &incx_t, &beta1,
                &solution.searchDir.data[0], &incy_t);
        }
      } else {
        int32_T LDimSizeP1;
        int32_T order;
        if (objective.objtype == 3) {
          internal::blas::xgemm(
              qrmanager.mrows, mNull_tmp, qrmanager.mrows, H, qrmanager.mrows,
              qrmanager.Q, nullStartIdx_tmp + 1, qrmanager.ldq,
              memspace.workspace_float, memspace.workspace_float.size(0));
          internal::blas::xgemm(mNull_tmp, mNull_tmp, qrmanager.mrows,
                                qrmanager.Q, nullStartIdx_tmp + 1,
                                qrmanager.ldq, memspace.workspace_float,
                                memspace.workspace_float.size(0),
                                cholmanager.FMat, cholmanager.ldm);
        } else if (alwaysPositiveDef) {
          nVar = qrmanager.mrows;
          internal::blas::xgemm(
              objective.nvar, mNull_tmp, objective.nvar, H, objective.nvar,
              qrmanager.Q, nullStartIdx_tmp + 1, qrmanager.ldq,
              memspace.workspace_float, memspace.workspace_float.size(0));
          LDimSizeP1 = objective.nvar + 1;
          for (order = 0; order < mNull_tmp; order++) {
            for (int32_T idx_row{LDimSizeP1}; idx_row <= nVar; idx_row++) {
              memspace.workspace_float
                  [(idx_row + memspace.workspace_float.size(0) * order) - 1] =
                  objective.beta *
                  qrmanager.Q[(idx_row + qrmanager.Q.size(0) *
                                             (order + qrmanager.ncols)) -
                              1];
            }
          }
          internal::blas::xgemm(mNull_tmp, mNull_tmp, qrmanager.mrows,
                                qrmanager.Q, nullStartIdx_tmp + 1,
                                qrmanager.ldq, memspace.workspace_float,
                                memspace.workspace_float.size(0),
                                cholmanager.FMat, cholmanager.ldm);
        }
        if (alwaysPositiveDef) {
          cholmanager.ndims = mNull_tmp;
          n_t = LAPACKE_dpotrf_work(102, 'U', (ptrdiff_t)mNull_tmp,
                                    &(cholmanager.FMat.data())[0],
                                    (ptrdiff_t)cholmanager.ldm);
          if ((int32_T)n_t < 0) {
            nVar = cholmanager.FMat.size(0);
            order = cholmanager.FMat.size(1);
            nVar *= order;
            for (LDimSizeP1 = 0; LDimSizeP1 < nVar; LDimSizeP1++) {
              cholmanager.FMat[LDimSizeP1] = rtNaN;
            }
          }
          cholmanager.info = (int32_T)n_t;
        } else {
          LDimSizeP1 = cholmanager.ldm + 1;
          cholmanager.ndims = mNull_tmp;
          n_t = (ptrdiff_t)mNull_tmp;
          incx_t = (ptrdiff_t)(cholmanager.ldm + 1);
          n_t = idamax(&n_t, &(cholmanager.FMat.data())[0], &incx_t);
          cholmanager.regTol_ = muDoubleScalarMax(
              muDoubleScalarAbs(
                  cholmanager.FMat[((int32_T)n_t +
                                    cholmanager.ldm * ((int32_T)n_t - 1)) -
                                   1]) *
                  2.2204460492503131E-16,
              0.0);
          if ((cholmanager.FMat.size(0) * cholmanager.FMat.size(1) > 16384) &&
              (mNull_tmp > 128)) {
            int32_T k;
            boolean_T exitg1;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < mNull_tmp)) {
              nVar = LDimSizeP1 * k + 1;
              order = mNull_tmp - k;
              if (k + 48 <= mNull_tmp) {
                DynamicRegCholManager::partialColLDL3_(cholmanager, nVar,
                                                       order);
                k += 48;
              } else {
                DynamicRegCholManager::fullColLDL2_(cholmanager, nVar, order);
                exitg1 = true;
              }
            }
          } else {
            DynamicRegCholManager::fullColLDL2_(cholmanager, 1, mNull_tmp);
          }
          if (cholmanager.ConvexCheck) {
            idx = 0;
            int32_T exitg2;
            do {
              exitg2 = 0;
              if (idx <= mNull_tmp - 1) {
                if (cholmanager.FMat[idx + cholmanager.ldm * idx] <= 0.0) {
                  cholmanager.info = -idx - 1;
                  exitg2 = 1;
                } else {
                  idx++;
                }
              } else {
                cholmanager.ConvexCheck = false;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }
        }
        if (cholmanager.info != 0) {
          solution.state = -6;
        } else {
          if (qrmanager.mrows >= 1) {
            alpha1 = -1.0;
            beta1 = 0.0;
            TRANSA = 'T';
            m_t = (ptrdiff_t)qrmanager.mrows;
            n_t = (ptrdiff_t)mNull_tmp;
            lda_t = (ptrdiff_t)qrmanager.ldq;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dgemv(&TRANSA, &m_t, &n_t, &alpha1,
                  (real_T *)&qrmanager.Q[nullStartIdx_tmp], &lda_t,
                  (real_T *)&objective.grad.data[0], &incx_t, &beta1,
                  &(memspace.workspace_float.data())[0], &incy_t);
          }
          if (alwaysPositiveDef) {
            if (cholmanager.ndims >= 1) {
              TRANSA = 'N';
              TRANSA1 = 'T';
              UPLO1 = 'U';
              n_t = (ptrdiff_t)cholmanager.ndims;
              lda_t = (ptrdiff_t)cholmanager.ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &(cholmanager.FMat.data())[0], &lda_t,
                    &(memspace.workspace_float.data())[0], &incx_t);
            }
            if (cholmanager.ndims >= 1) {
              TRANSA = 'N';
              TRANSA1 = 'N';
              UPLO1 = 'U';
              n_t = (ptrdiff_t)cholmanager.ndims;
              lda_t = (ptrdiff_t)cholmanager.ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &(cholmanager.FMat.data())[0], &lda_t,
                    &(memspace.workspace_float.data())[0], &incx_t);
            }
          } else {
            if (cholmanager.ndims >= 1) {
              TRANSA = 'U';
              TRANSA1 = 'N';
              UPLO1 = 'L';
              n_t = (ptrdiff_t)cholmanager.ndims;
              lda_t = (ptrdiff_t)cholmanager.ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &(cholmanager.FMat.data())[0], &lda_t,
                    &(memspace.workspace_float.data())[0], &incx_t);
            }
            LDimSizeP1 = cholmanager.ndims;
            for (idx = 0; idx < LDimSizeP1; idx++) {
              memspace.workspace_float[idx] =
                  memspace.workspace_float[idx] /
                  cholmanager.FMat[idx + cholmanager.ldm * idx];
            }
            if (cholmanager.ndims >= 1) {
              TRANSA = 'U';
              TRANSA1 = 'T';
              UPLO1 = 'L';
              n_t = (ptrdiff_t)cholmanager.ndims;
              lda_t = (ptrdiff_t)cholmanager.ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &(cholmanager.FMat.data())[0], &lda_t,
                    &(memspace.workspace_float.data())[0], &incx_t);
            }
          }
          if (qrmanager.mrows >= 1) {
            alpha1 = 1.0;
            beta1 = 0.0;
            TRANSA = 'N';
            m_t = (ptrdiff_t)qrmanager.mrows;
            n_t = (ptrdiff_t)mNull_tmp;
            lda_t = (ptrdiff_t)qrmanager.ldq;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dgemv(&TRANSA, &m_t, &n_t, &alpha1,
                  (real_T *)&qrmanager.Q[nullStartIdx_tmp], &lda_t,
                  &(memspace.workspace_float.data())[0], &incx_t, &beta1,
                  &solution.searchDir.data[0], &incy_t);
          }
        }
      }
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (compute_deltax.cpp)
