/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assignResidualsToXSlack.h
 *
 * Code generation for function 'assignResidualsToXSlack'
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
void assignResidualsToXSlack(emlrtCTX aTLS, int32_T nVarOrig,
                             const i_struct_T *WorkingSet,
                             h_struct_T *TrialState, f_struct_T *memspace);

/* End of code generation (assignResidualsToXSlack.h) */
