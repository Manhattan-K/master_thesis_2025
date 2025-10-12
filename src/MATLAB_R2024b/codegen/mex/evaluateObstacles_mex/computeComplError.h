/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeComplError.h
 *
 * Code generation for function 'computeComplError'
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
real_T computeComplError(int32_T fscales_cineq_constraint_size,
                         const real_T xCurrent[40], int32_T mIneq,
                         const real_T cIneq_data[],
                         const int32_T finiteLB_data[], int32_T mLB,
                         const real_T lb_data[], const int32_T finiteUB_data[],
                         int32_T mUB, const real_T ub_data[],
                         const emxArray_real_T *lambda, int32_T iL0);

/* End of code generation (computeComplError.h) */
