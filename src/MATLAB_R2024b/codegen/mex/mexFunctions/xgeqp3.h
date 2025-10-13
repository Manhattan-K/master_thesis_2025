//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgeqp3.h
//
// Code generation for function 'xgeqp3'
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
namespace lapack {
void xgeqp3(array<real_T, 2U> &A, int32_T m, int32_T n, int32_T jpvt_data[],
            const int32_T &jpvt_size, array<real_T, 1U> &tau);

}
} // namespace internal
} // namespace coder

// End of code generation (xgeqp3.h)
