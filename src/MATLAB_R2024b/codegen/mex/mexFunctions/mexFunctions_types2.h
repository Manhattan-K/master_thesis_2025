//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mexFunctions_types2.h
//
// Code generation for function 'mexFunctions_types2'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "string1.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
struct struct3_T {
  real_T n;
  real_T m;
  real_T Ts;
};

struct struct5_T {
  real_T M_l;
  real_T M_f;
  coder::array<real_T, 2U> A_bar_l;
  coder::bounded_array<real_T, 4200U, 1U> B_bar_l;
  coder::array<real_T, 2U> A_bar_f;
  coder::bounded_array<real_T, 800U, 1U> B_bar_f;
};

struct struct1_T {
  real_T Px[6];
  real_T v_max;
  real_T w_max;
  coder::b_rtString pos_color;
  coder::c_rtString pred_color;
  coder::rtString constraint_color;
  boolean_T show_predictions;
  boolean_T show_constraints;
  boolean_T keep_predictions;
  real_T initRobotShape[42];
  real_T robotShape[42];
  real_T W[9];
  real_T Z[9];
  real_T R[4];
  real_T W_hat[3600];
  real_T R_hat[1600];
  real_T lb[40];
  real_T ub[40];
};

struct struct2_T {
  real_T d_FL;
  real_T Px[6];
  real_T v_max;
  real_T w_max;
  coder::d_rtString pos_color;
  coder::d_rtString pred_color;
  coder::e_rtString constraint_color;
  boolean_T show_predictions;
  boolean_T show_constraints;
  boolean_T keep_predictions;
  real_T initRobotShape[8];
  real_T robotShape[8];
  real_T d_FL_sq[20];
  real_T C;
  real_T beta;
  real_T beta_N[20];
  real_T lb[40];
  real_T ub[40];
};

// End of code generation (mexFunctions_types2.h)
