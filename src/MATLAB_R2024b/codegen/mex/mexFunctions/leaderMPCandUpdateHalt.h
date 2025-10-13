//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// leaderMPCandUpdateHalt.h
//
// Code generation for function 'leaderMPCandUpdateHalt'
//

#pragma once

// Include files
#include "mexFunctions_types.h"
#include "mexFunctions_types2.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void leaderMPCandUpdateHalt(
    mexFunctionsStackData *SD, const struct3_T *sys, const real_T x0[3],
    real_T N, const struct1_T *robotParams, const struct5_T *obstacles,
    const real_T U_l_old[40], coder::array<real_T, 1U> &p_tp1,
    coder::array<real_T, 2U> &X_L, coder::array<real_T, 1U> &X_L_stacked,
    struct6_T *c_error, real_T u_t[2], real_T u_opt[40]);

real_T leaderMPCandUpdateHalt_anonFcn1(const real_T x0[3], real_T sys_n,
                                       real_T sys_Ts, real_T N,
                                       const real_T robotParams_Px[6],
                                       const real_T U[40]);

// End of code generation (leaderMPCandUpdateHalt.h)
