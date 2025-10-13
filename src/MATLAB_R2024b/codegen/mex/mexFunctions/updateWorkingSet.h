//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// updateWorkingSet.h
//
// Code generation for function 'updateWorkingSet'
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
namespace step {
namespace soc {
void updateWorkingSet(g_struct_T &WorkingSet,
                      const real_T TrialState_cIneq_data[],
                      const real_T TrialState_searchDir_data[],
                      int32_T workspace_int_data[]);

}
} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (updateWorkingSet.h)
