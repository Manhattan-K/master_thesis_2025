//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgemv.h
//
// Code generation for function 'xgemv'
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
void xgemv(int32_T m, int32_T n, const array<real_T, 1U> &A, int32_T lda,
           const real_T x_data[], array<real_T, 2U> &y);

}
} // namespace internal
} // namespace coder

// End of code generation (xgemv.h)
