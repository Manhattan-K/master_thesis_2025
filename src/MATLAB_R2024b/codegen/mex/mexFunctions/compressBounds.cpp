//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// compressBounds.cpp
//
// Code generation for function 'compressBounds'
//

// Include files
#include "compressBounds.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
int32_T compressBounds(int32_T indexLB_data[], int32_T indexUB_data[],
                       int32_T indexFixed_data[], const real_T lb[40],
                       const real_T ub[40], int32_T &mUB, int32_T &mFixed)
{
  int32_T mLB;
  mLB = 0;
  mUB = 0;
  mFixed = 0;
  for (int32_T idx{0}; idx < 40; idx++) {
    real_T d;
    boolean_T guard1;
    d = lb[idx];
    guard1 = false;
    if ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d))) {
      if (muDoubleScalarAbs(d - ub[idx]) < 1.0E-6) {
        mFixed++;
        indexFixed_data[mFixed - 1] = idx + 1;
      } else {
        mLB++;
        indexLB_data[mLB - 1] = idx + 1;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      d = ub[idx];
      if ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d))) {
        mUB++;
        indexUB_data[mUB - 1] = idx + 1;
      }
    }
  }
  return mLB;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (compressBounds.cpp)
