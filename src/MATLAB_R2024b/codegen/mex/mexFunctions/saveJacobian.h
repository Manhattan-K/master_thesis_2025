//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// saveJacobian.h
//
// Code generation for function 'saveJacobian'
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

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace TrialState {
void saveJacobian(f_struct_T &obj, int32_T nVar, int32_T mIneq,
                  const array<real_T, 1U> &JacCineqTrans, int32_T ineqCol0,
                  int32_T ldJ);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (saveJacobian.h)
