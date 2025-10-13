//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// squareQ_appendCol.cpp
//
// Code generation for function 'squareQ_appendCol'
//

// Include files
#include "squareQ_appendCol.h"
#include "mexFunctions_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void squareQ_appendCol(d_struct_T &obj, const array<real_T, 1U> &vec,
                       int32_T iv0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T beta1;
  real_T c;
  real_T s;
  real_T temp;
  int32_T Qk0;
  char_T TRANSA;
  Qk0 = obj.ncols + 1;
  obj.minRowCol = muIntScalarMin_sint32(obj.mrows, Qk0);
  if (obj.mrows >= 1) {
    temp = 1.0;
    beta1 = 0.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)obj.mrows;
    n_t = (ptrdiff_t)obj.mrows;
    lda_t = (ptrdiff_t)obj.ldq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &temp, &(obj.Q.data())[0], &lda_t,
          (real_T *)&vec[iv0 - 1], &incx_t, &beta1,
          &obj.QR[obj.ldq * obj.ncols], &incy_t);
  }
  obj.ncols++;
  obj.jpvt.data[obj.ncols - 1] = obj.ncols;
  for (int32_T idx{obj.mrows - 2}; idx + 2 > obj.ncols; idx--) {
    int32_T n;
    Qk0 = idx + obj.ldq * (obj.ncols - 1);
    beta1 = obj.QR[Qk0];
    temp = obj.QR[Qk0 + 1];
    c = 0.0;
    s = 0.0;
    drotg(&beta1, &temp, &c, &s);
    obj.QR[Qk0] = beta1;
    obj.QR[Qk0 + 1] = temp;
    Qk0 = obj.ldq * idx;
    n = obj.mrows;
    if (obj.mrows >= 1) {
      int32_T iy;
      iy = obj.ldq + Qk0;
      for (int32_T k{0}; k < n; k++) {
        int32_T b_temp_tmp;
        int32_T temp_tmp;
        temp_tmp = iy + k;
        b_temp_tmp = Qk0 + k;
        temp = c * obj.Q[b_temp_tmp] + s * obj.Q[temp_tmp];
        obj.Q[temp_tmp] = c * obj.Q[temp_tmp] - s * obj.Q[b_temp_tmp];
        obj.Q[b_temp_tmp] = temp;
      }
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (squareQ_appendCol.cpp)
