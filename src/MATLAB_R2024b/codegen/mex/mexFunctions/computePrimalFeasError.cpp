//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computePrimalFeasError.cpp
//
// Code generation for function 'computePrimalFeasError'
//

// Include files
#include "computePrimalFeasError.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
real_T computePrimalFeasError(const real_T x[40], int32_T mLinIneq,
                              int32_T mNonlinIneq, const real_T cIneq_data[],
                              const int32_T finiteLB_data[], int32_T mLB,
                              const real_T lb[40],
                              const int32_T finiteUB_data[], int32_T mUB,
                              const real_T ub[40])
{
  real_T feasError;
  int32_T mIneq;
  feasError = 0.0;
  mIneq = mNonlinIneq + mLinIneq;
  for (int32_T idx{0}; idx < mIneq; idx++) {
    feasError = muDoubleScalarMax(feasError, cIneq_data[idx]);
  }
  mIneq = static_cast<uint16_T>(mLB);
  for (int32_T idx{0}; idx < mIneq; idx++) {
    feasError = muDoubleScalarMax(feasError, lb[finiteLB_data[idx] - 1] -
                                                 x[finiteLB_data[idx] - 1]);
  }
  mIneq = static_cast<uint16_T>(mUB);
  for (int32_T idx{0}; idx < mIneq; idx++) {
    feasError = muDoubleScalarMax(feasError, x[finiteUB_data[idx] - 1] -
                                                 ub[finiteUB_data[idx] - 1]);
  }
  return feasError;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computePrimalFeasError.cpp)
