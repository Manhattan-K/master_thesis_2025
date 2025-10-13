//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// evaluateObstacles.h
//
// Code generation for function 'evaluateObstacles'
//

#pragma once

// Include files
#include "mexFunctions_types.h"
#include "mexFunctions_types2.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void evaluateObstacles(const struct0_T obstacles_data[],
                       const int32_T obstacles_size[2], const real_T x_l[2],
                       const real_T x_f[2], const struct1_T *leaderParams,
                       const struct2_T *followerParams, const struct3_T *sys,
                       real_T N, struct4_T *obstaclesInRange);

// End of code generation (evaluateObstacles.h)
