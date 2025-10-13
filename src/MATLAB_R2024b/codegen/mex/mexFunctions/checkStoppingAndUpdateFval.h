/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkStoppingAndUpdateFval.h
 *
 * Code generation for function 'checkStoppingAndUpdateFval'
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
void b_checkStoppingAndUpdateFval(emlrtCTX aTLS, int32_T *activeSetChangeID,
                                  h_struct_T *solution, f_struct_T *memspace,
                                  const e_struct_T *objective,
                                  i_struct_T *workingset, g_struct_T *qrmanager,
                                  int32_T runTimeOptions_MaxIterations,
                                  boolean_T *updateFval);

void checkStoppingAndUpdateFval(emlrtCTX aTLS, int32_T *activeSetChangeID,
                                const real_T f_data[], h_struct_T *solution,
                                f_struct_T *memspace,
                                const e_struct_T *objective,
                                i_struct_T *workingset, g_struct_T *qrmanager,
                                int32_T runTimeOptions_MaxIterations,
                                const boolean_T *updateFval);

/* End of code generation (checkStoppingAndUpdateFval.h) */
