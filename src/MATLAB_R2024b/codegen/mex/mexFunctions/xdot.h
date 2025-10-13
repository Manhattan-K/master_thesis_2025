/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdot.h
 *
 * Code generation for function 'xdot'
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
real_T b_xdot(int32_T n, const real_T x_data[], int32_T ix0,
              const real_T y_data[], int32_T iy0);

real_T xdot(int32_T n, const emxArray_real_T *x, int32_T ix0,
            const real_T y_data[]);

/* End of code generation (xdot.h) */
