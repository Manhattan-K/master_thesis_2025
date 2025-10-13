//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sortLambdaQP.h
//
// Code generation for function 'sortLambdaQP'
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
namespace optim {
namespace coder {
namespace qpactiveset {
namespace parseoutput {
void sortLambdaQP(array<real_T, 1U> &lambda, int32_T WorkingSet_nActiveConstr,
                  const int32_T WorkingSet_sizes[5],
                  const int32_T WorkingSet_isActiveIdx[6],
                  const int32_T WorkingSet_Wid_data[],
                  const int32_T WorkingSet_Wlocalidx_data[],
                  array<real_T, 2U> &workspace);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (sortLambdaQP.h)
