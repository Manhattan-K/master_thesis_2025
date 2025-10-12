/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * step.h
 *
 * Code generation for function 'step'
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
void step(evaluateObstacles_mexStackData *SD, struct_T *stepFlags,
          real_T Hessian[1600], const real_T lb_data[],
          const int32_T lb_size[2], const real_T ub_data[],
          const int32_T ub_size[2], j_struct_T *TrialState,
          l_struct_T *MeritFunction, e_struct_T *memspace,
          k_struct_T *WorkingSet, f_struct_T *QRManager,
          n_struct_T *CholManager, d_struct_T *QPObjective,
          o_struct_T *qpoptions);

/* End of code generation (step.h) */
