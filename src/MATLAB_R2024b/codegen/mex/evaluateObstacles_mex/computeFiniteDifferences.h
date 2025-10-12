/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeFiniteDifferences.h
 *
 * Code generation for function 'computeFiniteDifferences'
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
boolean_T computeFiniteDifferences(
    m_struct_T *obj, real_T fCurrent, const real_T cIneqCurrent_data[],
    int32_T ineq0, real_T xk[40], real_T gradf_data[],
    emxArray_real_T *JacCineqTrans, int32_T CineqColStart, int32_T ldJI,
    const real_T lb_data[], const real_T ub_data[]);

/* End of code generation (computeFiniteDifferences.h) */
