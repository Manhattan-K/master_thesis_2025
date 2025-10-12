/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeLinearResiduals.h
 *
 * Code generation for function 'computeLinearResiduals'
 *
 */

#pragma once

/* Include files */
#include "evaluateObstacles_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void computeLinearResiduals(const real_T x[40], int32_T nVar,
                            real_T workspaceIneq_data[], int32_T mLinIneq,
                            const emxArray_real_T *AineqT, int32_T ldAi);

/* End of code generation (computeLinearResiduals.h) */
