//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factorQRE.cpp
//
// Code generation for function 'factorQRE'
//

// Include files
#include "factorQRE.h"
#include "mexFunctions_internal_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
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
namespace QRManager {
void factorQRE(d_struct_T &obj, const array<real_T, 1U> &A, int32_T mrows,
               int32_T ncols, int32_T ldA)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  int32_T idx;
  boolean_T guard1;
  idx = mrows * ncols;
  guard1 = false;
  if (idx > 0) {
    for (idx = 0; idx < ncols; idx++) {
      n_t = (ptrdiff_t)mrows;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, (real_T *)&A[ldA * idx], &incx_t, &obj.QR[obj.ldq * idx],
            &incy_t);
    }
    guard1 = true;
  } else if (idx == 0) {
    obj.mrows = mrows;
    obj.ncols = ncols;
    obj.minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    obj.usedPivoting = true;
    obj.mrows = mrows;
    obj.ncols = ncols;
    obj.minRowCol = muIntScalarMin_sint32(mrows, ncols);
    internal::lapack::xgeqp3(obj.QR, mrows, ncols, obj.jpvt.data,
                             obj.jpvt.size[0], obj.tau);
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factorQRE.cpp)
