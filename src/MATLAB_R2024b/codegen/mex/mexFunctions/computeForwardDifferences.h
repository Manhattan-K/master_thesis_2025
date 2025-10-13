//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeForwardDifferences.h
//
// Code generation for function 'computeForwardDifferences'
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
struct p_struct_T;

struct q_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
boolean_T computeForwardDifferences(q_struct_T &obj, real_T fCurrent,
                                    const real_T cIneqCurrent_data[],
                                    int32_T ineq0, real_T xk[40],
                                    real_T gradf_data[],
                                    array<real_T, 1U> &JacCineqTrans,
                                    int32_T CineqColStart, int32_T ldJI,
                                    const real_T lb[40], const real_T ub[40]);

boolean_T computeForwardDifferences(p_struct_T &obj, real_T fCurrent,
                                    const real_T cIneqCurrent_data[],
                                    int32_T ineq0, real_T xk[40],
                                    real_T gradf_data[],
                                    array<real_T, 1U> &JacCineqTrans,
                                    int32_T CineqColStart, int32_T ldJI,
                                    const real_T lb[40], const real_T ub[40]);

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeForwardDifferences.h)
