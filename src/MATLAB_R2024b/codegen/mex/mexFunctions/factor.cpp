//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factor.cpp
//
// Code generation for function 'factor'
//

// Include files
#include "factor.h"
#include "mexFunctions_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace CholManager {
void factor(e_struct_T &obj, const real_T A[1600], int32_T ndims, int32_T ldA)
{
  ptrdiff_t info_t;
  int32_T ix0;
  int32_T iy0;
  obj.ndims = ndims;
  for (int32_T idx{0}; idx < ndims; idx++) {
    ix0 = ldA * idx;
    iy0 = obj.ldm * idx;
    for (int32_T k{0}; k < ndims; k++) {
      obj.FMat[iy0 + k] = A[ix0 + k];
    }
  }
  info_t = LAPACKE_dpotrf_work(102, 'U', (ptrdiff_t)ndims,
                               &(obj.FMat.data())[0], (ptrdiff_t)obj.ldm);
  if ((int32_T)info_t < 0) {
    ix0 = obj.FMat.size(0);
    iy0 = obj.FMat.size(1);
    ix0 *= iy0;
    for (iy0 = 0; iy0 < ix0; iy0++) {
      obj.FMat[iy0] = rtNaN;
    }
  }
  obj.info = (int32_T)info_t;
}

} // namespace CholManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factor.cpp)
