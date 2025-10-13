//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xcopy.cpp
//
// Code generation for function 'xcopy'
//

// Include files
#include "xcopy.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xcopy(int32_T n, const array<real_T, 2U> &x, int32_T ix0, real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  n_t = (ptrdiff_t)n;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dcopy(&n_t, (real_T *)&x[ix0 - 1], &incx_t, &y_data[0], &incy_t);
}

void xcopy(int32_T n, const array<real_T, 2U> &x, real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  n_t = (ptrdiff_t)n;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dcopy(&n_t, &(x.data())[0], &incx_t, &y_data[0], &incy_t);
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xcopy.cpp)
