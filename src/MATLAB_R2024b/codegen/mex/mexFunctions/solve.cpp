//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// solve.cpp
//
// Code generation for function 'solve'
//

// Include files
#include "solve.h"
#include "mexFunctions_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace CholManager {
void solve(const e_struct_T &obj, real_T rhs_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t lda_t;
  ptrdiff_t n_t;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  if (obj.ndims >= 1) {
    DIAGA1 = 'N';
    TRANSA1 = 'T';
    UPLO1 = 'U';
    n_t = (ptrdiff_t)obj.ndims;
    lda_t = (ptrdiff_t)obj.ldm;
    incx_t = (ptrdiff_t)1;
    dtrsv(&UPLO1, &TRANSA1, &DIAGA1, &n_t, &(obj.FMat.data())[0], &lda_t,
          &rhs_data[0], &incx_t);
  }
  if (obj.ndims >= 1) {
    DIAGA1 = 'N';
    TRANSA1 = 'N';
    UPLO1 = 'U';
    n_t = (ptrdiff_t)obj.ndims;
    lda_t = (ptrdiff_t)obj.ldm;
    incx_t = (ptrdiff_t)1;
    dtrsv(&UPLO1, &TRANSA1, &DIAGA1, &n_t, &(obj.FMat.data())[0], &lda_t,
          &rhs_data[0], &incx_t);
  }
}

} // namespace CholManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (solve.cpp)
