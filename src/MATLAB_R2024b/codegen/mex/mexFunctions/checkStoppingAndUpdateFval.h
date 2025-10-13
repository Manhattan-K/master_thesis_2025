//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkStoppingAndUpdateFval.h
//
// Code generation for function 'checkStoppingAndUpdateFval'
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
struct f_struct_T;

struct c_struct_T;

struct b_struct_T;

struct g_struct_T;

struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace stopping {
void b_checkStoppingAndUpdateFval(int32_T &activeSetChangeID,
                                  f_struct_T &solution, c_struct_T &memspace,
                                  const b_struct_T &objective,
                                  g_struct_T &workingset, d_struct_T &qrmanager,
                                  int32_T runTimeOptions_MaxIterations,
                                  boolean_T &updateFval);

void checkStoppingAndUpdateFval(int32_T &activeSetChangeID,
                                const real_T f_data[], f_struct_T &solution,
                                c_struct_T &memspace,
                                const b_struct_T &objective,
                                g_struct_T &workingset, d_struct_T &qrmanager,
                                int32_T runTimeOptions_MaxIterations,
                                const boolean_T &updateFval);

} // namespace stopping
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkStoppingAndUpdateFval.h)
