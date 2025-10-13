/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * modelDynamics.h
 *
 * Code generation for function 'modelDynamics'
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
void modelDynamics(const real_T x_k[3], const real_T u_k[2], real_T sys_n,
                   real_T sys_Ts, emxArray_real_T *x_k1);

/* End of code generation (modelDynamics.h) */
