//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// countsort.h
//
// Code generation for function 'countsort'
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
namespace utils {
void countsort(int32_T x_data[], int32_T xLen, int32_T workspace_data[],
               int32_T xMin, int32_T xMax);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (countsort.h)
