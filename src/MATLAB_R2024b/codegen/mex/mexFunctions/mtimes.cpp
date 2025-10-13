//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mtimes.cpp
//
// Code generation for function 'mtimes'
//

// Include files
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void mtimes(const real_T A[6], const array<real_T, 2U> &B, array<real_T, 2U> &C)
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
  if ((B.size(0) == 0) || (B.size(1) == 0)) {
    int32_T loop_ub_tmp;
    C.set_size(2, B.size(1));
    loop_ub_tmp = B.size(1) << 1;
    for (int32_T i{0}; i < loop_ub_tmp; i++) {
      C[i] = 0.0;
    }
  } else {
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)2;
    n_t = (ptrdiff_t)B.size(1);
    k_t = (ptrdiff_t)3;
    lda_t = (ptrdiff_t)2;
    ldb_t = (ptrdiff_t)B.size(0);
    ldc_t = (ptrdiff_t)2;
    C.set_size(2, B.size(1));
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A[0],
          &lda_t, &(B.data())[0], &ldb_t, &beta1, &(C.data())[0], &ldc_t);
  }
}

int32_T mtimes(const array<real_T, 2U> &A, const array<real_T, 1U> &B,
               real_T C_data[])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  int32_T C_size;
  char_T TRANSA1;
  char_T TRANSB1;
  if ((A.size(0) == 0) || (B.size(0) == 0)) {
    int32_T loop_ub;
    loop_ub = A.size(0);
    C_size = A.size(0);
    if (loop_ub - 1 >= 0) {
      std::memset(&C_data[0], 0,
                  static_cast<uint32_T>(loop_ub) * sizeof(real_T));
    }
  } else {
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A.size(0);
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)60;
    lda_t = (ptrdiff_t)A.size(0);
    ldb_t = (ptrdiff_t)B.size(0);
    ldc_t = (ptrdiff_t)A.size(0);
    C_size = A.size(0);
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(A.data())[0], &lda_t,
          &(B.data())[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
  return C_size;
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (mtimes.cpp)
