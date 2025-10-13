//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgemm.h
//
// Code generation for function 'xgemm'
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
void b_xgemm(int32_T m, int32_T k, const array<real_T, 2U> &A, int32_T lda,
             const array<real_T, 2U> &B, int32_T ldb, array<real_T, 2U> &C,
             int32_T ldc);

void xgemm(int32_T m, int32_T n, int32_T k, const real_T A[1600], int32_T lda,
           const array<real_T, 2U> &B, int32_T ib0, int32_T ldb,
           array<real_T, 2U> &C, int32_T ldc);

void xgemm(int32_T m, int32_T n, int32_T k, const array<real_T, 2U> &A,
           int32_T ia0, int32_T lda, const array<real_T, 2U> &B, int32_T ldb,
           array<real_T, 2U> &C, int32_T ldc);

void xgemm(int32_T m, int32_T k, const array<real_T, 2U> &A, int32_T lda,
           const array<real_T, 2U> &B, int32_T ldb, array<real_T, 2U> &C,
           int32_T ldc);

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xgemm.h)
