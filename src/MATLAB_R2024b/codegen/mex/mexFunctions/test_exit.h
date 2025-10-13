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
#include "mexFunctions_internal_types.h"
#include "mexFunctions_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_test_exit(struct_T *Flags, f_struct_T *memspace,
                 j_struct_T *MeritFunction,
                 int32_T fscales_cineq_constraint_size, i_struct_T *WorkingSet,
                 h_struct_T *TrialState, g_struct_T *QRManager,
                 const real_T lb[40], const real_T ub[40]);

boolean_T test_exit(j_struct_T *MeritFunction,
                    int32_T fscales_cineq_constraint_size,
                    const i_struct_T *WorkingSet, h_struct_T *TrialState,
                    const real_T lb[40], const real_T ub[40],
                    boolean_T *Flags_fevalOK, boolean_T *Flags_done,
                    boolean_T *Flags_stepAccepted,
                    boolean_T *Flags_failedLineSearch, int32_T *Flags_stepType);

/* End of code generation (test_exit.h) */
