//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// test_exit.h
//
// Code generation for function 'test_exit'
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

struct g_struct_T;

struct f_struct_T;

struct struct_T;

struct c_struct_T;

struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void b_test_exit(struct_T &Flags, c_struct_T &memspace,
                 h_struct_T &b_MeritFunction,
                 int32_T fscales_cineq_constraint_size, g_struct_T &WorkingSet,
                 f_struct_T &b_TrialState, d_struct_T &b_QRManager,
                 const real_T lb[40], const real_T ub[40]);

boolean_T test_exit(h_struct_T &b_MeritFunction,
                    int32_T fscales_cineq_constraint_size,
                    const g_struct_T &WorkingSet, f_struct_T &b_TrialState,
                    const real_T lb[40], const real_T ub[40],
                    boolean_T &Flags_fevalOK, boolean_T &Flags_done,
                    boolean_T &Flags_stepAccepted,
                    boolean_T &Flags_failedLineSearch, int32_T &Flags_stepType);

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (test_exit.h)
