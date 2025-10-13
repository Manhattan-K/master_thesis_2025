//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xasum.cpp
//
// Code generation for function 'xasum'
//

// Include files
#include "xasum.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
real_T xasum(int32_T n, const real_T x_data[], int32_T ix0)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  real_T y;
  if (n < 1) {
    y = 0.0;
  } else {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    y = dasum(&n_t, (real_T *)&x_data[ix0 - 1], &incx_t);
  }
  return y;
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xasum.cpp)
