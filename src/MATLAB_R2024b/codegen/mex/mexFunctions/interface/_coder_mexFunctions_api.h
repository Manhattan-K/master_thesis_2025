/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mexFunctions_api.h
 *
 * Code generation for function '_coder_mexFunctions_api'
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
void Rmat_api(const mxArray *prhs, const mxArray **plhs);

void evaluateObstacles_api(const mxArray *const prhs[7], const mxArray **plhs);

void followerMPCandUpdate_api(mexFunctionsStackData *SD,
                              const mxArray *const prhs[7], int32_T nlhs,
                              const mxArray *plhs[5]);

void leaderMPCandUpdateHalt_api(mexFunctionsStackData *SD,
                                const mxArray *const prhs[6], int32_T nlhs,
                                const mxArray *plhs[6]);

void leaderMPCandUpdate_api(mexFunctionsStackData *SD,
                            const mxArray *const prhs[6], int32_T nlhs,
                            const mxArray *plhs[6]);

/* End of code generation (_coder_mexFunctions_api.h) */
