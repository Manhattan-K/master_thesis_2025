//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeGradLag.cpp
//
// Code generation for function 'computeGradLag'
//

// Include files
#include "computeGradLag.h"
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
void computeGradLag(real_T workspace_data[], int32_T ldA, int32_T nVar,
                    const real_T grad_data[], int32_T mIneq,
                    const array<real_T, 1U> &AineqTrans,
                    const int32_T finiteFixed_data[], int32_T mFixed,
                    const int32_T finiteLB_data[], int32_T mLB,
                    const int32_T finiteUB_data[], int32_T mUB,
                    const array<real_T, 1U> &lambda)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  int32_T i;
  int32_T iL0;
  char_T TRANSA;
  i = static_cast<uint16_T>(nVar);
  std::copy(&grad_data[0], &grad_data[i], &workspace_data[0]);
  i = static_cast<uint16_T>(mFixed);
  for (int32_T idx{0}; idx < i; idx++) {
    workspace_data[finiteFixed_data[idx] - 1] += lambda[idx];
  }
  if (mIneq >= 1) {
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mIneq;
    lda_t = (ptrdiff_t)ldA;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(AineqTrans.data())[0], &lda_t,
          (real_T *)&lambda[mFixed], &incx_t, &beta1, &workspace_data[0],
          &incy_t);
  }
  iL0 = mFixed + mIneq;
  i = static_cast<uint16_T>(mLB);
  for (int32_T idx{0}; idx < i; idx++) {
    workspace_data[finiteLB_data[idx] - 1] -= lambda[iL0 + idx];
  }
  if (static_cast<uint16_T>(mLB) - 1 >= 0) {
    iL0 += static_cast<uint16_T>(mLB);
  }
  i = static_cast<uint16_T>(mUB);
  for (int32_T idx{0}; idx < i; idx++) {
    workspace_data[finiteUB_data[idx] - 1] += lambda[iL0 + idx];
  }
}

void computeGradLag(array<real_T, 2U> &workspace, int32_T ldA, int32_T nVar,
                    const real_T grad_data[], int32_T mIneq,
                    const array<real_T, 1U> &AineqTrans,
                    const int32_T finiteFixed_data[], int32_T mFixed,
                    const int32_T finiteLB_data[], int32_T mLB,
                    const int32_T finiteUB_data[], int32_T mUB,
                    const array<real_T, 1U> &lambda)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  int32_T b_i;
  int32_T i;
  int32_T iL0;
  char_T TRANSA;
  i = static_cast<uint16_T>(nVar);
  for (b_i = 0; b_i < i; b_i++) {
    workspace[b_i] = grad_data[b_i];
  }
  i = static_cast<uint16_T>(mFixed);
  for (int32_T idx{0}; idx < i; idx++) {
    b_i = finiteFixed_data[idx];
    workspace[b_i - 1] = workspace[b_i - 1] + lambda[idx];
  }
  if (mIneq >= 1) {
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)nVar;
    n_t = (ptrdiff_t)mIneq;
    lda_t = (ptrdiff_t)ldA;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(AineqTrans.data())[0], &lda_t,
          (real_T *)&lambda[mFixed], &incx_t, &beta1, &(workspace.data())[0],
          &incy_t);
  }
  iL0 = mFixed + mIneq;
  i = static_cast<uint16_T>(mLB);
  for (int32_T idx{0}; idx < i; idx++) {
    b_i = finiteLB_data[idx];
    workspace[b_i - 1] = workspace[b_i - 1] - lambda[iL0 + idx];
  }
  if (static_cast<uint16_T>(mLB) - 1 >= 0) {
    iL0 += static_cast<uint16_T>(mLB);
  }
  i = static_cast<uint16_T>(mUB);
  for (int32_T idx{0}; idx < i; idx++) {
    b_i = finiteUB_data[idx];
    workspace[b_i - 1] = workspace[b_i - 1] + lambda[iL0 + idx];
  }
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeGradLag.cpp)
