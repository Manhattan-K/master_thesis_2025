//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factorQRE.h
//
// Code generation for function 'factorQRE'
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
void factorQRE(d_struct_T &obj, const array<real_T, 1U> &A, int32_T mrows,
               int32_T ncols, int32_T ldA);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factorQRE.h)
