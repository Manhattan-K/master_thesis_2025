//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xdot.h
//
// Code generation for function 'xdot'
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
real_T xdot(int32_T n, const real_T x_data[], int32_T ix0,
            const real_T y_data[], int32_T iy0);

real_T xdot(int32_T n, const array<real_T, 1U> &x, int32_T ix0,
            const real_T y_data[]);

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xdot.h)
