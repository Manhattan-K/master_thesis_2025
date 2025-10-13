//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeFval.cpp
//
// Code generation for function 'computeFval'
//

// Include files
#include "computeFval.h"
#include "linearForm_.h"
#include "mexFunctions_types.h"
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
real_T computeFval(const b_struct_T &obj, array<real_T, 2U> &workspace,
                   const real_T H[1600], const real_T f_data[],
                   const real_T x_data[])
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
  case 3:
    linearForm_(obj.hasLinear, obj.nvar, workspace, H, f_data, x_data);
    if (obj.nvar >= 1) {
      n_t = (ptrdiff_t)obj.nvar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      val = ddot(&n_t, (real_T *)&x_data[0], &incx_t, &(workspace.data())[0],
                 &incy_t);
    }
    break;
  case 4: {
    int32_T i;
    int32_T i1;
    linearForm_(obj.hasLinear, obj.nvar, workspace, H, f_data, x_data);
    i = obj.nvar + 1;
    i1 = obj.maxVar;
    for (int32_T idx{i}; idx < i1; idx++) {
      workspace[idx - 1] = 0.5 * obj.beta * x_data[idx - 1] + obj.rho;
    }
    if (obj.maxVar - 1 >= 1) {
      n_t = (ptrdiff_t)(obj.maxVar - 1);
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      val = ddot(&n_t, (real_T *)&x_data[0], &incx_t, &(workspace.data())[0],
                 &incy_t);
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

// End of code generation (computeFval.cpp)
