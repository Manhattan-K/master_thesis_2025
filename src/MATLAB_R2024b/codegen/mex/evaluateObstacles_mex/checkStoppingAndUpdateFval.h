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
#include "evaluateObstacles_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_checkStoppingAndUpdateFval(int32_T *activeSetChangeID,
                                  j_struct_T *solution, e_struct_T *memspace,
                                  const d_struct_T *objective,
                                  k_struct_T *workingset, f_struct_T *qrmanager,
                                  int32_T runTimeOptions_MaxIterations,
                                  boolean_T *updateFval);

void checkStoppingAndUpdateFval(int32_T *activeSetChangeID,
                                const real_T f_data[], j_struct_T *solution,
                                e_struct_T *memspace,
                                const d_struct_T *objective,
                                k_struct_T *workingset, f_struct_T *qrmanager,
                                int32_T runTimeOptions_MaxIterations,
                                const boolean_T *updateFval);

/* End of code generation (checkStoppingAndUpdateFval.h) */
