//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeDeltaLag.cpp
//
// Code generation for function 'computeDeltaLag'
//

// Include files
#include "computeDeltaLag.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
void computeDeltaLag(int32_T nVar, int32_T ldJ, int32_T mNonlinIneq,
                     real_T workspace_data[], const real_T grad_data[],
                     const array<real_T, 1U> &JacIneqTrans, int32_T ineqJ0,
                     const real_T grad_old_data[],
                     const array<real_T, 2U> &JacIneqTrans_old,
                     const array<real_T, 1U> &lambda, int32_T ineqL0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T a;
  real_T beta1;
  int32_T i;
  char_T TRANSA;
  i = static_cast<uint16_T>(nVar);
  std::copy(&grad_data[0], &grad_data[i], &workspace_data[0]);
  if (nVar >= 1) {
    a = -1.0;
    n_t = (ptrdiff_t)nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    daxpy(&n_t, &a, (real_T *)&grad_old_data[0], &incx_t, &workspace_data[0],
          &incy_t);
  }
  if (mNonlinIneq > 0) {
    a = 1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mNonlinIneq;
    lda_t = (ptrdiff_t)ldJ;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &a, (real_T *)&JacIneqTrans[ldJ * (ineqJ0 - 1)],
          &lda_t, (real_T *)&lambda[ineqL0 - 1], &incx_t, &beta1,
          &workspace_data[0], &incy_t);
    a = -1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mNonlinIneq;
    lda_t = (ptrdiff_t)ldJ;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &a, &(JacIneqTrans_old.data())[0], &lda_t,
          (real_T *)&lambda[ineqL0 - 1], &incx_t, &beta1, &workspace_data[0],
          &incy_t);
  }
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeDeltaLag.cpp)
