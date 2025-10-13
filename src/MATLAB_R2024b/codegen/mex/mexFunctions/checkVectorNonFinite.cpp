//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkVectorNonFinite.cpp
//
// Code generation for function 'checkVectorNonFinite'
//

// Include files
#include "checkVectorNonFinite.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace ObjNonlinEvaluator {
namespace internal {
int32_T checkVectorNonFinite(int32_T N, const real_T vec_data[], int32_T iv0)
{
  int32_T idx_current;
  int32_T idx_end;
  int32_T status;
  boolean_T allFinite;
  status = 1;
  allFinite = true;
  idx_current = iv0;
  idx_end = (iv0 + N) - 1;
  while (allFinite && (idx_current <= idx_end)) {
    real_T allFinite_tmp;
    allFinite_tmp = vec_data[idx_current - 1];
    allFinite = ((!muDoubleScalarIsInf(allFinite_tmp)) &&
                 (!muDoubleScalarIsNaN(allFinite_tmp)));
    idx_current++;
  }
  if (!allFinite) {
    idx_current -= 2;
    if (muDoubleScalarIsNaN(vec_data[idx_current])) {
      status = -3;
    } else if (vec_data[idx_current] < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }
  return status;
}

} // namespace internal
} // namespace ObjNonlinEvaluator
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkVectorNonFinite.cpp)
