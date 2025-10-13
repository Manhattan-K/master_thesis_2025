//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// finDiffEvalAndChkErr.h
//
// Code generation for function 'finDiffEvalAndChkErr'
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
class anonymous_function;

class b_anonymous_function;

class c_anonymous_function;

class d_anonymous_function;

class e_anonymous_function;

} // namespace coder

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
boolean_T finDiffEvalAndChkErr(const e_anonymous_function &obj_objfun,
                               const d_anonymous_function &obj_nonlin,
                               int32_T obj_mIneq, real_T cIneqPlus_data[],
                               int32_T &cIneqPlus_size, int32_T dim,
                               real_T delta, real_T xk[40], real_T &fplus);

boolean_T finDiffEvalAndChkErr(const c_anonymous_function &obj_objfun,
                               const d_anonymous_function &obj_nonlin,
                               int32_T obj_mIneq, real_T cIneqPlus_data[],
                               int32_T &cIneqPlus_size, int32_T dim,
                               real_T delta, real_T xk[40], real_T &fplus);

boolean_T finDiffEvalAndChkErr(const anonymous_function &obj_objfun,
                               const b_anonymous_function &obj_nonlin,
                               int32_T obj_mIneq, real_T cIneqPlus_data[],
                               int32_T &cIneqPlus_size, int32_T dim,
                               real_T delta, real_T xk[40], real_T &fplus);

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (finDiffEvalAndChkErr.h)
