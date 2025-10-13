/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeGradLag.h
 *
 * Code generation for function 'computeGradLag'
 *
 */

#pragma once

/* Include files */
#include "mexFunctions_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_computeGradLag(emlrtCTX aTLS, emxArray_real_T *workspace, int32_T ldA,
                      int32_T nVar, const real_T grad_data[], int32_T mIneq,
                      const emxArray_real_T *AineqTrans,
                      const int32_T finiteFixed_data[], int32_T mFixed,
                      const int32_T finiteLB_data[], int32_T mLB,
                      const int32_T finiteUB_data[], int32_T mUB,
                      const emxArray_real_T *lambda);

void computeGradLag(emlrtCTX aTLS, real_T workspace_data[], int32_T ldA,
                    int32_T nVar, const real_T grad_data[], int32_T mIneq,
                    const emxArray_real_T *AineqTrans,
                    const int32_T finiteFixed_data[], int32_T mFixed,
                    const int32_T finiteLB_data[], int32_T mLB,
                    const int32_T finiteUB_data[], int32_T mUB,
                    const emxArray_real_T *lambda);

/* End of code generation (computeGradLag.h) */
