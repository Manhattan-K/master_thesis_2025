//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// squareQ_appendCol.h
//
// Code generation for function 'squareQ_appendCol'
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
struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void squareQ_appendCol(d_struct_T &obj, const array<real_T, 1U> &vec,
                       int32_T iv0);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (squareQ_appendCol.h)
