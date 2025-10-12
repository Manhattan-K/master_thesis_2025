/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * linesearch.h
 *
 * Code generation for function 'linesearch'
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
real_T b_linesearch(boolean_T *evalWellDefined, int32_T WorkingSet_nVar,
                    int32_T WorkingSet_ldA,
                    const emxArray_real_T *WorkingSet_Aineq,
                    j_struct_T *TrialState, real_T MeritFunction_penaltyParam,
                    real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                    real_T MeritFunction_phiFullStep,
                    int32_T c_FcnEvaluator_next_next_next_n,
                    const real_T d_FcnEvaluator_next_next_next_n[3],
                    const struct5_T *e_FcnEvaluator_next_next_next_n,
                    real_T f_FcnEvaluator_next_next_next_n,
                    const struct3_T g_FcnEvaluator_next_next_next_n,
                    const h_struct_T *h_FcnEvaluator_next_next_next_n,
                    boolean_T socTaken, int32_T *exitflag);

real_T c_linesearch(boolean_T *evalWellDefined, int32_T WorkingSet_nVar,
                    int32_T WorkingSet_ldA,
                    const emxArray_real_T *WorkingSet_Aineq,
                    j_struct_T *TrialState, real_T MeritFunction_penaltyParam,
                    real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                    real_T MeritFunction_phiFullStep,
                    int32_T c_FcnEvaluator_next_next_next_n,
                    const real_T d_FcnEvaluator_next_next_next_n[3],
                    const struct5_T *e_FcnEvaluator_next_next_next_n,
                    real_T f_FcnEvaluator_next_next_next_n,
                    const struct3_T g_FcnEvaluator_next_next_next_n,
                    const i_struct_T *h_FcnEvaluator_next_next_next_n,
                    boolean_T socTaken, int32_T *exitflag);

real_T linesearch(boolean_T *evalWellDefined, int32_T WorkingSet_nVar,
                  int32_T WorkingSet_ldA,
                  const emxArray_real_T *WorkingSet_Aineq,
                  j_struct_T *TrialState, real_T MeritFunction_penaltyParam,
                  real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                  real_T MeritFunction_phiFullStep,
                  int32_T c_FcnEvaluator_next_next_next_n,
                  const real_T d_FcnEvaluator_next_next_next_n[3],
                  const struct5_T *e_FcnEvaluator_next_next_next_n,
                  real_T f_FcnEvaluator_next_next_next_n,
                  const struct3_T g_FcnEvaluator_next_next_next_n,
                  const c_struct_T *h_FcnEvaluator_next_next_next_n,
                  boolean_T socTaken, int32_T *exitflag);

/* End of code generation (linesearch.h) */
