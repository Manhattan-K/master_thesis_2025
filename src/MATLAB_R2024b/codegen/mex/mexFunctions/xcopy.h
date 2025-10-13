//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xcopy.h
//
// Code generation for function 'xcopy'
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
namespace internal {
namespace blas {
void xcopy(int32_T n, const array<real_T, 2U> &x, int32_T ix0, real_T y_data[]);

void xcopy(int32_T n, const array<real_T, 2U> &x, real_T y_data[]);

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xcopy.h)
