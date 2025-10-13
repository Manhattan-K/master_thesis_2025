//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeLinearResiduals.cpp
//
// Code generation for function 'computeLinearResiduals'
//

// Include files
#include "computeLinearResiduals.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace internal {
void computeLinearResiduals(const real_T x[40], int32_T nVar,
                            real_T workspaceIneq_data[], int32_T mLinIneq,
                            const array<real_T, 1U> &AineqT, int32_T ldAi)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (mLinIneq > 0) {
    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mLinIneq;
    lda_t = (ptrdiff_t)ldAi;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(AineqT.data())[0], &lda_t,
          (real_T *)&x[0], &incx_t, &beta1, &workspaceIneq_data[0], &incy_t);
  }
}

} // namespace internal
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeLinearResiduals.cpp)
