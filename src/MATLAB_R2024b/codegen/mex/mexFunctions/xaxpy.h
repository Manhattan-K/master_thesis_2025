//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xaxpy.h
//
// Code generation for function 'xaxpy'
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
void xaxpy(int32_T n, real_T a, const real_T x_data[], real_T y_data[]);

void xaxpy(int32_T n, const real_T x_data[], array<real_T, 2U> &y);

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xaxpy.h)
