//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// RemoveDependentIneq_.h
//
// Code generation for function 'RemoveDependentIneq_'
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

struct d_struct_T;

struct c_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void RemoveDependentIneq_(g_struct_T &workingset, d_struct_T &qrmanager,
                          c_struct_T &memspace);

void b_RemoveDependentIneq_(g_struct_T &workingset, d_struct_T &qrmanager,
                            c_struct_T &memspace);

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (RemoveDependentIneq_.h)
