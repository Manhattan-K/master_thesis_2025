//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factoryConstruct1.h
//
// Code generation for function 'factoryConstruct1'
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
namespace qpactiveset {
namespace Objective {
int32_T factoryConstruct(int32_T MaxVars, int32_T &obj_Hx_size,
                         boolean_T &obj_hasLinear, int32_T &obj_nvar,
                         int32_T &obj_maxVar, real_T &obj_beta, real_T &obj_rho,
                         int32_T &obj_objtype, int32_T &obj_prev_objtype,
                         int32_T &obj_prev_nvar, boolean_T &obj_prev_hasLinear,
                         real_T &obj_gammaScalar);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factoryConstruct1.h)
