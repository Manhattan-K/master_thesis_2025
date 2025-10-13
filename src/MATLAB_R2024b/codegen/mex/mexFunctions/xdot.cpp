//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xdot.cpp
//
// Code generation for function 'xdot'
//

// Include files
#include "xdot.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
real_T xdot(int32_T n, const real_T x_data[], int32_T ix0,
            const real_T y_data[], int32_T iy0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T d;
  if (n < 1) {
    d = 0.0;
  } else {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    d = ddot(&n_t, (real_T *)&x_data[ix0 - 1], &incx_t,
             (real_T *)&y_data[iy0 - 1], &incy_t);
  }
  return d;
}

real_T xdot(int32_T n, const array<real_T, 1U> &x, int32_T ix0,
            const real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  n_t = (ptrdiff_t)n;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  return ddot(&n_t, (real_T *)&x[ix0 - 1], &incx_t, (real_T *)&y_data[0],
              &incy_t);
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xdot.cpp)
