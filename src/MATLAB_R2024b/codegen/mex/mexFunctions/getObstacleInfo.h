/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getObstacleInfo.h
 *
 * Code generation for function 'getObstacleInfo'
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
void getObstacleInfo(const struct0_T obstacles_data[],
                     const int32_T obstacles_size[2],
                     const real_T selector_data[], real_T obsNum,
                     const real_T x0[2], emxArray_real_T *q,
                     emxArray_real_T *d);

/* End of code generation (getObstacleInfo.h) */
