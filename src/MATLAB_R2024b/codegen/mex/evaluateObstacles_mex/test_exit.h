/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_exit.h
 *
 * Code generation for function 'test_exit'
 *
 */

#pragma once

/* Include files */
#include "evaluateObstacles_mex_internal_types.h"
#include "evaluateObstacles_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_test_exit(struct_T *Flags, e_struct_T *memspace,
                 l_struct_T *MeritFunction,
                 int32_T fscales_cineq_constraint_size, k_struct_T *WorkingSet,
                 j_struct_T *TrialState, f_struct_T *QRManager,
                 const real_T lb_data[], const int32_T lb_size[2],
                 const real_T ub_data[], const int32_T ub_size[2]);

boolean_T test_exit(l_struct_T *MeritFunction,
                    int32_T fscales_cineq_constraint_size,
                    const k_struct_T *WorkingSet, j_struct_T *TrialState,
                    const real_T lb_data[], const real_T ub_data[],
                    boolean_T *Flags_fevalOK, boolean_T *Flags_done,
                    boolean_T *Flags_stepAccepted,
                    boolean_T *Flags_failedLineSearch, int32_T *Flags_stepType);

/* End of code generation (test_exit.h) */
