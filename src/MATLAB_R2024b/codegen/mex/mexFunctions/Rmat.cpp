//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Rmat.cpp
//
// Code generation for function 'Rmat'
//

// Include files
#include "Rmat.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
void Rmat(real_T theta, real_T R[4])
{
  real_T R_tmp;
  real_T b_R_tmp;
  R_tmp = muDoubleScalarSin(theta);
  b_R_tmp = muDoubleScalarCos(theta);
  R[0] = b_R_tmp;
  R[2] = -R_tmp;
  R[1] = R_tmp;
  R[3] = b_R_tmp;
}

// End of code generation (Rmat.cpp)
