//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// normal.h
//
// Code generation for function 'normal'
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
struct mexFunctionsStackData;

struct f_struct_T;

struct h_struct_T;

struct c_struct_T;

struct g_struct_T;

struct d_struct_T;

struct e_struct_T;

struct b_struct_T;

struct i_struct_T;

struct struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
void normal(mexFunctionsStackData *SD, const real_T Hessian[1600],
            const real_T grad_data[], f_struct_T &b_TrialState,
            h_struct_T &b_MeritFunction, c_struct_T &memspace,
            g_struct_T &WorkingSet, d_struct_T &b_QRManager,
            e_struct_T &b_CholManager, b_struct_T &QPObjective,
            const i_struct_T &qpoptions, struct_T &stepFlags);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (normal.h)
