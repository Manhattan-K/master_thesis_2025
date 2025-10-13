//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// assignResidualsToXSlack.h
//
// Code generation for function 'assignResidualsToXSlack'
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

struct f_struct_T;

struct c_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
namespace relaxed {
void assignResidualsToXSlack(int32_T nVarOrig, const g_struct_T &WorkingSet,
                             f_struct_T &b_TrialState, c_struct_T &memspace);

}
} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (assignResidualsToXSlack.h)
