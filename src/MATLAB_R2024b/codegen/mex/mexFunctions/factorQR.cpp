//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factorQR.cpp
//
// Code generation for function 'factorQR'
//

// Include files
#include "factorQR.h"
#include "mexFunctions_data.h"
#include "mexFunctions_internal_types.h"
#include "rt_nonfinite.h"
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
namespace QRManager {
void factorQR(d_struct_T &obj, const array<real_T, 1U> &A, int32_T mrows,
              int32_T ncols, int32_T ldA)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> tau;
  int32_T i;
  int32_T minmn;
  boolean_T guard1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  i = mrows * ncols;
  guard1 = false;
  if (i > 0) {
    for (minmn = 0; minmn < ncols; minmn++) {
      n_t = (ptrdiff_t)mrows;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, (real_T *)&A[ldA * minmn], &incx_t, &obj.QR[obj.ldq * minmn],
            &incy_t);
    }
    guard1 = true;
  } else if (i == 0) {
    obj.mrows = mrows;
    obj.ncols = ncols;
    obj.minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    int32_T minmana;
    int16_T y_size_idx_0;
    obj.usedPivoting = false;
    obj.mrows = mrows;
    obj.ncols = ncols;
    for (minmn = 0; minmn < ncols; minmn++) {
      obj.jpvt.data[minmn] = minmn + 1;
    }
    int16_T y_size_idx_1;
    i = muIntScalarMin_sint32(mrows, ncols);
    obj.minRowCol = i;
    y_size_idx_0 = static_cast<int16_T>(obj.QR.size(0));
    y_size_idx_1 = static_cast<int16_T>(obj.QR.size(1));
    minmana = muIntScalarMin_sint32(static_cast<int32_T>(y_size_idx_0),
                                    static_cast<int32_T>(y_size_idx_1));
    tau.set_size(minmana);
    if (ncols == 0) {
      tau.set_size(minmana);
      for (i = 0; i < minmana; i++) {
        tau[i] = 0.0;
      }
    } else {
      n_t = LAPACKE_dgeqrf(102, (ptrdiff_t)mrows, (ptrdiff_t)ncols,
                           &(obj.QR.data())[0], (ptrdiff_t)y_size_idx_0,
                           &(tau.data())[0]);
      if ((int32_T)n_t != 0) {
        for (int32_T j{0}; j < ncols; j++) {
          minmn = static_cast<uint16_T>(mrows);
          for (int32_T b_i{0}; b_i < minmn; b_i++) {
            obj.QR[j * y_size_idx_0 + b_i] = rtNaN;
          }
        }
        minmn = i - 1;
        for (int32_T b_i{0}; b_i <= minmn; b_i++) {
          tau[b_i] = rtNaN;
        }
        i++;
        for (int32_T b_i{i}; b_i <= minmana; b_i++) {
          tau[b_i - 1] = 0.0;
        }
      }
    }
    minmn = tau.size(0);
    obj.tau.set_size(tau.size(0));
    for (i = 0; i < minmn; i++) {
      obj.tau[i] = tau[i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factorQR.cpp)
