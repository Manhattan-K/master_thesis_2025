//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xtrsm.h
//
// Code generation for function 'xtrsm'
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
void b_xtrsm(int32_T m, const array<real_T, 2U> &A, int32_T lda,
             array<real_T, 2U> &B, int32_T ldb);

void xtrsm(int32_T m, const array<real_T, 2U> &A, int32_T lda,
           array<real_T, 2U> &B, int32_T ldb);

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xtrsm.h)
