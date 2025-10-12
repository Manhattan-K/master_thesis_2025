/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateWorkingSet.h
 *
 * Code generation for function 'updateWorkingSet'
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
void updateWorkingSet(k_struct_T *WorkingSet,
                      const real_T TrialState_cIneq_data[],
                      const real_T TrialState_searchDir_data[],
                      int32_T workspace_int_data[]);

/* End of code generation (updateWorkingSet.h) */
