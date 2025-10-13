//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xaxpy.cpp
//
// Code generation for function 'xaxpy'
//

// Include files
#include "xaxpy.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xaxpy(int32_T n, real_T a, const real_T x_data[], real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  if (n >= 1) {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    daxpy(&n_t, &a, (real_T *)&x_data[0], &incx_t, &y_data[0], &incy_t);
  }
}

void xaxpy(int32_T n, const real_T x_data[], array<real_T, 2U> &y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T a;
  a = 1.0;
  n_t = (ptrdiff_t)n;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  daxpy(&n_t, &a, (real_T *)&x_data[0], &incx_t, &(y.data())[0], &incy_t);
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xaxpy.cpp)
