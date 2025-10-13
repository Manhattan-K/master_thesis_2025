//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeFval_ReuseHx.cpp
//
// Code generation for function 'computeFval_ReuseHx'
//

// Include files
#include "computeFval_ReuseHx.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
real_T computeFval_ReuseHx(const b_struct_T &obj, array<real_T, 2U> &workspace,
                           const real_T f_data[], const real_T x_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T val;
  val = 0.0;
  switch (obj.objtype) {
  case 5:
    val = obj.gammaScalar * x_data[obj.nvar - 1];
    break;
  case 3: {
    if (obj.hasLinear) {
      int32_T i;
      i = obj.nvar;
      for (int32_T maxRegVar{0}; maxRegVar < i; maxRegVar++) {
        workspace[maxRegVar] = 0.5 * obj.Hx.data[maxRegVar] + f_data[maxRegVar];
      }
      if (obj.nvar >= 1) {
        n_t = (ptrdiff_t)obj.nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, (real_T *)&x_data[0], &incx_t, &(workspace.data())[0],
                   &incy_t);
      }
    } else {
      if (obj.nvar >= 1) {
        n_t = (ptrdiff_t)obj.nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, (real_T *)&x_data[0], &incx_t,
                   (real_T *)&obj.Hx.data[0], &incy_t);
      }
      val *= 0.5;
    }
  } break;
  case 4: {
    int32_T maxRegVar;
    maxRegVar = obj.maxVar;
    if (obj.hasLinear) {
      int32_T i;
      i = obj.nvar;
      for (maxRegVar = 0; maxRegVar < i; maxRegVar++) {
        workspace[maxRegVar] = f_data[maxRegVar];
      }
      i = obj.maxVar - obj.nvar;
      for (maxRegVar = 0; maxRegVar <= i - 2; maxRegVar++) {
        workspace[obj.nvar + maxRegVar] = obj.rho;
      }
      i = static_cast<uint16_T>(obj.maxVar - 1);
      for (maxRegVar = 0; maxRegVar < i; maxRegVar++) {
        workspace[maxRegVar] =
            workspace[maxRegVar] + 0.5 * obj.Hx.data[maxRegVar];
      }
      if (obj.maxVar - 1 >= 1) {
        n_t = (ptrdiff_t)(obj.maxVar - 1);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, (real_T *)&x_data[0], &incx_t, &(workspace.data())[0],
                   &incy_t);
      }
    } else {
      int32_T i;
      if (obj.maxVar - 1 >= 1) {
        n_t = (ptrdiff_t)(obj.maxVar - 1);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, (real_T *)&x_data[0], &incx_t,
                   (real_T *)&obj.Hx.data[0], &incy_t);
      }
      val *= 0.5;
      i = obj.nvar + 1;
      for (int32_T idx{i}; idx < maxRegVar; idx++) {
        val += x_data[idx - 1] * obj.rho;
      }
    }
  } break;
  }
  return val;
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeFval_ReuseHx.cpp)
