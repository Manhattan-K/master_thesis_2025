//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// getObstacleInfo.h
//
// Code generation for function 'getObstacleInfo'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct struct0_T;

// Function Declarations
void getObstacleInfo(const struct0_T obstacles_data[],
                     const int32_T obstacles_size[2],
                     const real_T selector_data[], real_T obsNum,
                     const real_T x0[2], coder::array<real_T, 2U> &q,
                     coder::array<real_T, 2U> &d);

// End of code generation (getObstacleInfo.h)
