/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * maxConstraintViolation.h
 *
 * Code generation for function 'maxConstraintViolation'
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
real_T b_maxConstraintViolation(emlrtCTX aTLS, i_struct_T *obj,
                                const emxArray_real_T *x);

real_T c_maxConstraintViolation(emlrtCTX aTLS, i_struct_T *obj,
                                const emxArray_real_T *x, int32_T ix0);

real_T d_maxConstraintViolation(emlrtCTX aTLS, i_struct_T *obj,
                                const real_T x_data[]);

real_T maxConstraintViolation(emlrtCTX aTLS, mexFunctionsStackData *SD,
                              const i_struct_T *obj, const real_T x_data[]);

/* End of code generation (maxConstraintViolation.h) */
