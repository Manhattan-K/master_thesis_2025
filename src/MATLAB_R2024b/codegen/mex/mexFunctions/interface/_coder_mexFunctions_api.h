//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_mexFunctions_api.h
//
// Code generation for function '_coder_mexFunctions_api'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct mexFunctionsStackData;

// Function Declarations
void Rmat_api(const mxArray *prhs, const mxArray **plhs);

void b_followerMPCandUpdate_api(mexFunctionsStackData *SD,
                                const mxArray *const prhs[7], int32_T nlhs,
                                const mxArray *plhs[5]);

void b_leaderMPCandUpdateHalt_api(mexFunctionsStackData *SD,
                                  const mxArray *const prhs[6], int32_T nlhs,
                                  const mxArray *plhs[6]);

void b_leaderMPCandUpdate_api(mexFunctionsStackData *SD,
                              const mxArray *const prhs[6], int32_T nlhs,
                              const mxArray *plhs[6]);

void evaluateObstacles_api(const mxArray *const prhs[7], const mxArray **plhs);

// End of code generation (_coder_mexFunctions_api.h)
