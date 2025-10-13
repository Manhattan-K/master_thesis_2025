//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// compute_lambda.h
//
// Code generation for function 'compute_lambda'
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
struct f_struct_T;

struct b_struct_T;

struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_lambda(array<real_T, 2U> &workspace, f_struct_T &solution,
                    const b_struct_T &objective, const d_struct_T &qrmanager);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (compute_lambda.h)
