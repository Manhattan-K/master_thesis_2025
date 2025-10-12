/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * constraints.h
 *
 * Code generation for function 'constraints'
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
void binary_expand_op(emxArray_real_T *in1, const real_T in2_data[],
                      const int32_T *in2_size, const real_T in3_data[],
                      const int32_T *in3_size);

int32_T constraints(const real_T U[40], const real_T x0[3], real_T M,
                    const emxArray_real_T *A_bar, const real_T B_bar_data[],
                    int32_T B_bar_size, real_T N, real_T sys_n, real_T sys_Ts,
                    real_T c_data[]);

/* End of code generation (constraints.h) */
