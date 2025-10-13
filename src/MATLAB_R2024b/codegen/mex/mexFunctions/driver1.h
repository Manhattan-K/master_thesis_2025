//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// driver1.h
//
// Code generation for function 'driver1'
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

struct g_struct_T;

struct d_struct_T;

struct e_struct_T;

struct b_struct_T;

struct i_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void driver(const real_T H[1600], const real_T f_data[], f_struct_T &solution,
            c_struct_T &memspace, g_struct_T &workingset, d_struct_T &qrmanager,
            e_struct_T &cholmanager, b_struct_T &objective,
            const i_struct_T &options, const i_struct_T &runTimeOptions);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (driver1.h)
