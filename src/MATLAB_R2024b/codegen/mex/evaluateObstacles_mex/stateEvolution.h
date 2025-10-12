/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stateEvolution.h
 *
 * Code generation for function 'stateEvolution'
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
void stateEvolution(const real_T U[40], const real_T x0[3], real_T sys_n,
                    real_T sys_Ts, real_T N, emxArray_real_T *x_pred);

/* End of code generation (stateEvolution.h) */
