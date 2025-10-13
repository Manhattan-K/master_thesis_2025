//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeComplError.h
//
// Code generation for function 'computeComplError'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
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
real_T computeComplError(int32_T fscales_cineq_constraint_size,
                         const real_T xCurrent[40], int32_T mIneq,
                         const real_T cIneq_data[],
                         const int32_T finiteLB_data[], int32_T mLB,
                         const real_T lb[40], const int32_T finiteUB_data[],
                         int32_T mUB, const real_T ub[40],
                         const array<real_T, 1U> &lambda, int32_T iL0);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeComplError.h)
