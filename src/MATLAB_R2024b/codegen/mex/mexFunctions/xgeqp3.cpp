//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgeqp3.cpp
//
// Code generation for function 'xgeqp3'
//

// Include files
#include "xgeqp3.h"
#include "mexFunctions_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
void xgeqp3(array<real_T, 2U> &A, int32_T m, int32_T n, int32_T jpvt_data[],
            const int32_T &jpvt_size, array<real_T, 1U> &tau)
{
  array<ptrdiff_t, 1U> jpvt_t;
  int32_T ma;
  int32_T minmana;
  int32_T na;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  ma = A.size(0);
  na = A.size(1);
  minmana = muIntScalarMin_sint32(ma, na);
  tau.set_size(minmana);
  if (n < 1) {
    tau.set_size(minmana);
    for (int32_T i{0}; i < minmana; i++) {
      tau[i] = 0.0;
    }
    for (ma = 0; ma < n; ma++) {
      jpvt_data[ma] = ma + 1;
    }
  } else {
    ptrdiff_t info_t;
    int32_T i;
    na = jpvt_size;
    jpvt_t.set_size(na);
    for (i = 0; i < na; i++) {
      jpvt_t[i] = (ptrdiff_t)jpvt_data[i];
    }
    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)m, (ptrdiff_t)n, &(A.data())[0],
                            (ptrdiff_t)A.size(0), &(jpvt_t.data())[0],
                            &(tau.data())[0]);
    if ((int32_T)info_t != 0) {
      for (na = 0; na < n; na++) {
        for (i = 0; i < m; i++) {
          A[na * ma + i] = rtNaN;
        }
      }
      na = muIntScalarMin_sint32(m, n) - 1;
      for (ma = 0; ma <= na; ma++) {
        tau[ma] = rtNaN;
      }
      i = na + 2;
      for (ma = i; ma <= minmana; ma++) {
        tau[ma - 1] = 0.0;
      }
      for (ma = 0; ma < n; ma++) {
        jpvt_data[ma] = ma + 1;
      }
    } else {
      for (ma = 0; ma < n; ma++) {
        jpvt_data[ma] = (int32_T)jpvt_t[ma];
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xgeqp3.cpp)
