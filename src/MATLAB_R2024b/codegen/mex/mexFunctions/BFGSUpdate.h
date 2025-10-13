//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// BFGSUpdate.h
//
// Code generation for function 'BFGSUpdate'
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
boolean_T BFGSUpdate(int32_T nvar, real_T Bk[1600], const real_T sk_data[],
                     real_T yk_data[], array<real_T, 2U> &workspace);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (BFGSUpdate.h)
