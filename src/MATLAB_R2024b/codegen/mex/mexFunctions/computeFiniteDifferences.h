//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeFiniteDifferences.h
//
// Code generation for function 'computeFiniteDifferences'
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

// Type Declarations
struct o_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
boolean_T computeFiniteDifferences(o_struct_T &obj, real_T fCurrent,
                                   const real_T cIneqCurrent_data[],
                                   int32_T ineq0, real_T xk[40],
                                   real_T gradf_data[],
                                   array<real_T, 1U> &JacCineqTrans,
                                   int32_T CineqColStart, int32_T ldJI,
                                   const real_T lb[40], const real_T ub[40]);

}
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeFiniteDifferences.h)
