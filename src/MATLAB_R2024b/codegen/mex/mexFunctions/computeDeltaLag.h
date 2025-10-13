//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeDeltaLag.h
//
// Code generation for function 'computeDeltaLag'
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
void computeDeltaLag(int32_T nVar, int32_T ldJ, int32_T mNonlinIneq,
                     real_T workspace_data[], const real_T grad_data[],
                     const array<real_T, 1U> &JacIneqTrans, int32_T ineqJ0,
                     const real_T grad_old_data[],
                     const array<real_T, 2U> &JacIneqTrans_old,
                     const array<real_T, 1U> &lambda, int32_T ineqL0);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeDeltaLag.h)
