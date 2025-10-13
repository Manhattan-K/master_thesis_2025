//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computePrimalFeasError.h
//
// Code generation for function 'computePrimalFeasError'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
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
                              const real_T ub[40]);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computePrimalFeasError.h)
