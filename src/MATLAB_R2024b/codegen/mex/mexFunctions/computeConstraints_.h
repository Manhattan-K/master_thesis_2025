//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeConstraints_.h
//
// Code generation for function 'computeConstraints_'
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

// Type Declarations
namespace coder {
namespace internal {
class bb_stickyStruct;

class i_stickyStruct;

class r_stickyStruct;

} // namespace internal
} // namespace coder

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace ObjNonlinEvaluator {
int32_T computeConstraints_(const ::coder::internal::r_stickyStruct &obj,
                            const real_T x[40], real_T Cineq_workspace_data[],
                            int32_T ineq0);

int32_T computeConstraints_(const ::coder::internal::i_stickyStruct &obj,
                            const real_T x[40], real_T Cineq_workspace_data[],
                            int32_T ineq0);

int32_T computeConstraints_(const ::coder::internal::bb_stickyStruct &obj,
                            const real_T x[40], real_T Cineq_workspace_data[],
                            int32_T ineq0);

} // namespace ObjNonlinEvaluator
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeConstraints_.h)
