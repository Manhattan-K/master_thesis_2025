//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mexFunctions_types1.h
//
// Code generation for function 'mexFunctions_types1'
//

#pragma once

// Include files
#include "mexFunctions_types2.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
struct j_struct_T {
  real_T x0[3];
  struct3_T sys;
  real_T N;
  real_T X_L_stacked[60];
  struct2_T robotParams;
};

struct k_struct_T {
  real_T x0[3];
  struct5_T obstacles;
  real_T N;
  struct2_T robotParams;
  struct3_T sys;
};

struct l_struct_T {
  real_T x0[3];
  struct3_T sys;
  struct1_T robotParams;
  real_T N;
};

struct m_struct_T {
  real_T x0[3];
  struct5_T obstacles;
  real_T N;
  struct1_T robotParams;
  struct3_T sys;
};

struct n_struct_T {
  real_T x0[3];
  struct3_T sys;
  real_T N;
  struct1_T robotParams;
};

// End of code generation (mexFunctions_types1.h)
