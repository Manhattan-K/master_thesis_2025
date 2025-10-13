//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgemv.cpp
//
// Code generation for function 'xgemv'
//

// Include files
#include "xgemv.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xgemv(int32_T m, int32_T n, const array<real_T, 1U> &A, int32_T lda,
           const real_T x_data[], array<real_T, 2U> &y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  alpha1 = -1.0;
  beta1 = 1.0;
  TRANSA = 'T';
  m_t = (ptrdiff_t)m;
  n_t = (ptrdiff_t)n;
  lda_t = (ptrdiff_t)lda;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(A.data())[0], &lda_t,
        (real_T *)&x_data[0], &incx_t, &beta1, &(y.data())[0], &incy_t);
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xgemv.cpp)
