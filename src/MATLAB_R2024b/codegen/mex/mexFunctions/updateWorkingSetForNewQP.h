//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// updateWorkingSetForNewQP.h
//
// Code generation for function 'updateWorkingSetForNewQP'
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
struct g_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace internal {
void updateWorkingSetForNewQP(const real_T xk[40], g_struct_T &WorkingSet,
                              int32_T mIneq, const real_T cIneq_data[],
                              int32_T mLB, const real_T lb[40], int32_T mUB,
                              const real_T ub[40], int32_T mFixed);

void updateWorkingSetForNewQP(const real_T xk[40], g_struct_T &WorkingSet,
                              int32_T mIneq, int32_T mNonlinIneq,
                              const real_T cIneq_data[], int32_T mLB,
                              const real_T lb[40], int32_T mUB,
                              const real_T ub[40], int32_T mFixed);

} // namespace internal
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (updateWorkingSetForNewQP.h)
