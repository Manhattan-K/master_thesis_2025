/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "evaluateObstacles_mex_data.h"
#include "evaluateObstacles_mex_emxutil.h"
#include "evaluateObstacles_mex_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = {
    53,       /* lineNo */
    5,        /* colNo */
    "repmat", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pName
                                                                         */
};

/* Function Declarations */
static void b_error(const mxArray *m, emlrtMCInfo *location);

/* Function Definitions */
static void b_error(const mxArray *m, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "error", true,
                        location);
}

void repmat(const emxArray_real_T *a, real_T varargin_1, emxArray_real_T *b)
{
  static const int32_T b_iv[2] = {1, 15};
  static const char_T u[15] = {'M', 'A', 'T', 'L', 'A', 'B', ':', 'p',
                               'm', 'a', 'x', 's', 'i', 'z', 'e'};
  const mxArray *m;
  const mxArray *y;
  const real_T *a_data;
  real_T *b_data;
  int32_T itilerow;
  int32_T k;
  int32_T ntilerows;
  int32_T outsize_idx_0;
  a_data = a->data;
  outsize_idx_0 = a->size[0] * (int32_T)varargin_1;
  if (!(outsize_idx_0 == (real_T)a->size[0] * (real_T)(int32_T)varargin_1)) {
    y = NULL;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 15, m, &u[0]);
    emlrtAssign(&y, m);
    b_error(y, &emlrtMCI);
  }
  ntilerows = b->size[0];
  b->size[0] = outsize_idx_0;
  emxEnsureCapacity_real_T(b, ntilerows);
  b_data = b->data;
  outsize_idx_0 = a->size[0];
  ntilerows = (int32_T)varargin_1;
  for (itilerow = 0; itilerow < ntilerows; itilerow++) {
    int32_T ibcol;
    ibcol = itilerow * outsize_idx_0;
    for (k = 0; k < outsize_idx_0; k++) {
      b_data[ibcol + k] = a_data[k];
    }
  }
}

/* End of code generation (repmat.c) */
