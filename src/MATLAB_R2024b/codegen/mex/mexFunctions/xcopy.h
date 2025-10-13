/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xcopy.h
 *
 * Code generation for function 'xcopy'
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
void b_xcopy(int32_T n, const emxArray_real_T *x, real_T y_data[]);

void c_xcopy(int32_T n, const emxArray_real_T *x, int32_T ix0, real_T y_data[]);

void xcopy(int32_T n, const emxArray_real_T *x, emxArray_real_T *y);

/* End of code generation (xcopy.h) */
