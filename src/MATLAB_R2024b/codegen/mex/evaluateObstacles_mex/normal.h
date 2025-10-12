/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * normal.h
 *
 * Code generation for function 'normal'
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
void normal(evaluateObstacles_mexStackData *SD, const real_T Hessian[1600],
            const real_T grad_data[], j_struct_T *TrialState,
            l_struct_T *MeritFunction, e_struct_T *memspace,
            k_struct_T *WorkingSet, f_struct_T *QRManager,
            n_struct_T *CholManager, d_struct_T *QPObjective,
            const o_struct_T *qpoptions, struct_T *stepFlags);

/* End of code generation (normal.h) */
