//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// evalObjAndConstrAndDerivatives.h
//
// Code generation for function 'evalObjAndConstrAndDerivatives'
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
real_T evalObjAndConstrAndDerivatives(
    const ::coder::internal::r_stickyStruct &obj, const real_T x[40],
    real_T Cineq_workspace_data[], const int32_T &Cineq_workspace_size,
    int32_T ineq0, int32_T &status);

real_T evalObjAndConstrAndDerivatives(
    const ::coder::internal::i_stickyStruct &obj, const real_T x[40],
    real_T Cineq_workspace_data[], const int32_T &Cineq_workspace_size,
    int32_T ineq0, int32_T &status);

} // namespace ObjNonlinEvaluator
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (evalObjAndConstrAndDerivatives.h)
