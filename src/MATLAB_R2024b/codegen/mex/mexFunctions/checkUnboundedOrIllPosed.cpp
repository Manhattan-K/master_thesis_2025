//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkUnboundedOrIllPosed.cpp
//
// Code generation for function 'checkUnboundedOrIllPosed'
//

// Include files
#include "checkUnboundedOrIllPosed.h"
#include "mexFunctions_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace stopping {
void checkUnboundedOrIllPosed(f_struct_T &solution, const b_struct_T &objective)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  if (objective.objtype == 5) {
    real_T normDelta;
    if (objective.nvar < 1) {
      normDelta = 0.0;
    } else {
      n_t = (ptrdiff_t)objective.nvar;
      incx_t = (ptrdiff_t)1;
      normDelta = dnrm2(&n_t, &solution.searchDir.data[0], &incx_t);
    }
    if (normDelta >
        100.0 * static_cast<real_T>(objective.nvar) * 1.4901161193847656E-8) {
      solution.state = 3;
    } else {
      solution.state = 4;
    }
  }
}

} // namespace stopping
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkUnboundedOrIllPosed.cpp)
