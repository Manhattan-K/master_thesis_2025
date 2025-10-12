/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * hasFiniteBounds.h
 *
 * Code generation for function 'hasFiniteBounds'
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
boolean_T hasFiniteBounds(boolean_T hasLB[40], boolean_T hasUB[40],
                          const real_T lb_data[], const int32_T lb_size[2],
                          const real_T ub_data[], const int32_T ub_size[2]);

/* End of code generation (hasFiniteBounds.h) */
