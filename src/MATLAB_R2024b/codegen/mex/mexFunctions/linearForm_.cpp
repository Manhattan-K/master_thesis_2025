//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linearForm_.cpp
//
// Code generation for function 'linearForm_'
//

// Include files
#include "linearForm_.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
                 array<real_T, 2U> &workspace, const real_T H[1600],
                 const real_T f_data[], const real_T x_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  beta1 = 0.0;
  if (obj_hasLinear) {
    for (int32_T i{0}; i < obj_nvar; i++) {
      workspace[i] = f_data[i];
    }
    beta1 = 1.0;
  }
  if (obj_nvar >= 1) {
    alpha1 = 0.5;
    TRANSA = 'N';
    m_t = (ptrdiff_t)obj_nvar;
    n_t = (ptrdiff_t)obj_nvar;
    lda_t = (ptrdiff_t)obj_nvar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, (real_T *)&H[0], &lda_t,
          (real_T *)&x_data[0], &incx_t, &beta1, &(workspace.data())[0],
          &incy_t);
  }
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (linearForm_.cpp)
