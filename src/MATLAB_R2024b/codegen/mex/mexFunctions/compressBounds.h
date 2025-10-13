/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compressBounds.h
 *
 * Code generation for function 'compressBounds'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
int32_T compressBounds(int32_T indexLB_data[], int32_T indexUB_data[],
                       int32_T indexFixed_data[], const real_T lb[40],
                       const real_T ub[40], int32_T *mUB, int32_T *mFixed);

/* End of code generation (compressBounds.h) */
