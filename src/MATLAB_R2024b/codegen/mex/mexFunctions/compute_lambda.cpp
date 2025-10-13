//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// compute_lambda.cpp
//
// Code generation for function 'compute_lambda'
//

// Include files
#include "compute_lambda.h"
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
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
namespace qpactiveset {
void compute_lambda(array<real_T, 2U> &workspace, f_struct_T &solution,
                    const b_struct_T &objective, const d_struct_T &qrmanager)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T beta1;
  real_T tol;
  int32_T nActiveConstr_tmp;
  char_T TRANSA;
  char_T TRANSA1;
  char_T UPLO1;
  nActiveConstr_tmp = qrmanager.ncols;
  if (qrmanager.ncols > 0) {
    int32_T idx;
    boolean_T guard1;
    guard1 = false;
    if (objective.objtype != 4) {
      boolean_T nonDegenerate;
      tol = muDoubleScalarMin(1.4901161193847656E-8,
                              2.2204460492503131E-15 *
                                  static_cast<real_T>(muIntScalarMax_sint32(
                                      qrmanager.mrows, qrmanager.ncols)));
      if ((qrmanager.mrows > 0) && (qrmanager.ncols > 0)) {
        nonDegenerate = true;
      } else {
        nonDegenerate = false;
      }
      if (nonDegenerate) {
        int32_T idxQR;
        boolean_T guard2;
        idx = nActiveConstr_tmp;
        guard2 = false;
        if (qrmanager.mrows < qrmanager.ncols) {
          idxQR = qrmanager.mrows + qrmanager.ldq * (qrmanager.ncols - 1);
          while ((idx > qrmanager.mrows) &&
                 (muDoubleScalarAbs(qrmanager.QR[idxQR - 1]) >= tol)) {
            idx--;
            idxQR -= qrmanager.ldq;
          }
          nonDegenerate = (idx == qrmanager.mrows);
          if (nonDegenerate) {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }
        if (guard2) {
          idxQR = idx + qrmanager.ldq * (idx - 1);
          while ((idx >= 1) &&
                 (muDoubleScalarAbs(qrmanager.QR[idxQR - 1]) >= tol)) {
            idx--;
            idxQR = (idxQR - qrmanager.ldq) - 1;
          }
          nonDegenerate = (idx == 0);
        }
      }
      if (!nonDegenerate) {
        solution.state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      if (qrmanager.mrows >= 1) {
        tol = 1.0;
        beta1 = 0.0;
        TRANSA = 'T';
        m_t = (ptrdiff_t)qrmanager.mrows;
        n_t = (ptrdiff_t)qrmanager.ncols;
        lda_t = (ptrdiff_t)qrmanager.ldq;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dgemv(&TRANSA, &m_t, &n_t, &tol, &(qrmanager.Q.data())[0], &lda_t,
              (real_T *)&objective.grad.data[0], &incx_t, &beta1,
              &(workspace.data())[0], &incy_t);
      }
      TRANSA = 'N';
      TRANSA1 = 'N';
      UPLO1 = 'U';
      n_t = (ptrdiff_t)qrmanager.ncols;
      lda_t = (ptrdiff_t)qrmanager.ldq;
      incx_t = (ptrdiff_t)1;
      dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t, &(qrmanager.QR.data())[0], &lda_t,
            &(workspace.data())[0], &incx_t);
      for (idx = 0; idx < nActiveConstr_tmp; idx++) {
        solution.lambda[idx] = -workspace[idx];
      }
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (compute_lambda.cpp)
