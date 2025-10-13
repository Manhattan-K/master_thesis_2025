//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeDualFeasError.cpp
//
// Code generation for function 'computeDualFeasError'
//

// Include files
#include "computeDualFeasError.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
boolean_T computeDualFeasError(int32_T nVar, const real_T gradLag_data[],
                               real_T &val)
{
  int32_T idx;
  boolean_T exitg1;
  boolean_T gradOK;
  gradOK = true;
  val = 0.0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= static_cast<uint16_T>(nVar) - 1)) {
    gradOK = ((!muDoubleScalarIsInf(gradLag_data[idx])) &&
              (!muDoubleScalarIsNaN(gradLag_data[idx])));
    if (!gradOK) {
      exitg1 = true;
    } else {
      val = muDoubleScalarMax(val, muDoubleScalarAbs(gradLag_data[idx]));
      idx++;
    }
  }
  return gradOK;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeDualFeasError.cpp)
