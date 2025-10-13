//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeGradLag.h
//
// Code generation for function 'computeGradLag'
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
namespace fminconsqp {
namespace stopping {
void computeGradLag(real_T workspace_data[], int32_T ldA, int32_T nVar,
                    const real_T grad_data[], int32_T mIneq,
                    const array<real_T, 1U> &AineqTrans,
                    const int32_T finiteFixed_data[], int32_T mFixed,
                    const int32_T finiteLB_data[], int32_T mLB,
                    const int32_T finiteUB_data[], int32_T mUB,
                    const array<real_T, 1U> &lambda);

void computeGradLag(array<real_T, 2U> &workspace, int32_T ldA, int32_T nVar,
                    const real_T grad_data[], int32_T mIneq,
                    const array<real_T, 1U> &AineqTrans,
                    const int32_T finiteFixed_data[], int32_T mFixed,
                    const int32_T finiteLB_data[], int32_T mLB,
                    const int32_T finiteUB_data[], int32_T mUB,
                    const array<real_T, 1U> &lambda);

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeGradLag.h)
