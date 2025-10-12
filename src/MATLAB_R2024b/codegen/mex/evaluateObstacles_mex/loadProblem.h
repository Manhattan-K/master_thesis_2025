/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * loadProblem.h
 *
 * Code generation for function 'loadProblem'
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
void loadProblem(k_struct_T *obj, int32_T mIneq, int32_T mLB, int32_T mUB,
                 int32_T mFixed, int32_T mConstrMax);

/* End of code generation (loadProblem.h) */
