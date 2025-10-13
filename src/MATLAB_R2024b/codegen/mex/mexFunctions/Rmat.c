/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Rmat.c
 *
 * Code generation for function 'Rmat'
 *
 */

/* Include files */
#include "Rmat.h"
#include "mexFunctions_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
void Rmat(real_T theta, real_T R[4])
{
  real_T R_tmp;
  real_T b_R_tmp;
  emlrtMEXProfilingFunctionEntry((char_T *)Rmat_complete_name, isMexOutdated);
  emlrtMEXProfilingStatement(1, isMexOutdated);
  R_tmp = muDoubleScalarSin(theta);
  b_R_tmp = muDoubleScalarCos(theta);
  R[0] = b_R_tmp;
  R[2] = -R_tmp;
  R[1] = R_tmp;
  R[3] = b_R_tmp;
  emlrtMEXProfilingStatement(2, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
}

/* End of code generation (Rmat.c) */
