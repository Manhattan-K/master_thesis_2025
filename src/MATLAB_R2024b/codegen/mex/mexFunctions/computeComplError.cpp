//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeComplError.cpp
//
// Code generation for function 'computeComplError'
//

// Include files
#include "computeComplError.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
real_T computeComplError(int32_T fscales_cineq_constraint_size,
                         const real_T xCurrent[40], int32_T mIneq,
                         const real_T cIneq_data[],
                         const int32_T finiteLB_data[], int32_T mLB,
                         const real_T lb[40], const int32_T finiteUB_data[],
                         int32_T mUB, const real_T ub[40],
                         const array<real_T, 1U> &lambda, int32_T iL0)
{
  real_T nlpComplError;
  nlpComplError = 0.0;
  if ((mIneq + mLB) + mUB > 0) {
    real_T lbDelta;
    real_T lbLambda;
    int32_T i;
    int32_T lbOffset;
    int32_T ubOffset;
    for (int32_T idx{0}; idx < fscales_cineq_constraint_size; idx++) {
      lbDelta = lambda[(iL0 + idx) - 1];
      lbLambda = cIneq_data[idx];
      nlpComplError = muDoubleScalarMax(
          nlpComplError,
          muDoubleScalarMin(
              muDoubleScalarAbs(lbLambda * lbDelta),
              muDoubleScalarMin(muDoubleScalarAbs(lbLambda), lbDelta)));
    }
    lbOffset = (iL0 + mIneq) - 1;
    ubOffset = lbOffset + mLB;
    i = static_cast<uint16_T>(mLB);
    for (int32_T idx{0}; idx < i; idx++) {
      lbDelta = xCurrent[finiteLB_data[idx] - 1] - lb[finiteLB_data[idx] - 1];
      lbLambda = lambda[lbOffset + idx];
      nlpComplError = muDoubleScalarMax(
          nlpComplError,
          muDoubleScalarMin(
              muDoubleScalarAbs(lbDelta * lbLambda),
              muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
    }
    i = static_cast<uint16_T>(mUB);
    for (int32_T idx{0}; idx < i; idx++) {
      lbDelta = ub[finiteUB_data[idx] - 1] - xCurrent[finiteUB_data[idx] - 1];
      lbLambda = lambda[ubOffset + idx];
      nlpComplError = muDoubleScalarMax(
          nlpComplError,
          muDoubleScalarMin(
              muDoubleScalarAbs(lbDelta * lbLambda),
              muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
    }
  }
  return nlpComplError;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeComplError.cpp)
