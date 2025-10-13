//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgemm.cpp
//
// Code generation for function 'xgemm'
//

// Include files
#include "xgemm.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void b_xgemm(int32_T m, int32_T k, const array<real_T, 2U> &A, int32_T lda,
             const array<real_T, 2U> &B, int32_T ldb, array<real_T, 2U> &C,
             int32_T ldc)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  if (k >= 1) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)2;
    k_t = (ptrdiff_t)k;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)ldb;
    ldc_t = (ptrdiff_t)ldc;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(A.data())[0], &lda_t,
          &(B.data())[0], &ldb_t, &beta1, &(C.data())[0], &ldc_t);
  }
}

void xgemm(int32_T m, int32_T n, int32_T k, const real_T A[1600], int32_T lda,
           const array<real_T, 2U> &B, int32_T ib0, int32_T ldb,
           array<real_T, 2U> &C, int32_T ldc)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  if ((m >= 1) && (n >= 1) && (k >= 1)) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    k_t = (ptrdiff_t)k;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)ldb;
    ldc_t = (ptrdiff_t)ldc;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A[0],
          &lda_t, (real_T *)&B[ib0 - 1], &ldb_t, &beta1, &(C.data())[0],
          &ldc_t);
  }
}

void xgemm(int32_T m, int32_T n, int32_T k, const array<real_T, 2U> &A,
           int32_T ia0, int32_T lda, const array<real_T, 2U> &B, int32_T ldb,
           array<real_T, 2U> &C, int32_T ldc)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  if ((m >= 1) && (n >= 1) && (k >= 1)) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    k_t = (ptrdiff_t)k;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)ldb;
    ldc_t = (ptrdiff_t)ldc;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A[ia0 - 1],
          &lda_t, &(B.data())[0], &ldb_t, &beta1, &(C.data())[0], &ldc_t);
  }
}

void xgemm(int32_T m, int32_T k, const array<real_T, 2U> &A, int32_T lda,
           const array<real_T, 2U> &B, int32_T ldb, array<real_T, 2U> &C,
           int32_T ldc)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  alpha1 = 1.0;
  beta1 = 0.0;
  TRANSB1 = 'N';
  TRANSA1 = 'T';
  m_t = (ptrdiff_t)m;
  n_t = (ptrdiff_t)2;
  k_t = (ptrdiff_t)k;
  lda_t = (ptrdiff_t)lda;
  ldb_t = (ptrdiff_t)ldb;
  ldc_t = (ptrdiff_t)ldc;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(A.data())[0], &lda_t,
        &(B.data())[0], &ldb_t, &beta1, &(C.data())[0], &ldc_t);
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xgemm.cpp)
