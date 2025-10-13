//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// stateEvolution.h
//
// Code generation for function 'stateEvolution'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void stateEvolution(const real_T U[40], const real_T x0[3], real_T sys_n,
                    real_T sys_Ts, real_T N, coder::array<real_T, 1U> &x_pred);

// End of code generation (stateEvolution.h)
