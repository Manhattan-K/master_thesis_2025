//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// compressBounds.h
//
// Code generation for function 'compressBounds'
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
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
int32_T compressBounds(int32_T indexLB_data[], int32_T indexUB_data[],
                       int32_T indexFixed_data[], const real_T lb[40],
                       const real_T ub[40], int32_T &mUB, int32_T &mFixed);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (compressBounds.h)
