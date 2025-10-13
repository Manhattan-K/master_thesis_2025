//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// updatePenaltyParam.h
//
// Code generation for function 'updatePenaltyParam'
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
struct h_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace MeritFunction {
void updatePenaltyParam(h_struct_T &obj, real_T fval,
                        const real_T ineq_workspace_data[], int32_T mIneq,
                        int32_T sqpiter, real_T qpval, const real_T x_data[],
                        int32_T iReg0, int32_T nRegularized);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (updatePenaltyParam.h)
