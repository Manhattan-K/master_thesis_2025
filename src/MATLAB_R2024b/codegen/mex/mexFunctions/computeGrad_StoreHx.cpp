//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeGrad_StoreHx.cpp
//
// Code generation for function 'computeGrad_StoreHx'
//

// Include files
#include "computeGrad_StoreHx.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void computeGrad_StoreHx(b_struct_T &obj, const real_T H[1600],
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
  switch (obj.objtype) {
  case 5: {
    int32_T i;
    i = obj.nvar;
    if (i - 2 >= 0) {
      std::memset(&obj.grad.data[0], 0,
                  static_cast<uint32_T>(i - 1) * sizeof(real_T));
    }
    obj.grad.data[obj.nvar - 1] = obj.gammaScalar;
  } break;
  case 3: {
    int32_T i;
    if (obj.nvar >= 1) {
      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSA = 'N';
      m_t = (ptrdiff_t)obj.nvar;
      n_t = (ptrdiff_t)obj.nvar;
      lda_t = (ptrdiff_t)obj.nvar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dgemv(&TRANSA, &m_t, &n_t, &alpha1, (real_T *)&H[0], &lda_t,
            (real_T *)&x_data[0], &incx_t, &beta1, &obj.Hx.data[0], &incy_t);
    }
    i = obj.nvar;
    if (i - 1 >= 0) {
      std::copy(&obj.Hx.data[0], &obj.Hx.data[i], &obj.grad.data[0]);
    }
    if (obj.hasLinear && (obj.nvar >= 1)) {
      alpha1 = 1.0;
      n_t = (ptrdiff_t)obj.nvar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      daxpy(&n_t, &alpha1, (real_T *)&f_data[0], &incx_t, &obj.grad.data[0],
            &incy_t);
    }
  } break;
  case 4: {
    int32_T i;
    int32_T iy;
    int32_T maxRegVar;
    maxRegVar = obj.maxVar;
    if (obj.nvar >= 1) {
      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSA = 'N';
      m_t = (ptrdiff_t)obj.nvar;
      n_t = (ptrdiff_t)obj.nvar;
      lda_t = (ptrdiff_t)obj.nvar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dgemv(&TRANSA, &m_t, &n_t, &alpha1, (real_T *)&H[0], &lda_t,
            (real_T *)&x_data[0], &incx_t, &beta1, &obj.Hx.data[0], &incy_t);
    }
    i = obj.nvar + 1;
    for (iy = i; iy < maxRegVar; iy++) {
      obj.Hx.data[iy - 1] = obj.beta * x_data[iy - 1];
    }
    i = static_cast<uint16_T>(obj.maxVar - 1);
    std::copy(&obj.Hx.data[0], &obj.Hx.data[i], &obj.grad.data[0]);
    if (obj.hasLinear && (obj.nvar >= 1)) {
      alpha1 = 1.0;
      n_t = (ptrdiff_t)obj.nvar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      daxpy(&n_t, &alpha1, (real_T *)&f_data[0], &incx_t, &obj.grad.data[0],
            &incy_t);
    }
    maxRegVar = (obj.maxVar - obj.nvar) - 1;
    if (maxRegVar >= 1) {
      iy = obj.nvar;
      for (int32_T k{0}; k < maxRegVar; k++) {
        i = iy + k;
        obj.grad.data[i] += obj.rho;
      }
    }
  } break;
  }
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeGrad_StoreHx.cpp)
