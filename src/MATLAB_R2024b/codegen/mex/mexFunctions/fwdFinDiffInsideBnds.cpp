//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fwdFinDiffInsideBnds.cpp
//
// Code generation for function 'fwdFinDiffInsideBnds'
//

// Include files
#include "fwdFinDiffInsideBnds.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
boolean_T fwdFinDiffInsideBnds(real_T xC_i, real_T lb_i, real_T ub_i,
                               real_T &delta_i)
{
  boolean_T modifiedStep;
  modifiedStep = false;
  if ((lb_i != ub_i) && (xC_i >= lb_i) && (xC_i <= ub_i)) {
    real_T lbDiff;
    lbDiff = xC_i + delta_i;
    if ((lbDiff > ub_i) || (lbDiff < lb_i)) {
      delta_i = -delta_i;
      modifiedStep = true;
      lbDiff = xC_i + delta_i;
      if ((lbDiff > ub_i) || (lbDiff < lb_i)) {
        real_T ubDiff;
        lbDiff = xC_i - lb_i;
        ubDiff = ub_i - xC_i;
        if (lbDiff <= ubDiff) {
          delta_i = -lbDiff;
        } else {
          delta_i = ubDiff;
        }
      }
    }
  }
  return modifiedStep;
}

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (fwdFinDiffInsideBnds.cpp)
