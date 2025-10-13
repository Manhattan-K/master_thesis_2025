/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_mtimes_helper.h
 *
 * Code generation for function 'eml_mtimes_helper'
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
void binary_expand_op_1(emlrtCTX aTLS, emxArray_real_T *in1,
                        const real_T in2[6], const emxArray_real_T *in3,
                        const real_T in4[3], int32_T in5, const real_T in6[2]);

void binary_expand_op_3(emxArray_real_T *in1, const real_T in2[6],
                        const real_T in3[60], const emxArray_real_T *in4,
                        const real_T in5[2]);

/* End of code generation (eml_mtimes_helper.h) */
