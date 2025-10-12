/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeDeltaLag.h
 *
 * Code generation for function 'computeDeltaLag'
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
void computeDeltaLag(int32_T nVar, int32_T ldJ, int32_T mNonlinIneq,
                     real_T workspace_data[], const real_T grad_data[],
                     const emxArray_real_T *JacIneqTrans, int32_T ineqJ0,
                     const real_T grad_old_data[],
                     const emxArray_real_T *JacIneqTrans_old,
                     const emxArray_real_T *lambda, int32_T ineqL0);

/* End of code generation (computeDeltaLag.h) */
