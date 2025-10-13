//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// maxConstraintViolation.h
//
// Code generation for function 'maxConstraintViolation'
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
struct mexFunctionsStackData;

struct g_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
real_T b_maxConstraintViolation(g_struct_T &obj, const array<real_T, 2U> &x);

real_T b_maxConstraintViolation(g_struct_T &obj, const array<real_T, 2U> &x,
                                int32_T ix0);

real_T b_maxConstraintViolation(g_struct_T &obj, const real_T x_data[]);

real_T b_maxConstraintViolation(mexFunctionsStackData *SD,
                                const g_struct_T &obj, const real_T x_data[]);

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (maxConstraintViolation.h)
