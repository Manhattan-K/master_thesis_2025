/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexFunctions_data.h
 *
 * Code generation for function 'mexFunctions_data'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern boolean_T isMexOutdated;
extern const char_T *evaluateObstacles_complete_name;
extern const char_T *getObstacleInfo_complete_name;
extern const char_T *getqiFromShape_complete_name;
extern const char_T *constMatrices_complete_name;
extern const char_T *c_followerMPCandUpdate_complete;
extern const char_T *completeName;
extern const char_T *constraints_complete_name;
extern const char_T *stateEvolution_complete_name;
extern const char_T *modelDynamics_complete_name;
extern const char_T *b_completeName;
extern const char_T *followerCost_complete_name;
extern const char_T *c_leaderMPCandUpdate_complete_n;
extern const char_T *c_completeName;
extern const char_T *d_completeName;
extern const char_T *leaderCost_complete_name;
extern const char_T *c_leaderMPCandUpdateHalt_comple;
extern const char_T *e_completeName;
extern const char_T *f_completeName;
extern const char_T *leaderCostHalt_complete_name;
extern const char_T *Rmat_complete_name;
extern emlrtContext emlrtContextGlobal;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t mexFunctions_nestLockGlobal;
extern const int32_T iv1[8];

/* End of code generation (mexFunctions_data.h) */
