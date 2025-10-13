//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xasum.h
//
// Code generation for function 'xasum'
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

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
real_T xasum(int32_T n, const real_T x_data[], int32_T ix0);

}
} // namespace internal
} // namespace coder

// End of code generation (xasum.h)
