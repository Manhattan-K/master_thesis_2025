/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexFunctions_internal_types.h
 *
 * Code generation for function 'evaluateObstacles'
 *
 */

#pragma once

/* Include files */
#include "mexFunctions_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_j_struct_T
#define typedef_j_struct_T
typedef struct {
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationIneq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
  real_T firstOrderOpt;
} j_struct_T;
#endif /* typedef_j_struct_T */

#ifndef typedef_n_struct_T
#define typedef_n_struct_T
typedef struct {
  char_T SolverName[7];
  int32_T MaxIterations;
} n_struct_T;
#endif /* typedef_n_struct_T */

/* End of code generation (mexFunctions_internal_types.h) */
