//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factor.h
//
// Code generation for function 'factor'
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

// Type Declarations
struct e_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace CholManager {
void factor(e_struct_T &obj, const real_T A[1600], int32_T ndims, int32_T ldA);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factor.h)
